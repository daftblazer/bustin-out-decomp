#include "sims/cas/CASSim.h"

// 0x80018310
Unk80018374::Unk80018374(int a, int b, Unk8001EE8C* owner) {
    unk0 = 0;
    fn_8001857C(a, b, owner);
}

// 0x80018374
Unk80018374::Unk80018374(CASSimDesc* desc, Unk8001EE8C* owner, int c) {
    unk0 = c;
    fn_80018F5C(desc, owner);
}

// 0x800183D0
// Sets the remembered choices of the four body types to their defaults.
// NON_MATCHING: same length (107), 62 differ: the values are right, but the original
// interleaves the 76 stores across the four records in an order this source order does
// not reproduce (too many to search).
void fn_800183D0() {
    lbl_802E5A38.unk0 = 1;
    lbl_802E5A38.unk4 = 1;
    lbl_802E5A38.unk8[1] = 22;
    lbl_802E5A38.unk8[2] = 14;
    lbl_802E5A38.unk8[15] = 1;
    lbl_802E5A38.unk8[16] = 0;
    lbl_802E5A38.unk8[17] = 4;
    lbl_802E5A38.unk8[3] = 33;
    lbl_802E5A38.unk8[4] = 47;
    lbl_802E5A38.unk8[6] = 10;
    lbl_802E5A38.unk8[5] = 41;
    lbl_802E5A38.unk8[7] = 18;
    lbl_802E5A38.unk8[8] = 1;
    lbl_802E5A38.unk8[9] = 2;
    lbl_802E5A38.unk8[10] = 4;
    lbl_802E5A38.unk8[11] = 3;
    lbl_802E5A38.unk8[12] = 3;
    lbl_802E5A38.unk8[13] = 2;
    lbl_802E5A38.unk8[14] = 15;
    lbl_802E5A1C.unk0 = 0;
    lbl_802E5A1C.unk4 = 1;
    lbl_802E5A1C.unk8[1] = 0;
    lbl_802E5A1C.unk8[2] = 3;
    lbl_802E5A1C.unk8[15] = 10;
    lbl_802E5A1C.unk8[16] = 11;
    lbl_802E5A1C.unk8[17] = 11;
    lbl_802E5A1C.unk8[3] = 10;
    lbl_802E5A1C.unk8[4] = 1;
    lbl_802E5A1C.unk8[6] = 2;
    lbl_802E5A1C.unk8[5] = 19;
    lbl_802E5A1C.unk8[7] = 6;
    lbl_802E5A1C.unk8[8] = 1;
    lbl_802E5A1C.unk8[9] = 1;
    lbl_802E5A1C.unk8[10] = 1;
    lbl_802E5A1C.unk8[11] = 1;
    lbl_802E5A1C.unk8[12] = 1;
    lbl_802E5A1C.unk8[13] = 0;
    lbl_802E5A1C.unk8[14] = 28;
    lbl_802E5A70.unk0 = 1;
    lbl_802E5A70.unk4 = 0;
    lbl_802E5A70.unk8[1] = 0;
    lbl_802E5A70.unk8[2] = 3;
    lbl_802E5A70.unk8[15] = 0;
    lbl_802E5A70.unk8[16] = 0;
    lbl_802E5A70.unk8[17] = 0;
    lbl_802E5A70.unk8[3] = 0;
    lbl_802E5A70.unk8[4] = 0;
    lbl_802E5A70.unk8[6] = 0;
    lbl_802E5A70.unk8[5] = 0;
    lbl_802E5A70.unk8[7] = 0;
    lbl_802E5A70.unk8[8] = 1;
    lbl_802E5A70.unk8[9] = 0;
    lbl_802E5A70.unk8[10] = 0;
    lbl_802E5A70.unk8[11] = 0;
    lbl_802E5A70.unk8[12] = 0;
    lbl_802E5A70.unk8[13] = 0;
    lbl_802E5A70.unk8[14] = 0;
    lbl_802E5A54.unk0 = 0;
    lbl_802E5A54.unk4 = 0;
    lbl_802E5A54.unk8[1] = 0;
    lbl_802E5A54.unk8[2] = 0;
    lbl_802E5A54.unk8[15] = 0;
    lbl_802E5A54.unk8[16] = 0;
    lbl_802E5A54.unk8[17] = 0;
    lbl_802E5A54.unk8[3] = 0;
    lbl_802E5A54.unk8[4] = 1;
    lbl_802E5A54.unk8[6] = 0;
    lbl_802E5A54.unk8[5] = 0;
    lbl_802E5A54.unk8[7] = 0;
    lbl_802E5A54.unk8[8] = 1;
    lbl_802E5A54.unk8[9] = 0;
    lbl_802E5A54.unk8[10] = 0;
    lbl_802E5A54.unk8[11] = 0;
    lbl_802E5A54.unk8[12] = 0;
    lbl_802E5A54.unk8[13] = 0;
    lbl_802E5A54.unk8[14] = 0;
}

