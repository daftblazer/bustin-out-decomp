#include "sims/Unk80026864.h"
#include "sims/cas/CASSim.h"
#include "sims/cas/CASWidgets.h"
#include "sims/cas/CASSelectors.h"
#include "engine/EController.h"
#include "sims/cas/CASTarget.h"

extern float lbl_8037BFC8;
struct Unk8002FD24 {
    void fn_8002FD24();
};
int fn_80068758(int arg);

// Interface returned by fn_801FD05C: a pointer to the object's own pointer, then
// the vtable pointer.
struct Unk801FD05CResult {
    Unk800053D4Inner** unk0;
    Unk800053D4Inner* Object() const { return *unk0; }
    virtual void vfn1();
    virtual Unk800053D4Inner** vfn2();   // first contained object
    virtual Unk800053D4Inner** vfn3();   // next
    virtual int vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void* vfn8b();
    virtual int vfn9();
    virtual void vfn10(int);
};
// The part of a game object at +0x20: vtable pointer at 0x1C, slot 19 gives its model.
struct Unk801FD05C {
    char unk0[0x1C];
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
    virtual void* vfn19();
};
Unk801FD05CResult* fn_801FD05C(Unk801FD05C* object, int kind);
inline Unk801FD05C* GetUnk20(Unk800053D4Inner* object) { return *(Unk801FD05C**)((char*)object + 0x20); }

// The camera object's own mode word (its virtual base, at +0x1F0).
inline bool IsBuildCameraMode() {
    return ((Unk802A2AC0*)((char*)lbl_802E6700.unkBC + 0x1F0))->IsBuildMode();
}

struct Unk8037BFA8 {
    char unk0[0x468];
    int unk468;
};
extern Unk8037BFA8* lbl_8037BFA8;
struct Unk8004E8C8 {
    int fn_8004E8C8(Unk80026864List* selection);
    int fn_8004ED28();
};
Unk800053D4Inner* fn_80080418(void* item);
struct Unk8037D990B {
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
    virtual void vfn20();
    virtual void vfn21();
    virtual void vfn22();
    virtual void vfn23();
    virtual void vfn24();
    virtual void vfn25();
    virtual void vfn26();
    virtual void vfn27();
    virtual void vfn28();
    virtual void vfn29();
    virtual void vfn30();
    virtual void vfn31();
    virtual void vfn32();
    virtual void vfn33();
    virtual void vfn34(int);
};
struct Unk8004AD08 {
    struct Unk8007FFE8* unk0;
    struct Unk8007FFE8* unk4;
    void fn_8004AD08();
};
struct Unk8007FFE8 {
    void fn_8007FFE8(int);
};
extern void* lbl_8037D990;

// Object manager (0x8037D98C): slot 18 finds an object by id.
struct Unk8037D98C {
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
    virtual Unk800053D4Inner* vfn18(int id);
    int fn_801C8858(void* definition, int arg, int);
};
extern Unk8037D98C* lbl_8037D98C;
struct Unk801FD05CGroupNode {
    int unk0;
    Unk800053D4Inner** unk4;
};
struct Unk801FD05CGroupBase {
    int unk0;
    virtual void vfn1();
};
struct Unk801FD05CGroup : Unk801FD05CGroupBase {
    char unk8[4];
    struct Unk801FD05CGroupNode* unkC;
};
inline bool IsGroup(Unk800053D4Inner* object) {
    if (object && object->vfn124()) {
        return true;
    }
    return false;
}
inline Unk801FD05CGroup* GetGroup(Unk800053D4Inner* object) {
    if (object) {
        return (Unk801FD05CGroup*)fn_801FD05C(GetUnk20(object), 8);
    }
    return 0;
}
inline Unk800053D4Inner* FirstOf(Unk801FD05CGroupNode* node) {
    Unk800053D4Inner* first;
    if (node) {
        first = *node->unk4;
    } else {
        first = 0;
    }
    return first;
}
struct Unk8004F7EC {
    void fn_8004F7EC();
    void fn_8004F720();
};
struct Unk8007F3B4 {
    void fn_8007F3B4();
};
inline Unk801FD05CResult* GetPart(Unk800053D4Inner* object, int kind) {
    if (object) {
        return fn_801FD05C(GetUnk20(object), kind);
    }
    return 0;
}
inline bool HasFlag4(UnkTargetBase* screen) {
    if (!(screen->unk18 & 4)) {
        return false;
    }
    return true;
}
inline bool IsActive(UnkTargetBase* screen) {
    if (screen) {
        return HasFlag4(screen);
    }
    return false;
}
// A flag of the camera object.
inline bool IsCameraBusy() { return *(int*)((char*)lbl_802E6700.unkBC + 0x2958) != 0; }

