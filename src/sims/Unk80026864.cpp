#include "sims/Unk80026864.h"
#include "sims/cas/CASSim.h"
#include "sims/cas/CASWidgets.h"

extern float lbl_8037BFC8;
struct Unk8002FD24 {
    void fn_8002FD24();
};
int fn_80068758(int arg);

// Callback table copied over the engine's defaults (0x30 bytes at 0x802D1ED8).
struct Unk802DBAEC {
    int unk0[10];
};
extern Unk802DBAEC lbl_802D1ED8;
extern Unk802DBAEC lbl_802DBAEC;
void fn_8002E1BC();
void fn_8002E2A0();
void fn_8002E498();
void fn_8002E5DC();
void fn_8002E68C();
void fn_8002E73C();
void fn_8002EA74();
extern void (*lbl_80381438)();
extern void (*lbl_8038143C)();
extern void (*lbl_80381440)();
extern void (*lbl_80381444)();
extern void (*lbl_80381448)();
extern void (*lbl_8038144C)();
extern void (*lbl_80381450)();
extern void (*lbl_80381454)(void*);
extern int (*lbl_80381458)(int);

Unk802E5B28 lbl_802E5B28;
ELightSet lbl_802E5B40[2];
ELightSet lbl_802E5D00;
EVec3 lbl_802E5DE0(0.0f, 0.0f, 0.0f);

// 0x800266C0
void fn_800266C0(int* id) {
    lbl_802E6700.fn_800673EC(*id);
}

// 0x80026864
Unk80026864::Unk80026864(int player) {
    fn_8002ED34();
    unk38 = player;
    unkC0 = 0;
    unkC4 = 0;
    unkC8 = 0;
    unkFC = 0;
    unk100 = 0;
    unk104 = 0;
    unk108 = 0;
    unk10C = 0;
    unk110 = 0;
    unk114 = 0;
    unk118 = 0;
    unk11C = 0;
    unk120 = 0;
    unk124 = 0;
    unk128 = 0;
    unk130 = 0;
    unk12C = 0;
    unk134 = 0;
    unk138 = 0;
    unk13C = 0;
    unk140 = 0;
    unk144 = 0;
    unkBC = 0;
    unkF0 = 0;
    unk84 = 0;
    unk88 = 0;
    unk90 = 0;
    unk8C = 0;
    unkA0 = EVec3(0.0f);
    unk94 = unkA0;
    unk1B8 = 1;
    unk1C0 = 1;
    unk1B0 = 0;
    unk1B4 = 0;
    unkF8 = 0;
    unkF4 = 0.0f;
    unk1BC = 0.0f;
    fn_80111C78(unk4C, 0, sizeof(unk4C));
    unk4C[0] = &Unk80026864::fn_800290B0;
    unk4C[2] = &Unk80026864::fn_80031324;
    unk4C[3] = &Unk80026864::fn_80033974;
    unk4C[4] = &Unk80026864::fn_80033754;
    unk4C[5] = &Unk80026864::fn_80033954;
    unkCC = 0;
}

// 0x80026B34
Unk80026864::~Unk80026864() {
    fn_80027780();
}

// Vertex handed to the mesh builder (0x50 bytes).
struct Unk80173D58Vertex {
    float unk0[4];   // position
    int unk10[3];    // normal, -127..127
    int unk1C;
    float unk20[4];  // texture coordinates
    int unk30[4];    // colour
};
Unk80173D58Vertex* fn_80173D58(int size, int align);
struct Unk8016F034 {
    char unk0[0x44];
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3(Unk80173D58Vertex* vertices, int count);
    void fn_8016F034(float, float);
};
// The child screen created by fn_80026C78 (0x60 bytes, constructor 0x8004E19C).
class Unk8004E19C : public UnkTargetBase {
public:
    Unk8004E19C(int player);
    char unk48[0x60 - 0x48];
};
extern EVec3 lbl_802E6A14;
extern EVec3 lbl_802E6A24;

// Component of a unit normal scaled to a signed byte range.
inline int QuantizeNormal(float value) {
    if (value < -127.0f) {
        return -0x7F;
    }
    if (value > 127.0f) {
        return 0x7F;
    }
    return (signed char)(int)value;
}

inline void SetVertexNormal(Unk80173D58Vertex* vertex, float x, float y, float z) {
    EVec3 normal(x, y, z);
    fn_801221E4(&normal, &normal);
    normal.x *= 127.0f;
    normal.y *= 127.0f;
    normal.z *= 127.0f;
    vertex->unk10[0] = QuantizeNormal(normal.x);
    vertex->unk10[1] = QuantizeNormal(normal.y);
    vertex->unk10[2] = QuantizeNormal(normal.z);
    vertex->unk1C = 0;
}

inline void SetVertex(Unk80173D58Vertex* vertex, float x, float y, float u, float v) {
    vertex->unk20[0] = u;
    vertex->unk20[2] = v;
    vertex->unk20[3] = 1.0f;
    vertex->unk20[1] = 1.0f;
    vertex->unk0[1] = y;
    vertex->unk0[2] = 0.035f;
    vertex->unk0[3] = 1.0f;
    vertex->unk0[0] = x;
}

