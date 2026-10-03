#include <new>

#include "sims/ESimsApp.h"

// 0x800034A0
// NON_MATCHING: one instruction short (90 vs 91). The original tests `space` once (kept
// in cr4) ahead of the '-' check and lays the inner loop out with the continue test at
// the bottom.
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
    StateMachineManager::Shutdown();
    unk478->Stop();
    if (unk478) {
        delete unk478;
    }
    unk478 = 0;
    unk2B40 = 0;
    unk2B44 = 0;
    operator delete(unk2B60);
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
    PlayerCheats* cheats = (PlayerCheats*)operator new(sizeof(PlayerCheats));
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

// 0x80003A7C
void ESimsApp::initContinue() {
    LoadSimulatorGlobs();
    fn_800616B0();
    float volume = (float)lbl_802E6818.unk0->unk14 * 0.1f;
    float clamped;
    if (volume < 0.0f) {
        clamped = 0.0f;
    } else if (volume > 1.0f) {
        clamped = 1.0f;
    } else {
        clamped = volume;
    }
    lbl_8037D938 = clamped;
    StateMachineManager::Startup();
    StateMachineManager* manager = lbl_8037D93C;
    manager->AddMachine(new Unk802B5A68Machine);
    manager->AddMachine(new Unk802AF658Machine);
    unk4E0.fn_800D5618();
    Unk800669ACResult banner1 = lbl_802E6700.fn_800669AC("ngc_ipl_banner_1");
    int id1 = banner1.ptr ? *banner1.ptr : 0;
    Unk800669ACResult banner2 = lbl_802E6700.fn_800669AC("ngc_ipl_banner_2");
    fn_8018FE20(id1, banner2.ptr ? *banner2.ptr : 0);
}

