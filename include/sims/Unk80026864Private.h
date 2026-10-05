#ifndef SIMS_UNK80026864PRIVATE_H
#define SIMS_UNK80026864PRIVATE_H

// Declarations shared by the source files that implement Unk80026864 and the
// build-mode tools around it. Everything here is provisional: most of these types
// belong to engine or game classes that have not been identified yet.

#include <stddef.h>
#include "sims/Unk80026864.h"
#include "sims/cas/CASSim.h"
#include "sims/cas/CASWidgets.h"
#include "sims/cas/CASSelectors.h"
#include "engine/EController.h"
#include "sims/cas/CASTarget.h"

void* fn_80169F1C(unsigned int size, int align);

// Vertex handed to the mesh builder (0x50 bytes).
struct Unk80173D58Vertex {
    Unk80173D58Vertex() {}
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
extern float lbl_8037BFC8;
// A square drawn on the floor (0x48 bytes): a recorded renderer object and where
// to draw it. unk194 owns a list of these.
struct Unk8002FC60 {
    Unk8002FC60(void* owner) {
        unk0 = owner;
        unk4 = 0;
    }
    void* operator new(size_t size) { return fn_80169F1C(size, 16); }
    void fn_8002FC60(float x, float y);      // create at a position
    void fn_8002FD24();                      // release
    void fn_8002FDC0(const EVec2* at);       // move

