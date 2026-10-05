#include "engine/e_storable.h"
#include "engine/e_resource.h"
#include "engine/e_rfont.h"
#include "engine/e_texture.h"
#include "engine/e_shader.h"
#include "engine/e_rshader.h"
#include "engine/e_instance.h"
#include "engine/e_ifloor.h"
#define EOR_BUILD_TIME "21:41:24"
#include "engine/e_engine.h"
#include "sims/Unk80026864Private.h"

// The floor tool of build mode: part of Unk80026864 and its helpers.

// Deletes the markers a list owns and empties it (as in fn_80027780, without the
// test for an empty list).
inline void DeleteMarkers(Unk80026864List& list) {
    Unk80026864Node* node = list.tail;
    while (EIsValidNode(node)) {
        Unk8002FC60* item = (Unk8002FC60*)node->item;
        Unk80026864Node* next = node->prev;
        if (list.owns && item) {
            item->fn_8002FD24();
            fn_80169EE8(item);
        }
        node = next;
    }
    list.fn_801B4760();
}

// 0x8002EFAC
void fn_8002EFAC(ERC* rc, Unk8002EFACItem* item) {
    int a;
    int b;
    int c;
    int d;
    item->unk1C->fn_80181824(rc);
    ((Unk80026864*)item->unk18)->fn_8002F2E0(rc, &a, &b, &c, &d);
}

// 0x8002F000
// Starts the floor tool with a floor type from the catalogue.
// NON_MATCHING: 106 instructions vs 111; the zeroing of unk154 and the marker's
// construction are laid out differently. One variant tried.
void Unk80026864::fn_8002F000(Unk8002F000Tool* tool) {
    unk84 = 2;
    unk1C4 = tool->unk0;
    DeleteMarkers(unk194);
    if (unk100) {
        fn_801767FC(unk100);
        unk100 = 0;
    }
    unk100 = lbl_80340AB8.fn_80177628(tool->unkC, 0, 0);
    float x = unkA0.x;
    float y = unkA0.y;
    Unk8002FC60* marker = new Unk8002FC60(tool);
    marker->fn_8002FC60(x, y);
    unk194.fn_801B4600(marker);
    *(EVec2*)&unkAC = fn_8002BD98();
    marker->fn_8002FDC0((EVec2*)&unkAC);
    unk188 = EVec3(-1000.0f);
    unk154.unk0 = 0;
    unk154.unk24 = 0;
    unk154.unk4 = 0;
    unk154.unk8 = 0;
    unk154.unkC = 0;
    unk154.unk10 = 0;
    unk154.unk14 = 0;
    unk154.unk18 = 0;
    unk154.unk1C = 0;
    unk154.unk20 = 0;
    unk154.unk0 = 2;
    unk154.unk8 = (int)&unk188;
    unk154.unk14 = (int)fn_8002EFAC;
    unk154.unk18 = (int)this;
}

// 0x8002F1BC
// Releases the floor tool's texture and markers.
// NON_MATCHING: 14 instructions; the walk over the marker list keeps its node in r3
// instead of r9, as in fn_80027780. Two variants tried.
void Unk80026864::fn_8002F1BC() {
    if (unk100) {
        fn_801767FC(unk100);
        unk100 = 0;
    }
    DeleteMarkers(unk194);
    if (unk84 == 2) {
        unk84 = 0;
    }
}

// 0x8002F268
void Unk80026864::fn_8002F268() {
    if (unk100) {
        unk154.unk1C = (int)unk100;
        ((Unk8004B740*)lbl_802E67B0.unk0)->fn_8004B740(&unk154);
    }
}

// 0x8002F2A4
void Unk80026864::fn_8002F2A4() {
    if (lbl_8037B4B0) {
        unk154.unk1C = (int)lbl_8037B4B0;
        ((Unk8004B740*)lbl_802E67B0.unk0)->fn_8004B740(&unk154);
    }
}

