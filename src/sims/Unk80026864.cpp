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
void fn_800311B0(char* entry, int flag, Unk80234390* list);
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
void fn_800266EC(Unk800053D4Inner* object, Unk80026864List* out) {
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
                for (group = group->vfn2(); group; group = group->vfn3()) {
                    void* model = GetUnk20(group->Direct())->vfn19();
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
    if (list.head) {
        Unk80026864Node* node = list.tail;
        while (EIsValid(node)) {
            Unk8002FD24* item = (Unk8002FD24*)node->item;
            Unk80026864Node* next = node->prev;
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
        if (unk148.Head() != 0 && unk148.Head() == unk148.Tail()) {
            vfn7((UnkTargetBase*)fn_80080418(unk148.head->item)->vfn111(), 0x1C);
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
                    fn_80027FCC(unkF0->vfn8b());
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

// 0x80028BB0
// Lets go of the object being placed: a moved object goes back (or to the
// nearest free tile, or is destroyed), a bought one is refunded.
// NON_MATCHING: not yet compared.
void Unk80026864::fn_80028BB0(int notify) {
    unk84 = 0;
    if (unkF0 == 0) {
        unk1B0 = 0;
        if (notify) {
            ((UnkTargetBase*)unkC)->vfn7(this, 0x27);
        }
        return;
    }
    if (unk8C) {
        Unk800053D4Inner* object = unkF0->vfn8b();
        if (!fn_80028860()) {
            unkF0->vfn7();
            if (!fn_80028AA4(object)) {
                ((Unk8037D98CB*)lbl_8037D98C)->vfn11(object->vfn111());
                object = 0;
            }
        }
        if (object) {
            fn_8002BE48(object);
            lbl_8037D96C->fn_8006186C(0xD9552AE4);
            fn_80027FCC(object);
        }
    } else {
        Unk800053D4Inner* object = unkF0->vfn8b();
        if (object) {
            int kind = 7;
            if (!object->vfn137()) {
                kind = 6;
            }
            if (lbl_802E6700.unk144 == 0 && !lbl_802E6700.fn_80068ED8()) {
                ((Unk8037D944B*)lbl_8037D944)->vfn26(kind, -((Unk80217FDCInfoB*)fn_80217FDC(object->vfn119())->unk18)->unk24, 0);
            }
        }
        unkF0->vfn6();
        ((Unk800914D0*)((char*)lbl_802E6700.unkBC + 0x2970))->fn_800914D0();
    }
    ((Unk8037D98CB*)lbl_8037D98C)->vfn11(unkF0->Object()->vfn111());
    unkF0 = 0;
    lbl_8037D994->vfn19();
    if (notify) {
        ((UnkTargetBase*)unkC)->vfn7(this, 0x27);
    }
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

// 0x80028F30
// Whether the held object may be put down where it is.
int Unk80026864::fn_80028F30() {
    Unk800053D4Inner* object;
    if (unkF0 == 0 || (object = unkF0->vfn8b()) == 0) {
        return 0;
    }
    if (unk90) {
        return 1;
    }
    bool ok = true;
    if (!(object->vfn88(0x2B) & 8)) {
        ok = false;
    }
    if (ok) {
        if (!object->vfn124()) {
            if (object->vfn98(0)) {
                ok = false;
            }
        } else {
            Unk801FD05CResult* group = fn_801FD05C(GetUnk20(object), 3);
            if (!group->vfn9()) {
                for (group = group->vfn2(); group; group = group->vfn3()) {
                    if (group->Direct()->vfn98(0)) {
                        ok = false;
                        break;
                    }
                }
            }
        }
    }
    return ok;
}

// 0x800290B0
// State 0's handler: what putting the held object back would cost (negated).
int Unk80026864::fn_800290B0() {
    Unk800053D4Inner* object;
    if (unkF0 == 0 || (object = unkF0->vfn8b()) == 0) {
        return 0;
    }
    int value;
    if (unk90) {
        value = ((Unk80217FDCInfoB*)fn_80217FDC(object->vfn119())->unk18)->unk24;
    } else {
        if (object->vfn137() == 4) {
            return 0;
        }
        value = object->vfn131();
    }
    return -value;
}

// 0x8002917C
// The cursor while an object is held (or none is): the directions drop it, the
// confirm button places it, 0xF sells it, 7 cancels, 0xD and 0xE turn it.
// NON_MATCHING: 609 instructions vs 620. The structure and every call are the
// original's; it has not been tuned (register use and the layout of the sell branch
// differ). One variant tried.
void Unk80026864::fn_8002917C() {
    int confirm = IsBuildCameraMode() ? 5 : 6;
    if (unk84 == 1) {
        UnkTargetBase* child = unkC8;
        bool active = IsActive(child);
        if (!active) {
            if (child) {
                ((Unk8004F7EC*)child)->fn_8004F7EC();
            }
            unk84 = active;
        }
    }
    EController* controller = lbl_8037C11C->fn_8015E5FC(lbl_8037C11C->fn_8015E614(unk38));
    int up = controller->fn_8015E204(0x33);
    int down = controller->fn_8015E204(0x34);
    int left = controller->fn_8015E204(0x35);
    int right = controller->fn_8015E204(0x36);
    if (!(unk84 == 1 && IsActive(unkC8)) && (up || down || left || right)) {
        fn_80028BB0(1);
        return;
    }
    Unk801FD05CResult* part = unkF0;
    if (part == 0) {
        if (controller->fn_8015E0F8(7)) {
            ((UnkTargetBase*)unkC)->vfn7(this, 0x27);
            unk84 = 0;
            return;
        }
        if (unk84 == 1 && IsActive(unkC8)) {
            unkC8->vfn2();
            return;
        }
        fn_80029BF8();
        fn_80027D24();
        return;
    }
    fn_80029BF8();
    fn_8002C158();
    if (controller->fn_8015E0F8(confirm)) {
        bool onLot = false;
        Unk800053D4Inner* object = unkF0->vfn8b();
        Unk801C727C tile = ((Unk800053D4InnerB*)object)->vfn117();
        if (tile.fn_801C727C() >= 0 && tile.fn_801C727C() <= ((Unk8037D990F*)lbl_8037D990)->vfn6() &&
            tile.fn_801C7288() >= 0) {
            onLot = tile.fn_801C7288() <= ((Unk8037D990F*)lbl_8037D990)->vfn6();
        }
        if (CanCommit(unkF0, onLot)) {
            Unk800053D4Inner* left;
            if (unkF0->vfn4() && (left = unkF0->vfn8b()) == 0) {
                if (object) {
                    fn_800686D4(object);
                    fn_80027FCC(object);
                }
                ((Unk8037D98CB*)lbl_8037D98C)->vfn11(unkF0->Object()->vfn111());
                unk8C = 0;
                unkF0 = 0;
                unk90 = 0;
                lbl_8037D96C->fn_8006186C(0xD9552AE4);
                ((Unk800914D0*)((char*)lbl_802E6700.unkBC + 0x2970))->fn_800914D0();
            } else {
                unkF0->vfn6();
                lbl_8037D96C->fn_8006186C(0x3804219F);
                ((Unk8037D98CB*)lbl_8037D98C)->vfn11(unkF0->Object()->vfn111());
                unkF0 = 0;
            }
        } else {
            lbl_8037D96C->fn_8006186C(0x3804219F);
        }
        return;
    }
    if (controller->fn_8015E0F8(0xF)) {
        bool ok = true;
        Unk800053D4Inner* object = unkF0->vfn8b();
        if (object == 0) {
            ok = false;
        }
        if (ok) {
            if (!(object->vfn88(0x2B) & 8)) {
                ok = false;
            }
        }
        if (ok) {
            if (!object->vfn124()) {
                if (object->vfn98(0)) {
                    ok = false;
                }
            } else {
                Unk801FD05CResult* group = GetPart(object, 3);
                if (!group->vfn9()) {
                    for (group = group->vfn2(); group; group = group->vfn3()) {
                        if (group->Direct()->vfn98(0)) {
                            ok = false;
                            break;
                        }
                    }
                }
            }
        }
        if (!ok) {
            lbl_8037D96C->fn_8006186C(0x3804219F);
            return;
        }
        if (unk90) {
            unk90 = 0;
            int kind = 7;
            if (!object->vfn137()) {
                kind = 6;
            }
            Refund(kind, ((Unk80217FDCInfoB*)fn_80217FDC(object->vfn119())->unk18)->unk24);
        } else if (object->vfn137() != 4) {
            int value = object->vfn131();
            if (object->vfn137()) {
                value = (int)((float)value * 0.8f + 0.5f);
                Refund(7, value);
            } else {
                Refund(6, value);
            }
        }
        unkF0->vfn6();
        ((Unk8037D98CB*)lbl_8037D98C)->vfn11(unkF0->Object()->vfn111());
        unkF0 = 0;
        lbl_8037D994->vfn19();
        ((Unk8037D988B*)lbl_8037D988)->vfn8();
        lbl_8037D96C->fn_8006186C(0x994E8974);
        ((Unk800914D0*)((char*)lbl_802E6700.unkBC + 0x2970))->fn_800914D0();
        return;
    }
    if (controller->fn_8015E0F8(7)) {
        fn_80028BB0(0);
        ((Unk800914D0*)((char*)lbl_802E6700.unkBC + 0x2970))->fn_800914D0();
        return;
    }
    if (controller->fn_8015E0F8(0xD)) {
        fn_8002BA04(1);
        return;
    }
    if (controller->fn_8015E0F8(0xE)) {
        fn_8002BA04(0);
    }
}

// 0x80029B2C
void Unk80026864::vfn2() {
    if (unk38 == 1 && !lbl_802E6700.fn_800655C4()) {
        return;
    }
    if (lbl_802E30B8[0]->fn_80064F8C(unk38) && (unk18 & 2) &&
        lbl_802E6700.unk114->unk104 == 0) {
        switch (mode) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            fn_800285D4();
            break;
        case 9:
            if (unk38 == lbl_802E6700.unk138) {
                fn_800286CC();
            }
            break;
        }
    }
}

// 0x80029BF8
// Moves the cursor with the stick, relative to the camera, and keeps it on the lot.
// NON_MATCHING: 297 instructions vs 300. Calls and arithmetic are the original's; the
// stack layout of the vector temporaries and the two range tests differ. One variant.
void Unk80026864::fn_80029BF8() {
    unk94 = unkA0;
    Unk80026864Cam* camera = (Unk80026864Cam*)unkBC;
    if (camera->unk328 == 4) {
        return;
    }
    EController* controller = lbl_8037C11C->fn_8015E5FC(lbl_8037C11C->fn_8015E614(unk38));
    if (unk84 == 4 && (unk88 & 2) && controller->fn_8015DF98(0x11)) {
        return;
    }
    float stickX = controller->fn_8015DEE4(0, 0);
    float stickY = controller->fn_8015DEE4(0, 1);
    float moveX = SignedSquare(stickX);
    float moveY = SignedSquare(stickY);
    EVec3 move;
    move.x = moveX * camera->unk390 * lbl_8037BFC8;
    move.z = 0.0f;
    move.y = moveY * camera->unk390 * lbl_8037BFC8;
    float limit = (float)((Unk8037D990F*)lbl_8037D990)->vfn6() - 1.0f;
    lbl_8037B4A0 += lbl_8037BFC8;
    if (move.x != 0.0f || move.y != 0.0f) {
        EVec3 eye(camera->unk378);
        EVec3 target(camera->unk398);
        EVec3 direction = target - eye;
        direction.Normalize();
        EVec3 flat(direction);
        float angle = fn_8010DD60(flat.x, flat.y);
        EMat4 rotation;
        rotation.fn_801B2AFC();
        rotation.fn_801B2CC8(-angle);
        move = move * rotation;
        unkA0 += move;
        bool inX = unkA0.x >= 1.0f && unkA0.x <= limit;
        bool inY = unkA0.y >= 1.0f && unkA0.y <= limit;
        if (!inX) {
            move.x = 0.0f;
        }
        if (!inY) {
            move.y = 0.0f;
        }
        float x;
        if (unkA0.x < 1.0f) {
            x = 1.0f;
        } else if (unkA0.x > limit) {
            x = limit;
        } else {
            x = unkA0.x;
        }
        unkA0.x = x;
        float y;
        if (unkA0.y < 1.0f) {
            y = 1.0f;
        } else if (unkA0.y > limit) {
            y = limit;
        } else {
            y = unkA0.y;
        }
        unkA0.y = y;
        ((UnkTargetBase*)unkC)->vfn7(this, unk38 == 0 ? 0x15 : 0x16);
        camera->fn_80007528(unk38, move);
    }
    int tileX;
    int tileY;
    fn_8002BB64(&tileX, &tileY);
    if (tileY >= 0 && tileX >= 0) {
        Unk801C6F44 tile(tileY, tileX, 1);
        fn_800328F4(&tile);
    }
}

// 0x8002A0A8
void Unk80026864::fn_8002A0A8() {
    unk148.fn_801B4760();
    ((Unk8007F630*)((Unk8004AD08*)lbl_802E67B0.unk0)->unk4)->fn_8007F630(unk38, &unk148);
}

// 0x8002A0F4
// Starts placing a newly bought object.
void Unk80026864::fn_8002A0F4(void* definition) {
    unk90 = 1;
    unk1B0 = 0;
    unk8C = 0;
    int arg = lbl_8037D988->vfn14(0x437);
    int id = lbl_8037D98C->Create(fn_80217FDC(definition), arg, 1);
    unkF0 = GetPart(lbl_8037D98C->vfn18(id), 4);
    unk84 = 0;
}

// 0x8002A1BC
void Unk80026864::fn_8002A1BC(ERC* rc) {
    if (unk84 == 1 && IsActive(unkC8)) {
        unkC8->vfn3(rc);
    }
}

// 0x8002A234
// Draws the tile cursor under the pointer (or, while dragging, at the grabbed spot).
// NON_MATCHING: 137 instructions vs 144. Draft; the early-out tests and the discarded
// camera-mode test differ as in fn_800286CC. One variant tried.
void Unk80026864::fn_8002A234(ERC* rc) {
    if (unk38 == 1 && !lbl_802E6700.fn_800655C4()) {
        return;
    }
    if (!(unk18 & 2)) {
        return;
    }
    lbl_8037C11C->fn_8015E5FC(lbl_8037C11C->fn_8015E614(unk38));
    IsBuildCameraMode();
    if (unk84 == 1 && IsActive(unkC8)) {
        return;
    }
    if (((Unk80026864Cam*)unkBC)->unk328 == 4) {
        return;
    }
    ((Unk80181824*)unkFC)->fn_80181824(rc);
    float size = ((Unk80026864Cam*)unkBC)->fn_8000562C() * (2.5f - 1.0f) + 1.0f;
    EMat4* matrix = ((Unk80173D58Alloc*)rc)->fn_80173D58(0x40, 0x20);
    matrix->fn_801B2AFC();
    EVec3 scale(1.0f, 1.0f, size);
    matrix->fn_801B2BA4(&scale);
    if (unk84 == 2) {
        EVec2 at = fn_8002BD98();
        matrix->m[3][0] = at.x;
        matrix->m[3][2] = 0.1f;
        matrix->m[3][1] = at.y;
        rc->vfn28(matrix, 1);
        rc->vfn22(unkC4);
    } else if (unk84 != 4 && !(unk84 == 3 || unk84 == 5)) {
        matrix->m[3][0] = unkA0.x;
        matrix->m[3][2] = 0.0f;
        matrix->m[3][1] = unkA0.y;
        rc->vfn28(matrix, 1);
        rc->vfn22(unkC4);
    }
}

// 0x8002A474
// Draws every piece of a model with its own texture.
// NON_MATCHING: 51 instructions vs 53. The original reaches the group array through
// the address of the {pointer, count} pair (inline accessors). One variant tried.
void fn_8002A474(ERC* rc, Unk8033FF34Resource* model) {
    for (int i = 0; i < model->unk24; i++) {
        EModelGroup* group = &model->unk20[i];
        for (int j = 0; j < group->unk4; j++) {
            Unk80184C00* piece = &group->unk0[j];
            piece->unk4->fn_80181824(rc);
            rc->vfn54(0, 1, 0, 0);
            piece->fn_80184C00(rc);
        }
    }
}

// Helpers shared by the two drawing functions below.
inline EMat4* NewMatrix(ERC* rc) {
    EMat4* matrix = ((Unk80173D58Alloc*)rc)->fn_80173D58(0x40, 0x20);
    matrix->fn_801B2AFC();
    return matrix;
}
inline void DrawModelAt(ERC* rc, void* model, const EVec3& position, void* lights) {
    EMat4* matrix = NewMatrix(rc);
    matrix->fn_801B2B54(&position);
    rc->vfn28(matrix, 1);
    rc->vfn44(lights);
    ((Unk8033FF34Resource*)model)->fn_8017CC58(rc);
}
int fn_8003401C(Unk80026864* self, EVec2* from, EVec2* to, float* scale);
void fn_80034E10();
void fn_800351E4();
void fn_80034968();
void fn_8002F794(Unk80026864* self, ERC* rc);
void fn_8002F268(Unk80026864* self, ERC* rc);
void fn_8002F2A4(Unk80026864* self, ERC* rc);
void fn_80035B4C(Unk80026864* self, ERC* rc);
void fn_80035724(Unk80026864* self, ERC* rc);
void fn_800359C0(Unk80026864* self, ERC* rc);
void fn_800329D8(Unk80026864* self, ERC* rc);
void fn_80031B1C(Unk80026864* self, ERC* rc);

// 0x8002A548
// Draws the screen: the build-mode overlays for the current state, the pointer
// model with its shadow, the hand or the tool models, and the arrow over the object
// under the cursor.
// NON_MATCHING: skeleton only (the original is 755 instructions). The early-out
// tests and the order of the major calls follow the original; the many per-state
// matrix set-ups and model draws are reduced to the pointer and tool models, and the
// arguments of the overlay helpers are assumed. One variant tried.
void Unk80026864::fn_8002A548(ERC* rc) {
    bool build = IsBuildCameraMode();
    if (unk38 == 1 && !lbl_802E6700.fn_800655C4()) {
        return;
    }
    if (((Unk80026864Cam*)unkBC)->unk328 == 3) {
        return;
    }
    EController* controller = lbl_8037C11C->fn_8015E5FC(lbl_8037C11C->fn_8015E614(unk38));
    if (!(unk18 & 2)) {
        return;
    }
    fn_8002D1CC();
    if (unk84 == 2) {
        if (controller->fn_8015DF98(0x11)) {
            fn_8002F794(this, rc);
        }
        if (controller->fn_8015DF98(0x12)) {
            fn_8002F268(this, rc);
        }
        if (controller->fn_8015DF98(0x13)) {
            fn_8002F2A4(this, rc);
        }
    }
    if (unk84 == 3 || unk84 == 5) {
        EVec2 centre;
        fn_8002BC5C(&centre);
        EVec2 corner = fn_8002BD98();
        fn_8002B114(rc);
        if (controller->fn_8015DF98(0x11)) {
            fn_80035B4C(this, rc);
        }
        fn_80035724(this, rc);
        fn_800359C0(this, rc);
    }
    if (unk84 == 4) {
        EVec2 centre;
        fn_8002BC5C(&centre);
        EVec2 corner = fn_8002BD98();
        fn_8002B114(rc);
        if (controller->fn_8015DF98(0x11)) {
            fn_800329D8(this, rc);
        }
        fn_80031B1C(this, rc);
    }
    if (unk84 == 1 && IsActive(unkC8)) {
        return;
    }
    void* lights = &lbl_802E5B40[unk38];
    if (unkF0 == 0) {
        // The pointer and its shadow at the cursor.
        EVec2 corner = fn_8002BD98();
        EVec3 position(unkA0.x, unkA0.y, 0.0f);
        DrawModelAt(rc, unk128, position, &lbl_802E5D00);
        rc->vfn44(lights);
        ((Unk8033FF34Resource*)unk130)->fn_8017CC58(rc);
        if (unk84 == 4) {
            DrawModelAt(rc, unk11C, position, &lbl_802E5D00);
            rc->vfn44(lights);
            ((Unk8033FF34Resource*)unk120)->fn_8017CC58(rc);
            fn_8002A474(rc, (Unk8033FF34Resource*)unk124);
        }
        if (build && Unk802A2AC0::mode != 0 && Unk802A2AC0::mode != 9) {
            Unk800053D4Inner* under = fn_8002C7B4(0);
            if (under) {
                // The arrow above the object under the cursor, turned to face the camera.
                DrawModelAt(rc, unk134, position, &lbl_802E5D00);
                rc->vfn44(lights);
                ((Unk8033FF34Resource*)unk13C)->fn_8017CC58(rc);
                rc->vfn44(lights);
                fn_8002A474(rc, (Unk8033FF34Resource*)unk138);
            }
        }
    } else {
        // The hand holding an object.
        EVec3 position(unkA0.x, unkA0.y, 0.0f);
        DrawModelAt(rc, unk108, position, &lbl_802E5D00);
        rc->vfn44(lights);
        ((Unk8033FF34Resource*)unk10C)->fn_8017CC58(rc);
        DrawModelAt(rc, unk114, position, &lbl_802E5D00);
        rc->vfn44(lights);
        fn_8002A474(rc, (Unk8033FF34Resource*)unk118);
        fn_8002A474(rc, (Unk8033FF34Resource*)unk110);
    }
}

// 0x8002B114
// Draws the wall and floor tools' cursor: the pulsing tile marker, the tool model,
// and while a wall is being dragged the post models at both ends.
// NON_MATCHING: skeleton only (the original is 559 instructions). The pulse and the
// choice of position follow the original; the rest keeps the order of the draws but
// not their matrices. One variant tried.
void Unk80026864::fn_8002B114(ERC* rc) {
    EController* controller = lbl_8037C11C->fn_8015E5FC(lbl_8037C11C->fn_8015E614(unk38));
    EVec2 from(unkAC, unkB0);
    EMat4* toolMatrix = ((Unk80173D58Alloc*)rc)->fn_80173D58(0x40, 0x20);
    float sizes[2];
    sizes[0] = 1.0f;
    sizes[1] = 1.1f;
    float scale = 1.0f;
    if (unk88 & 1) {
        unk1BC += lbl_8037BFC8;
        if (unk1BC > 0.4f) {
            int swap = unk1B4;
            unk1B4 = unk1B8;
            unk1B8 = swap;
            unk1BC = 1.0f;
        }
    }
    float t = unk1BC / 0.4f;
    float eased = t * -2.0f * t * t + t * 3.0f * t;
    float size = (sizes[unk1B4] + (sizes[unk1B8] - sizes[unk1B4]) * eased) * 1.5f;
    bool dragging = false;
    if (unk84 == 3 && (unk88 & 2) && controller->fn_8015DF98(0x11)) {
        dragging = true;
    }
    EVec2 at;
    if (dragging) {
        fn_8002BC5C(&at);
    } else if (unk84 == 4 && controller->fn_8015DF98(0x11)) {
        const EVec2& origin = ((Unk8004AD08B*)lbl_802E67B0.unk0)->unk34;
        scale = 1.0f;
        at.x = unkAC + origin.x;
        at.y = unkB0 - origin.y;
    } else {
        fn_8003401C(this, &from, &at, &scale);
    }
    EMat4* matrix = NewMatrix(rc);
    matrix->m[3][0] = at.x;
    matrix->m[3][1] = at.y;
    matrix->m[3][2] = 0.1f;
    ((Unk80181824*)unkFC)->fn_80181824(rc);
    matrix->fn_801B32D4(scale);
    rc->vfn28(matrix, 1);
    rc->vfn22(unkC4);
    ((Unk8033FF34Resource*)unk130)->fn_8017CC58(rc);
    EMat4* pulse = NewMatrix(rc);
    *pulse = *matrix;
    pulse->fn_801B28F0(EVec3(size, size, 1.0f));
    rc->vfn28(pulse, 1);
    rc->vfn44(&lbl_802E5D00);
    rc->vfn44(&lbl_802E5B40[unk38]);
    ((Unk8033FF34Resource*)unk12C)->fn_8017CC58(rc);
    toolMatrix->fn_801B2AFC();
    if (!dragging) {
        const EVec2& origin = ((Unk8004AD08B*)lbl_802E67B0.unk0)->unk34;
        EVec3 position(unkAC + origin.x, unkB0 - origin.y, 0.1f);
        toolMatrix->fn_801B2B54(&position);
        rc->vfn28(toolMatrix, 1);
        rc->vfn44(&lbl_802E5B40[unk38]);
        ((Unk8033FF34Resource*)unk128)->fn_8017CC58(rc);
    }
}

// 0x8002B9D0
float Unk80026864::fn_8002B9D0() {
    return ((Unk80026864Cam*)unkBC)->fn_8000562C() * (lbl_8037B4A8 - lbl_8037B4A4) + lbl_8037B4A4;
}

// Keeps a direction (0, 2, 4, 6) in range.
inline int WrapDirection(int direction) {
    int result;
    if (direction < 0) {
        result = 6;
    } else {
        result = 0;
        if (direction <= 6) {
            result = direction;
        }
    }
    return result;
}

// 0x8002BA04
// Turns the held object a quarter turn.
// NON_MATCHING: 87 instructions vs 88; the wrap of the direction is laid out
// differently (the original tests the sign straight after each add). Four variants.
void Unk80026864::fn_8002BA04(int forward) {
    Unk801FD05CResult* part = unkF0;
    Unk800053D4Inner* object = part->vfn8b();
    int direction = object->vfn88(1);
    if (forward) {
        direction += 2;
        direction = WrapDirection(direction);
    } else {
        direction -= 2;
        direction = WrapDirection(direction);
    }
    part->vfn10(direction);
    lbl_8037D96C->fn_8006186C(0x0C21C2A9);
    ETilePair tile;
    part->Object()->vfn114(&tile);
    if (part->Object()->vfn49(&tile, 1, 0, 0)) {
        part->Object()->vfn50(&tile, 1, 0, 0);
    }
    fn_800686D4(object);
}

// 0x8002BB64
// The tile under the cursor, rounded to the nearest.
void Unk80026864::fn_8002BB64(int* tileX, int* tileY) {
    Unk8004AD08B* view = (Unk8004AD08B*)lbl_802E67B0.unk0;
    EVec2 offset(unkA0.x - view->unk34.x, unkA0.y - view->unk34.y);
    *tileX = (int)offset.x;
    *tileY = (int)offset.y;
    if (offset.x - (float)(int)offset.x >= 0.5f) {
        (*tileX)++;
    }
    if (offset.y - (float)(int)offset.y >= 0.5f) {
        (*tileY)++;
    }
}

// 0x8002BC5C
// World position of the centre of the tile under the cursor.
void Unk80026864::fn_8002BC5C(EVec2* out) {
    Unk8004AD08B* view = (Unk8004AD08B*)lbl_802E67B0.unk0;
    const EVec2& origin = view->unk34;
    EVec2 offset(unkA0.x - origin.x, unkA0.y - origin.y);
    int tileX = (int)offset.x;
    int tileY = (int)offset.y;
    if (offset.x - (float)tileX >= 0.5f) {
        tileX++;
    }
    if (offset.y - (float)tileY >= 0.5f) {
        tileY++;
    }
    EVec2 centre((float)tileX - 0.5f, (float)tileY + 0.5f);
    *out = centre + origin;
}

// 0x8002BD98
// World position of the corner of the tile under the cursor.
EVec2 Unk80026864::fn_8002BD98() {
    int tileX;
    int tileY;
    fn_8002BB64(&tileX, &tileY);
    EVec2 tile((float)tileX, (float)tileY);
    Unk8004AD08B* view = (Unk8004AD08B*)lbl_802E67B0.unk0;
    return tile + view->unk34;
}

// 0x8002BE48
// Clears the highlight of an object's model and of everything standing on it.
// NON_MATCHING: 178 instructions vs 196. Draft: calls and loops are the original's;
// the original duplicates the walk over stacked objects per branch. One variant.
void Unk80026864::fn_8002BE48(Unk800053D4Inner* object) {
    Unk80068758* model = fn_80068758(object);
    if (model) {
        if (!model->vfn51()) {
            model->unk320.vfn2();
            Unk801C727C tile = ((Unk800053D4InnerB*)object)->vfn117();
            model->vfn50(0);
            if (!object->vfn124()) {
                for (Unk800053D4Inner* above = object->vfn98(0); above; above = above->vfn98(0)) {
                    Unk80068758* part = GetModel(above);
                    if (part) {
                        part->unk320.vfn2();
                        part->vfn50(0);
                    }
                }
            } else {
                Unk801FD05CResult* group = GetPart(object, 3);
                if (!group->vfn9()) {
                    for (group = group->vfn2(); group; group = group->vfn3()) {
                        for (Unk800053D4Inner* above = group->Direct()->vfn98(0); above; above = above->vfn98(0)) {
                            Unk80068758* part = GetModel(above);
                            if (part) {
                            part->unk320.vfn2();
                        part->vfn50(0);
                            }
                        }
                    }
                }
            }
        } else {
            Unk80026864List models;
            fn_800266EC(object, &models);
            for (Unk80026864Node* node = models.head; node; node = node->next) {
                Unk80068758* part = (Unk80068758*)node->item;
                part->unk320.vfn2();
                part->vfn50(0);
            }
        }
    }
}

// 0x8002C158
// Moves the held object to the middle of the tile under the cursor if it fits.
// NON_MATCHING: 131 instructions vs 134. The original stores the sub-tile pair and
// reloads each half from the stack before centring it; here the shift and the mask
// are combined in registers. One variant tried.
void Unk80026864::fn_8002C158() {
    Unk801FD05CResult* part = unkF0;
    ETilePair old;
    part->Object()->vfn114(&old);
    if (part->Object()->vfn64()) {
        part->Object()->vfn48();
    }
    part->Object()->vfn50(&old, 1, 0, 0);
    if (part->Object()->vfn64()) {
        part->Object()->vfn48();
    }
    int tileX;
    int tileY;
    ETilePair tile;
    fn_8002BB64(&tileX, &tileY);
    SetSubTile(tile, tileX, tileY);
    CentreSubTile(tile);
    if (!((Unk8037D990E*)lbl_8037D990)->vfn10(&tile)) {
        if (part->Object()->vfn49(&tile, 1, 0, 0)) {
            part->Object()->vfn50(&tile, 1, 0, 0);
        }
    }
    Unk800053D4Inner* object = part->vfn8b();
    if (object) {
        fn_8002C370(object);
    }
}

// 0x8002C370
// Resets an object's model and marks it when the object is off the lot.
// NON_MATCHING: 265 instructions vs 273. Draft, as fn_8002BE48. One variant.
void Unk80026864::fn_8002C370(Unk800053D4Inner* object) {
    Unk80068758* model = fn_80068758(object);
    if (model) {
        if (!model->vfn51()) {
            model->unk320.vfn2();
            Unk801C727C tile = ((Unk800053D4InnerB*)object)->vfn117();
            if (IsOffLot(tile)) {
                model->vfn50(1);
            } else {
                model->vfn50(0);
            }
            if (!object->vfn124()) {
                for (Unk800053D4Inner* above = object->vfn98(0); above; above = above->vfn98(0)) {
                    Unk80068758* part = GetModel(above);
                    if (part) {
                        part->unk320.vfn2();
                    }
                }
            } else {
                Unk801FD05CResult* group = GetPart(object, 3);
                if (!group->vfn9()) {
                    for (group = group->vfn2(); group; group = group->vfn3()) {
                        for (Unk800053D4Inner* above = group->Direct()->vfn98(0); above; above = above->vfn98(0)) {
                            Unk80068758* part = GetModel(above);
                            if (part) {
                            part->unk320.vfn2();
                            }
                        }
                    }
                }
            }
        } else {
            Unk80026864List models;
            fn_800266EC(object, &models);
            for (Unk80026864Node* node = models.head; node; node = node->next) {
                Unk80068758* part = (Unk80068758*)node->item;
                part->unk320.vfn2();
                Unk801C727C tile = ((Unk800053D4InnerB*)object)->vfn117();
                if (IsOffLot(tile)) {
                    part->vfn50(1);
                } else {
                    part->vfn50(0);
                }
            }
        }
    }
}

// 0x8002C7B4
// The object on the tile under the cursor that matches `kind` (0 any, 1 without
// either wall flag, 2 and 3 with one of them).
// NON_MATCHING: 100 instructions vs 99. The switch and the loop agree; the original
// does not keep the iterator's address in a register, and loads both tile indices
// before shifting them. Two variants tried.
Unk800053D4Inner* Unk80026864::fn_8002C7B4(int kind) {
    int tileX;
    int tileY;
    fn_8002BB64(&tileX, &tileY);
    ETilePair subTile;
    SetSubTile(subTile, tileX, tileY);
    Unk801C6F20 tile(subTile, 1);
    if (((Unk8037D990D*)lbl_8037D990)->vfn8(&tile)) {
        return 0;
    }
    Unk800053D4Inner* found = 0;
    Unk801C6F20 copy(tile);
    Unk801FCE7C it(copy, 0);
    while (it.unk4) {
        Unk800053D4Inner* object = it.unk4;
        int flags = object->vfn88(0x28);
        switch (kind) {
        case 1:
            if (!(flags & 0xC000)) {
                found = object;
            }
            break;
        case 0:
            found = object;
            break;
        case 3:
            if (flags & 0x4000) {
                found = object;
            }
            break;
        case 2:
            if (flags & 0x8000) {
                found = object;
            }
            break;
        }
        if (found) {
            break;
        }
        it.fn_801FCF04();
    }
    return found;
}

// 0x8002C940
// Releases the overlay's shared textures.
// NON_MATCHING: 3 instructions at the entry are in a different order (the store that
// clears lbl_8037B4BC and the first load). One variant tried.
void Unk80026864::fn_8002C940() {
    lbl_8037B4BC = 0;
    if (lbl_8037B4C0) {
        if (lbl_8037C198->vfn19(lbl_8037B4C0)) {
            lbl_8037C198->vfn8();
        }
        lbl_8037C198->vfn18(lbl_8037B4C0);
        lbl_8037B4C0 = 0;
    }
    if (lbl_8037B4AC) {
        fn_801767FC(lbl_8037B4AC);
        lbl_8037B4AC = 0;
    }
    if (lbl_8037B4B0) {
        fn_801767FC(lbl_8037B4B0);
        lbl_8037B4B0 = 0;
    }
    if (lbl_8037B4B4) {
        fn_801767FC(lbl_8037B4B4);
        lbl_8037B4B4 = 0;
    }
    if (lbl_8037B4B8) {
        fn_801767FC(lbl_8037B4B8);
        lbl_8037B4B8 = 0;
    }
}

struct Unk8002CA3CRC {
    char unk0[0x44];
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
    virtual void vfn13(Unk80173D58Vertex* vertices, int count);   // line list
};

// 0x8002CA3C
// Loads the overlay's four textures and records the lot's tile grid (one line per
// row and per column) as a renderer object, once.
// NON_MATCHING: condensed draft. The texture loads and the renderer calls are the
// original's; the grid's vertices are generated by plain loops here, where the
// original also clips the grid to the editable part of the lot. One variant tried.
void Unk80026864::fn_8002CA3C() {
    if (lbl_8037B4BC) {
        return;
    }
    lbl_8037B4BC = 1;
    if (lbl_8037B4AC) {
        fn_801767FC(lbl_8037B4AC);
        lbl_8037B4AC = 0;
    }
    if (lbl_8037B4B0) {
        fn_801767FC(lbl_8037B4B0);
        lbl_8037B4B0 = 0;
    }
    if (lbl_8037B4B4) {
        fn_801767FC(lbl_8037B4B4);
        lbl_8037B4B4 = 0;
    }
    if (lbl_8037B4B8) {
        fn_801767FC(lbl_8037B4B8);
        lbl_8037B4B8 = 0;
    }
    lbl_8037B4AC = lbl_80340AB8.fn_80177628(0x899BA3EB, 0, 0);
    lbl_8037B4B0 = (Unk80181824*)lbl_80340AB8.fn_80177628(0x3B494D6C, 0, 0);
    lbl_8037B4B4 = lbl_80340AB8.fn_80177628(0xEA1905EB, 0, 0);
    lbl_8037B4B8 = lbl_80340AB8.fn_80177628(0x84853612, 0, 0);
    ERC* builder = lbl_8037C198->vfn13(1);
    EVec2 origin;
    Unk8004AD08B* view = (Unk8004AD08B*)lbl_802E67B0.unk0;
    if (view) {
        origin = view->unk34;
    } else {
        origin = EVec2(0.0f, 0.0f);
    }
    int size = ((Unk8037D990F*)lbl_8037D990)->vfn6();
    int lines = (unsigned char)(size - 1);
    for (int pass = 0; pass < 2; pass++) {
        Unk80173D58Vertex* vertices = (Unk80173D58Vertex*)((Unk80173D58Alloc*)builder)->fn_80173D58(lines * 0xA0, 0x20);
        for (int i = 0; i < lines; i++) {
            Unk80173D58Vertex* v = &vertices[i * 2];
            v[0].unk30[0] = 0;
            v[0].unk30[1] = 0;
            v[0].unk30[2] = 0;
            v[0].unk30[3] = 0x80;
            v[1] = v[0];
            float along = (float)i;
            if (pass == 0) {
                v[0].unk0[0] = origin.x;
                v[0].unk0[1] = origin.y + along;
                v[1].unk0[0] = origin.x + (float)size;
                v[1].unk0[1] = origin.y + along;
            } else {
                v[0].unk0[0] = origin.x + along;
                v[0].unk0[1] = origin.y;
                v[1].unk0[0] = origin.x + along;
                v[1].unk0[1] = origin.y + (float)size;
            }
            v[0].unk0[2] = 0.02f;
            v[0].unk0[3] = 1.0f;
            v[1].unk0[2] = 0.02f;
            v[1].unk0[3] = 1.0f;
        }
        ((Unk8002CA3CRC*)builder)->vfn13(vertices, lines * 2);
    }
    lbl_8037B4C0 = lbl_8037C198->vfn14(builder);
}

// 0x8002D1CC
void Unk80026864::fn_8002D1CC() {
}

// 0x8002D1D0
void Unk80026864::fn_8002D1D0() {
    EVec3 position(*fn_8002D2C8());
    Unk800053D4Owner* owner = lbl_802E6700.unk9C[unk38];
    if (owner) {
        void* definition = owner->unk0->vfn111();
        ((Unk800B38CC*)lbl_802E6700.fn_80068FE0())->fn_800B38CC(unk38, definition, &position);
    }
}

// 0x8002D270
int Unk80026864::fn_8002D270(int a, int b) {
    if (unk84 == 1) {
        return ((Unk8004FC0C*)unkC8)->fn_8004FC0C(a, b);
    }
    return b;
}

// 0x8002D2A8
void Unk80026864::fn_8002D2A8(EVec3* out) {
    *out = unkA0;
}

// 0x8002D2C8
EVec3* Unk80026864::fn_8002D2C8() {
    return &unkA0;
}

// 0x8002D2D0
void Unk80026864::fn_8002D2D0() {
}

// A flat, upward-facing vertex of the overlay quads.
inline void SetFlatVertex(Unk80173D58Vertex* vertex, float x, float y, float u, float v) {
    vertex->unk10[2] = 0x7F;
    vertex->unk30[0] = 0x80;
    vertex->unk30[1] = 0x80;
    vertex->unk30[2] = 0x80;
    vertex->unk30[3] = 0x80;
    vertex->unk10[0] = 0;
    vertex->unk10[1] = 0;
    vertex->unk1C = 0;
    EVec2 uv(u, v);
    vertex->unk20[0] = uv.x;
    vertex->unk20[1] = uv.y;
    vertex->unk0[0] = x;
    vertex->unk0[1] = y;
    vertex->unk0[2] = 0.05f;
    vertex->unk0[3] = 1.0f;
}
struct Unk8002D2D4RC {
    char unk0[0x44];
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3(Unk80173D58Vertex* vertices, int count);
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
};
struct Unk801C727CEntry {
    int fn_801C727C();
    int fn_801C7288();
    char unk0[3];
};

// 0x8002D2D4
// Draws a textured square over every tile filed under the item's key.
// NON_MATCHING: condensed draft, 189 instructions vs 234. The original builds the
// four vertices in the open, copying the first into the others; here a helper sets
// each. One variant tried.
void fn_8002D2D4(ERC* rc, Unk8002D67CItem* item) {
    unsigned short key = item->unk6;
    Unk80234390* list = FindList((void*)key);
    if (list && key) {
        char* it = list->unk4;
        if (it != list->unk8) {
            item->unk28->fn_80181824(rc);
            const EVec2& origin = ((Unk8004AD08B*)lbl_802E67B0.unk0)->unk34;
            for (; it != list->unk8; it += 3) {
                float tileY = (float)((Unk801C727CEntry*)it)->fn_801C7288();
                float tileX = (float)((Unk801C727CEntry*)it)->fn_801C727C();
                float x1 = tileY + 0.5f + origin.x;
                float x0 = tileY - 0.5f + origin.x;
                float y0 = tileX - 0.5f + origin.y;
                float y1 = tileX + 0.5f + origin.y;
                Unk80173D58Vertex vertices[4];
                SetFlatVertex(&vertices[0], x1, y0, 1.0f, 1.0f);
                SetFlatVertex(&vertices[1], x0, y0, 0.0f, 1.0f);
                SetFlatVertex(&vertices[2], x1, y1, 1.0f, 0.0f);
                SetFlatVertex(&vertices[3], x0, y1, 0.0f, 0.0f);
                ((Unk8002D2D4RC*)rc)->vfn29();
                ((Unk8002D2D4RC*)rc)->vfn3(vertices, 4);
            }
        }
    }
}

// 0x8002D67C
// Draws one quad over the item's rectangle of tiles, the texture repeating per tile.
// NON_MATCHING: condensed draft (194 instructions vs 256), as fn_8002D2D4.
void fn_8002D67C(ERC* rc, Unk8002D67CItem* item) {
    int ax = (int)item->unk8;
    int ay = (int)item->unkC;
    int bx = (int)item->unk10;
    int by = (int)item->unk14;
    const EVec2& origin = ((Unk8004AD08B*)lbl_802E67B0.unk0)->unk34;
    float x0 = (float)(ax > bx ? bx : ax) - 0.5f;
    float x1 = (float)(ax < bx ? bx : ax) + 0.5f;
    float y0 = (float)(ay > by ? by : ay) - 0.5f;
    float y1 = (float)(ay < by ? by : ay) + 0.5f;
    x1 += origin.x;
    x0 += origin.x;
    y0 += origin.y;
    y1 += origin.y;
    float width = x1 - x0;
    if (!(width > 1.0f)) {
        width = 1.0f;
    }
    float height = y1 - y0;
    if (!(height > 1.0f)) {
        height = 1.0f;
    }
    Unk80173D58Vertex vertices[4];
    SetFlatVertex(&vertices[0], x1, y0, width, height);
    SetFlatVertex(&vertices[1], x0, y0, 0.0f, height);
    SetFlatVertex(&vertices[2], x1, y1, width, 0.0f);
    SetFlatVertex(&vertices[3], x0, y1, 0.0f, 0.0f);
    ((Unk8002D2D4RC*)rc)->vfn29();
    ((Unk8002D2D4RC*)rc)->vfn3(vertices, 4);
}

// 0x8002DA7C
void fn_8002DA7C(ERC* rc, Unk8002D67CItem* item) {
    item->unk28->fn_80181824(rc);
    fn_8002D67C(rc, item);
}

// 0x8002DAC0
void fn_8002DAC0(ERC* rc, Unk8002D67CItem* item) {
    lbl_8037B4B0->fn_80181824(rc);
    fn_8002D67C(rc, item);
}

// 0x8002DB04
void fn_8002DB04(ERC* rc, Unk8002D67CItem* item) {
    EVec2 a(item->unk8, item->unkC);
    EVec2 b(item->unk10, item->unk14);
    int flag = item->unk24;
    fn_80035C70(rc, item->unk28, &a, &b, &flag);
}

// 0x8002DB60
// Draws a textured strip from one point of the item to the other, the texture
// repeated once per unit of length.
// NON_MATCHING: condensed draft (the original fills four renderer-allocated vertices
// in the open and treats kinds 3 and 5 specially). One variant tried.
extern "C" float fn_8010DF80(float); // sqrtf
void fn_8002DB60(ERC* rc, Unk8002D67CItem* item) {
    EVec2 delta(item->unk8 - item->unk10, item->unkC - item->unk14);
    int kind = item->unk24;
    int length = (int)fn_8010DF80(delta.x * delta.x + delta.y * delta.y);
    if (length < 1) {
        length = 1;
    }
    Unk80173D58Vertex* vertices = (Unk80173D58Vertex*)((Unk80173D58Alloc*)rc)->fn_80173D58(0x140, 0x20);
    float height = kind == 5 ? 1.0f : 3.5f;
    float repeat = (float)length;
    SetFlatVertex(&vertices[0], item->unk8, item->unkC, 0.0f, 0.0f);
    vertices[0].unk0[2] = height;
    vertices[1] = vertices[0];
    vertices[1].unk0[2] = 0.0f;
    vertices[1].unk20[1] = 1.0f;
    vertices[2] = vertices[0];
    vertices[2].unk0[0] = item->unk10;
    vertices[2].unk0[1] = item->unk14;
    vertices[2].unk20[0] = repeat;
    vertices[3] = vertices[2];
    vertices[3].unk0[2] = 0.0f;
    vertices[3].unk20[1] = 1.0f;
    ((Unk8002D2D4RC*)rc)->vfn29();
    ((Unk8002D2D4RC*)rc)->vfn3(vertices, 4);
}

// 0x8002DF60
void fn_8002DF60(ERC* rc, Unk8002D67CItem* item) {
    EVec2 a(item->unk8, item->unkC);
    EVec2 b(item->unk10, item->unk14);
    int kind = item->unk24;
    float width;
    if (kind == 5) {
        width = 1.5f;
    } else {
        width = 3.5f;
    }
    fn_80031CF0(rc, lbl_8037B4B0, &a, &b, 0, width, 0.0f);
    a += item->unk18;
    b += item->unk18;
    int out;
    fn_8003849C(rc, &a, &b, item->unk28, &out, kind, 0);
}

// 0x8002E058
void fn_8002E058(ERC* rc, Unk8002D67CItem* item) {
    Unk80056498* drawer = 0;
    Unk8004AD08C* view = (Unk8004AD08C*)lbl_802E67B0.unk0;
    if (view) {
        drawer = view->unk8;
    }
    if (drawer) {
        item->unk28->fn_80181824(rc);
        drawer->fn_80056498(rc, item->unk6, &item->unk10);
    }
}

// 0x8002E0C4
void fn_8002E0C4(ERC* rc, Unk8002D67CItem* item) {
    EVec2 a(item->unk8, item->unkC);
    EVec2 b(item->unk10, item->unk14);
    fn_80031CF0(rc, lbl_8037B4B0, &a, &b, 0, 3.5f, 0.0f);
    a += item->unk18;
    b += item->unk18;
    int out;
    fn_8003849C(rc, &a, &b, item->unk28, &out, 3, 0);
}

// 0x8002E19C
void fn_8002E19C(ERC* rc, Unk8002D67CItem* item) {
    fn_8002E0C4(rc, item);
}

// 0x8002E1BC
// Callback: applies an action to every entry filed under a key.
// NON_MATCHING: 56 instructions vs 57; the loop over the three-byte entries is laid
// out differently. One variant tried.
void fn_8002E1BC(void* key, int flag) {
    Unk80234390* list = FindList(key);
    if (list && key) {
        char* it = list->unk4;
        if (it != list->unk8) {
            do {
                fn_800311B0(it, flag, list);
                it += 3;
            } while (it != list->unk8);
            if (fn_8007600C()) {
                if (flag) {
                    lbl_8037D96C->fn_8006186C(0xB2AD3ECD);
                } else {
                    lbl_8037D96C->fn_8006186C(0x994E8974);
                }
                Unk80026864::fn_80028ECC();
            } else {
                lbl_8037D96C->fn_8006186C(0x3804219F);
            }
        }
    }
}

// 0x8002E2A0
// Callback: sets or clears a floor flag on every tile of a rectangle.
void fn_8002E2A0(int flag, int x0, int y0, int x1, int y1) {
    for (int x = x0; x <= x1; x++) {
        for (int y = y0; y <= y1; y++) {
            Unk801C6F44 tile(x, y, 1);
            if (fn_8002FE20(&tile, flag)) {
                Unk8037D990E* level = (Unk8037D990E*)lbl_8037D990;
                Unk8023DFA8 info = level->vfn18(&tile);
                if (!info.fn_8023DFA8()) {
                    level->vfn15(&tile, flag);
                } else {
                    int second;
                    int first;
                    if (info.fn_8023DEA4(0x20)) {
                        second = 1;
                        first = 3;
                    } else {
                        info.fn_8023DEA4(0x10);
                        second = 2;
                        first = 4;
                    }
                    info.fn_8023E43C(flag, first);
                    info.fn_8023E43C(flag, second);
                    Unk8023DDC4 packed(info);
                    level->vfn19(&tile, &packed);
                    level->vfn15(&tile, 0xFF);
                }
            }
        }
    }
    if (fn_8007600C()) {
        if (flag) {
            lbl_8037D96C->fn_8006186C(0xB2AD3ECD);
        } else {
            lbl_8037D96C->fn_8006186C(0x994E8974);
        }
        Unk80026864::fn_80028ECC();
    } else {
        lbl_8037D96C->fn_8006186C(0x3804219F);
    }
}

// 0x8002E498
// Callback: an outline, drawn as four edges.
// NON_MATCHING: same length, 32 instructions differ: the eight coordinate stores of
// the four corners and the argument set-up are interleaved differently. One variant.
void fn_8002E498(void* arg, int kind, float x0, float x1, float y0, float y1) {
    EVec2 a(x0, y0);
    EVec2 b(x1, y0);
    EVec2 c(x1, y1);
    EVec2 d(x0, y1);
    int out = 0;
    fn_80038FC0(&a, &b, arg, kind, &out, 1, 0, 0);
    fn_80038FC0(&b, &c, arg, kind, &out, 1, 0, 0);
    fn_80038FC0(&d, &c, arg, kind, &out, 1, 0, 0);
    fn_80038FC0(&d, &a, arg, kind, &out, 1, 0, 0);
    if (((Unk80057920*)((Unk8004AD08C*)lbl_802E67B0.unk0)->unk8)->fn_80057920(kind == 5)) {
        lbl_8037D96C->fn_8006186C(0xB2AD3ECD);
        Unk80026864::fn_80028ECC();
    } else {
        lbl_8037D96C->fn_8006186C(0x3804219F);
    }
}

// 0x8002E5DC
// NON_MATCHING: 8 instructions; the address of the first point is loaded into r3
// last in the original (after the other arguments) and first here. One variant.
void fn_8002E5DC(void* arg, int kind, float x0, float y0, float x1, float y1) {
    EVec2 a(x0, y0);
    EVec2 b(x1, y1);
    int out = 0;
    fn_80038FC0(&a, &b, arg, kind, &out, 1, 0, 0);
    if (((Unk80057920*)((Unk8004AD08C*)lbl_802E67B0.unk0)->unk8)->fn_80057920(kind == 5)) {
        lbl_8037D96C->fn_8006186C(0xB2AD3ECD);
        Unk80026864::fn_80028ECC();
    } else {
        lbl_8037D96C->fn_8006186C(0x3804219F);
    }
}

// 0x8002E68C
// NON_MATCHING: as fn_8002E5DC.
void fn_8002E68C(void* arg, int kind, float x0, float y0, float x1, float y1) {
    EVec2 a(x0, y0);
    EVec2 b(x1, y1);
    int out = 0;
    fn_80038FC0(&a, &b, arg, kind, &out, 1, 1, 0);
    if (((Unk80057920*)((Unk8004AD08C*)lbl_802E67B0.unk0)->unk8)->fn_80057920(kind == 5)) {
        lbl_8037D96C->fn_8006186C(0xB2AD3ECD);
        Unk80026864::fn_80028ECC();
    } else {
        lbl_8037D96C->fn_8006186C(0x3804219F);
    }
}


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
// The two sides a wall of the given kind has when nothing narrows it down.
inline void BothSides(int* sides, int& count, int wall) {
    if (wall == 0x10) {
        sides[count++] = 2;
        sides[count] = 4;
    } else {
        sides[count++] = 1;
        sides[count] = 3;
    }
}

// 0x8002E73C
// Callback: for every tile filed under a key, applies an action to the sides of its
// walls that belong to that key.
// NON_MATCHING: 201 instructions vs 206. Draft: calls, loops and the side tables are
// the original's; register use differs throughout. One variant tried.
void fn_8002E73C(int key, int arg) {
    Unk80234774* table = (Unk80234774*)lbl_8037D998;
    Unk8037D990G* level = (Unk8037D990G*)lbl_8037D990;
    Unk80234390* list = fn_80234390(table, (void*)key);
    for (char* it = list->unk4; it != list->unk8; it += 3) {
        Unk801C6F20 tile(*(Unk801C6F20*)it);
        if (level->vfn21(&tile)) {
            Unk8023E354 info = level->vfn18(&tile);
            int count = 0;
            int sides[2];
            sides[0] = 0;
            sides[1] = 0;
            for (int wall = info.fn_8023E354(); wall; wall = info.fn_8023E3BC(wall)) {
                if (wall == 0x10 || wall == 0x20) {
                    Unk801C6F20 copy(tile);
                    unsigned short* a = 0;
                    unsigned short* b = 0;
                    int sideA;
                    int sideB;
                    if (table->fn_80234774(&copy, &a, &b, &sideA, &sideB)) {
                        if (a && *a == key) {
                            if (sideA == 1) {
                                sides[count] = sideA;
                            } else if (sideA == 3) {
                                sides[count] = sideA;
                            } else if (sideA == 4) {
                                sides[count] = 2;
                            } else if (sideA == 2) {
                                sides[count] = 4;
                            } else {
                                BothSides(sides, count, wall);
                            }
                            count++;
                        }
                        if (b && b != a && *b == key) {
                            bool known = true;
                            if (sideB == 1) {
                                sides[count] = sideB;
                            } else if (sideB == 3) {
                                sides[count] = sideB;
                            } else if (sideB == 4) {
                                sides[count] = 2;
                            } else if (sideB == 2) {
                                sides[count] = 4;
                            } else {
                                known = false;
                            }
                            if (known) {
                                count++;
                            }
                        }
                    } else {
                        BothSides(sides, count, wall);
                        count++;
                    }
                } else {
                    count = 1;
                }
                for (int i = 0; i < count; i++) {
                    if (sides[i]) {
                        sides[i] = fn_8023E4A4(sides[i], 0);
                    }
                    fn_800331A8(&tile, arg, wall, sides[i]);
                }
            }
        }
    }
    Unk80026864::fn_80028ECC();
}

// Tile position with the operations the wall-run callback uses (the same 8-byte
// CTilePt as above).
struct Unk801C6EF4 {
    Unk801C6EF4();                                         // 0x801C6EF4
    Unk801C6EF4(const Unk801C6EF4& other);                 // 0x801C6F00
    ~Unk801C6EF4();                                        // 0x801C6FCC
    Unk801C6EF4& operator=(const Unk801C6EF4& other);      // 0x801C6FF4
    int operator==(const Unk801C6EF4& other) const;        // 0x801C7014
    Unk801C6EF4 operator+(const struct Unk8035ABB0& step) const;   // 0x801C7144
    char unk0[2];
    char unk2;
    char unk3[5];
};
struct Unk8035ABB0 {
    char unk0[3];
};
extern Unk8035ABB0 lbl_8035ABB0[];   // one step per direction
void fn_8003739C(EVec2* a, EVec2* b, Unk801C6EF4* start, Unk801C6EF4* end);
void fn_800315FC(Unk801C6EF4* start, Unk801C6EF4* end);
int fn_800369A0(Unk801C6EF4* start, Unk801C6EF4* end);
int fn_8023DC04(int direction);
void fn_800323D8(int* wall, int kind, int* side, Unk801C6EF4* from, Unk801C6EF4* to);
struct Unk8023E110 : Unk8023DFA8 {
    void fn_8023E110(int arg, int wall, int side);
};
struct Unk8037D990H {
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
    virtual Unk8023E110 vfn18(Unk801C6EF4* tile);
    virtual void vfn19(Unk801C6EF4* tile, Unk8023DDC4* packed);
};
struct Unk80233FC0 {
    void fn_80233FC0();
};

// 0x8002EA74
// Callback: walks the tiles from one point to another and applies an action to the
// wall on each.
// NON_MATCHING: same length (157), 67 instructions differ: register assignment and
// the order in which the locals' addresses are taken. One variant tried.
void fn_8002EA74(int arg, int kind, float x0, float y0, float x1, float y1) {
    EVec2 a(x0, y0);
    EVec2 b(x1, y1);
    Unk801C6EF4 start;
    Unk801C6EF4 end;
    fn_8003739C(&a, &b, &start, &end);
    int steps = 0;
    fn_800315FC(&start, &end);
    bool done = false;
    int direction = fn_800369A0(&start, &end);
    int wall = fn_8023DC04(direction);
    Unk801C6EF4 current(start);
    Unk801C6EF4 last(end);
    int side = 0;
    fn_800323D8(&wall, kind, &side, &current, &last);
    Unk8037D990H* level = (Unk8037D990H*)lbl_8037D990;
    do {
        Unk8023E110 info = level->vfn18(&current);
        if (info.fn_8023DEA4(wall)) {
            info.fn_8023E110(arg, wall, side);
            Unk8023DDC4 packed(info);
            level->vfn19(&current, &packed);
        }
        current = current + lbl_8035ABB0[direction];
        current.unk2 = 1;
        if (level->vfn8(&current)) {
            done = true;
        }
        if (!done && current == last) {
            done = true;
        }
        steps++;
        if (steps >= level->vfn6()) {
            break;
        }
    } while (!done);
    ((Unk80233FC0*)lbl_8037D998)->fn_80233FC0();
    Unk80026864::fn_80028ECC();
}

// 0x8002ECE8
void fn_8002ECE8(void* arg) {
    ((Unk80026864*)lbl_802E6700.unkA8[0])->fn_8002C370((Unk800053D4Inner*)arg);
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

// 0x8002EE28
// NON_MATCHING (not emitted): this is STLport's _Rb_global<bool>::_M_increment (the
// red-black tree iterator's ++), a template function that lives in this unit because
// it is the first one in link order to offer it; units further on call it. Nothing
// in this file uses a std::map or std::set yet, so the compiler has no instance to
// emit. Its symbol carries the mangled name, so including the header that uses the
// tree here (once it is identified) is all that is missing.
