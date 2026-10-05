#include "sims/cas/CASTarget.h"

void fn_8000C3C8();
int fn_80014B6C(int, int);

// 0x80008AA0
CASTarget::CASTarget() {
    unk52C0 = 0;
    unk48 = 0;
    unk45A8 = lbl_802E6700.unk17C;
    unk52C4 = lbl_802E6700.unk90;
}

// 0x8000AF70
// The view-matrix pair below may belong to a different class with a matrix at
// offset 0: the product is taken with `this` as the left operand.
void CASTarget::fn_8000AF70(E3DWindowLike* window) {
    unk5C.unk30.Copy64(window->unkA0);
    EMat4 product;
    product.fn_801B2888((EMat4*)this, &window->unkA0);
    window->fn_801546D8(&product);
}

// 0x8000B03C
void CASTarget::fn_8000B03C(E3DWindowLike* window) {
    window->fn_801546D8(&unk5C.unk30);
}

// 0x8000C3C8
// Runs in the background: loads the screen's resources in four steps.
void fn_8000C3C8() {
    CASTarget* target = lbl_8037CA80;
    target->fn_8000C5DC();
    lbl_8037CA88 += 0.1f;
    target->fn_8000CBD8();
    lbl_8037CA88 += 0.1f;
    target->fn_8000CC40();
    lbl_8037CA88 += 0.1f;
    target->fn_8000CD04();
    lbl_8037CA88 += 0.1f;
    lbl_8037D9B8 = 1;
}

// 0x8000C458
void CASTarget::fn_8000C458() {
    lbl_8037CA80 = this;
    lbl_8037D9B8 = 0;
    lbl_8037D13C->vfn8(fn_8000C3C8);
}

// 0x8000C4A4
int CASTarget::fn_8000C4A4() {
    if (lbl_8037CA80 == 0) {
        lbl_8037CA88 = 0.0f;
        fn_800183D0();
        fn_8000C458();
        lbl_8037CA84 = 1;
    } else if (lbl_8037CA84 == 0) {
        if (unk52C8) {
            lbl_8037CA80 = 0;
            lbl_8037CA88 += 0.1f;
            return 0;
        }
    } else {
        int done;
        {
            Unk801BE528 lock;
            lock.fn_801BE5C4(0x10);
            done = lbl_8037D9B8;
        }
        if (done) {
            lbl_8037CA84 = 0;
            fn_8000C588();
            lbl_8037CA88 += 0.1f;
        }
    }
    return 1;
}

// 0x8000C588
void CASTarget::fn_8000C588() {
    unk52C8 = 0;
    EGlobal* global = &lbl_802E6700;
    ((UnkViewer*)global->unk90)->fn_8010826C(this);
    fn_801066A0(global->unk90, "create", 0);
}

// 0x8000CBD8
void CASTarget::fn_8000CBD8() {
    Unk80340AB8* manager = &lbl_80340AB8;
    unk4C = manager->fn_80177628(0xAB5FDCCC, 0, 0);
    unk50 = manager->fn_80177628(0x0F303F75, 0, 0);
}

// 0x8000CC40
void CASTarget::fn_8000CC40() {
    Unk803401C4* manager = &lbl_803401C4;
    unk4574 = manager->fn_80177628(0x2A2AF469, 0, 0);
    unk4578 = manager->fn_80177628(0x23428ABB, 0, 0);
    unk457C = manager->fn_80177628(0xA173A1EE, 0, 0);
    Unk8033FA38* manager2 = &lbl_8033FA38;
    unk54 = manager2->fn_80177628(0xF56854CE, 0, 0);
    unk58 = manager2->fn_80177628(0x3A7628B6, 0, 0);
}

// 0x8000D010
void CASTarget::fn_8000D010() {
    lbl_8037CA80 = 0;
    lbl_8037C230 = 0;
}

// 0x8000F9D8
int CASTarget::fn_8000F9D8() {
    vfn2();
    if (unk4588) {
        unk530C = 1;
        if (unk52FC) {
            delete unk52FC;
            unk52FC = 0;
        }
        fn_80014840();
    }
    return unk4588;
}

// 0x80014110
void CASTarget::fn_80014110() {
    short choices[5];
    choices[0] = unk533C[0].fn_80015900();
    choices[1] = unk533C[1].fn_80015900();
    choices[2] = unk533C[2].fn_80015900();
    choices[3] = unk533C[3].fn_80015900();
    choices[4] = unk533C[4].fn_80015900();
    unk57A8.unk48 = fn_80061FE0(choices);
    fn_80062134(unk57A8.unk48);
}

// 0x80014188
void CASTarget::fn_80014188(ERC* rc, const unsigned short* text, int a, EVec2* position, int b) {
    unk52E4->fn_8003D93C(rc, text, a, position, b, 0, 2.0f, 1.0f);
}

// 0x80014378
void CASTarget::fn_80014378() {
    if (unk5320) {
        fn_80106164(unk52C4, "hideCAS", 0, 0, 0);
        unk5320 = 0;
    }
    unk4590 = 0;
    unk5310 = 1;
}

// 0x80014564
void CASTarget::fn_80014564() {
    if (unk5324) {
        fn_80106164(unk52C4, "hideCAF", 0, 0, 0);
        unk5324 = 0;
    }
    unk5310 = 1;
}

// 0x80014840
void CASTarget::fn_80014840() {
    unk5328 = 0;
    if (unk532C) {
        fn_80106164(unk52C4, "setButtonContext", 0, 0, 1, "CAS");
        fn_80106164(unk52C4, "destroyButton", 0, 0, 1, "accept");
        fn_80106164(unk52C4, "destroyButton", 0, 0, 1, "decline");
        fn_80106164(unk52C4, "resetButtonContext", 0, 0, 0);
        unk532C = 0;
    }
}

// 0x80014A88
void CASTarget::fn_80014A88() {
    char unused[64];
    if (unk45C9 == 0) {
        unk52D4 = 1;
    }
}

struct CASCallback : Unk802316EC {
    CASCallback(void* a, int b) : unk4(a), unk8(b) {}
    virtual void vfn2();
    virtual int vfn3();

    void* unk4;
    int unk8;
};

// 0x80014AA8
void fn_80014AA8(void* a, int b, int c) {
    CASCallback callback(a, c);
    Unk80231598 caller;
    caller.fn_80231598(&callback, b);
}

// 0x80014B00
int fn_80014B00(void* a, int b, int c, int d, int e) {
    CASCallback callback(a, c);
    Unk80231598 caller;
    return caller.fn_802313B4(&callback, e, b, d);
}

// 0x800155D4
void CASCallback::vfn2() {
    fn_801FC174(unk4);
}

// 0x800155F8
int CASCallback::vfn3() {
    return unk8;
}

// 0x80015600
void fn_80015600() {
    fn_80014B6C(1, 0xFFFF);
}
