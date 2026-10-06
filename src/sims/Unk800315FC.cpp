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

// 0x800318B0
// Starts the wallpaper tool with a covering from the catalogue.
// NON_MATCHING: 5 instructions: the first load of unk104 and two stores are
// scheduled differently. Three orders tried.
void Unk80026864::fn_800318B0(Unk800318B0Tool* tool) {
    unk84 = 4;
    unk88 = 0;
    if (unk104) {
        fn_801767FC(unk104);
        unk104 = 0;
    }
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
    if (unk104) {
        fn_801767FC(unk104);
        unk104 = 0;
    }
}

// 0x80031980
// The wallpaper tool's buttons. unk88: bit 0 a run is being dragged, bit 1 to paper
// it, bit 2 to strip it.
// NON_MATCHING: 105 instructions vs 103; the branches share their final store of
// unk88 differently. One variant tried.
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
    if (!(unk88 & 1)) {
        if (controller->fn_8015E0F8(5)) {
            unk88 |= 3;
            return;
        }
        if (!(unk88 & 1) && controller->fn_8015E0F8(0xF)) {
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
        unk88 = (unk88 & ~1) & ~4;
        return;
    }
    if (controller->fn_8015DF98(7)) {
        unk88 = 0;
    }
}

// 0x80031B1C
// Draws the wall run being dragged (papered or, with `remove`, marked for stripping).
// NON_MATCHING: 118 instructions vs 117; draft (the history call's arguments are
// partly guessed). One variant tried.
void Unk80026864::fn_80031B1C(ERC* rc, int remove) {
    Unk80181824* texture;
    if (remove) {
        texture = (Unk80181824*)lbl_8037B4AC;
    } else {
        texture = (Unk80181824*)unk104;
    }
    void* handle = *(void**)((char*)texture + 4);
    texture->fn_80181824(rc);
    EVec2 from(unkD0, unkD4);
    EVec2 to(unkD8, unkDC);
    EVec3 offset;
    int unused;
    fn_80033278(&from, &to, &offset);
    from += *(EVec2*)&offset;
    to += *(EVec2*)&offset;
    if (remove) {
        fn_801E36E4b(lbl_802E6700.unk120, 9, 0, &unkD0, &unkD4, &unkD8, &unkDC, &offset, &unused, &handle, 0);
    } else {
        fn_801E36E4b(lbl_802E6700.unk120, 8, 0, &unkD0, &unkD4, &unkD8, &unkDC, &offset, &unused, &handle, remove);
    }
    unkE8 = fn_8003849C(rc, &from, &to, texture, &unkEC, unk84, unkF8 == 0);
    fn_80031CF0(rc, unkE8 ? lbl_8037B4B0 : (Unk80181824*)lbl_8037B4B4, (EVec2*)&unkD0, (EVec2*)&unkD8, 0, 3.5f, 0.0f);
}

// 0x8003210C
// Price of wall covering `index`.
// NON_MATCHING: 17 instructions vs 16, as fn_8002FEF4 (the index leaves r3).
int fn_8003210C(int index) {
    Unk802E67C0Entry** types = ((Unk802E67C0*)lbl_802E6700.unkC4b)->unk0;
    int count = 0;
    if (types) {
        count = ((int*)types)[-1];
    }
    if (index >= count - 1) {
        return 0;
    }
    return types[index]->unk0;
}

// 0x800323D8
// Works out which side of a wall an action applies to; for the two straight kinds
// it also shifts the run by one step, depending on the direction it is drawn in.
// NON_MATCHING: same length (80), 34 instructions differ in how the four cases are
// laid out. One variant tried.
void fn_800323D8(int* wall, int kind, int* side, Unk801C6EF4* from, Unk801C6EF4* to) {
    int step = lbl_802D1F00[fn_800369A0(from, to)];
    if (*wall == 0x10) {
        if (kind) {
            *side = 2;
        } else {
            *side = 4;
        }
    } else if (*wall == 0x20) {
        if (kind == 0) {
            *side = 3;
        } else {
            *side = 1;
        }
    } else if (*wall == 1 && kind == 0) {
        *wall = fn_8023DB98(1);
        ((Unk801C711C*)from)->fn_801C711C(&lbl_8035ABB0[step]);
        ((Unk801C711C*)to)->fn_801C711C(&lbl_8035ABB0[step]);
    } else if (*wall == 2 && kind == 1) {
        *wall = fn_8023DB98(2);
        ((Unk801C711C*)from)->fn_801C70F4(&lbl_8035ABB0[step]);
        ((Unk801C711C*)to)->fn_801C70F4(&lbl_8035ABB0[step]);
    }
}

