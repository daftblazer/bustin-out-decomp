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

// The floor types (local view of Unk802E67C0: the prices are unsigned and the
// array keeps its length in the word before the data).
struct Unk8002EFACType {
    unsigned int unk0;
};
struct Unk8002EFACTypes {
    Unk8002EFACType** unk0;
    int GetCount() {
        int count = 0;
        if (unk0) {
            count = ((int*)unk0)[-1];
        }
        return count;
    }
    Unk8002EFACType*& At(int i) { return unk0[i]; }
};

inline bool IsValidNode2(Unk80026864Node* node) {
    bool valid = true;
    if (node == 0) {
        valid = false;
    }
    return valid;
}

// Deletes the markers a list owns and empties it (as in fn_80027780, without the
// test for an empty list).
// The marker as its owner list destroys it: `delete` with an inline destructor.
struct Unk8002EFACMarker {
    ~Unk8002EFACMarker() { ((Unk8002FC60*)this)->fn_8002FD24(); }
    void operator delete(void* p) { fn_80169EE8(p); }
};

// Deletes the markers a list owns and empties it (as in fn_80027780, without the
// test for an empty list).
inline void DeleteMarkers(Unk80026864List& list) {
    Unk80026864Node* node = list.tail;
    while (IsValidNode2(node)) {
        Unk80026864Node* next = node->prev;
        Unk8002EFACMarker* item = (Unk8002EFACMarker*)node->item;
        if (list.owns) {
            delete item;
        }
        node = next;
    }
    list.fn_801B4760();
}

// Unk8002EF48 with its zeroing function (0x8002EF48) as an inline.
struct Unk8002EFACQueued {
    void Reset() {
        unk0 = 0;
        unk4 = 0;
        unk8 = 0;
        unkC = 0;
        unk10 = 0;
        unk14 = 0;
        unk18 = 0;
        unk1C = 0;
        unk20 = 0;
        unk24 = 0;
    }
    int unk0, unk4, unk8, unkC, unk10, unk14, unk18, unk1C, unk20, unk24;
};

// The marker list with its inline forwarding append.
struct Unk8002EFACList : Unk80026864List {
    void Add(void* item) { fn_801B4600(item); }
};

// A tile reference as the room lists store it (three bytes).

// Minimum and maximum as macros: the original evaluates the int-to-float
// conversion again for each use, which the inline EMinF/EMaxF do not.
#define F2EFAC_MIN(a, b) ((a) < (b) ? (a) : (b))
#define F2EFAC_MAX(a, b) ((a) > (b) ? (a) : (b))

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
// NON_MATCHING: 2 instructions: the two argument set-ups of the list append are
// swapped (the original has `mr r4,r30` before `addi r3,r31,0x194`). About twenty
// variants tried (inline forwarding appends, typed and reference parameters, a
// constructor that also creates the marker).
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
    ((Unk8002EFACList&)unk194).Add(marker);
    *(EVec2*)&unkAC = fn_8002BD98();
    marker->fn_8002FDC0((EVec2*)&unkAC);
    unk188 = EVec3(-1000.0f);
    ((Unk8002EFACQueued&)unk154).Reset();
    unk154.unk0 = 2;
    unk154.unk8 = (int)&unk188;
    unk154.unk14 = (int)fn_8002EFAC;
    unk154.unk18 = (int)this;
}

