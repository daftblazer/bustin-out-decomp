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

// 0x8002EFAC
void fn_8002EFAC(ERC* rc, Unk8002EFACItem* item) {
    int a;
    int b;
    int c;
    int d;
    item->unk1C->fn_80181824(rc);
    fn_8002F2E0(item->unk18, rc, &a, &b, &c, &d);
}

// 0x8002F1BC
// Releases the floor tool's texture and markers.
void Unk80026864::fn_8002F1BC() {
    if (unk100) {
        fn_801767FC(unk100);
        unk100 = 0;
    }
    Unk80026864Node* node = unk194.tail;
    while (EIsValidNode(node)) {
        Unk8002FC60* item = (Unk8002FC60*)node->item;
        Unk80026864Node* next = node->prev;
        if (unk194.owns && item) {
            item->fn_8002FD24();
            fn_80169EE8(item);
        }
        node = next;
    }
    unk194.fn_801B4760();
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
void Unk8002FC60::fn_8002FDC0(const EVec2* at) {
    unk8.fn_801B2AFC();
    EVec3 position(at->x, at->y, 0.05f);
    unk8.fn_801B2B54(&position);
}

// 0x8002FE20
// Whether floor can be laid on a tile; with `flag`, nothing on it may object either.
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
int fn_8002FEF4(int index) {
    Unk802E67C0Entry** types = ((Unk802E67C0*)lbl_802E6700.unkC0b)->unk0;
    if (index >= ECount((int*)types)) {
        return 0;
    }
    return types[index]->unk0;
}

// 0x8002FF30
// What removing floor type `index` gives back: 80% of its price.
int fn_8002FF30(int index) {
    Unk802E67C0Entry** types = ((Unk802E67C0*)lbl_802E6700.unkC0b)->unk0;
    if (index >= ECount((int*)types) - 1) {
        return 0;
    }
    return (int)((float)types[index]->unk0 * 0.8f);
}

// 0x8002FFB8
// Refund for the floor on a tile (the mean of the two halves when it is split).
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
