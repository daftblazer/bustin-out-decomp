#include "sims/SimsApp.h"

// 0x8000360C
SimsApp::SimsApp() {
    unk478 = 0;
    unk2B3C = 0;
    unk2B40 = 0;
    unk2B44 = 0;
    unk2B50 = 0;
    fn_8015C6D4(0);
}

// 0x8000367C
SimsApp::~SimsApp() {
    if (unk2B50) {
        delete unk2B50;
        unk2B50 = 0;
    }
}

// 0x80003708
void SimsApp::Shutdown() {
    lbl_802E6700.Begin();
    fn_801CD9A8(lbl_8037C3D8);
    fn_800FD840();
    unk478->Stop();
    if (unk478) {
        delete unk478;
    }
    unk478 = 0;
    unk2B40 = 0;
    unk2B44 = 0;
    fn_801B8A60(unk2B60);
    unk2B60 = 0;
    lbl_802E6700.End();
    lbl_80340094.Shutdown();
    lbl_802E5E1C.Shutdown();
    if (unk2B3C) {
        delete unk2B3C;
    }
}

// 0x800037C8
const char* SimsApp::GetBuildString() {
    return "NGC Sims Bustin Out Build 2.1.3.31-1i";
}

// 0x80004058
// NON_MATCHING: the original copies the `new` result through r0 before storing it
// (`mr r0, r3; stw r0, 0x2b50(r31)`), one instruction more than this produces.
void SimsApp::vfn21(int arg) {
    unk468 = arg;
    if (arg == 1) {
        if (unk2B50 == 0) {
            unk2B50 = new SimsAppUnk2B50(1, 2);
            fn_80046194();
            ((Unk801888F4*)unk2B50)->fn_801888F4(2, 0);
        }
        lbl_802E6820.unk0->unk24 = 0;
    } else if (unk2B50) {
        delete unk2B50;
        unk2B50 = 0;
    }
}

// 0x800046B0
void SimsApp::vfn17(int arg) {
    lbl_8037D948->vfn14(lbl_8037D94C);
    lbl_8037D94C->fn_801EAE6C(arg);
}

// 0x80004704
bool SimsApp::vfn18() {
    return lbl_8037D94C->fn_801EB1D8() != 0;
}

// 0x80004738
void SimsApp::vfn19(int arg) {
    if (arg) {
        lbl_8037D944->vfn14();
    } else {
        lbl_8037D944->vfn15();
    }
}

// 0x80004798
void SimsApp::vfn20(int arg) {
    lbl_802F7658.unkF0->fn_80086E58();
    lbl_802F7658.unkF0->unk84 = arg == 1;
}

// 0x800049F0
unsigned char SimsApp::fn_800049F0(unsigned char* value) {
    (*value)++;
    if (*value > 5) {
        *value = 0;
    }
    return *value;
}

// 0x80004A18
// NON_MATCHING: the original has the first iteration peeled off ahead of the loop.
bool SimsApp::fn_80004A18(int mask) {
    bool found = false;
    for (unsigned char i = 0; i <= 15; i++) {
        if ((mask >> i) & 1) {
            if (!found) {
                found = true;
            } else {
                return false;
            }
        }
    }
    return found;
}
