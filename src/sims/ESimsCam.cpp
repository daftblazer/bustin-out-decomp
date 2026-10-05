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

// Reference camera rig: an eye position and the point it looks at. The eye
// offset for any target is derived from the direction between them.
EVec3 lbl_802E57B8(0.0f, 0.0f, 0.0f);
EVec3 lbl_802E57C4(10.0f, 10.0f, 0.0f);
EVec3 lbl_802E57D0(0.0f, 0.0f, 1.0f);

// 0x8000562C
float ESimsCam::GetCurZoomRatio() {
    return (unk398.unkC - lbl_8037B408) / (lbl_8037B404 - lbl_8037B408);
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
    fn_80154490(fov, aspect, nearPlane, farPlane);
    SetWinPos(*this);
    fn_801547E0(ERectF(0.0f, 0.0f, 1.0f, 1.0f));
}

// 0x80005838
void ESimsCam::Reset() {
    unk3CC = 100.0f;
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
    mPanelState = state;
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
        unk398.unk0.z = unk378.z;
        unk328 = 3;
        lbl_802E6700.unkBC->vfn7(0, 0x17);
    }
}

// 0x80005A34
// NON_MATCHING: 2 of 300 instructions, swapped. At 0x80005CC4 the original loads the
// player index (unk8) before forming the address of lbl_802E6700 for the per-player
// lookup; this loads them the other way round.
void ESimsCam::Update() {
    lbl_8037B408 = lbl_8037B428;
    lbl_8037B404 = lbl_8037B424;
    if (mPanelState != 1) {
        if (mPanelState != 3) {
            if (mPanelState != 4) {
                goto other;
            }
        }
    } else {
        unk330 = 0;
        if (unk328 == 3) {
            unk10 = fn_8000633C();
        } else {
            int a = fn_80005EE4();
            int b = fn_80005FC8();
            int c = fn_800060A8();
            unk10 = a != 0 || b != 0 || c != 0;
        }
    }
    fn_8000650C();
    return;

other:
    unk10 = 0;
    if (unk334 == 0) {
        EController* controller = lbl_8037C11C->fn_8015E5FC(lbl_8037C11C->fn_8015E614(unk8));
        float x = controller->fn_8015DEE4(0, 0);
        float y = controller->fn_8015DEE4(0, 1);
        float moveX;
        if (x < 0.0f) {
            moveX = x * -x;
        } else {
            moveX = x * x;
        }
        if (y < 0.0f) {
            y = y * -y;
        } else {
            y = y * y;
        }
        EVec3 move(moveX * unk390 * lbl_8037BFC8, y * unk390 * lbl_8037BFC8, 0.0f);
        int blocked;
        int pressed = lbl_8037D944->vfn6(0x28);
        if (lbl_802F76DC.unk0 != 0) {
            pressed = 0;
        }
        if (pressed != 0 && unk328 != 4) {
            unk32C = unk328;
            unk328 = 4;
            fn_80006E6C();
            if (unk328 == 4) {
                lbl_8037D96C->fn_8006186C(0x61C374D4);
            } else {
                lbl_8037D96C->fn_8006186C(0x3804219F);
            }
        } else {
            if (pressed == 0 && (move.x != 0.0f || move.y != 0.0f) && unk328 == 4) {
                goto restore;
            }
            if (pressed == 0) {
                blocked = 0;
                if (mPanelState == 8 || mPanelState == 10 || mPanelState == 11 || mPanelState == 9) {
                    blocked = 1;
                }
                if (!blocked && controller->fn_8015E0F8(8)) {
                    if (unk328 != 3 && unk328 != 4 && lbl_802E6700.GetUnk9C(unk8) != 0 &&
                        !lbl_802E6700.GetUnk9C(unk8)->unk0->vfn88(0x22) &&
                        lbl_802E6700.GetUnk9C(unk8)->unk0->vfn64()) {
                        unk330 = 1;
                        fn_80006E6C();
                        unk32C = unk328;
                        unk328 = 4;
                        lbl_8037D96C->fn_8006186C(0x61C374D4);
                        goto after;
                    }
                restore:
                    unk328 = unk32C;
                    lbl_8037D96C->fn_8006186C(0x61C374D4);
                    goto after;
                }
            }
            if (lbl_802E686C.unk0 != 0) {
                if (controller->fn_8015E0F8(9) && unk328 != 3) {
                    unk330 = 1;
                    if (unk328 == 1) {
                        unk328 = 2;
                    } else {
                        unk328 = 1;
                    }
                }
            }
        }
    after:
        if (lbl_802E686C.unk0 == 0 && unk328 == 1) {
            unk328 = 2;
        }
    }
    if (unk330 == 0) {
        int moved = 0;
        if (unk328 != 3) {
            if (unk328 != 4) {
                int a = fn_80005EE4();
                int b = fn_80005FC8();
                int c = fn_800060A8();
                if (a != 0 || b != 0 || c != 0) {
                    moved = 1;
                }
            } else {
                int a = fn_80005EE4();
                int b = fn_80005FC8();
                int c = fn_800060A8();
                if (a != 0 || b != 0 || c != 0) {
                    moved = 1;
                }
                fn_80006E6C();
            }
        } else {
            moved = fn_8000633C();
        }
        unk10 = moved;
    }
    unk330 = 0;
    fn_8000650C();
}

