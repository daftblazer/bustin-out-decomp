#include "sims/ESimsApp.h"

// 0x800034A0
// NON_MATCHING: same size, but the original tests `space` once (kept in cr4) ahead of
// the '-' check and lays the inner loop out with the continue test at the bottom.
void ESimsApp::parseCommandLine() {
    int argc = mArgc;
    char** argv = mArgv;
    if (argc <= 1) {
        return;
    }
    for (int i = 0; i < argc;) {
        char* arg = *argv;
        i++;
        argv++;
        int used;
        do {
            char* space = fn_80111E30(arg, ' ');
            char* space2 = 0;
            if (space) {
                *space = 0;
                space2 = fn_80111E30(space + 1, ' ');
                if (space2) {
                    *space2 = 0;
                }
            }
            used = 0;
            if (*arg == '-') {
                char* opt = arg + 1;
                char* value = 0;
                if (i < argc) {
                    value = *argv;
                }
                if (space) {
                    value = space + 1;
                }
                if (value && *value == 0) {
                    value = 0;
                }
                switch (*opt) {
                case 'L':
                case 'l':
                    if (fn_801120A8(opt, "lot", 3) == 0) {
                        lbl_8037B3E0 = fn_80110874(value);
                        if ((unsigned int)(lbl_8037B3E0 - 1) > 15) {
                            lbl_8037B3E0 = 0;
                        }
                        used = 1;
                    }
                    break;
                }
            }
            if (used) {
                if (!space) {
                    break;
                }
                space = space2;
                used = 0;
            }
            arg = space;
        } while (arg);
        if (used) {
            i += used;
            argv += used;
        }
    }
}

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

// 0x800037DC
// NON_MATCHING: 8 of 168 instructions. In the three fn_80177628 calls made through a
// saved register, the original loads `this` (mr r3) after the other arguments.
void ESimsApp::Init() {
    PlayerCheats* cheats = (PlayerCheats*)fn_801B8A3C(sizeof(PlayerCheats));
    unk2B60 = cheats;
    if (cheats) {
        cheats->unk10 = 0;
        cheats->unk14 = 1;
        lbl_8037C114->vfn4(cheats);
    }
    parseCommandLine();
    lbl_802E5E1C.fn_80176C78("rletextures", 0x100);
    lbl_8037C0B4 = &lbl_802E5E1C;
    lbl_803401C4.unkA4 = GetDefaultLanguage();
    lbl_8037CA30 = 1;
    fn_801C6168(&lbl_8037D2D8, "");
    lbl_8037C0B8 = 0;
    unsigned int id = lbl_802F7658.fn_800F85B4();
    Unk80340AB8* mgr = &lbl_80340AB8;
    mgr->fn_80177628(id, 0, 0);
    mgr->fn_80177628(0xCD2395BD, 0, 0);
    lbl_8033F5C4.fn_80177628(lbl_802E6700.fn_800655D8(), 0, 0);
    lbl_803401C4.fn_80177628(0xA173A1EE, 0, 0);
    mgr->fn_80177628(0x1A18CA65, 0, 0);
    fn_80104794(fn_80169E74(0x100000, 4), 0x100000);
    lbl_802E6700.fn_800656D8();
    for (int i = 0; i < GetNumControllers(); i++) {
        lbl_8037C11C->fn_8015E574(i)->fn_8015CAA0(lbl_802D1C60);
        lbl_8037C11C->fn_8015E550(i);
    }
    unk478 = new SimsAppUnk478;
    unk478->fn_800645E8(new Unk80103028);
    unk478->fn_800645E8(new Unk800813CC);
    lbl_802F7658.fn_800F87A0();
    fn_8006015C();
    unk2B4C = 0;
    unk2B3C = new SimsAppUnk2B3C;
    if (unk2B3C) {
        unk2B3C->fn_8018B584(SimsAppUnk2B3CRect(0.0f, 0.0f, 1.0f, 1.0f));
    }
    initContinue();
    fn_801C6A24(&lbl_8037D2EC, "Allocating CTGDump object memory\n");
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
