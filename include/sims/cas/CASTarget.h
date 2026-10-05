#ifndef SIMS_CAS_CASTARGET_H
#define SIMS_CAS_CASTARGET_H

#include "engine/Unk801543AC.h"
#include "engine/EMat4.h"
#include "engine/UnkTargetBase.h"
#include "engine/ResourceManagers.h"
#include "sims/EGlobal.h"
#include "sims/cas/CASWidgets.h"

void* fn_80169F1C(unsigned int size, int align); // aligned allocate
extern "C" void* fn_80111C78(void*, int, unsigned int); // memset

// Member classes, known only by their constructors. Sizes are lower bounds
// except where an array fixes them.

// 0xE0 bytes, constructor 0x8001562C (the next unit); its method at 0x80015900
// returns the current choice. Members come from its generated assignment.
class CASTargetUnk533C : public UnkTargetBase {
public:
    CASTargetUnk533C();
    virtual ~CASTargetUnk533C();
    short fn_80015900();
    void fn_80015908(unsigned char choice);

    unsigned char unk48;
    unsigned char unk49;
    unsigned char unk4A;
    float unk4C;
    float unk50;
    EColorF unk54;
    EColorF unk64;
    struct Entry {
        void* ptr;
    } unk74[2];
    int unk7C;
    int unk80;
    float unk84[20];
    int unkD4;
    int unkD8;
    int unkDC;
};
struct Unk8001EE8C {
    Unk8001EE8C();
    ~Unk8001EE8C();
    void fn_8001EFEC();
    void fn_8001F34C();
    void fn_8001FAE0();
    char unk0[4];
};
struct Unk801CC464 {
    Unk801CC464();
    Unk801CC464(const Unk801CC464& other);
    void fn_801CC688();
    int unk0;
    int unk4;
    signed char unk8[0x14]; // one choice per feature slot
};
// Description of one sim (0xF8 bytes); copied whole.
struct CASSimDesc {
    unsigned char unk0[0xC];
    Unk801CC464 unkC;
    unsigned short unk28[0x20]; // first name
    unsigned short unk68[0x20]; // family name
    int unkA8;
    int unkAC;
    int unkB0[14];
    char unkE8[0xF8 - 0xE8];
};
// A family of up to four sims.
struct CASFamily {
    CASSimDesc sims[4];
    int present[4];
    int unk3F0[4];
    void* unk400; // name object
};
extern "C" const unsigned short* fn_8023C9EC(void* name);
extern "C" void fn_8023C9FC(void* name, const unsigned short* text);
extern "C" void fn_8023CA3C(void* name, void* other);
struct Unk80039E78 {
    Unk80039E78();
    ~Unk80039E78();
    int fn_8003A500();
    void fn_8003A0C0(EVec2* position, int, int* captions, int text, int, int, float width);
    void fn_80039F1C();
    char unk0[4];
};
// Animated model instance (0x74 bytes).
struct Unk80156438 {
    Unk80156438();
    void fn_80156700(unsigned int modelId);
    int fn_8015AA0C(int);  // animation finished
    void fn_8015A520(int); // restart
    void fn_801569F8(int, int, const EVec3& scale);
    void fn_8015B044(ERC* rc, Unk8033FF34Resource* model, const EMat4* transform); // draw
    void fn_80159994(int, unsigned int animationId);
    void SetUnk54(float value) { unk54 = value; }
    char unk0[0x54];
    float unk54;
    char unk58[0x70 - 0x58];
    virtual ~Unk80156438();
};
struct Unk801B9FEC {
    Unk801B9FEC();
    ~Unk801B9FEC() { fn_801B9FF8(unk0); }
    void fn_801B9FF8(void*);
    void fn_801BA18C(int capacity);
    char* unk0;
};
// 0x90 bytes, constructor 0x80016448.
class Unk80016448 : public UnkTargetBase {
public:
    Unk80016448();
    virtual ~Unk80016448();

    unsigned char unk48;
    int unk4C[13];
    int unk80;
    int unk84;
    int unk88;
    int unk8C;

    // Declared so that it stays out of line, as in the original (see the
    // definition in CASTarget.cpp).
    Unk80016448& operator=(const Unk80016448& other);
};

