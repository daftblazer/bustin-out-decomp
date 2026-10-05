#include "sims/cas/CASSelectors.h"

#include "engine/EController.h"
#include "engine/ResourceManagers.h"
#include "sims/EGlobal.h"

// 0x8001562C
CASTargetUnk533C::CASTargetUnk533C() {
    fn_800156C8();
}

// 0x80015670
CASTargetUnk533C::~CASTargetUnk533C() {
    fn_800158A4();
}

// 0x800156C8
void CASTargetUnk533C::fn_800156C8() {
    unk48 = 0;
    unk49 = 0;
    unk4A = 0;
    unk80 = 0;
    unk4C = 0.12f;
    unk50 = 0.267f;
    Unk80340AB8* manager = &lbl_80340AB8;
    unkD4 = manager->fn_80177628(0xA25EBA9A, 0, 0);
    unkD8 = manager->fn_80177628(0xE3E852F9, 0, 0);
    unkDC = manager->fn_80177628(0x19E76F9A, 0, 0);
    unk7C = lbl_8033F964.fn_80177628(lbl_802E6700.fn_800655D8(), 0, 0);
    unk54 = lbl_802E6964;
    unk64 = lbl_802E6964;
    // Bar brightness ramps: 0.1 to 1.0 going out from the centre, then back.
    int i;
    for (i = 1; i <= 10; i++) {
        unk84[i - 1] = (float)i / 10.0;
    }
    for (i = 10; i > 0; i--) {
        unk84[20 - i] = (float)i / 10.0;
    }
}

// 0x800158A4
void CASTargetUnk533C::fn_800158A4() {
    fn_801767FC(unkD4);
    unkD4 = 0;
    fn_801767FC(unkD8);
    unkD8 = 0;
    fn_801767FC(unkDC);
    unkDC = 0;
    fn_801767FC(unk7C);
    unk7C = 0;
}

// 0x80015900
unsigned char CASTargetUnk533C::fn_80015900() {
    return unk48;
}

// 0x80015908
void CASTargetUnk533C::fn_80015908(int value) {
    if (value >= 0 && value <= 10) {
        unk48 = value;
        fn_8001593C(value);
    }
}

// 0x8001593C
void CASTargetUnk533C::fn_8001593C(int value) {
    if (value == 0) {
        unk49 = 0;
        unk4A = 0;
    } else if (value >= 1 && value <= 5) {
        unk49 = 6 - value;
        unk4A = 0;
    } else if (value >= 6 && value <= 10) {
        unk4A = value - 5;
        unk49 = 0;
    }
}

// 0x8001633C
void CASTargetUnk533C::vfn2() {
    if (unk18 & 4) {
        if (unk18 & 8) {
            vfn7(this, 0x41);
            vfn7(this, 0x40);
        }
        EController* controller = lbl_8037C11C->fn_8015E5FC(lbl_8037C11C->fn_8015E614(unk38));
        if (controller->fn_8015E0F8(4)) {
            vfn7(this, 0x34);
        } else if (controller->fn_8015E0F8(3)) {
            vfn7(this, 0x35);
        }
        fn_801887C8();
    }
}

// 0x80016448
Unk80016448::Unk80016448() {
    fn_800164D4();
}

// 0x8001648C
Unk80016448::~Unk80016448() {
    fn_8001680C();
}

// 0x800164D4
void Unk80016448::fn_800164D4() {
    unk48 = 0;
    Unk800669ACResult first = lbl_802E6700.fn_800667EC("no sign");
    unk4C[0] = first.ptr ? *first.ptr : 0;
    unk4C[1] = GetText("aries");
    unk4C[2] = GetText("taurus");
    unk4C[3] = GetText("gemini");
    unk4C[4] = GetText("cancer");
    unk4C[5] = GetText("leo");
    unk4C[6] = GetText("virgo");
    unk4C[7] = GetText("libra");
    unk4C[8] = GetText("scorpio");
    unk4C[9] = GetText("sagitarius");
    unk4C[10] = GetText("capricorn");
    unk4C[11] = GetText("aquarius");
    unk4C[12] = GetText("pisces");
    unk80 = lbl_8033F964.fn_80177628(lbl_802E6700.fn_800655D8(), 0, 0);
    Unk80340AB8* manager = &lbl_80340AB8;
    unk84 = manager->fn_80177628(0xA25EBA9A, 0, 0);
    unk88 = manager->fn_80177628(0xE3E852F9, 0, 0);
    unk8C = manager->fn_80177628(0x19E76F9A, 0, 0);
}

// 0x8001680C
void Unk80016448::fn_8001680C() {
    fn_801767FC(unk80);
    unk80 = 0;
    fn_801767FC(unk84);
    unk84 = 0;
    fn_801767FC(unk88);
    unk88 = 0;
    fn_801767FC(unk8C);
    unk8C = 0;
}

// 0x80016BD4
void Unk80016448::vfn2() {
    EController* controller = lbl_8037C11C->fn_8015E5FC(lbl_8037C11C->fn_8015E614(unk38));
    if (controller->fn_8015E0F8(4)) {
        lbl_8037D96C->fn_8006186C(0xCF99DB1E);
        vfn7(this, 0x36);
    } else if (controller->fn_8015E0F8(3)) {
        lbl_8037D96C->fn_8006186C(0xCF99DB1E);
        vfn7(this, 0x37);
    }
    if (unk18 & 8) {
        vfn7(this, 0x41);
        vfn7(this, 0x40);
    }
}

// 0x80017148
void Unk80016CF0::fn_80017148() {
    fn_801767FC(unk58);
    unk58 = 0;
    fn_801767FC(unk5C);
    unk5C = 0;
    fn_801767FC(unk60);
    unk60 = 0;
    fn_801767FC(unk64);
    unk64 = 0;
}

// 0x800171A4
void Unk80017218::vfn2() {
    if (unk18 & 8) {
        vfn7(this, 0x43);
        vfn7(this, 0x40);
    }
}
