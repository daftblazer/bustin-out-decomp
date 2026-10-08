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
#include "sims/Unk80026864Private.h"

// The wall and wallpaper tools of build mode: part of Unk80026864 and its helpers.

// The counted pointer arrays of the catalogue, read through inline accessors.
struct Unk8003210CList {
    Unk802E67C0Entry** unk0;
    int GetSize() const { return unk0 ? ((int*)unk0)[-1] : 0; }
    Unk802E67C0Entry*& At(int i) { return unk0[i]; }
};

// Releasing a resource is a statement macro in the original: the `do { } while (0)`
// keeps the first load of the pointer behind the stores that precede it
// (fn_800318B0 only matches this way).
#define UNK_RELEASE_801767FC(p) \
    do { \
        if (p) { \
            fn_801767FC(p); \
            p = 0; \
        } \
    } while (0)

// A flat vector made from the first two components of an EVec3. In the original
// this is presumably a constructor of EVec2 itself (EVec2(const EVec3&)).
struct Unk80033484Vec2 : EVec2 {
    Unk80033484Vec2(const EVec3& v) : EVec2(v.x, v.y) {}
};

// What stands on a tile (0x38 bytes). The shared header spreads this class over a
// chain of placeholder structs that inherit Unk8023DFA8's destructor; the code here
// only matches when the class has its own destructor, and when the functions that
// are ignored at the call site still return something (assignment and the setter
// return a reference: the call then loads its arguments before `this`).
struct Unk800315FCInfo : Unk8023E088 {
    Unk800315FCInfo();                                           // 0x8023DD8C
    ~Unk800315FCInfo();                                          // 0x8023DE20
    Unk800315FCInfo& fn_8023DE48(const Unk8023DFA8& other);      // 0x8023DE48, operator=
    int fn_8023DED4(int wall);
    Unk800315FCInfo& fn_8023E110(int arg, int wall, int side);   // 0x8023E110
};
// The tile position's += and -= with a direction step; they return the tile.
struct Unk800315FCTile : Unk801C6EF4 {
    Unk800315FCTile& fn_801C711C(const Unk8035ABB0* step);       // 0x801C711C, +=
    Unk800315FCTile& fn_801C70F4(const Unk8035ABB0* step);       // 0x801C70F4, -=
};

// The level's tile grid, with the tile contents returned as the class above.
struct Unk800315FCLevel {
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual int vfn6();
    virtual void vfn7();
    virtual int vfn8(Unk801C6EF4* tile);
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual Unk800315FCInfo vfn18(Unk801C6EF4* tile);
    virtual void vfn19(Unk801C6EF4* tile, Unk8023DDC4* packed);
};
// The room list at lbl_8037D998: slot 19 is called after walls have changed.
struct Unk800315FCRooms {
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
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
};

// 0x800315FC
// Puts the two ends of a wall run in a fixed order (lower first), and moves the run
// one tile along when that changed its first end.
void fn_800315FC(Unk801C6EF4* start, Unk801C6EF4* end) {
    Unk801C6EF4 a(*start);
    Unk801C6EF4 b(*end);
    if (a.x == b.x) {
        signed char lo = a.y < b.y ? a.y : b.y;
        signed char hi = a.y > b.y ? a.y : b.y;
        a.y = lo;
        b.y = hi;
        if (a != *start) {
            a.y++;
            b.y++;
        }
    } else if (a.y == b.y) {
        signed char lo = a.x < b.x ? a.x : b.x;
        signed char hi = a.x > b.x ? a.x : b.x;
        a.x = lo;
        b.x = hi;
        if (a != *start) {
            a.x++;
            b.x++;
        }
    } else {
        float slope = (float)(b.y - a.y) / (float)(b.x - a.x);
        if (slope > 0.0f) {
            if (a.x > b.x) {
                Unk801C6EF4 swap(a);
                a = b;
                b = swap;
            }
            if (a != *start) {
                a.y++;
                a.x++;
                b.y++;
                b.x++;
            }
        } else {
            if (a.y > b.y) {
                Unk801C6EF4 swap(a);
                a = b;
                b = swap;
            }
            if (a != *start) {
                a.y++;
                a.x--;
                b.y++;
                b.x--;
            }
        }
    }
    *start = a;
    *end = b;
}

