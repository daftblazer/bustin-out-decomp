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
