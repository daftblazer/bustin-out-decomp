#include "sims/cas/CASSim.h"

#include "sims/EGlobal.h"

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

// 0x800198DC
// Sets the sim up as an adult male: animation lists, model, skin and the table of choices.
// NON_MATCHING: 131 instructions vs 132. The original forms the address of unk194 early
// and keeps it in r30 for the final null-checked store; the instructions around the
// random pick are scheduled differently as a result. Four variants tried.
void Unk80018374::fn_800198DC() {
    int list = unk18C->Find("CasAnimationIDList");
    unk48 = unk18C->fn_8018021C(list, "IdleAM");
    unk4C = unk18C->fn_8018021C(list, "SittingAM");
    unk50 = unk18C->fn_8018021C(list, "SitAM");
    unk54 = unk18C->fn_8018021C(list, "StandUpAM");
    unk60 = unk5C = unk58 = unk18C->fn_8018021C(list, "MirrorReactAM");
    unkE0.fn_80156700(0xFFA60350);
    fn_8001D844(Unk801B9FEC("AM"));
    unk10 = 0;
    int roll = fn_801115C4();
    int pick = (roll >> 4) % ECount((int*)(*unk74)[1]);
    unkE0.SetUnk54(1.0f / 4096.0f);
    unk2C = 0;
    unkE0.fn_80159994(0, EAt((*unk74)[1], pick));
    unkE0.fn_8015AB78(1.18f);
    unkE0.SetCallback(fn_8001D2C0, this);
    unkC8->fn_8001FEA8(1, 0x29F28D35);
    unk188 = (Unk801800FC*)lbl_803401C4.fn_80177628(0x2A2AF469, 0, 0);
    int table = unk188->fn_801800FC("Sim::Table");
    EConstruct(&unk194, (int**)unk188->fn_8018021C(table, "AdultMale"));
    unkC4 = (Unk8017CE68*)lbl_8033FF34.fn_80177628(0x6EF2F2DA, 0, 0);
}

// 0x80019AEC
// Sets the sim up as an adult female: animation lists, model, skin and the table of choices.
// NON_MATCHING: 131 instructions vs 132. The original forms the address of unk194 early
// and keeps it in r30 for the final null-checked store; the instructions around the
// random pick are scheduled differently as a result. Four variants tried.
void Unk80018374::fn_80019AEC() {
    int list = unk18C->Find("CasAnimationIDList");
    unk48 = unk18C->fn_8018021C(list, "IdleAF");
    unk4C = unk18C->fn_8018021C(list, "SittingAF");
    unk50 = unk18C->fn_8018021C(list, "SitAF");
    unk54 = unk18C->fn_8018021C(list, "StandUpAF");
    unk60 = unk5C = unk58 = unk18C->fn_8018021C(list, "MirrorReactAF");
    unkE0.fn_80156700(0x1FB80AF4);
    fn_8001D844(Unk801B9FEC("AF"));
    unk10 = 0;
    int roll = fn_801115C4();
    int pick = (roll >> 4) % ECount((int*)(*unk74)[1]);
    unkE0.SetUnk54(1.0f / 4096.0f);
    unk2C = 0;
    unkE0.fn_80159994(0, EAt((*unk74)[1], pick));
    unkE0.fn_8015AB78(1.13f);
    unkE0.SetCallback(fn_8001D2C0, this);
    unkC8->fn_8001FEA8(1, 0x5E63299A);
    unk188 = (Unk801800FC*)lbl_803401C4.fn_80177628(0x2A2AF469, 0, 0);
    int table = unk188->fn_801800FC("Sim::Table");
    EConstruct(&unk194, (int**)unk188->fn_8018021C(table, "AdultFemale"));
    unkC4 = (Unk8017CE68*)lbl_8033FF34.fn_80177628(0x6EF2F2DA, 0, 0);
}