// 0x800318B0
// Starts the wallpaper tool with a covering from the catalogue.
void Unk80026864::fn_800318B0(Unk800318B0Tool* tool) {
    unk84 = 4;
    unk88 = 0;
    UNK_RELEASE_801767FC(unk104);
    unk1C4 = tool->unk0;
    unk1A0 = tool;
    unk104 = lbl_80340AB8.fn_80177628(tool->unk8, 0, 0);
}

// 0x80031928
void Unk80026864::fn_80031928() {
    if (unk84 == 4) {
        unk84 = 0;
        unk88 = 0;
    }
    UNK_RELEASE_801767FC(unk104);
}

// 0x80031980
// The wallpaper tool's buttons. unk88: bit 0 a run is being dragged, bit 1 to paper
// it, bit 2 to strip it.
void Unk80026864::fn_80031980() {
    EController* controller = lbl_8037C11C->fn_8015E5FC(lbl_8037C11C->fn_8015E614(unk38));
    if (controller->fn_8015DF98(0x11)) {
        if (!controller->fn_8015E0F8(5)) {
            return;
        }
        if (!fn_80032B64()) {
            lbl_8037D96C->fn_8006186C(0x3804219F);
        }
        unk88 = 0;
        return;
    }
    if ((unk88 & 1) == 0) {
        if (controller->fn_8015E0F8(5)) {
            unk88 |= 3;
            return;
        }
        if ((unk88 & 1) == 0 && controller->fn_8015E0F8(0xF)) {
            unk88 |= 5;
        }
        return;
    }
    if ((unk88 & 2) && controller->fn_8015E0F8(5)) {
        if (!fn_800330A0()) {
            lbl_8037D96C->fn_8006186C(0x3804219F);
        }
        unk88 &= ~3;
        return;
    }
    if ((unk88 & 4) && controller->fn_8015E0F8(5)) {
        if (!fn_80032FF0()) {
            lbl_8037D96C->fn_8006186C(0x3804219F);
        }
        unk88 &= ~1;
        unk88 &= ~4;
        return;
    }
    if (controller->fn_8015DF98(7)) {
        unk88 = 0;
    }
}

// 0x80031B1C
// Draws the wall run being dragged (papered or, with `remove`, marked for stripping).
inline EVec2& AsVec2B1C(EVec3& v) { return *(EVec2*)&v; }
void Unk80026864::fn_80031B1C(ERC* rc, int remove) {
    Unk80181824* texture;
    void* handle;
    if (remove) {
        texture = (Unk80181824*)lbl_8037B4AC;
        handle = *(void**)((char*)texture + 4);
    } else {
        texture = (Unk80181824*)unk104;
        handle = *(void**)((char*)texture + 4);
    }
    texture->fn_80181824(rc);
    EVec2 from(*(EVec2*)&unkD0);
    EVec2 to(*(EVec2*)&unkD8);
    EVec3 offset;
    fn_80033278(&from, &to, &offset);
    from += AsVec2B1C(offset);
    to += AsVec2B1C(offset);
    if (remove) {
        fn_801E36E4b(lbl_802E6820[0], 9, 0, &unkD0, &unkD4, &unkD8, &unkDC, &offset.x, &offset.y, &handle, 0);
    } else {
        fn_801E36E4b(lbl_802E6820[0], 8, 0, &unkD0, &unkD4, &unkD8, &unkDC, &offset.x, &offset.y, &handle, remove);
    }
    unkE8 = fn_8003849C(rc, &from, &to, texture, &unkEC, unk84, unkF8 == 0);
    Unk80181824* mark;
    if (unkE8) {
        mark = lbl_8037B4B0;
    } else {
        mark = (Unk80181824*)lbl_8037B4B4;
    }
    fn_80031CF0(rc, mark, (EVec2*)&unkD0, (EVec2*)&unkD8, 0, 3.5f, 0.0f);
}

