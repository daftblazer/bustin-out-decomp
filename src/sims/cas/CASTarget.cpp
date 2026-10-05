#include "sims/cas/CASTarget.h"

void fn_8000C3C8();

// Camera eye/target pairs for each view of the sim (indices 0-19), followed by
// lighting and layout constants. Built at start-up by the static initializer at
// 0x80014B6C.
// NON_MATCHING (__static_initialization_and_destruction_0, 0x80014B6C): same length, 146
// of 321 differ. The values and store order are right; the compiler assigns the forty-odd
// address and constant registers differently.
EVec3 lbl_802E57DC(2.545f, -2.243f, 2.165f);
EVec3 lbl_802E57E8(-0.285f, 1.279f, 1.213f);
EVec3 lbl_802E57F4(0.388f, 0.133f, 1.7f);
EVec3 lbl_802E5800(0.323f, 1.442f, 1.6f);
EVec3 lbl_802E580C(0.388f, -0.288f, 1.223f);
EVec3 lbl_802E5818(0.342f, 1.018f, 1.129f);
EVec3 lbl_802E5824(0.397f, -0.623f, 1.467f);
EVec3 lbl_802E5830(0.328f, 1.308f, 1.514f);
EVec3 lbl_802E583C(0.397f, -0.623f, 1.067f);
EVec3 lbl_802E5848(0.328f, 1.308f, 1.114f);
EVec3 lbl_802E5854(0.188f, -1.136f, 0.85f);
EVec3 lbl_802E5860(0.26f, 1.227f, 0.586f);
EVec3 lbl_802E586C(0.188f, -1.136f, 0.85f);
EVec3 lbl_802E5878(0.26f, 1.227f, 0.586f);
EVec3 lbl_802E5884(0.011f, -2.874f, 1.569f);
EVec3 lbl_802E5890(-0.113f, 1.151f, 1.064f);
EVec3 lbl_802E589C(0.011f, -3.348f, 1.569f);
EVec3 lbl_802E58A8(0.274f, -5.759f, 1.297f);
EVec3 lbl_802E58B4(0.011f, -3.348f, 1.569f);
EVec3 lbl_802E58C0(2.324f, -3.402f, 1.311f);
EVec3 lbl_802E58CC(0.0f, 0.0f, 0.0f);
EVec3 lbl_802E58D8(3.5f, 2.0f, -0.5f);
EVec3 lbl_802E58E4(1.2f, 1.2f, 1.0f);
EVec3 lbl_802E58F0(-3.5f, -2.5f, -3.7f);
EVec3 lbl_802E58FC(0.8f, 0.8f, 0.8f);
EVec3 lbl_802E5908(-1.0f, 1.0f, 1.0f);
EVec3 lbl_802E5914(0.5f, 0.5f, 0.5f);
EVec3 lbl_802E5920(-0.546f, 1.905f, 2.5f);
EVec3 lbl_802E592C(0.15f, 0.15f, 0.2f);
EVec3 lbl_802E5938(-0.5f, 1.0f, 0.0f);
EVec3 lbl_802E5944(0.2f, 0.2f, 0.1f);
EVec3 lbl_802E5950(2.0f, 0.5f, 0.0f);
EVec3 lbl_802E595C(0.0f, 0.0f, 0.0f);

// Looks up a localized string by name; null when it does not exist.
inline int GetText(const char* name) {
    Unk800669ACResult result = lbl_802E6700.fn_800667EC(name);
    return result.ptr ? *result.ptr : 0;
}

// As GetText, through the other look-up (0x8006670C).
inline int GetTextB(const char* name) {
    Unk800669ACResult result = lbl_802E6700.fn_8006670C(name);
    return result.ptr ? *result.ptr : 0;
}

// 0x80008AA0
CASTarget::CASTarget() {
    unk52C0 = 0;
    unk48 = 0;
    unk45A8 = lbl_802E6700.unk17C;
    unk52C4 = lbl_802E6700.unk90;
}

// Deletes the text-entry dialog and restores the buttons it had hidden.
#define CAS_CLOSE_DIALOG()     \
    if (unk52FC) {             \
        delete unk52FC;        \
        unk52FC = 0;           \
        fn_800146A0();         \
    }
#define CAS_HIDE_PROMPT() fn_80106164(lbl_802E6700.unk90, "hideDialog", 0, 0, 0)

