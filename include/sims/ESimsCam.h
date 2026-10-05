#ifndef SIMS_ESIMSCAM_H
#define SIMS_ESIMSCAM_H

#include "engine/ERectF.h"
#include "engine/EMat4.h"
#include "engine/EVec3.h"
#include "engine/EController.h"
#include "sims/EGlobal.h"
#include "sims/Unk800052C8.h"
#include "sims/Unk8037D944.h"

// View window: projection and viewport of a camera. Class name from The Sims 2's
// symbol map (ESimsCam::SetWinPos(E3DWindow&)).
class E3DWindow {
public:
    void fn_80154490(float fov, float aspect, float nearPlane, float farPlane);
    void fn_801547E0(const ERectF& rect);

    char unk0[0x310]; // size inferred from ESimsCam's layout
};

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

struct Unk324 {
    void fn_80027EAC();
};

// The game camera. Class and method names follow The Sims 2's symbol map where
// the functions line up; member names are provisional.
class ESimsCam {
public:
    float GetCurZoomRatio();
    float GetNearPlane();
    float GetFarPlane();
    float GetFov();
    void CalcEyePosition(EVec3& eye, CameraParameters& params);
    void Update();
    int fn_80005EE4();
    int fn_80005FC8();
    int fn_800060A8();
    int fn_8000633C();
    void fn_8000650C();
    void fn_800056C8();
    void Reset();
    void fn_800058CC();
    void SetState(int state);
    void fn_80005984();
    void fn_8000698C();
    void fn_80006C58();
    void fn_80006D90();
    void fn_80006E6C();
    void SetWinPos(E3DWindow& window);
    EVec3 fn_80007DD8();

    int unk0;           // panel state, see SetState
    int unk4;
    int unk8;           // player index
    int unkC;
    int unk10;
    E3DWindow unk14;
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
    int unk3C8;
    float unk3CC;
};

#endif