// 0x80005EE4
int ESimsCam::fn_80005EE4() {
    if (unk324 != 0) {
        float input = lbl_8037C11C->fn_8015E5FC(lbl_8037C11C->fn_8015E614(unk8))->fn_8015DEE4(1, 0);
        if (input < 0.0f) {
            input = input * -input;
        } else {
            input = input * input;
        }
        input = input * lbl_8037BFC8 * unk394;
        if (input != 0.0f) {
            unk398.unk10 = unk398.unk10 + input;
            float wrapped;
            if (unk398.unk10 < 0.0f) {
                wrapped = 360.0f;
            } else if (unk398.unk10 > 360.0f) {
                wrapped = 0.0f;
            } else {
                wrapped = unk398.unk10;
            }
            unk398.unk10 = wrapped;
            return 1;
        }
    }
    return 0;
}

// 0x80005FC8
int ESimsCam::fn_80005FC8() {
    if (unk328 == 1 || (unk328 == 4 && unk32C == 1)) {
        if (unk324 != 0) {
            float input = lbl_8037C11C->fn_8015E5FC(lbl_8037C11C->fn_8015E614(unk8))->fn_8015DEE4(1, 1) * lbl_8037BFC8 * unk394;
            if (input != 0.0f) {
                unk398.unk14 = unk398.unk14 + input;
                float clamped;
                if (unk398.unk14 < 20.0f) {
                    clamped = 20.0f;
                } else if (unk398.unk14 > 88.0f) {
                    clamped = 88.0f;
                } else {
                    clamped = unk398.unk14;
                }
                unk398.unk14 = clamped;
                return 1;
            }
        }
    }
    return 0;
}

// 0x800060A8
// NON_MATCHING: 164 instructions vs 165; everything up to the cursor-distance block
// matches. There the original forms each vector's address in a scratch register and
// copies it to a saved one (addi r3; mr r28, r3), where this computes it straight into
// the saved register, and the saved registers are numbered differently.
int ESimsCam::fn_800060A8() {
    if (unk328 == 2 || (unk328 == 4 && unk32C == 2)) {
        if (unk324 != 0) {
            float input = lbl_8037C11C->fn_8015E5FC(lbl_8037C11C->fn_8015E614(unk8))->fn_8015DEE4(1, 1);
            if (input != 0.0f) {
                float maxZoom;
                if (lbl_802E6700.fn_800655C4()) {
                    maxZoom = lbl_8037B404 * 0.65f;
                } else {
                    maxZoom = lbl_8037B404;
                }
                unk398.unkC = unk398.unkC - input;
                unk398.unkC = unk398.unkC < lbl_8037B408 ? lbl_8037B408 : (unk398.unkC > maxZoom ? maxZoom : unk398.unkC);
                unk398.unk14 = (unk398.unkC - lbl_8037B408) / (maxZoom - lbl_8037B408) * (lbl_8037B410 - lbl_8037B40C) + lbl_8037B40C;
                if (unk3C8 != 0 && input > 0.0f) {
                    EVec3 offset = unk398.unk0 - fn_80007DD8();
                    float distance = offset.Length();
                    float limit = 0.0f;
                    if (GetCurZoomRatio() > 0.1f) {
                        limit = (GetCurZoomRatio() - 0.1f) * 10.0f * (GetCurZoomRatio() - 0.1f);
                    }
                    if (distance > limit) {
                        unk3CC = 100.0f;
                        unk398.unk0 = fn_80007DD8() + limit * offset * (1.0f / distance);
                    }
                }
                return 1;
            }
        }
    }
    return 0;
}

