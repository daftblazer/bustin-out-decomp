#include "engine/e_storable.h"
#include "engine/e_resource.h"
#include "engine/e_rfont.h"
#include "engine/e_texture.h"
#include "engine/e_shader.h"
#include "engine/e_rshader.h"
#define EOR_BUILD_TIME "21:41:34"
#include "engine/e_engine.h"
#include "engine/e_rcharacter.h"
#include "engine/e_submodelshader.h"
#include "engine/e_submodel.h"
#include "engine/e_rmodel.h"
#include "engine/e_ranim.h"
#include "sims/Unk80297B74.h"
#include "sims/Unk800454AC.h"
#include "engine/ResourceManagers.h"
#include "sims/Unk800421C0Sim.h"

// The action queue display, second source file of the unit at 0x80044D84 (0x800454AC
// to 0x80049ADC, about 55 functions). IN PROGRESS: this is the first stage, the icon
// pool and the icon's small members. Not written yet: the manager (0x800455A8,
// 0x800455D4, 0x80049590 to 0x800498D8 and the small virtuals after), the queue
// display itself (0x8004578C to 0x80047430) and the icon's drawing (0x80047A98 to
// 0x80049094).

// 0x800454AC
// A hash of some bytes: each is rotated left three bits further than the last and
// they are combined with exclusive or.
unsigned int fn_800454AC(const unsigned char* data, int size) {
    unsigned int hash = 0;
    unsigned int shift = 0;
    for (int i = 0; i < size; i++) {
        unsigned int byte = data[i];
        unsigned int rotated = byte << shift;
        if (shift > 0x18) {
            rotated ^= byte >> (0x20 - shift);
        }
        hash ^= rotated;
        shift = (shift + 3) & 0x1F;
    }
    return hash;
}

inline bool IsNode(Unk80026864Node* node) {
    return node != 0 ? true : false;
}

inline void DeleteIcons(Unk80026864ListBase& list) {
    Unk80026864Node* next;
    for (Unk80026864Node* node = list.tail; IsNode(node); node = next) {
        Unk80047840* item = (Unk80047840*)node->item;
        next = node->prev;
        if (list.owns && item) {
            delete item;
        }
    }
    list.fn_801B4760();
}

// 0x800454FC
// NON_MATCHING: the delete loop keeps the node in r3 where the original uses r9 (the
// same difference as in the dialog unit's delete loops).
Unk80045650::~Unk80045650() {
    DeleteIcons(unk8);
}

// 0x80045650
void Unk80045650::fn_80045650() {
    unk0 = 0;
    for (int i = 0; i <= 9; i++) {
        Unk80047840* item = new Unk80047840;
        item->unkF8 = unk0;
        unk0 = item;
        item->unkF4 = i;
        fn_800456BC(item);
    }
}

// 0x800456BC
// NON_MATCHING: 2 of 25 instructions. Before the append the original loads the item
// (mr r4) and then the list's address (addi r3); here they are the other way round.
// Five forms of the call give the same.
int Unk80045650::fn_800456BC(Unk80047840* item) {
    if (unk4 == 10) {
        return 0;
    }
    item->fn_80049094(1);
    unk8.Append(item);
    unk4++;
    return 1;
}

// 0x80045720
Unk80047840* Unk80045650::fn_80045720() {
    Unk80047840* result;
    if (unk4 != 0) {
        Unk80026864Node* node = unk8.head;
        Unk80047840* item = (Unk80047840*)node->item;
        unk8.fn_801B4520(node);
        unk4--;
        item->fn_80049094(1);
        result = item;
    } else {
        result = 0;
    }
    return result;
}