// 0x80031CF0
// Draws an upright textured strip along a run on the ground: one pair of vertices
// per tile, from the ground up to `height`. `flag` picks how the texture is mapped
// (2 along the run, 1 across it, otherwise not at all).
// NON_MATCHING: 262 instructions vs 263, 22 differ. The original keeps the vertex
// count in r0 through the loop and the loop counter in r4 (then `mr r4, r0` for the
// draw call); here the count goes straight to r4 and the counter to r11. The copies
// of `flag` and `height` at the entry are also exchanged. About fifteen variants
// tried (loop forms, where the counter and the count are declared).
struct Unk80031CF0Position {
    float x, y, z, w;
};
struct Unk80031CF0RC {
    char unk0[0x44];
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4(int count, Unk80031CF0Position* positions, EVec2* coords, int, int, int);
};
void fn_80031CF0(ERC* rc, Unk80181824* texture, EVec2* a, EVec2* b, int flag, float height, float base) {
    texture->fn_80181824(rc);
    rc->vfn54(1, 2, 1, 0);
    ELightSet lights;
    lights.numPoint = 0;
    lights.numDirectional = 0;
    lights.ambient = EVec3(1.0f);
    rc->vfn44(&lights);
    rc->vfn36(8);
    rc->vfn29();
    float deltaX = b->x - a->x;
    int countX = (int)(EABS(deltaX) + 0.5f);
    float deltaY = b->y - a->y;
    int countY = (int)(EABS(deltaY) + 0.5f);
    int count = countY;
    if (count < countX) {
        count = countX;
    }
    if (count == 0) {
        return;
    }
    int i;
    int points = count + 1;
    int positionBytes = points * 32;
    Unk80031CF0Position* positions =
        (Unk80031CF0Position*)((Unk80173D58Alloc*)rc)->fn_80173D58(positionBytes + points * 16, 0x20);
    if (positions == 0) {
        return;
    }
    EVec2* coords = (EVec2*)((char*)positions + positionBytes);
    Unk80031CF0Position* position = positions;
    EVec2* coord = coords;
    float x = a->x;
    float y = a->y;
    EVec2 step = (*b - *a) * (1.0f / (float)count);
    EVec2 across;
    EVec2 along;
    float u;
    float v;
    if (flag == 2) {
        u = 0.0f;
        across.x = 1.0f;
        along.y = base;
        across.y = u;
        along.x = u;
        v = (float)(-count / 2);
    } else if (flag == 1) {
        v = 0.0f;
        across.y = 1.0f;
        along.x = base;
        across.x = v;
        along.y = v;
        u = (float)(-count / 2);
    } else {
        across = EVec2(0.0f);
        along = EVec2(0.0f);
        v = 0.5f;
        u = v;
    }
    int vertices = points + points;
    i = points;
    while (i-- != 0) {
        position->y = y;
        position->x = x;
        position->z = 0.0f;
        position->w = 0.0f;
        coord->y = v;
        coord->x = u;
        position++;
        position->x = x;
        position->y = y;
        position->z = height;
        position->w = 0.0f;
        position++;
        coord++;
        coord->x = u + across.x;
        coord->y = v + across.y;
        coord++;
        x += step.x;
        y += step.y;
        u += along.x;
        v += along.y;
    }
    ((Unk80031CF0RC*)rc)->vfn4(vertices, positions, coords, 0, 0, 0);
}

// 0x8003210C
// Price of wall covering `index`.
int fn_8003210C(int index) {
    Unk8003210CList* types = (Unk8003210CList*)lbl_802E6700.unkC4b;
    if (index < types->GetSize() - 1) {
        return types->At(index)->unk0;
    }
    return 0;
}