// 0x8002F1BC
// Releases the floor tool's texture and markers.
void Unk80026864::fn_8002F1BC() {
    E_RELEASE_RESOURCE(unk100);
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
    CTilePt tile(tileY, tileX, 1);
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
void Unk8002FC60::fn_8002FC60(float x, float y) {
    ERC* builder = lbl_8037C198->vfn13(1);
    ((Unk8016F034*)builder)->fn_8016F034(1.0f, 1.0f);
    unk4 = lbl_8037C198->vfn14(builder);
    unk8.fn_801B2AFC();
    EVec3 position;
    position.x = x;
    position.y = y;
    position[2] = 0.05f;
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
void Unk8002FC60::fn_8002FDC0(const EVec2* at) {
    unk8.fn_801B2AFC();
    EVec3 position;
    position.x = at->x;
    position.y = at->y;
    position[2] = 0.05f;
    unk8.fn_801B2B54(&position);
}

// The objects on a tile (the iterator with its inline wrappers).
struct Unk8002FE20Iter : Unk801FCE7C {
    Unk8002FE20Iter(const CTilePt& tile) : Unk801FCE7C(tile, 0) {}
    Unk800053D4Inner* Get() { return unk4; }
};

// 0x8002FE20
// Whether floor can be laid on a tile; with `flag`, nothing on it may object either.
int fn_8002FE20(CTilePt* tile, int flag) {
    if ((((Unk8037D990I*)lbl_8037D990)->vfn26(tile) & 0x21) != 1) {
        return 0;
    }
    if (flag) {
        Unk8002FE20Iter it(*tile);
        while (it.Get()) {
            if ((it.Get()->vfn88(0x2A) ^ 1) & 1) {
                return 0;
            }
            it.fn_801FCF04();
        }
    }
    return 1;
}

// 0x8002FEF4
// Price of floor type `index`.
int fn_8002FEF4(int index) {
    Unk8002EFACTypes* types = (Unk8002EFACTypes*)lbl_802E6700.unkC0b;
    if (index < types->GetCount()) {
        return types->At(index)->unk0;
    }
    return 0;
}

// 0x8002FF30
// What removing floor type `index` gives back: 80% of its price.
int fn_8002FF30(int index) {
    Unk8002EFACTypes* types = (Unk8002EFACTypes*)lbl_802E6700.unkC0b;
    if (index < types->GetCount() - 1) {
        return (int)((float)types->At(index)->unk0 * 0.8f);
    }
    return 0;
}

// 0x8002FFB8
// Refund for the floor on a tile (the mean of the two halves when it is split).
int fn_8002FFB8(CTilePt* tile) {
    int type = ((Unk8037D990I*)lbl_8037D990)->vfn14(tile);
    unsigned char* record = ((Unk8037D990I*)lbl_8037D990)->vfn22(tile);
    bool split = false;
    if (record[0] & 0x30) {
        split = true;
    }
    if (split) {
        int typeA = record[2];
        int typeB = record[4];
        return -((fn_8002FF30(typeA) + fn_8002FF30(typeB)) / 2);
    }
    return -fn_8002FF30(type);
}

// 0x80030084
// What flooring a rectangle of tiles with `type` costs; *any is set when at least
// one tile can take it.
int fn_80030084(int* any, int x0, int x1, int y0, int y1, int type) {
    *any = 0;
    int total = 0;
    for (int x = x0; x <= x1; x++) {
        for (int y = y0; y <= y1; y++) {
            CTilePt tile(x, y, 1);
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
            CTilePt tile(x, y, 1);
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
int fn_8003025C(int* any, void* table, Unk80234390* tiles, int type) {
    *any = 0;
    bool remove = type == 0;
    int total = 0;
    int count = (CTilePt*)tiles->unk4 - (CTilePt*)tiles->unk0;
    for (int i = 0; i < count; i++) {
        CTilePt* tile = (CTilePt*)((char*)tiles->unk0 + i * 3);
        if (fn_8002FE20(tile, type)) {
            *any = 1;
            Unk8023E420 info = ((Unk8037D990J*)lbl_8037D990)->vfn18(tile);
            if (!info.fn_8023DFA8()) {
                if (!remove) {
                    total += fn_8002FEF4(type);
                } else {
                    total += fn_8002FFB8(tile);
                }
            } else {
                int sideA = 0;
                int sideB = 0;
                fn_80031084(table, tile, &info, &sideA, &sideB);
                if (sideA == 0) {
                    if (!remove) {
                        total += fn_8002FEF4(type);
                    } else {
                        total -= fn_8002FF30(info.fn_8023E420(sideB)) / 2;
                    }
                } else if (sideB == 0) {
                    if (!remove) {
                        total += fn_8002FEF4(type);
                    } else {
                        total -= fn_8002FF30(info.fn_8023E420(sideA)) / 2;
                    }
                } else {
                    if (!remove) {
                        total += fn_8002FEF4(type);
                    } else {
                        total -= fn_8002FF30(info.fn_8023E420(sideB)) / 2;
                        total -= fn_8002FF30(info.fn_8023E420(sideA)) / 2;
                    }
                }
            }
        }
    }
    if (CheatMoney()) {
        return 0;
    }
    return total;
}

// The undo record as the floor tool makes it: an unnamed record of the whole lot.
struct Unk8003043CUndo : Unk801E6424 {
    Unk8003043CUndo() : Unk801E6424(1, 0x40, 0x40, &Unk801C3E30("")) {}
};

// Sets `free` when purchases cost nothing and fetches the household's funds.
#define F2EFAC_FUNDS(free, funds) \
    bool free = false; \
    int funds = ((Unk8037D944C*)lbl_8037D944)->vfn25(0); \
    if (CheatMoney()) { \
        free = true; \
    }

// Lays floor `type` on one tile of a rectangle: an older form of fn_800311B0
// that floors both halves of a cut tile.
// A tile reference built from tile coordinates, with an inline constructor.
struct Unk8003043CTile : CTilePt {
    Unk8003043CTile(int tileX, int tileY) : CTilePt(tileX, tileY, 1) {}
};

// Lays floor `type` on one tile of a rectangle: an older form of fn_800311B0
// that floors both halves of a cut tile.
inline void fn_8003043CLay(const CTilePt& at, int type) {
    CTilePt* tile = (CTilePt*)&at;
    if (fn_8002FE20(tile, type)) {
        Unk8037D990E* level = (Unk8037D990E*)lbl_8037D990;
        Unk8023DFA8 data = level->vfn18(tile);
        Unk8023DFA8* info = &data;
        if (!info->fn_8023DFA8()) {
            level->vfn15(tile, type);
        } else {
            int sideA;
            int sideB;
            if (info->fn_8023DEA4(0x20)) {
                sideA = 1;
                sideB = 3;
            } else {
                info->fn_8023DEA4(0x10);
                sideA = 2;
                sideB = 4;
            }
            info->fn_8023E43C(type, sideB);
            info->fn_8023E43C(type, sideA);
            Unk8023DDC4 packed(*info);
            level->vfn19(tile, &packed);
            level->vfn15(tile, 0xFF);
        }
    }
}

// 0x8003043C
// The floor tool: with button 0x11 held, button 5 floors the whole room under the
// cursor; otherwise button 5 floors the dragged rectangle and 0xF clears it. Each
// action is priced, checked against the household's money, recorded for undo,
// applied tile by tile and paid for. With no button the marker follows the cursor.
// NON_MATCHING: 781 instructions vs 786, 456 differ. A full reconstruction that an
// interrupted pass left part-way: the structure and calls follow the original, the
// register and stack layout do not yet. It was not taken further in this pass.
void Unk80026864::fn_8003043C() {
    EController* controller = lbl_8037C11C->fn_8015E5FC(lbl_8037C11C->fn_8015E614(unk38));
    if (controller->fn_8015DF98(0x11)) {
        if (fn_8015E298(controller, 5) && unk194.head) {
            int type = fn_800266C0((int*)unk194.head->item);
            int tileX;
            int tileY;
            fn_8002BB64(&tileX, &tileY);
            CTilePt tile(tileY, tileX, 1);
            int room = ((Unk8037D990K*)lbl_8037D990)->vfn24(&tile);
            Unk80234390* list = FindList((void*)room);
            if (list && room) {
                Unk80234390* tiles = (Unk80234390*)&list->unk4;
                CTilePt* it = (CTilePt*)tiles->unk0;
                if (it != (CTilePt*)tiles->unk4) {
                    int any = 0;
                    int cost = fn_8003025C(&any, list, tiles, type);
                    F2EFAC_FUNDS(free, funds)
                    if (!free && cost > funds) {
                        lbl_8037D96C->fn_8006186C(0x3804219F);
                    } else {
                        Unk8003043CUndo undo;
                        undo.fn_801E6BC4(((Unk8037D990L*)lbl_8037D990)->vfn13());
                        for (; it != (CTilePt*)tiles->unk4; it++) {
                            fn_800311B0((CTilePt*)it, type, list);
                        }
                        if (fn_8007600C()) {
                            lbl_802E6820[0]->fn_801E3C80(room, type);
                            ((Unk8037D944C*)lbl_8037D944)->vfn26(7, cost, 0);
                            if (type != 0) {
                                lbl_8037D96C->fn_8006186C(0xB2AD3ECD);
                            } else {
                                lbl_8037D96C->fn_8006186C(0x994E8974);
                            }
                            fn_80028ECC();
                        } else {
                            ((Unk801E6424*)((Unk8037D990L*)lbl_8037D990)->vfn13())->fn_801E6BC4(&undo);
                            lbl_8037D96C->fn_8006186C(0x3804219F);
                        }
                    }
                }
            }
        }
    } else if (fn_8015E298(controller, 5)) {
        if (unk194.head) {
            int type = fn_800266C0((int*)unk194.head->item);
            int tileX;
            int tileY;
            fn_8002BB64(&tileX, &tileY);
            int x0 = (int)F2EFAC_MIN((float)tileY, unkB0);
            int y0 = (int)F2EFAC_MIN((float)tileX, unkAC);
            int x1 = (int)F2EFAC_MAX((float)tileY, unkB0);
            int y1 = (int)F2EFAC_MAX((float)tileX, unkAC);
            int any = 0;
            int cost;
            if (type == 0) {
                cost = fn_80030170(&any, x0, x1, y0, y1, 0);
            } else {
                cost = fn_80030084(&any, x0, x1, y0, y1, type);
            }
            F2EFAC_FUNDS(free, funds)
            if (!free && cost > funds) {
                lbl_8037D96C->fn_8006186C(0x3804219F);
            } else {
                Unk8003043CUndo undo;
                undo.fn_801E6BC4(((Unk8037D990L*)lbl_8037D990)->vfn13());
                for (int x = x0; x <= x1; x++) {
                    for (int y = y0; y <= y1; y++) {
                        Unk8003043CTile tile(x, y);
                        fn_8003043CLay(tile, type);
                    }
                }
                if (fn_8007600C()) {
                    ((Unk8037D944C*)lbl_8037D944)->vfn26(7, cost, 0);
                    lbl_802E6820[0]->fn_801E3CE4(type, x0, y0, x1, y1);
                    if (type != 0) {
                        lbl_8037D96C->fn_8006186C(0xB2AD3ECD);
                    } else {
                        lbl_8037D96C->fn_8006186C(0x994E8974);
                    }
                    fn_80028ECC();
                } else {
                    ((Unk801E6424*)((Unk8037D990L*)lbl_8037D990)->vfn13())->fn_801E6BC4(&undo);
                    lbl_8037D96C->fn_8006186C(0x3804219F);
                }
            }
        }
    } else if (fn_8015E298(controller, 0xF)) {
        int type = 0;
        int tileX;
        int tileY;
        fn_8002BB64(&tileX, &tileY);
        int x0 = (int)F2EFAC_MIN((float)tileY, unkB0);
        int y0 = (int)F2EFAC_MIN((float)tileX, unkAC);
        int x1 = (int)F2EFAC_MAX((float)tileY, unkB0);
        int y1 = (int)F2EFAC_MAX((float)tileX, unkAC);
        int any = 0;
        int cost = fn_80030170(&any, x0, x1, y0, y1, type);
        F2EFAC_FUNDS(free, funds)
        if (!free && cost > funds) {
            lbl_8037D96C->fn_8006186C(0x3804219F);
        } else {
            Unk8003043CUndo undo;
            undo.fn_801E6BC4(((Unk8037D990L*)lbl_8037D990)->vfn13());
            for (int x = x0; x <= x1; x++) {
                for (int y = y0; y <= y1; y++) {
                    Unk8003043CTile tile(x, y);
                    if (fn_8002FE20(&tile, type)) {
                        fn_8003043CLay(tile, type);
                    }
                }
            }
            if (fn_8007600C()) {
                ((Unk8037D944C*)lbl_8037D944)->vfn26(7, cost, 0);
                lbl_802E6820[0]->fn_801E3CE4(type, x0, y0, x1, y1);
                if (type != 0) {
                    lbl_8037D96C->fn_8006186C(0xB2AD3ECD);
                } else {
                    lbl_8037D96C->fn_8006186C(0x994E8974);
                }
                fn_80028ECC();
            } else {
                ((Unk801E6424*)((Unk8037D990L*)lbl_8037D990)->vfn13())->fn_801E6BC4(&undo);
                lbl_8037D96C->fn_8006186C(0x3804219F);
            }
        }
    } else if (unk194.head) {
        Unk8002FC60* marker = (Unk8002FC60*)unk194.head->item;
        if (!controller->fn_8015DF98(5) && !controller->fn_8015DF98(0xF)) {
            *(EVec2*)&unkAC = fn_8002BD98();
        }
        marker->fn_8002FDC0((EVec2*)&unkA0);
    }
}

// 0x80031084
// Which halves of a diagonally cut tile lie inside the room: looks for the room on
// the tiles to the left and right.
void fn_80031084(void* table, CTilePt* tile, Unk8023DFA8* info, int* sideA, int* sideB) {
    *sideA = 0;
    *sideB = 0;
    if (info->fn_8023DFA8()) {
        CTilePt* at = (CTilePt*)tile;
        int left;
        {
            CTilePt neighbour(at->fn_801C727C() - 1, at->fn_801C7288(), 1);
            left = ((Unk80235F64*)table)->fn_80235F64(&neighbour);
        }
        int right;
        {
            CTilePt neighbour(at->fn_801C727C() + 1, at->fn_801C7288(), 1);
            right = ((Unk80235F64*)table)->fn_80235F64(&neighbour);
        }
        if (left) {
            if (info->fn_8023DEA4(0x10)) {
                *sideA = 2;
            } else {
                *sideA = 1;
            }
        }
        if (right) {
            if (info->fn_8023DEA4(0x10)) {
                *sideB = 4;
            } else {
                *sideB = 3;
            }
        }
    }
}

// 0x800311B0
// Lays floor `type` on one tile of a room (on the halves inside it when the tile is cut).
void fn_800311B0(CTilePt* tile, int type, void* table) {
    if (fn_8002FE20(tile, type)) {
        Unk8023DFA8 info = ((Unk8037D990E*)lbl_8037D990)->vfn18(tile);
        if (!info.fn_8023DFA8()) {
            ((Unk8037D990E*)lbl_8037D990)->vfn15(tile, type);
        } else {
            int sideA = 0;
            int sideB = 0;
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
            ((Unk8037D990E*)lbl_8037D990)->vfn19(tile, &packed);
            ((Unk8037D990E*)lbl_8037D990)->vfn15(tile, 0xFF);
        }
    }
}

// 0x80031324
// State 2's handler: what the floor tool's pending action would cost. With button
// 0x11 held it prices the room under the cursor, otherwise the dragged rectangle;
// button 0xF turns the action into removal.
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
        CTilePt tile(tileY, tileX, 1);
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
    int y0 = (int)F2EFAC_MIN((float)tileY, unkB0);
    int x0 = (int)F2EFAC_MIN((float)tileX, unkAC);
    int y1 = (int)F2EFAC_MAX((float)tileY, unkB0);
    int x1 = (int)F2EFAC_MAX((float)tileX, unkAC);
    int any = 0;
    if (controller->fn_8015DF98(0xF)) {
        type = 0;
    }
    if (type != 0) {
        return fn_80030084(&any, y0, y1, x0, x1, type);
    }
    return fn_80030170(&any, y0, y1, x0, x1, 0);
}