// 0x8002F2E0
// Draws the rectangle being dragged with the floor tool, textured with the floor,
// and returns its bounds in tiles.
// NON_MATCHING: condensed draft (the original is 301 instructions and builds the
// four vertices in the open). One variant tried.
void Unk80026864::fn_8002F2E0(ERC* rc, int* outX0, int* outY0, int* outX1, int* outY1) {
    const EVec2& origin = ((Unk8004AD08B*)lbl_802E67B0.unk0)->unk34;
    int startX = (int)(unkAC - origin.x);
    int startY = (int)(unkB0 - origin.y);
    int tileX;
    int tileY;
    fn_8002BB64(&tileX, &tileY);
    *(float*)outX0 = (float)startX;
    *(float*)outY0 = (float)startY;
    *(float*)outX1 = (float)tileX;
    *(float*)outY1 = (float)tileY;
    float x0 = (float)(startX > tileX ? tileX : startX) - 0.5f + origin.x;
    float x1 = (float)(startX < tileX ? tileX : startX) + 0.5f + origin.x;
    float y0 = (float)(startY > tileY ? tileY : startY) - 0.5f + origin.y;
    float y1 = (float)(startY < tileY ? tileY : startY) + 0.5f + origin.y;
    Unk80173D58Vertex vertices[4];
    for (int i = 0; i < 4; i++) {
        vertices[i].unk10[0] = 0;
        vertices[i].unk10[1] = 0;
        vertices[i].unk10[2] = 0x7F;
        vertices[i].unk1C = 0;
        vertices[i].unk30[0] = 0x80;
        vertices[i].unk30[1] = 0x80;
        vertices[i].unk30[2] = 0x80;
        vertices[i].unk30[3] = 0x80;
        vertices[i].unk0[0] = (i & 1) ? x0 : x1;
        vertices[i].unk0[1] = (i & 2) ? y1 : y0;
        vertices[i].unk0[2] = 0.05f;
        vertices[i].unk0[3] = 1.0f;
        vertices[i].unk20[0] = vertices[i].unk0[0];
        vertices[i].unk20[1] = vertices[i].unk0[1];
    }
    ((Unk8002D2D4RC*)rc)->vfn3(vertices, 4);
}

// 0x8002F794
// Draws the floor texture over every tile of the room under the cursor.
// NON_MATCHING: condensed draft (the original is 307 instructions; it also handles
// tiles cut by a diagonal wall). One variant tried.
void Unk80026864::fn_8002F794(ERC* rc) {
    int tileX;
    int tileY;
    fn_8002BB64(&tileX, &tileY);
    Unk801C6F44 tile(tileY, tileX, 1);
    unsigned short room = ((Unk8037D990K*)lbl_8037D990)->vfn24(&tile);
    if (room == 0xFFFB) {
        unsigned short* a;
        unsigned short* b;
        int sideA;
        int sideB;
        ((Unk80234774*)lbl_8037D998)->fn_80234774(&tile, &a, &b, &sideA, &sideB);
        room = *a;
    }
    Unk80234390* list = FindList((void*)room);
    if (list && room) {
        char* it = list->unk4;
        if (it != list->unk8) {
            if (unk100 == 0) {
                return;
            }
            ((Unk80181824*)unk100)->fn_80181824(rc);
            ((Unk8002F794RC*)rc)->vfn52(0.2f);
            const EVec2& origin = ((Unk8004AD08B*)lbl_802E67B0.unk0)->unk34;
            for (; it != list->unk8; it += 3) {
                float x = (float)((Unk801C727CEntry*)it)->fn_801C7288() + origin.x;
                float y = (float)((Unk801C727CEntry*)it)->fn_801C727C() + origin.y;
                Unk80173D58Vertex vertices[4];
                for (int i = 0; i < 4; i++) {
                    vertices[i].unk10[0] = 0;
                    vertices[i].unk10[1] = 0;
                    vertices[i].unk10[2] = 0x7F;
                    vertices[i].unk1C = 0;
                    vertices[i].unk30[0] = 0x80;
                    vertices[i].unk30[1] = 0x80;
                    vertices[i].unk30[2] = 0x80;
                    vertices[i].unk30[3] = 0x80;
                    vertices[i].unk0[0] = x + ((i & 1) ? -0.5f : 0.5f);
                    vertices[i].unk0[1] = y + ((i & 2) ? 0.5f : -0.5f);
                    vertices[i].unk0[2] = 0.05f;
                    vertices[i].unk0[3] = 1.0f;
                    vertices[i].unk20[0] = (i & 1) ? 0.0f : 1.0f;
                    vertices[i].unk20[1] = (i & 2) ? 0.0f : 1.0f;
                }
                fn_801E36E4(rc, vertices, 4);
            }
        }
    }
}