// 0x8003214C
// What stripping the covering from the dragged wall run gives back.
int Unk80026864::fn_8003214C() {
    Unk801C6EF4 start;
    Unk801C6EF4 end;
    fn_8003739C((EVec2*)&unkD0, (EVec2*)&unkD8, &start, &end);
    fn_800315FC(&start, &end);
    int direction = fn_800369A0(&start, &end);
    if (direction == 8) {
        lbl_8037D96C->fn_8006186C(0x3804219F);
        return 0;
    }
    int wall = fn_8023DC04(direction);
    Unk801C6EF4 current(start);
    int side = 0;
    fn_800323D8(&wall, unkF8 == 0, &side, &current, &end);
    int total = 0;
    Unk800315FCInfo info;
    Unk8037D990N* level = (Unk8037D990N*)lbl_8037D990;
    while (!level->vfn8(&current) && !(current == end)) {
        info.fn_8023DE48(level->vfn18(&current));
        if (info.fn_8023DED4(wall)) {
            side = 0;
            switch (wall) {
            case 0x10:
                side = unkF8 == 0 ? 2 : 4;
                break;
            case 0x20:
                side = unkF8 ? 3 : 1;
                break;
            }
            total += fn_8003210C(info.fn_8023E088(wall, side));
        }
        ((Unk800315FCTile*)&current)->fn_801C70F4(&lbl_8035ABB0[direction]);
        current.unk2 = 1;
    }
    if (CheatMoney()) {
        return 0;
    }
    return total;
}

// 0x800323D8
// Works out which side of a wall an action applies to; for the two straight kinds
// it also shifts the run by one step, depending on the direction it is drawn in.
void fn_800323D8(int* wall, int kind, int* side, Unk801C6EF4* from, Unk801C6EF4* to) {
    int direction = fn_800369A0(from, to);
    int step = lbl_802D1F00[direction];
    if (*wall == 0x10) {
        if (kind) {
            *side = 2;
            return;
        }
        *side = 4;
        return;
    }
    if (*wall == 0x20) {
        if (kind == 0) {
            *side = 3;
            return;
        }
        *side = 1;
        return;
    }
    if (*wall == 1 && kind == 0) {
        *wall = fn_8023DB98(1);
        ((Unk800315FCTile*)from)->fn_801C711C(&lbl_8035ABB0[step]);
        ((Unk800315FCTile*)to)->fn_801C711C(&lbl_8035ABB0[step]);
    } else if (*wall == 2 && kind == 1) {
        *wall = fn_8023DB98(2);
        ((Unk800315FCTile*)from)->fn_801C70F4(&lbl_8035ABB0[step]);
        ((Unk800315FCTile*)to)->fn_801C70F4(&lbl_8035ABB0[step]);
    }
}