struct Unk800226F0 {
    void fn_800226F0(Unk801CC464* out);
    int fn_800218D8(int);
    void fn_80021928(int slot);
    void fn_8002196C(int slot);
};
// The sim being shown (0x19C bytes).
struct Unk80018374 {
    Unk80018374(CASSimDesc* desc, Unk8001EE8C* owner, int);
    Unk80018374(int, int, Unk8001EE8C* owner);
    ~Unk80018374() { fn_8001A67C(); }
    void fn_8001A67C();
    void fn_8001C240();
    void fn_8001C384();
    void fn_8001C028(int slot); // next choice
    void fn_8001C0A4(int slot); // previous choice
    void fn_8001A908(ERC* rc, float turn, int); // draw
    void fn_8001C3B8();
    int fn_8001D04C();
    void fn_8001AC88();
    void fn_8001AE1C(int, CASTargetUnk533C* selectors);
    int fn_8001E9D8(int, int, int slot, signed char choice); // true when the slot's choice is locked
    void fn_8001E6E8(int, int);
    void SetUnk154(EVec3 position) { unk154 = position; }

    char unk0[8];
    int unk8;
    char unkC[0x14 - 0xC];
    int unk14;
    char unk18[0x40 - 0x18];
    int unk40; // which side the sim is seen from
    int unk44;
    char unk48[0xC8 - 0x48];
    Unk800226F0* unkC8;
    char unkCC[0xE0 - 0xCC];
    Unk80156438 unkE0;
    EVec3 unk154; // position in the line-up
    char unk160[0x16C - 0x160];
    Unk801CC464 unk16C;
    char unk188[0x19C - 0x188];
};
// Text-entry dialog (0x178 bytes).
class Unk800C6704 : public UnkTargetBase {
public:
    Unk800C6704(int, int, int, int, int, int, int, float, float, float, int, int, int, int, int, int, int, int,
                int, int, int, int, int, int, int, int);
    int fn_800CAEF0();                  // 0 while open, 1 accepted, 2 cancelled
    Unk801BA678* fn_800C6FAC();         // the entered text
    void fn_800C6F08(int text, int);
    void fn_800C6FB4(int title);
    void fn_800C6E5C(int);
    char unk48[0x178 - 0x48];
};

// Save-data record for one user (ctor/dtor inline from its members).
struct Unk801C4E90 {
    Unk801C4E90();
    ~Unk801C4E90();
    char unk0[4];
};
struct CASUserRecord {
    int unk0;
    Unk801C4E90 unk4;
    Unk801C4E90 unk8;
    Unk801CC464 unkC;
};
void fn_80014AA8(CASUserRecord* record, void* data, int tag, int);
int fn_80014B00(CASUserRecord* record, void* file, int tag, int index, int);

// Resource file object: vtable pointer at 0x10.
struct Unk8037D94C {
    char unk0[0x10];
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
    virtual int vfn15(int tag);                    // number of records
    virtual void vfn16();
    virtual void vfn17();
    virtual void* vfn18(int tag, int index, int);  // record data
};
extern Unk8037D94C* lbl_8037D94C;
struct Unk8037D988 {
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
    virtual int vfn14(int id);
};
extern Unk8037D988* lbl_8037D988;
struct Unk8037D948 {
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
    virtual void* vfn64();
};
extern Unk8037D948* lbl_8037D948;
extern int lbl_8037C3F4;
void fn_801DA828(void*, Unk8037D94C* file);
extern "C" int fn_801115C4(); // rand
void fn_800620CC(short* choices, int preset);

// Data set resource with named nodes.
struct Unk801800FC {
    int fn_801800FC(const char* name);
    int Find(const char* name) { return fn_801800FC(name); }
    unsigned int** fn_8018021C(int node, const char* name);
    unsigned int** Get(int node, const char* name) { return fn_8018021C(node, name); }
};

// The renderer: screen size in pixels, and the texture cache.
struct CASScreenInfoBase {
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
    virtual void vfn21(int texture); // release
    virtual int vfn22();
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
    virtual float vfn37(); // pixel aspect
};
struct CASScreenInfo : CASScreenInfoBase {
    char unk4[0x10];
    int unk14; // width
    int unk18; // height
};
extern CASScreenInfo* lbl_8037C198;
int fn_800430EC(unsigned short character); // true for characters a line may break at

