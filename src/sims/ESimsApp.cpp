#include "sims/ESimsApp.h"

// 0x8000360C
ESimsApp::ESimsApp() {
    unk478 = 0;
    unk2B3C = 0;
    unk2B40 = 0;
    unk2B44 = 0;
    unk2B50 = 0;
    fn_8015C6D4(0);
}

// 0x8000367C
ESimsApp::~ESimsApp() {
    if (unk2B50) {
        delete unk2B50;
        unk2B50 = 0;
    }
}

// 0x80003708
void ESimsApp::Shutdown() {
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
const char* ESimsApp::GetBuildVersion() {
    return "NGC Sims Bustin Out Build 2.1.3.31-1i";
}

// 0x800037D4
int ESimsApp::GetDefaultLanguage() {
    return 0;
}

// 0x80004058
// NON_MATCHING: the original copies the `new` result through r0 before storing it
// (`mr r0, r3; stw r0, 0x2b50(r31)`), one instruction more than this produces.
void ESimsApp::SetGameState(int arg) {
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

// 0x8000410C
void ESimsApp::LoadSimulatorGlobs() {
    fn_801C6BB8();
}

// 0x8000412C
void ProfileHook() {
    lbl_8037B3E8++;
}

// 0x800046B0
void ESimsApp::vfn17(int arg) {
    lbl_8037D948->vfn14(lbl_8037D94C);
    lbl_8037D94C->fn_801EAE6C(arg);
}

// 0x80004704
bool ESimsApp::vfn18() {
    return lbl_8037D94C->fn_801EB1D8() != 0;
}

// 0x80004738
void ESimsApp::vfn19(int arg) {
    if (arg) {
        lbl_8037D944->vfn14();
    } else {
        lbl_8037D944->vfn15();
    }
}

// 0x80004798
void ESimsApp::vfn20(int arg) {
    lbl_802F7658.unkF0->fn_80086E58();
    lbl_802F7658.unkF0->unk84 = arg == 1;
}

// 0x800049F0
unsigned char PlayerCheats::GetNextIndex(unsigned char& index) {
    index++;
    if (index > 5) {
        index = 0;
    }
    return index;
}

// 0x80004A18
// NON_MATCHING: the original has the first iteration peeled off ahead of the loop.
bool PlayerCheats::IsSingleButton(unsigned short buttons) {
    bool found = false;
    for (unsigned char i = 0; i <= 15; i++) {
        if ((buttons >> i) & 1) {
            if (!found) {
                found = true;
            } else {
                return false;
            }
        }
    }
    return found;
}

// 0x80004A6C
void PlayerCheats::PurgeBtnMemory() {
    unk18 = lbl_8037C114->vfn5(this) * 1000.0;
    if (unk14 == 1) {
        unk14 = 0;
        unk10 = 0;
        unk18 = unk18 + 1500.0f;
    }
    for (unsigned char i = 0; i <= 5; i++) {
        if (unk1C[i].buttons != 0 && unk18 >= unk1C[i].expireTime) {
            unk1C[i].buttons = 0;
            unk1C[i].expireTime = 0.0f;
        }
    }
}

// 0x80004B44
unsigned short PlayerCheats::CreateBtnMask() {
    unsigned short mask = 0;
    for (unsigned char i = 0; i <= 5; i++) {
        mask |= unk1C[i].buttons;
    }
    return mask;
}

inline void* operator new(unsigned int, void* ptr) { return ptr; }

// Storage for the application object. It is constructed in place and never
// destroyed: the original has no global destructor for it.
char lbl_802E2C40[sizeof(ESimsApp)];

struct ESimsAppInit {
    ESimsAppInit() { new (lbl_802E2C40) ESimsApp; }
};
static ESimsAppInit sAppInit;