// 0x80004058
void ESimsApp::SetGameState(int arg) {
    unk468 = arg;
    if (arg == 1) {
        if (unk2B50 == 0) {
            SimsAppUnk2B50* object = new SimsAppUnk2B50(1, 2);
            unk2B50 = object;
            object->fn_80046194();
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

// 0x8000413C
// NON_MATCHING: same length, 35 of 349 instructions differ, all register numbering
// (r29/r30/r31). It stems from the four timing floats at the top: the original stores
// [0] and [1] like a constructed pair and [3], [2] straight to the stack.
void ESimsApp::Update() {
    SimsAppUnk2B3CRect times(0.0f, 0.0f, 0.0f, 0.0f);
    MarkUpdateStart(times);
    ProfileHook();
    if (lbl_8037D3D0 == 0 && lbl_8037C11C != 0) {
        static int sControllerId = lbl_8037C11C->fn_8015E614(lbl_8037B3EC);
        static EController* sController = lbl_8037C11C->fn_8015E5FC(lbl_8037C11C->fn_8015E614(sControllerId));
        if (sController && unk2B60 && sController->fn_8015E304()) {
            unk2B60->Capture(sController);
        }
    }
    unk47C.fn_800E6038();
    unk4E0.fn_800D59D0();
    fn_8011D784();
    if (lbl_802E6700.GetUnk214() == 0) {
        fn_801063A4(lbl_802E6700.GetUnk90());
    }
    lbl_802F7658.fn_800F850C(lbl_8037BFC8);
    StateMachineManager::UpdateMachines(lbl_8037BFC8);
    if (lbl_802E6700.GetUnkA4() != 0 && unk2B50) {
        unk2B50->vfn32();
    }
    fn_800E6714();
    fn_800E67CC();
    if (unk450 == 0 && lbl_8037D940) {
        fn_80255A54(lbl_8037D940);
    }
    float scale;
    Unk8037D944* movie = lbl_8037D944;
    if (movie == 0) {
        scale = 1.0f;
    } else if (movie->vfn18() != 0) {
        scale = 0.0f;
    } else if (movie->vfn13() != 0) {
        scale = 0.0f;
    } else {
        switch (movie->vfn9()) {
        case 0:
            scale = 1.0f;
            break;
        case -1:
            scale = 0.5f;
            break;
        case -2:
            scale = 5.0f;
            break;
        case -3:
            scale = 10.0f;
            break;
        default:
            scale = 0.0f;
            break;
        }
    }
    fn_80182B30(lbl_8037BFC8 * scale);
    char* timer = lbl_8033F8B0;
    times.unkC = lbl_8037C114->vfn5(timer);
    ERC* rc = lbl_8037C198->vfn13(0);
    unk2B38 = rc;
    StateMachineManager::DrawMachines(rc);
    lbl_8037C198->vfn14(rc);
    unk2B38 = 0;
    lbl_8037C114->vfn5(timer);
    if (unk2B54) {
        lbl_8037C198->vfn7();
        for (int y = 0; y < unk2B5C; y++) {
            for (int x = 0; x < unk2B58; x++) {
                fn_8018AD9C(1, unk2B58, unk2B5C, x, y);
                lbl_8037C198->vfn6();
                rc = lbl_8037C198->vfn13(0);
                unk2B38 = rc;
                SimsAppUnk2B3C window;
                window.fn_8018B044(rc);
                StateMachineManager::DrawMachines(rc);
                lbl_8037C198->vfn14(rc);
                lbl_8037C198->vfn7();
                char name[256];
                fn_8010F710(name, "screenshot-x%dy%d.raw", x + 1, y + 1);
                lbl_8037C198->vfn42(name);
            }
        }
        fn_8018AD9C(1, 1, 1, 0, 0);
        lbl_8037C198->vfn6();
        rc = lbl_8037C198->vfn13(0);
        unk2B38 = rc;
        SimsAppUnk2B3C window;
        window.fn_8018B044(rc);
        StateMachineManager::DrawMachines(rc);
        lbl_8037C198->vfn14(rc);
        fn_8018AD9C(0, 1, 1, 0, 0);
        unk2B54 = 0;
    }
    lbl_8037C114->vfn5(lbl_8033F8B0);
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

// 0x800047E4
// NON_MATCHING: one instruction longer. The original lays the inner sequence loop out
// with the code comparison first and the `code == 0 || i == 6` checks merged into the
// loop condition at the bottom.
bool PlayerCheats::Capture(EController* controller) {
    bool found = false;
    unsigned short buttons = controller->fn_8015E304();
    if (!IsSingleButton(buttons) || (lbl_802E6700.cheats.unk0 & buttons) == 0) {
        unk14 = 1;
        return false;
    }
    PurgeBtnMemory();
    unk1C[unk10].buttons = buttons;
    unk18 = lbl_8037C114->vfn5(this) * 1000.0;
    unk1C[unk10].expireTime = unk18 + 1500.0f;
    unsigned short mask = CreateBtnMask();
    for (unsigned char cheat = 0; cheat <= 7; cheat++) {
        if ((lbl_802E6700.cheats.masks[cheat] & mask) == lbl_802E6700.cheats.masks[cheat]) {
            unsigned char index = unk10;
            while (GetNextIndex(index) != unk10) {
                if (unk1C[index].buttons != 0) {
                    unsigned char cursor = index;
                    bool match = false;
                    for (unsigned char i = 0; i <= 6; i++) {
                        unsigned short code = lbl_802E6700.cheats.codes[cheat][i];
                        if (code == 0 || i == 6) {
                            match = true;
                            break;
                        }
                        if (code != unk1C[cursor].buttons) {
                            break;
                        }
                        GetNextIndex(cursor);
                    }
                    if (match) {
                        controller->fn_8015DFEC(0);
                        found = true;
                        lbl_802E6700.fn_800690E0(cheat);
                        unk14 = 1;
                        unk10 = 0;
                        break;
                    }
                }
            }
        }
    }
    GetNextIndex(unk10);
    return found;
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
// NON_MATCHING: 14 instructions vs 21. The original has the bit check duplicated ahead
// of the loop (first iteration, with the shift folded away) and again after the
// `i > 15` exit test, as GCC does when that check is the loop's condition.
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

// Storage for the application object. It is constructed in place and never
// destroyed: the original has no global destructor for it.
char lbl_802E2C40[sizeof(ESimsApp)];

struct ESimsAppInit {
    ESimsAppInit() { new (lbl_802E2C40) ESimsApp; }
};
static ESimsAppInit sAppInit;