// 0x80008C08
// Per-frame update: UI sounds, the name dialogs, the yes/no prompts, input on
// the family page, the camera, and the animated props.
// NON_MATCHING: 2,091 instructions vs 2,073. Control flow follows the original branch
// for branch; known differences: this build keeps a separate register for the end of
// the four-sim array (the original derives it at each loop), gives the string and vector
// temporaries different stack slots (0x4C/0x50 against 0x48/0x50/0x58), and so numbers
// the saved registers differently throughout. Three variants tried.
void CASTarget::vfn2() {
    if (!((UnkViewer*)lbl_802E6700.unk90)->fn_801082CC()) {
        return;
    }
    if (fn_800E5DF8()->unk4) {
        fn_800E5DF8()->fn_800E5EA8("CharacterEdit Mode\n");
        vfn7(this, 3);
    }
    if (unk530C) {
        fn_80014A88();
        unk530C = 0;
    }
    if (unk5308) {
        int event = fn_80106774(unk52C4, 0, 0, 0, 1);
        if (unk52FC == 0) {
            switch ((unsigned int)event & 0x7FFFFFFF) {
            case 3:
            case 4:
                if (event < 0 && unk5334) {
                    lbl_8037D96C->fn_8006186C(0x867A1F00);
                }
                break;
            case 1:
            case 2:
                if (event < 0 && unk5330 && unk5304 == 0) {
                    lbl_8037D96C->fn_8006186C(0x867A1F00);
                }
                break;
            case 7:
                if (event < 0) {
                    lbl_8037D96C->fn_8006186C(0xCF99DB1E);
                }
                break;
            case 9:
                if (event < 0) {
                    lbl_8037D96C->fn_8006186C(0x048AE94F);
                }
                break;
            }
        }
    }

    if (unk52FC) {
        int result = unk52FC->fn_800CAEF0();
        if (result == 1) {
            // Accepted: tidy the text, then store it as family or first name.
            Unk801BA678* text = unk52FC->fn_800C6FAC();
            if (text) {
                Unk801BA678 space(" ");
                text->fn_801BAF74(*space.unk0);
                for (int i = 0; i < text->fn_801BA934(); i++) {
                    if (text->fn_801BAEE8(*space.unk0) == 0) {
                        Unk801BA678 shorter = text->fn_801BAC38(text->fn_801BA934() - 1);
                        text->fn_801BA860(shorter.unk0);
                    }
                }
                if (text->fn_801BA934() <= 0) {
                    Unk801BA678 fallback("Error");
                    text->fn_801BA860(fallback.unk0);
                }
                if (unk52D4) {
                    fn_8023C9FC(unk4478->unk400, text->unk0);
                    fn_8024254C(unk579C.unk0, text->unk0);
                    if (unk52E8 == 0) {
                        unk52D4 = 0;
                        if (unk57A0.fn_801BA934() > 0) {
                            unk52FC->fn_800C6F08((int)unk57A0.unk0, 9);
                        } else {
                            unk52FC->fn_800C6F08(GetText("default_text_firstname"), 9);
                        }
                        unk52FC->fn_800C6FB4(GetText("first"));
                        unk52FC->fn_800C6E5C(10);
                    } else {
                        unk52D4 = 0;
                        CAS_CLOSE_DIALOG();
                        unk45A0 = 1;
                        vfn7(this, 0x42);
                        vfn7(this, 0x41);
                        fn_800143E4();
                    }
                } else {
                    int i;
                    for (i = 0; i < text->fn_801BA934(); i++) {
                        unk4478->sims[unk45CA].unk28[i] = text->unk0[i];
                        unk57A0.unk0[i] = text->unk0[i];
                    }
                    unk4478->sims[unk45CA].unk28[i] = 0;
                    unk57A0.unk0[i] = 0;
                    CAS_CLOSE_DIALOG();
                    if (unk52E8 == 0) {
                        fn_8024254C(unk4478->sims[0].unk68, fn_8023C9EC(unk4478->unk400));
                        if (unk52F8) {
                            CAS_CLOSE_DIALOG();
                            unk52F8 = 0;
                        } else {
                            fn_800141C0();
                        }
                    } else {
                        unk4580 = 9;
                        if (unk52F8 == 0) {
                            delete unk4464;
                            unk4464 = new Unk80018374(unk45A8, 1, &unk3C8);
                            unk4464->unk14 = unk458C;
                            if (unk45A8) {
                                unk4584 = 0;
                            } else {
                                unk4584 = 1;
                            }
                        }
                        if (unk52F8) {
                            CAS_CLOSE_DIALOG();
                            unk52F8 = 0;
                        } else {
                            fn_800141C0();
                        }
                    }
                }
            }
        } else if (result == 2) {
            // Cancelled: step back from first name to family name, or leave.
            if (unk52D4) {
                Unk801BA678* text = unk52FC->fn_800C6FAC();
                if (text) {
                    fn_8024254C(unk579C.unk0, text->unk0);
                }
                if (unk52E8 == 0) {
                    fn_8024254C(unk4478->sims[0].unk68, fn_8023C9EC(unk4478->unk400));
                    unk52CC = 0;
                    unk52D8 = 0;
                    unk52DC = 0;
                    unk52E0 = 0;
                    if (unk52FC) {
                        delete unk52FC;
                        unk52FC = 0;
                    }
                } else {
                    if (unk52FC) {
                        delete unk52FC;
                        unk52FC = 0;
                    }
                }
                vfn7(this, 0x46);
                unk5318 = 1;
            } else {
                Unk801BA678* text = unk52FC->fn_800C6FAC();
                if (text && unk52F8 == 0) {
                    fn_8024254C(unk57A0.unk0, text->unk0);
                }
                if (unk52E8 == 0) {
                    if (unk52F8) {
                        CAS_CLOSE_DIALOG();
                        unk52F8 = 0;
                    } else {
                        unk52FC->fn_800C6F08((int)unk579C.unk0, 9);
                        unk52D4 = 1;
                        unk52FC->fn_800C6FB4(GetText("last"));
                        unk52FC->fn_800C6E5C(10);
                    }
                } else {
                    CAS_CLOSE_DIALOG();
                    if (unk52F8) {
                        unk4580 = 9;
                        unk52F8 = 0;
                    } else {
                        fn_800143E4();
                    }
                }
            }
        }
    }

    EController* controller = lbl_8037C11C->fn_8015E5FC(lbl_8037C11C->fn_8015E614(0));
    fn_8017A778(unk58);
    fn_8017A778(unk54);

    if (unk4580 == 4) {
    } else if (unk4580 == 5) {
        if (unk52E8) {
            unk45CC = 0x2D;
        }
    } else if (unk4580 == 6) {
        unk45CC = 0x28;
    } else if (unk4580 == 12 && unk45D0) {
        // A yes/no prompt is up; unk45D4 says which question it asked.
        if (unk461C.fn_8003A500() != -1) {
            int showButtons = 1;
            switch (unk45D4) {
            case 0: // leave Create-A-Sim?
                if (controller->fn_8015E204(5)) {
                    unk45D0 = 0;
                    CAS_HIDE_PROMPT();
                    fn_80014378();
                    unk4588 = -1;
                    *unk579C.unk0 = 0;
                    *unk57A0.unk0 = 0;
                } else {
                    unk45D0 = 0;
                    CAS_HIDE_PROMPT();
                    if (unk5318) {
                        if (unk52FC == 0) {
                            fn_80014770();
                            if (unk579C.fn_801BA934() > 0) {
                                unk52FC = new Unk800C6704((int)unk579C.unk0, 9, 0, GetText("last"), GetText("create a family"),
                                                          20, 0, 0.5f, 0.25f, 0.25f, 10, 0, 16, 0, 0, 0, 1, 0, 0, 1, 0, 0,
                                                          0, 1, 1, 0);
                            } else {
                                unk52FC = new Unk800C6704(GetText("default_text_lastname"), 9, 0, GetText("last"),
                                                          GetText("create a family"), 20, 0, 0.5f, 0.25f, 0.25f, 10, 0, 16,
                                                          0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0);
                            }
                            showButtons = 0;
                        }
                        unk5318 = 0;
                        unk4580 = 5;
                        unk45D0 = 0;
                    } else if (unk458C) {
                        unk4580 = 9;
                    } else {
                        unk4580 = 10;
                    }
                }
                break;
            case 1: // discard this sim?
                if (controller->fn_8015E204(5)) {
                    unk45D0 = 0;
                    CAS_HIDE_PROMPT();
                    ((UnkViewer*)lbl_802E6700.unk90)->fn_8010826C(this);
                    CAS_CLOSE_DIALOG();
                    fn_80014378();
                    unk52D4 = 0;
                    if (unk4468[unk45CA]) {
                        unk4468[unk45CA]->fn_8001E6E8(1, 1);
                    }
                    fn_800143E4();
                } else {
                    unk45D0 = 0;
                    CAS_HIDE_PROMPT();
                    ((UnkViewer*)lbl_802E6700.unk90)->fn_8010826C(this);
                    unk4580 = 9;
                }
                break;
            case 2: // discard the family?
                if (controller->fn_8015E204(5)) {
                    unk45D0 = 0;
                    CAS_HIDE_PROMPT();
                    ((UnkViewer*)lbl_802E6700.unk90)->fn_8010826C(this);
                    if (unk5318) {
                        unk5318 = 0;
                    } else {
                        fn_80014564();
                    }
                    unk4588 = -1;
                    *unk579C.unk0 = 0;
                    *unk57A0.unk0 = 0;
                } else {
                    unk45D0 = 0;
                    CAS_HIDE_PROMPT();
                    ((UnkViewer*)lbl_802E6700.unk90)->fn_8010826C(this);
                    if (unk5318) {
                        if (unk52FC == 0) {
                            fn_80014770();
                            int name = (int)unk579C.unk0;
                            int isDefault = 0;
                            if (unk579C.fn_801BA934() == 0) {
                                name = GetText("default_text_lastname");
                                isDefault = 1;
                            }
                            unk52FC = new Unk800C6704(name, 9, 0, GetText("last family"), GetText("create a family"), 20, 0,
                                                      0.5f, 0.25f, 0.25f, 10, 0, 16, 0, 0, 0, 1, 0, 0, 1, 0, isDefault, 0, 1,
                                                      1, 0);
                            showButtons = 0;
                        }
                        unk5318 = 0;
                        unk4580 = 5;
                    } else if (unk458C) {
                        unk4580 = 9;
                    } else {
                        unk4580 = 10;
                    }
                }
                break;
            case 3: // finish the single sim?
                if (controller->fn_8015E204(5)) {
                    unk45D0 = 0;
                    CAS_HIDE_PROMPT();
                    Unk80018374* sim = unk4464;
                    CASSimDesc* desc = &unk4478->sims[0];
                    sim->unkC8->fn_800226F0(&sim->unk16C);
                    desc->unkC = sim->unk16C;
                    fn_80010520(desc, 1);
                    desc->unkC.fn_801CC688();
                    unk4464->fn_8001C3B8();
                    desc->unkA8 = unk4464->fn_8001D04C();
                    unk4478->present[0] = 1;
                    unk4478->unk3F0[0] = 0;
                    if (unk458C && unk5314 == 0) {
                        fn_8023C9FC((char*)lbl_802E6700.unk118 + 0x84, desc->unk28);
                        fn_8023CA3C((char*)lbl_802E6700.unk118 + 0x3C, unk4478->unk400);
                        fn_80014914(0x4DEB3722, unk4478->sims[0].unkC.unk8[8]);
                        lbl_802E6700.unk118->unkCC = 0;
                    }
                    fn_80014378();
                    unk4588 = 1;
                } else {
                    unk45D0 = 0;
                    CAS_HIDE_PROMPT();
                    unk4580 = 9;
                    fn_800141C0();
                }
                break;
            case 4: // add this sim to the family?
                if (controller->fn_8015E204(5)) {
                    unk45D0 = 0;
                    CAS_HIDE_PROMPT();
                    CASSimDesc* desc = &unk4478->sims[unk45CA];
                    Unk80018374* sim = unk4464;
                    sim->unkC8->fn_800226F0(&sim->unk16C);
                    desc->unkC = sim->unk16C;
                    fn_80010520(desc, 1);
                    desc->unkC.fn_801CC688();
                    delete unk4468[unk45CA];
                    unk4468[unk45CA] = new Unk80018374(desc, &unk3C8, 0);
                    unk4468[unk45CA]->fn_8001E6E8(1, 1);
                    unk4468[unk45CA]->unk14 = unk458C;
                    unk3C8.fn_8001EFEC();
                    unk4468[unk45CA]->fn_8001C384();
                    unk3C8.fn_8001EFEC();
                    EVec2 place;
                    switch (unk45CA) {
                    case 0:
                        place.x = 0.74f;
                        place.y = -7.5f;
                        break;
                    case 1:
                        place.x = -0.34f;
                        place.y = -7.5f;
                        break;
                    case 2:
                        place.x = 0.18f;
                        place.y = -7.5f;
                        break;
                    case 3:
                        place.x = 1.3f;
                        place.y = -7.5f;
                        break;
                    case 4:
                        place.x = 3.6f;
                        place.y = -7.75f;
                        break;
                    case 5:
                        place.x = 0.5f;
                        place.y = -6.5f;
                        break;
                    case 6:
                        place.x = -1.4f;
                        place.y = -7.5f;
                        break;
                    default:
                        place.x = 2.5f;
                        place.y = -7.0f;
                        break;
                    }
                    unk4468[unk45CA]->unk154 = EVec3(place.x, place.y, 0.0f);
                    unk4468[unk45CA]->fn_8001E6E8(1, 1);
                    vfn7(this, 0x2E);
                    unk45BC = unk45C0;
                    if (unk4478->present[unk45CA] == 0) {
                        unk45C9++;
                        unk4478->present[unk45CA] = 1;
                        unk4478->unk3F0[unk45CA] = 0;
                    }
                    fn_80014378();
                    fn_800143E4();
                } else {
                    unk4580 = 9;
                    unk45D0 = 0;
                    CAS_HIDE_PROMPT();
                    fn_800141C0();
                }
                break;
            case 5: // remove a family member?
                if (controller->fn_8015E204(5)) {
                    unk45D0 = 0;
                    CAS_HIDE_PROMPT();
                    delete unk4468[unk45D5];
                    unk4468[unk45D5] = 0;
                    unk4478->unk3F0[unk45D5] = 0;
                    unk4478->present[unk45D5] = 0;
                    if (unk4478->sims[0].unkA8) {
                        if (lbl_8037C198->vfn22()) {
                            lbl_8037C198->vfn8();
                        }
                        lbl_8037C198->vfn21(unk4478->sims[0].unkA8);
                        unk4478->sims[0].unkA8 = 0;
                    }
                    unk45C9--;
                    unk4580 = 10;
                    fn_80106164(unk52C4, "showMenu", 0, 0, 0);
                } else {
                    unk45D0 = 0;
                    CAS_HIDE_PROMPT();
                    if (unk4468[unk45D5]) {
                        unk4468[unk45D5]->fn_8001E6E8(1, 0);
                    }
                    unk4580 = 10;
                    unk45AC = 1;
                    fn_80106164(unk52C4, "showMenu", 0, 0, 0);
                }
                break;
            case 7: // finish the family?
                if (controller->fn_8015E204(5)) {
                    unk45D0 = 0;
                    CAS_HIDE_PROMPT();
                    for (unsigned int i = 0; i <= 3; i++) {
                        if (unk4478->present[i] && unk4468[i]) {
                            unk4468[i]->fn_8001C3B8();
                            unk4478->sims[i].unkA8 = unk4468[i]->fn_8001D04C();
                        }
                    }
                    fn_80014564();
                    unk4588 = 1;
                } else {
                    unk45D0 = 0;
                    CAS_HIDE_PROMPT();
                    fn_800143E4();
                }
                break;
            case 8: // leave the family page?
                if (controller->fn_8015E204(5)) {
                    unk45D0 = 0;
                    CAS_HIDE_PROMPT();
                    fn_80014564();
                    unk4588 = -1;
                    fn_800143E4();
                } else {
                    unk45D0 = 0;
                    CAS_HIDE_PROMPT();
                    fn_800143E4();
                }
                break;
            }
            if (showButtons) {
                fn_800146A0();
            }
        }
    } else {
        int state = unk4580;
        if (state == 9) {
        } else if (state == 7) {
            unk4580 = state;
        } else if (state == 10 || state == 11) {
            // Family page.
            if (unk52E8) {
                fn_801887C8();
                if (unk45B0 >= 1.0f && unk45CC == 0) {
                    if (controller->fn_8015E0F8(7)) {
                        if (unk458C) {
                            unk4588 = -1;
                        } else if (unk4590 && unk4580 == 9) {
                            fn_800143E4();
                            for (Unk80018374** sim = unk4468, **last = sim + 3; sim <= last; sim++) {
                                if (*sim) {
                                    (*sim)->fn_8001E6E8(1, 1);
                                }
                            }
                            unk45BC = unk45C0;
                        } else if (unk3B4) {
                            unk4468[unk3B4->unk48->unk58]->fn_8001E6E8(1, 0);
                            unk4580 = 10;
                            unk45AC = 1;
                            fn_80106164(unk52C4, "showMenu", 0, 0, 0);
                            unk45BC = unk45C0;
                            for (int i = 0; i < unk45C9; i++) {
                                unk3B4->vfn15(unk3B8[i]);
                            }
                            vfn15(unk3B4);
                            unk459C = 1;
                        } else if (unk52FC) {
                            delete unk52FC;
                            unk52FC = 0;
                            fn_800143E4();
                            fn_800146A0();
                        }
                    } else if (controller->fn_8015E0F8(3) || controller->fn_8015E0F8(4)) {
                        if (unk45B0 >= 1.0f && unk45CC == 0 && unk3B4) {
                            unsigned char selected = unk3B4->unk48->unk58;
                            for (Unk80018374** sim = unk4468, **last = sim + 3; sim <= last; sim++) {
                                if (*sim) {
                                    (*sim)->fn_8001E6E8(1, 0);
                                }
                            }
                            unk4468[selected]->fn_8001E6E8(0, 0);
                        }
                    }
                }
            }
        } else if (state != 0) {
            if (controller->fn_8015E0F8(7)) {
                if (unk52FC == 0) {
                    fn_80010408();
                }
            } else {
                fn_801887C8();
            }
        }
    }

    fn_8000FCE4();
    if (unk4464) {
        // Which quarter the sim is seen from, from its turn angle.
        float angle = unk45B8;
        if (angle > 5.0f && angle < 5.9f) {
            unk4464->unk40 = 1;
        } else if (angle > 3.1f && angle < 4.1f) {
            unk4464->unk40 = 2;
        } else if (angle > 1.0f && angle < 2.3f) {
            unk4464->unk40 = 3;
        } else {
            unk4464->unk40 = 0;
        }
    }
    if (unk4590) {
        float stick = controller->fn_8015DEE4(1, 0);
        if (stick != 0.0f) {
            float degrees = (stick + stick) * 45.0f * lbl_8037BFC8 + ERadToDeg(unk45B8);
            if (degrees > 360.0) {
                degrees = degrees - 360.0;
            } else if (degrees < 0.0) {
                degrees = degrees + 360.0;
            }
            unk45B8 = EDegToRad(degrees);
        }
        if (unk52E8) {
            unk4464->fn_8001AE1C(unk52CC, unk533C);
        } else {
            unk4464->fn_8001AE1C(unk52CC, unk533C);
        }
    }
    for (Unk80018374** sim = unk4468, **last = sim + 3; sim <= last; sim++) {
        if (*sim) {
            (*sim)->fn_8001AC88();
        }
    }

    // The parrot, the thief and the window: unk52B9 steps through their routine.
    if (unk523C.fn_8015AA0C(1)) {
        if (unk52B9 == 10) {
            unk52B9++;
        }
        if (unk52B9 == 0) {
            int roll = fn_801115C4() % 8;
            if (roll == 0) {
                unk52B9 = 1;
            } else if (roll == 1) {
                unk52B9 = 10;
            }
        }
        if (unk52B9 == 3 || unk52B9 == 11) {
            unk52B9 = 0;
        }
        if (unk52B9 == 1) {
            unk4EF0.fn_80159994(1, (*unk52B4)[4]);
            unk52B9++;
            unk523C.fn_8015A520(1);
        } else if (unk52B9 == 2) {
            if (fn_801115C4() % 2 == 0) {
                unk4EF0.fn_80159994(1, (*unk52B4)[5]);
                unk52B9++;
                unk523C.fn_80159994(1, (*unk52B0)[1]);
                unk4FDC.fn_80159994(1, (*unk5050)[1]);
            } else {
                unk4EF0.fn_80159994(1, (*unk52B4)[7]);
                unk52B9++;
                unk523C.fn_80159994(1, (*unk52B0)[0]);
                unk4FDC.fn_80159994(1, (*unk5050)[0]);
            }
            unk523C.fn_8015A520(1);
        } else if (unk52B9 == 10) {
            unk4EF0.fn_80159994(1, (*unk52B4)[6]);
            unk523C.fn_80159994(1, (*unk52B0)[0]);
            unk4FDC.fn_80159994(1, (*unk5050)[2]);
            unk523C.fn_8015A520(1);
        } else {
            unk523C.fn_80159994(1, (*unk52B0)[0]);
            unk4FDC.fn_80159994(1, (*unk5050)[0]);
            unk523C.fn_8015A520(1);
        }
    } else {
        unk523C.fn_801569F8(0, 0, EVec3(1.0f));
        if (unk52B9) {
            unk4EF0.fn_801569F8(0, 0, EVec3(1.0f));
        }
    }
    unk4FDC.fn_801569F8(0, 0, EVec3(1.0f));
    unk50DC[0].fn_801569F8(0, 0, EVec3(1.0f));
    unk50DC[1].fn_801569F8(0, 0, EVec3(1.0f));
    if (unk52B9 <= 1 && unk4FDC.fn_8015AA0C(1)) {
        unk4FDC.fn_8015A520(1);
    }

    if (unk459C) {
        for (int i = 0; i < 4; i++) {
            if (unk3B8[i]) {
                delete unk3B8[i];
                unk3B8[i] = 0;
            }
        }
        if (unk3B4) {
            delete unk3B4;
        }
        unk459C = 0;
        unk3B4 = 0;
    }
    fn_801063A0(unk52C4);
}