    void* unk0;      // the tool it belongs to
    void* unk4;      // renderer object
    EMat4 unk8;
};
typedef Unk8002FC60 Unk8002FD24;
int fn_80068758(int arg);

// Interface returned by fn_801FD05C: a pointer to the object's own pointer, then
// the vtable pointer.
struct Unk801FD05CResult {
    Unk800053D4Inner** unk0;
    Unk800053D4Inner* Object() const { return *unk0; }
    virtual void vfn1();
    virtual Unk801FD05CResult* vfn2();   // first contained object's node
    virtual Unk801FD05CResult* vfn3();   // the node after this one
    // In a container's nodes the first word is the object itself.
    Unk800053D4Inner* Direct() const { return (Unk800053D4Inner*)unk0; }
    virtual int vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual Unk800053D4Inner* vfn8b();   // the object itself
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
// The same view object's origin.
struct Unk8004AD08B {
    char unk0[0x34];
    EVec2 unk34;   // world position of tile (0, 0)
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
    int fn_801C92C4(void* definition, int arg, int);
    int Create(void* definition, int arg, int flag) { return fn_801C92C4(definition, arg, flag); }
};
// The same object's slot 11 (destroy an object by definition); declared apart
// because slot 18 above is the only other one known.
struct Unk8037D98CB {
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
    virtual void vfn11(void* definition);
};
struct Unk8037D944B {
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
    virtual void vfn26(int kind, int amount, int);
};
extern void* lbl_8037D944;
struct Unk800914D0 {
    void fn_800914D0();
};
struct Unk8007F630 {
    void fn_8007F630(int player, Unk80026864List* out);
};
struct Unk80064F8C {
    int fn_80064F8C(unsigned char player);
};
extern Unk80064F8C* lbl_802E30B8[3]; // part of a larger object; size guessed
struct Unk80217FDCInfoB {
    char unk0[0x24];
    short unk24; // price
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

// The camera object the cursor follows (ESimsCam); only what is used here.
struct Unk80026864Cam {
    float fn_8000562C();          // ESimsCam::GetCurZoomRatio, 0..1 (ESimsCam.h cannot be
                                  // included next to CASSim.h yet)
    void fn_80007528(int player, EVec3& move);   // ESimsCam::CursorMoved
    char unk0[0x328];
    int unk328;                   // camera mode
    char unk32C[0x378 - 0x32C];
    EVec3 unk378;                 // eye
    char unk384[0x390 - 0x384];
    float unk390;                 // cursor speed
    char unk394[4];
    EVec3 unk398;                 // target
};
extern float lbl_8037B4A0;
extern "C" float fn_8010DD60(float y, float x); // atan2f
void fn_800328F4(struct Unk801C6F20* tile);
// A stick axis squared, keeping its sign.
inline float SignedSquare(float value) {
    if (value < 0.0f) {
        return value * -value;
    }
    return value * value;
}
extern float lbl_8037B4A4;
extern float lbl_8037B4A8;
void fn_800686D4(Unk800053D4Inner* object);
struct Unk80173D58Alloc {
    EMat4* fn_80173D58(int size, int align);
};

// One queued piece of cursor/overlay drawing, as handed to the callbacks below.
struct Unk8002D67CItem {
    char unk0[6];
    unsigned short unk6;
    float unk8;
    float unkC;
    float unk10;
    float unk14;
    EVec2 unk18;          // offset
    char unk20[0x24 - 0x20];
    unsigned char unk24;
    Unk80181824* unk28;   // texture
};
void fn_8002D67C(ERC* rc, Unk8002D67CItem* item);
void fn_8002E0C4(ERC* rc, Unk8002D67CItem* item);
void fn_80035C70(ERC* rc, Unk80181824* texture, EVec2* a, EVec2* b, int* flag);
extern Unk80181824* lbl_8037B4B0;
struct Unk80056498 {
    void fn_80056498(ERC* rc, unsigned short id, float* at);
};
struct Unk8004AD08C {
    char unk0[8];
    Unk80056498* unk8;
};
struct Unk800B38CC {
    void fn_800B38CC(int player, void* definition, EVec3* position);
};
struct Unk8004FC0C {
    int fn_8004FC0C(int, int);
};

// Tile position as used by the object search (8 bytes; constructors 0x801C6F20 and
// 0x801C6F00, destructor 0x801C6FCC). This is CTilePt; the shared header's copy has
// a different size, so it is declared apart until that is sorted out.
struct Unk801C6F20 {
    Unk801C6F20() {}
    Unk801C6F20(const ETilePair& subTile, int);
    Unk801C6F20(const Unk801C6F20& other);
    ~Unk801C6F20();
    char unk0[8];
};
// Walks the objects standing on a tile.
struct Unk801FCE7C {
    Unk801FCE7C(const Unk801C6F20& tile, int);
    void fn_801FCF04();   // next
    int unk0;
    Unk800053D4Inner* unk4;   // current object
    char unk8[8];
};
struct Unk8037D990D {
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual int vfn8(Unk801C6F20* tile);   // off the lot
};
extern int lbl_8037B4BC;
extern void* lbl_8037B4C0;
extern void* lbl_8037B4AC;
extern void* lbl_8037B4B4;
extern void* lbl_8037B4B8;
void fn_80031CF0(ERC* rc, Unk80181824* texture, EVec2* a, EVec2* b, int, float, float);
void fn_8003849C(ERC* rc, EVec2* a, EVec2* b, Unk80181824* texture, void* out, int kind, int);
struct Unk80234390 {
    int unk0;
    char* unk4;   // first
    char* unk8;   // one past the last
};
extern void* lbl_8037D998;
Unk80234390* fn_80234390(void* table, void* key);
void fn_800311B0(Unk801C6F20* tile, int type, void* table);
int fn_8007600C();
void fn_80038FC0(EVec2* a, EVec2* b, void* arg, int kind, int* out, int, int, int);
struct Unk80057920 {
    int fn_80057920(int);
};
inline Unk80234390* FindList(void* key) {
    if (lbl_8037D998) {
        return fn_80234390(lbl_8037D998, key);
    }
    return 0;
}

// Sub-tile coordinates (sixteenths of a tile) of a tile's corner, and of its middle.
inline void SetSubTile(ETilePair& out, int tileX, int tileY) {
    out.x = tileX << 4;
    out.y = tileY << 4;
}
inline void CentreSubTile(ETilePair& tile) {
    tile.y = (tile.y & ~0xF) | 8;
    tile.x = (tile.x & ~0xF) | 8;
}
// What stands on a tile, as the level reports it (0x38 bytes), and its packed form.
struct Unk8023DFA8 {
    ~Unk8023DFA8();
    int fn_8023DFA8();
    int fn_8023DEA4(int mask);
    void fn_8023E43C(int flag, int which);
    char unk0[0x38];
};
struct Unk8023DDC4 {
    Unk8023DDC4(const Unk8023DFA8& info);
    char unk0[0x38];
};
struct Unk801C6F44 : Unk801C6F20 {
    Unk801C6F44(int tileX, int tileY, int);
};
int fn_8002FE20(Unk801C6F20* tile, int flag);
struct Unk8037D990E {
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual int vfn10(ETilePair* tile);
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15(Unk801C6F20* tile, int value);
    virtual void vfn16();
    virtual void vfn17();
    virtual Unk8023DFA8 vfn18(Unk801C6F20* tile);
    virtual void vfn19(Unk801C6F20* tile, Unk8023DDC4* packed);
};

struct Unk801C727C : Unk801C6F20 {
    int fn_801C727C();   // tile x
    int fn_801C7288();   // tile y
};
struct Unk8037D990F {
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual int vfn6();   // lot size in tiles
};
struct Unk8037D988B {
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
};
// vfn117 of a game object returns its tile; declared here with the 8-byte type.
struct Unk800053D4InnerB {
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
    virtual void vfn34();
    virtual void vfn35();
    virtual void vfn36();
    virtual void vfn37();
    virtual void vfn38();
    virtual void vfn39();
    virtual void vfn40();
    virtual void vfn41();
    virtual void vfn42();
    virtual void vfn43();
    virtual void vfn44();
    virtual void vfn45();
    virtual void vfn46();
    virtual void vfn47();
    virtual void vfn48();
    virtual void vfn49();
    virtual void vfn50();
    virtual void vfn51();
    virtual void vfn52();
    virtual void vfn53();
    virtual void vfn54();
    virtual void vfn55();
    virtual void vfn56();
    virtual void vfn57();
    virtual void vfn58();
    virtual void vfn59();
    virtual void vfn60();
    virtual void vfn61();
    virtual void vfn62();
    virtual void vfn63();
    virtual void vfn64();
    virtual void vfn65();
    virtual void vfn66();
    virtual void vfn67();
    virtual void vfn68();
    virtual void vfn69();
    virtual void vfn70();
    virtual void vfn71();
    virtual void vfn72();
    virtual void vfn73();
    virtual void vfn74();
    virtual void vfn75();
    virtual void vfn76();
    virtual void vfn77();
    virtual void vfn78();
    virtual void vfn79();
    virtual void vfn80();
    virtual void vfn81();
    virtual void vfn82();
    virtual void vfn83();
    virtual void vfn84();
    virtual void vfn85();
    virtual void vfn86();
    virtual void vfn87();
    virtual void vfn88();
    virtual void vfn89();
    virtual void vfn90();
    virtual void vfn91();
    virtual void vfn92();
    virtual void vfn93();
    virtual void vfn94();
    virtual void vfn95();
    virtual void vfn96();
    virtual void vfn97();
    virtual void vfn98();
    virtual void vfn99();
    virtual void vfn100();
    virtual void vfn101();
    virtual void vfn102();
    virtual void vfn103();
    virtual void vfn104();
    virtual void vfn105();
    virtual void vfn106();
    virtual void vfn107();
    virtual void vfn108();
    virtual void vfn109();
    virtual void vfn110();
    virtual void vfn111();
    virtual void vfn112();
    virtual void vfn113();
    virtual void vfn114();
    virtual void vfn115();
    virtual void vfn116();
    virtual Unk801C727C vfn117();
};
// An object's model: vtable pointer at 0, and at +0x320 a part with its own vtable
// whose slot 2 resets it.
struct Unk80068758Part {
    virtual void vfn1();
    virtual void vfn2();
};
struct Unk80068758 {
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
    virtual void vfn34();
    virtual void vfn35();
    virtual void vfn36();
    virtual void vfn37();
    virtual void vfn38();
    virtual void vfn39();
    virtual void vfn40();
    virtual void vfn41();
    virtual void vfn42();
    virtual void vfn43();
    virtual void vfn44();
    virtual void vfn45();
    virtual void vfn46();
    virtual void vfn47();
    virtual void vfn48();
    virtual void vfn49();
    virtual void vfn50(int highlight);
    virtual int vfn51();          // made of several models
    char unk4[0x320 - 0x4];
    Unk80068758Part unk320;
};
Unk80068758* fn_80068758(Unk800053D4Inner* object);
inline Unk80068758* GetModel(Unk800053D4Inner* object) { return (Unk80068758*)GetUnk20(object)->vfn19(); }
inline bool IsOffLot(Unk801C727C& tile) {
    return !(tile.fn_801C727C() >= 0 && tile.fn_801C727C() <= ((Unk8037D990F*)lbl_8037D990)->vfn6() &&
             tile.fn_801C7288() >= 0 && tile.fn_801C7288() <= ((Unk8037D990F*)lbl_8037D990)->vfn6());
}

inline bool CanCommit(Unk801FD05CResult* part, bool onLot) {
    if (part) {
        bool ok = false;
        if (part->vfn3() && onLot) {
            ok = true;
        }
        return ok;
    }
    return false;
}
inline void Refund(int kind, int amount) {
    if (lbl_802E6700.unk144 == 0 && !lbl_802E6700.fn_80068ED8()) {
        ((Unk8037D944B*)lbl_8037D944)->vfn26(kind, -amount, 0);
    }
}

// Callback table copied over the engine's defaults (0x30 bytes at 0x802D1ED8).
struct Unk802DBAEC {
    int unk0[10];
};
extern Unk802DBAEC lbl_802D1ED8;
extern Unk802DBAEC lbl_802DBAEC;
void fn_8002E1BC(void* key, int flag);
void fn_8002EA74(int arg, int kind, float x0, float y0, float x1, float y1);
void fn_8002E73C(int key, int arg);
void fn_8002E2A0(int flag, int x0, int y0, int x1, int y1);
void fn_8002E498(void* arg, int kind, float x0, float x1, float y0, float y1);
void fn_8002E5DC(void* arg, int kind, float x0, float y0, float x1, float y1);
void fn_8002E68C(void* arg, int kind, float x0, float y0, float x1, float y1);
extern void (*lbl_80381438)(void*, int);
extern void (*lbl_8038143C)(int, int, int, int, int);
extern void (*lbl_80381440)(void*, int, float, float, float, float);
extern void (*lbl_80381444)(void*, int, float, float, float, float);
extern void (*lbl_80381448)(void*, int, float, float, float, float);
extern void (*lbl_8038144C)(int, int);
extern void (*lbl_80381450)(int, int, float, float, float, float);
extern void (*lbl_80381454)(void*);
extern int (*lbl_80381458)(int);


// Inline pieces of fn_80027780 that fn_8002F1BC repeats.
inline bool EIsValidNode(Unk80026864Node* node) {
    if (node == 0) {
        return false;
    }
    return true;
}
struct Unk8004B740 {
    void fn_8004B740(Unk8002EF48* arg);
};
// Item of the floor tool's draw queue.
struct Unk8002EFACItem {
    char unk0[0x18];
    void* unk18;
    Unk80181824* unk1C;
};
void fn_8002F2E0(void* arg, ERC* rc, int* a, int* b, int* c, int* d);
int fn_8002FF30(int index);
struct Unk8037D990I {
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
    virtual int vfn14(Unk801C6F20* tile);                // floor type on a tile
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn20();
    virtual void vfn21();
    virtual unsigned char* vfn22(Unk801C6F20* tile);     // floor record of a tile
    virtual void vfn23();
    virtual void vfn24();
    virtual void vfn25();
    virtual int vfn26(Unk801C6F20* tile);                // tile flags
};
// Counted array of pointers kept by the global at +0xC0.
struct Unk802E67C0Entry {
    int unk0;
};
struct Unk802E67C0 {
    Unk802E67C0Entry** unk0;
};

struct Unk80234774 {
    int fn_80234774(Unk801C6F20* tile, unsigned short** a, unsigned short** b, int* sideA, int* sideB);
};
struct Unk8023E354 : Unk8023DFA8 {
    int fn_8023E354();           // first wall on the tile
    int fn_8023E3BC(int wall);   // the one after
};
int fn_8023E4A4(int side, int);
void fn_800331A8(Unk801C6F20* tile, int arg, int wall, int side);
struct Unk8037D990G {
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
    virtual Unk8023E354 vfn18(Unk801C6F20* tile);
    virtual void vfn19();
    virtual void vfn20();
    virtual int vfn21(Unk801C6F20* tile);
};
void* fn_80169F1C(unsigned int size, int align);
// A floor type as the catalogue hands it to the tool.
struct Unk8002F000Tool {
    int unk0;
    int unk4;
    int unk8;
    unsigned int unkC;   // texture id
};
struct Unk80235F64 {
    int fn_80235F64(Unk801C6F20* tile);
};
struct Unk8023E420 : Unk8023E354 {
    int fn_8023E420(int side);   // floor type on one half
};
struct Unk8037D990J {
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
    virtual Unk8023E420 vfn18(Unk801C6F20* tile);
};
void fn_80031084(void* table, Unk801C6F20* tile, Unk8023DFA8* info, int* sideA, int* sideB);
int fn_8002FEF4(int index);
int fn_8002FFB8(Unk801C6F20* tile);
void fn_8002EFAC(ERC* rc, struct Unk8002EFACItem* item);
// True when purchases are free (the freeitems setting, or the mode fn_80068ED8 tests).
#define CheatMoney() (lbl_802E6700.unk144 != 0 || lbl_802E6700.fn_80068ED8())

#endif