// 0x80026C78
// Builds the two cursor quads (a 3.5 and a 4.5 tile square, as two triangle
// strips of four vertices each), loads the cursor's textures and models, and
// creates the child screen.
// NON_MATCHING: condensed draft. The renderer and resource calls are the original's,
// in order; the vertex data is written through helpers here where the original has
// eight open-coded vertices built by copying the first one, so most of the function
// differs. One variant tried.
void Unk80026864::fn_80026C78() {
    lbl_802E5B40[1].numPoint = 0;
    lbl_802E5D00.ambient = EVec3(1.0f, 1.0f, 1.0f);
    lbl_802E5B40[0].numDirectional = 0;
    lbl_802E5B40[0].numPoint = 0;
    lbl_802E5B40[1].numDirectional = 0;
    lbl_802E5D00.numDirectional = 0;
    lbl_802E5D00.numPoint = 0;
    unk84 = 0;
    unk18 |= 2;
    Unk8016F034* builder = (Unk8016F034*)lbl_8037C198->vfn13(1);
    builder->fn_8016F034(1.0f, 1.0f);
    unkC0 = lbl_8037C198->vfn14((ERC*)builder);
    builder = (Unk8016F034*)lbl_8037C198->vfn13(1);
    Unk80173D58Vertex* vertices = fn_80173D58(0x280, 0x20);
    for (int quad = 0; quad < 2; quad++) {
        float size = quad == 0 ? 3.5f : 4.5f;
        Unk80173D58Vertex* v = vertices + quad * 4;
        v[0].unk30[3] = 0x80;
        v[0].unk30[0] = 0x80;
        v[0].unk30[1] = 0x80;
        v[0].unk30[2] = 0x80;
        SetVertexNormal(&v[0], 1.0f, 0.0f, -1.0f);
        SetVertex(&v[0], size, 0.0f, 1.0f, 0.0f);
        v[1] = v[0];
        SetVertex(&v[1], 0.0f, 0.0f, 0.0f, 0.0f);
        v[2] = v[0];
        SetVertex(&v[2], size, size, 1.0f, 1.0f);
        v[3] = v[0];
        SetVertex(&v[3], 0.0f, size, 0.0f, 1.0f);
        builder->vfn3(v, 4);
    }
    unkC4 = lbl_8037C198->vfn14((ERC*)builder);
    unkFC = lbl_80340AB8.fn_80177628(unk38 == 0 ? 0x9A1FBCDE : 0xE8136BD8, 0, 0);
    lbl_802E5B40[unk38].ambient = unk38 == 0 ? lbl_802E6A24 : lbl_802E6A14;
    unk108 = lbl_8033FF34.fn_80177628(0x18DD79EC, 0, 0);
    unk10C = lbl_8033FF34.fn_80177628(0xDFEFF763, 0, 0);
    unk110 = lbl_8033FF34.fn_80177628(0x295792E6, 0, 0);
    unk114 = lbl_8033FF34.fn_80177628(0xF6140AD9, 0, 0);
    unk118 = lbl_8033FF34.fn_80177628(0xB4D2FB9A, 0, 0);
    unk11C = lbl_8033FF34.fn_80177628(0xC1A394FD, 0, 0);
    unk120 = lbl_8033FF34.fn_80177628(0x528D93C8, 0, 0);
    unk124 = lbl_8033FF34.fn_80177628(0x68DE8AE2, 0, 0);
    unk128 = lbl_8033FF34.fn_80177628(0xC2706DA9, 0, 0);
    unk130 = lbl_8033FF34.fn_80177628(0x483B42F3, 0, 0);
    unk12C = lbl_8033FF34.fn_80177628(0xD9CFD517, 0, 0);
    unk134 = lbl_8033FF34.fn_80177628(0x05ADADD6, 0, 0);
    unk13C = lbl_8033FF34.fn_80177628(0x7BF822A7, 0, 0);
    unk138 = lbl_8033FF34.fn_80177628(0xB5FA839A, 0, 0);
    unkC8 = new Unk8004E19C(unk38);
    vfn14(unkC8);
}

// 0x8002775C
void Unk80026864::fn_8002775C(int value) {
    unkBC = value;
    fn_80027EAC();
}

// Deletes the objects a list owns, then empties it.
inline void DeleteAll(Unk80026864List& list) {
    if (list.count) {
        Unk80026864Node* node = list.head;
        while (EIsValid(node)) {
            Unk8002FD24* item = (Unk8002FD24*)node->item;
            Unk80026864Node* next = node->next;
            if (list.owns && item) {
                item->fn_8002FD24();
                fn_80169EE8(item);
            }
            node = next;
        }
        list.fn_801B4760();
    }
}