// 0x80032518
// Applies a covering (0 strips it) to one side of every wall along the dragged run,
// after checking that it can be paid for. The two points passed in are not used.
int Unk80026864::fn_80032518(EVec2* from, EVec2* to, int type, int flag) {
    Unk801C6EF4 start;
    Unk801C6EF4 end;
    EVec2 a(unkD0, unkD4);
    EVec2 b(unkD8, unkDC);
    fn_8003739C(&a, &b, &start, &end);
    fn_800315FC(&start, &end);
    int direction = fn_800369A0(&start, &end);
    if (direction == 8) {
        lbl_8037D96C->fn_8006186C(0x3804219F);
        return 0;
    }
    int wall = fn_8023DC04(direction);
    Unk801C6EF4 current(start);
    Unk801C6EF4 last(end);
    int side = 0;
    fn_800323D8(&wall, flag, &side, &current, &last);
    int cost;
    if (unk88 & 4) {
        cost = (int)((float)unkEC * -0.8f);
    } else {
        cost = unkE8 * unk1C4;
    }
    int money = ((Unk8037D944C*)lbl_8037D944)->vfn25(0);
    if ((cost == 0 || money < cost) && !CheatMoney()) {
        lbl_8037D96C->fn_8006186C(0x3804219F);
        return 0;
    }
    ((Unk8037D944C*)lbl_8037D944)->vfn26(7, cost, 0);
    lbl_8037D96C->fn_8006186C(0xB2AD3ECD);
    Unk800315FCLevel* level = (Unk800315FCLevel*)lbl_8037D990;
    int steps = 0;
    bool done;
    do {
        Unk800315FCInfo info = level->vfn18(&current);
        if (info.fn_8023DEA4(wall)) {
            info.fn_8023E110(type, wall, side);
            Unk8023DDC4 packed(info);
            level->vfn19(&current, &packed);
        }
        done = false;
        current = current + lbl_8035ABB0[direction];
        current.unk2 = 1;
        if (level->vfn8(&current) || current == last) {
            done = true;
        }
        steps++;
        if (steps >= level->vfn6()) {
            break;
        }
    } while (!done);
    ((Unk800315FCRooms*)lbl_8037D998)->vfn19();
    return 1;
}

// 0x800328F4
// The room a tile belongs to (looked up through its wall when the tile is cut).
int fn_800328F4(Unk801C6F20* tile) {
    Unk8037D990G* level = (Unk8037D990G*)lbl_8037D990;
    int room = ((Unk8037D990K*)level)->vfn24(tile);
    if (lbl_8037D998 == 0) {
        return 0;
    }
    if (room == 0xFFFB) {
        unsigned short* a;
        unsigned short* b;
        int sideA;
        int sideB;
        ((Unk80234774*)lbl_8037D998)->fn_80234774(tile, &a, &b, &sideA, &sideB);
        Unk8023E354 info = level->vfn18(tile);
        if (info.fn_8023DEA4(0x20)) {
            room = *a;
        } else {
            info.fn_8023DEA4(0x10);
            room = *a;
        }
    }
    return room;
}

// 0x800329D8
// Draws the wallpaper preview on the walls of the room under the cursor.
// NON_MATCHING: 71 instructions vs 72. The original loads the history object into r6
// and moves it to r3 (`mr r3, r6`), needs one saved register and 8 bytes of frame
// less, and has the temporary tile below `room` on the stack. Ten variants tried
// (member and inline forwarding forms of the history call, a single tile class with
// its own constructor, an inline cursor-tile helper, declaration orders).
void Unk80026864::fn_800329D8(ERC* rc) {
    Unk80056498* drawer = 0;
    Unk8004AD08C* view = (Unk8004AD08C*)lbl_802E6700.unkA8[2];
    if (view) {
        drawer = view->unk8;
    }
    Unk801C6EF4 tile;
    if (drawer) {
        ((Unk80181824*)unk104)->fn_80181824(rc);
        int tileX;
        int tileY;
        fn_8002BB64(&tileX, &tileY);
        tile = *(Unk801C6EF4*)&Unk801C6F44(tileY, tileX, 1);
        unsigned short room = fn_800328F4((Unk801C6F20*)&tile);
        void* texture = *(void**)((char*)unk104 + 4);
        fn_801E36E4b(lbl_802E6700.unk120, 7, &room, 0, 0, &unkB4, &unkB4, 0, 0, &texture, 0);
        unkE8 = ((Unk80056498B*)drawer)->fn_80056498(rc, room, &unkB4);
    }
}

// 0x80032AF8
int fn_80032AF8(int a, int b) {
    if (CheatMoney()) {
        return 0;
    }
    return ((Unk800563C0*)((Unk8004AD08C*)lbl_802E6700.unkA8[2])->unk8)->fn_800563C0(a, b);
}

