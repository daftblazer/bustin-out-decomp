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

// One side's worth of wall data on a tile, with the operations this file uses.
struct Unk8023E1C4 : Unk8023DD8C {
    int fn_8023E1C4(int wall);          // what is built on a wall
    int fn_8023E420(int half);
    void fn_8023E2FC(int wall);         // remove a wall
    int fn_8023DF40(int wall);
    int fn_8023D9B8(int wall);
};
struct Unk8037D990Q {
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual int vfn8(Unk801C6EF4* tile);
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual int vfn14(Unk801C6EF4* tile);
    virtual void vfn15(Unk801C6EF4* tile, int type);
    virtual void vfn16();
    virtual void vfn17();
    virtual Unk8023DFA8 vfn18(Unk801C6EF4* tile);
    virtual void vfn19(Unk801C6EF4* tile, Unk8023DDC4* packed);
};
int fn_8023E488(int wall, int turn);
extern float lbl_8037DA20;
struct Unk8037D98CC {
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11(void* object);
};
int fn_80036B14(Unk801C6EF4* tile, int wall, int* refund);
int fn_80036D1C(Unk801C6EF4* tile, Unk8023E1C4* info, int wall, int arg, int kind);
int fn_80036EAC(Unk801C6EF4* tile, int wall);
int fn_80037140(Unk801C6EF4* tile, Unk8023E1C4* info, int wall, int type, int kind);
int fn_80038A7C(ERC* rc, EVec2* a, EVec2* b, Unk80181824* texture, int flag);
void fn_80035C70(ERC* rc, void* texture, EVec2* a, EVec2* b, int* flag);