// 0x8001AB8C
// Plays an animation, first requesting it if the manager is not ready.
// NON_MATCHING: 2 of 29 differ: the original saves the argument (`mr r31, r4`) before
// loading the manager's address, this build after. Seven variants tried.
void Unk80018374::fn_8001AB8C(unsigned int animationId) {
    if (lbl_8033F3D8.fn_80177B24() == 0) {
        unk198 = animationId;
        lbl_8033F3D8.fn_801776C0(animationId);
    } else {
        unkE0.fn_80159994(0, animationId);
        unkE0.fn_8015A520(0);
    }
}

// 0x8001AC00
// Starts the requested animation once it has loaded; true while still waiting.
int Unk80018374::fn_8001AC00() {
    if (unk198) {
        if (lbl_8033F3D8.fn_801770C0(unk198) == 0) {
            return 1;
        }
        unkE0.fn_80159994(0, unk198);
        unkE0.fn_8015A520(0);
        lbl_8033F3D8.fn_801778B4(unk198);
        unk198 = 0;
    }
    return 0;
}

// 0x8001AC88
// Per-frame animation: the turn-round animation when one is queued, otherwise
// an idle animation picked at random every few loops.
// NON_MATCHING: 1 of 101 differs: the indexed load of the random animation id has its
// base and index registers the other way round (`lwzx r4, r11, r9`). Five forms tried.
void Unk80018374::fn_8001AC88() {
    if (fn_8001AC00()) {
        return;
    }
    if (unkE0.fn_8015AA0C(0)) {
        if (unk3C) {
            if (unk38) {
                fn_8001AB8C(**unk50);
            } else {
                fn_8001AB8C(**unk54);
            }
            unk3C = 0;
        } else {
            unsigned int*** list;
            if (unk38 == 0) {
                list = unk74;
            } else {
                list = unk78;
            }
            if (unk10) {
                if (unk2C) {
                    unk2C--;
                    unkE0.fn_8015A520(0);
                } else {
                    unk10 = 0;
                    int roll = fn_801115C4();
                    unsigned int* ids = (*list)[1];
                    fn_8001AB8C(ids[(roll >> 4) % ECount((int*)ids)]);
                    unk2C = fn_801115C4() % 4 + 2;
                }
            } else {
                unk10 = 1;
                fn_8001AB8C((*list)[1][0]);
            }
        }
    }
    unkE0.fn_801569F8(0, 0, EVec3(1.0f));
}

// 0x8001B850
void Unk80018374::fn_8001B850(int slot) {
    switch (slot) {
    case 0:
        if (unkBC) {
            fn_801767FC(unkBC);
            unkBC = 0;
        }
        break;
    case 8:
        if (unkC0) {
            fn_801767FC(unkC0);
            unkC0 = 0;
        }
        break;
    default:
        if (unk90[slot - 1]) {
            fn_801767FC(unk90[slot - 1]);
            unk90[slot - 1] = 0;
        }
        break;
    }
}

// 0x8001BF1C
int Unk80018374::fn_8001BF1C(unsigned int slot) {
    switch (slot) {
    case 3:
        return unk16C.unk8[4];
    case 4:
        return unk16C.unk8[5];
    case 5:
        return unk16C.unk8[6];
    case 2:
        return unk16C.unk8[3];
    case 1:
        return unk16C.unk8[2];
    case 9:
        return unk16C.unk8[15];
    case 10:
        return unk16C.unk8[16];
    case 11:
        return unk16C.unk8[17];
    case 0:
        return unk16C.unk8[1];
    case 6:
        return unk16C.unk8[7];
    case 7:
        return unk16C.unk8[0];
    }
    return 0;
}

// 0x8001C028
void Unk80018374::fn_8001C028(int slot) {
    int choice = fn_8001BF1C(slot);
    do {
        choice = fn_8001DB38(slot, choice + 1, 0);
    } while (fn_8001E794(unk16C.unk4, unk16C.unk0, slot, choice));
    fn_8001B8E4(slot, choice);
}