// 0x80032B64
// Papers every wall of the room under the cursor with the current covering.
// NON_MATCHING: draft built on fn_8002E73C, which has the same walk over the room's
// tiles and walls; the pricing at the start follows the original's calls, the rest
// is reduced to a call of that function (98 instructions vs 291). One variant.
int Unk80026864::fn_80032B64() {
    int tileX;
    int tileY;
    fn_8002BB64(&tileX, &tileY);
    Unk801C6F44 tile(tileY, tileX, 1);
    int room = fn_800328F4(&tile);
    Unk80234390* list = FindList((void*)room);
    if (list == 0 || room == 0) {
        return 0;
    }
    int type = lbl_802E6700.fn_80067434(unk1A0);
    ((Unk801E3EF0*)lbl_802E6700.unk120)->fn_801E3EF0(room, type);
    int cost = fn_80032AF8(room, type) * unk1C4;
    if (!CheatMoney() && cost > ((Unk8037D944C*)lbl_8037D944)->vfn25(0)) {
        lbl_8037D96C->fn_8006186C(0x3804219F);
        return 0;
    }
    ((Unk8037D944C*)lbl_8037D944)->vfn26(7, cost, 0);
    lbl_8037D96C->fn_8006186C(0xB2AD3ECD);
    lbl_8037D96C->fn_8006186C(0x994E8974);
    fn_8002E73C(room, type);
    return 1;
}

// 0x80032FF0
// Removes the wall run that was dragged out.
int Unk80026864::fn_80032FF0() {
    EVec2 from(unkD0, unkD4);
    EVec2 to(unkD8, unkDC);
    int done = fn_80032518(&from, &to, 0, unkF8 == 0);
    if (done == 1) {
        ((Unk801E3F54*)lbl_802E6820[0])->fn_801E3F54(0, unkF8 == 0, from.x, from.y, to.x, to.y);
        ((Unk80233FC0*)lbl_8037D998)->fn_80233FC0();
        fn_80028ECC();
    }
    return done;
}

// 0x800330A0
// Papers the wall run that was dragged out with the current covering.
int Unk80026864::fn_800330A0() {
    EVec2 from(unkD0, unkD4);
    EVec2 to(unkD8, unkDC);
    int done = fn_80032518(&from, &to, lbl_802E6700.fn_80067434(unk1A0), unkF8 == 0);
    if (done == 1) {
        Unk801E3F54* history = (Unk801E3F54*)lbl_802E6700.unk120;
        float x0 = from.x;
        float y0 = from.y;
        float x1 = to.x;
        float y1 = to.y;
        history->fn_801E3F54(lbl_802E6700.fn_80067434(unk1A0), unkF8 == 0, x0, y0, x1, y1);
        ((Unk80233FC0*)lbl_8037D998)->fn_80233FC0();
        fn_80028ECC();
    }
    return done;
}

// 0x800331A8
// Sets the covering of one side of one wall of a tile, if it differs.
void fn_800331A8(Unk801C6F20* tile, int arg, int wall, int side) {
    Unk8037D990M* level = (Unk8037D990M*)lbl_8037D990;
    Unk8023E088 info = level->vfn18(tile);
    if (info.fn_8023E088(wall, side) == arg) {
        return;
    }
    ((Unk800315FCInfo*)&info)->fn_8023E110(arg, wall, side);
    Unk8023DDC4 packed(info);
    level->vfn19(tile, &packed);
}