// 0x800328F4
// The room a tile belongs to (looked up through its wall when the tile is cut).
// NON_MATCHING: 3 instructions: the load of the room id and the destructor's
// arguments are exchanged. One variant tried.
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
        if (!info.fn_8023DEA4(0x20)) {
            info.fn_8023DEA4(0x10);
        }
        room = *a;
    }
    return room;
}

// 0x800329D8
// Draws the wallpaper preview on the walls of the room under the cursor.
// NON_MATCHING: 71 instructions vs 72; draft (the argument list of the preview call
// is partly guessed). One variant tried.
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
        fn_801E36E4b(lbl_802E6820[0], 7, &room, 0, 0, &unkB4, &unkB4, 0, 0, &texture, 0);
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
// NON_MATCHING: 2 instructions: two argument moves are exchanged. One variant.
void fn_800331A8(Unk801C6F20* tile, int arg, int wall, int side) {
    Unk8037D990M* level = (Unk8037D990M*)lbl_8037D990;
    Unk8023E088 info = level->vfn18(tile);
    if (info.fn_8023E088(wall, side) == arg) {
        return;
    }
    info.fn_8023E110(arg, wall, side);
    Unk8023DDC4 packed(info);
    level->vfn19(tile, &packed);
}

// 0x80033278
// Orders the two ends of a wall run, and gives the offset that puts its preview on
// the side facing the camera; unkF8 records which side that is.
// NON_MATCHING: 134 instructions vs 131; condensed draft, the ordering of the end
// points is simplified. One variant tried.
char Unk80026864::fn_80033278(EVec2* from, EVec2* to, EVec3* offset) {
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
        if (slope > 0.0f ? a.x > b.x : a.y > b.y) {
            EVec2 swap(a.x, a.y);
            a = b;
            b = swap;
        }
    }
    EVec2 along(b.x - a.x, b.y - a.y);
    EVec2 normal(along.y, -along.x);
    float length = fn_8010DF80(normal.y * normal.y + normal.x * normal.x);
    if (length != 0.0f) {
        float scale = 1.0f / length;
        normal.y *= scale;
        normal.x *= scale;
    }
    unkF8 = fn_80033484(&normal);
    normal.x *= lbl_8037B4C4;
    normal.y *= lbl_8037B4C4;
    offset->z = 0.0f;
    offset->x = normal.x;
    offset->y = normal.y;
    if (unkF8) {
        *offset = EVec3(-normal.x, -normal.y, -0.0f);
    } else {
        *offset = EVec3(normal.x, normal.y, 0.0f);
    }
    return unkF8;
}

// 0x80033484
// Whether a direction on the ground points towards the camera.
// NON_MATCHING: same length (52), 36 instructions differ: the vector temporaries
// are laid out differently on the stack. One variant tried.
bool fn_80033484(EVec2* direction) {
    Unk80026864Cam* camera = (Unk80026864Cam*)lbl_802E6700.unkA8[4];
    EVec3 view = camera->unk378 - camera->unk398;
    view.Normalize();
    EVec2 flat(view.x, view.y);
    return flat.x * direction->x + flat.y * direction->y > 0.0f;
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
// NON_MATCHING: 57 instructions vs 58; the test for the fence kinds and the choice
// of texture are merged differently. One variant tried.
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
        if (kind == 0xC) {
            texture = 0x10FE3D7A;
        } else if (kind == 0xD) {
            texture = 0x9F057195;
        }
        unk1C4 = fn_80033814(kind);
        unk104 = lbl_80340AB8.fn_80177628(texture, 0, 0);
    } else {
        if (unk104) {
            fn_801767FC(unk104);
            unk104 = 0;
        }
        unk84 = 3;
    }
    unk88 = 0;
}

// 0x80033954
// State 5's handler: the fence tool is priced like the wall tool.
int Unk80026864::fn_80033954() {
    return fn_80033974();
}
