#include "engine/e_storable.h"
#include "engine/e_resource.h"
#include "engine/e_rfont.h"
#include "engine/e_texture.h"
#include "engine/e_shader.h"
#include "engine/e_rshader.h"
#include "engine/e_instance.h"
#include "engine/e_igameinstance.h"
#include "engine/e_istaticmodel.h"
#include "engine/e_rcharacter.h"
#include "engine/e_submodelshader.h"
#include "engine/e_submodel.h"
#include "engine/e_rmodel.h"
#include "engine/e_ranim.h"
#include "sims/i_siminstance.h"
#include "sims/e_sim.h"
#define EOR_BUILD_TIME "21:41:28"
#include "engine/e_engine.h"
#include "sims/Unk80297B74.h"
#include "sims/e_simsapp_title.h"
#include "sims/Unk80026864Private.h"
#include "sims/Unk8003AA6C.h"

extern int lbl_8037B4C8;
extern int lbl_8037C3DC;
extern int lbl_8037C3E4;
extern int lbl_8037C3EC;
extern int lbl_8037C3F0;
extern EVec2 lbl_8037CBFC;

static EVec2 lbl_8037CA8C(0.49f, 0.0f);
static EVec2 lbl_802E5DEC[3] = { EVec2(-0.14f, 0.74f), EVec2(-0.059f, -0.25f), EVec2(0.66f, 0.65f) };
static EVec2 lbl_802E5E04[3] = { EVec2(0.0f, 0.0f), EVec2(0.0f, -0.2f), EVec2(0.0f, 0.0f) };

// The player's sim as this file reaches it.
struct Unk8003AA6CSimC {
    char unk0[0x594];
    struct Unk800B51AC* unk594;
};
struct Unk8003AA6CSimB {
    char unk0[0x18];
    Unk8003AA6CSimC* unk18;
};
struct Unk8003AA6CSimA {
    char unk0[0x20];
    Unk8003AA6CSimB* unk20;
};
struct Unk8003AA6CPlayer {
    Unk8003AA6CSimA* unk0;
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn20();
    virtual int vfn21();
    virtual void vfn22();
    virtual void* vfn23();
};
struct Unk800B51AC {
    void fn_800B51AC(ERC* rc, Unk8003AA6CPlayer* player);
};
int fn_801CFE88(void* object);
void fn_801CDA68(int on);
void fn_801CDA58(int on);
struct Unk801E5598 {
    void fn_801E5598(int arg);
    int fn_801E5670(int arg);
};
struct Unk802F7658b {
    void fn_800F6C6C();
    char unk0[0x60];
};
extern Unk802F7658b lbl_802F7658;
// The per-player screens the camera object keeps (ESimsCamUnkBC).
struct Unk8003AA6CScreens {
    char unk0[0x224];
    Unk8003AA6C* unk224[2];
    struct Unk8003AA6CSlot* unk22C[2];
};
struct Unk8003AA6CSlot {
    char unk0[0x48];
    int unk48;
    char unk4C[0x120 - 0x4C];
    int unk120;
};
struct Unk8003AA6CGlobal118 {
    int unk0;
    int unk4;
    int unk8;
};

inline Unk800B51AC* GetPlayerPanel(int player) {
    Unk8003AA6CPlayer* owner = (Unk8003AA6CPlayer*)lbl_802E6700.unk9C[player];
    Unk8003AA6CSimC* sim;
    if (owner) {
        sim = owner->unk0->unk20->unk18;
    } else {
        sim = 0;
    }
    return sim ? sim->unk594 : 0;
}

// 0x8003AA6C
// The table is filled in index order except that 9 comes before 8.
Unk8003AA6C::Unk8003AA6C(int player) {
    unk4C = EVec2(0.0f);
    unk38 = player;
    fn_80111C78(unk54, 0, sizeof(unk54));
    unk54[0] = &Unk8003AA6C::fn_8003B6A4;
    unk54[1] = &Unk8003AA6C::fn_8003B710;
    unk54[2] = &Unk8003AA6C::fn_8003B730;
    unk54[3] = &Unk8003AA6C::fn_8003B750;
    unk54[4] = &Unk8003AA6C::fn_8003B750;
    unk54[5] = &Unk8003AA6C::fn_8003B770;
    unk54[6] = &Unk8003AA6C::fn_8003B6A4;
    unk54[9] = &Unk8003AA6C::fn_8003B6A4;
    unk54[8] = &Unk8003AA6C::fn_8003B6A4;
    unk54[10] = &Unk8003AA6C::fn_8003B6A4;
    unk54[11] = &Unk8003AA6C::fn_8003B6A4;
}

