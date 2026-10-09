#include "engine/e_storable.h"
#include "engine/e_resource.h"
#include "engine/e_rfont.h"
#include "engine/e_texture.h"
#include "engine/e_shader.h"
#include "engine/e_rshader.h"
#define EOR_BUILD_TIME "21:41:33"
#include "engine/e_engine.h"
#include "engine/e_rcharacter.h"
#include "engine/e_submodelshader.h"
#include "engine/e_submodel.h"
#include "engine/e_rmodel.h"
#include "engine/e_ranim.h"
#include "sims/Unk80297B74.h"
#include "sims/Unk80044D84.h"
#include "sims/Unk800401FCPrivate.h"

// The timed dialog (first source file of the unit at 0x80044D84; the other two are
// the action queue manager at 0x800454AC and the level file at 0x80049ADC).

// The camera's mode word (its virtual base, at +0x1F0): 8 to 11 are the build modes.
inline bool IsBuildCameraMode() {
    int mode = *(int*)((char*)lbl_802E6700.unkBC + 0x1F0);
    bool build = false;
    if (mode == 8 || mode == 10 || mode == 11 || mode == 9) {
        build = true;
    }
    return build;
}

// 0x80044D84
// Sets the dialog up from its description, as Unk80040274's slot 22 does, without
// buttons, and starts its timer.
void Unk80044D84::vfn26(Unk800424F0Source* source, unsigned char* b) {
    int who = b[5] & 0xF;
    if (who == 1) {
        unk70 = 0;
    } else if (who == 2) {
        unk70 = 1;
    } else {
        unk70 = 2;
    }
    unk50->unk10.length();
    Unk8023CDDC strings;
    unk7C = b[5] >> 4;
    unk78 = (b[7] >> 4) & 7;
    fn_8023CE04(strings.table);
    strings.table = 0;
    strings.table = fn_8023CDDC();
    if (source) {
        unk84 = source->unk4;
    } else {
        unk84 = 0;
    }
    int set;
    if (source) {
        set = fn_801C27C8(source->unkC);
    } else {
        set = 0;
    }
    strings.table->vfn19(set, 0x12D, 0);
    BString2 body;
    lbl_802E6700.unkEC->SetSize(true, lbl_8037B504, 1.0f);
    unk50->unk10.length();
    fn_80043034(strings.table, &body, b[2], 0, 1);
    unk50->unkC = (const unsigned short*)TextOf(strings.table->vfn6(b[2]));
    int state = 0;
    unk68->vfn44(&body, source, 0, &state, 0);
    fn_80043110(&body, 1);
    fn_80044F6C();
}

// 0x80044F6C
void Unk80044D84::fn_80044F6C() {
    unkF4 = 1;
    unkF8 = 10.0f;
}

// Moves the rectangle towards where it is going by how far the fade has got, and
// snaps it there when it is close.
inline void Blend(Unk8004024C* fade) {
    float t = fade->unk30.Fraction();
    float amount;
    if (t < 0.0f) {
        amount = 0.0f;
    } else if (t > 1.0f) {
        amount = 1.0f;
    } else {
        amount = t;
    }
    float* from = &fade->unk0.unk0;
    float* now = &fade->unk20.unk0;
    float* to = &fade->unk10.unk0;
    for (int i = 0; i < 4; i++) {
        now[i] = from[i] + (to[i] - from[i]) * amount;
    }
    float difference = fade->unk20.SumSq() - fade->unk10.SumSq();
    if (!(difference >= 0.0f)) {
        difference = -difference;
    }
    if (difference <= 0.0001f) {
        fade->unk20 = fade->unk10;
    }
}

// 0x80044F84
void Unk80044D84::vfn2() {
    if (IsBuildCameraMode()) {
        unkF4 = 0;
        unkF8 = 0.0f;
        return;
    }
    if (unkF4 == 0) {
        return;
    }
    if (IsBuildCameraMode()) {
        unkF4 = 0;
        unkF8 = 0.0f;
    } else if (unkF8 <= 0.0f) {
        unkF4 = 0;
        unkF8 = 0.0f;
    }
    Blend(unk4C);
    unkF8 -= lbl_8037BFC8;
}

// 0x80045170
void Unk80044D84::vfn3(ERC* rc) {
    if (unkF4 == 0) {
        return;
    }
    if (lbl_802E6700.fn_800655C4() == 0) {
        return;
    }
    if (lbl_802E6700.unkBC != 0 && IsBuildCameraMode()) {
        return;
    }
    unk4C->unk20 = unk4C->unk10;
    lbl_802E6700.unkE4->fn_80181824(rc);
    float top = lbl_8037ED50;
    float bottom = 0.32f - top;
    float spacing = lbl_8037B550 * lbl_802E6700.unkEC->GetLineSpacing(0);
    if (unk70 == 0) {
        unk64->fn_8018B584(ERectF(0.28f, -0.05f, lbl_8037ED54 - 0.025f, bottom));
        unk50->unk24 = spacing + spacing + top;
    } else if (unk70 == 1) {
        unk64->fn_8018B584(ERectF(lbl_8037ED4C + 0.05f, 0.77f, 0.725f, 1.05f));
        unk50->unk24 = unk64->Top() + 0.02f;
    }
    EVec2 from(unk64->Left(), unk64->Top());
    EVec2 to(unk64->Right(), unk64->Bottom());
    fn_800411A0(rc, from.x, from.y, to.x, to.y, 1.0f);
    if (unk4C->IsStill()) {
        fn_800411A8(rc, 0);
    }
}

// 0x800453FC
Unk80044D84::~Unk80044D84() {
}

// 0x8004544C
void Unk80044D84::operator delete(void* ptr) {
    fn_80169EE8(ptr);
}
