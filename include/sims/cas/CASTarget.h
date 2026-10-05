#ifndef SIMS_CAS_CASTARGET_H
#define SIMS_CAS_CASTARGET_H

#include "engine/EMat4.h"
#include "engine/UnkTargetBase.h"
#include "engine/ResourceManagers.h"
#include "sims/EGlobal.h"
#include "sims/cas/CASWidgets.h"

void* fn_80169F1C(unsigned int size, int align); // aligned allocate
extern "C" void* fn_80111C78(void*, int, unsigned int); // memset

extern "C" void fn_8024254C(unsigned short* dst, const unsigned short* src); // wide string copy

// Member classes, known only by their constructors. Sizes are lower bounds
// except where an array fixes them.

// 0xE0 bytes, constructor 0x8001562C (the next unit); its method at 0x80015900
// returns the current choice.
struct CASTargetUnk533C {
    CASTargetUnk533C();
    void fn_800150F8(CASTargetUnk533C* other);
    short fn_80015900();
    char unk0[0xE0];
};
struct Unk801543AC {
    Unk801543AC();
    char unk0[0x30];
    EMat4 unk30;
};
struct Unk8001EE8C {
    Unk8001EE8C();
    char unk0[4];
};
struct Unk801CC464 {
    Unk801CC464();
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;

    int GetKind() const {
        if (unk4) {
            if (unk0) {
                return 0;
            }
            return 1;
        }
        if (unk0) {
            return 2;
        }
        return 3;
    }
};
// Description of one sim (0xF8 bytes); copied whole.
struct CASSimDesc {
    char unk0[0xC];
    Unk801CC464 unkC;
    char unk28[0xF8 - 0x28];
};
struct Unk80039E78 {
    Unk80039E78();
    char unk0[4];
};
struct Unk80156438 {
    Unk80156438();
    ~Unk80156438();
    char unk0[0x74];
};
struct Unk801B9FEC {
    Unk801B9FEC();
    char unk0[4];
};
struct Unk801BA678 {
    Unk801BA678();
    unsigned short* unk0; // text buffer
    unsigned short* Get() const { return unk0; }
    void Assign(const Unk801BA678& other) { fn_8024254C(Get(), other.Get()); }
};
struct Unk80016448 {
    Unk80016448();
    void fn_800152A8(Unk80016448* other);
    char unk0[0x48];
    unsigned char unk48;
    char unk49[0x90 - 0x49];
};

struct Unk800226F0 {
    void fn_800226F0(Unk801CC464* out);
};
// The sim being shown (0x19C bytes).
struct Unk80018374 {
    Unk80018374(CASSimDesc* desc, Unk8001EE8C* owner, int);
    ~Unk80018374() { fn_8001A67C(); }
    void fn_8001A67C();
    void fn_8001C240();

    char unk0[0x14];
    int unk14;
    char unk18[0xC8 - 0x18];
    Unk800226F0* unkC8;
    char unkCC[0xE0 - 0xCC];
    Unk80156438 unkE0;
    char unk154[0x16C - 0x154];
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

struct E3DWindowLike {
    void fn_801546D8(const EMat4* matrix);
    char unk0[0xA0];
    EMat4 unkA0;
};

struct UnkViewer {
    void fn_8010826C(void* owner);
};
void fn_801066A0(void* viewer, const char* name, int);
extern "C" void fn_80106164(void* viewer, const char* command, ...);
unsigned char fn_80061FE0(short* choices);
void fn_80062134(unsigned char);

// The Create-A-Sim / Create-A-Family screen (0x5D30 bytes, ctor 0x80008AA0).
// Named after The Sims 2's CASTarget; whether this game used that exact name
// is not known. Members are generated from CASTarget.fields.
class CASTarget : public UnkTargetBase {
public:
    CASTarget();
    virtual ~CASTarget();
    void fn_8000AF70(E3DWindowLike* window);
    void fn_8000B03C(E3DWindowLike* window);
    void fn_8000C458();
    int fn_8000C4A4();
    void fn_8000C5DC();
    void fn_8000CC40();
    void fn_8000CD04();
    void fn_8000C588();
    void fn_8000CBD8();
    void fn_8000D010();
    void fn_8000D7D8();
    void fn_800102B0();
    void fn_80010408();
    void fn_80010520(CASSimDesc* desc, int);
    void fn_800143E4();
    int fn_8000F9D8();
    void fn_80014110();
    void fn_80014188(ERC* rc, const unsigned short* text, int a, EVec2* position, int b);
    void fn_80014378();
    void fn_80014564();
    void fn_800145C8();
    void fn_800146A0();
    void fn_80014770();
    void fn_80014840();
    void fn_80014A88();

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