// 0x8000AC6C
// NON_MATCHING: 4 of 193 differ. For the first two calls on `toAxis` the original sets
// up r4 before r3; this build does r3 first (the same pattern as the text copies in
// fn_800102B0).
// Builds the reflection matrix for the plane through the three corners: rotate
// the plane normal onto an axis, flip that axis, rotate back.
void CASMirror::fn_8000AC6C() {
    EVec3 normal = (unk40[1] - unk40[0]).Cross(unk40[2] - unk40[1]);
    normal.Normalize();
    EVec3 axis(0.0f, 0.0f, 1.0f);
    int index = 2;
    float angle = fn_8010DB14(normal.Dot(axis));
    if (angle > EDegToRad(175.0f)) {
        axis.Set(0.0f, 1.0f, 0.0f);
        index = 1;
        angle = fn_8010DB14(normal.Dot(axis));
    }
    EVec3 rotAxis = normal.Cross(axis);
    rotAxis.Normalize();
    EMat4 toAxis;
    toAxis.fn_801B3024(rotAxis, angle);
    toAxis.fn_801B2988(-unk40[0]);
    EVec3 scale(1.0f);
    scale[index] = -1.0f;
    toAxis.fn_801B3494(scale);
    EMat4 back;
    back.fn_801B3024(rotAxis, -angle);
    back.fn_801B345C(unk40[0]);
    EMat4 product;
    product.fn_801B2888(&toAxis, &back);
    unk0.Copy64(product);
}

// 0x8000AF70
void CASMirror::fn_8000AF70(Unk801543AC* view) {
    unk8C.Copy64(view->unkA0);
    EMat4 product;
    product.fn_801B2888(&unk0, &view->unkA0);
    view->fn_801546D8(&product);
}

// 0x8000B03C
void CASMirror::fn_8000B03C(Unk801543AC* view) {
    view->fn_801546D8(&unk8C);
}

// Sets the render state used for both mirror-related quads.
#define CAS_MIRROR_STATE(rc)        \
    rc->vfn35(0, 0);                \
    rc->vfn38(0);                   \
    rc->vfn41(0x48, 0);             \
    rc->vfn61(2, 2, 2, 1, 0, 0);    \
    rc->vfn54(1, 1, 0, 0);          \
    rc->vfn55(0, 5, 0, 0.5f);       \
    rc->vfn60(0, 0)

// Draws the shadow pieces of a prop model with the shadow material.
#define CAS_DRAW_SHADOWS(rc, model, material)                      \
    for (int g = 0; g < model->unk24; g++) {                       \
        EModelGroup* group = &model->unk20[g];                     \
        for (int n = 0; n < group->unk4; n++) {                    \
            Unk80184C00* piece = &group->unk0[n];                  \
            material->unk20->vfn3(rc);                             \
            rc->vfn36(0x4000);                                     \
            rc->vfn37(8);                                          \
            rc->vfn56(0, 2, 0);                                    \
            piece->fn_80184C00(rc);                                \
            rc->vfn37(0x4000);                                     \
            rc->vfn36(8);                                          \
        }                                                          \
    }