// 0x80047840
Unk80047840::Unk80047840() : unkD4(0.0f, 0.0f), unkE0(0.0f, 0.0f) {
    unkF4 = -1;
    unk48[0] = 0;
    unk48[1] = 0;
    unk48[2] = 0;
    unk48[3] = 0;
    unk48[4] = 0;
    unk48[5] = 0;
    unk48[6] = 0;
    unk48[7] = 0;
    unk48[8] = 0;
    unk48[9] = 0;
    unk48[10] = 0;
    unk48[11] = 0;
    unk48[12] = 0;
    unkF8 = 0;
    unk100 = 0;
    unkFC = 0;
    unk84 = 0;
    fn_80049094(1);
}

// 0x80047910
Unk80047840::~Unk80047840() {
    E_RELEASE_RESOURCE(unk48[11]);
    E_RELEASE_RESOURCE(unk48[0]);
    E_RELEASE_RESOURCE(unk48[1]);
    E_RELEASE_RESOURCE(unk48[2]);
    E_RELEASE_RESOURCE(unk48[3]);
    E_RELEASE_RESOURCE(unk48[4]);
    E_RELEASE_RESOURCE(unk48[5]);
    E_RELEASE_RESOURCE(unk48[6]);
    E_RELEASE_RESOURCE(unk48[7]);
    E_RELEASE_RESOURCE(unk48[8]);
    E_RELEASE_RESOURCE(unk48[9]);
    E_RELEASE_RESOURCE(unk48[10]);
    E_RELEASE_RESOURCE(unk48[12]);
}

// 0x80049400
// Shows the icon with this resource id (unless it already does).
void Unk80047840::fn_80049400(unsigned int id) {
    if (unk100 == 1 && unk104 == id && unk48[11] != 0) {
        return;
    }
    E_RELEASE_RESOURCE(unk48[11]);
    unk48[11] = lbl_80340AB8.fn_80177628(id, 0, 0);
    unk100 = 1;
    unk104 = id;
    unkFC = 1;
}

// 0x80049498
// Shows an icon it is handed (or none).
void Unk80047840::fn_80049498(void* icon) {
    int source = 2;
    if (icon == 0) {
        source = 0;
    }
    if (unk48[11] == icon && unk100 == source) {
        return;
    }
    E_RELEASE_RESOURCE(unk48[11]);
    unk48[11] = icon;
    unk100 = source;
    unkFC = 1;
}

extern float lbl_8037B578;

// 0x8004950C
void Unk80047840::fn_8004950C() {
    unkE0.Set(0.0f, lbl_8037B578, 0.0f);
}

// The registration object (lbl_8037BFA8): slot 0x340 holds the input manager.
struct Unk8015C620 {
    void fn_8015C620(int id, void* listener);
};
extern Unk8015C620* lbl_8037BFA8;
extern Unk800455D4* lbl_8037B558;

// 0x800455A8
void fn_800455A8() {
    lbl_8037B558 = new Unk800455D4;
}

// 0x800455D4
Unk800455D4::Unk800455D4() : Unk801E58D4(-1, 0) {
    unk24 = 0;
    unk0 = (int (*)(void*, char*))fn_800498A8;
    lbl_8037BFA8->fn_8015C620(0xF, (Unk80049AA8*)this);
    unkC = 6;
}

// The object an action's icon comes from (found by id; vtable pointer at 0x1C): slot 5
// gives the holder of the sim it is about.
struct Unk801E5A50Holder {
    Unk800421C0Sim* sim;
};
class Unk801E5A50Object {
public:
    char unk0[0x1C];
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual Unk801E5A50Holder* vfn5();
};
Unk801E5A50Object* fn_801E5A50(int id);
void fn_802182EC(int id, void** out);

// 0x800498D8
inline int Unk800498D0::vfn3(Unk80047840* icon) {
    if (unk5B != 0) {
        if (unk5B == 1) {
            Unk801E5A50Object* object = fn_801E5A50(unk5C);
            if (object) {
                void* image = 0;
                fn_802182EC(object->vfn5()->sim->vfn119(), &image);
                icon->fn_80049498(image);
            }
        }
    } else {
        if (unk5C == 0) {
            icon->fn_80049400(0xD59C7BB5);
        } else {
            icon->fn_80049400(unk5C);
        }
    }
    return 1;
}

