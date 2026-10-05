#include "sims/cas/CASTarget.h"

// 0x8000B03C
void CASTarget::fn_8000B03C(E3DWindowLike* window) {
    window->fn_801546D8(unk8C);
}

// 0x8000C588
// NON_MATCHING: 6 of 21 differ. The original copies `this` to r4 before the store and
// loads the viewer straight into r3; here the viewer goes through r0. Eight variants tried.
void CASTarget::fn_8000C588() {
    EGlobal* global = &lbl_802E6700;
    void* viewer = global->unk90;
    unk52C8 = 0;
    fn_8010826C(viewer);
    fn_801066A0(global->unk90, "create", 0);
}

// 0x8000CBD8
void CASTarget::fn_8000CBD8() {
    Unk80340AB8* manager = &lbl_80340AB8;
    unk4C = manager->fn_80177628(0xAB5FDCCC, 0, 0);
    unk50 = manager->fn_80177628(0x0F303F75, 0, 0);
}

// 0x8000D010
void CASTarget::fn_8000D010() {
    lbl_8037CA80 = 0;
    lbl_8037C230 = 0;
}

// 0x80014110
void CASTarget::fn_80014110() {
    short choices[5];
    choices[0] = unk533C.fn_80015900();
    choices[1] = unk541C.fn_80015900();
    choices[2] = unk54FC.fn_80015900();
    choices[3] = unk55DC.fn_80015900();
    choices[4] = unk56BC.fn_80015900();
    unk57F0 = fn_80061FE0(choices);
    fn_80062134(unk57F0);
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

// 0x80014A88
void CASTarget::fn_80014A88() {
    char unused[64];
    if (unk45C9 == 0) {
        unk52D4 = 1;
    }
}
