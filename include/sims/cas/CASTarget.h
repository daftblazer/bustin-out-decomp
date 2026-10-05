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
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    unsigned char unk10;
    int unk14;
    int unk18;
};
// Description of one sim (0xF8 bytes); copied whole.
struct CASSimDesc {
    unsigned char unk0[0xC];
    Unk801CC464 unkC;
    char unk28[0xA8 - 0x28];
    int unkA8;
    char unkAC[0xF8 - 0xAC];
};
// A family of up to four sims.
struct CASFamily {
    CASSimDesc sims[4];
    int present[4];
};
struct Unk80039E78 {
    Unk80039E78();
    ~Unk80039E78();
    char unk0[4];
};
// Animated model instance (0x74 bytes).
struct Unk80156438 {
    Unk80156438();
    void fn_80156700(unsigned int modelId);
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
    void* unk0;
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
};
// The sim being shown (0x19C bytes).
struct Unk80018374 {
    Unk80018374(CASSimDesc* desc, Unk8001EE8C* owner, int);
    Unk80018374(int, int, Unk8001EE8C* owner);
    ~Unk80018374() { fn_8001A67C(); }
    void fn_8001A67C();
    void fn_8001C240();
    void fn_8001C384();
    void fn_8001E6E8(int, int);
    void SetUnk154(EVec3 position) { unk154 = position; }

    char unk0[8];
    int unk8;
    char unkC[0x14 - 0xC];
    int unk14;
    char unk18[0xC8 - 0x18];
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

// Screen size in pixels.
struct CASScreenInfo {
    char unk0[0x14];
    int unk14; // width
    int unk18; // height
};
extern CASScreenInfo* lbl_8037C198;
int fn_800430EC(unsigned short character); // true for characters a line may break at

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
    void fn_8010826C(void* owner);
    void fn_80108290(void* owner);
};
void fn_801066A0(void* viewer, const char* name, int);
extern "C" void fn_80106164(void* viewer, const char* command, ...);
unsigned char fn_80061FE0(short* choices);
void fn_80062134(unsigned char);

// A mirror plane given by three corner points: builds the reflection matrix
// and applies it to a view while the reflected scene is drawn. The class name
// is provisional.
class CASMirror {
public:
    void fn_8000AC6C();
    void fn_8000AF70(Unk801543AC* view);
    void fn_8000B03C(Unk801543AC* view);

    EMat4 unk0;   // reflection
    EVec3 unk40;  // three corners of the mirror
    EVec3 unk4C;
    EVec3 unk58;
    char unk64[0x8C - 0x64];
    EMat4 unk8C;  // the view's own matrix, saved while reflecting
};

// The Create-A-Sim / Create-A-Family screen (0x5D30 bytes, ctor 0x80008AA0).
// Named after The Sims 2's CASTarget; whether this game used that exact name
// is not known. Members are generated from CASTarget.fields.
class CASTarget : public UnkTargetBase {
public:
    CASTarget();
    virtual ~CASTarget();
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
    void fn_80014110();
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
