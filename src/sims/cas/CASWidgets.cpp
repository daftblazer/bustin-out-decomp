#include "sims/cas/CASWidgets.h"

void fn_80169EE8(void* ptr);

// 0x80007F88
// NON_MATCHING: same length (212), 52 differ. Same calls in the same order; the
// differences are in which saved registers hold the temporaries' addresses and in the
// order the two-float temporaries are filled.
void CASSelector::Draw(ERC* rc) {
    if (!(unk18 & 2)) {
        return;
    }
    unk78->fn_8003C95C(1, 14.0f, 1.0f);
    EVec2 extent = unk78->fn_8003D550(unk68 ? *unk68 : 0, 1, 0);
    EVec2 position;
    position.x = unk20.x * 0.5f + unk2C.x;
    position.y = extent.y * 0.5f + unk2C.z;
    EVec2 corner;
    if (unk18 & 8) {
        unk78->unk64 = lbl_802E69C4;
        float halfWidth = extent.x * 0.5f + 0.01f;
        EController* controller = lbl_8037C11C->fn_8015E5FC(lbl_8037C11C->fn_8015E614(unk38));
        if (controller->fn_8015DF98(4)) {
            unk58 = lbl_802E69C4;
        } else {
            unk58 = lbl_802E6964;
        }
        if (controller->fn_8015DF98(3)) {
            unk48 = lbl_802E69C4;
        } else {
            unk48 = lbl_802E6964;
        }
        unk80->fn_80181824(rc);
        EVec2 size;
        corner.x = position.x - halfWidth - 0.018f;
        corner.y = unk2C.z - 0.02f;
        size.x = 1.0f;
        size.y = 1.0f;
        rc->vfn49(&corner, &size, &unk48, 0.0f);
        unk84->fn_80181824(rc);
        corner.x = position.x + halfWidth;
        corner.y = unk2C.z - 0.02f;
        size.x = 1.0f;
        size.y = 1.0f;
        rc->vfn49(&corner, &size, &unk58, 0.0f);
    } else {
        unk78->unk64 = lbl_802E6964;
    }
    unk78->fn_8003DBE8(rc);
    corner.x = position.x;
    corner.y = position.y;
    unk78->fn_8003D740(rc, unk68 ? *unk68 : 0, 1, &corner, 2, 2, 0);
}

// 0x800082D8
void CASSelector::Update() {
    if (unk18 & 4) {
        vfn7(this, unk74);
        if (unk18 & 8) {
            vfn7(this, 0x41);
            vfn7(this, 0x40);
        }
        EController* controller = lbl_8037C11C->fn_8015E5FC(lbl_8037C11C->fn_8015E614(unk38));
        if (controller->fn_8015E0F8(4)) {
            if (lbl_8037C0D4) {
                lbl_8037C0D4();
            }
            if (unk6C) {
                vfn7(this, unk6C);
            }
        } else if (controller->fn_8015E0F8(3)) {
            if (lbl_8037C0D4) {
                lbl_8037C0D4();
            }
            if (unk70) {
                vfn7(this, unk70);
            }
        }
    }
    fn_801887C8();
}

// 0x80008440
void CASSelector::ReleaseResources() {
    fn_801767FC(unk78);
    unk78 = 0;
    fn_801767FC(unk7C);
    unk7C = 0;
    fn_801767FC(unk80);
    unk80 = 0;
    fn_801767FC(unk84);
    unk84 = 0;
}

// 0x8000849C
CASSpinner::CASSpinner(unsigned char message) {
    unk48 = 0.0f;
    unk4C = EVec3(0.0f);
    unk58 = 0;
    unk5C = lbl_8033FF34.fn_80177628(0x6D1F0956, 0, 0);
    unk59 = message;
}

// 0x80008540
CASSpinner::~CASSpinner() {
    lbl_8033FF34.fn_801778B4(0x6D1F0956);
    unk5C = 0;
}

// 0x800085A0
// NON_MATCHING: outline only, 31 instructions vs 122. The original builds a rotation matrix
// from unk48, sets up a light (three- and four-element arrays with empty constructors,
// a position, a colour and a normalized direction), then draws the model resource.
void CASSpinner::Draw(ERC* rc) {
    if ((unk18 & 2) && (unk18 & 8)) {
        EMat4 mat;
        mat.fn_801B2AFC();
        mat.fn_801B3388(unk48);
        rc->vfn28(&mat, 1);
        unk5C->fn_8017CC58(rc);
    }
}

// 0x80008788
void CASSpinner::Update() {
    if (unk18 & 4) {
        EController* controller = lbl_8037C11C->fn_8015E5FC(lbl_8037C11C->fn_8015E614(unk38));
        unk48 = lbl_8037BFC8 * 3.0f + unk48;
        float wrapped;
        if (unk48 < 0.0f) {
            wrapped = 6.2831855f;
        } else if (unk48 > 6.2831855f) {
            wrapped = 0.0f;
        } else {
            wrapped = unk48;
        }
        unk48 = wrapped;
        if (wrapped > 6.2f) {
            unk48 = wrapped - 6.2f;
        }
        if (controller->fn_8015E0F8(5)) {
            vfn7(this, unk59);
        }
        if (unk18 & 8) {
            vfn7(this, 0x41);
            vfn7(this, 0x42);
        }
    }
}

// 0x800088BC
CASSelector::~CASSelector() {
    ReleaseResources();
}

// 0x80008914
void CASSelector::operator delete(void* ptr) {
    fn_80169EE8(ptr);
}
