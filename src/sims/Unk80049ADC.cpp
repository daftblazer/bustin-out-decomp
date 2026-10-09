#include "engine/e_storable.h"
#include "engine/e_instance.h"
#include "engine/e_ilight.h"
#include "engine/e_idirlight.h"
#include "engine/e_resource.h"
#include "engine/e_rfont.h"
#include "engine/e_texture.h"
#include "engine/e_ifloor.h"
#include "engine/e_igameinstance.h"
#include "engine/e_istaticmodel.h"
#include "engine/e_rcharacter.h"
#include "engine/e_shader.h"
#include "engine/e_rshader.h"
#include "engine/e_submodelshader.h"
#include "engine/e_submodel.h"
#include "engine/e_rmodel.h"
#include "engine/e_ranim.h"
#include "sims/i_siminstance.h"
#include "sims/i_simsobjectmodel.h"
#include "sims/i_simswallobjectmodel.h"
#include "sims/i_simsmultitileobjectmodel.h"
#include "sims/i_simscountertopobject.h"
#include "sims/i_shrubobject.h"
#define EOR_BUILD_TIME "21:41:35"
#include "engine/e_engine.h"
#include "engine/e_ipointlight.h"
#include "engine/e_rlevel.h"
#include "engine/e_iwallpart2.h"
#include "engine/e_ifencewall.h"
#include "engine/e_iamblight.h"
#include "engine/e_ipointamblight.h"
#include "sims/Unk80297B74.h"
#include "engine/e_particle.h"
#include "engine/e_iparticleemit.h"
#include "engine/e_rparticletype.h"
#include "engine/e_ispotlight.h"
#include "sims/EHouse.h"
#include "sims/EGlobal.h"
#include "sims/ESimsCam.h"
#include "engine/ResourceManagers.h"

// The level loader (third source file of the unit at 0x80044D84: 0x80049ADC to
// 0x8004BCBC, build time 21:41:35). It sets up a lot: the level objects, the lights,
// the particle effects and the house to load. IN PROGRESS: only the small functions are
// written. The names are unknown (The Sims 2's ERLevel is the engine's level class, not
// this one); the object is called after its constructor.

// 0x80049ADC
// The name of one of the sixteen houses (1 to 16; anything else gives the nearest).
const char* GetHouseNameText(int index) {
    const char* names[16] = {"house 01", "house 02", "house 03", "house 04", "house 05", "house 06",
                             "house 07", "house 08", "house 09", "house 10", "house 11", "house 12",
                             "house 13", "house 14", "house 15", "house 16"};
    int i = index - 1;
    if (i < 0) {
        i = 0;
    }
    if (i > 15) {
        i = 15;
    }
    return names[i];
}

void fn_801B8AA4(void* block);                                 // frees an array

// 0x80049B7C
const char* EHouse::GetHouseName() {
    return GetHouseNameText(unk3C);
}

// 0x80049BA0
EHouse::EHouse(EVec2& position, int id, ERLevel* level, bool makeObjects, bool makeWalls, bool unused,
               bool owner) {
    unk0 = owner;
    unk3C = id;
    unk1C = 0;
    unk30 = 0;
    unk2C = 0;
    if (lbl_802E6700.fn_800655C4()) {
        unk20 = 2;
    } else {
        unk20 = 1;
    }
    unk34 = position.y;
    unk38 = position.x;
    unk14 = 0;
    unk24 = 0;
    unk28 = 0;
    unk10 = 1;
    if (makeWalls) {
        unk8 = new Unk80055C60;
    } else {
        unk8 = 0;
    }
    if (makeObjects) {
        unk4 = new Unk8007F234(this);
    } else {
        unk4 = 0;
    }
    if (level == 0) {
        unsigned int id = lbl_802E6700.fn_80066CE4(GetHouseName());
        Unk8033F5C4* manager = &lbl_8033F5C4;
        manager->fn_80177628(id, 0, 0);
        unk1C = (ERLevel*)lbl_8033FA38.fn_80177628(id, 0, 0);
        manager->fn_801778B4(id);
    } else {
        unk1C = level;
        level->fn_80176860();
    }
    unkC = 0;
    unk18 = 0;
    unkD0.Clear();
}

// 0x80049D50
EHouse::~EHouse() {
    fn_8004ABB8();
}

// 0x80049DA4
void EHouse::Init() {
    BuildHouse();
    unk14 = 1;
}

// 0x80049DD8
// A callback the houses' objects are given; it never has anything to say.
int fn_80049DD8() {
    return 0;
}

// 0x8004A90C
void EHouse::fn_8004A90C() {
    unk110 = 0.0f;
}

// 0x8004B104
short fn_8004B104(int value) {
    return value;
}

// 0x80049FB4
void EHouse::fn_80049FB4(int state) {
    unk20 = state;
    if (unk8) {
        unk8->fn_80056598(state);
        unk8->fn_80056914(0);
    }
}

// 0x80049FFC
// Goes to the next way of showing the walls (a guess at the Sims 2's SetNextWallMode, the next
// method in its order): none, then all down or cut away, then up.
void EHouse::SetNextWallMode() {
    switch (unk20) {
    case 0:
        unk20 = lbl_802E6700.fn_800655C4() == 0 ? 1 : 2;
        break;
    case 1:
        unk20 = 2;
        break;
    case 2:
        unk20 = 0;
        break;
    default:
        unk20 = 0;
        break;
    }
    if (unk8) {
        unk8->fn_80056598(unk20);
        unk8->fn_80056914(0);
    }
    lbl_8037C198->vfn8();
}

