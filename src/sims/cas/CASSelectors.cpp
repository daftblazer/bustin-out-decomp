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

// 0x80016CF0
// Caption and value, with an arrow sprite either side when focused; each
// arrow lights up while its direction is held.
// NON_MATCHING: 12 of 278 differ: in the by-value copies of the two caption positions
// the original loads x and y through f13/f0 (first caption) and f0/f0 (second), this
// build through f0/f13. Six variants tried, including other copy-constructor forms.
void Unk80016CF0::vfn3(ERC* rc) {
    EController* controller = lbl_8037C11C->fn_8015E5FC(lbl_8037C11C->fn_8015E614(unk38));
    if (unk18 & 8) {
        unk58->fn_8003DBE8(rc);
        unk58->fn_8003C95C(1, 14.0f, 1.0f);
        unk58->unk64 = lbl_802E69C4;
        {
            EVec2 at(unk2C.x + unk4C, unk2C.z + 0.0021f);
            unk58->fn_8003D740(rc, unk50, 1, at, 1, 0, 0);
        }
        {
            EVec2 at(unk2C.x + 0.0261f + unk4C, unk2C.z + 0.0021f);
            unk58->fn_8003D740(rc, unk54, 1, at, 0, 0, 0);
        }
        EVec2 extent = unk58->fn_8003D550(unk54, 1, 0);
        EColorF color;
        if (controller->fn_8015DF98(4)) {
            color = lbl_802E69C4;
        } else {
            color = lbl_802E6964;
        }
        unk64->fn_80181824(rc);
        rc->vfn49(EVec2(unk2C.x + extent.x + 0.1561f, unk2C.z - 0.016f), EVec2(1.0f, 1.0f), color, 0.0f);
        if (controller->fn_8015DF98(3)) {
            color = lbl_802E69C4;
        } else {
            color = lbl_802E6964;
        }
        unk60->fn_80181824(rc);
        rc->vfn49(EVec2(unk2C.x + 0.124f, unk2C.z - 0.016f), EVec2(1.0f, 1.0f), color, 0.0f);
    } else {
        unk58->fn_8003DBE8(rc);
        unk58->fn_8003C95C(1, 14.0f, 1.0f);
        unk58->unk64 = lbl_802E6964;
        {
            EVec2 at(unk2C.x + unk4C, unk2C.z + 0.0021f);
            unk58->fn_8003D740(rc, unk50, 1, at, 1, 0, 0);
        }
        {
            EVec2 at(unk2C.x + 0.0261f + unk4C, unk2C.z + 0.0021f);
            unk58->fn_8003D740(rc, unk54, 1, at, 0, 0, 0);
        }
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

// 0x80017218
// Caption and value only; dimmed unless flag 0x10 is set.
// NON_MATCHING: 10 of 162 differ, the same float-register pattern as Unk80016CF0::vfn3.
void Unk80017218::vfn3(ERC* rc) {
    if (unk18 & 8) {
        unk58->fn_8003DBE8(rc);
        unk58->fn_8003C95C(1, 14.0f, 1.0f);
        unk58->unk64 = lbl_802E69C4;
        {
            EVec2 at(unk2C.x + unk4C, unk2C.z + 0.0021f);
            unk58->fn_8003D740(rc, unk50, 1, at, 1, 0, 0);
        }
        {
            EVec2 at(unk2C.x + 0.0261f + unk4C, unk2C.z + 0.0021f);
            unk58->fn_8003D740(rc, unk54, 1, at, 0, 0, 0);
        }
    } else {
        unk58->fn_8003DBE8(rc);
        unk58->fn_8003C95C(1, 14.0f, 1.0f);
        if (unk18 & 0x10) {
            unk58->unk64 = lbl_802E6964;
        } else {
            unk58->unk64 = lbl_802E69E4;
        }
        {
            EVec2 at(unk2C.x + unk4C, unk2C.z + 0.0021f);
            unk58->fn_8003D740(rc, unk50, 1, at, 1, 0, 0);
        }
        {
            EVec2 at(unk2C.x + 0.0261f + unk4C, unk2C.z + 0.0021f);
            unk58->fn_8003D740(rc, unk54, 1, at, 0, 0, 0);
        }
    }
}

// 0x800174A0
// Either direction flips between the two choices.
void Unk800176C0::vfn2() {
    EController* controller = lbl_8037C11C->fn_8015E5FC(lbl_8037C11C->fn_8015E614(unk38));
    if (controller->fn_8015E0F8(4)) {
        if (unk68) {
            lbl_8037D96C->fn_8006186C(0xCF99DB1E);
            if (unk48 == 0x30) {
                Unk800669ACResult text = lbl_802E6700.fn_800667EC("child");
                unk54 = (const unsigned short*)(text.ptr ? *text.ptr : 0);
                unk48 = 0x31;
            } else {
                Unk800669ACResult text = lbl_802E6700.fn_800667EC("adult");
                unk54 = (const unsigned short*)(text.ptr ? *text.ptr : 0);
                unk48 = 0x30;
            }
            vfn7(this, unk48);
        } else {
            lbl_8037D96C->fn_8006186C(0x3804219F);
        }
    } else if (controller->fn_8015E0F8(3)) {
        if (unk68) {
            lbl_8037D96C->fn_8006186C(0xCF99DB1E);
            if (unk48 == 0x30) {
                Unk800669ACResult text = lbl_802E6700.fn_800667EC("child");
                unk54 = (const unsigned short*)(text.ptr ? *text.ptr : 0);
                unk48 = 0x31;
            } else {
                Unk800669ACResult text = lbl_802E6700.fn_800667EC("adult");
                unk54 = (const unsigned short*)(text.ptr ? *text.ptr : 0);
                unk48 = 0x30;
            }
            vfn7(this, unk48);
        } else {
            lbl_8037D96C->fn_8006186C(0x3804219F);
        }
    }
    if (unk18 & 8) {
        vfn7(this, 0x41);
        vfn7(this, 0x40);
    }
}

// 0x800176C0
// As Unk80016CF0::vfn3 with the arrows hugging the value text; dimmed when
// not focused unless flag 0x10 is set.
// NON_MATCHING: 10 of 290 differ, the same float-register pattern as Unk80016CF0::vfn3.
void Unk800176C0::vfn3(ERC* rc) {
    EController* controller = lbl_8037C11C->fn_8015E5FC(lbl_8037C11C->fn_8015E614(unk38));
    if (unk18 & 8) {
        unk58->fn_8003DBE8(rc);
        unk58->fn_8003C95C(1, 14.0f, 1.0f);
        unk58->unk64 = lbl_802E69C4;
        {
            EVec2 at(unk2C.x + unk4C, unk2C.z + 0.0021f);
            unk58->fn_8003D740(rc, unk50, 1, at, 1, 0, 0);
        }
        {
            EVec2 at(unk2C.x + 0.0261f + unk4C, unk2C.z + 0.0021f);
            unk58->fn_8003D740(rc, unk54, 1, at, 0, 0, 0);
        }
        EVec2 extent = unk58->fn_8003D550(unk54, 1, 0);
        EColorF color;
        if (controller->fn_8015DF98(4)) {
            color = lbl_802E69C4;
        } else {
            color = lbl_802E6964;
        }
        unk64->fn_80181824(rc);
        rc->vfn49(EVec2(unk2C.x + extent.x + unk4C + 0.0301f, unk2C.z - 0.016f), EVec2(1.0f, 1.0f), color, 0.0f);
        if (controller->fn_8015DF98(3)) {
            color = lbl_802E69C4;
        } else {
            color = lbl_802E6964;
        }
        unk60->fn_80181824(rc);
        rc->vfn49(EVec2(unk2C.x + unk4C + 0.004f, unk2C.z - 0.016f), EVec2(1.0f, 1.0f), color, 0.0f);
    } else {
        unk58->fn_8003DBE8(rc);
        unk58->fn_8003C95C(1, 14.0f, 1.0f);
        if (unk18 & 0x10) {
            unk58->unk64 = lbl_802E6964;
        } else {
            unk58->unk64 = lbl_802E69E4;
        }
        {
            EVec2 at(unk2C.x + unk4C, unk2C.z + 0.0021f);
            unk58->fn_8003D740(rc, unk50, 1, at, 1, 0, 0);
        }
        {
            EVec2 at(unk2C.x + 0.0261f + unk4C, unk2C.z + 0.0021f);
            unk58->fn_8003D740(rc, unk54, 1, at, 0, 0, 0);
        }
    }
}

// 0x80017B48
// Either direction flips between the two choices.
void Unk80017D68::vfn2() {
    EController* controller = lbl_8037C11C->fn_8015E5FC(lbl_8037C11C->fn_8015E614(unk38));
    if (controller->fn_8015E0F8(4)) {
        if (unk68) {
            lbl_8037D96C->fn_8006186C(0xCF99DB1E);
            if (unk48 == 0x32) {
                Unk800669ACResult text = lbl_802E6700.fn_800667EC("female");
                unk54 = (const unsigned short*)(text.ptr ? *text.ptr : 0);
                unk48 = 0x33;
            } else {
                Unk800669ACResult text = lbl_802E6700.fn_800667EC("male");
                unk54 = (const unsigned short*)(text.ptr ? *text.ptr : 0);
                unk48 = 0x32;
            }
            vfn7(this, unk48);
        } else {
            lbl_8037D96C->fn_8006186C(0x3804219F);
        }
    } else if (controller->fn_8015E0F8(3)) {
        if (unk68) {
            lbl_8037D96C->fn_8006186C(0xCF99DB1E);
            if (unk48 == 0x32) {
                Unk800669ACResult text = lbl_802E6700.fn_800667EC("female");
                unk54 = (const unsigned short*)(text.ptr ? *text.ptr : 0);
                unk48 = 0x33;
            } else {
                Unk800669ACResult text = lbl_802E6700.fn_800667EC("male");
                unk54 = (const unsigned short*)(text.ptr ? *text.ptr : 0);
                unk48 = 0x32;
            }
            vfn7(this, unk48);
        } else {
            lbl_8037D96C->fn_8006186C(0x3804219F);
        }
    }
    if (unk18 & 8) {
        vfn7(this, 0x41);
        vfn7(this, 0x40);
    }
}

// 0x80017D68
// As Unk80016CF0::vfn3 with the arrows hugging the value text; dimmed when
// not focused unless flag 0x10 is set.
// NON_MATCHING: 10 of 290 differ, the same float-register pattern as Unk80016CF0::vfn3.
void Unk80017D68::vfn3(ERC* rc) {
    EController* controller = lbl_8037C11C->fn_8015E5FC(lbl_8037C11C->fn_8015E614(unk38));
    if (unk18 & 8) {
        unk58->fn_8003DBE8(rc);
        unk58->fn_8003C95C(1, 14.0f, 1.0f);
        unk58->unk64 = lbl_802E69C4;
        {
            EVec2 at(unk2C.x + unk4C, unk2C.z + 0.0021f);
            unk58->fn_8003D740(rc, unk50, 1, at, 1, 0, 0);
        }
        {
            EVec2 at(unk2C.x + 0.0261f + unk4C, unk2C.z + 0.0021f);
            unk58->fn_8003D740(rc, unk54, 1, at, 0, 0, 0);
        }
        EVec2 extent = unk58->fn_8003D550(unk54, 1, 0);
        EColorF color;
        if (controller->fn_8015DF98(4)) {
            color = lbl_802E69C4;
        } else {
            color = lbl_802E6964;
        }
        unk64->fn_80181824(rc);
        rc->vfn49(EVec2(unk2C.x + extent.x + unk4C + 0.0301f, unk2C.z - 0.016f), EVec2(1.0f, 1.0f), color, 0.0f);
        if (controller->fn_8015DF98(3)) {
            color = lbl_802E69C4;
        } else {
            color = lbl_802E6964;
        }
        unk60->fn_80181824(rc);
        rc->vfn49(EVec2(unk2C.x + unk4C + 0.005f, unk2C.z - 0.016f), EVec2(1.0f, 1.0f), color, 0.0f);
    } else {
        unk58->fn_8003DBE8(rc);
        unk58->fn_8003C95C(1, 14.0f, 1.0f);
        if (unk18 & 0x10) {
            unk58->unk64 = lbl_802E6964;
        } else {
            unk58->unk64 = lbl_802E69E4;
        }
        {
            EVec2 at(unk2C.x + unk4C, unk2C.z + 0.0021f);
            unk58->fn_8003D740(rc, unk50, 1, at, 1, 0, 0);
        }
        {
            EVec2 at(unk2C.x + 0.0261f + unk4C, unk2C.z + 0.0021f);
            unk58->fn_8003D740(rc, unk54, 1, at, 0, 0, 0);
        }
    }
}