// 0x80027780
// NON_MATCHING: 8 instructions. The list walk keeps its node in r3 instead of r9, and
// the load of the first resource is hoisted above the store that clears unkC8.
// Four variants tried.
void Unk80026864::fn_80027780() {
    unk148.Clear();
    DeleteAll(unk194);
    if (unkC0) {
        if (lbl_8037C198->vfn19(unkC0)) {
            lbl_8037C198->vfn8();
        }
        lbl_8037C198->vfn18(unkC0);
        unkC0 = 0;
    }
    if (unkC4) {
        if (lbl_8037C198->vfn19(unkC4)) {
            lbl_8037C198->vfn8();
        }
        lbl_8037C198->vfn18(unkC4);
        unkC4 = 0;
    }
    vfn15(unkC8);
    if (unkC8) {
        delete unkC8;
    }
    unkC8 = 0;
    if (unkFC) {
        fn_801767FC(unkFC);
        unkFC = 0;
    }
    if (unk100) {
        fn_801767FC(unk100);
        unk100 = 0;
    }
    if (unk104) {
        fn_801767FC(unk104);
        unk104 = 0;
    }
    if (unk108) {
        fn_801767FC(unk108);
        unk108 = 0;
    }
    if (unk10C) {
        fn_801767FC(unk10C);
        unk10C = 0;
    }
    if (unk110) {
        fn_801767FC(unk110);
        unk110 = 0;
    }
    if (unk114) {
        fn_801767FC(unk114);
        unk114 = 0;
    }
    if (unk118) {
        fn_801767FC(unk118);
        unk118 = 0;
    }
    if (unk11C) {
        fn_801767FC(unk11C);
        unk11C = 0;
    }
    if (unk120) {
        fn_801767FC(unk120);
        unk120 = 0;
    }
    if (unk124) {
        fn_801767FC(unk124);
        unk124 = 0;
    }
    if (unk128) {
        fn_801767FC(unk128);
        unk128 = 0;
    }
    if (unk12C) {
        fn_801767FC(unk12C);
        unk12C = 0;
    }
    if (unk130) {
        fn_801767FC(unk130);
        unk130 = 0;
    }
    if (unk134) {
        fn_801767FC(unk134);
        unk134 = 0;
    }
    if (unk138) {
        fn_801767FC(unk138);
        unk138 = 0;
    }
    if (unk13C) {
        fn_801767FC(unk13C);
        unk13C = 0;
    }
    fn_80027EAC();
    unk84 = 0;
}

// 0x80027AD8
int Unk80026864::fn_80027AD8() {
    if (unk84 <= 6 && unk4C[unk84] != 0) {
        return (this->*unk4C[unk84])();
    }
    return 0;
}

// 0x80027B7C
void Unk80026864::vfn4(const EVec3& position) {
    unkA0 = position;
    ((UnkTargetBase*)unkC)->vfn7(this, unk38 == 0 ? 0x15 : 0x16);
}

// 0x80027E84
void Unk80026864::vfn18(int flags, int set) {
    if (set) {
        unk18 |= flags;
    } else {
        unk18 &= ~flags;
    }
}

// World coordinate of a tile index. Taking the index by reference is what makes the
// original copy the tile pair to the stack first.
inline float TileToWorld(const int& tile, float origin) { return (float)tile * 0.0625f + origin; }

// 0x80027EAC
// Puts the cursor on the tile the player's sim stands on.
void Unk80026864::fn_80027EAC() {
    EGlobal* global = &lbl_802E6700;
    if (global->unk9C[0] || global->unk9C[1]) {
        Unk800053D4Owner* owner = global->unk9C[unk38];
        if (owner) {
            ETilePair tile = *owner->unk0->vfn115();
            unkA0.Set(TileToWorld(tile.x, global->unk7C), TileToWorld(tile.y, global->unk80), 0.05f);
            unk94 = unkA0;
        }
    }
}

// 0x8002ECE8
void fn_8002ECE8(void* arg) {
    ((Unk80026864*)lbl_802E6700.unkA8[0])->fn_8002C370(arg);
}

// 0x8002ED14
int fn_8002ED14(int arg) {
    return fn_80068758(arg);
}

// 0x8002ED34
// Installs this file's callbacks.
void Unk80026864::fn_8002ED34() {
    lbl_802DBAEC = lbl_802D1ED8;
    lbl_80381438 = fn_8002E1BC;
    lbl_8038143C = fn_8002E2A0;
    lbl_80381440 = fn_8002E498;
    lbl_80381444 = fn_8002E5DC;
    lbl_80381448 = fn_8002E68C;
    lbl_8038144C = fn_8002E73C;
    lbl_80381450 = fn_8002EA74;
    lbl_80381454 = fn_8002ECE8;
    lbl_80381458 = fn_8002ED14;
}

// 0x8002EF48
void Unk8002EF48::fn_8002EF48() {
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

// 0x8002EF78
void Unk80026864::vfn3(ERC* rc) {
}

// 0x8002EF7C
void Unk80026864::vfn3() {
}