inline bool IsFenceLike(int type) {
    return type == 3 || type == 5 || type == 6 || type == 0xF || type == 0x17;
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
void Unk80026864::fn_80033C3C() {
    EController* controller = lbl_8037C11C->fn_8015E5FC(lbl_8037C11C->fn_8015E614(unk38));
    if (controller->fn_8015DF98(0x11) && controller->fn_8015E0F8(5)) {
        if (!fn_80037C34()) {
            lbl_8037D96C->fn_8006186C(0x3804219F);
        }
        unk88 = 0;
    } else if ((unk88 & 1) == 0) {
        if (controller->fn_8015E0F8(5)) {
            unk88 |= 3;
        } else if ((unk88 & 1) == 0 && controller->fn_8015E0F8(0xF)) {
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
        unk88 &= ~1;
        unk88 &= ~4;
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

// 0x8003401C
// Places the marker of the wall tool: snaps the cursor, and when it is on a wall
// works out that wall's ends, angle and length.
// NON_MATCHING: skeleton (408 instructions in the original): the calls are the
// original's, in its order; the arithmetic between them is not reconstructed.
int Unk80026864::fn_8003401C(EVec2* from, EVec2* to, float* scale) {
    int wall;
    float angle = 0.0f;
    EVec2 marker;
    EVec3 offset;
    fn_80033DD8(from, to);
    if (fn_80034FF4(&wall)) {
        fn_800351E4(from, to, wall, &angle, &marker);
    }
    int side = fn_80034968(from, to);
    side = fn_80034968(from, to);
    float length = fn_8010DF80((to->x - from->x) * (to->x - from->x) + (to->y - from->y) * (to->y - from->y));
    fn_80033278(from, to, &offset);
    fn_801221E4(&offset, &offset);
    float step = fn_8010D900(GetGrid()->unk34 * GetGrid()->unk34 + GetGrid()->unk38 * GetGrid()->unk38);
    fn_8003467C((EVec2*)&offset, &angle);
    *scale = length / step;
    return side;
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
    float value;
    if (direction.x == 0.0f) {
        float x = from->x;
        if (unkE0 > x) {
            from->x = x + step;
        } else {
            from->x = x - step;
        }
    }
    if (direction.y == 0.0f) {
        from->y = unkE4 > from->y ? from->y + step : from->y - step;
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

// 0x80035C70
// Draws a stretch of wall preview as two textured quads (both faces).
// NON_MATCHING: skeleton (844 instructions in the original, which fills sixteen
// vertices in the open and draws four strips); here it draws through fn_80031CF0.
void fn_80035C70(ERC* rc, void* texture, EVec2* a, EVec2* b, int* flag) {
    fn_80031CF0(rc, (Unk80181824*)texture, a, b, *flag, 3.0f, 0.0f);
    fn_80031CF0(rc, (Unk80181824*)texture, b, a, *flag, 3.0f, 0.0f);
}

// 0x800369A0
// The direction (0 to 7) from one tile corner to another, 8 when they are the same.
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
    int result;
    if (width < height && width <= halfV && width <= halfU) {
        result = dy >= 0;
    } else if (height < width && height <= halfV && height <= halfU) {
        result = dx < 0 ? 2 : 3;
    } else if (halfV < width && halfV < height && halfV < halfU) {
        result = bu < au ? 4 : 5;
    } else {
        result = bv < av ? 7 : 6;
    }
    return result;
}

// 0x80036B14
// Looks for an object hung on one side of a wall; when there is one, adds what it
// is worth to `refund` and has it removed.
// NON_MATCHING: 126 instructions vs 130; the calls and tests are the original's,
// the loop is laid out differently. One variant tried.
int fn_80036B14(Unk801C6EF4* tile, int wall, int* refund) {
    int found = 0;
    *refund = 0;
    Unk801FCE7C it(*(Unk801C6F20*)tile, 0);
    Unk800053D4Inner* hit = 0;
    while (it.unk4) {
        Unk800053D4Inner* object = it.unk4;
        if (object->vfn109() == 8 && object->vfn109() != 2) {
            int flags = object->vfn88(0xD);
            int sides = flags;
            int side = fn_8023E488(wall, ((8 - object->vfn88(1)) >> 1) & 3);
            if ((side == 1 && (flags & 8)) || (side == 8 && (flags & 4)) || (side == 2 && (flags & 1)) ||
                (side == 4 && (sides & 2))) {
                hit = object;
                break;
            }
        }
        it.fn_801FCF04();
    }
    if (hit) {
        found = 1;
        *refund += (int)((float)hit->vfn131() * lbl_8037DA20 + 0.5f);
        ((Unk8037D98CC*)lbl_8037D98C)->vfn11(hit->vfn111());
    }
    return found;
}

// 0x80036D1C
// Removes one wall from a tile (with anything hung on it); returns what that costs.
// NON_MATCHING: 101 instructions vs 100; register allocation differs from the
// first call on. One variant tried.
int fn_80036D1C(Unk801C6EF4* tile, Unk8023E1C4* info, int wall, int arg, int kind) {
    if (!fn_80039A70(tile, (void*)wall, kind)) {
        return 0;
    }
    Unk8037D990Q* level = (Unk8037D990Q*)lbl_8037D990;
    Unk801C6EF4 scratch;
    int refund = 0;
    int amount = 0;
    int type = info->fn_8023E1C4(wall);
    if (IsFenceLike(type) || type == 0x16) {
        if (fn_80036B14(tile, wall, &amount)) {
            refund = -amount;
        }
    }
    if (wall == 0x10 || wall == 0x20) {
        if (level->vfn14(tile) == 0xFF) {
            level->vfn15(tile, info->fn_8023E420(wall == 0x10 ? 4 : 3));
        }
    }
    info->fn_8023E2FC(wall);
    Unk8023DDC4 packed(*(Unk8023DFA8*)info);
    level->vfn19(tile, &packed);
    return refund;
}

// 0x80036EAC
// Whether a wall may be removed: nothing stands against it on either side.
// NON_MATCHING: skeleton (165 instructions in the original, which also looks at the
// neighbouring tile and at the objects' footprints).
int fn_80036EAC(Unk801C6EF4* tile, int wall) {
    Unk8037D990Q* level = (Unk8037D990Q*)lbl_8037D990;
    if (wall == 0 && level->vfn8(tile)) {
        return 0;
    }
    Unk801FCE7C it(*(Unk801C6F20*)tile, 0);
    while (it.unk4) {
        Unk800053D4Inner* object = it.unk4;
        if (object->vfn88(0xD) != 0 && object->vfn109() == 8) {
            return 0;
        }
        it.fn_801FCF04();
    }
    return 1;
}

// 0x80037140
// Builds one wall on a tile, replacing what is there, and returns what it costs.
// NON_MATCHING: skeleton (151 instructions in the original): the checks and the
// final store are the original's, the handling of the diagonal cases is not
// reconstructed.
int fn_80037140(Unk801C6EF4* tile, Unk8023E1C4* info, int wall, int type, int kind) {
    if (!fn_800395B0(tile, info, type, kind)) {
        return 0;
    }
    Unk8037D990Q* level = (Unk8037D990Q*)lbl_8037D990;
    if (info->fn_8023DEA4(wall)) {
        if (info->fn_8023E1C4(wall) == type) {
            return 0;
        }
    }
    ((Unk8023E110*)info)->fn_8023E110(type, wall, 0);
    Unk8023DDC4 packed(*(Unk8023DFA8*)info);
    level->vfn19(tile, &packed);
    int refund = 0;
    if (IsFenceLike(info->fn_8023E1C4(wall))) {
        fn_80036B14(tile, wall, &refund);
    }
    return 1;
}

// 0x8003739C
// Turns the two ends of a run on the ground into tile corners, nudged so that the
// run covers the tiles it should for each of the eight directions.
// NON_MATCHING: 168 instructions vs 171; the cases are the original's, the shared
// tails of the adjustments are merged differently. One variant tried.
void fn_8003739C(EVec2* from, EVec2* to, Unk801C6EF4* start, Unk801C6EF4* end) {
    EVec2 a(*from);
    EVec2 b;
    a = EVec2(a.x - 0.5f, a.y + 0.5f);
    b.x = to->x;
    b.y = to->y;
    b = EVec2(b.x - 0.5f, b.y + 0.5f);
    EVec2 delta(to->x - from->x, to->y - from->y);
    int signX = 1;
    if (delta.x < 0.0f) {
        signX = -1;
    }
    int signY = 1;
    if (delta.y < 0.0f) {
        signY = -1;
    }
    if (delta.x == 0.0f) {
        if (signY > 0) {
            a.y += 1.0f;
            b.y += 1.0f;
        }
        a.x += 1.0f;
        b.x += 1.0f;
        a.y -= 1.0f;
        b.y -= 1.0f;
    } else if (delta.y == 0.0f) {
        if (signX > 0) {
            a.y -= 1.0f;
            b.y -= 1.0f;
        } else {
            a.y -= 1.0f;
            b.y -= 1.0f;
            a.x -= 1.0f;
            b.x -= 1.0f;
        }
        a.x += 1.0f;
        b.x += 1.0f;
        a.y += 1.0f;
        b.y += 1.0f;
    } else if (signX < 0 && signY < 0) {
        a.y -= 1.0f;
        b.y -= 1.0f;
    } else if (signX > 0) {
        if (signY < 0) {
            a.x += 1.0f;
            b.x += 1.0f;
            a.y -= 1.0f;
            b.y -= 1.0f;
        } else if (signY > 0) {
            a.x += 1.0f;
            b.x += 1.0f;
        }
    }
    ((Unk801C72D4*)start)->fn_801C72D4((int)a.y, (int)a.x, 1);
    ((Unk801C72D4*)end)->fn_801C72D4((int)b.y, (int)b.x, 1);
}

// 0x80037648
// Builds the wall or fence run that was dragged out.
// NON_MATCHING: skeleton (174 instructions in the original): the order of the
// checks (can build, money, room limit) and the calls are the original's; the
// undo-history bookkeeping around them is left out.
int Unk80026864::fn_80037648() {
    EVec2 from(unkD0, unkD4);
    EVec2 to(unkD8, unkDC);
    int count = 0;
    if (!fn_80037900(&from, &to, &count)) {
        lbl_8037D96C->fn_8006186C(0x3804219F);
        return 0;
    }
    int cost = fn_80033974();
    if (!CheatMoney() && cost > ((Unk8037D944C*)lbl_8037D944)->vfn25(0)) {
        lbl_8037D96C->fn_8006186C(0x3804219F);
        return 0;
    }
    int built = 0;
    if (!fn_80038424(&from, &to, &built, 0, 0)) {
        lbl_8037D96C->fn_8006186C(0x3804219F);
        return 0;
    }
    lbl_8037D96C->fn_8006186C(0xB2AD3ECD);
    ((Unk8037D944C*)lbl_8037D944)->vfn26(7, cost, 0);
    lbl_8037D96C->fn_8006186C(0x994E8974);
    fn_80028ECC();
    return 1;
}

// 0x80037900
// Checks every tile along a run: whether a wall may be built (or removed) there.
// `out` gets the number of tiles that pass.
// NON_MATCHING: skeleton (205 instructions in the original): the walk and its calls
// are the original's, the bookkeeping per tile is simplified.
int Unk80026864::fn_80037900(EVec2* from, EVec2* to, int* out) {
    *out = 0;
    Unk801C6EF4 start;
    Unk801C6EF4 end;
    fn_8003739C(from, to, &start, &end);
    int direction = fn_800369A0(&start, &end);
    int wall = fn_8023DC04(direction);
    Unk801C6EF4 current(start);
    Unk8037D990Q* level = (Unk8037D990Q*)lbl_8037D990;
    int ok = 1;
    while (!level->vfn8(&current) && !(current == end)) {
        if (!fn_8003957C(&current, (void*)wall) || !fn_80039A40(&current, (void*)wall)) {
            ok = 0;
        } else {
            Unk8023E1C4 info;
            info.fn_8023DE48(level->vfn18(&current));
            fn_80033814(info.fn_8023E1C4(wall));
            *out += 1;
        }
        current = current + lbl_8035ABB0[direction];
    }
    if (CheatMoney()) {
        return 1;
    }
    return ok;
}

// 0x80037C34
// Builds the four walls of the room that was dragged out.
// NON_MATCHING: skeleton (248 instructions in the original): the four sides are
// checked and then built in the original's order; the undo-history bookkeeping
// is left out.
int Unk80026864::fn_80037C34() {
    EVec2 start(unkD0, unkD4);
    EVec2 cursor;
    fn_8002BC5C(&cursor);
    EVec2 corners[5];
    corners[0] = start;
    corners[1] = EVec2(cursor.x, start.y);
    corners[2] = cursor;
    corners[3] = EVec2(start.x, cursor.y);
    corners[4] = start;
    int count = 0;
    int i;
    for (i = 0; i < 4; i++) {
        if (!fn_80037900(&corners[i], &corners[i + 1], &count)) {
            return 0;
        }
    }
    int cost = fn_80033974();
    if (!CheatMoney() && cost > ((Unk8037D944C*)lbl_8037D944)->vfn25(0)) {
        return 0;
    }
    int built = 0;
    for (i = 0; i < 4; i++) {
        fn_80038424(&corners[i], &corners[i + 1], &built, 0, 0);
    }
    lbl_8037D96C->fn_8006186C(0xB2AD3ECD);
    ((Unk8037D944C*)lbl_8037D944)->vfn26(7, cost, 0);
    lbl_8037D96C->fn_8006186C(0x994E8974);
    fn_80028ECC();
    return 1;
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

// 0x800380C4
// Removes the wall or fence run that was dragged out and pays the refund.
// NON_MATCHING: skeleton (216 instructions in the original): the calls are the
// original's; the undo-history bookkeeping and the room-count check after the
// removal are left out.
int Unk80026864::fn_800380C4() {
    EVec2 from(unkD0, unkD4);
    EVec2 to(unkD8, unkDC);
    int removed = 0;
    if (!fn_80038424(&from, &to, &removed, 0, 1)) {
        lbl_8037D96C->fn_8006186C(0x3804219F);
        return 0;
    }
    if (!fn_80038014()) {
        return 0;
    }
    Unk801C6EF4 start;
    Unk801C6EF4 end;
    fn_8003739C(&from, &to, &start, &end);
    int wall = fn_8023DC04(fn_800369A0(&start, &end));
    lbl_8037D96C->fn_8006186C(0x994E8974);
    ((Unk8037D944C*)lbl_8037D944)->vfn26(6, fn_80033974(), 0);
    lbl_8037D96C->fn_8006186C(0xB2AD3ECD);
    fn_80028ECC();
    return 1;
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

// 0x8003849C
// Draws the preview of a run tile by tile and counts the walls it covers;
// `total` gets what removing them gives back.
// NON_MATCHING: skeleton (376 instructions in the original, which repeats the walk
// of fn_80038A7C with the pricing added).
int fn_8003849C(ERC* rc, EVec2* a, EVec2* b, Unk80181824* texture, void* total, int kind, int flag) {
    int count = fn_80038A7C(rc, a, b, texture, flag);
    Unk801C6EF4 start;
    Unk801C6EF4 end;
    fn_8003739C(a, b, &start, &end);
    int direction = fn_800369A0(&start, &end);
    int wall = fn_8023DC04(direction);
    Unk8037D990Q* level = (Unk8037D990Q*)lbl_8037D990;
    Unk801C6EF4 current(start);
    int refund = 0;
    while (!level->vfn8(&current) && !(current == end)) {
        Unk8023E1C4 info;
        info.fn_8023DE48(level->vfn18(&current));
        if (info.fn_8023DED4(wall) && info.fn_8023DF40(wall)) {
            refund += fn_80033814(info.fn_8023E1C4(wall));
        }
        ((Unk801C711C*)&current)->fn_801C70F4(&lbl_8035ABB0[direction]);
    }
    *(int*)total = refund;
    return count;
}

// 0x80038A7C
// Draws the preview of a run tile by tile and counts the walls it covers.
// NON_MATCHING: skeleton (337 instructions in the original, which fills the
// vertices of each tile's quad in the open).
int fn_80038A7C(ERC* rc, EVec2* a, EVec2* b, Unk80181824* texture, int flag) {
    Unk801C6EF4 start;
    Unk801C6EF4 end;
    fn_8003739C(a, b, &start, &end);
    int direction = fn_800369A0(&start, &end);
    if (direction == 8) {
        return 0;
    }
    int wall = fn_8023DC04(direction);
    Unk8037D990Q* level = (Unk8037D990Q*)lbl_8037D990;
    Unk801C6EF4 current(start);
    texture->fn_80181824(rc);
    int count = 0;
    while (!level->vfn8(&current) && current != end) {
        Unk8023E1C4 info;
        info.fn_8023DE48(level->vfn18(&current));
        if (info.fn_8023DED4(wall)) {
            count++;
        }
        ((Unk801C711C*)&current)->fn_801C70F4(&lbl_8035ABB0[direction]);
    }
    return count;
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

// 0x800390FC
// Removes every wall along a run; returns how many were removed.
// NON_MATCHING: 93 instructions vs 132; draft, the calls are the original's but
// the loop's bookkeeping is simplified. One variant tried.
int fn_800390FC(Unk801C6EF4* start, Unk801C6EF4* end, int* direction, int* type, int* kind, int price) {
    Unk801C6EF4 current(*start);
    int wall = fn_8023DC04(*direction);
    Unk8023E1C4 info;
    Unk8037D990Q* level = (Unk8037D990Q*)lbl_8037D990;
    int count = 0;
    do {
        info.fn_8023DE48(level->vfn18(&current));
        if (info.fn_8023DED4(wall) && info.fn_8023DF40(wall) && fn_80039A70(&current, (void*)wall, *kind)) {
            count += fn_80036D1C(&current, &info, wall, *type, *kind);
            count++;
        }
        ((Unk801C711C*)&current)->fn_801C70F4(&lbl_8035ABB0[*direction]);
    } while (!(current == *end) && !level->vfn8(&current));
    return count;
}

// 0x8003930C
// Builds a wall on every tile along a run; returns how many were built.
// NON_MATCHING: 88 instructions vs 156; draft, the original also handles the tile
// before the first one and removes a crossing wall. One variant tried.
int fn_8003930C(Unk801C6EF4 start, Unk801C6EF4 end, int* direction, int* type, int* kind, int price) {
    Unk801C6EF4 current(start);
    int wall = fn_8023DC04(*direction);
    Unk8023E1C4 info;
    Unk8037D990Q* level = (Unk8037D990Q*)lbl_8037D990;
    int count = 0;
    do {
        info.fn_8023DE48(level->vfn18(&current));
        if (!info.fn_8023D9B8(wall)) {
            count += fn_80037140(&current, &info, wall, *type, *kind);
        }
        ((Unk801C711C*)&current)->fn_801C70F4(&lbl_8035ABB0[*direction]);
    } while (!(current == end) && !level->vfn8(&current));
    return count;
}

// 0x8003957C
int Unk80026864::fn_8003957C(void* a, void* b) {
    return fn_800395B0(a, b, unk1C0, unk84);
}

// 0x800395B0
// Whether a wall of the given type may be built on a tile: nothing in the way on
// either side, and the neighbouring tiles agree.
// NON_MATCHING: skeleton (292 instructions in the original, which walks the
// objects on this tile and on the two neighbours).
int fn_800395B0(void* a, void* b, int type, int kind) {
    Unk801C6EF4* tile = (Unk801C6EF4*)a;
    Unk8023E1C4* info = (Unk8023E1C4*)b;
    Unk8037D990Q* level = (Unk8037D990Q*)lbl_8037D990;
    if (level->vfn18(tile).fn_8023DEA4(type)) {
        return 0;
    }
    if (!fn_80039A70(a, b, kind)) {
        return 0;
    }
    return fn_80036EAC(tile, type);
}

// 0x80039A40
int Unk80026864::fn_80039A40(void* a, void* b) {
    return fn_80039A70(a, b, unk84);
}

// 0x80039A70
// Whether the wall on one side of a tile may be changed: no object hangs on it or
// stands against it, here or on the tile across.
// NON_MATCHING: skeleton (258 instructions in the original, which also checks the
// tile across the wall).
int fn_80039A70(void* a, void* b, int kind) {
    Unk801C6EF4* tile = (Unk801C6EF4*)a;
    int wall = (int)b;
    Unk8037D990Q* level = (Unk8037D990Q*)lbl_8037D990;
    Unk8023DFA8 info = level->vfn18(tile);
    if (!info.fn_8023DEA4(wall)) {
        return 1;
    }
    Unk801FCE7C it(*(Unk801C6F20*)tile, 0);
    while (it.unk4) {
        Unk800053D4Inner* object = it.unk4;
        if (object->vfn109() == 8 && object->vfn109() != 2) {
            int flags = object->vfn88(0xD);
            int side = fn_8023E488(wall, ((8 - object->vfn88(1)) >> 1) & 3);
            if ((side == 1 && (flags & 8)) || (side == 8 && (flags & 4)) || (side == 2 && (flags & 1)) ||
                (side == 4 && (flags & 2))) {
                return 0;
            }
        }
        it.fn_801FCF04();
    }
    return 1;
}