// 0x8002FC60
// NON_MATCHING: 1 instruction: the position's y is stored through the vector's
// address here and straight to the stack in the original. Two variants tried.
void Unk8002FC60::fn_8002FC60(float x, float y) {
    ERC* builder = lbl_8037C198->vfn13(1);
    ((Unk8016F034*)builder)->fn_8016F034(1.0f, 1.0f);
    unk4 = lbl_8037C198->vfn14(builder);
    unk8.fn_801B2AFC();
    EVec3 position(x, y, 0.05f);
    unk8.fn_801B2B54(&position);
}

// 0x8002FD24
void Unk8002FC60::fn_8002FD24() {
    if (unk4) {
        if (lbl_8037C198->vfn19(unk4)) {
            lbl_8037C198->vfn8();
        }
        lbl_8037C198->vfn18(unk4);
        unk4 = 0;
    }
}

// 0x8002FDC0
// NON_MATCHING: 9 instructions; the three stores of the position are ordered and
// addressed differently. Two variants tried.
void Unk8002FC60::fn_8002FDC0(const EVec2* at) {
    unk8.fn_801B2AFC();
    EVec3 position(at->x, at->y, 0.05f);
    unk8.fn_801B2B54(&position);
}

// 0x8002FE20
// Whether floor can be laid on a tile; with `flag`, nothing on it may object either.
// NON_MATCHING: 49 instructions vs 53; the original keeps a second copy of the
// iterator's address and returns through a shared `li r3,0`. One variant tried.
int fn_8002FE20(Unk801C6F20* tile, int flag) {
    if ((((Unk8037D990I*)lbl_8037D990)->vfn26(tile) & 0x21) != 1) {
        return 0;
    }
    if (flag) {
        Unk801FCE7C it(*tile, 0);
        while (it.unk4) {
            if ((it.unk4->vfn88(0x2A) ^ 1) & 1) {
                return 0;
            }
            it.fn_801FCF04();
        }
    }
    return 1;
}

// 0x8002FEF4
// Price of floor type `index`.
// NON_MATCHING: 16 instructions vs 15; the index is moved out of r3 here, so the
// bounds test and the return are laid out the other way round. Two variants tried.
int fn_8002FEF4(int index) {
    Unk802E67C0Entry** types = ((Unk802E67C0*)lbl_802E6700.unkC0b)->unk0;
    int count = 0;
    if (types) {
        count = ((int*)types)[-1];
    }
    if (index >= count) {
        return 0;
    }
    return types[index]->unk0;
}

// 0x8002FF30
// What removing floor type `index` gives back: 80% of its price.
// NON_MATCHING: 36 instructions vs 34, as fn_8002FEF4.
int fn_8002FF30(int index) {
    Unk802E67C0Entry** types = ((Unk802E67C0*)lbl_802E6700.unkC0b)->unk0;
    int count = 0;
    if (types) {
        count = ((int*)types)[-1];
    }
    if (index >= count - 1) {
        return 0;
    }
    return (int)((float)types[index]->unk0 * 0.8f);
}

