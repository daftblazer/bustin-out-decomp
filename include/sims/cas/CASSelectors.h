#ifndef SIMS_CAS_CASSELECTORS_H
#define SIMS_CAS_CASSELECTORS_H

#include "engine/E3DWindow.h"
#include "engine/UnkTargetBase.h"
#include "sims/cas/CASWidgets.h"

// Widgets of the Create-A-Sim personality and family pages (the source file
// at 0x8001562C). Class names are provisional.

// Personality slider: a value from 0 to 10 shown as bars either side of the
// centre. 0xE0 bytes, vtable 0x802948C8. Members also follow from its
// compiler-generated assignment operator (0x800150F8).
class CASTargetUnk533C : public UnkTargetBase {
public:
    CASTargetUnk533C();
    virtual ~CASTargetUnk533C();
    virtual void vfn2();
    virtual void vfn3(ERC* rc);
    void fn_800156C8();
    void fn_800158A4();
    unsigned char fn_80015900();
    void fn_80015908(int value);
    void fn_8001593C(int value);
    void operator delete(void* ptr) { fn_80169EE8(ptr); }

    unsigned char unk48; // value, 0-10
    unsigned char unk49; // bars left of centre
    unsigned char unk4A; // bars right of centre
    float unk4C;
    float unk50;
    EColorF unk54;
    EColorF unk64;
    struct Entry {
        const unsigned short* ptr;
    } unk74[2];           // captions at the two ends
    ERFont* unk7C;   // font
    unsigned int unk80;   // pulse phase
    float unk84[20];      // pulse brightness ramp
    Unk80181824* unkD4;   // bar texture
    Unk80181824* unkD8;   // left arrow
    Unk80181824* unkDC;   // right arrow
};

// Star-sign display. 0x90 bytes, vtable 0x80294830.
class Unk80016448 : public UnkTargetBase {
public:
    Unk80016448();
    virtual ~Unk80016448();
    virtual void vfn2();
    virtual void vfn3(ERC* rc);
    void fn_800164D4();
    void fn_8001680C();

    unsigned char unk48;
    int unk4C[13];
    ERFont* unk80; // font
    void* unk84;
    Unk80181824* unk88; // left arrow
    Unk80181824* unk8C; // right arrow

    // Declared so that it stays out of line, as in the original (see the
    // definition in CASTarget.cpp).
    Unk80016448& operator=(const Unk80016448& other);
};

// Base of the three arrow widgets below (vtable 0x80294798): owns four
// resources and draws them.
class Unk80016CF0 : public UnkTargetBase {
public:
    virtual ~Unk80016CF0() { fn_80017148(); }
    virtual void vfn3(ERC* rc);
    void fn_80017148();

    unsigned char unk48;          // current choice (also the message sent)
    float unk4C;                  // caption indent
    const unsigned short* unk50;  // caption
    const unsigned short* unk54;  // value text
    ERFont* unk58;           // font
    void* unk5C;
    Unk80181824* unk60;           // left arrow
    Unk80181824* unk64;           // right arrow
    int unk68;                    // enabled
};
class Unk80017218 : public Unk80016CF0 { // vtable 0x80294700
public:
    virtual void vfn2();
    virtual void vfn3(ERC* rc);
};
class Unk800176C0 : public Unk80016CF0 { // vtable 0x80294668
public:
    virtual void vfn2();
    virtual void vfn3(ERC* rc);
};
class Unk80017D68 : public Unk80016CF0 { // vtable 0x802945D0
public:
    virtual void vfn2();
    virtual void vfn3(ERC* rc);
};

struct Unk8037D96C {
    void fn_8006186C(unsigned int soundId);
};
extern Unk8037D96C* lbl_8037D96C;

#endif