// 0x8004A0B4
void EHouse::fn_8004A0B4(ERC* rc) {
    if (unk1C) {
        unk1C->fn_8017AA14(rc);
    }
    unk4->fn_8007FFE4(rc);
    if (unk8) {
        unk8->fn_8005653C(rc);
    }
}

// 0x8004ACBC
// Takes the walls away (the Sims 2's DestroyWalls has the same size).
void EHouse::DestroyWalls() {
    if (unk8) {
        delete unk8;
        unk8 = 0;
    }
    unk1C->fn_8017BE44();
}

// 0x8004B578
void EHouse::fn_8004B578(int a, int b) {
    unk4C.fn_801B5704(b, a, 0);
}

// 0x8004B634
void EHouse::fn_8004B634() {
    Unk801B5358Node* next;
    for (Unk801B5358Node* node = unk4C.unk0; node != 0; node = next) {
        EInstance* object = node->unk18;
        next = node->unk10;
        fn_8016C9A4(object);
    }
}

// 0x8004B678
struct Unk8004B678Arg {
    char unk0[0x18];
    void* unk18;
};
void fn_8004B678(void* a, Unk8004B678Arg* b) {
    fn_8002A234(b->unk18, a);
}

// 0x8004B740
void EHouse::fn_8004B740(Unk8002EF48* descriptor) {
    if (unk1C != 0 && descriptor != 0) {
        descriptor->unk24 = (int)&unk58;
        unk1C->fn_8017BF6C(descriptor);
    }
}

// 0x8004B6A4
// Describes an object to the level: where it is, what it is and who draws it.
void EHouse::fn_8004B6A4(Unk80026864* object) {
    if (unk1C != 0 && object != 0) {
        unk104 = *object->fn_8002D2C8();
        unkD0.unk18 = (int)object;
        unkD0.unk24 = (int)&unk58;
        unkD0.unkC = 0;
        unkD0.unk10 = 0;
        unkD0.unk1C = 0;
        unkD0.unk8 = (int)&unk104;
        unkD0.unk14 = (int)fn_8004B678;
        unk1C->fn_8017BF6C(&unkD0);
    }
}

// 0x8004A110
void EHouse::fn_8004A110() {
    unkC = 1;
    fn_8004A91C();
    fn_8004AFC0();
    fn_8004AE38();
    if (unk1C) {
        unk1C->Update();
    }
    fn_8004B5AC();
    if (unk8 != 0 && unk8->unk0 == 0) {
        unk8->fn_80056914(0);
    }
    unkC = 0;
}

// 0x8004A194
// NON_MATCHING: 25 instructions against 24. The original multiplies the index by 0x28 in
// the loop (mulli) and compares `i <= 9` with cmpwi/ble; here the compiler turns the loop
// into a counter loop (mtctr/bdnz) and walks a pointer. A for, a while and an inline
// accessor all give the same.
// Which of the ten entries of the lighting table a time falls in: the entry with that
// time, or the one before the first later entry (wrapping), or the last.
struct Unk802E60C4Entry {
    int unk0;                         // time
    char unk4[0x28 - 4];
};
extern Unk802E60C4Entry lbl_802E60C4[10];
int fn_8004A194(int time) {
    for (int i = 0; i <= 9; i++) {
        int value = lbl_802E60C4[i].unk0;
        if (time == value) {
            return i;
        }
        if (time < value) {
            return (i + 9) % 10;
        }
    }
    return 9;
}

// 0x8004B4A0
// Takes the lights off the level and deletes them (a guess at the Sims 2's CleanUpRoomLights,
// the same place in its method order).
void EHouse::CleanUpRoomLights() {
    if (unk2C) {
        for (int i = 1; i < unk30; i++) {
            unk1C->RemoveLight(unk2C[i]);
            if (unk2C[i]) {
                delete unk2C[i];
            }
        }
        if (unk2C) {
            fn_801B8AA4(unk2C);
        }
        unk2C = 0;
    }
    if (unk24) {
        unk1C->RemoveLight(unk24);
    }
    if (unk28) {
        unk1C->RemoveLight(unk28);
    }
}

// 0x8004B5AC
// Deletes everything on the object list and empties it.
// NON_MATCHING: same 34 instructions; the original keeps the entry in r30 and the resource in
// r31, here they are the other way round (three declaration orders tried).
void EHouse::fn_8004B5AC() {
    Unk801B5358Node* node = unk4C.unk0;
    if (node != 0) {
        do {
            EInstance* object = node->unk18;
            Unk801B5358Node* next = node->unk10;
            void* resource = node->unk1C;
            if (object) {
                delete object;
            }
            if (resource) {
                fn_801767FC(resource);
            }
            unk4C.fn_801B5B08(node);
            node = next;
        } while (node != 0);
    }
}

// 0x8004ABB8
// Takes the whole house down (called by the destructor).
void EHouse::fn_8004ABB8() {
    if (unk4) {
        unk4->fn_8007FAB8(unk1C);
    }
    CleanUpRoomLights();
    if (unk24) {
        delete unk24;
    }
    int zero = 0;
    unk24 = (EILight*)zero;
    if (unk28) {
        delete unk28;
    }
    unk28 = (EILight*)zero;
    unk1C->fn_8017B8C0(0);
    DestroyWalls();
    fn_80075ABC();
    if (unk4) {
        delete unk4;
    }
    unk1C->fn_8017BE20();
    fn_8004B634();
    fn_8004B5AC();
    if (unk1C) {
        fn_801767FC(unk1C);
        unk1C = (ERLevel*)zero;
    }
    unk18 = zero;
    unk10 = 1;
}