// 0x8002FFB8
// Refund for the floor on a tile (the mean of the two halves when it is split).
// NON_MATCHING: 50 instructions vs 51; the test for a split tile is materialised
// differently. One variant tried.
int fn_8002FFB8(Unk801C6F20* tile) {
    int type = ((Unk8037D990I*)lbl_8037D990)->vfn14(tile);
    unsigned char* record = ((Unk8037D990I*)lbl_8037D990)->vfn22(tile);
    bool split = false;
    if (record[0] & 0x30) {
        split = true;
    }
    if (!split) {
        return -fn_8002FF30(type);
    }
    return -((fn_8002FF30(record[2]) + fn_8002FF30(record[4])) / 2);
}

// 0x80030084
// What flooring a rectangle of tiles with `type` costs; *any is set when at least
// one tile can take it.
int fn_80030084(int* any, int x0, int x1, int y0, int y1, int type) {
    *any = 0;
    int total = 0;
    for (int x = x0; x <= x1; x++) {
        for (int y = y0; y <= y1; y++) {
            Unk801C6F44 tile(x, y, 1);
            if (fn_8002FE20(&tile, type)) {
                *any = 1;
                total += fn_8002FEF4(type);
            }
        }
    }
    if (CheatMoney()) {
        return 0;
    }
    return total;
}

// 0x80030170
// The refund for clearing the floor of a rectangle.
int fn_80030170(int* any, int x0, int x1, int y0, int y1, int flag) {
    *any = 0;
    int total = 0;
    for (int x = x0; x <= x1; x++) {
        for (int y = y0; y <= y1; y++) {
            Unk801C6F44 tile(x, y, 1);
            if (fn_8002FE20(&tile, flag)) {
                *any = 1;
                total += fn_8002FFB8(&tile);
            }
        }
    }
    if (CheatMoney()) {
        return 0;
    }
    return total;
}

// 0x8003025C
// Cost (or refund, for type 0) of flooring the tiles of a room; tiles cut by a
// diagonal wall count half per side.
// NON_MATCHING: same length (120), 60 instructions differ: the branches on which
// half lies inside the room are arranged differently. Two variants tried.
int fn_8003025C(int* any, void* table, Unk80234390* tiles, int type) {
    *any = 0;
    bool remove = type == 0;
    int total = 0;
    int count = ((char*)tiles->unk4 - (char*)tiles->unk0) / 3;
    for (int i = 0; i < count; i++) {
        Unk801C6F20* tile = (Unk801C6F20*)((char*)tiles->unk0 + i * 3);
        if (fn_8002FE20(tile, type)) {
            *any = 1;
            Unk8023E420 info = ((Unk8037D990J*)lbl_8037D990)->vfn18(tile);
            if (!info.fn_8023DFA8()) {
                if (remove) {
                    total += fn_8002FFB8(tile);
                } else {
                    total += fn_8002FEF4(type);
                }
            } else {
                int sideA = 0;
                int sideB = 0;
                fn_80031084(table, tile, &info, &sideA, &sideB);
                if (!remove) {
                    total += fn_8002FEF4(type);
                } else if (sideA == 0) {
                    total -= fn_8002FF30(info.fn_8023E420(sideB)) / 2;
                } else if (sideB == 0) {
                    total -= fn_8002FF30(info.fn_8023E420(sideA)) / 2;
                } else {
                    total -= fn_8002FF30(info.fn_8023E420(sideB)) / 2;
                    total -= fn_8002FF30(info.fn_8023E420(sideA)) / 2;
                }
            }
        }
    }
    if (CheatMoney()) {
        return 0;
    }
    return total;
}