// 0x8000B068
// Draws the screen: the room reflected in the mirror, the mirror itself, the
// room, the sims and props, then the 2D overlay.
// NON_MATCHING: 1,327 instructions vs 1,240. Same calls in the same order. The original
// runs out of registers and keeps the addresses of its temporaries in stack slots
// (0x4B8-0x4F8), builds each quad's five temporaries in fixed slots it reuses, and
// assigns the point lights in one interleaved run; this build lays the frame out
// differently (and re-loads addresses instead). One variant tried.
void CASTarget::vfn3(ERC* rc) {
    ELightSet lights;
    lights.ambient = lbl_802E58CC;
    lights.directional[0].color = lbl_802E58E4;
    lights.directional[1].color = lbl_802E58FC;
    lights.directional[2].color = lbl_802E5914;
    lights.directional[0].direction = lbl_802E58D8;
    lights.directional[1].direction = lbl_802E58F0;
    lights.directional[2].direction = lbl_802E5908;
    lights.numPoint = 3;
    lights.numDirectional = 3;
    // The three point lights are assigned twice in the original.
    for (int pass = 0; pass < 2; pass++) {
        lights.point[0].position = lbl_802E5920;
        lights.point[0].color = lbl_802E592C;
        lights.point[0].range = 4.0f;
        lights.point[1].position = lbl_802E5938;
        lights.point[1].color = lbl_802E5944;
        lights.point[1].range = 1.0f;
        lights.point[2].position = lbl_802E5950;
        lights.point[2].color = lbl_802E595C;
        lights.point[2].range = 2.0f;
    }
    lights.directional[0].direction.Normalize();
    lights.directional[1].direction.Normalize();

    float fov = unk45BC * (float)lbl_8037C198->unk18 / (float)lbl_8037C198->unk14;
    unk5C.fn_80154490(fov, lbl_8037C198->vfn37(), 0.25f, 50.0f);
    EVec3 up(0.0f, 0.0f, 1.0f);
    unk5C.fn_80154798(unk36C, unk390, up);
    unk5C.fn_80156018(rc);

    // Reflection pass.
    CASMirror mirror;
    rc->vfn92();
    mirror.unk40[0] = EVec3(0.543f, 1.75f, 0.111f);
    mirror.unk40[1] = EVec3(0.865f, 1.592f, 0.111f);
    mirror.unk40[2] = EVec3(0.865f, 1.592f, 1.998f);
    mirror.unk40[3] = EVec3(0.543f, 1.75f, 1.998f);
    mirror.unk88 = 4;
    mirror.fn_8000AC6C();
    mirror.fn_8000AF70(&unk5C);
    CAS_MIRROR_STATE(rc);
    rc->vfn47(EVec2(0.0f, 0.0f), EVec2(1.0f, 1.0f), EVec2(0.0f, 0.0f), EVec2(0.0f, 0.0f), EColorF(1.0f, 1.0f, 1.0f, 1.0f),
              0.0f);

    // The mirror surface as a four-vertex strip (corners 0, 1, 3, 2).
    EVertex vertices[4];
    for (int i = 0; i < 4; i++) {
        int corner;
        if (i == 2) {
            corner = 3;
        } else if (i == 3) {
            corner = 2;
        } else {
            corner = i;
        }
        vertices[i].position.x = mirror.unk40[corner].x;
        vertices[i].position.y = mirror.unk40[corner].y;
        vertices[i].position.z = mirror.unk40[corner].z;
        vertices[i].w = 1.0f;
        vertices[i].unk10[0] = 0;
        vertices[i].unk10[1] = 0;
        vertices[i].unk10[2] = 0;
        vertices[i].unk10[3] = 0;
        vertices[i].unk30[0] = 0;
        vertices[i].unk30[1] = 0;
        vertices[i].unk30[2] = 0;
        vertices[i].unk3C = 0xFF;
    }
    vertices[0].u = 0.0f;
    vertices[0].v = 0.0f;
    vertices[1].u = 1.0f;
    vertices[1].v = 0.0f;
    vertices[2].u = 0.0f;
    vertices[2].v = 1.0f;
    vertices[3].u = 1.0f;
    vertices[3].v = 1.0f;
    EMat4 projection;
    float mirrorFov = unk45C4 * (float)lbl_8037C198->unk18 / (float)lbl_8037C198->unk14;
    projection.fn_801B3834(mirrorFov, lbl_8037C198->vfn37(), 0.0001f, 1000.0f);
    rc->vfn31(&projection);
    rc->vfn29();
    rc->vfn3(vertices, 4);
    unk5C.fn_80156018(rc);
    fn_8017AA14(unk54, rc);
    if (unk4590) {
        unk4464->fn_8001A908(rc, unk45B8, 1);
    }
    mirror.fn_8000B03C(&unk5C);
    unk5C.fn_80156018(rc);

    // The mirror's own surface.
    CAS_MIRROR_STATE(rc);
    rc->vfn56(0, 0, 1);
    rc->vfn47(EVec2(0.0f, 0.0f), EVec2(1.0f, 1.0f), EVec2(0.0f, 0.0f), EVec2(0.0f, 0.0f), EColorF(1.0f, 1.0f, 1.0f, 1.0f),
              1.0f);
    unk4C->fn_80181824(rc);
    rc->vfn29();
    rc->vfn3(vertices, 4);

    // Main pass.
    up = EVec3(0.0f, 0.0f, 1.0f);
    unk5C.fn_80154798(unk36C, unk390, up);
    unk5C.fn_80156018(rc);
    fn_8017AA14(unk58, rc);
    fn_8017AA14(unk54, rc);
    if (unk4590) {
        unk4464->fn_8001A908(rc, unk45B8, 1);
    }
    for (Unk80018374** sim = unk4468, **last = sim + 3; sim <= last; sim++) {
        if (*sim) {
            (*sim)->fn_8001A908(rc, 0.0f, 1);
        }
    }

    EMat4 place;
    place.fn_801B2AFC();
    place.fn_801B3024(EVec3(0.0f, 0.0f, 1.0f), lbl_8037B458);
    place.fn_801B345C(EVec3(lbl_8037B44C, lbl_8037B450, lbl_8037B454));
    rc->vfn44(&lights);
    unk50DC[1].fn_8015B044(rc, unk50D4, &place);

    // View used for the shadows: flattened and lifted slightly off the floor.
    EMat4 shadowView;
    shadowView.fn_801B2AFC();
    shadowView.m[2][0] = 0.2f;
    shadowView.m[2][1] = 0.2f;
    shadowView.m[2][2] = 0.0f;
    shadowView.fn_801B345C(EVec3(0.0f, 0.0f, 0.01f));
    EMat4 savedView;
    savedView.Copy64(lbl_8037C0E0->unkA0);
    EMat4 product;
    product.fn_801B2888(&shadowView, &savedView);
    fn_80015070(shadowView, product);
    EMat4 shadowViewCopy;
    fn_80015070(shadowViewCopy, shadowView);
    ((Unk80182DE0*)lbl_80340AB8.fn_80177628(0xA785BD26, 0, 0))->fn_80182DE0(0.25f);

    if (unk4590) {
        place.fn_801B2AFC();
        if (unk52B9) {
            unk4EF0.fn_8015B044(rc, unk4EE8, &place);
        }
        unk4FDC.fn_8015B044(rc, unk4FD8, &place);
        place.fn_801B2AFC();
        place.fn_801B3024(EVec3(0.0f, 0.0f, 1.0f), lbl_8037B468);
        place.fn_801B345C(EVec3(lbl_8037B45C, lbl_8037B460, lbl_8037B464));
        unk50DC[0].fn_8015B044(rc, unk50D0, &place);
        rc->vfn30(&shadowView);
        Unk80182DE0* material = (Unk80182DE0*)lbl_80340AB8.fn_80177628(0xA785BD26, 0, 0);
        CAS_DRAW_SHADOWS(rc, unk50D0, material);
        rc->vfn56(0, 0, 0);
        rc->vfn30(&savedView);
        place.fn_801B3024(EVec3(0.0f, 0.0f, 1.0f), lbl_8037B478);
        place.fn_801B345C(EVec3(lbl_8037B46C, lbl_8037B470, lbl_8037B474));
        unk523C.fn_8015B044(rc, unk5238, &place);
        rc->vfn30(&shadowView);
        CAS_DRAW_SHADOWS(rc, unk5238, material);
        rc->vfn56(0, 0, 0);
        rc->vfn30(&savedView);
    }

    // 2D overlay.
    if (unk52E8) {
        fn_80188850(rc);
        if (unk4580 == 6) {
            Unk8003C95C* font = lbl_802E6700.unkEC;
            font->fn_8003DBE8(rc);
            font->fn_8003C95C(1, 16.0f, 1.0f);
            lbl_802E6700.unkEC->unk64 = lbl_802E6964;
            EVec2 position(0.5f, 0.142f);
            EVec2 at(position);
            lbl_802E6700.unkEC->fn_8003D740(rc, (const unsigned short*)GetText("last"), 1, &at, 2, 0, 0);
        } else if (unk4580 == 7) {
            Unk8003C95C* font = lbl_802E6700.unkEC;
            font->fn_8003DBE8(rc);
            font->fn_8003C95C(1, 16.0f, 1.0f);
            lbl_802E6700.unkEC->unk64 = lbl_802E6964;
            EVec2 position(0.5f, 0.142f);
            EVec2 at(position);
            lbl_802E6700.unkEC->fn_8003D740(rc, (const unsigned short*)GetText("first"), 1, &at, 2, 0, 0);
        }
        fn_80106484(unk52C4, rc);
        if (fn_801082B4(unk52C4)) {
            fn_800123A4(rc);
        }
        fn_80013784(rc);
    } else {
        fn_80106484(unk52C4, rc);
        if (fn_801082B4(unk52C4)) {
            fn_800123A4(rc);
        }
        fn_80013784(rc);
    }
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

// 0x8000C5DC
// First loading step: resets the screen's state, fetches the font and button
// captions, and sets the default names, colours and camera.
// NON_MATCHING: 384 instructions vs 383. Same statements in the same order; the saved
// registers are numbered differently (r25-r29) and one address load is placed one slot
// earlier, which shifts the rest. Two variants tried.
void CASTarget::fn_8000C5DC() {
    unk52E4 = (Unk8003C95C*)lbl_8033F964.fn_80177628(lbl_802E6700.fn_800655D8(), 0, 0);
    unk45B8 = 3.0f;
    unk5308 = 1;
    unk52D0 = 1;
    unk52D4 = 1;
    unk52E8 = 0;
    unk458C = 0;
    unk4590 = 0;
    unk4598 = 0;
    unk459C = 0;
    unk45A0 = 0;
    unk45A4 = 0;
    unk3B4 = 0;
    unk45CC = 0;
    unk52D8 = 0;
    unk52DC = 0;
    unk52E0 = 0;
    unk52F0 = 0;
    unk52F4 = 0;
    unk52F8 = 0;
    unk5300 = 0;
    unk5304 = 0;
    unk530C = 0;
    unk5310 = 0;
    unk5318 = 0;
    unk45AC = 0;
    unk531C = 0;
    unk5320 = 0;
    unk5324 = 0;
    unk5330 = 0;
    unk5334 = 0;
    unk5338 = 0;
    unk45E0 = EVec2(0.0f, 0.0f);
    unk45E8 = EVec2(0.0f, 0.0f);
    unk45F0 = EVec2(0.0f, 0.0f);
    unk45F8 = EVec2(0.0f, 0.0f);
    unk4600 = EVec2(0.0f, 0.0f);
    unk4608 = EVec2(0.0f, 0.0f);
    unk4610 = EVec2(0.0f, 0.0f);
    unk4618 = 0;
    unk461C.fn_80039F1C();
    unk4EAC = GetTextB("no");
    unk4EB0 = GetTextB("yes");
    unk4EB4 = GetTextB("yes");
    unk4EB8 = GetTextB("no");
    unk4EBC = GetText("cancel");
    unk4EC8 = GetText("cancel");
    unk4ED0 = 0.86f;
    unk4ED4 = 0.8f;
    unk4ED8 = lbl_802E6700.fn_800667EC("accept").ptr;
    unk4EDC = 0.86f;
    unk4EE0 = 0.9f;
    unk4EE4 = lbl_802E6700.fn_800667EC("cancel").ptr;
    unk52B9 = 0;
    unk579C.fn_801BA958(0x20, 0);
    fn_8024254C(unk579C.unk0, lbl_8037D2D8.fn_801C5B24());
    unk57A0.fn_801BA958(0x20, 0);
    fn_8024254C(unk57A0.unk0, lbl_8037D2D8.fn_801C5B24());
    unk57A4.fn_801BA958(0x20, 0);
    fn_8024254C(unk57A4.unk0, fn_80014110());
    unk5C98.fn_801BA958(0x20, 0);
    fn_8024254C(unk5C98.unk0, lbl_8037D2D8.fn_801C5B24());
    unk5C9C.fn_801BA958(0x20, 0);
    fn_8024254C(unk5C9C.unk0, lbl_8037D2D8.fn_801C5B24());
    unk52EC.fn_801BA18C(0x32);
    strcpy(unk52EC.unk0, "");
    unk45C9 = 0;
    for (int i = 0; i < 4; i++) {
        unk3B8[i] = 0;
        unk4468[i] = 0;
    }
    lbl_80341458.unk0 = EColorF(0.0f, 0.0f, 0.0f, 1.0f);
    lbl_80341458.unk10 = EColorF(1.0f, 1.0f, 1.0f, 1.0f);
    unk533C[0].fn_80015908(5);
    unk533C[1].fn_80015908(5);
    unk533C[2].fn_80015908(5);
    unk533C[3].fn_80015908(5);
    unk533C[4].fn_80015908(5);
    fn_80014110();
    unk52CC = 0;
    unk36C = lbl_802E57DC;
    unk390 = lbl_802E57E8;
    unk378 = lbl_802E57DC;
    unk39C = lbl_802E57E8;
    unk384 = lbl_802E57DC;
    unk3A8 = lbl_802E57E8;
    unk52B8 = 0;
    unk45C8 = 0x28;
    unk45BC = 45.0f;
    unk45B4 = 0.0f;
    unk45B0 = 0.0f;
    unk45C4 = 45.0f;
    unk45C0 = 45.0f;
}

// 0x8000CBD8
void CASTarget::fn_8000CBD8() {
    Unk80340AB8* manager = &lbl_80340AB8;
    unk4C = (Unk80181824*)manager->fn_80177628(0xAB5FDCCC, 0, 0);
    unk50 = (Unk80181824*)manager->fn_80177628(0x0F303F75, 0, 0);
}

// 0x8000CC40
void CASTarget::fn_8000CC40() {
    Unk803401C4* manager = &lbl_803401C4;
    unk4574 = manager->fn_80177628(0x2A2AF469, 0, 0);
    unk4578 = (Unk801800FC*)manager->fn_80177628(0x23428ABB, 0, 0);
    unk457C = manager->fn_80177628(0xA173A1EE, 0, 0);
    Unk8033FA38* manager2 = &lbl_8033FA38;
    unk54 = manager2->fn_80177628(0xF56854CE, 0, 0);
    unk58 = manager2->fn_80177628(0x3A7628B6, 0, 0);
}

// 0x8000CD04
// Last loading step: the default sim and the animated props around it.
void CASTarget::fn_8000CD04() {
    unk4580 = 0;
    unk4464 = new Unk80018374(unk45A8, 1, &unk3C8);
    if (unk45A8) {
        unk4584 = 0;
    } else {
        unk4584 = 1;
    }
    int list = unk4578->Find("CasAnimationIDList");
    unk52B4 = unk4578->fn_8018021C(list, "Thief");
    Unk8033FF34* models = &lbl_8033FF34;
    unk4EE8 = models->fn_80177628(0x992EEB73, 0, 0);
    unk4EF0.fn_80156700(0x1FB80AF4);
    unk4EF0.SetUnk54(unk4EE8->unk6C);
    unk4EEC = models->fn_80177628(0x21995ECE, 0, 0);
    unk4F64.fn_80156700(0x6264D711);
    unk4F64.SetUnk54(unk4EEC->unk6C);
    unk4F64.fn_80159994(1, 0x21995ECE);
    unk5050 = unk4578->Get(list, "Window");
    unk4FD8 = models->fn_80177628(0xA5D1396A, 0, 0);
    unk4FDC.fn_80156700(0xA5D1396A);
    unk4FDC.SetUnk54(unk4FD8->unk6C);
    unk4FDC.fn_80159994(1, **unk5050);
    unk5054 = models->fn_80177628(0xAE65D4A9, 0, 0);
    unk5058.fn_80156700(0xAE65D4A9);
    unk5058.SetUnk54(unk5054->unk6C);
    unk5058.fn_80159994(1, 0x04EB1CCF);
    unk50D0 = models->fn_80177628(0x4072E590, 0, 0);
    unk50DC[0].fn_80156700(0x4072E590);
    unk50DC[0].SetUnk54(unk50D0->unk6C);
    unk50DC[0].fn_80159994(1, 0x561D9AAC);
    unk50D4 = models->fn_80177628(0x2925E2DF, 0, 0);
    unk50DC[1].fn_80156700(0x2925E2DF);
    unk50DC[1].SetUnk54(unk50D4->unk6C);
    unk50DC[1].fn_80159994(1, 0x73565E14);
    unk50D8 = models->fn_80177628(0x08559636, 0, 0);
    unk52B0 = unk4578->fn_8018021C(list, "Parrot");
    unk5238 = models->fn_80177628(0xF911768A, 0, 0);
    unk523C.fn_80156700(0xF911768A);
    unk523C.SetUnk54(unk5238->unk6C);
    unk523C.fn_80159994(1, **unk52B0);
}

// 0x8000D010
void CASTarget::fn_8000D010() {
    lbl_8037CA80 = 0;
    lbl_8037C230 = 0;
}

// 0x8000D020
// NON_MATCHING: 2 of 130 differ. In the delete loop the original decrements the
// counter after stepping the array pointer; here the decrement is scheduled two
// instructions earlier (the same loop pattern as fn_8000FA68).
void CASTarget::fn_8000D020(CASFamily* family, int edit) {
    unk5314 = edit;
    unk458C = 1;
    unk4478 = family;
    unk52E8 = 0;
    unk4590 = 0;
    unk45A0 = 0;
    unk45CA = 0;
    unk4588 = 0;
    unk45C9 = 0;
    for (int i = 0; i < 4; i++) {
        delete unk4468[i];
        unk4468[i] = 0;
        unk4478->sims[i].unkA8 = 0;
    }
    delete unk4464;
    if (unk5314) {
        unk4464 = new Unk80018374(&unk4478->sims[unk45CA], &unk3C8, 0);
        unk4464->unk14 = unk458C;
        if (unk4464->unk16C.unk4) {
            if (unk4464->unk16C.unk0) {
                unk4584 = 0;
            } else {
                unk4584 = 1;
            }
        } else {
            if (unk4464->unk16C.unk0) {
                unk4584 = 2;
            } else {
                unk4584 = 3;
            }
        }
    } else {
        unk4464 = new Unk80018374(unk45A8, 1, &unk3C8);
        unk4464->unk14 = 1;
        if (unk45A8) {
            unk4584 = 0;
        } else {
            unk4584 = 1;
        }
    }
    unk4464->unk8 = 1;
    unk384 = lbl_802E57DC;
    unk3A8 = lbl_802E57E8;
    unk45C8 = 0x28;
    unk45BC = unk45C4;
}

// 0x8000D228
// Shows the first page: the sim editor when editing, the family-name dialog
// when creating.
void CASTarget::fn_8000D228() {
    if (unk5314) {
        CASSimDesc* desc = &unk4478->sims[unk45CA];
        unk533C[0].fn_80015908(desc->unk0[5]);
        unk533C[1].fn_80015908(desc->unk0[4]);
        unk533C[2].fn_80015908(desc->unk0[1]);
        unk533C[3].fn_80015908(desc->unk0[3]);
        unk533C[4].fn_80015908(desc->unk0[0]);
        unk57A8.unk48 = desc->unk0[6];
        fn_800141C0();
    } else {
        if (unk52FC == 0) {
            fn_80014770();
            unk52FC = new Unk800C6704(GetText("default_text_lastname"), 9, 0, GetText("last"),
                                      GetText("create a family"), 20, 0, 0.5f, 0.25f, 0.25f, 10, 0, 16, 0, 0, 0, 1, 0, 0, 1,
                                      0, 1, 0, 1, 1, 0);
        }
        unk4580 = 6;
        unk45A0 = 0;
    }
    vfn7(this, 0x40);
    vfn7(this, 0x41);
}

// 0x8000D440
// Shows the family line-up: rebuilds the sims of `family` (all four, or only
// `which`) and stands them at their places.
void CASTarget::fn_8000D440(CASFamily* family, int edit, int which) {
    EVec3 position(0.0f);
    unk458C = 0;
    unk4590 = 0;
    unk45C9 = 0;
    for (int i = 0; i < 4; i++) {
        if (family->present[i]) {
            unk45C9++;
        }
    }
    unk4478 = family;
    unk52E8 = 1;
    unk5314 = edit;
    int first = 0;
    int end = 4;
    if (which != -1) {
        first = which;
        end = first + 1;
    }
    for (int i = first; i < end; i++) {
        if (unk4468[i]) {
            delete unk4468[i];
            unk4468[i] = 0;
        }
        if (unk4478->present[i]) {
            unk3C8.fn_8001FAE0();
            unk3C8.fn_8001F34C();
            unk4468[i] = new Unk80018374(&unk4478->sims[i], &unk3C8, 0);
            unk4468[i]->unk14 = unk458C;
            unk3C8.fn_8001EFEC();
            unk4468[i]->fn_8001C384();
            switch (i) {
            case 0:
                position.x = 0.74f;
                position.y = -7.5f;
                break;
            case 1:
                position.x = -0.34f;
                position.y = -7.5f;
                break;
            case 2:
                position.x = 0.18f;
                position.y = -7.5f;
                break;
            case 3:
                position.x = 1.3f;
                position.y = -7.5f;
                break;
            case 4:
                position.x = 3.6f;
                position.y = -7.75f;
                break;
            case 5:
                position.x = 0.5f;
                position.y = -6.5f;
                break;
            case 6:
                position.x = -1.4f;
                position.y = -7.5f;
                break;
            default:
                position.x = 2.5f;
                position.y = -7.0f;
                break;
            }
            unk4468[i]->SetUnk154(position);
            unk4468[i]->fn_8001E6E8(1, 1);
        } else {
            unk4468[i] = 0;
            unk4478->sims[i].unkA8 = 0;
        }
    }
    unk384 = lbl_802E589C;
    unk3A8 = lbl_802E58A8;
    unk45C8 = 0x2D;
    unk45B0 = 0.0f;
    unk45BC = unk45C0;
}

// 0x8000D7D8
void CASTarget::fn_8000D7D8() {
    if (unk45C9) {
        unk45A0 = 0;
        unk4580 = 0;
        if (unk52FC) {
            delete unk52FC;
            unk52FC = 0;
        }
        unk52D4 = 0;
        fn_800143E4();
        fn_800146A0();
    } else {
        unk4580 = 5;
        unk45A0 = unk45C9;
        if (unk52FC == 0) {
            fn_80014770();
            unk52FC = new Unk800C6704(GetText("default_text_lastname"), 9, 0, GetText("last family"), 0, 0, 0, 0.5f,
                                      0.25f, 0.25f, 10, 0, 16, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0);
        }
    }
    unk4588 = 0;
}

// Asks a yes/no question; the answer is handled in vfn2 by `kind`.
#define CAS_ASK(question, title, body, kind)                                                    \
    {                                                                                           \
        fn_80014770();                                                                          \
        EVec2 at(0.2f, 0.2f);                                                                   \
        unk461C.fn_8003A0C0(&at, 2, &unk4EAC, GetText(question), 0, 1, 0.6f);                   \
        unk45D8 = lbl_802E6700.fn_800667EC(title).ptr;                                          \
        unk45DC = lbl_802E6700.fn_800667EC(body).ptr;                                           \
        unk4580 = 12;                                                                           \
        unk45D4 = kind;                                                                         \
        fn_80106164(lbl_802E6700.unk90, "showDialog", 0, 0, 0);                                 \
        unk45D0 = 0;                                                                            \
    }

// Copies the edited sim into `desc` and places a finished copy in the line-up.
#define CAS_STORE_SIM(desc)                         \
    Unk80018374* sim = unk4464;                     \
    sim->unkC8->fn_800226F0(&sim->unk16C);          \
    (desc)->unkC = sim->unk16C;                     \
    fn_80010520(desc, 1);                           \
    (desc)->unkC.fn_801CC688()

// 0x8000D970
// Message handler: everything the UI script and the widgets ask of the screen.
// NON_MATCHING: 2,027 instructions vs 2,074. Every case is present with the original's
// calls; the original repeats the yes/no prompt set-up and the sim-storing sequence with
// slightly different tails per case (shared here through macros), keeps its frame 0x10
// smaller, and dispatches through the same compare tree. One variant tried.
void CASTarget::vfn7(UnkTargetBase* sender, int message) {
    switch ((unsigned int)message) {
    case 3: // accept
        if (unk458C) {
            if (fn_800E5DF8()->unk4) {
                CASSimDesc* desc = &unk4478->sims[0];
                CAS_STORE_SIM(desc);
                unk4464->fn_8001C3B8();
                desc->unkA8 = unk4464->fn_8001D04C();
                unk4478->present[0] = 1;
                unk4478->unk3F0[0] = 0;
                if (unk458C && unk5314 == 0) {
                    fn_8023C9FC((char*)lbl_802E6700.unk118 + 0x84, desc->unk28);
                    fn_8023CA3C((char*)lbl_802E6700.unk118 + 0x3C, unk4478->unk400);
                    fn_80014914(0x4DEB3722, unk4478->sims[0].unkC.unk8[8]);
                }
                fn_80014378();
                unk4588 = 1;
            } else {
                CAS_ASK("cancel warning", "dialog accept title", "dialog accept", 3);
            }
        } else {
            CASSimDesc* desc = &unk4478->sims[unk45CA];
            CAS_STORE_SIM(desc);
            delete unk4468[unk45CA];
            unk4468[unk45CA] = new Unk80018374(desc, &unk3C8, 0);
            unk4468[unk45CA]->fn_8001E6E8(1, 1);
            unk4468[unk45CA]->unk14 = unk458C;
            unk3C8.fn_8001EFEC();
            unk4468[unk45CA]->fn_8001C384();
            unk3C8.fn_8001EFEC();
            EVec2 place;
            switch (unk45CA) {
            case 0:
                place.x = 0.74f;
                place.y = -7.5f;
                break;
            case 1:
                place.x = -0.34f;
                place.y = -7.5f;
                break;
            case 2:
                place.x = 0.18f;
                place.y = -7.5f;
                break;
            case 3:
                place.x = 1.3f;
                place.y = -7.5f;
                break;
            case 4:
                place.x = 3.6f;
                place.y = -7.75f;
                break;
            case 5:
                place.x = 0.5f;
                place.y = -6.5f;
                break;
            case 6:
                place.x = -1.4f;
                place.y = -7.5f;
                break;
            default:
                place.x = 2.5f;
                place.y = -7.0f;
                break;
            }
            unk4468[unk45CA]->unk154 = EVec3(place.x, place.y, 0.0f);
            unk4468[unk45CA]->fn_8001E6E8(1, 1);
            vfn7(this, 0x2E);
            unk45BC = unk45C0;
            if (unk4478->present[unk45CA] == 0) {
                unk45C9++;
                unk4478->present[unk45CA] = 1;
                unk4478->unk3F0[unk45CA] = 0;
            }
            fn_80014378();
            fn_800143E4();
        }
        break;
    case 0x4:
        unk4580 = 0;
        break;
    case 0x5:
        unk4598 = 1;
        break;
    case 0x6:
        unk4464->unkC8->fn_80021928(1);
        unk4464->unkC8->fn_80021928(7);
        unk4464->unkC8->fn_80021928(8);
        unk4464->unkC8->fn_80021928(9);
        unk4464->unkC8->fn_80021928(10);
        break;
    case 0x7:
        unk4464->unkC8->fn_8002196C(1);
        unk4464->unkC8->fn_8002196C(7);
        unk4464->unkC8->fn_8002196C(8);
        unk4464->unkC8->fn_8002196C(9);
        unk4464->unkC8->fn_8002196C(10);
        break;
    case 0x8:
        unk4464->fn_8001C028(3);
        break;
    case 0x9:
        unk4464->fn_8001C0A4(3);
        break;
    case 0xA:
        unk4464->fn_8001C028(4);
        break;
    case 0xB:
        unk4464->fn_8001C0A4(4);
        break;
    case 0xC:
        unk4464->fn_8001C028(5);
        break;
    case 0xD:
        unk4464->fn_8001C0A4(5);
        break;
    case 0xE:
        unk4464->fn_8001C028(2);
        unk4464->unkC8->fn_8002196C(13);
        unk4464->unkC8->fn_80021928(13);
        break;
    case 0xF:
        unk4464->fn_8001C0A4(2);
        unk4464->unkC8->fn_8002196C(13);
        unk4464->unkC8->fn_80021928(13);
        break;
    case 0x10:
        unk4464->fn_8001C028(1);
        break;
    case 0x11:
        unk4464->fn_8001C0A4(1);
        break;
    case 0x12:
        unk4464->fn_8001C028(6);
        if (unk4584 == 0) {
            unk4464->unkC8->fn_80021928(12);
        }
        break;
    case 0x13:
        unk4464->fn_8001C0A4(6);
        if (unk4584 == 0) {
            unk4464->unkC8->fn_8002196C(12);
        }
        break;
    case 0x16:
        unk4464->fn_8001C028(0);
        break;
    case 0x17:
        unk4464->fn_8001C0A4(0);
        break;
    case 0x18:
        unk4464->fn_8001C028(7);
        break;
    case 0x19:
        unk4464->fn_8001C0A4(7);
        break;
    case 0x1A:
        unk4464->unkC8->fn_80021928(1);
        unk4464->unkC8->fn_80021928(7);
        unk4464->unkC8->fn_80021928(8);
        unk4464->unkC8->fn_80021928(9);
        unk4464->unkC8->fn_80021928(10);
        break;
    case 0x1B:
        unk4464->unkC8->fn_8002196C(1);
        unk4464->unkC8->fn_8002196C(7);
        unk4464->unkC8->fn_8002196C(8);
        unk4464->unkC8->fn_8002196C(9);
        unk4464->unkC8->fn_8002196C(10);
        break;
    case 0x1C:
        unk4464->unkC8->fn_80021928(2);
        break;
    case 0x1D:
        unk4464->unkC8->fn_8002196C(2);
        break;
    case 0x1E:
        unk4464->unkC8->fn_80021928(4);
        break;
    case 0x1F:
        unk4464->unkC8->fn_8002196C(4);
        break;
    case 0x20:
        unk4464->unkC8->fn_80021928(6);
        break;
    case 0x21:
        unk4464->unkC8->fn_8002196C(6);
        break;
    case 0x22:
        unk4464->unkC8->fn_80021928(13);
        if (unk4584 == 0) {
            unk4464->unkC8->fn_80021928(12);
        }
        break;
    case 0x23:
        unk4464->unkC8->fn_8002196C(13);
        if (unk4584 == 0) {
            unk4464->unkC8->fn_8002196C(12);
        }
        break;
    case 0x26:
        unk4464->unkC8->fn_80021928(11);
        break;
    case 0x27:
        unk4464->unkC8->fn_8002196C(11);
        break;
    case 0x28:
        if (unk45C8 != 0x28) {
            unk45C8 = 0x28;
            fn_8000FECC(0x28);
            unk45BC = unk45C4;
        }
        break;
    case 0x29:
        if (unk45C8 != 0x29) {
            unk45C8 = 0x29;
            fn_8000FECC(0x29);
            unk45BC = unk45C4;
        }
        break;
    case 0x2A:
        if (unk45C8 != 0x2A) {
            unk45C8 = 0x2A;
            fn_8000FECC(0x2A);
            unk45BC = unk45C4;
        }
        break;
    case 0x2B:
        if (unk45C8 != 0x2B) {
            unk45C8 = 0x2B;
            fn_8000FECC(0x2B);
            unk45BC = unk45C4;
        }
        break;
    case 0x2C:
        if (unk45C8 != 0x2C) {
            unk45C8 = 0x2C;
            fn_8000FECC(0x2C);
            unk45BC = unk45C4;
        }
        break;
    case 0x2D:
        if (unk45C8 != 0x2D) {
            unk45C8 = 0x2D;
            fn_8000FECC(0x2D);
            unk45BC = unk45C0;
        }
        break;
    case 0x2F:
        if (unk45C8 != 0x2F) {
            unk45C8 = 0x2F;
            fn_8000FECC(0x2F);
            unk45BC = unk45C0;
        }
        break;
    case 0x2E:
        if (unk45C8 != 0x2E) {
            unk45C8 = 0x2E;
            fn_8000FECC(0x2E);
        }
        break;
    case 0x30:
        if (unk4584 == 2) {
            unk4584 = 0;
            } else {
            unk4584 = 1;
            delete unk4464;
            unk4464 = new Unk80018374(0, 1, &unk3C8);
            unk4464->unk14 = unk458C;
        }
        break;
    case 0x31:
        if (unk4584 == 0) {
            unk4584 = 2;
            } else {
            unk4584 = 3;
            delete unk4464;
            unk4464 = new Unk80018374(0, 0, &unk3C8);
            unk4464->unk14 = unk458C;
        }
        break;
    case 0x32:
        if (unk4584 == 3) {
            unk4584 = 2;
            } else {
            unk4584 = 0;
            delete unk4464;
            unk4464 = new Unk80018374(1, 1, &unk3C8);
            unk4464->unk14 = unk458C;
        }
        break;
    case 0x33:
        if (unk4584 == 2) {
            unk4584 = 3;
            } else {
            unk4584 = 1;
            delete unk4464;
            unk4464 = new Unk80018374(0, 1, &unk3C8);
            unk4464->unk14 = unk458C;
        }
        break;
    case 0x38: // add a family member
        if (unk45C9 <= 3) {
            unk45CA = -1;
            int slot;
            for (slot = 0; slot <= 3; slot++) {
                if (unk4478->present[slot] == 0) {
                    unk45CA = slot;
                    fn_8024254C(unk4478->sims[slot].unk68, fn_8023C9EC(unk4478->unk400));
                    break;
                }
            }
            for (int n = 0; n < 14; n++) {
                unk4478->sims[slot].unkB0[n] = 0;
            }
            fn_80014564();
            if (unk45CA >= 0) {
                if (unk52FC == 0) {
                    fn_80014770();
                    unk52FC = new Unk800C6704(GetText("default_text_firstname"), 9, 0, GetText("first"), 0, 0, 0, 0.5f, 0.25f,
                                              0.25f, 10, 0, 16, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0);
                }
                unk45A0 = 0;
            }
        }
        break;
    case 0x39:
        if (unk45C9 == 0) {
            lbl_8037D96C->fn_8006186C(0x3804219F);
        } else {
            int count = 0;
            for (int i = 0; i <= 3; i++) {
                if (unk4468[i]) {
                    unk3B8[count] = new CASSpinner(0x3B);
                    EVec3 place(unk4468[i]->unk154);
                    ((CASSpinner*)unk3B8[count])->unk4C.x = place.x;
                    ((CASSpinner*)unk3B8[count])->unk4C.y = place.y;
                    ((CASSpinner*)unk3B8[count])->unk58 = i;
                    // Keep the entries sorted by position.
                    for (int j = count; j > 0; j--) {
                        CASSpinner* a = (CASSpinner*)unk3B8[j];
                        EVec2 pa;
                        pa = EVec2(a->unk4C.x, a->unk4C.y);
                        CASSpinner* b = (CASSpinner*)unk3B8[j - 1];
                        EVec2 pb;
                        pb = EVec2(b->unk4C.x, b->unk4C.y);
                        if (pb.x < pa.x || (pb.x == pa.x && pb.y < pa.y)) {
                            unk3B8[j] = b;
                            unk3B8[j - 1] = a;
                        }
                    }
                    count++;
                }
            }
            unk3B4 = new CASFamilyList(-1, 0, 0.05f, 0.0f, 0.0f);
            unk3B4->vfn4(EVec3(0.0351f, 0.0f, 0.12f));
            unk3B4->vfn6(EVec2(0.9297f, 0.065f));
            unk3B4->unk7C = 0.02f;
            unk3B4->vfn21();
            unk3B4->unk80 = -0.01f;
            unk3B4->vfn21();
            unk3B4->vfn27(4);
            unk3B4->vfn24(1, 0, 0);
            unk3B4->vfn25(0, 3, 4, 0.33f, 0.125f);
            for (int i = 0; i < count; i++) {
                unk3B4->vfn20(unk3B8[i], EVec3(0.0f));
            }
            vfn14(unk3B4);
            unk4468[unk3B4->unk48->unk58]->fn_8001E6E8(0, 0);
            unk4580 = 11;
            unk531C = 1;
            fn_80106164(unk52C4, "hideMenu", 0, 0, 0);
        }
        break;
    case 0x3A:
        if (unk45C9 == 0) {
            lbl_8037D96C->fn_8006186C(0x3804219F);
        } else {
            int count = 0;
            for (int i = 0; i <= 3; i++) {
                if (unk4468[i]) {
                    unk3B8[count] = new CASSpinner(0x3C);
                    EVec3 place(unk4468[i]->unk154);
                    ((CASSpinner*)unk3B8[count])->unk4C.x = place.x;
                    ((CASSpinner*)unk3B8[count])->unk4C.y = place.y;
                    ((CASSpinner*)unk3B8[count])->unk58 = i;
                    // Keep the entries sorted by position.
                    for (int j = count; j > 0; j--) {
                        CASSpinner* a = (CASSpinner*)unk3B8[j];
                        EVec2 pa;
                        pa = EVec2(a->unk4C.x, a->unk4C.y);
                        CASSpinner* b = (CASSpinner*)unk3B8[j - 1];
                        EVec2 pb;
                        pb = EVec2(b->unk4C.x, b->unk4C.y);
                        if (pb.x < pa.x || (pb.x == pa.x && pb.y < pa.y)) {
                            unk3B8[j] = b;
                            unk3B8[j - 1] = a;
                        }
                    }
                    count++;
                }
            }
            unk3B4 = new CASFamilyList(-1, 0, 0.05f, 0.0f, 0.0f);
            unk3B4->vfn4(EVec3(0.0351f, 0.0f, 0.12f));
            unk3B4->vfn6(EVec2(0.9297f, 0.065f));
            unk3B4->unk7C = 0.02f;
            unk3B4->vfn21();
            unk3B4->unk80 = -0.01f;
            unk3B4->vfn21();
            unk3B4->vfn27(4);
            unk3B4->vfn24(1, 0, 0);
            unk3B4->vfn25(0, 3, 4, 0.33f, 0.125f);
            for (int i = 0; i < count; i++) {
                unk3B4->vfn20(unk3B8[i], EVec3(0.0f));
            }
            vfn14(unk3B4);
            unk4468[unk3B4->unk48->unk58]->fn_8001E6E8(0, 0);
            unk4580 = 11;
            unk531C = 0;
            fn_80106164(unk52C4, "hideMenu", 0, 0, 0);
        }
        break;
    case 0x3B: { // edit the chosen family member
        unk45CA = ((CASFamilyList*)sender)->unk48->unk58;
        delete unk4464;
        unk4464 = new Unk80018374(&unk4478->sims[unk45CA], &unk3C8, 0);
        unk4464->unk14 = unk458C;
        fn_8024254C(unk57A0.unk0, unk4478->sims[unk45CA].unk28);
        CASSimDesc* desc = &unk4478->sims[unk45CA];
        unk533C[0].fn_80015908(desc->unk0[5]);
        unk533C[1].fn_80015908(desc->unk0[4]);
        unk533C[2].fn_80015908(desc->unk0[1]);
        unk533C[3].fn_80015908(desc->unk0[3]);
        unk533C[4].fn_80015908(desc->unk0[0]);
        unk57A8.unk48 = desc->unk0[6];
        if (unk4464->unk16C.unk4) {
            if (unk4464->unk16C.unk0) {
                unk4584 = 0;
            } else {
                unk4584 = 1;
            }
        } else {
            if (unk4464->unk16C.unk0) {
                unk4584 = 2;
            } else {
                unk4584 = 3;
            }
        }
        unk45BC = unk45C4;
        for (int i = 0; i < unk45C9; i++) {
            unk3B4->fn_80188B10(unk3B8[i]);
        }
        fn_80188B10(unk3B4);
        unk459C = 1;
        fn_80106164(unk52C4, "showMenu", 0, 0, 0);
        fn_80014564();
        fn_800141C0();
        break;
    }
    case 0x3C: // remove the chosen family member
        for (int i = 0; i < unk45C9; i++) {
            unk3B4->fn_80188B10(unk3B8[i]);
        }
        fn_80188B10(unk3B4);
        unk459C = 1;
        fn_80014770();
        unk45D5 = ((CASFamilyList*)sender)->unk48->unk58;
        CAS_ASK("dialog delete fam", "dialog delete fam title", "dialog delete fam", 5);
        break;
    case 0x3D:
        CAS_ASK("dialog delete fam", "dialog accept title", "dialog1", 7);
        break;
    case 0x40:
        fn_80106164(unk52C4, "setDPadArrowVisibility", 0, 0, 2, "up", "1");
        fn_80106164(unk52C4, "setDPadArrowVisibility", 0, 0, 2, "down", "1");
        unk5334 = 1;
        break;
    case 0x41:
        fn_80106164(unk52C4, "setDPadArrowVisibility", 0, 0, 2, "left", "1");
        fn_80106164(unk52C4, "setDPadArrowVisibility", 0, 0, 2, "right", "1");
        unk5330 = 1;
        break;
    case 0x42:
        fn_80106164(unk52C4, "setDPadArrowVisibility", 0, 0, 2, "up", "0");
        fn_80106164(unk52C4, "setDPadArrowVisibility", 0, 0, 2, "down", "0");
        unk5334 = 0;
        break;
    case 0x43:
        fn_80106164(unk52C4, "setDPadArrowVisibility", 0, 0, 2, "left", "0");
        fn_80106164(unk52C4, "setDPadArrowVisibility", 0, 0, 2, "right", "0");
        unk5330 = 0;
        break;
    case 0x46: // back
        if (unk52E8 == 0) {
            CAS_CLOSE_DIALOG();
            CAS_ASK("cancel warning", "dialog warning title", "cancel warning", 0);
        } else if (unk4580 == 10 || unk4580 == 5) {
            CAS_ASK("cancel warning", "dialog warning title", "cancel warning", 2);
        } else {
            CAS_CLOSE_DIALOG();
            CAS_ASK("cancel warning", "dialog warning title", "cancel warning", 1);
        }
        break;
    case 0x47:
        unk4464->fn_8001C028(9);
        break;
    case 0x48:
        unk4464->fn_8001C0A4(9);
        break;
    case 0x49:
        unk4464->fn_8001C028(10);
        break;
    case 0x4A:
        unk4464->fn_8001C0A4(10);
        break;
    case 0x4B:
        unk4464->fn_8001C028(11);
        break;
    case 0x4C:
        unk4464->fn_8001C0A4(11);
        break;
    case 0x4D:
        if (unk45AC) {
            unk45AC = 0;
        } else {
            CAS_ASK("cancel warning", "dialog warning title", "cancel warning", 2);
        }
        break;
    }
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

// 0x8000FA68
// NON_MATCHING: 2 of 159 differ. In the four-element delete loop the original steps the
// array offset before the counter; here they come out the other way round. Six loop forms tried.
// Releases everything the screen loaded and hides its dialogs.
void CASTarget::fn_8000FA68() {
    lbl_8037C230 = 1;
    if (unk52E4) {
        fn_801767FC(unk52E4);
        unk52E4 = 0;
    }
    if (unk52C0) {
        unk52C0 = 0;
    }
    if (unk4C) {
        fn_801767FC(unk4C);
        unk4C = 0;
    }
    if (unk50) {
        fn_801767FC(unk50);
        unk50 = 0;
    }
    if (unk54) {
        fn_801767FC(unk54);
        unk54 = 0;
    }
    if (unk58) {
        fn_801767FC(unk58);
        unk58 = 0;
    }
    delete unk4464;
    unk4464 = 0;
    for (int i = 0; i < 4; i++) {
        delete unk4468[i];
        unk4468[i] = 0;
    }
    if (unk4EE8) {
        fn_801767FC(unk4EE8);
        unk4EE8 = 0;
    }
    if (unk4EEC) {
        fn_801767FC(unk4EEC);
        unk4EEC = 0;
    }
    if (unk4FD8) {
        fn_801767FC(unk4FD8);
        unk4FD8 = 0;
    }
    if (unk5238) {
        fn_801767FC(unk5238);
        unk5238 = 0;
    }
    unk4588 = 0;
    fn_801767FC(unk4574);
    fn_801767FC(unk4578);
    fn_801767FC(unk457C);
    if (unk52FC) {
        delete unk52FC;
        unk52FC = 0;
    }
    fn_80014770();
    if (unk5320) {
        fn_80106164(unk52C4, "hideCAS", 0, 0, 0);
        unk5320 = 0;
    }
    if (unk5324) {
        fn_80106164(unk52C4, "hideCAF", 0, 0, 0);
        unk5324 = 0;
    }
    if (unk45D0) {
        fn_80106164(lbl_802E6700.unk90, "hideDialog", 0, 0, 0);
        unk45D0 = 0;
    }
    ((UnkViewer*)lbl_802E6700.unk90)->fn_80108290(this);
}

// 0x8000FCE4
// Advances the camera move between two views (ease curve on unk45B0), then
// starts the next queued view.
void CASTarget::fn_8000FCE4() {
    if (unk45B0 < 1.0) {
        unk45B0 += lbl_8037BFC8;
        if (unk45B0 > 1.0) {
            unk45B0 = 1.0f;
        }
        float t;
        if (unk45C8 == 0x2E) {
            float x = unk45B0;
            t = -x * x * x + 2.0f * x * x + x * 0.0f;
        } else {
            float x = unk45B0;
            t = -x * x * x + x * x + x;
        }
        unk36C = unk378 + t * (unk384 - unk378);
        unk390 = unk39C + t * (unk3A8 - unk39C);
    } else if (unk45CC) {
        unk45C8 = unk45CC;
        fn_8000FECC(unk45C8);
    }
}

// 0x8000FECC
// NON_MATCHING: 248 instructions vs 249. Same logic and case layout; the original
// schedules the two vector copies one instruction earlier and ends the default case with
// `beq; blr` where this build emits `bnelr`, which shifts everything after. Eight variants tried.
// Starts a camera move to the given view.
void CASTarget::fn_8000FECC(unsigned char view) {
    float progress;
    if (unk45B0 < 1.0) {
        if (unk45B0 > 0.5) {
            progress = 1.0 - unk45B0;
        } else {
            progress = unk45B0;
        }
    } else {
        progress = 0.0f;
    }
    unk45B0 = progress;
    unk378 = unk36C;
    unk39C = unk390;
    unk45CC = 0;
    switch (view) {
    case 0x28:
    case 0x2F:
        unk4464->unk8 = 1;
        unk384 = lbl_802E57DC;
        unk3A8 = lbl_802E57E8;
        unk4590 = 1;
        break;
    case 0x29:
        unk4464->unk8 = 0;
        if ((unsigned int)unk4584 <= 1) {
            unk384 = lbl_802E57F4;
            unk3A8 = lbl_802E5800;
        } else {
            unk384 = lbl_802E580C;
            unk3A8 = lbl_802E5818;
        }
        unk4590 = 1;
        break;
    case 0x2A:
        unk4464->unk8 = 1;
        if ((unsigned int)unk4584 <= 1) {
            unk384 = lbl_802E5824;
            unk3A8 = lbl_802E5830;
        } else {
            unk384 = lbl_802E583C;
            unk3A8 = lbl_802E5848;
        }
        unk4590 = 1;
        break;
    case 0x2B:
        unk4464->unk8 = 1;
        if ((unsigned int)unk4584 <= 1) {
            unk384 = lbl_802E5854;
            unk3A8 = lbl_802E5860;
        } else {
            unk384 = lbl_802E586C;
            unk3A8 = lbl_802E5878;
        }
        unk4590 = 1;
        break;
    case 0x2C:
        unk4464->unk8 = 1;
        unk384 = lbl_802E5884;
        unk3A8 = lbl_802E5890;
        unk4590 = 1;
        break;
    case 0x2D:
        unk384 = lbl_802E589C;
        unk3A8 = lbl_802E58A8;
        unk4590 = 0;
        break;
    case 0x2E:
        unk384 = lbl_802E58B4;
        unk3A8 = lbl_802E58C0;
        if (unk4590) {
            unk45CC = 0x2D;
        } else {
            unk45CC = 0x2F;
        }
        break;
    }
}

// 0x800102B0
// NON_MATCHING: 4 of 86 differ. Each of the two text copies loads its source pointer
// (r4) before its destination (r3) in the original; five forms tried.
// Loads the selected description into the editor and keeps a backup of the
// selector state.
void CASTarget::fn_800102B0() {
    unk4464->fn_8001C240();
    unk447C = unk4478->sims[unk45CA];
    Unk80018374* sim = unk4464;
    sim->unkC8->fn_800226F0(&sim->unk16C);
    unk447C.unkC = sim->unk16C;
    fn_80010520(&unk447C, 0);
    for (int i = 0; i < 5; i++) {
        unk5838[i] = unk533C[i];
    }
    unk5C98.Assign(unk57A0);
    unk5C9C.Assign(unk57A4);
    unk5CA0 = unk57A8;
    unk48 = 1;
}

// 0x80010408
// NON_MATCHING: 2 of 70 differ, the same r4-before-r3 load order as fn_800102B0 (only
// the first of the two copies here).
// Rebuilds the sim from the description and restores the selector state.
void CASTarget::fn_80010408() {
    if (unk48) {
        delete unk4464;
        unk4464 = new Unk80018374(&unk447C, &unk3C8, 0);
        unk4464->unk14 = unk458C;
        if (unk447C.unkC.unk4) {
            if (unk447C.unkC.unk0) {
                unk4584 = 0;
            } else {
                unk4584 = 1;
            }
        } else {
            if (unk447C.unkC.unk0) {
                unk4584 = 2;
            } else {
                unk4584 = 3;
            }
        }
        unk45A0 = 0;
        for (int i = 0; i < 5; i++) {
            unk533C[i] = unk5838[i];
        }
        unk57A0.Assign(unk5C98);
        unk57A4.Assign(unk5C9C);
        unk57A8 = unk5CA0;
    }
}

// 0x80010520
// NON_MATCHING: 36 of 81 differ, all in the random branch: the original keeps the
// random preset in r29 (here r30) and reads the five shorts in the order 2, 3, 0, 1, 4.
// Statement order (all 120 permutations) and setter-style inlines do not reproduce it.
// Fills in a description's five feature bytes, from the selectors or, when
// asked and no preset is chosen, from a random preset.
void CASTarget::fn_80010520(CASSimDesc* desc, int randomize) {
    unsigned char preset = unk57A8.unk48;
    if (preset != 0 || randomize == 0) {
        desc->unk0[5] = unk533C[0].fn_80015900();
        desc->unk0[4] = unk533C[1].fn_80015900();
        desc->unk0[1] = unk533C[2].fn_80015900();
        desc->unk0[3] = unk533C[3].fn_80015900();
        desc->unk0[0] = unk533C[4].fn_80015900();
        desc->unk0[6] = preset;
    } else {
        short choices[5];
        short random = fn_801115C4() % 11 + 1;
        fn_800620CC(choices, random);
        desc->unk0[6] = random;
        desc->unk0[5] = choices[0] / 100;
        desc->unk0[4] = choices[1] / 100;
        desc->unk0[1] = choices[2] / 100;
        desc->unk0[3] = choices[3] / 100;
        desc->unk0[0] = choices[4] / 100;
    }
}

// 0x800133DC
// Draws `text` word-wrapped into the description box, one line at a time.
// NON_MATCHING: same length (234), 81 differ: register numbering (r27/r28 and the
// r28-r30 loop variables are permuted) and the placement of the `line = 0` load.
void CASTarget::fn_800133DC(ERC* rc, const unsigned short* text, int centered) {
    EVec2 box(0.6f, 0.5f);
    EVec2 pixel(10.0f / (float)lbl_8037C198->unk14, 4.0f / (float)lbl_8037C198->unk18);
    EVec2 origin(0.22f, 0.3f);
    EVec2 size(box.x - 32.0f / (float)lbl_8037C198->unk14, 0.0f);
    EVec2 cursor(origin.x + pixel.x, origin.y + pixel.y);
    unk52E4->fn_8003C95C(1, 16.0f, 1.0f);
    if (text == 0) {
        return;
    }
    unk52E4->fn_8003DBE8(rc);
    const unsigned short* in = text;
    float startX = cursor.x;
    float maxWidth = size.x - (pixel.x + pixel.x);
    float lineHeight = unk52E4->fn_8003DC1C(0);
    int line = 0;
    while (*in) {
        unsigned short buffer[0x100];
        fn_80111C78(buffer, 0, sizeof(buffer));
        int count = 0;
        unsigned short* out = buffer;
        int done = 0;
        int lastBreak = 0;
        while (*in) {
            *out = *in;
            if (*in == '\n') {
                in++;
                done = 1;
            } else {
                EVec2 charSize;
                charSize = unk52E4->fn_8003D550(out, 1, 0);
                if (fn_800430EC(*in)) {
                    lastBreak = count;
                }
                bool over = unk52E4->fn_8003D550(buffer, 1, 0).x > maxWidth;
                if (over) {
                    done = 1;
                    int back = count - lastBreak;
                    if (back != 0) {
                        if (count == back) {
                            back = 0;
                        }
                        in--;
                        count -= back;
                        in -= back;
                        buffer[count] = 0;
                    } else {
                        buffer[count] = 0;
                    }
                    count--;
                }
                count++;
                out++;
                in++;
                if (count > 0xFD) {
                    break;
                }
            }
            if (done) {
                break;
            }
        }
        if (done || buffer[0] != 0) {
            buffer[count] = 0;
            if (line >= 0) {
                if (centered == 0) {
                    unk52E4->fn_8003D93C(rc, buffer, &cursor, 0, 0, &cursor, 2.0f, 1.0f);
                } else {
                    EVec2 position;
                    position.x = size.x * 0.5f + origin.x;
                    position.y = cursor.y;
                    unk52E4->fn_8003D93C(rc, buffer, &position, 2, 0, &cursor, 2.0f, 1.0f);
                }
                cursor.x = startX;
                cursor.y += lineHeight;
            } else {
                line++;
            }
        }
    }
}

// 0x80013784
// Draws a padlock over each feature whose current choice is still locked.
// NON_MATCHING: 596 instructions vs 611. The original keeps more stack temporaries per
// quad (frame 0xA8 against 0x70 here: every corner sum gets a temporary and a copy) and
// holds 1.0f in f31 across the calls. Two variants tried.
void CASTarget::fn_80013784(ERC* rc) {
    static EVec2 bodyOrigin(0.285f, 0.348f);
    static EVec2 bodyStep(0.0f, 0.14f);
    static EVec2 headOrigin(0.245f, 0.082f);
    static EVec2 headStep(0.0f, 0.09f);
    static EVec2 headGap(0.0f, 0.027f);
    EVec2 size(0.05f, 0.0714f);
    Unk80018374* sim = unk4464;
    sim->unkC8->fn_800226F0(&sim->unk16C);
    Unk801CC464 desc(sim->unk16C);
    if (unk52E0) {
        if (unk4464->fn_8001E9D8(desc.unk4, desc.unk0, 3, desc.unk8[4])) {
            unk50->fn_80181824(rc);
            rc->vfn47(bodyOrigin, bodyOrigin + size, EVec2(0.0f, 1.0f), EVec2(1.0f, 0.0f), EColorF(1.0f, 1.0f, 1.0f, 1.0f), 0.0f);
        }
        if (unk4464->fn_8001E9D8(desc.unk4, desc.unk0, 4, desc.unk8[5])) {
            unk50->fn_80181824(rc);
            EVec2 corner = bodyOrigin + bodyStep;
            rc->vfn47(corner, corner + size, EVec2(0.0f, 1.0f), EVec2(1.0f, 0.0f), EColorF(1.0f, 1.0f, 1.0f, 1.0f), 0.0f);
        }
        if (unk4464->fn_8001E9D8(desc.unk4, desc.unk0, 5, desc.unk8[6])) {
            unk50->fn_80181824(rc);
            EVec2 corner = bodyOrigin + (bodyStep + bodyStep);
            rc->vfn47(corner, corner + size, EVec2(0.0f, 1.0f), EVec2(1.0f, 0.0f), EColorF(1.0f, 1.0f, 1.0f, 1.0f), 0.0f);
        }
    } else if (unk52DC) {
        if (unk4464->fn_8001E9D8(desc.unk4, desc.unk0, 9, desc.unk8[15])) {
            unk50->fn_80181824(rc);
            rc->vfn47(headOrigin, headOrigin + size, EVec2(0.0f, 1.0f), EVec2(1.0f, 0.0f), EColorF(1.0f, 1.0f, 1.0f, 1.0f), 0.0f);
        }
        if (unk4464->fn_8001E9D8(desc.unk4, desc.unk0, 10, desc.unk8[16])) {
            unk50->fn_80181824(rc);
            EVec2 corner = headOrigin + headStep;
            rc->vfn47(corner, corner + size, EVec2(0.0f, 1.0f), EVec2(1.0f, 0.0f), EColorF(1.0f, 1.0f, 1.0f, 1.0f), 0.0f);
        }
        if (unk4464->fn_8001E9D8(desc.unk4, desc.unk0, 11, desc.unk8[17])) {
            unk50->fn_80181824(rc);
            EVec2 corner = headOrigin + (headStep + headStep);
            rc->vfn47(corner, corner + size, EVec2(0.0f, 1.0f), EVec2(1.0f, 0.0f), EColorF(1.0f, 1.0f, 1.0f, 1.0f), 0.0f);
        }
        if (unk4464->fn_8001E9D8(desc.unk4, desc.unk0, 2, desc.unk8[3])) {
            unk50->fn_80181824(rc);
            EVec2 corner = headOrigin + headStep * 3.0f;
            rc->vfn47(corner, corner + size, EVec2(0.0f, 1.0f), EVec2(1.0f, 0.0f), EColorF(1.0f, 1.0f, 1.0f, 1.0f), 0.0f);
        }
        if (unk4464->fn_8001E9D8(desc.unk4, desc.unk0, 6, desc.unk8[7])) {
            unk50->fn_80181824(rc);
            EVec2 corner = headOrigin + headGap + headStep * 4.0f;
            rc->vfn47(corner, corner + size, EVec2(0.0f, 1.0f), EVec2(1.0f, 0.0f), EColorF(1.0f, 1.0f, 1.0f, 1.0f), 0.0f);
        }
        if (unk4464->fn_8001E9D8(desc.unk4, desc.unk0, 0, desc.unk8[1])) {
            unk50->fn_80181824(rc);
            EVec2 corner = headOrigin + headGap + headStep * 6.0f;
            rc->vfn47(corner, corner + size, EVec2(0.0f, 1.0f), EVec2(1.0f, 0.0f), EColorF(1.0f, 1.0f, 1.0f, 1.0f), 0.0f);
        }
    }
}

// 0x80014110
const unsigned short* CASTarget::fn_80014110() {
    short choices[5];
    choices[0] = unk533C[0].fn_80015900();
    choices[1] = unk533C[1].fn_80015900();
    choices[2] = unk533C[2].fn_80015900();
    choices[3] = unk533C[3].fn_80015900();
    choices[4] = unk533C[4].fn_80015900();
    unk57A8.unk48 = fn_80061FE0(choices);
    return fn_80062134(unk57A8.unk48);
}

// 0x80014188
void CASTarget::fn_80014188(ERC* rc, const unsigned short* text, EVec2* position, int a, int b) {
    unk52E4->fn_8003D93C(rc, text, position, a, b, 0, 2.0f, 1.0f);
}

// 0x800141C0
void CASTarget::fn_800141C0() {
    vfn7(this, 0x42);
    vfn7(this, 0x41);
    unk45A0 = 0;
    unk4588 = 0;
    unk4590 = 1;
    vfn7(this, 0x28);
    if (unk52FC) {
        delete unk52FC;
        unk52FC = 0;
    }
    fn_800146A0();
    if (unk52F8) {
        unk52F8 = 0;
    } else if (unk5320 == 0) {
        fn_80106164(unk52C4, "showCAS", 0, 0, 0);
        fn_800145C8();
        unk5320 = 1;
    }
    fn_80106164(unk52C4, "setButtonContext", 0, 0, 1, "CAS");
    fn_80106164(unk52C4, "showButton", 0, 0, 1, "accept");
    fn_80106164(unk52C4, "showButton", 0, 0, 1, "decline");
    fn_80106164(unk52C4, "resetButtonContext", 0, 0, 0);
    unk4580 = 9;
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

// 0x800143E4
void CASTarget::fn_800143E4() {
    vfn7(this, 0x42);
    vfn7(this, 0x41);
    unk45A0 = 0;
    vfn7(this, 0x2D);
    unk4590 = 0;
    if (unk52F8) {
        unk52F8 = 0;
    } else if (unk5324 == 0) {
        fn_80106164(unk52C4, "showCAF", 0, 0, 0);
        fn_800145C8();
        unk5324 = 1;
    }
    fn_80106164(unk52C4, "setButtonContext", 0, 0, 1, "CAS");
    fn_80106164(unk52C4, "showButton", 0, 0, 1, "accept");
    fn_80106164(unk52C4, "showButton", 0, 0, 1, "decline");
    fn_80106164(unk52C4, "resetButtonContext", 0, 0, 0);
    unk4580 = 10;
}

// 0x80014564
void CASTarget::fn_80014564() {
    if (unk5324) {
        fn_80106164(unk52C4, "hideCAF", 0, 0, 0);
        unk5324 = 0;
    }
    unk5310 = 1;
}

// 0x800145C8
void CASTarget::fn_800145C8() {
    if (unk532C == 0) {
        fn_80106164(unk52C4, "setButtonContext", 0, 0, 1, "CAS");
        fn_80106164(unk52C4, "createButton", 0, 0, 1, "accept");
        fn_80106164(unk52C4, "createButton", 0, 0, 1, "decline");
        fn_80106164(unk52C4, "resetButtonContext", 0, 0, 0);
        unk532C = 1;
    }
    unk5328 = 1;
}

// 0x800146A0
void CASTarget::fn_800146A0() {
    if (unk532C) {
        fn_80106164(unk52C4, "setButtonContext", 0, 0, 1, "CAS");
        fn_80106164(unk52C4, "showButton", 0, 0, 1, "accept");
        fn_80106164(unk52C4, "showButton", 0, 0, 1, "decline");
        fn_80106164(unk52C4, "resetButtonContext", 0, 0, 0);
        unk5328 = 1;
    }
}

// 0x80014770
void CASTarget::fn_80014770() {
    if (unk532C) {
        fn_80106164(unk52C4, "setButtonContext", 0, 0, 1, "CAS");
        fn_80106164(unk52C4, "hideButton", 0, 0, 1, "accept");
        fn_80106164(unk52C4, "hideButton", 0, 0, 1, "decline");
        fn_80106164(unk52C4, "resetButtonContext", 0, 0, 0);
        unk5328 = 0;
    }
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

// 0x80014914
// Finds the user record with the given id in the save file, sets one byte in
// it and writes it back.
void CASTarget::fn_80014914(int id, unsigned char value) {
    int count = lbl_8037D94C->vfn15('User');
    CASUserRecord record;
    for (short i = 1; i <= count; i++) {
        void* data = lbl_8037D94C->vfn18('User', i, 0);
        if (data) {
            fn_80014AA8(&record, data, 'User', 0);
            if (record.unk0 == id) {
                if (lbl_8037D988->vfn14(record.unk0)) {
                    record.unkC.unk8[8] = value;
                    fn_80014B00(&record, lbl_8037D94C, 'User', i, lbl_8037C3F4);
                    fn_801DA828(lbl_8037D948->vfn64(), lbl_8037D94C);
                    break;
                }
            }
        }
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
void fn_80014AA8(CASUserRecord* record, void* data, int tag, int) {
    CASCallback callback(record, tag);
    Unk80231598 caller;
    caller.fn_80231598(&callback, (int)data);
}

// 0x80014B00
int fn_80014B00(CASUserRecord* record, void* file, int tag, int index, int e) {
    CASCallback callback(record, tag);
    Unk80231598 caller;
    return caller.fn_802313B4(&callback, e, (int)file, index);
}

// 0x80015070
// Matrix assignment as eight 64-bit words; almost certainly an inline operator
// of the matrix class that this unit emitted out of line.
EMat4& fn_80015070(EMat4& dst, const EMat4& src) {
    dst.Copy64(src);
    return dst;
}

// 0x800152A8
// Member-by-member assignment. In the original this is probably the
// compiler-generated operator (the one for CASTargetUnk533C at 0x800150F8 is);
// here the generated version gets inlined into its callers, so it is spelled out.
Unk80016448& Unk80016448::operator=(const Unk80016448& other) {
    UnkTargetBase::operator=(other);
    unk48 = other.unk48;
    for (int i = 0; i < 13; i++) {
        unk4C[i] = other.unk4C[i];
    }
    unk80 = other.unk80;
    unk84 = other.unk84;
    unk88 = other.unk88;
    unk8C = other.unk8C;
    return *this;
}

// 0x800153B8
CASTarget::~CASTarget() {
    fn_8000FA68();
}

// 0x800155D4
void CASCallback::vfn2() {
    fn_801FC174(unk4);
}

// 0x800155F8
int CASCallback::vfn3() {
    return unk8;
}