// Supplies the default names.
struct Unk8037D2D8 {
    const unsigned short* fn_801C5B24();
};
extern Unk8037D2D8 lbl_8037D2D8;
// Two colours used by the screen's lighting.
struct Unk80341458 {
    EColorF unk0;
    EColorF unk10;
};
extern Unk80341458 lbl_80341458;
extern "C" char* strcpy(char*, const char*);

// The family-member list shown on the family page.
class CASFamilyList : public UnkTargetBase {
public:
    CASFamilyList(int, int, float, float, float); // 0x80186F00
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn20(UnkTargetBase* child, const EVec3& offset);
    virtual void vfn21();
    virtual void vfn22();
    virtual void vfn23();
    virtual void vfn24(int, int, int);
    virtual void vfn25(int, int, int, float, float);
    virtual void vfn26();
    virtual void vfn27(int);

    CASSpinner* unk48; // highlighted entry
    char unk4C[0x7C - 0x4C];
    float unk7C;
    float unk80;
    char unk84[0x100 - 0x84];
};
struct Unk800E5DF8 {
    int unk0;
    int unk4;
    void fn_800E5EA8(const char* text);
};
Unk800E5DF8* fn_800E5DF8();
int fn_80106774(void* viewer, int, int, int, int); // next UI event: code, sign bit set on press
void fn_801063A0(void* viewer);
struct Unk8037D96C {
    void fn_8006186C(unsigned int soundId);
};
extern Unk8037D96C* lbl_8037D96C;
struct EGlobalUnk118 {
    char unk0[0xCC];
    int unkCC;
};
void fn_8017A778(void* resource);
inline float ERadToDeg(float radians) { return radians * 57.29578f; }

// Lighting set-up handed to the render context (0xE0 bytes).
struct ELightSet {
    struct Directional {
        EVec3 color;
        EVec3 direction;
    };
    struct Point {
        EVec3 position;
        float range;
        EVec3 color;
        float unk1C;
    };
    EVec3 ambient;
    int unkC;
    Directional directional[3];
    Point point[4];
    int numDirectional;
    int numPoint;
};
// Vertex as the render context takes it (0x50 bytes).
struct EVertex {
    EVec3 position;
    float w;
    int unk10[4];
    float u, v;
    int unk28[2];
    int unk30[3];
    int unk3C; // alpha
    char unk40[0x10];
};
struct Unk80184C00 {
    char unk0[0x24];
    void fn_80184C00(ERC* rc);
};
// The shader/material resource used for the props' shadows.
struct Unk80182DE0Inner {
    char unk0[0xB8];
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3(ERC* rc);
};
struct Unk80182DE0 {
    char unk0[0x20];
    Unk80182DE0Inner* unk20;
    void fn_80182DE0(float);
};
struct Unk8037C0E0 {
    char unk0[0xA0];
    EMat4 unkA0;
};
extern Unk8037C0E0* lbl_8037C0E0; // the active view
void fn_8017AA14(void* scene, ERC* rc);
void fn_80106484(void* viewer, ERC* rc);
int fn_801082B4(void* viewer);
EMat4& fn_80015070(EMat4& dst, const EMat4& src);
// Placement of three props: x, y, z and a turn angle each (small data, 0x8037B44C).
extern float lbl_8037B44C, lbl_8037B450, lbl_8037B454, lbl_8037B458;
extern float lbl_8037B45C, lbl_8037B460, lbl_8037B464, lbl_8037B468;
extern float lbl_8037B46C, lbl_8037B470, lbl_8037B474, lbl_8037B478;

extern "C" int fn_80111ECC(const char*, const char*);     // strcmp
extern "C" int fn_80112210(const char*, const char*, unsigned int); // strncmp
extern "C" char* fn_801122F0(char*, const char*, unsigned int);     // strncpy
extern "C" unsigned int fn_80111FF8(const char*);                   // strlen
extern "C" int fn_80110874(const char*);                            // atoi
extern "C" int fn_8010F7F0(const char*, const char* format, ...);   // sscanf
extern "C" void fn_8024257C(unsigned short* dst, const unsigned short* src, int count); // wide strncpy
extern unsigned char lbl_802B6491[]; // character class table
unsigned char fn_800621AC(const unsigned short* signName); // star sign by name
extern "C" int fn_8010F710(char* out, const char* format, ...); // sprintf
extern int lbl_802F76D8; // children enabled