// 0x8003043C
// The floor tool: with button 0x11 held, button 5 floors the whole room under the
// cursor; otherwise button 5 floors the dragged rectangle and 0xF clears it. Each
// action is priced, checked against the household's money, recorded for undo,
// applied tile by tile and paid for.
// NON_MATCHING: skeleton only (the original is 786 instructions). The room branch
// follows the original call for call; the two rectangle branches, which repeat the
// per-tile code of fn_800311B0 inline, are reduced to calls of it. One variant tried.
void Unk80026864::fn_8003043C() {
    EController* controller = lbl_8037C11C->fn_8015E5FC(lbl_8037C11C->fn_8015E614(unk38));
    if (controller->fn_8015DF98(0x11)) {
        if (!fn_8015E298(controller, 5) || unk194.head == 0) {
            return;
        }
        int type = fn_800266C0((int*)unk194.head->item);
        int tileX;
        int tileY;
        fn_8002BB64(&tileX, &tileY);
        Unk801C6F44 tile(tileY, tileX, 1);
        int room = ((Unk8037D990K*)lbl_8037D990)->vfn24(&tile);
        Unk80234390* list = FindList((void*)room);
        if (list == 0 || room == 0 || list->unk4 == list->unk8) {
            return;
        }
        int any = 0;
        int cost = fn_8003025C(&any, list, (Unk80234390*)&list->unk4, type);
        int funds = ((Unk8037D944C*)lbl_8037D944)->vfn25(0);
        if (!CheatMoney() && cost > funds) {
            lbl_8037D96C->fn_8006186C(0x3804219F);
            return;
        }
        Unk801C3E30 name("");
        Unk801E6424 undo(1, 0x40, 0x40, &name);
        undo.fn_801E6BC4(((Unk8037D990L*)lbl_8037D990)->vfn13());
        for (char* it = list->unk4; it != list->unk8; it += 3) {
            fn_800311B0((Unk801C6F20*)it, type, list);
        }
        if (fn_8007600C()) {
            lbl_802E6820[0]->fn_801E3C80(room, type);
            ((Unk8037D944C*)lbl_8037D944)->vfn26(7, cost, 0);
            lbl_8037D96C->fn_8006186C(0xB2AD3ECD);
            fn_80028ECC();
        } else {
            lbl_8037D96C->fn_8006186C(0x3804219F);
        }
        return;
    }
    bool lay = fn_8015E298(controller, 5) != 0;
    bool clear = !lay && fn_8015E298(controller, 0xF) != 0;
    if ((!lay && !clear) || unk194.head == 0) {
        return;
    }
    int type = lay ? fn_800266C0((int*)unk194.head->item) : 0;
    int tileX;
    int tileY;
    fn_8002BB64(&tileX, &tileY);
    int y0 = (int)EMinF((float)tileY, unkB0);
    int x0 = (int)EMinF((float)tileX, unkAC);
    int y1 = (int)EMaxF((float)tileY, unkB0);
    int x1 = (int)EMaxF((float)tileX, unkAC);
    int any = 0;
    int cost = lay ? fn_80030084(&any, y0, y1, x0, x1, type) : fn_80030170(&any, y0, y1, x0, x1, 0);
    if (!CheatMoney() && cost > ((Unk8037D944C*)lbl_8037D944)->vfn25(0)) {
        lbl_8037D96C->fn_8006186C(0x3804219F);
        return;
    }
    Unk801C3E30 name("");
    Unk801E6424 undo(1, 0x40, 0x40, &name);
    undo.fn_801E6BC4(((Unk8037D990L*)lbl_8037D990)->vfn13());
    for (int x = y0; x <= y1; x++) {
        for (int y = x0; y <= x1; y++) {
            Unk801C6F44 tile(x, y, 1);
            fn_800311B0(&tile, type, 0);
        }
    }
    if (fn_8007600C()) {
        lbl_802E6820[0]->fn_801E3CE4(y0, y1, x0, x1, type);
        ((Unk8037D944C*)lbl_8037D944)->vfn26(lay ? 7 : 6, cost, 0);
        lbl_8037D96C->fn_8006186C(lay ? 0xB2AD3ECD : 0x994E8974);
        fn_80028ECC();
    } else {
        lbl_8037D96C->fn_8006186C(0x3804219F);
    }
}