// 0x80019CFC
// Sets the sim up as a boy: animation lists, model, skin and the table of choices.
// NON_MATCHING: 147 instructions vs 148. The original forms the address of unk194 early
// and keeps it in r30 for the final null-checked store; the instructions around the
// random pick are scheduled differently as a result. Four variants tried.
void Unk80018374::fn_80019CFC() {
    int list = unk18C->Find("CasAnimationIDList");
    unk48 = unk18C->fn_8018021C(list, "IdleCM");
    unk4C = unk18C->fn_8018021C(list, "SittingCM");
    unk50 = unk18C->fn_8018021C(list, "SitCM");
    unk54 = unk18C->fn_8018021C(list, "StandUpCM");
    unk60 = unk5C = unk58 = unk18C->fn_8018021C(list, "MirrorReactCM");
    unkE0.fn_80156700(0x1FB80AF4);
    fn_8001D844(Unk801B9FEC("CM"));
    unk10 = 0;
    int roll = fn_801115C4();
    int pick = (roll >> 4) % ECount((int*)(*unk74)[1]);
    unk2C = fn_801115C4() % 5 + 3;
    unkE0.fn_80156700(0xD5E79699);
    unkE0.SetUnk54(1.0f / 4096.0f);
    unkE0.fn_80159994(0, EAt((*unk74)[1], pick));
    unkE0.fn_8015AB78(1.18f);
    unkE0.SetCallback(fn_8001D2C0, this);
    unkC8->fn_8001FEA8(1, 0x2BCA7663);
    unk188 = (Unk801800FC*)lbl_803401C4.fn_80177628(0x2A2AF469, 0, 0);
    int table = unk188->fn_801800FC("Sim::Table");
    EConstruct(&unk194, (int**)unk188->fn_8018021C(table, "ChildMale"));
    unkC4 = (Unk8017CE68*)lbl_8033FF34.fn_80177628(0x566F5472, 0, 0);
}

// 0x80019F4C
// Sets the sim up as a girl: animation lists, model, skin and the table of choices.
// NON_MATCHING: 147 instructions vs 148. The original forms the address of unk194 early
// and keeps it in r30 for the final null-checked store; the instructions around the
// random pick are scheduled differently as a result. Four variants tried.
void Unk80018374::fn_80019F4C() {
    int list = unk18C->Find("CasAnimationIDList");
    unk48 = unk18C->fn_8018021C(list, "IdleCF");
    unk4C = unk18C->fn_8018021C(list, "SittingCF");
    unk50 = unk18C->fn_8018021C(list, "SitCF");
    unk54 = unk18C->fn_8018021C(list, "StandUpCF");
    unk60 = unk5C = unk58 = unk18C->fn_8018021C(list, "MirrorReactCF");
    unkE0.fn_80156700(0x1FB80AF4);
    fn_8001D844(Unk801B9FEC("CF"));
    unk10 = 0;
    int roll = fn_801115C4();
    int pick = (roll >> 4) % ECount((int*)(*unk74)[1]);
    unk2C = fn_801115C4() % 5 + 3;
    unkE0.fn_80156700(0xD5E79699);
    unkE0.SetUnk54(1.0f / 4096.0f);
    unkE0.fn_80159994(0, EAt((*unk74)[1], pick));
    unkE0.fn_8015AB78(1.13f);
    unkE0.SetCallback(fn_8001D2C0, this);
    unkC8->fn_8001FEA8(1, 0x98EDFAE4);
    unk188 = (Unk801800FC*)lbl_803401C4.fn_80177628(0x2A2AF469, 0, 0);
    int table = unk188->fn_801800FC("Sim::Table");
    EConstruct(&unk194, (int**)unk188->fn_8018021C(table, "ChildFemale"));
    unkC4 = (Unk8017CE68*)lbl_8033FF34.fn_80177628(0x566F5472, 0, 0);
}

// 0x8001A67C
// Releases the sim's models, textures, materials and pending animations.
void Unk80018374::fn_8001A67C() {
    fn_80169D7C();
    fn_801B2680();
    for (int slot = 0; slot <= 11; slot++) {
        fn_8001B850((signed char)slot);
    }
    fn_80169D7C();
    fn_801B2680();
    if (unkDC) {
        fn_80169EE8(unkDC);
    }
    fn_80169D7C();
    fn_801B2680();
    fn_801767FC(unk188);
    if (unk18C) {
        fn_801767FC(unk18C);
    }
    if (unk190) {
        fn_801767FC(unk190);
    }
    ETextureLike* texture = unkD0->unk14;
    if (unkD0) {
        if (lbl_8037C198->vfn32(unkD0)) {
            lbl_8037C198->vfn8();
        }
        lbl_8037C198->vfn31(unkD0);
        unkD0 = 0;
    }
    if (texture) {
        if (lbl_8037C198->vfn22(texture)) {
            lbl_8037C198->vfn8();
        }
        lbl_8037C198->vfn21(texture);
    }
    if (unkCC) {
        if (lbl_8037C198->vfn22(unkCC)) {
            lbl_8037C198->vfn8();
        }
        lbl_8037C198->vfn21(unkCC);
        unkCC = 0;
    }
    if (unkD4) {
        fn_801767FC(unkD4);
        unkD4 = 0;
    }
    if (unkD8) {
        fn_801767FC(unkD8);
        unkD8 = 0;
    }
    if (unkC4) {
        fn_801767FC(unkC4);
        unkC4 = 0;
    }
    fn_80169D7C();
    fn_801B2680();
    if (unk198) {
        lbl_8033F3D8.fn_8017717C(unk198, 1);
        lbl_8033F3D8.fn_801778B4(unk198);
    }
    if (unk28) {
        lbl_8033F3D8.fn_8017717C(unk28, 1);
        lbl_8033F3D8.fn_801778B4(unk28);
    }
}

