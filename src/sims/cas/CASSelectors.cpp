#include "sims/cas/CASSelectors.h"

#include "engine/EController.h"

// 0x8001562C
CASTargetUnk533C::CASTargetUnk533C() {
    fn_800156C8();
}

// 0x80015670
CASTargetUnk533C::~CASTargetUnk533C() {
    fn_800158A4();
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