// 0x80031084
// Which halves of a diagonally cut tile lie inside the room: looks for the room on
// the tiles to the left and right.
// NON_MATCHING: 76 instructions vs 75; register use around the two neighbour
// look-ups differs. One variant tried.
void fn_80031084(void* table, Unk801C6F20* tile, Unk8023DFA8* info, int* sideA, int* sideB) {
    *sideA = 0;
    *sideB = 0;
    if (info->fn_8023DFA8()) {
        Unk801C727C* at = (Unk801C727C*)tile;
        int left;
        {
            Unk801C6F44 neighbour(at->fn_801C727C() - 1, at->fn_801C7288(), 1);
            left = ((Unk80235F64*)table)->fn_80235F64(&neighbour);
        }
        int right;
        {
            Unk801C6F44 neighbour(at->fn_801C727C() + 1, at->fn_801C7288(), 1);
            right = ((Unk80235F64*)table)->fn_80235F64(&neighbour);
        }
        if (left) {
            *sideA = info->fn_8023DEA4(0x10) ? 2 : 1;
        }
        if (right) {
            *sideB = info->fn_8023DEA4(0x10) ? 4 : 3;
        }
    }
}

// 0x800311B0
// Lays floor `type` on one tile of a room (on the halves inside it when the tile is cut).
// NON_MATCHING: 90 instructions vs 93; the three-way choice of halves is merged
// differently. One variant tried.
void fn_800311B0(Unk801C6F20* tile, int type, void* table) {
    if (fn_8002FE20(tile, type)) {
        Unk8037D990E* level = (Unk8037D990E*)lbl_8037D990;
        Unk8023DFA8 info = level->vfn18(tile);
        if (!info.fn_8023DFA8()) {
            level->vfn15(tile, type);
        } else {
            int sideB = 0;
            int sideA = 0;
            fn_80031084(table, tile, &info, &sideA, &sideB);
            if (sideA == 0) {
                info.fn_8023E43C(type, sideB);
            } else if (sideB == 0) {
                info.fn_8023E43C(type, sideA);
            } else {
                info.fn_8023E43C(type, sideB);
                info.fn_8023E43C(type, sideA);
            }
            Unk8023DDC4 packed(info);
            level->vfn19(tile, &packed);
            level->vfn15(tile, 0xFF);
        }
    }
}

// 0x80031324
// State 2's handler: what the floor tool's pending action would cost. With button
// 0x11 held it prices the room under the cursor, otherwise the dragged rectangle;
// button 0xF turns the action into removal.
// NON_MATCHING: 157 instructions vs 182; the original converts and compares each
// bound separately where the min/max helpers are used here. One variant tried.
int Unk80026864::fn_80031324() {
    if (unk194.head == 0) {
        return 0;
    }
    int* marker = (int*)unk194.head->item;
    if (marker == 0) {
        return 0;
    }
    int type = fn_800266C0(marker);
    EController* controller = lbl_8037C11C->fn_8015E5FC(lbl_8037C11C->fn_8015E614(unk38));
    if (controller->fn_8015DF98(0x11)) {
        int tileX;
        int tileY;
        fn_8002BB64(&tileX, &tileY);
        Unk801C6F44 tile(tileY, tileX, 1);
        int room = ((Unk8037D990K*)lbl_8037D990)->vfn24(&tile);
        Unk80234390* list = FindList((void*)room);
        if (list == 0 || room == 0) {
            return 0;
        }
        int any = 0;
        return fn_8003025C(&any, list, (Unk80234390*)&list->unk4, type);
    }
    int tileX;
    int tileY;
    fn_8002BB64(&tileX, &tileY);
    int y0 = (int)EMinF((float)tileY, unkB0);
    int x0 = (int)EMinF((float)tileX, unkAC);
    int y1 = (int)EMaxF((float)tileY, unkB0);
    int x1 = (int)EMaxF((float)tileX, unkAC);
    int any = 0;
    if (controller->fn_8015DF98(0xF)) {
        type = 0;
    }
    if (type == 0) {
        return fn_80030170(&any, y0, y1, x0, x1, 0);
    }
    return fn_80030084(&any, y0, y1, x0, x1, type);
}
