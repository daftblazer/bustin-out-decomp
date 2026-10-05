#ifndef SIMS_ESIMSCAM_H
#define SIMS_ESIMSCAM_H

#include "engine/ERectF.h"
#include "engine/E3DWindow.h"
#include "engine/EMat4.h"
#include "engine/EVec3.h"
#include "engine/EController.h"
#include "sims/EGlobal.h"
#include "sims/Unk800052C8.h"
#include "sims/Unk8037D944.h"


// Renderer singleton (also used by ESimsApp::Update).
struct ESimsCamRendererBase {
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
    virtual float vfn37();
    virtual int vfn38();
    virtual int vfn39();
};
struct ESimsCamRenderer : public ESimsCamRendererBase {
    char unk4[0x14 - 0x4];
    int unk14; // display width
    int unk18; // display height
};
extern ESimsCamRenderer* lbl_8037C198;

// Level/lot singleton: slot 6 returns the lot size in tiles.
struct Unk8037D990 {
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual int vfn6();
};
extern Unk8037D990* lbl_8037D990;

struct Unk8037D96C {
    void fn_8006186C(unsigned int id);
};
extern Unk8037D96C* lbl_8037D96C;

// Both live inside larger globals, so they are addressed with lis/addi.
struct ESimsCamBigInt {
    int unk0;
    char unk4[0x14];
};
extern ESimsCamBigInt lbl_802F76DC;
extern ESimsCamBigInt lbl_802E686C;

// Object at EGlobal+0xBC, vtable pointer at 0x44.
struct ESimsCamUnkBC {
    char unk0[0x44];
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7(int, int);
};

// Where the camera looks and from how far. Name from The Sims 2's symbol map
// (ESimsCam::CalcEyePosition(EVec3&, ESimsCam::CameraParameters&)).
struct CameraParameters {
    EVec3 unk0;   // target
    float unkC;   // distance
    float unk10;  // rotation, degrees
    float unk14;  // tilt, degrees
};

// The cursor/target object a camera follows; vtable pointer at 0x44.
struct Unk324Base {
    void fn_80027EAC();
    EVec3* fn_8002D2C8();

    char unk0[0x44];
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4(const EVec3& position);
};
struct Unk324 : public Unk324Base {
    char unk48[0x94 - 0x48];
    EVec3 unk94; // previous position
};

// The game camera. Class and method names follow The Sims 2's symbol map where
// the functions line up; member names are provisional.
// First base of ESimsCam: holds the panel state and declares the state hooks.
// The real name is unknown.
class ESimsCamBase {
public:
    virtual ~ESimsCamBase() {}
    virtual void SetState(int state) = 0;
    virtual void vfn3() = 0;

    int mPanelState;
};

// Second-level base: the player the camera belongs to.
class ESimsCamBase2 : public ESimsCamBase {
public:
    int unk8;  // player index
    int unkC;
    int unk10;
};

class ESimsCam : public ESimsCamBase2, public E3DWindow {
public:
    // 0x80007EC0. NON_MATCHING: 28 instructions vs 25. The original destroys the window
    // as a base class (destructor flag 0) but does not store a second vtable pointer
    // at 0xB0 first, which this compiler does for a polymorphic second base.
    virtual ~ESimsCam() { fn_800058CC(); }
    virtual void SetState(int state);
    virtual void vfn3() {}
    virtual void Update();
    void operator delete(void* ptr) { fn_80169EE8(ptr); }

    void GetPos(EVec3& eye, EVec3& target, EVec3& unk);
    void CursorMoved(int player, EVec3& delta);
    int fn_80007470(float left, float top, float right, float bottom);
    float GetCurZoomRatio();
    float GetNearPlane();
    float GetFarPlane();
    float GetFov();
    void CalcEyePosition(EVec3& eye, CameraParameters& params);
    int fn_80005EE4();
    int fn_80005FC8();
    int fn_800060A8();
    int fn_8000633C();
    void fn_8000650C();
    void fn_800056C8();
    void Reset();
    void fn_800058CC();
    void fn_80005984();
    void fn_8000698C();
    int fn_80007430();
    float fn_80007714(EVec3* current, EVec3 target, float speed, int mode);
    void fn_800078BC(float* current, float target, float speed, int mode);
    void fn_800079C0(float* current, float target, float speed, int mode);
    void fn_80006C58();
    void fn_80006D90();
    void fn_80006E6C();
    void SetWinPos(E3DWindow& window);
    EVec3 fn_80007DD8();

    char unkB4[0x324 - 0xB4];
    struct Unk324* unk324;
    int unk328;         // camera mode
    int unk32C;         // camera mode to return to
    int unk330;
    int unk334;
    char unk338[0x378 - 0x338];
    EVec3 unk378;       // eye position
    EVec3 unk384;
    float unk390;
    float unk394;
    CameraParameters unk398; // current
    CameraParameters unk3B0; // wanted
    unsigned int unk3C8; // interpolation mode (0-2)
    float unk3CC;
};

#endif