// 0x8003AC84
Unk8003AA6C::~Unk8003AA6C() {
}

// 0x8003ADB0
void fn_8003ADB0() {
    if (lbl_8037B4C8 == 0) {
        lbl_8037B4C8 = 1;
    }
}

// 0x8003ADC8
void fn_8003ADC8() {
    lbl_8037B4C8 = 0;
}

// 0x8003ADD4
void Unk8003AA6C::vfn2(int newMode) {
    mode = newMode;
}

// 0x8003ADE0
// Turns the player's button presses into messages for the parent screen.
// NON_MATCHING: 418 instructions vs 411, identical up to 0x8003B3D8: the original
// shares the tail of the call for message 0x2E with the one for 0x2F, here it is
// emitted twice. Five shapes of the last block tried.
void Unk8003AA6C::vfn2() {
    EController* controller = lbl_8037C11C->fn_8015E5FC(lbl_8037C11C->fn_8015E614(unk38));
    if (IsBuildMode()) {
        if (unk38 != lbl_802E6700.unk138) {
            return;
        }
        if (mode != 9) {
            return;
        }
        if (controller->fn_8015E0F8(0x10)) {
            lbl_8037D96C->fn_8006186C(0xD9552AE4);
            ((UnkTargetBase*)unkC)->vfn7(this, 0xD);
            return;
        }
        if (mode == 9 && controller->fn_8015E204(7)) {
            lbl_8037D96C->fn_8006186C(0x048AE94F);
        }
        return;
    }
    Unk8003AA6CPlayer* player = (Unk8003AA6CPlayer*)lbl_802E6700.unk9C[unk38];
    if (mode == 2) {
        if (lbl_8037C3DC) {
            bool busy = true;
            if (((Unk8003AA6CScreens*)lbl_802E6700.unkBC)->unk22C[unk38]->unk120 == 0) {
                busy = false;
            }
            if (!busy) {
                lbl_8037D96C->fn_8006186C(0x383DF7E6);
                ((UnkTargetBase*)unkC)->vfn7((UnkTargetBase*)unk38, 0xA);
                return;
            }
        } else if (player) {
            int a = player->vfn21();
            int b = fn_801CFE88(player->vfn23());
            if (a == 0 && b == 0) {
                lbl_8037D96C->fn_8006186C(0x383DF7E6);
                ((UnkTargetBase*)unkC)->vfn7((UnkTargetBase*)unk38, 0xA);
                return;
            }
        }
    }
    Unk8003AA6C* screen = ((Unk8003AA6CScreens*)lbl_802E6700.unkBC)->unk224[unk38];
    bool other = false;
    if ((unk38 == 0 && screen->mode == 3) || (unk38 == 1 && screen->mode == 4)) {
        other = true;
    }
    if (mode != 1) {
        bool pause = false;
        if (((lbl_8037C3F0 && controller->fn_8015E0F8(0x12)) || lbl_8037C3E4) && lbl_802E6700.unk130 != 7) {
            if (lbl_8037C3EC == 0) {
                ((Unk801E5598*)lbl_802E6700.unk120)->fn_801E5598(*(int*)((char*)lbl_8037BFA8 + 0x468));
                if (lbl_8037C3E4 == 0) {
                    fn_801CDA68(1);
                }
                pause = true;
            }
            fn_801CDA58(0);
        } else {
            fn_801CDA68(0);
        }
        if (pause) {
            if (((Unk801E5598*)lbl_802E6700.unk120)->fn_801E5670(-1)) {
                ((UnkTargetBase*)unkC)->vfn7(this, 0x22);
                lbl_802F7658.fn_800F6C6C();
                return;
            }
            ((UnkTargetBase*)unkC)->vfn7(this, 0x24);
            return;
        }
        if (controller->fn_8015E0F8(0x10)) {
            lbl_8037D96C->fn_8006186C(0xD9552AE4);
            ((UnkTargetBase*)unkC)->vfn7(this, 0xD);
            return;
        }
        if (mode != 1 && controller->fn_8015E0F8(0x12)) {
            return;
        }
    }
    if (IsBuildMode()) {
        return;
    }
    if (mode == 1 || mode == 5) {
        return;
    }
    if (!(screen->unk18 & 2) && other) {
        ((UnkTargetBase*)unkC)->vfn7(this, 0x10);
        return;
    }
    if (controller->fn_8015E0F8(0x14)) {
        if ((unsigned int)(mode - 3) <= 1) {
            return;
        }
        if (mode != 2) {
            if (lbl_802E6700.unk9C[unk38] == 0 || ((Unk8003AA6CScreens*)lbl_802E6700.unkBC)->unk22C[unk38]->unk48 == 0) {
                lbl_8037D96C->fn_8006186C(0x3804219F);
                return;
            }
            lbl_8037D96C->fn_8006186C(0x383DF7E6);
            ((UnkTargetBase*)unkC)->vfn7((UnkTargetBase*)unk38, 0xA);
            return;
        }
        lbl_8037D96C->fn_8006186C(0x383DF7E6);
        ((UnkTargetBase*)unkC)->vfn7((UnkTargetBase*)unk38, 0xA);
        return;
    }
    if (mode == 2) {
        if (controller->fn_8015E0F8(7) || controller->fn_8015DEE4(0, 0) != 0.0f || controller->fn_8015DEE4(0, 1) != 0.0f) {
            lbl_8037D96C->fn_8006186C(0x383DF7E6);
            ((UnkTargetBase*)unkC)->vfn7((UnkTargetBase*)unk38, 0xA);
        }
        return;
    }
    Unk8003AA6CGlobal118* state = (Unk8003AA6CGlobal118*)lbl_802E6700.unk118;
    if (state->unk8 == 1) {
        if (controller->fn_8015E0F8(0x15)) {
            lbl_8037D96C->fn_8006186C(0x0C21C2A9);
            ((UnkTargetBase*)unkC)->vfn7((UnkTargetBase*)unk38, 8);
            return;
        }
        if (((Unk8003AA6CGlobal118*)lbl_802E6700.unk118)->unk8 == 1 && controller->fn_8015E0F8(0x16)) {
            lbl_8037D96C->fn_8006186C(0x0C21C2A9);
            ((UnkTargetBase*)unkC)->vfn7((UnkTargetBase*)unk38, 9);
            return;
        }
    }
    if (((Unk8003AA6CGlobal118*)lbl_802E6700.unk118)->unk8 == 0) {
        if (controller->fn_8015E0F8(0x15)) {
            lbl_8037D96C->fn_8006186C(0x0C21C2A9);
            ((UnkTargetBase*)unkC)->vfn7((UnkTargetBase*)unk38, 0x2E);
        } else {
            if (((Unk8003AA6CGlobal118*)lbl_802E6700.unk118)->unk8 != 0) {
                return;
            }
            if (!controller->fn_8015E0F8(0x16)) {
                return;
            }
            lbl_8037D96C->fn_8006186C(0x0C21C2A9);
            ((UnkTargetBase*)unkC)->vfn7((UnkTargetBase*)unk38, 0x2F);
        }
    }
}

