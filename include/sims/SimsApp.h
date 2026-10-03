#ifndef SIMS_SIMSAPP_H
#define SIMS_SIMSAPP_H

#include "engine/EApp.h"

// NOTE: The retail disc has no symbols. Class, member and function names in
// this project are provisional unless stated otherwise.

struct SimsAppUnk478 {
    ~SimsAppUnk478();
    void Stop();
};

struct SimsAppUnk47C {
    SimsAppUnk47C();
    ~SimsAppUnk47C();
    char unk0[0x64];
};

struct SimsAppUnk4E0 {
    SimsAppUnk4E0();
    ~SimsAppUnk4E0();
    char unk0[0x2B3C - 0x4E0];
};

struct SimsAppUnk2B3C {
    char unk0[0x9C];
    virtual ~SimsAppUnk2B3C();
};

// Base class of the object at SimsApp+0x2B50; introduces the vtable pointer at 0x44.
struct SimsAppUnk2B50Base {
    virtual ~SimsAppUnk2B50Base();

    char unk0[0x44];
};

// Size 0x338 (ctor at 0x8004578C).
struct SimsAppUnk2B50 : public SimsAppUnk2B50Base {
    SimsAppUnk2B50(int, int);
    virtual ~SimsAppUnk2B50();

    char unk48[0x338 - 0x48];
};

struct Unk802E6700 {
    char unk0[0x100]; // size unknown
    void Begin();
    void End();
};

struct Unk80340094 {
    char unk0[0x100]; // size unknown
    void Shutdown();
};

struct Unk802E5E1C {
    char unk0[0x100]; // size unknown
    void Shutdown();
};

extern Unk802E6700 lbl_802E6700;
extern Unk80340094 lbl_80340094;
extern Unk802E5E1C lbl_802E5E1C;
extern void* lbl_8037C3D8;
extern int lbl_8037B3E8;

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
    virtual void vfn14(void*);
};

struct Unk8037D94C {
    void fn_801EAE6C(int);
    int fn_801EB1D8();
};

struct Unk8037D944 {
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
};

struct Unk801888F4 {
    void fn_801888F4(int, int);
};

struct Unk80086E58 {
    char unk0[0x84];
    int unk84;
    void fn_80086E58();
};

struct Unk802F7658 {
    char unk0[0xF0];
    Unk80086E58* unkF0;
};

struct Unk802E6820Target {
    char unk0[0x24];
    int unk24;
};

struct Unk802E6820 {
    Unk802E6820Target* unk0;
    char unk4[0x100]; // size unknown
};

extern Unk8037D948* lbl_8037D948;
extern Unk8037D94C* lbl_8037D94C;
extern Unk8037D944* lbl_8037D944;
extern Unk802F7658 lbl_802F7658;
extern Unk802E6820 lbl_802E6820;

void fn_80046194();
void fn_801CD9A8(void*);
void fn_800FD840();
void fn_801B8A60(void*);

// The game's application object.
class SimsApp : public EApp {
public:
    SimsApp();
    virtual ~SimsApp();
    virtual const char* vfn3() { return ""; }
    virtual const char* vfn4() { return ""; }
    virtual const char* GetBuildString();
    virtual const char* GetTitle() { return "The Sims For PS2"; }
    virtual int vfn16() { return 0; }
    virtual void vfn17(int);
    virtual bool vfn18();
    virtual void vfn19(int);
    virtual void vfn20(int);
    virtual void vfn21(int);
    virtual void vfn23();
    virtual void vfn24();
    virtual void Shutdown();

    unsigned char fn_800049F0(unsigned char*);
    bool fn_80004A18(int);

    SimsAppUnk478* unk478;
    SimsAppUnk47C unk47C;
    SimsAppUnk4E0 unk4E0;
    SimsAppUnk2B3C* unk2B3C;
    char unk2B40;
    int unk2B44;
    char unk2B48[0x2B50 - 0x2B48];
    SimsAppUnk2B50Base* unk2B50;
    char unk2B54[0x2B60 - 0x2B54];
    void* unk2B60;
};

#endif