// 0x8001A908
// Draws the sim: transform, lights, then each outfit piece with its material.
// NON_MATCHING: 159 instructions vs 161. The original loads the model's skeleton holder
// straight into the argument register, materialises the null test as 0/1 and re-tests
// it, where this build branches on the pointer directly. Five variants tried.
void Unk80018374::fn_8001A908(ERC* rc, float turn, int shadow) {
    EVec3 rotation(0.0f, 0.0f, turn);
    EMat4 transform;
    fn_80156964(&unk154, &rotation, &unk160, &transform);
    unkE0.fn_80157BD0(&transform, lbl_8037BFBC);
    Unk80156438::Unk80156438Inner* inner = unkE0.unk18;
    int skeleton;
    if (EIsValid(inner)) {
        skeleton = inner->unk24;
    } else {
        skeleton = 0;
    }
    rc->vfn26(unkE0.unk4, skeleton);
    if (shadow) {
        fn_8001D6D8(rc);
    }
    rc->vfn44(unkDC);
    for (int i = 0; i <= 10; i++) {
        if (unkC) {
            unkD0->vfn2(rc);
        } else {
            switch (i + 1) {
            case 2:
            case 3:
            case 4:
                unkC8->unk4C->vfn2(rc);
                break;
            default:
                unkC8->unk48->vfn2(rc);
                break;
            }
        }
        if (unk90[i]) {
            unk90[i]->fn_8017CBEC(rc);
        }
    }
    if (unkBC) {
        if (unkC) {
            unkD0->vfn2(rc);
        } else {
            unkC8->unk44->vfn2(rc);
        }
        unkBC->fn_8017CC58(rc);
    }
    if (unkC0) {
        if (unkC) {
            unkD0->vfn2(rc);
        } else {
            unkC8->unk44->vfn2(rc);
        }
        unkC0->fn_8017CC58(rc);
    }
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
                    fn_8001AB8C(EAt(ids, (roll >> 4) % ECount((int*)ids)));
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

// 0x8001B378
// Moves the body-shape sequence one step towards `step` (or restarts it for the
// other gender), starting the transition animation. False when already there.
// NON_MATCHING: same length (113), 87 differ: the saved registers are numbered
// differently (r27-r31 against r28-r31 plus r27 for a late constant) and the blend value
// travels in f13 instead of f0. Two variants tried.
int Unk80018374::fn_8001B378(CASAnimStep** steps, unsigned int step, int which) {
    unsigned int animation;
    float blend;
    if (which != unk34) {
        step = 6;
        if (which == 0) {
            step = 0;
        }
        animation = *EStepAt(*steps, step).unk4;
        blend = 0.8f;
    } else if (step > unk30) {
        unsigned int next = unk30 + 1;
        if (next >= (unsigned int)ECount((int*)*steps)) {
            next = ECount((int*)*steps);
        }
        step = next;
        animation = EStepAt(*steps, step).unk0;
        blend = EStepAt(*steps, unk30).unk10;
    } else if (step < unk30) {
        step = unk30 - 1;
        blend = EStepAt(*steps, unk30).unkC;
        animation = EStepAt(*steps, step).unk8;
    } else {
        return 0;
    }
    unk20 = blend;
    if (animation == EStepAt(*steps, unk30).unk14) {
        unk30 = step;
        EStepAt(*steps, step).unk14 = animation;
    } else if (unk28 == 0) {
        if (unk20 == 1.0) {
            if (!unkE0.fn_8015AA0C(0)) {
                return 1;
            }
            fn_8001AB8C(animation);
        } else {
            unk18 = 1;
            if (unkE0.fn_8015A82C(0) > unk20) {
                unk1C = 1;
            }
            unk28 = animation;
            lbl_8033F3D8.fn_801776C0(animation);
        }
        EStepAt(*steps, step).unk14 = animation;
        unk30 = step;
    }
    return 1;
}

// 0x8001B53C
// Replaces the model in one outfit slot, then welds the seams it shares with
// the neighbouring pieces.
void Unk80018374::fn_8001B53C(int slot, unsigned int modelId) {
    if (slot == 0) {
        if (unkBC) {
            fn_8001B850(0);
        }
        if (modelId) {
            unkBC = lbl_8033FF34.fn_80177628(modelId, 0, 0);
        }
    } else if (slot == 8) {
        if (unkC0) {
            fn_8001B850(8);
        }
        if (modelId) {
            unkC0 = lbl_8033FF34.fn_80177628(modelId, 0, 0);
        }
    } else {
        if (unk90[slot - 1]) {
            fn_8001B850(slot);
        }
        if (modelId) {
            unk90[slot - 1] = lbl_8033FF34.fn_80177628(modelId, 0, 0);
        }
        switch (slot) {
        case 9:
            if (unk90[1]) {
                unk90[8]->fn_8017D384(unk90[1], 0.001f);
            }
            if (unk90[9]) {
                unk90[8]->fn_8017D384(unk90[9], 0.001f);
            }
            unk90[1]->fn_8017DF14();
            unk90[9]->fn_8017DF14();
            unk90[8]->fn_8017DF14();
            break;
        case 10:
            if (unk90[8]) {
                unk90[9]->fn_8017D384(unk90[8], 0.001f);
            }
            if (unk90[10]) {
                unk90[9]->fn_8017D384(unk90[10], 0.001f);
            }
            unk90[10]->fn_8017DF14();
            unk90[9]->fn_8017DF14();
            unk90[8]->fn_8017DF14();
            break;
        case 11:
            if (unk90[9]) {
                unk90[10]->fn_8017D384(unk90[9], 0.001f);
            }
            if (unk90[2]) {
                unk90[10]->fn_8017D384(unk90[2], 0.001f);
            }
            unk90[10]->fn_8017DF14();
            unk90[9]->fn_8017DF14();
            unk90[2]->fn_8017DF14();
            break;
        case 2:
            if (unk90[8]) {
                unk90[1]->fn_8017D384(unk90[8], 0.001f);
            }
            unk90[8]->fn_8017DF14();
            unk90[1]->fn_8017DF14();
            break;
        case 3:
            if (unk90[3]) {
                unk90[2]->fn_8017D384(unk90[3], 0.01f);
            }
            if (unk90[10]) {
                unk90[2]->fn_8017D384(unk90[10], 0.001f);
            }
            unk90[10]->fn_8017DF14();
            unk90[3]->fn_8017DF14();
            unk90[2]->fn_8017DF14();
            break;
        case 4:
            if (unk90[2]) {
                unk90[3]->fn_8017D384(unk90[2], 0.01f);
            }
            if (unk90[4]) {
                unk90[3]->fn_8017D384(unk90[4], 0.001f);
            }
            unk90[4]->fn_8017DF14();
            unk90[3]->fn_8017DF14();
            unk90[2]->fn_8017DF14();
            break;
        case 5:
            if (unk90[3]) {
                unk90[4]->fn_8017D384(unk90[3], 0.001f);
            }
            unk90[4]->fn_8017DF14();
            unk90[3]->fn_8017DF14();
            break;
        }
    }
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

// 0x8001D04C
// Makes a 32x32 paletted copy of the sim's skin texture (kept with the saved
// family) and returns it.
// NON_MATCHING: 154 instructions vs 157. Same calls; the descriptor's default and
// override stores are scheduled differently and the original re-reads the palette size
// fields from the stack. One variant tried.
ETextureLike* Unk80018374::fn_8001D04C() {
    ETextureDesc desc;
    desc.unk8 = 0x800;
    desc.unk10 = 0x20;
    desc.unk1A = 8;
    desc.unk14 = 0x100;
    desc.unk18 = 0x84;
    desc.unk12 = 0x20;
    desc.unk19 = 5;
    desc.unk1B = 0x10;
    ETextureLike* copy = lbl_8037C198->vfn20(&desc);
    int a;
    int b;
    copy->vfn5(2);
    void* dstPixels = copy->vfn7();
    void* dstPalette = copy->vfn6(0, &a, &b);
    unkCC->vfn5(1);
    void* srcPixels = unkCC->vfn7();
    void* srcPalette = unkCC->vfn6(0, &a, &b);
    fn_80111AE8(dstPixels, srcPixels, (desc.unk14 * desc.unk1B + 7) >> 3);
    struct Palette {
        unsigned int entries[0x100];
    };
    *(Palette*)dstPalette = *(Palette*)srcPalette;
    unkCC->vfn8();
    copy->vfn8();
    return copy;
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

// 0x8001D844
// Looks up the animation lists whose names end in the body-type suffix.
void Unk80018374::fn_8001D844(const Unk801B9FEC& suffix) {
    int list = unk18C->Find("CasAnimationList");
    unk7C = (CASAnimStep**)FindList(list, "MessyToNeat", suffix.unk0);
    unk80 = (CASAnimStep**)FindList(list, "ShyToOutgoing", suffix.unk0);
    unk84 = (CASAnimStep**)FindList(list, "LazyToActive", suffix.unk0);
    unk88 = (CASAnimStep**)FindList(list, "SeriousToPlayful", suffix.unk0);
    unk8C = (CASAnimStep**)FindList(list, "MeanToNice", suffix.unk0);
    unk74 = (unsigned int***)FindList(list, "GlobalIdle", suffix.unk0);
    unk78 = (unsigned int***)FindList(list, "SittingIdle", suffix.unk0);
    list = unk18C->Find("CasAnimationIDList");
    unk64 = (unsigned int**)FindList(list, "UpperBodyReact", suffix.unk0);
    unk68 = (unsigned int**)FindList(list, "ShoeReact", suffix.unk0);
    unk6C = (unsigned int**)FindList(list, "HairReact", suffix.unk0);
    unk70 = (unsigned int**)FindList(list, "PantsReact", suffix.unk0);
    unk18C->fn_8017FF7C();
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

// 0x8001E794
// True when the choice is in the unlockables table for this body type and its
// unlock flag has not been earned yet.
int Unk80018374::fn_8001E794(int adult, int male, int slot, int choice) {
    if (lbl_802E6700.unk14C == 0 && lbl_802E6700.fn_800690B0(6) == 0) {
        int node = unk190->Find("Unlockables");
        CASLockTable* table = (CASLockTable*)unk190->Get(node, "Bustin Out Unlockables");
        int kind;
        switch ((unsigned int)slot) {
        case 2:
            kind = 0;
            break;
        case 6:
            kind = 1;
            break;
        case 9:
            kind = 2;
            break;
        case 10:
            kind = 3;
            break;
        case 11:
            kind = 4;
            break;
        case 0:
            kind = 5;
            break;
        case 3:
            kind = 6;
            break;
        case 4:
            kind = 7;
            break;
        case 5:
            kind = 8;
            break;
        default:
            return 0;
        }
        for (int i = 0; i < ECount((int*)table->unk8); i++) {
            int mask = 1 << (i % 16);
            if ((lbl_8037D948->vfn23(i / 16 + 16, 0) & mask) == 0) {
                CASLockEntry entry = table->At(i);
                if (entry.unkC != (short)choice) {
                    continue;
                }
                if (entry.unk8 != kind) {
                    continue;
                }
                if (entry.unk4) {
                    if (adult != 1) {
                        continue;
                    }
                } else {
                    if (adult != 0) {
                        continue;
                    }
                }
                if (entry.unk5) {
                    if (male != 1) {
                        continue;
                    }
                } else {
                    if (male != 0) {
                        continue;
                    }
                }
                return 1;
            }
        }
    }
    return 0;
}

// 0x8001E9D8
// As fn_8001E794 without the unlock-flag test: true when the choice is in the
// table at all (used to draw the padlocks).
int Unk80018374::fn_8001E9D8(int adult, int male, int slot, int choice) {
    if (lbl_802E6700.unk14C == 0) {
        int node = unk190->Find("Unlockables");
        CASLockTable* table = (CASLockTable*)unk190->Get(node, "Bustin Out Unlockables");
        int kind;
        switch ((unsigned int)slot) {
        case 2:
            kind = 0;
            break;
        case 6:
            kind = 1;
            break;
        case 9:
            kind = 2;
            break;
        case 10:
            kind = 3;
            break;
        case 11:
            kind = 4;
            break;
        case 0:
            kind = 5;
            break;
        case 3:
            kind = 6;
            break;
        case 4:
            kind = 7;
            break;
        case 5:
            kind = 8;
            break;
        default:
            return 0;
        }
        for (int i = 0; i < ECount((int*)table->unk8); i++) {
            CASLockEntry entry = table->At(i);
            if (entry.unkC != (short)choice) {
                continue;
            }
            if (entry.unk8 != kind) {
                continue;
            }
            if (entry.unk4) {
                if (adult != 1) {
                    continue;
                }
            } else {
                if (adult != 0) {
                    continue;
                }
            }
            if (entry.unk5) {
                if (male != 1) {
                    continue;
                }
            } else {
                if (male != 0) {
                    continue;
                }
            }
            return 1;
        }
    }
    return 0;
}