// 0x8003B44C
// Draws through the current mode's entry of the table (or entry 0, unshifted).
void Unk8003AA6C::vfn3(ERC* rc) {
    if (unk38 == 1 && !lbl_802E6700.fn_800655C4()) {
        return;
    }
    const EVec2* at;
    if (unk38 == 1) {
        at = &EVec2(0.62f, 0.0f);
    } else if (lbl_802E6700.fn_800655C4()) {
        at = &EVec2(0.0f, -0.74f);
    } else {
        at = &lbl_8037CBFC;
    }
    if (unk54[mode] != 0) {
        (this->*unk54[mode])(rc, *at + EVec2(-0.075f, 0.03f));
    } else {
        (this->*unk54[0])(rc, *at);
    }
}

// 0x8003B61C
void Unk8003AA6C::fn_8003B61C(ERC* rc, const EVec2& at) {
    Unk800B51AC* panel = GetPlayerPanel(unk38);
    if (panel) {
        panel->fn_800B51AC(rc, (Unk8003AA6CPlayer*)lbl_802E6700.unk9C[unk38]);
    }
}

// 0x8003B6A4
void Unk8003AA6C::fn_8003B6A4(ERC* rc, const EVec2& at) {
    if (GetPlayerPanel(unk38)) {
        fn_8003B61C(rc, at);
    }
}

// 0x8003B710
void Unk8003AA6C::fn_8003B710(ERC* rc, const EVec2& at) {
    fn_8003B61C(rc, at);
}

// 0x8003B730
void Unk8003AA6C::fn_8003B730(ERC* rc, const EVec2& at) {
    fn_8003B61C(rc, at);
}

// 0x8003B750
void Unk8003AA6C::fn_8003B750(ERC* rc, const EVec2& at) {
    fn_8003B61C(rc, at);
}

// 0x8003B770
void Unk8003AA6C::fn_8003B770(ERC* rc, const EVec2& at) {
    fn_8003B61C(rc, at);
}

// 0x8003B840
void Unk8003AA6C::vfn3() {
}
