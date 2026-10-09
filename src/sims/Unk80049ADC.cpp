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

// 0x80049B7C
const char* EHouse::GetHouseName() {
    return GetHouseNameText(unk3C);
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
        unk8->fn_80056598();
        unk8->fn_80056914(0);
    }
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
        void* object = node->unk18;
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
void EHouse::fn_8004B740(Unk8007F234* object) {
    if (unk1C != 0 && object != 0) {
        *(void**)((char*)object + 0x24) = &unk58;
        unk1C->fn_8017BF6C(object);
    }
}