// 0x8000650C
void ESimsCam::fn_8000650C() {
    unk390 = (unk398.unkC - lbl_8037B408) / (lbl_8037B404 - lbl_8037B408) * (lbl_8037B414 - lbl_8037B418) + lbl_8037B418;
    fn_801547E0(ERectF(0.0f, 0.0f, 1.0f, 1.0f));
    float fov = GetFov();
    fov *= (float)lbl_8037C198->unk18;
    fov /= (float)lbl_8037C198->unk14;
    float aspect = lbl_8037C198->vfn37();
    float nearPlane = GetNearPlane();
    float farPlane = GetFarPlane();
    fn_80154490(fov, aspect, nearPlane, farPlane);
    if (unk328 != 3) {
        fn_8000698C();
        if (unk3C8 == 0) {
            fn_80006C58();
        }
    } else {
        SetWinPos(*this);
    }
}

// 0x80006688
// NON_MATCHING: 197 instructions vs 193. Same operations in the same order, but the
// original writes the first two temporaries (`back` and the rotation axis) straight to
// the stack and keeps only one vector address in a saved register (r29); this keeps two.
void ESimsCam::CalcEyePosition(EVec3& eye, CameraParameters& params) {
    EMat4 mat;
    mat.fn_801B2AFC();
    EVec3 dir = lbl_802E57C4 - lbl_802E57B8;
    EVec3 back(-dir.x, -dir.y, 0.0f);
    EVec3 axis = EVec3(-dir.y, dir.x, 0.0f).Normalize();
    mat.fn_801B3024(axis, params.unk14 * 0.017453292f);
    mat.fn_801B3388(params.unk10 * 0.017453292f);
    back = back * mat;
    back += lbl_802E57B8 + dir;
    eye = back;
    EVec3 toEye = (eye - lbl_802E57C4).Normalize();
    eye = params.unk0 + toEye * params.unkC;
}

// 0x80006D90
void ESimsCam::fn_80006D90() {
    unk398.unk0 = lbl_802E57C4;
    unk384 = lbl_802E57D0;
    unk3B0.unk0 = lbl_802E57C4;
    unk3B0.unk14 = lbl_8037B420;
    unk3B0.unk10 = lbl_8037B41C;
    unk3B0.unkC = lbl_8037B428;
    unk398.unk14 = lbl_8037B420;
    unk398.unk10 = lbl_8037B41C;
    unk398.unkC = lbl_8037B428;
    CalcEyePosition(unk378, unk3B0);
    if (unk324) {
        unk324->fn_80027EAC();
    }
    fn_8000650C();
    fn_80006E6C();
}