extern "C" void* fn_80111AE8(void* dst, const void* src, ...);   // memcpy (called without a prototype)
void fn_80047788(int object, int item);

// 0x80045C50
Unk80047840* Unk8004578C::fn_80045C50(int id) {
    for (Unk80026864Node* node = *(Unk80026864Node**)this; node != 0; node = node->next) {
        Unk80047840* icon = (Unk80047840*)node->item;
        if (icon->unkCC == id) {
            return icon;
        }
    }
    return 0;
}

// 0x80049550
Unk80047840* Unk8004578C::fn_80049550(char slot) {
    Unk80047840* icon = unk11C->unk0;
    while (icon != 0 && icon->unkF4 != slot) {
        icon = icon->unkF8;
    }
    return icon;
}

// 0x800495C4
// Reads a packed stream of commands and returns how many bytes it used. Command 0 puts the
// icon with a resource id on a pooled widget, 1 the icon of an object, 2 replaces the
// queued actions, 3 takes one off.
// NON_MATCHING: 175 instructions against 185, 156 differ. Three attempts (case order, a
// varargs memcpy, switch against if chain). Left: the original keeps the byte count in r30
// loaded straight from data[0] and builds the CTilePt temporary at sp+0x10 beside a char
// spilled at sp+0x18; here the count lands in r29/r9 and the temporary at sp+8.
int Unk8004578C::fn_800495C4(unsigned char* data) {
    int pos = 1;
    unsigned char left = data[0] - 1;
    while (left != 0xFF) {
        int command = data[pos];
        pos++;
        switch (command) {
        case 3: {
            int object = *(int*)(data + pos);
            pos += 4;
            int item = *(int*)(data + pos);
            pos += 4;
            Unk80047840* icon = fn_80045C50(item);
            if (icon) {
                icon->unk7C = 1;
            }
            fn_80047788(object, item);
            break;
        }
        case 2: {
            unsigned short length = *(unsigned short*)(data + pos);
            pos += 2;
            unk12C = length;
            fn_80111AE8(unk130, data + pos, length);
            pos += unk12C;
            if (unk124 == 0) {
                unk124 = new Unk800498D0[9];
            }
            int first = *(int*)unk130;
            unk120 = 0;
            if (first != 0) {
                char* p = unk130 + 4;
                do {
                    Unk800498D0* record = unk124 + unk120;
                    record->unk40 = first;
                    record->unk28 = *(int*)p;
                    p += 4;
                    record->unk44 = *(int*)p;
                    p += 4;
                    CTilePt tile;
                    *(unsigned short*)&tile = *(unsigned short*)p;
                    tile.unk2 = p[2];
                    p += 3;
                    record->tile = tile;
                    record->unk5B = *(unsigned char*)p;
                    p += 1;
                    record->unk5C = *(int*)p;
                    p += 4;
                    int a = *(int*)p;
                    p += 4;
                    int b = *(int*)p;
                    p += 4;
                    record->fn_801CFAB8(a, b);
                    unk120++;
                    first = *(int*)p;
                    p += 4;
                } while (first != 0);
            }
            break;
        }
        case 0:
        case 1: {
            char slot = data[pos];
            pos++;
            int id = *(int*)(data + pos);
            pos += 4;
            Unk80047840* icon = fn_80049550(slot);
            icon->unk104 = id;
            if (command == 0) {
                if (id == 0) {
                    id = 0xD59C7BB5;
                }
                icon->fn_80049400(id);
            } else if (command == 1) {
                Unk801E5A50Object* object = fn_801E5A50(id);
                if (object) {
                    void* image = 0;
                    fn_802182EC(object->vfn5()->sim->vfn119(), &image);
                    icon->fn_80049498(image);
                }
            }
            break;
        }
        }
        left--;
    }
    return pos;
}
