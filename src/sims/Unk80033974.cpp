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

extern "C" double fn_8010D900(double); // sqrt

// The tile grid's cell size, in the view object at the global's +0xB0.
struct Unk80034734View {
    char unk0[0x34];
    float unk34;
    float unk38;
};
inline Unk80034734View* GetGrid() { return (Unk80034734View*)lbl_802E6700.unkA8[2]; }

struct Unk801C72D4 : Unk801C6EF4 {
    void fn_801C72D4(int y, int x, int);
};

inline bool SamePoint(const EVec2& a, const EVec2& b) {
    bool same = false;
    if (a.x == b.x) {
        same = a.y == b.y;
    }
    return same;
}

inline void NormalizeVec2(EVec2& v) {
    float length = fn_8010DF80(v.y * v.y + v.x * v.x);
    if (length != 0.0f) {
        float scale = 1.0f / length;
        v.y *= scale;
        v.x *= scale;
    }
}

// Whether the run directions in `flags` (1 diagonal, 2 straight; 0 = any) include `mask`.
inline bool AllowsRun(unsigned char flags, int mask) {
    return (flags & mask) || flags == 0;
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

// 0x80033DD8
// Snaps the dragged end of a wall run to a straight or diagonal line from its start.
// NON_MATCHING: 139 instructions vs 145; the slopes and signs are computed in a
// different order. One variant tried.
void Unk80026864::fn_80033DD8(EVec2* from, EVec2* to) {
    EVec2 cursor;
    fn_8002BC5C(&cursor);
    EVec2 delta(cursor.x - from->x, cursor.y - from->y);
    float rise = delta.y / delta.x;
    float run = delta.x / delta.y;
    float signX = delta.x < 0.0f ? -1.0f : 1.0f;
    float signY = delta.y < 0.0f ? -1.0f : 1.0f;
    float threshold = 1.0f / (delta.x * delta.x + delta.y * delta.y) * (-0.25f - 0.25f) + 0.25f + 0.5f;
    run = EABS(run);
    rise = EABS(rise);
    if (run == 1.0f) {
        *to = cursor;
        fn_80034734(to, from);
        return;
    }
    if (run < threshold) {
        delta.x = 0.0f;
    } else if (run >= threshold && run < 1.0f) {
        delta.x = signX * EABS(delta.y);
    } else if (rise < threshold) {
        delta.y = 0.0f;
    } else if (rise >= threshold && rise < 1.0f) {
        delta.y = signY * EABS(delta.x);
    }
    *to = EVec2(from->x + delta.x, from->y + delta.y);
    if (unk84 == 3 && unkCC) {
        return;
    }
    fn_80034734(to, from);
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

// 0x80034734
// Moves the start of a run one grid step back from the cursor along the run, and
// keeps it on the cursor's side of a straight run.
// NON_MATCHING: 4 instructions: the last comparison keeps from->y in f1, here f13.
// Four variants tried.
void Unk80026864::fn_80034734(EVec2* to, EVec2* from) {
    if (SamePoint(*to, *from)) {
        return;
    }
    EVec2 direction((*to - *from).Normalize());
    float step;
    if (direction.x == 0.0f || direction.y == 0.0f) {
        step = GetGrid()->unk34;
    } else {
        step = fn_8010D900(GetGrid()->unk34 * GetGrid()->unk34 + GetGrid()->unk38 * GetGrid()->unk38);
    }
    *from = unkB4 - step * direction;
    EVec2 back((*(EVec2*)&unkE0 - *from).Normalize());
    if (direction.x == 0.0f) {
        float x = from->x;
        if (unkE0 > x) {
            from->x = x + step;
        } else {
            from->x = x - step;
        }
    }
    if (direction.y == 0.0f) {
        float y = from->y;
        if (unkE4 > y) {
            from->y = y + step;
        } else {
            from->y = y - step;
        }
    }
}

// 0x80034E10
// Whether a diagonal wall crosses the tile under the cursor (and which diagonal).
// NON_MATCHING: 123 instructions vs 121; the two points are set up in a different
// order. One variant tried.
int Unk80026864::fn_80034E10(int* wall) {
    float size = GetGrid()->unk34;
    Unk801C6EF4 first;
    Unk801C6EF4 second;
    EVec2 a(unkAC, unkB0);
    EVec2 b;
    a.x -= GetGrid()->unk34;
    b.x = a.x + (size + size);
    b.y = a.y - GetGrid()->unk38;
    a.y = b.y;
    for (int i = 0; i <= 1; i++) {
        *wall = i == 0 ? 0x10 : 0x20;
        ((Unk801C72D4*)&first)->fn_801C72D4((int)a.y, (int)a.x, 1);
        ((Unk801C72D4*)&second)->fn_801C72D4((int)b.y, (int)b.x, 1);
        Unk8037D990H* level = (Unk8037D990H*)lbl_8037D990;
        int direction = fn_800369A0(&first, &second);
        if (!level->vfn8(&second) && direction != 8) {
            Unk8023E110 info = level->vfn18(&second);
            if (info.fn_8023DEA4(*wall)) {
                return 1;
            }
        }
    }
    return 0;
}

// 0x80034FF4
// Whether there is a wall on the tile under the cursor; gives its description.
// NON_MATCHING: 123 instructions vs 124; as fn_80034E10. One variant tried.
int Unk80026864::fn_80034FF4(int* out) {
    float size = GetGrid()->unk34;
    Unk801C6EF4 first;
    Unk801C6EF4 second;
    EVec2 a(unkAC, unkB0);
    EVec2 b;
    a.x -= GetGrid()->unk34;
    b.x = a.x + (size + size);
    a.y -= GetGrid()->unk38;
    b.y = a.y;
    ((Unk801C72D4*)&first)->fn_801C72D4((int)a.y, (int)a.x, 1);
    ((Unk801C72D4*)&second)->fn_801C72D4((int)b.y, (int)b.x, 1);
    Unk8037D990P* level = (Unk8037D990P*)lbl_8037D990;
    int direction = fn_800369A0(&first, &second);
    if (!level->vfn8(&second) && direction != 8) {
        if (level->vfn18(&second).fn_8023DEBC()) {
            *out = *(int*)&level->vfn18(&second);
            return 1;
        }
    }
    return 0;
}

// 0x800351E4
// Works out both ends of the wall under the cursor and where its marker goes.
// NON_MATCHING: 137 instructions vs 148; draft, the vector temporaries are not
// laid out as in the original. One variant tried.
void Unk80026864::fn_800351E4(EVec2* a, EVec2* b, int wall, float* angle, EVec2* out) {
    fn_80035434(a, b, angle, wall);
    *out = *b;
    EVec3 offset;
    fn_80033278(a, out, &offset);
    if (offset.x != 0.0f || offset.y != 0.0f || offset.z != 0.0f) {
        fn_801221E4(&offset, &offset);
    }
    float step = fn_8010D900(GetGrid()->unk34 * GetGrid()->unk34 + GetGrid()->unk38 * GetGrid()->unk38);
    EVec3 scaled(step * offset.x, step * offset.y, step * offset.z);
    EVec2 plus(unkB4.x + scaled.x, unkB4.y + scaled.y);
    EVec3 direction(step * offset.x, step * offset.y, step * offset.z);
    EVec2 minus(unkB4.x - direction.x, unkB4.y - direction.y);
    if (unk84 == 4 || (unk88 & 4)) {
        *b = minus;
        *a = plus;
        direction.x = offset.x;
        direction.y = offset.y;
        fn_8003467C((EVec2*)&direction, angle);
    }
    fn_80033278(&plus, &minus, &direction);
    if (direction.x != 0.0f || direction.y != 0.0f || direction.z != 0.0f) {
        fn_801221E4(&direction, &direction);
    }
    EVec3 moved(step * direction.x, step * direction.y, step * direction.z);
    *out = EVec2(unkB4.x + moved.x, unkB4.y + moved.y);
}

// 0x80035434
// The two ends of the diagonal wall under the cursor and the angle of its marker.
// NON_MATCHING: 191 instructions vs 188; draft, the two cases share their tail
// differently. One variant tried.
void Unk80026864::fn_80035434(EVec2* a, EVec2* b, float* angle, int wall) {
    fn_80034E10(&wall);
    float step = fn_8010D900(GetGrid()->unk34 * GetGrid()->unk34 + GetGrid()->unk38 * GetGrid()->unk38);
    EVec2 direction;
    bool flip;
    if (wall == 0x20) {
        direction = EVec2(1.0f, 1.0f);
        NormalizeVec2(direction);
        int side = fn_80034968(a, b);
        if (side >= 0 && (side <= 1 || (side <= 5 && side >= 4))) {
            *angle = 2.3561945f;
            flip = true;
        } else {
            *angle = 5.4977875f;
            flip = false;
        }
    } else {
        direction = EVec2(-1.0f, 1.0f);
        NormalizeVec2(direction);
        switch (fn_80034968(a, b)) {
        case 1:
        case 2:
        case 4:
        case 6:
            *angle = 3.926991f;
            flip = true;
            break;
        default:
            *angle = 0.7853982f;
            flip = false;
            break;
        }
    }
    if (flip) {
        direction = EVec2(-direction.x, -direction.y);
    }
    EVec2 scaled(step * direction.x, step * direction.y);
    *a = EVec2(unkB4.x + scaled.x, unkB4.y + scaled.y);
    EVec3 offset;
    fn_80033278(&unkB4, a, &offset);
    if (offset.x != 0.0f || offset.y != 0.0f || offset.z != 0.0f) {
        fn_801221E4(&offset, &offset);
    }
    *b = *a;
    b->x += (step + step) * offset.x;
    b->y += (step + step) * offset.y;
}

// 0x80035724
void Unk80026864::fn_80035724(ERC* rc) {
    EVec2 from(unkD0, unkD4);
    EVec2 to(unkD8, unkDC);
    fn_80035774(rc, &from, &to);
}

// 0x80035774
// Draws one stretch of wall or fence preview, in the "cannot build" texture when
// the run's direction is not allowed.
// NON_MATCHING: same length (147), 28 instructions: the registers of the two
// texture pointers are exchanged and the copy sits before the test. Four variants.
void Unk80026864::fn_80035774(ERC* rc, EVec2* from, EVec2* to) {
    float height;
    if (unk84 == 5) {
        height = 1.0f;
    } else {
        height = 3.0f;
    }
    EVec2 direction((*(EVec2*)&unkD8 - *(EVec2*)&unkD0).Normalize());
    float base = 1.0f;
    Unk80181824* texture;
    int flag;
    if (unk84 == 3) {
        texture = (Unk80181824*)lbl_8037B4AC;
        flag = 2;
    } else {
        if (*(unsigned int*)((char*)unk104 + 4) == 0xDB6A33BD) {
            texture = (Unk80181824*)lbl_80340AB8.fn_80177628(0x71BA2E9A, 0, 0);
            base = 2.0f;
        } else {
            texture = (Unk80181824*)unk104;
        }
        flag = 1;
    }
    Unk80181824* shown = texture;
    if (!((direction.x == 0.0f || direction.y == 0.0f) ? AllowsRun(unkCC, 2) : AllowsRun(unkCC, 1))) {
        shown = (Unk80181824*)lbl_8037B4B4;
        flag = 0;
    }
    void* handle = *(void**)((char*)shown + 4);
    fn_801E36E4b(lbl_802E6700.unk120, 5, 0, &unkD0, &unkD4, &unkD8, &unkDC, 0, 0, &handle, (int)&unk84);
    fn_80031CF0(rc, shown, from, to, flag, height, base);
    if (unk84 != 3 && *(unsigned int*)((char*)unk104 + 4) == 0xDB6A33BD && texture) {
        fn_801767FC(texture);
    }
}

// 0x800359C0
// Draws the wall or fence run being dragged.
// NON_MATCHING: 98 instructions vs 99; as fn_80031B1C. One variant tried.
void Unk80026864::fn_800359C0(ERC* rc) {
    EVec2 from(unkD0, unkD4);
    EVec2 to(unkD8, unkDC);
    EVec3 offset;
    int unused;
    fn_80033278(&from, &to, &offset);
    from += *(EVec2*)&offset;
    to += *(EVec2*)&offset;
    float height;
    if (unk84 == 5) {
        height = 1.5f;
    } else {
        height = 3.5f;
    }
    unkE8 = fn_8003849C(rc, &from, &to, (Unk80181824*)lbl_8037B4B8, &unkEC, unk84, unkF8 == 0);
    Unk80181824* texture;
    if (unkE8) {
        texture = lbl_8037B4B0;
    } else {
        texture = (Unk80181824*)lbl_8037B4B4;
    }
    void* handle = *(void**)((char*)texture + 4);
    fn_801E36E4b(lbl_802E6700.unk120, 6, 0, &unkD0, &unkD4, &unkD8, &unkDC, &offset, &unused, &handle, (int)&unk84);
    fn_80031CF0(rc, texture, (EVec2*)&unkD0, (EVec2*)&unkD8, 0, height, 0.0f);
}

// 0x80035B4C
// Draws the four sides of the room being dragged out.
void Unk80026864::fn_80035B4C(ERC* rc) {
    EVec2 start(unkD0, unkD4);
    EVec2 cursor;
    fn_8002BC5C(&cursor);
    EVec2 a;
    a = start;
    EVec2 b;
    b.x = cursor.x;
    b.y = start.y;
    fn_80035774(rc, &a, &b);
    a = b;
    b = cursor;
    fn_80035774(rc, &a, &b);
    a = b;
    b.x = start.x;
    b.y = cursor.y;
    fn_80035774(rc, &a, &b);
    a = b;
    b = start;
    fn_80035774(rc, &a, &b);
}

// 0x800369A0
// The direction (0 to 7) from one tile corner to another, 8 when they are the same.
// NON_MATCHING: 2 instructions: `nor r0; srwi r3, r0` for the first result, here
// the nor goes straight into r3. Two variants tried.
int fn_800369A0(Unk801C6EF4* from, Unk801C6EF4* to) {
    if (*from == *to) {
        return 8;
    }
    Unk801C727C* a = (Unk801C727C*)from;
    Unk801C727C* b = (Unk801C727C*)to;
    int ax = a->fn_801C727C();
    int ay = a->fn_801C7288();
    int dx = b->fn_801C727C() - ax;
    int dy = b->fn_801C7288() - ay;
    int bu = b->fn_801C7204();
    int bv = b->fn_801C721C();
    int au = a->fn_801C7204();
    int av = a->fn_801C721C();
    int width = __builtin_abs(dx);
    int height = __builtin_abs(dy);
    int halfV = __builtin_abs(bv - av) / 2;
    int halfU = __builtin_abs(bu - au) / 2;
    if (width < height && width <= halfV && width <= halfU) {
        return dy < 0 ? 0 : 1;
    }
    if (height < width && height <= halfV && height <= halfU) {
        return dx < 0 ? 2 : 3;
    }
    if (halfV < width && halfV < height && halfV < halfU) {
        return bu < au ? 4 : 5;
    }
    return bv < av ? 7 : 6;
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
