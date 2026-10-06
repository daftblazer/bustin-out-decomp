#include "engine/e_storable.h"
#include "engine/e_resource.h"
#include "engine/e_rfont.h"
#include "engine/e_texture.h"
#include "engine/e_shader.h"
#include "engine/e_rshader.h"
#include "engine/e_instance.h"
#include "engine/e_igameinstance.h"
#include "engine/e_istaticmodel.h"
#include "engine/e_iwallpart2.h"
#include "engine/e_ifencewall.h"
#define EOR_BUILD_TIME "21:41:26"
#include "engine/e_engine.h"
#include <map>
#include "sims/Unk80026864Private.h"

// The wall and fence tools of build mode: part of Unk80026864 and its helpers.

extern "C" double fn_8010D684(double); // acos
void fn_801C6310(int id, int on);
inline void SetButtonHint(int id, bool on) { fn_801C6310(id, on); }
int fn_800390FC(Unk801C6EF4* start, Unk801C6EF4* end, int* direction, int* type, int* kind, int price);
int fn_8003930C(Unk801C6EF4 start, Unk801C6EF4 end, int* direction, int* type, int* kind, int price);
int fn_80038FC0(EVec2* from, EVec2* to, int type, int kind, int* out, int arg, int remove, int price);
int fn_800395B0(void* a, void* b, int type, int kind);
int fn_80039A70(void* a, void* b, int kind);

// A room as the room table keeps it.
struct Unk80235FD0 {
    char unk0[0x34];
    int unk34;
    int fn_80235FD0();
};
// The room table's tree, walked by hand (the iterator class would live in memory).
struct Unk8037D998Node : _STL::_Rb_tree_node_base {
    int key;
    Unk80235FD0* room;
};
struct Unk8037D998Table {
    int unk0;
    _STL::_Rb_tree_node_base* header;
};
inline bool NotAtEnd(const _STL::_Rb_tree_node_base* node, const _STL::_Rb_tree_node_base* end) {
    return !(node == end);
}

// 0x80033974
// States 3 and 5's handler: what the pending wall or fence action costs.
int Unk80026864::fn_80033974() {
    int price = 0x46;
    EController* controller = lbl_8037C11C->fn_8015E5FC(lbl_8037C11C->fn_8015E614(unk38));
    if (unk84 != 3) {
        price = unk1C4;
    }
    if ((unk88 & 1) && controller->fn_8015DF98(0x11)) {
        EVec2 from(unkD0, unkD4);
        EVec2 to;
        fn_8002BC5C(&to);
        float dx = to.x - from.x;
        int width = (int)(EABS(dx) + 0.5f);
        float dy = to.y - from.y;
        int height = (int)(EABS(dy) + 0.5f);
        return (width + height) * (price + price);
    }
    if (unk88 & 4) {
        return (int)-((float)unkEC * 0.8f);
    }
    if (unkD0 == unkD8) {
        float length = unkD4 - unkDC;
        return price * (int)(EABS(length) + 0.5f);
    }
    float length = unkD0 - unkD8;
    return price * (int)(EABS(length) + 0.5f);
}

// 0x80033BAC
// Leaves the wall or fence tool.
// NON_MATCHING: 6 instructions: the original loads the second argument of each
// button-hint call before the first. Four forms of the call tried.
void Unk80026864::fn_80033BAC() {
    bool active = false;
    if (unk84 == 3 || unk84 == 5) {
        active = true;
    }
    if (active) {
        unk84 = 0;
        unk88 = 0;
        SetButtonHint(0x90, false);
        SetButtonHint(0x100, false);
        SetButtonHint(0xEF, true);
        if (unk104) {
            fn_801767FC(unk104);
            unk104 = 0;
        }
    }
}