// 0x8001C0A4
// Previous choice, wrapping from the first to the last and skipping choices
// that are not allowed.
void Unk80018374::fn_8001C0A4(int slot) {
    int choice = fn_8001BF1C(slot);
    do {
        if (choice == 0) {
            switch (slot) {
            case 3:
                choice = ECount(unk194[0]) - 1;
                break;
            case 4:
                choice = ECount(unk194[1]) - 1;
                break;
            case 5:
                choice = ECount(unk194[2]) - 1;
                break;
            case 2:
                choice = ECount(unk194[6]) - 1;
                break;
            case 9:
                choice = ECount(unk194[3]) - 1;
                break;
            case 10:
                choice = ECount(unk194[4]) - 1;
                break;
            case 11:
                choice = ECount(unk194[5]) - 1;
                break;
            case 0:
                choice = ECount(unk194[7]) - 1;
                break;
            case 6:
                choice = ECount(unk194[8]) - 1;
                break;
            case 7:
                choice = 2;
                break;
            }
        } else {
            choice--;
        }
        choice = fn_8001DB38(slot, choice, 1);
    } while (fn_8001E794(unk16C.unk4, unk16C.unk0, slot, choice));
    fn_8001B8E4(slot, choice);
}

// 0x8001C240
// Remembers the current choices for this body type.
void Unk80018374::fn_8001C240() {
    Unk801CC464* saved;
    if (unk16C.unk4) {
        if (unk16C.unk0) {
            saved = &lbl_802E5A38;
        } else {
            saved = &lbl_802E5A1C;
        }
    } else {
        if (unk16C.unk0) {
            saved = &lbl_802E5A70;
        } else {
            saved = &lbl_802E5A54;
        }
    }
    *saved = unk16C;
    unkC8->fn_80021D94();
}

// 0x8001C2F4
// Restores the remembered choices for this body type.
void Unk80018374::fn_8001C2F4() {
    Unk801CC464* saved;
    if (unk16C.unk4) {
        if (unk16C.unk0) {
            saved = &lbl_802E5A38;
        } else {
            saved = &lbl_802E5A1C;
        }
    } else {
        if (unk16C.unk0) {
            saved = &lbl_802E5A70;
        } else {
            saved = &lbl_802E5A54;
        }
    }
    unk16C = *saved;
}

// 0x8001C384
void Unk80018374::fn_8001C384() {
    unkC = 1;
    unkC8->fn_80021A14(unkD0->unk14);
}

// 0x8001D6D8
// Draws the sim's shadow with a flattened view (the same view set-up as the
// props' shadows in CASTarget::vfn3).
// NON_MATCHING: 92 instructions vs 91. The original keeps the view matrix's address in
// r30 from before the identity call and so needs one saved register fewer; pointer,
// reference and by-value-product forms do not reproduce that. Four variants tried.
void Unk80018374::fn_8001D6D8(ERC* rc) {
    EMat4 view;
    view.fn_801B2AFC();
    view.m[2][0] = 0.2f;
    view.m[2][1] = 0.2f;
    view.m[2][2] = 0.0f;
    view.fn_801B345C(EVec3(0.0f, 0.0f, 0.01f));
    EMat4 saved;
    saved.Copy64(lbl_8037C0E0->unkA0);
    EMat4 copy;
    fn_80015070(view, view.Mul(saved));
    fn_80015070(copy, view);
    rc->vfn30(&view);
    unkC4->fn_8017CE68(rc);
    rc->vfn30(&saved);
}

// 0x8001DB0C
// Comparison for sorting unsigned ids.
int fn_8001DB0C(const unsigned int* a, const unsigned int* b) {
    if (*a < *b) {
        return -1;
    }
    if (*a == *b) {
        return 0;
    }
    return 1;
}

// 0x8001E6E8
void Unk80018374::fn_8001E6E8(int a, int b) {
    if (b) {
        if (a == 0) {
            unkE0.fn_80159994(0, **unk54);
        } else {
            unkE0.fn_80159994(0, **unk50);
        }
        unk3C = 0;
    } else if (a != unk38) {
        if (unk3C) {
            unk3C = b;
        } else {
            unk3C = 1;
        }
    }
    unk38 = a;
    unk2C = 0;
}