// 0x8000698C
void ESimsCam::fn_8000698C() {
    if (unk324 != 0) {
        int notState1 = 1;
        if (mPanelState == 1) {
            notState1 = 0;
        }
        if (notState1 && lbl_802E6700.fn_800655C4()) {
            unk398.unk0 = fn_80007DD8();
        }
        if (unkC != 0) {
            unk398.unk0 = fn_80007DD8();
        }
        unk398.unk0.z = 0.25f;
    }
    switch (unk3C8) {
    case 0:
        fn_80007714(&unk3B0.unk0, unk398.unk0, 0.0f, 2);
        fn_800078BC(&unk3B0.unkC, unk398.unkC, 2.0f, 1);
        fn_800079C0(&unk3B0.unk10, unk398.unk10, 3.0f, 1);
        fn_800079C0(&unk3B0.unk14, unk398.unk14, 2.5f, 1);
        break;
    case 1: {
        float speed;
        if (lbl_802E6700.fn_800655C4()) {
            speed = 5.0f;
        } else {
            speed = 2.0f;
        }
        fn_80007714(&unk3B0.unk0, unk398.unk0, speed, 1);
        fn_800078BC(&unk3B0.unkC, unk398.unkC, 2.0f, 1);
        fn_800079C0(&unk3B0.unk10, unk398.unk10, 3.0f, 1);
        fn_800079C0(&unk3B0.unk14, unk398.unk14, 2.5f, 1);
        break;
    }
    case 2: {
        float speed;
        if (lbl_802E6700.fn_800655C4()) {
            speed = 5.0f;
        } else {
            speed = 2.0f;
        }
        float remaining = fn_80007714(&unk3B0.unk0, unk398.unk0, speed, 1);
        fn_800078BC(&unk3B0.unkC, unk398.unkC, 2.0f, 1);
        fn_800079C0(&unk3B0.unk10, unk398.unk10, 3.0f, 1);
        fn_800079C0(&unk3B0.unk14, unk398.unk14, 2.5f, 1);
        if (unkC != 0 && remaining < 1.5f) {
            unkC = 0;
        }
        break;
    }
    }
    SetWinPos(*this);
}

// 0x80006C58
void ESimsCam::fn_80006C58() {
    if (unk324 != 0) {
        const EVec3& cursor = fn_80007DD8();
        if (fn_80007430()) {
            EVec3 dir = (unk398.unk0 - cursor).Normalize();
            unk324->vfn4(cursor + unk390 * lbl_8037BFC8 * dir);
        }
    }
}

// 0x80007184
void ESimsCam::GetPos(EVec3& eye, EVec3& target, EVec3& unk) {
    eye = unk378;
    target = unk398.unk0;
    unk = unk384;
}

// 0x80007430
int ESimsCam::fn_80007430() {
    return fn_80007470(0.15f, 0.3f, 0.85f, 0.75f);
}

// 0x80007470
// NON_MATCHING: 23 of 46 instructions. The original keeps the screen position at the
// bottom of the frame (read straight off the stack) with the cursor temporary above it,
// its address held in r29 from before the call; this lays the two out the other way.
int ESimsCam::fn_80007470(float left, float top, float right, float bottom) {
    EVec2 screen;
    fn_80156130(fn_80007DD8(), &screen);
    int flags = 0;
    if (screen.x < left) {
        flags = 1;
    }
    if (screen.x > right) {
        flags |= 2;
    }
    if (screen.y < top) {
        flags |= 4;
    }
    if (screen.y > bottom) {
        flags |= 8;
    }
    return flags;
}

// 0x80007DD8
EVec3 ESimsCam::fn_80007DD8() {
    EVec3 position = *unk324->fn_8002D2C8();
    position.z = 0.25f;
    return position;
}

// 0x80006E6C
// NON_MATCHING: 197 instructions vs 198, 52 differ. The frame is 8 bytes smaller than
// the original's, so later temporaries sit 8 bytes lower, and the original zeroes
// position.z through a saved pointer to `position` where this writes the stack slot.
void ESimsCam::fn_80006E6C() {
    Unk800053D4Owner* player = lbl_802E6700.unk9C[unk8];
    if (player == 0) {
        return;
    }
    EVec3 position;
    player->vfn37()->vfn34(2, &position);
    position.z = 0.0f;
    if (position.LengthSquared() < 0.5f) {
        position = lbl_802E6700.unk9C[unk8]->unk0->vfn117();
        position.z = 0.0f;
    }
    if (unk324 != 0) {
        unk324->vfn4(position);
    }
    float limit = (float)(lbl_8037D990->vfn6() - 1);
    if (position.x >= 1.0f && position.x <= limit && position.y >= 1.0f && position.y <= limit) {
        EVec3 dir = unk398.unk0 - unk378;
        dir.z = 0.0f;
        dir.Normalize();
        unk398.unk0 = position + dir * 2.0f;
        unk3CC = 100.0f;
        EVec3 moved = unk398.unk0 - unk3B0.unk0;
        if (moved.LengthSquared() > 100.0f) {
            unk3B0.unk0 = unk398.unk0;
        }
        CalcEyePosition(unk378, unk3B0);
        fn_8000650C();
    } else if (unk328 == 4) {
        unk328 = unk32C;
    }
}