// 0x80033C3C
// The wall tool's buttons (the same scheme as the wallpaper tool's, fn_80031980).
// NON_MATCHING: 105 instructions vs 103, as fn_80031980: the branches share their
// final store of unk88 differently. Two variants tried.
void Unk80026864::fn_80033C3C() {
    EController* controller = lbl_8037C11C->fn_8015E5FC(lbl_8037C11C->fn_8015E614(unk38));
    if (controller->fn_8015DF98(0x11) && controller->fn_8015E0F8(5)) {
        if (!fn_80037C34()) {
            lbl_8037D96C->fn_8006186C(0x3804219F);
        }
        unk88 = 0;
    } else if (!(unk88 & 1)) {
        if (controller->fn_8015E0F8(5)) {
            unk88 |= 3;
        } else if (!(unk88 & 1) && controller->fn_8015E0F8(0xF)) {
            unk88 |= 5;
        }
    } else if ((unk88 & 2) && controller->fn_8015E0F8(5)) {
        if (!fn_80037648()) {
            lbl_8037D96C->fn_8006186C(0x3804219F);
        }
        unk88 &= ~3;
    } else if ((unk88 & 4) && controller->fn_8015E0F8(5)) {
        if (!fn_800380C4()) {
            lbl_8037D96C->fn_8006186C(0x3804219F);
        }
        unk88 = (unk88 & ~1) & ~4;
    } else if (controller->fn_8015DF98(7)) {
        unk88 = 0;
    }
}

// 0x8003467C
// The angle of a wall direction, turned half a circle for the far side.
// NON_MATCHING: 44 instructions vs 46; the axis vector's components are kept in
// registers differently. Three variants tried.
void Unk80026864::fn_8003467C(EVec2* direction, float* angle) {
    EVec2 axis;
    axis.x = 1.0f;
    axis.y = 0.0f;
    float dot = axis.x * direction->x + direction->y * axis.y;
    float cosine = EABS(dot);
    double turned;
    if (direction->y * direction->x >= 0.0f) {
        turned = fn_8010D684(cosine);
    } else {
        turned = fn_8010D684(cosine) + 1.5707964f;
    }
    *angle = turned;
    float result = *angle;
    if (!unkF8) {
        result += 3.1415927f;
    }
    *angle = result;
}

// 0x80035724
void Unk80026864::fn_80035724(ERC* rc) {
    EVec2 from(unkD0, unkD4);
    EVec2 to(unkD8, unkDC);
    fn_80035774(rc, &from, &to);
}

// 0x80038014
// Whether another room may be made (fewer than twenty rooms are in use).
bool fn_80038014() {
    ((Unk8037D990B*)lbl_8037D990)->vfn34(0);
    int count = 0;
    Unk8037D998Table* table = (Unk8037D998Table*)lbl_8037D998;
    Unk8037D998Node* node = (Unk8037D998Node*)table->header->_M_left;
    while (NotAtEnd(node, table->header)) {
        Unk80235FD0* room = node->room;
        if (room->unk34 != 0 && !room->fn_80235FD0()) {
            count++;
        }
        node = (Unk8037D998Node*)_STL::_Rb_global<bool>::_M_increment(node);
    }
    return count <= 0x13;
}

// 0x80038424
// NON_MATCHING: 26 instructions vs 30: the original keeps `remove` in a saved
// register (and so has a larger frame). One variant tried.
int Unk80026864::fn_80038424(EVec2* from, EVec2* to, int* out, int arg, int remove) {
    int price;
    int kind;
    if (remove) {
        price = unkEC;
        kind = unk84;
    } else {
        kind = unk84;
        price = 0x46;
        if (kind != 3) {
            price = unk1C4;
        }
    }
    return fn_80038FC0(from, to, unk1C0, kind, out, arg, remove, price);
}

// 0x80038FC0
// Counts (and prices) the walls along a run; true when there are any.
int fn_80038FC0(EVec2* from, EVec2* to, int type, int kind, int* out, int arg, int remove, int price) {
    Unk801C6EF4 start;
    Unk801C6EF4 end;
    EVec2 a(*from);
    EVec2 b(*to);
    fn_8003739C(&a, &b, &start, &end);
    int direction = fn_800369A0(&start, &end);
    *out = 0;
    if (remove) {
        *out = fn_800390FC(&start, &end, &direction, &type, &kind, price);
    } else {
        *out = fn_8003930C(start, end, &direction, &type, &kind, price);
    }
    return *out != 0;
}

// 0x8003957C
int Unk80026864::fn_8003957C(void* a, void* b) {
    return fn_800395B0(a, b, unk1C0, unk84);
}

// 0x80039A40
int Unk80026864::fn_80039A40(void* a, void* b) {
    return fn_80039A70(a, b, unk84);
}
