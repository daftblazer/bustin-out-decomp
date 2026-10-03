#ifndef SIMS_ESIMSAPP_H
#define SIMS_ESIMSAPP_H

#include "engine/EApp.h"
#include "engine/EStream.h"
#include "engine/StateMachine.h"

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
    void fn_800E6038();
    ~SimsAppUnk47C();
    char unk0[0x64];
};

struct SimsAppUnk4E0 {
    SimsAppUnk4E0();
    void fn_800D5618();
    void fn_800D59D0();
    ~SimsAppUnk4E0();
    char unk0[0x2B38 - 0x4E0];
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
    void fn_8018B044(struct ERC*);
    void* operator new(unsigned int size) { return fn_80169F1C(size, 16); }

    char unk0[0x9C];
};

// Base class of the object at ESimsApp+0x2B50; introduces the vtable pointer at 0x44.
struct SimsAppUnk2B50Base {
    virtual ~SimsAppUnk2B50Base();
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

    char unk0[0x44];
};

// Size 0x338 (ctor at 0x8004578C).
struct SimsAppUnk2B50 : public SimsAppUnk2B50Base {
    SimsAppUnk2B50(int, int);
    virtual ~SimsAppUnk2B50();

    char unk48[0x338 - 0x48];
};

struct Unk802E6700 {
    union {
        char unk0[0x218]; // size unknown
        struct {
            unsigned short unk0;            // 0x00 buttons allowed in cheat codes
            unsigned short codes[8][6];     // 0x02 button sequences, zero-terminated
            unsigned short masks[8];        // 0x62 buttons used by each sequence
        } cheats;
    };
    void fn_800690E0(int);
    void Begin();
    void End();
    void* GetUnk90() { return *(void**)(unk0 + 0x90); }
    int GetUnkA4() { return *(int*)(unk0 + 0xA4); }
    int GetUnk214() { return *(int*)(unk0 + 0x214); }
    unsigned int fn_800655D8();
    struct Unk800669ACResult fn_800669AC(const char* format, ...);
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
    virtual int vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual int vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual int vfn18();
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
    void fn_800F850C(float);
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

struct EController;

// Cheat-code button sequence tracker.
class PlayerCheats {
public:
    bool Capture(EController* controller);
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
    virtual float vfn5(void*);
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

struct EController {
    int fn_8015E304();
    void fn_8015DFEC(int);
};

struct Unk8037C11C {
    Unk8015CAA0* fn_8015E574(int);
    void fn_8015E550(int);
    int fn_8015E614(int);
    EController* fn_8015E5FC(int);
};

struct ERC;

struct Unk8037C198 {
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
    virtual ERC* vfn13(int);
    virtual void vfn14(ERC*);
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
    virtual void vfn42(const char*);
};

struct Unk80292314 {
    float unk0, unk4, unk8, unkC;
    Unk80292314() : unk0(0.0f), unk4(0.0f), unk8(0.0f), unkC(0.0f) {}
};

extern Unk8037C198* lbl_8037C198;
extern int lbl_8037D3D0;
extern unsigned short lbl_8037B3EC;
extern void* lbl_8037D940;
extern float lbl_8037BFC8;
extern char lbl_8033F8B0[0x100]; // size unknown
void fn_8011D784();
void fn_801063A4(void*);
void fn_800E6714();
void fn_800E67CC();
void fn_80255A54(void*);
void fn_80182B30(float);
void fn_8018AD9C(int, int, int, int, int);
extern "C" int fn_8010F710(char*, const char*, ...); // sprintf

// Frame timing marks kept by ESimsApp::Update (written, never read).
inline void MarkUpdateStart(SimsAppUnk2B3CRect& times) { times.unk4 = lbl_8037C114->vfn5(lbl_8033F8B0); }

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

// State machines created by ESimsApp::initContinue (0x94 bytes each).
class Unk802B5A68Machine : public StateMachine {
public:
    Unk802B5A68Machine() : StateMachine(0x53494D53) /* 'SIMS' */, unk7C(0), unk80(0), unk84(0), unk88(0), unk8C(1), unk90(0) {}
    virtual ~Unk802B5A68Machine();
    virtual void Startup();

    int unk7C, unk80, unk84, unk88, unk8C, unk90;
};

class Unk802AF658Machine : public StateMachine {
public:
    Unk802AF658Machine() : StateMachine(0x4D555354) /* 'MUST' */, unk7C(0), unk80(0), unk84(0), unk88(0), unk8C(1) {}
    virtual ~Unk802AF658Machine();
    virtual void Startup();

    int unk7C, unk80, unk84, unk88, unk8C, unk90;
};

struct Unk802E6818Target {
    char unk0[0x14];
    char unk14;
};
struct Unk802E6818 {
    Unk802E6818Target* unk0;
    char unk4[0x100]; // size unknown
};
struct Unk800669ACResult {
    int* ptr;
};

extern Unk802E6818 lbl_802E6818;
extern float lbl_8037D938;
void fn_800616B0();
void fn_8018FE20(int, int);

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

// Something included by this unit streams a TArray<unsigned int>: the unit holds
// the binary's shared copy of that template and of its operator>>. What it is
// has not been identified, so this stand-in triggers the instantiation.
struct UnkUIntArrayReader {
    TArray<unsigned int> unk0;
    void Read(EStream& stream) { stream >> unk0; }
};

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
    virtual void Update(); // slot 24
    virtual void Shutdown();

    void Init();
    void initContinue();
    void parseCommandLine();
    int GetDefaultLanguage();
    void LoadSimulatorGlobs();

    SimsAppUnk478* unk478;
    SimsAppUnk47C unk47C;
    SimsAppUnk4E0 unk4E0;
    ERC* unk2B38;
    SimsAppUnk2B3C* unk2B3C;
    char unk2B40;
    int unk2B44;
    char unk2B48[0x2B4C - 0x2B48];
    int unk2B4C;
    SimsAppUnk2B50Base* unk2B50;
    int unk2B54; // take a tiled screenshot on the next update
    int unk2B58; // tiles across
    int unk2B5C; // tiles down
    PlayerCheats* unk2B60;
};

#endif