// Scoped object used around the loading-thread flag (ctor 0x801BE528).
struct Unk801BE528 {
    Unk801BE528();
    ~Unk801BE528();
    void fn_801BE5C4(int);
    char unk0[0x40];
};

// Object whose slot-8 virtual starts a function running in the background.
struct Unk8037D13C {
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8(void (*function)());
};
extern Unk8037D13C* lbl_8037D13C;
extern int lbl_8037D9B8; // set by the background function when it has finished

// Callback objects handed to the functions at 0x80231598 / 0x802313B4.
struct Unk802316EC {
    virtual ~Unk802316EC();
    virtual void vfn2() = 0;
    virtual int vfn3() = 0;
};
struct Unk80231598 {
    void fn_80231598(Unk802316EC* callback, int);
    int fn_802313B4(Unk802316EC* callback, int, int, int);
};
void fn_801FC174(void*);
void fn_800183D0();

struct UnkViewer {
    int fn_801082CC();
    void fn_8010826C(void* owner);
    void fn_80108290(void* owner);
};
void fn_801066A0(void* viewer, const char* name, int);
extern "C" void fn_80106164(void* viewer, const char* command, ...);
unsigned char fn_80061FE0(short* choices);
const unsigned short* fn_80062134(unsigned char preset); // preset name

// A mirror plane given by three corner points: builds the reflection matrix
// and applies it to a view while the reflected scene is drawn. The class name
// is provisional.
class CASMirror {
public:
    void fn_8000AC6C();
    void fn_8000AF70(Unk801543AC* view);
    void fn_8000B03C(Unk801543AC* view);

    EMat4 unk0;   // reflection
    EVec3 unk40[6]; // corners of the mirror (the first three define the plane)
    int unk88;      // number of corners
    EMat4 unk8C;  // the view's own matrix, saved while reflecting
};

// The Create-A-Sim / Create-A-Family screen (0x5D30 bytes, ctor 0x80008AA0).
// Named after The Sims 2's CASTarget; whether this game used that exact name
// is not known. Members are generated from CASTarget.fields.
class CASTarget : public UnkTargetBase {
public:
    CASTarget();
    virtual ~CASTarget();
    virtual void vfn2();
    virtual void vfn3(ERC* rc);
    virtual void vfn7(UnkTargetBase* sender, int message);
    virtual void vfn8(const char* name, const char* value);
    virtual char* vfn9(const char* name);
    void fn_800123A4(ERC* rc);
    void fn_8000C458();
    int fn_8000C4A4();
    void fn_8000C5DC();
    void fn_8000CC40();
    void fn_8000CD04();
    void fn_8000C588();
    void fn_8000CBD8();
    void fn_8000D010();
    void fn_8000D020(CASFamily* family, int edit);
    void fn_8000D440(CASFamily* family, int edit, int which);
    void fn_8000D228();
    void fn_8000D7D8();
    void fn_800102B0();
    void fn_80010408();
    void fn_80010520(CASSimDesc* desc, int);
    void fn_800143E4();
    int fn_8000F9D8();
    void fn_8000FA68();
    void fn_8000FCE4();
    void fn_8000FECC(unsigned char view);
    void fn_80013784(ERC* rc);
    const unsigned short* fn_80014110();
    void fn_800141C0();
    void fn_800133DC(ERC* rc, const unsigned short* text, int centered);
    void fn_80014188(ERC* rc, const unsigned short* text, EVec2* position, int a, int b);
    void fn_80014378();
    void fn_80014564();
    void fn_80014914(int id, unsigned char value);
    void fn_800145C8();
    void fn_800146A0();
    void fn_80014770();
    void fn_80014840();
    void fn_80014A88();

    void operator delete(void* ptr) { fn_80169EE8(ptr); }

    // Zero-filled on allocation.
    void* operator new(unsigned int size) {
        void* ptr = fn_80169F1C(size, 16);
        fn_80111C78(ptr, 0, size);
        return ptr;
    }

#include "sims/cas/CASTarget.inc"
};

extern CASTarget* lbl_8037CA80; // screen being loaded
extern int lbl_8037CA84;
extern float lbl_8037CA88;     // loading progress
extern int lbl_8037C230;

#endif
