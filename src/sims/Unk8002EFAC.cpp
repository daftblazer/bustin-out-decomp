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
    fn_8002F2E0(item->unk18, rc, &a, &b, &c, &d);
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
