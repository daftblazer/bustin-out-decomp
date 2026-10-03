#ifndef SIMS_ESIMSAPP_H
#define SIMS_ESIMSAPP_H

#include "engine/EApp.h"

void* fn_80169F1C(unsigned int size, int align);

// NOTE: The retail disc has no symbols. Class, member and function names in
// this project are provisional unless stated otherwise.

// Size 0x74 (ctor at 0x8006431C).
struct SimsAppUnk478 {
    SimsAppUnk478();
    ~SimsAppUnk478();
    void Stop();
    void fn_800645E8(void*);

    char unk0[0x74];
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

struct SimsAppUnk2B3CRect {
    float unk0, unk4, unk8, unkC;
    SimsAppUnk2B3CRect(float a, float b, float c, float d) : unk0(a), unk4(b), unk8(c), unkC(d) {}
};

// Size 0xA0 (ctor at 0x8018ABB0).
struct SimsAppUnk2B3C {
    SimsAppUnk2B3C();
    virtual ~SimsAppUnk2B3C();
    void fn_8018B584(const SimsAppUnk2B3CRect&);
    void* operator new(unsigned int size) { return fn_80169F1C(size, 16); }

    char unk0[0x9C];
};

// Base class of the object at ESimsApp+0x2B50; introduces the vtable pointer at 0x44.
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
    unsigned int fn_800655D8();
    void fn_800656D8();
};

struct Unk80340094 {
    char unk0[0x100]; // size unknown
    void Shutdown();
};

struct Unk802E5E1C {
    char unk0[0x100]; // size unknown
    void Shutdown();
    void fn_80176C78(const char*, int);
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
    unsigned int fn_800F85B4();
    void fn_800F87A0();
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
void* fn_801B8A3C(unsigned int);

// Cheat-code button sequence tracker.
class PlayerCheats {
public:
    unsigned char GetNextIndex(unsigned char& index);
    bool IsSingleButton(unsigned short buttons);
    void PurgeBtnMemory();
    unsigned short CreateBtnMask();

    struct Button {
        unsigned short buttons;
        float expireTime;
    };

    char unk0[0x10];
    unsigned char unk10;
    int unk14;
    float unk18; // current time in milliseconds
    Button unk1C[6];
};

struct Unk8037C114 {
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4(PlayerCheats*);
    virtual float vfn5(PlayerCheats*);
};

extern Unk8037C114* lbl_8037C114;
extern int lbl_8037B3E0; // start lot from the "-lot" command line option

// These three globals share the method at 0x80177628 (resource managers?).
struct Unk803401C4 {
    void fn_80177628(unsigned int, int, int);
    char unk0[0xA4];
    int unkA4; // default language
};

struct Unk80340AB8 {
    void fn_80177628(unsigned int, int, int);
    char unk0[0x6C];
};

struct Unk8033F5C4 {
    void fn_80177628(unsigned int, int, int);
    char unk0[0xA4];
};

struct Unk8015CAA0 {
    void fn_8015CAA0(void*);
};

struct Unk8037C11C {
    Unk8015CAA0* fn_8015E574(int);
    void fn_8015E550(int);
};

// Allocated with the aligned allocator and zero-filled.
void* fn_80169F1C(unsigned int size, int align);
void* fn_80169E74(unsigned int size, int align);
void fn_80104794(void*, unsigned int);
void fn_8006015C();
extern "C" void* fn_80111C78(void*, int, unsigned int); // memset

struct Unk80103028 {
    Unk80103028();
    void* operator new(unsigned int size) {
        void* ptr = fn_80169F1C(size, 16);
        fn_80111C78(ptr, 0, size);
        return ptr;
    }
    char unk0[0xC];
};

struct Unk800813CC {
    Unk800813CC();
    void* operator new(unsigned int size) {
        void* ptr = fn_80169F1C(size, 16);
        fn_80111C78(ptr, 0, size);
        return ptr;
    }
    char unk0[0x8C];
};

struct Unk8037D2D8;
struct Unk8037D2EC {
    int unk0;
};
extern Unk8037D2D8 lbl_8037D2D8;
extern Unk8037D2EC lbl_8037D2EC;
void fn_801C6168(Unk8037D2D8*, const char*);
void fn_801C6A24(Unk8037D2EC*, const char*);

extern Unk803401C4 lbl_803401C4;
extern Unk80340AB8 lbl_80340AB8;
extern Unk8033F5C4 lbl_8033F5C4;
// The loop bound in ESimsApp::Init is not folded into the comparison, so it
// comes from an inline function rather than a literal.
inline int GetNumControllers() { return 4; }
extern Unk802E5E1C* lbl_8037C0B4;
extern int lbl_8037C0B8;
extern Unk8037C11C* lbl_8037C11C;
extern int lbl_8037CA30;
extern char lbl_802D1C60[0x1B8];

extern "C" {
char* fn_80111E30(const char*, int);                   // strchr
int fn_801120A8(const char*, const char*, int);        // case-insensitive strncmp
int fn_80110874(const char*);                          // atoi
}
void fn_801C6BB8();
void ProfileHook();

// The game's application object. Class and method names follow the symbol map
// of The Sims 2 (GameCube), which shares this engine.
class ESimsApp : public EApp {
public:
    ESimsApp();
    virtual ~ESimsApp();
    virtual const char* GetBuildVersion();
    // Inline functions are emitted at the end of the object in declaration order.
    virtual const char* GetAppName() { return "The Sims For PS2"; }
    virtual const char* vfn3() { return ""; }
    virtual const char* vfn4() { return ""; }
    virtual int GetEventTableSize() { return 0; }
    virtual void vfn17(int);
    virtual bool vfn18();
    virtual void vfn19(int);
    virtual void vfn20(int);
    virtual void SetGameState(int);
    virtual void vfn23();
    virtual void vfn24();
    virtual void Shutdown();

    void Init();
    void initContinue();
    void parseCommandLine();
    int GetDefaultLanguage();
    void LoadSimulatorGlobs();

    SimsAppUnk478* unk478;
    SimsAppUnk47C unk47C;
    SimsAppUnk4E0 unk4E0;
    SimsAppUnk2B3C* unk2B3C;
    char unk2B40;
    int unk2B44;
    char unk2B48[0x2B4C - 0x2B48];
    int unk2B4C;
    SimsAppUnk2B50Base* unk2B50;
    char unk2B54[0x2B60 - 0x2B54];
    PlayerCheats* unk2B60;
};

#endif
