#ifndef SIMS_CAS_CASWIDGETS_H
#define SIMS_CAS_CASWIDGETS_H

#include "engine/EController.h"
#include "engine/EMat4.h"
#include "engine/EVec3.h"
#include "engine/UnkTargetBase.h"

// Two widgets used by the Create-A-Sim screen. Class names are provisional.

struct ERC;

// RGBA colour as four floats; copied as words.
struct EColorF {
    float r, g, b, a;
};
extern EColorF lbl_802E69C4; // highlighted
extern EColorF lbl_802E6964; // normal

// Text renderer (functions around 0x8003C95C).
struct Unk8003C95C {
    void fn_8003C95C(int, float, float);
    EVec3 fn_8003D550(const unsigned short* text, int, int); // text extent
    void fn_8003DBE8(ERC* rc);
    void fn_8003D740(ERC* rc, const unsigned short* text, int, EVec2* position, int, int, int);

    char unk0[0x64];
    EColorF unk64;
};

struct Unk80181824 {
    void fn_80181824(ERC* rc);
};

// Render context: vtable pointer at 0x44.
struct ERC {
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
    virtual void vfn28(EMat4* matrix, int);
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
    virtual void vfn44(void* light);
    virtual void vfn45();
    virtual void vfn46();
    virtual void vfn47();
    virtual void vfn48();
    virtual void vfn49(EVec2* position, EVec2* size, EColorF* color, float);
};

// Callback invoked when a widget arrow is pressed (may be null).
extern void (*lbl_8037C0D4)();

void fn_801767FC(void* resource);

// Left/right selector with a caption (vtable 0x80292EA8).
class CASSelector : public UnkTargetBase {
public:
    virtual ~CASSelector();
    void Draw(ERC* rc);
    void Update();
    void ReleaseResources();
    void operator delete(void* ptr);

    EColorF unk48;        // left arrow colour
    EColorF unk58;        // right arrow colour
    const unsigned short** unk68; // caption
    int unk6C;            // message sent when moving right
    int unk70;            // message sent when moving left
    int unk74;
    Unk8003C95C* unk78;
    void* unk7C;
    Unk80181824* unk80;   // left arrow sprite
    Unk80181824* unk84;   // right arrow sprite
};

struct Unk8033FF34Resource {
    char unk0[0x6C];
    float unk6C;
    void fn_8017CC58(ERC* rc);
};
struct Unk8033FF34 {
    Unk8033FF34Resource* fn_80177628(unsigned int id, int, int);
    void fn_801778B4(unsigned int id);
    char unk0[0x100]; // size unknown
};
extern Unk8033FF34 lbl_8033FF34;

// Spinning 3D model button (vtable 0x80292E10).
class CASSpinner : public UnkTargetBase {
public:
    CASSpinner(unsigned char message);
    virtual ~CASSpinner();
    void Draw(ERC* rc);
    void Update();

    float unk48;          // rotation, radians
    EVec3 unk4C;
    unsigned char unk58;
    unsigned char unk59;  // message sent when pressed
    Unk8033FF34Resource* unk5C;
};

#endif
