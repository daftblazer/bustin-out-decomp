#include "sims/ESimsCam.h"

// Camera tuning values (.sdata, 0x8037B3FC onwards).
int lbl_8037B3FC = 2;
float lbl_8037B400 = 65.0f;
float lbl_8037B404 = 35.0f; // zoom distance, far limit
float lbl_8037B408 = 8.0f;  // zoom distance, near limit
float lbl_8037B40C = 25.0f;
float lbl_8037B410 = 56.0f;
float lbl_8037B414 = 15.0f;
float lbl_8037B418 = 5.0f;
float lbl_8037B41C = 0.0f;
float lbl_8037B420 = 25.0f;
float lbl_8037B424 = 35.0f;
float lbl_8037B428 = 8.0f;
float lbl_8037B42C = 55.0f;  // field of view at the near zoom limit
float lbl_8037B430 = 62.0f;  // field of view at the far zoom limit
float lbl_8037B434 = 200.0f; // far plane
float lbl_8037B438 = 2.0f;   // near plane at the near zoom limit
float lbl_8037B43C = 10.0f;  // near plane at the far zoom limit

// 0x8000562C
float ESimsCam::GetCurZoomRatio() {
    return (unk3A4 - lbl_8037B408) / (lbl_8037B404 - lbl_8037B408);
}

// 0x80005648
float ESimsCam::GetNearPlane() {
    float ratio = GetCurZoomRatio();
    return lbl_8037B43C * ratio + lbl_8037B438 * (1.0f - ratio);
}

// 0x80005684
float ESimsCam::GetFarPlane() {
    return lbl_8037B434;
}

// 0x8000568C
float ESimsCam::GetFov() {
    float ratio = GetCurZoomRatio();
    return lbl_8037B430 * ratio + lbl_8037B42C * (1.0f - ratio);
}

// 0x800056C8
void ESimsCam::fn_800056C8() {
    if (!lbl_802E6700.fn_800655C4()) {
        return;
    }
    float fov = GetFov();
    int height = lbl_8037C198->vfn39();
    int width = lbl_8037C198->vfn38();
    fov *= (float)height;
    fov /= (float)width;
    float aspect = lbl_8037C198->vfn37();
    float nearPlane = GetNearPlane();
    float farPlane = GetFarPlane();
    unk14.fn_80154490(fov, aspect, nearPlane, farPlane);
    SetWinPos(unk14);
    unk14.fn_801547E0(ERectF(0.0f, 0.0f, 1.0f, 1.0f));
}

// 0x80005838
void ESimsCam::Reset() {
    unk3CC = 0.0f;
    unk334 = 0;
    unkC = 0;
    unk3C8 = 0;
    lbl_802E6700.unkA8[unk8] = unk324;
    lbl_8037B408 = lbl_8037B428;
    lbl_8037B404 = lbl_8037B424;
    fn_80006D90();
    unk328 = lbl_8037B3FC;
    unk32C = lbl_8037B3FC;
    unk390 = lbl_8037B414;
    unk394 = lbl_8037B400;
    unk330 = 0;
}

// 0x800058CC
void ESimsCam::fn_800058CC() {
    unk324 = 0;
    lbl_802E6700.unkA8[unk8] = 0;
}

// 0x800058F0
void ESimsCam::SetState(int state) {
    unk0 = state;
    switch (state) {
    case 7:
    case 8:
    case 10:
    case 11:
        if (unk328 == 4) {
            unk328 = unk32C;
        }
        // fallthrough
    case 1:
    case 2:
        unk334 = 1;
        break;
    case 0:
    case 3:
    case 4:
    case 6:
    case 9:
        unk334 = 0;
        break;
    case 5:
    default:
        if (unk328 == 4) {
            unk328 = unk32C;
        }
        unk334 = 0;
        break;
    }
}

// 0x80005984
void ESimsCam::fn_80005984() {
    if (lbl_802E6700.unk170 == 0) {
        return;
    }
    if (unk328 == 3) {
        unk328 = 2;
        fn_80006E6C();
        lbl_802E6700.unkBC->vfn7(0, 0x18);
    } else {
        unk3A0 = unk380;
        unk328 = 3;
        lbl_802E6700.unkBC->vfn7(0, 0x17);
    }
}