struct Unk8037D990C {
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10(ETilePair* tile);
};
struct Unk80217FDC {
    char unk0[0x18];
    struct Unk80217FDCInfo* unk18;
};
struct Unk80217FDCInfo {
    char unk0[0x12];
    short unk12;
};
Unk80217FDC* fn_80217FDC(void* definition);
// Search parameters for an object's "find a free tile" call.
struct Unk80028AA4Query {
    Unk80028AA4Query() {
        unk0 = 0;
        unk1C = 0;
        unk10 = -1;
        unk14 = 1;
        unk18 = 1;
    }
    int unk0;
    char unk4[0x10 - 0x4];
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
struct Unk8037D994 {
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
extern Unk8037D994* lbl_8037D994;
int fn_80028AA4(Unk800053D4Inner* object);

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

// 0x800266EC
// Collects the models of an object (or of everything it contains) into a list.
// NON_MATCHING: 3 instructions. The original keeps the loop's iterator in r30 across
// the calls; here it stays in r3. Two variants tried.
void fn_800266EC(Unk800053D4Inner* object, Unk80026864List* out) {
    Unk800053D4Inner** it;
    out->fn_801B4760();
    if (object) {
        if (object->vfn124()) {
            Unk801FD05CResult* group = fn_801FD05C(GetUnk20(object), 3);
            if (group->vfn9()) {
                void* model = GetUnk20(object)->vfn19();
                if (model) {
                    out->fn_801B4600(model);
                }
            } else {
                for (it = group->vfn2(); it; it = group->vfn3()) {
                    void* model = GetUnk20(*it)->vfn19();
                    int present = out->fn_801B484C(model);
                    if (model != 0 && present == 0) {
                        out->fn_801B4600(model);
                    }
                }
            }
        } else {
            void* model = GetUnk20(object)->vfn19();
            if (model) {
                out->fn_801B4600(model);
            }
        }
    }
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
    if (list.tail) {
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

// 0x80027BF0
int Unk80026864::fn_80027BF0() {
    EController* controller = lbl_8037C11C->fn_8015E5FC(lbl_8037C11C->fn_8015E614(unk38));
    int button = IsBuildCameraMode() ? 5 : 6;
    if (unk84 != 1 && controller->fn_8015E0F8(button)) {
        if (lbl_8037BFA8->unk468 != 2) {
            fn_8002A0A8();
            int ok = ((Unk8004E8C8*)unkC8)->fn_8004E8C8(&unk148);
            if (ok == 0) {
                lbl_8037D96C->fn_8006186C(0x3804219F);
                unk84 = ok;
                return 0;
            }
        } else {
            fn_8002D1D0();
        }
        lbl_8037D96C->fn_8006186C(0x7D99927F);
        ((UnkTargetBase*)unkC)->vfn7(this, 0x13);
        unk84 = 1;
        return 1;
    }
    return 0;
}

// 0x80027D24
// NON_MATCHING: 4 instructions. The selection list's address is in r4 in the original
// and r9 here, and the final store of the state and `li r3,1` are exchanged. Four
// variants tried.
int Unk80026864::fn_80027D24() {
    EController* controller = lbl_8037C11C->fn_8015E5FC(lbl_8037C11C->fn_8015E614(unk38));
    int button = IsBuildCameraMode() ? 5 : 6;
    if (unk84 != 1 && controller->fn_8015E0F8(button)) {
        int state;
        fn_8002A0A8();
        if (unk148.Tail() != 0 && unk148.Tail() == unk148.Head()) {
            vfn7((UnkTargetBase*)fn_80080418(unk148.tail->item)->vfn111(), 0x1C);
            state = 0;
        } else {
            int ok = ((Unk8004E8C8*)unkC8)->fn_8004ED28();
            if (ok == 0) {
                lbl_8037D96C->fn_8006186C(0x3804219F);
                unk84 = ok;
                return 0;
            }
            lbl_8037D96C->fn_8006186C(0x7D99927F);
            state = 1;
        }
        unk84 = state;
        return 1;
    }
    return 0;
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

// 0x80027FCC
void Unk80026864::fn_80027FCC(Unk800053D4Inner* object) {
    ((Unk8037D990B*)lbl_8037D990)->vfn34(0);
    Unk8004AD08* view = (Unk8004AD08*)lbl_802E67B0.unk0;
    if (view->unk4) {
        view->unk4->fn_8007FFE8(0);
    }
    Unk801FD05CResult* found;
    if (object) {
        found = fn_801FD05C(GetUnk20(object), 0xB);
    } else {
        found = 0;
    }
    if (found) {
        view->fn_8004AD08();
    } else if (lbl_802E6700.fn_80068D9C(object)) {
        view->fn_8004AD08();
    }
}

// 0x80028080
// Messages from the child screen: 0x1C picks up the chosen object, 0x1D leaves.
void Unk80026864::vfn7(UnkTargetBase* sender, int message) {
    if (message == 0x1D) {
        if (!IsBuildMode()) {
            ((UnkTargetBase*)unkC)->vfn7(this, 0x14);
            ((Unk8007F3B4*)((Unk8004AD08*)lbl_802E67B0.unk0)->unk4)->fn_8007F3B4();
            unk84 = 0;
        } else {
            ((Unk8004F7EC*)unkC8)->fn_8004F7EC();
            unk84 = 0;
        }
    } else if (message == 0x1C) {
        if (IsBuildMode()) {
            Unk800053D4Inner* object = lbl_8037D98C->vfn18((int)sender);
            if (IsGroup(object)) {
                if (GetGroup(object)->unkC != 0) {
                    object = FirstOf(GetGroup(object)->unkC);
                }
            }
            if (object && object->vfn54()) {
                unk1B0 = 0;
                unk90 = 0;
                unk8C = 1;
                unk1A4 = *object->vfn115();
                unk1AC = object->vfn88(1);
                int arg = lbl_8037D988->vfn14(0x437);
                Unk8037D98C* manager = lbl_8037D98C;
                int id = manager->fn_801C8858(object->vfn111(), arg, 1);
                unkF0 = GetPart(lbl_8037D98C->vfn18(id), 4);
                unkF0->Object()->vfn48();
                if (unkF0) {
                    lbl_8037D96C->fn_8006186C(0xD9552AE4);
                    ((Unk8004F7EC*)unkC8)->fn_8004F7EC();
                    unk84 = 0;
                    fn_80027FCC((Unk800053D4Inner*)((Unk801FD05CResult*)unkF0)->vfn8b());
                    return;
                }
            }
            lbl_8037D96C->fn_8006186C(0x3804219F);
        }
    } else {
        if (message == 0x1A) {
            message = 0x11;
        } else if (message == 0x1B) {
            message = 0x12;
        }
        ((UnkTargetBase*)unkC)->vfn7(sender, message);
    }
}

// 0x8002840C
// Mode change (the virtual base's slot 2).
void Unk80026864::vfn2(int mode) {
    Unk802A2AC0::mode = mode;
    switch (mode) {
    case 9:
        fn_801888F4(2, 1);
        break;
    case 0:
        Common();
        ((Unk8004F7EC*)unkC8)->fn_8004F7EC();
        unk84 = mode;
        vfn10(2, 1);
        unk18 |= 2;
        break;
    case 8:
        Common();
        ((Unk8004F7EC*)unkC8)->fn_8004F7EC();
        fn_801888F4(2, 0);
        unk84 = 6;
        break;
    case 3: {
        int player = unk38;
        if (player == 0) {
            Common();
            ((Unk8004F7EC*)unkC8)->fn_8004F7EC();
            fn_801888F4(2, 0);
            unk84 = player;
        }
        break;
    }
    case 4:
        if (unk38 != 1) {
            break;
        }
    case 1:
    case 2:
    case 6:
    case 7:
        Common();
        ((Unk8004F7EC*)unkC8)->fn_8004F7EC();
        fn_801888F4(2, 0);
        unk84 = 0;
        break;
    case 5:
        break;
    default:
        Common();
        break;
    }
}

// 0x800285D4
void Unk80026864::fn_800285D4() {
    if (!IsCameraBusy()) {
        UnkTargetBase* child = unkC8;
        if (unk84 == 1 && IsActive(child)) {
            child->vfn2();
            return;
        }
        if (IsActive(child)) {
            ((Unk8004F7EC*)child)->fn_8004F720();
        }
        if (!fn_80027BF0()) {
            fn_80029BF8();
        }
    }
}

// 0x800286CC
// NON_MATCHING: same length, 51 instructions differ. The original evaluates and
// discards a two-mode test of the camera (`cmpwi 8; beq; cmpwi 10`) before the state
// check; no form tried here keeps it, and the rest is shifted by it. Three variants.
void Unk80026864::fn_800286CC() {
    EController* controller = lbl_8037C11C->fn_8015E5FC(lbl_8037C11C->fn_8015E614(unk38));
    IsBuildCameraMode();
    if (unk84 - 2 <= 3) {
        int up = controller->fn_8015E0F8(0x33);
        int down = controller->fn_8015E0F8(0x34);
        int left = controller->fn_8015E0F8(0x35);
        int right = controller->fn_8015E0F8(0x36);
        bool moved = up || down || left || right;
        if (moved || (controller->fn_8015E0F8(7) && !(unk88 & 1))) {
            ((UnkTargetBase*)unkC)->vfn7(this, 0x27);
        }
    }
    switch (unk84) {
    case 2:
        fn_80029BF8();
        fn_8003043C();
        break;
    case 3:
    case 5:
        fn_80029BF8();
        fn_80033C3C();
        break;
    case 4:
        fn_80029BF8();
        fn_80031980();
        break;
    default:
        fn_8002917C();
        break;
    }
}

// 0x80028860
// Puts the object being moved back where it was picked up.
int Unk80026864::fn_80028860() {
    if (unkF0) {
        ETilePair tile;
        unkF0->Object()->vfn114(&tile);
        if (unkF0->Object()->vfn64()) {
            unkF0->Object()->vfn48();
        }
        unkF0->Object()->vfn50(&tile, 1, 0, 0);
        if (unkF0->Object()->vfn64()) {
            unkF0->Object()->vfn48();
        }
        unkF0->vfn10(unk1AC);
        ETilePair home = unk1A4;
        ((Unk8037D990C*)lbl_8037D990)->vfn10(&home);
        if (unkF0->Object()->vfn49(&home, 1, 0, 0)) {
            unkF0->Object()->vfn50(&home, 1, 0, 0);
            if (unkF0->vfn3() && unkF0->vfn4()) {
                return 1;
            }
        }
    }
    return 0;
}

// 0x80028AA4
// Moves an object to the nearest free tile; false when there is none.
// NON_MATCHING: 66 instructions vs 67. The original places the object right after the
// first successful search and jumps back to that code after the second; here the
// placement comes after both searches. Three variants tried.
int fn_80028AA4(Unk800053D4Inner* object) {
    if (object && fn_80217FDC(object->vfn119())->unk18->unk12 != 7) {
        Unk80028AA4Query query;
        ETilePair tile;
        if (!object->vfn61(&query, &tile)) {
            query.unk14 = 0;
            if (!object->vfn61(&query, &tile)) {
                return 0;
            }
        }
        object->vfn50(&tile, 1, 0, 0);
    }
    return 1;
}

// 0x80028E84
void* Unk80026864::fn_80028E84() {
    return unkF0 ? unkF0->vfn8b() : 0;
}

// 0x80028ECC
void Unk80026864::fn_80028ECC() {
    ((Unk8037D990B*)lbl_8037D990)->vfn34(0);
    lbl_802E6700.fn_80068838();
    lbl_8037D994->vfn19();
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