// 0x80033278
// Orders the two ends of a wall run, and gives the offset that puts its preview on
// the side facing the camera; unkF8 records which side that is.
unsigned char Unk80026864::fn_80033278(EVec2* from, EVec2* to, EVec3* offset) {
    EVec2 a(*from);
    EVec2 b(*to);
    if (a.x == b.x) {
        float lo = a.y < b.y ? a.y : b.y;
        float hi = a.y > b.y ? a.y : b.y;
        a.y = lo;
        b.y = hi;
    } else if (a.y == b.y) {
        float lo = a.x < b.x ? a.x : b.x;
        float hi = a.x > b.x ? a.x : b.x;
        a.x = lo;
        b.x = hi;
    } else {
        float slope = (b.y - a.y) / (b.x - a.x);
        if (slope > 0.0f) {
            if (a.x > b.x) {
                EVec2 swap(a);
                a = b;
                b = swap;
            }
        } else {
            if (a.y > b.y) {
                EVec2 swap(a);
                a = b;
                b = swap;
            }
        }
    }
    EVec2 along(b - a);
    EVec2 normal(along.y, -along.x);
    normal.Normalize();
    unkF8 = fn_80033484(&normal);
    normal.x *= lbl_8037B4C4;
    normal.y *= lbl_8037B4C4;
    offset->z = 0.0f;
    offset->x = normal.x;
    offset->y = normal.y;
    *offset = unkF8 ? -*offset : *offset;
    return unkF8;
}

// 0x80033484
// Whether a direction on the ground points towards the camera.
bool fn_80033484(EVec2* direction) {
    Unk80026864Cam* camera = (Unk80026864Cam*)lbl_802E6700.unkA8[4];
    Unk80033484Vec2 flat((camera->unk378 - camera->unk398).Normalize());
    return flat.x * direction->x + flat.y * direction->y > 0.0f;
}

// 0x80033554
// Moves a point `amount` tiles in one of the eight directions.
void fn_80033554(int direction, int amount, EVec2* point) {
    switch (direction) {
    case 0:
        point->x -= (float)amount;
        break;
    case 1:
        point->x += (float)amount;
        break;
    case 2:
        point->y -= (float)amount;
        break;
    case 3:
        point->y += (float)amount;
        break;
    case 4:
        point->x -= (float)amount;
        point->y -= (float)amount;
        break;
    case 5:
        point->x += (float)amount;
        point->y += (float)amount;
        break;
    case 6:
        point->x -= (float)amount;
        point->y += (float)amount;
        break;
    case 7:
        point->x += (float)amount;
        point->y -= (float)amount;
        break;
    }
}

// 0x80033754
// State 4's handler: what the pending wallpaper action costs.
int Unk80026864::fn_80033754() {
    EController* controller = lbl_8037C11C->fn_8015E5FC(lbl_8037C11C->fn_8015E614(unk38));
    if (controller->fn_8015DF98(0x11) || !(unk88 & 4)) {
        return unkE8 * unk1C4;
    }
    int refund = fn_8003214C();
    unkEC = refund;
    return (int)((float)refund * -0.8f);
}

// 0x80033814
// Price of the fence or wall of kind `id` (10 when it is not listed).
int fn_80033814(int id) {
    Unk802E67C8Entry** list = *(Unk802E67C8Entry***)lbl_802E6700.unkC8b;
    int count = 0;
    if (list) {
        count = ((int*)list)[-1];
    }
    for (int i = 0; i < count; i++) {
        Unk802E67C8Entry* entry = list[i];
        if (id == entry->unkC) {
            return entry->unk4;
        }
    }
    return 10;
}

// 0x8003386C
// Starts the wall tool (state 3), or for the fence kinds the fence tool (state 5).
void Unk80026864::fn_8003386C(int kind) {
    unk1C0 = kind;
    bool fence;
    if (kind == 2 || kind == 0xC || kind == 0xD || kind == 0xE) {
        fence = true;
    } else {
        fence = false;
    }
    if (fence) {
        unk84 = 5;
        unsigned int texture = 0xDB6A33BD;
        switch (kind) {
        case 0xC:
            texture = 0x10FE3D7A;
            break;
        case 0xD:
            texture = 0x9F057195;
            break;
        }
        unk1C4 = fn_80033814(kind);
        unk104 = lbl_80340AB8.fn_80177628(texture, 0, 0);
    } else {
        UNK_RELEASE_801767FC(unk104);
        unk84 = 3;
    }
    unk88 = 0;
}

// 0x80033954
// State 5's handler: the fence tool is priced like the wall tool.
int Unk80026864::fn_80033954() {
    return fn_80033974();
}
