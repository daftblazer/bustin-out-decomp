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
