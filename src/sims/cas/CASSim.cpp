#include "sims/cas/CASSim.h"

#include "sims/EGlobal.h"

int fn_8001DB0C(const unsigned int* a, const unsigned int* b);
extern "C" void fn_80110C38(void* base, unsigned int count, unsigned int size, int (*compare)(const void*, const void*)); // qsort

// Start-up position and scale of the sim, then its lighting (see CASSim.h), then
// the remembered choices of the four body types. Built by the static
// initializer at 0x8001EBC0.
EVec3 lbl_802E5968(0.341f, 1.165f, 0.0f);
EVec3 lbl_802E5974(1.0f, 1.0f, 1.0f);
EVec3 lbl_802E5980(0.2f, 0.2f, 0.1f);
EVec3 lbl_802E598C(-1.311f, 0.208f, -0.371f);
EVec3 lbl_802E5998(0.8f, 0.8f, 1.5f);
EVec3 lbl_802E59A4(0.443f, -0.748f, -0.775f);
EVec3 lbl_802E59B0(1.2f, 1.2f, 0.8f);
EVec3 lbl_802E59BC(0.794f, 0.417f, -0.627f);
EVec3 lbl_802E59C8(0.4f, 0.4f, 0.6f);
EVec3 lbl_802E59D4(-0.541f, 0.801f, 1.551f);
EVec3 lbl_802E59E0(0.1f, 0.1f, 0.05f);
EVec3 lbl_802E59EC(0.541f, 0.477f, 0.563f);
EVec3 lbl_802E59F8(0.1f, 0.1f, 0.05f);
EVec3 lbl_802E5A04(0.696f, 1.666f, 0.5f);
EVec3 lbl_802E5A10(0.6f, 0.6f, 0.8f);
Unk801CC464 lbl_802E5A1C;
Unk801CC464 lbl_802E5A38;
Unk801CC464 lbl_802E5A54;
Unk801CC464 lbl_802E5A70;

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

// 0x8001857C
// Builds a new sim of the given gender and age from the choices last used
// for that body type; otherwise as fn_80018F5C.
// NON_MATCHING: 640 instructions vs 632. Adapted from fn_80018F5C, which it follows
// except at the start, where the texture layers are chosen and at the end; the same
// approximate texture and material descriptions apply. Two variants tried.
void Unk80018374::fn_8001857C(int male, int adult, Unk8001EE8C* owner) {
    fn_80169D7C();
    fn_801B2680();
    unk8 = 1;
    unk3C = 0;
    unk24 = 0;
    unk18 = 0;
    unk1C = 0;
    unk2C = 0;
    unk30 = 0;
    unk34 = 0;
    unk14 = 0;
    unk38 = 0;
    unk40 = 0;
    unk44 = 0;
    for (int i = 10; i >= 0; i--) {
        unk90[i] = 0;
    }
    unkDC = (ELightSet*)fn_80169F1C(sizeof(ELightSet), 16);
    fn_8001A19C();
    unkC8 = (Unk800226F0*)owner;
    owner->fn_8001FD00();
    unk16C.unk0 = male;
    unk16C.unk4 = adult;
    unk154 = lbl_802E5968;
    unk160 = lbl_802E5974;
    fn_8001C2F4();
    unk194 = 0;
    unk48 = 0;
    unk4C = 0;
    unk50 = 0;
    unk54 = 0;
    unk64 = 0;
    unk68 = 0;
    unk6C = 0;
    unk70 = 0;
    unk74 = 0;
    unk78 = 0;
    unk7C = 0;
    unk80 = 0;
    unk84 = 0;
    unk88 = 0;
    unk8C = 0;
    unk188 = 0;
    unk18C = (Unk801800FC*)lbl_803401C4.fn_80177628(0x23428ABB, 0, 0);
    unk190 = (Unk801800FC*)lbl_803401C4.fn_80177628(0xA173A1EE, 0, 0);
    if (male) {
        if (adult) {
            fn_800198DC();
        } else {
            fn_80019CFC();
        }
    } else {
        if (adult) {
            fn_80019AEC();
        } else {
            fn_80019F4C();
        }
    }
    {
        CASChoice12* table = (CASChoice12*)unk194[2];
        unsigned int model = table[unk16C.unk8[6]].unk4;
        if (model == 0) {
            model = table[unk16C.unk8[6]].unk0;
        }
        fn_8001B53C(5, model);
    }
    unkC8->fn_8001FEA8(6, ((CASChoice12*)unk194[2])[unk16C.unk8[6]].unk8);
    {
        CASChoice16* table = (CASChoice16*)unk194[1];
        unsigned int model = table[unk16C.unk8[5]].unk4;
        if (model == 0) {
            model = table[unk16C.unk8[5]].unk0;
        }
        fn_8001B53C(4, model);
    }
    unkC8->fn_8001FEA8(4, ((CASChoice16*)unk194[1])[unk16C.unk8[5]].unk8);
    unkC8->fn_8001FEA8(5, ((CASChoice16*)unk194[1])[unk16C.unk8[5]].unkC);
    {
        CASChoice16* table = (CASChoice16*)unk194[0];
        unsigned int model = table[unk16C.unk8[4]].unk4;
        if (model == 0) {
            model = table[unk16C.unk8[4]].unk0;
        }
        fn_8001B53C(3, model);
    }
    unkC8->fn_8001FEA8(2, ((CASChoice16*)unk194[0])[unk16C.unk8[4]].unk8);
    unkC8->fn_8001FEA8(3, ((CASChoice16*)unk194[0])[unk16C.unk8[4]].unkC);
    {
        CASChoice16* table = (CASChoice16*)unk194[3];
        unsigned int model = table[unk16C.unk8[15]].unk4;
        if (model == 0) {
            model = table[unk16C.unk8[15]].unk0;
        }
        fn_8001B53C(9, model);
    }
    unkC8->fn_8001FEA8(8, ((CASChoice16*)unk194[3])[unk16C.unk8[15]].unkC);
    {
        CASChoice12* table = (CASChoice12*)unk194[4];
        unsigned int model = table[unk16C.unk8[16]].unk4;
        if (model == 0) {
            model = table[unk16C.unk8[16]].unk0;
        }
        fn_8001B53C(10, model);
    }
    unkC8->fn_8001FEA8(9, ((CASChoice12*)unk194[4])[unk16C.unk8[16]].unk8);
    {
        CASChoice12* table = (CASChoice12*)unk194[5];
        unsigned int model = table[unk16C.unk8[17]].unk4;
        if (model == 0) {
            model = table[unk16C.unk8[17]].unk0;
        }
        fn_8001B53C(11, model);
    }
    unkC8->fn_8001FEA8(10, ((CASChoice12*)unk194[5])[unk16C.unk8[17]].unk8);
    {
        CASChoice16* table = (CASChoice16*)unk194[6];
        unsigned int model = table[unk16C.unk8[3]].unk4;
        if (model == 0) {
            model = table[unk16C.unk8[3]].unk0;
        }
        fn_8001B53C(2, model);
    }
    unkC8->fn_8001FEA8(13, ((CASChoice16*)unk194[6])[unk16C.unk8[3]].unk8);
    unkC8->fn_8001FEA8(14, ((CASChoice16*)unk194[6])[unk16C.unk8[3]].unkC);
    {
        CASChoice16* table = (CASChoice16*)unk194[8];
        unsigned int model = table[unk16C.unk8[7]].unk4;
        if (model == 0) {
            model = table[unk16C.unk8[7]].unk0;
        }
        if (model != 0) {
            fn_8001B53C(6, model);
        } else {
            fn_8001B53C(6, 0);
        }
    }
    unkC8->fn_8001FEA8(12, ((CASChoice16*)unk194[8])[unk16C.unk8[7]].unk8);
    unkC8->fn_80020EF4(1, unk16C.unk8[8], 0);
    unkC8->fn_80020EF4(13, unk16C.unk8[9], 0);
    unkC8->fn_80020EF4(14, unk16C.unk8[9], 0);
    unkC8->fn_80020EF4(11, unk16C.unk8[14], 0);
    unkC8->fn_80020EF4(2, unk16C.unk8[10], 0);
    unkC8->fn_80020EF4(4, unk16C.unk8[11], 0);
    unkC8->fn_80020EF4(6, unk16C.unk8[12], 0);
    unkC8->fn_8001EFEC();
    unkBC = 0;
    fn_8001B53C(0, ((unsigned int*)unk194[7])[unk16C.unk8[1]]);
    unkC0 = 0;
    fn_8001B53C(8, ((CASChoice16*)unk194[3])[unk16C.unk8[15]].unk8);
    unkC = 0;
    Unk80340AB8* textures = &lbl_80340AB8;
    unkD4 = textures->fn_80177628(0xA25EBA9A, 0, 0);
    unkD8 = textures->fn_80177628(0xF46AEDCB, 0, 0);

    // The 256x256 paletted texture the outfit textures are composited into.
    ETextureDesc skin;
    skin.unk1C = "*charedsim3*";
    skin.unk1A = 8;
    skin.unk19 = 5;
    skin.unk8 = (skin.unk8 | 0x80) & ~3;
    skin.unk1B = 0x10;
    skin.unk14 = 0x100;
    skin.unk18 = 0x84;
    skin.unk12 = 0x100;
    skin.unk10 = 0x100;
    ETextureLike* texture = lbl_8037C198->vfn20(&skin);

    EMaterialDesc material;
    material.unk54 = EVec3(0.0f);
    material.unk60 = EVec3(1.0f);
    material.unk44 = EColorF(material.unk60.x, material.unk60.y, material.unk60.z, 1.0f);
    material.unk7C = 10.0f;
    material.unk84 = 0.0f;
    material.unk80 = 0.0f;
    material.unk4 = 0x20000007;
    material.unk0 = 8;
    material.unk8 = 0;
    material.unkC = 1;
    material.unkD = 0;
    material.unk10 = 0;
    material.unk8C[0] = EVec2(0.0f, 0.0f);
    material.unk8C[1] = EVec2(0.0f, 0.0f);
    material.unk8C[2] = EVec2(1.0f, 1.0f);
    material.unk8C[3] = EVec2(0.0f, 0.0f);
    material.stages[0].unk0 = texture;
    material.unkC = 2;
    material.stages[1].unk0 = lbl_80340B80.fn_80177628(0xD958C63C, 0, 0)->unk20;
    material.stages[1].unk15 = 1;
    material.stages[1].unk16 = 2;
    material.stages[1].unk4 |= 0x40;
    material.stages[1].unk10 = 0;
    material.stages[1].unk11 = 2;
    material.stages[1].unk12 = 1;
    material.stages[1].unk13 = 1;
    material.stages[1].unk14 = 0;
    unkD0 = lbl_8037C198->vfn30(&material);

    // A 32x32 copy for the family portrait.
    skin.unk8 = (skin.unk8 & ~0x80) | 0x803;
    skin.unk10 = 0x20;
    skin.unk1C = "*charedsim4*";
    skin.unk12 = 0x20;
    unkCC = lbl_8037C198->vfn20(&skin);
    fn_8001C240();
    fn_80169D7C();
    fn_801B2680();
    unk28 = 0;
    unk198 = 0;
}

// 0x80018F5C
// Builds the sim from a saved description: lights, animation lists, a model
// and textures for every slot's stored choice, then its own skin texture and
// material.
// NON_MATCHING: 618 instructions vs 608. The slot set-up half follows the original
// call for call; the texture and material descriptions at the end are approximate (the
// material description's layout is only partly understood), so that part differs
// throughout. One variant tried.
void Unk80018374::fn_80018F5C(CASSimDesc* desc, Unk8001EE8C* owner) {
    fn_80169D7C();
    fn_801B2680();
    unk8 = 1;
    unk14 = 0;
    unk24 = 0;
    unk18 = 0;
    unk1C = 0;
    unk2C = 0;
    unk30 = 0;
    unk34 = 0;
    for (int i = 10; i >= 0; i--) {
        unk90[i] = 0;
    }
    unkDC = (ELightSet*)fn_80169F1C(sizeof(ELightSet), 16);
    fn_8001A19C();
    unkC8 = (Unk800226F0*)owner;
    owner->fn_8001FD00();
    unk154 = lbl_802E5968;
    unk160 = lbl_802E5974;
    unk16C = desc->unkC;
    unk48 = 0;
    unk4C = 0;
    unk50 = 0;
    unk54 = 0;
    unk64 = 0;
    unk68 = 0;
    unk6C = 0;
    unk70 = 0;
    unk74 = 0;
    unk78 = 0;
    unk7C = 0;
    unk80 = 0;
    unk84 = 0;
    unk88 = 0;
    unk8C = 0;
    unk188 = 0;
    unk194 = 0;
    unk18C = (Unk801800FC*)lbl_803401C4.fn_80177628(0x23428ABB, 0, 0);
    unk190 = (Unk801800FC*)lbl_803401C4.fn_80177628(0xA173A1EE, 0, 0);
    unk3C = 0;
    unk38 = 0;
    if (unk16C.unk0) {
        if (unk16C.unk4) {
            fn_800198DC();
        } else {
            fn_80019CFC();
        }
    } else {
        if (unk16C.unk4) {
            fn_80019AEC();
        } else {
            fn_80019F4C();
        }
    }
    {
        CASChoice12* table = (CASChoice12*)unk194[2];
        unsigned int model = table[unk16C.unk8[6]].unk4;
        if (model == 0) {
            model = table[unk16C.unk8[6]].unk0;
        }
        fn_8001B53C(5, model);
    }
    unkC8->fn_8001FEA8(6, ((CASChoice12*)unk194[2])[unk16C.unk8[6]].unk8);
    {
        CASChoice16* table = (CASChoice16*)unk194[1];
        unsigned int model = table[unk16C.unk8[5]].unk4;
        if (model == 0) {
            model = table[unk16C.unk8[5]].unk0;
        }
        fn_8001B53C(4, model);
    }
    unkC8->fn_8001FEA8(4, ((CASChoice16*)unk194[1])[unk16C.unk8[5]].unk8);
    unkC8->fn_8001FEA8(5, ((CASChoice16*)unk194[1])[unk16C.unk8[5]].unkC);
    {
        CASChoice16* table = (CASChoice16*)unk194[0];
        unsigned int model = table[unk16C.unk8[4]].unk4;
        if (model == 0) {
            model = table[unk16C.unk8[4]].unk0;
        }
        fn_8001B53C(3, model);
    }
    unkC8->fn_8001FEA8(2, ((CASChoice16*)unk194[0])[unk16C.unk8[4]].unk8);
    unkC8->fn_8001FEA8(3, ((CASChoice16*)unk194[0])[unk16C.unk8[4]].unkC);
    {
        CASChoice16* table = (CASChoice16*)unk194[3];
        unsigned int model = table[unk16C.unk8[15]].unk4;
        if (model == 0) {
            model = table[unk16C.unk8[15]].unk0;
        }
        fn_8001B53C(9, model);
    }
    unkC8->fn_8001FEA8(8, ((CASChoice16*)unk194[3])[unk16C.unk8[15]].unkC);
    {
        CASChoice12* table = (CASChoice12*)unk194[4];
        unsigned int model = table[unk16C.unk8[16]].unk4;
        if (model == 0) {
            model = table[unk16C.unk8[16]].unk0;
        }
        fn_8001B53C(10, model);
    }
    unkC8->fn_8001FEA8(9, ((CASChoice12*)unk194[4])[unk16C.unk8[16]].unk8);
    {
        CASChoice12* table = (CASChoice12*)unk194[5];
        unsigned int model = table[unk16C.unk8[17]].unk4;
        if (model == 0) {
            model = table[unk16C.unk8[17]].unk0;
        }
        fn_8001B53C(11, model);
    }
    unkC8->fn_8001FEA8(10, ((CASChoice12*)unk194[5])[unk16C.unk8[17]].unk8);
    {
        CASChoice16* table = (CASChoice16*)unk194[6];
        unsigned int model = table[unk16C.unk8[3]].unk4;
        if (model == 0) {
            model = table[unk16C.unk8[3]].unk0;
        }
        fn_8001B53C(2, model);
    }
    unkC8->fn_8001FEA8(13, ((CASChoice16*)unk194[6])[unk16C.unk8[3]].unk8);
    unkC8->fn_8001FEA8(14, ((CASChoice16*)unk194[6])[unk16C.unk8[3]].unkC);
    {
        CASChoice16* table = (CASChoice16*)unk194[8];
        unsigned int model = table[unk16C.unk8[7]].unk4;
        if (model == 0) {
            model = table[unk16C.unk8[7]].unk0;
        }
        if (model != 0) {
            fn_8001B53C(6, model);
        } else {
            fn_8001B53C(6, 0);
        }
    }
    unkC8->fn_8001FEA8(12, ((CASChoice16*)unk194[8])[unk16C.unk8[7]].unk8);
    unkC8->fn_80022724(&unk16C);
    unkC8->fn_80021DBC(unk16C.unk4, unk16C.unk0);
    unkC = 0;
    unkBC = 0;
    fn_8001B53C(0, ((unsigned int*)unk194[7])[unk16C.unk8[1]]);
    unkC0 = 0;
    fn_8001B53C(8, ((CASChoice16*)unk194[3])[unk16C.unk8[15]].unk8);
    Unk80340AB8* textures = &lbl_80340AB8;
    unkD4 = textures->fn_80177628(0xA25EBA9A, 0, 0);
    unkD8 = textures->fn_80177628(0xF46AEDCB, 0, 0);

    // The 256x256 paletted texture the outfit textures are composited into.
    ETextureDesc skin;
    skin.unk1C = "*charedsim3*";
    skin.unk1A = 8;
    skin.unk19 = 5;
    skin.unk8 = (skin.unk8 | 0x80) & ~3;
    skin.unk1B = 0x10;
    skin.unk14 = 0x100;
    skin.unk18 = 0x84;
    skin.unk12 = 0x100;
    skin.unk10 = 0x100;
    ETextureLike* texture = lbl_8037C198->vfn20(&skin);

    EMaterialDesc material;
    material.unk54 = EVec3(0.0f);
    material.unk60 = EVec3(1.0f);
    material.unk44 = EColorF(material.unk60.x, material.unk60.y, material.unk60.z, 1.0f);
    material.unk7C = 10.0f;
    material.unk84 = 0.0f;
    material.unk80 = 0.0f;
    material.unk4 = 0x20000007;
    material.unk0 = 8;
    material.unk8 = 0;
    material.unkC = 1;
    material.unkD = 0;
    material.unk10 = 0;
    material.unk8C[0] = EVec2(0.0f, 0.0f);
    material.unk8C[1] = EVec2(0.0f, 0.0f);
    material.unk8C[2] = EVec2(1.0f, 1.0f);
    material.unk8C[3] = EVec2(0.0f, 0.0f);
    material.stages[0].unk0 = texture;
    material.unkC = 2;
    material.stages[1].unk0 = lbl_80340B80.fn_80177628(0xD958C63C, 0, 0)->unk20;
    material.stages[1].unk15 = 1;
    material.stages[1].unk16 = 2;
    material.stages[1].unk4 |= 0x40;
    material.stages[1].unk10 = 0;
    material.stages[1].unk11 = 2;
    material.stages[1].unk12 = 1;
    material.stages[1].unk13 = 1;
    material.stages[1].unk14 = 0;
    unkD0 = lbl_8037C198->vfn30(&material);

    // A 32x32 copy for the family portrait.
    skin.unk8 = (skin.unk8 & ~0x80) | 0x803;
    skin.unk10 = 0x20;
    skin.unk1C = "*charedsim4*";
    skin.unk12 = 0x20;
    unkCC = lbl_8037C198->vfn20(&skin);
    unk28 = 0;
    unk198 = 0;
    fn_8001C240();
    fn_80169D7C();
    fn_801B2680();
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
    new (&unk194, ECheckedPlace()) int**((int**)unk188->fn_8018021C(table, "AdultMale"));
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
    new (&unk194, ECheckedPlace()) int**((int**)unk188->fn_8018021C(table, "AdultFemale"));
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
    new (&unk194, ECheckedPlace()) int**((int**)unk188->fn_8018021C(table, "ChildMale"));
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
    new (&unk194, ECheckedPlace()) int**((int**)unk188->fn_8018021C(table, "ChildFemale"));
    unkC4 = (Unk8017CE68*)lbl_8033FF34.fn_80177628(0x566F5472, 0, 0);
}

// 0x8001A19C
// Fills in the sim's light set. A sim made from a saved description (unk0 set)
// gets dimmer lights and no point lights.
void Unk80018374::fn_8001A19C() {
    unkDC->numDirectional = 3;
    if (unk0 == 0) {
        unkDC->numPoint = 3;
    } else {
        unkDC->numPoint = 0;
    }
    float directional = 1.0f;
    float ambient = 1.0f;
    if (unk0) {
        directional = 0.8f;
        ambient = 1.5f;
    }
    unkDC->ambient = lbl_802E5980 * ambient;
    unkDC->directional[0].color = lbl_802E5998 * directional;
    unkDC->directional[1].color = lbl_802E59B0 * directional;
    unkDC->directional[2].color = lbl_802E59C8 * directional;
    unkDC->directional[0].direction = lbl_802E598C;
    unkDC->directional[1].direction = lbl_802E59A4;
    unkDC->directional[2].direction = lbl_802E59BC;
    unkDC->directional[0].direction.Normalize();
    unkDC->directional[1].direction.Normalize();
    // The original normalizes the second direction twice and never the third.
    unkDC->directional[1].direction.Normalize();
    if (unk0 == 0) {
        // Also written twice in the original.
        unkDC->point[0].position = lbl_802E59D4;
        unkDC->point[0].color = lbl_802E59E0;
        unkDC->point[0].range = 3.0f;
        unkDC->point[1].position = lbl_802E59EC;
        unkDC->point[1].color = lbl_802E59F8;
        unkDC->point[1].range = 1.0f;
        unkDC->point[2].position = lbl_802E5A04;
        unkDC->point[2].color = lbl_802E5A10;
        unkDC->point[2].range = 0.5f;
        unkDC->point[0].position = lbl_802E59D4;
        unkDC->point[0].color = lbl_802E59E0;
        unkDC->point[0].range = 3.0f;
        unkDC->point[1].position = lbl_802E59EC;
        unkDC->point[1].color = lbl_802E59F8;
        unkDC->point[1].range = 1.0f;
        unkDC->point[2].position = lbl_802E5A04;
        unkDC->point[2].color = lbl_802E5A10;
        unkDC->point[2].range = 0.5f;
    }
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

// 0x8001AE1C
// Per-frame animation for the sim being edited: follows the personality
// slider for the active trait through its body-language sequence, plays the
// reactions to outfit changes, and blends between animations.
// NON_MATCHING: 354 instructions vs 343. Same branches and calls; the four reaction
// cases share one tail in the original (three of them merged, the fourth a copy) and the
// blend arithmetic is kept in double precision there with one fewer conversion.
// One variant tried.
void Unk80018374::fn_8001AE1C(int trait, CASTargetUnk533C* selectors) {
    int waiting = fn_8001AC00();
    if (waiting) {
        return;
    }
    int value = 0;
    CASAnimStep** steps = 0;
    unk2C = waiting;
    if (unk18 == 0) {
        switch (trait) {
        case 0:
            value = 0;
            if (unk38 == 0) {
                steps = (CASAnimStep**)unk74;
            } else {
                steps = (CASAnimStep**)unk78;
            }
            break;
        case 1:
            value = selectors[0].fn_80015900();
            steps = unk7C;
            break;
        case 2:
            value = selectors[1].fn_80015900();
            steps = unk80;
            break;
        case 3:
            value = selectors[trait - 1].fn_80015900();
            steps = unk84;
            break;
        case 4:
            value = selectors[3].fn_80015900();
            steps = unk88;
            break;
        case 5:
            value = selectors[4].fn_80015900();
            steps = unk8C;
            break;
        }
        if (fn_8001B378(steps, value, trait) == 0 && unkE0.fn_8015AA0C(0) && steps != 0) {
            int reaction = unk24;
            int busy = unk44;
            if (reaction != -1 && busy == 0) {
                // React to the outfit piece that was just changed.
                switch ((unsigned int)reaction) {
                case 3:
                    fn_8001AB8C(EAt(*unk64, (fn_801115C4() >> 4) % ECount((int*)*unk64)));
                    break;
                case 5:
                    fn_8001AB8C(EAt(*unk68, (fn_801115C4() >> 4) % ECount((int*)*unk68)));
                    break;
                case 2:
                    fn_8001AB8C(EAt(*unk6C, (fn_801115C4() >> 4) % ECount((int*)*unk6C)));
                    break;
                case 4:
                    fn_8001AB8C(EAt(*unk70, (fn_801115C4() >> 4) % ECount((int*)*unk70)));
                    break;
                }
                unk2C = 0;
                unk24 = -1;
            } else if (unk40 == 1 && lbl_8037B488 == 0 && busy == 0 && trait == 0) {
                // Facing the mirror for the first time.
                fn_8001AB8C(EAt(*unk58, (fn_801115C4() >> 4) % ECount((int*)*unk58)));
                lbl_8037B488 = 1;
            } else if (busy == 0) {
                lbl_8037B488 = 0;
                unsigned int* ids = EStepAt(*steps, value).unk4;
                int pick = (fn_801115C4() >> 4) % ECount((int*)ids);
                fn_8001AB8C(EAt(ids, pick));
                EStepAt(*steps, value).unk14 = EAt(EStepAt(*steps, value).unk4, pick);
            } else {
                fn_8001AB8C((*steps)->unk4[0]);
            }
            unk30 = value;
        }
        unk34 = trait;
    } else {
        // A transition between two animations is being blended.
        bool ready = unkE0.unk2C.fn_801B5CE8(1, 0) != 0;
        if (ready) {
            float time = unkE0.fn_8015A82C(0);
            if (time == 1.0) {
                unkE0.fn_8015980C(0);
                unkE0.fn_801598A8(1, 0);
                unkE0.fn_80159FE4(0, 1.0f, 5.0f, 0.01f);
                unk18 = 0;
            } else {
                float blend = (time - unk20) / (1.0 - unk20);
                unkE0.fn_80159CBC(0, 1.0 - blend);
                unkE0.fn_80159CBC(1, blend);
            }
        } else if (unk1C) {
            if (unkE0.fn_8015AA0C(0)) {
                unkE0.fn_8015A520(0);
                unk1C = 0;
            }
        } else {
            float time = unkE0.fn_8015A82C(0);
            if (time > unk20) {
                float blend = (time - unk20) / (1.0 - unk20);
                if (lbl_8033F3D8.fn_801770C0(unk28)) {
                    unkE0.fn_80159994(1, unk28);
                    lbl_8033F3D8.fn_801778B4(unk28);
                    unk28 = 0;
                    unkE0.fn_8015A100(0, 1.0f, 0.5f, 0.0f, 0.0f);
                    unkE0.fn_8015A100(1, 1.0f, 0.5f, 0.0f, 0.0f);
                    unkE0.fn_80159CBC(0, 1.0 - blend);
                    unkE0.fn_80159CBC(1, blend);
                    unkE0.fn_8015A520(1);
                }
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

// 0x8001B8E4
// Sets one slot's choice (wrapping at the number of choices) and loads the
// model and textures that go with it.
// NON_MATCHING: 393 instructions vs 398. Same switches and calls. The original re-reads
// the table pointer and the stored choice before each texture call (as here) but picks
// the model through the table address already in a register, and tests `slot == 5`
// once ahead of both switches (kept in cr7). One variant tried.
void Unk80018374::fn_8001B8E4(int slot, unsigned int choice) {
    unk24 = slot;
    if (slot == 7) {
        unk16C.unk8[0] = choice % 3;
        return;
    }
    int count;
    signed char current;
    switch ((unsigned int)slot) {
    case 3:
        count = ECount(unk194[0]);
        current = unk16C.unk8[4];
        break;
    case 4:
        count = ECount(unk194[1]);
        current = unk16C.unk8[5];
        break;
    case 5:
        count = ECount(unk194[2]);
        current = unk16C.unk8[6];
        break;
    case 2:
        count = ECount(unk194[6]);
        current = unk16C.unk8[3];
        break;
    case 9:
        count = ECount(unk194[3]);
        current = unk16C.unk8[15];
        break;
    case 10:
        count = ECount(unk194[4]);
        current = unk16C.unk8[16];
        break;
    case 11:
        count = ECount(unk194[5]);
        current = unk16C.unk8[17];
        break;
    case 0:
        count = ECount(unk194[7]);
        current = unk16C.unk8[1];
        break;
    case 6:
        count = ECount(unk194[8]);
        current = unk16C.unk8[7];
        break;
    default:
        return;
    }
    choice %= (unsigned int)count;
    if (current == (int)choice) {
        return;
    }
    switch ((unsigned int)slot) {
    case 3:
        unk16C.unk8[4] = choice;
        {
            CASChoice16* table = (CASChoice16*)unk194[0];
            unsigned int model = table[(signed char)choice].unk4;
            if (model == 0) {
                model = table[(signed char)choice].unk0;
            }
            fn_8001B53C(3, model);
        }
        unkC8->fn_8001FEA8(2, ((CASChoice16*)unk194[0])[unk16C.unk8[4]].unk8);
        unkC8->fn_8001FEA8(3, ((CASChoice16*)unk194[0])[unk16C.unk8[4]].unkC);
        break;
    case 4:
        unk16C.unk8[5] = choice;
        {
            CASChoice16* table = (CASChoice16*)unk194[1];
            unsigned int model = table[(signed char)choice].unk4;
            if (model == 0) {
                model = table[(signed char)choice].unk0;
            }
            fn_8001B53C(4, model);
        }
        unkC8->fn_8001FEA8(4, ((CASChoice16*)unk194[1])[unk16C.unk8[5]].unk8);
        unkC8->fn_8001FEA8(5, ((CASChoice16*)unk194[1])[unk16C.unk8[5]].unkC);
        break;
    case 5:
        unk16C.unk8[6] = choice;
        {
            CASChoice12* table = (CASChoice12*)unk194[2];
            unsigned int model = table[(signed char)choice].unk4;
            if (model == 0) {
                model = table[(signed char)choice].unk0;
            }
            fn_8001B53C(5, model);
        }
        unkC8->fn_8001FEA8(6, ((CASChoice12*)unk194[2])[unk16C.unk8[6]].unk8);
        break;
    case 2:
        unk16C.unk8[3] = choice;
        {
            CASChoice16* table = (CASChoice16*)unk194[6];
            unsigned int model = table[(signed char)choice].unk4;
            if (model == 0) {
                model = table[(signed char)choice].unk0;
            }
            fn_8001B53C(2, model);
        }
        unkC8->fn_8001FEA8(13, ((CASChoice16*)unk194[6])[unk16C.unk8[3]].unk8);
        unkC8->fn_8001FEA8(14, ((CASChoice16*)unk194[6])[unk16C.unk8[3]].unkC);
        break;
    case 9:
        unk16C.unk8[15] = choice;
        {
            CASChoice16* table = (CASChoice16*)unk194[3];
            unsigned int model = table[(signed char)choice].unk4;
            if (model == 0) {
                model = table[(signed char)choice].unk0;
            }
            fn_8001B53C(9, model);
        }
        unkC8->fn_8001FEA8(8, ((CASChoice16*)unk194[3])[unk16C.unk8[15]].unkC);
        if (((CASChoice16*)unk194[3])[unk16C.unk8[15]].unk8) {
            fn_8001B53C(8, ((CASChoice16*)unk194[3])[unk16C.unk8[15]].unk8);
        }
        break;
    case 10:
        unk16C.unk8[16] = choice;
        {
            CASChoice12* table = (CASChoice12*)unk194[4];
            unsigned int model = table[(signed char)choice].unk4;
            if (model == 0) {
                model = table[(signed char)choice].unk0;
            }
            fn_8001B53C(10, model);
        }
        unkC8->fn_8001FEA8(9, ((CASChoice12*)unk194[4])[unk16C.unk8[16]].unk8);
        break;
    case 11:
        unk16C.unk8[17] = choice;
        {
            CASChoice12* table = (CASChoice12*)unk194[5];
            unsigned int model = table[(signed char)choice].unk4;
            if (model == 0) {
                model = table[(signed char)choice].unk0;
            }
            fn_8001B53C(11, model);
        }
        unkC8->fn_8001FEA8(10, ((CASChoice12*)unk194[5])[unk16C.unk8[17]].unk8);
        break;
    case 0:
        unk16C.unk8[1] = choice;
        fn_8001B53C(0, ((unsigned int*)unk194[7])[(signed char)choice]);
        break;
    case 6:
        unk16C.unk8[7] = choice;
        {
            CASChoice16* table = (CASChoice16*)unk194[8];
            unsigned int model = table[(signed char)choice].unk4;
            if (model == 0) {
                model = table[(signed char)choice].unk0;
            }
            if (model != 0) {
                fn_8001B53C(6, model);
            } else {
                fn_8001B53C(6, 0);
            }
        }
        unkC8->fn_8001FEA8(12, ((CASChoice16*)unk194[8])[unk16C.unk8[7]].unk8);
        break;
    }
    unkC8->fn_8001EFEC();
    if (unkC) {
        fn_8001C384();
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

// 0x8001C3B8
// Renders a 64x64 head-and-shoulders portrait of the sim to an off-screen
// target, reduces it to a 255-colour palette and writes the result, shrunk to
// 32x32, into the portrait texture (unkCC).
// NON_MATCHING: 804 instructions vs 805, but only by coincidence: this is a condensed
// draft. The sequence of calls is the original's; the field stores of the descriptions,
// the camera positions per body type and the pixel loops are approximate, so most
// instructions differ. One variant tried.
void Unk80018374::fn_8001C3B8() {
    ERC* rc = lbl_8037C198->vfn13(0);
    Unk801543AC camera;
    EViewportDesc viewport;
    viewport.unk4 = 0x40;
    viewport.unk0 = 0x40;
    viewport.unk8 = 3;
    viewport.unk18 = 1;
    viewport.unkC = EVec3(0.0f);
    viewport.unkC = EVec3(0.0f);
    viewport.unk0 = 0x40;
    viewport.unk4 = 0x40;
    lbl_8037C198->vfn8();
    lbl_8037C198->vfn44();
    ERenderTarget* target = lbl_8037C198->vfn23(&viewport);
    camera.fn_80154490(14.0f, 1.0f, 0.5f, 5.0f);
    camera.fn_8018ACF4(target, 5);
    // Eye and look-at point for each body type.
    if (unk16C.unk4) {
        if (unk16C.unk0) {
            camera.fn_80154798(EVec3(-0.185f, 2.5f, 1.55f), EVec3(-0.165f, 0.0f, 1.6f), EVec3(0.0f, 0.0f, 1.0f));
        } else {
            camera.fn_80154798(EVec3(-0.185f, 2.5f, 1.55f), EVec3(-0.185f, 0.0f, 1.56f), EVec3(0.0f, 0.0f, 1.0f));
        }
    } else {
        if (unk16C.unk0) {
            camera.fn_80154798(EVec3(-0.185f, 2.5f, 1.0f), EVec3(-0.15f, 0.0f, 1.14f), EVec3(0.0f, 0.0f, 1.0f));
        } else {
            camera.fn_80154798(EVec3(-0.185f, 2.5f, 1.0f), EVec3(-0.15f, 0.0f, 1.14f), EVec3(0.0f, 0.0f, 1.0f));
        }
    }
    rc->vfn57(target, 5);
    camera.fn_80156018(rc);
    lbl_802E6700.unkE4->fn_80181824(rc);
    rc->vfn47(EVec2(0.0f, 0.0f), EVec2(1.0f, 1.0f), EVec2(0.0f, 1.0f), EVec2(1.0f, 0.0f), EColorF(1.0f, 0.0f, 1.0f, 1.0f), 0.0f);
    if (unkC) {
        unkD0->vfn2(rc);
    } else {
        unkC8->unk44->vfn2(rc);
    }
    ELightSet lights;
    lights.numDirectional = 2;
    lights.numPoint = 0;
    lights.ambient = EVec3(0.6f);
    lights.directional[0].color = EVec3(0.4f, 0.4f, 0.6f);
    lights.directional[1].color = EVec3(0.6f);
    lights.directional[0].direction = EVec3(-10.0f, -10.0f, -11.0f);
    lights.directional[1].direction = EVec3(10.0f, 10.0f, -11.0f);
    lights.directional[0].direction.Normalize();
    lights.directional[1].direction.Normalize();
    rc->vfn44(&lights);

    // A second model instance in the idle pose, drawn with the sim's own pieces.
    Unk80156438 model;
    if (unk16C.unk4) {
        if (unk16C.unk0) {
            model.fn_80156700(0xFFA60350);
        } else {
            model.fn_80156700(0x1FB80AF4);
        }
    } else {
        model.fn_80156700(0xD5E79699);
    }
    model.SetUnk54(0.0002f);
    model.fn_80159994(0, **unk48);
    EMat4 transform;
    fn_80156964(&EVec3(0.0f), &EVec3(0.0f), &unk160, &transform);
    model.fn_80156954();
    model.fn_80157BD0(&transform, lbl_8037BFBC);
    model.fn_80156954();
    Unk80156438::Unk80156438Inner* inner = model.unk18;
    int skeleton;
    if (EIsValid(inner)) {
        skeleton = inner->unk24;
    } else {
        skeleton = 0;
    }
    rc->vfn26(model.unk4, skeleton);
    unk90[1]->fn_8017CBEC(rc);
    for (int i = 0; i < 4; i++) {
        if (unk90[7 + i]) {
            unk90[7 + i]->fn_8017CBEC(rc);
        }
    }
    if (unkBC) {
        unkBC->fn_8017CC58(rc);
    }
    if (unkC0) {
        unkC0->fn_8017CC58(rc);
    }
    rc->vfn57(0, 5);
    camera.fn_8018ACF4(0, 5);
    camera.fn_80156018(rc);
    lbl_8037C198->vfn8();

    // Copy the target into a temporary 64x64 texture and read it back.
    ETextureDesc desc;
    desc.unk1C = "*charedsim5*";
    desc.unk8 |= 0x80;
    desc.unk10 = 0x40;
    desc.unk12 = 0x40;
    ETextureLike* capture = lbl_8037C198->vfn20(&desc);
    target->vfn10(capture);
    rc->vfn57(0, 5);
    lbl_8037C198->vfn24(target);
    lbl_8037C198->vfn14(rc);
    int a;
    int b;
    capture->vfn5(0);
    unsigned char* pixels = (unsigned char*)capture->vfn6(0, &a, &b);
    unkCC->vfn5(2);
    unsigned short* palette = (unsigned short*)unkCC->vfn7();
    unsigned char* indices = (unsigned char*)unkCC->vfn6(0, &a, &b);

    Unk801B7464 quantizer;
    quantizer.fn_801B7538(0xFF, 0x7C00, 0, 0, 1);
    unsigned char color[4];
    int blocks = (desc.unk10 >> 2) * (desc.unk12 >> 2);
    for (int block = 0; block < blocks; block++) {
        unsigned char* top = pixels + block * 0x40;
        unsigned char* bottom = top + 0x20;
        for (int n = 0; n < 16; n++) {
            color[0] = top[1 + n * 2];
            color[1] = bottom[n * 2];
            color[2] = bottom[n * 2 + 1];
            quantizer.fn_801B79B4(color);
        }
    }
    quantizer.fn_801B8308();
    int colors = quantizer.fn_801B8630();
    for (int i = 0; i < colors; i++) {
        quantizer.fn_801B8638(i, color);
        color[0] >>= 3;
        color[1] >>= 3;
        color[2] >>= 3;
        palette[i] = 0x8000;
        palette[i] += color[0] << 10;
        palette[i] += color[1] << 5;
        palette[i] += color[2];
    }
    palette[colors] = 0;
    unsigned char* rgba = (unsigned char*)fn_80169F1C(0x4000, 4);
    fn_801AD298(pixels, 0x40, 0x40, rgba);
    int out = 0;
    for (int y = 0; y <= 0x1F; y++) {
        for (int x = 0; x <= 0x1F; x++) {
            unsigned char* p = rgba + ((0x1F - y) * desc.unk10 + x) * 4;
            color[0] = p[0];
            color[1] = p[1];
            color[2] = p[2];
            // Pure magenta (the background) becomes the transparent last entry.
            if (color[0] > 0xFA && color[1] == 0 && color[2] > 0xFA) {
                indices[out] = colors;
            } else {
                indices[out] = quantizer.fn_801B8664(color);
            }
            out++;
        }
    }
    fn_80169EE8(rgba);
    quantizer.fn_801B74E8();
    capture->vfn8();
    unkCC->vfn8();
    if (capture) {
        if (lbl_8037C198->vfn22(capture)) {
            lbl_8037C198->vfn8();
        }
        lbl_8037C198->vfn21(capture);
    }
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

// 0x8001D2C0
// Bone callback: for a heavy or skinny sim, scales the torso, limb and head
// bones by the table for its body type.
// NON_MATCHING: same length (262), 36 differ: before each of the 18 scale calls the
// original sets up the vector argument (r4) ahead of the bone address (r3); here the
// order is reversed. Four variants tried, including an inline wrapper.
void fn_8001D2C0(Unk80018374* sim, int, int, EMat4* bones) {
    if (sim->unk16C.unk8[0] != 0) {
        Unk801800FC* data = (Unk801800FC*)lbl_803401C4.fn_80177628(0xA173A1EE, 0, 0);
        int node = data->fn_801800FC("BoneScaleValues");
        float* scales;
        switch (sim->unk16C.unk8[0]) {
        case 1:
        if (sim->unk16C.unk4) {
            if (sim->unk16C.unk0) {
                scales = (float*)data->fn_8018021C(node, "HeavyAM");
            } else {
                scales = (float*)data->fn_8018021C(node, "HeavyAF");
            }
        } else {
            if (sim->unk16C.unk0) {
                scales = (float*)data->fn_8018021C(node, "HeavyCM");
            } else {
                scales = (float*)data->fn_8018021C(node, "HeavyCF");
            }
        }
        break;
        case 2:
        if (sim->unk16C.unk4) {
            if (sim->unk16C.unk0) {
                scales = (float*)data->fn_8018021C(node, "SkinnyAM");
            } else {
                scales = (float*)data->fn_8018021C(node, "SkinnyAF");
            }
        } else {
            if (sim->unk16C.unk0) {
                scales = (float*)data->fn_8018021C(node, "SkinnyCM");
            } else {
                scales = (float*)data->fn_8018021C(node, "SkinnyCF");
            }
        }
        break;
        default:
            fn_801767FC(data);
            return;
        }
        bones[2].Scale(EVec3(scales[0], scales[1], scales[2]));
        bones[3].Scale(EVec3(scales[3], scales[4], scales[5]));
        bones[12].Scale(EVec3(scales[6], scales[7], scales[8]));
        bones[13].Scale(EVec3(scales[9], scales[10], scales[11]));
        bones[14].Scale(EVec3(scales[12], scales[13], scales[14]));
        bones[15].Scale(EVec3(scales[15], scales[16], scales[17]));
        bones[16].Scale(EVec3(scales[18], scales[19], scales[20]));
        bones[4].Scale(EVec3(scales[21], scales[22], scales[23]));
        bones[8].Scale(EVec3(scales[21], scales[22], scales[23]));
        bones[5].Scale(EVec3(scales[24], scales[25], scales[26]));
        bones[9].Scale(EVec3(scales[24], scales[25], scales[26]));
        bones[6].Scale(EVec3(scales[27], scales[28], scales[29]));
        bones[10].Scale(EVec3(scales[27], scales[28], scales[29]));
        bones[39].Scale(EVec3(scales[30], scales[31], scales[32]));
        bones[47].Scale(EVec3(scales[30], scales[31], scales[32]));
        bones[40].Scale(EVec3(scales[33], scales[34], scales[35]));
        bones[48].Scale(EVec3(scales[33], scales[34], scales[35]));
        bones[41].Scale(EVec3(scales[36], scales[37], scales[38]));
        bones[49].Scale(EVec3(scales[36], scales[37], scales[38]));
        fn_801767FC(data);
    }
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

// 0x8001DB38
// Returns the nearest choice at or after `choice` (direction 0) or at or before
// it (direction 1) that this body type may use. Each table lists the choices
// of one slot that are *not* available to one body type; {-1} means all are.
// NON_MATCHING: 744 instructions vs 748. The tables, their copy loops and the selection
// switch line up; the differences are in the list-building and search loops at the end
// (the original walks them with pre-incremented pointers) and in register numbering.
// One variant tried.
int Unk80018374::fn_8001DB38(int slot, int choice, int direction) {
    int hairAM[16] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 16, 25, 37, 39
    };
    int slot2AM[34] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 24, 25, 40, 42, 44, 45, 47, 48, 66,
        69, 70, 81, 83, 85, 87
    };
    int slot3AM[52] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 27, 29, 32, 34, 35,
        37, 38, 50, 51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 63, 64, 65, 66, 67, 68, 69, 74, 79, 87, 88
    };
    int slot4AM[48] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 28, 34, 37, 38, 47, 48,
        49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 70, 71, 73, 78, 79, 80
    };
    int slot5AM[22] = {
        0, 1, 2, 3, 4, 5, 6, 7, 9, 23, 24, 26, 27, 28, 29, 30, 31, 33, 35, 36, 37, 39
    };
    int slot6AM[9] = {
        1, 2, 3, 5, 6, 7, 10, 16, 19
    };
    int hairAF[14] = {
        1, 2, 3, 4, 6, 7, 8, 13, 14, 27, 28, 29, 30, 31
    };
    int slot2AF[40] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 28, 34,
        36, 54, 58, 79, 73, 64, 82, 69, 80, 65, 70, 76
    };
    int slot3AF[57] = {
        0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 26, 28, 31, 35,
        36, 38, 39, 40, 46, 47, 49, 50, 51, 53, 55, 56, 58, 59, 61, 62, 63, 64, 65, 71, 76, 77, 78, 80, 83, 84,
        88, 89, 90
    };
    int slot4AF[46] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 20, 21, 22, 23, 24, 25, 27, 33, 37,
        38, 41, 42, 47, 51, 52, 53, 59, 60, 61, 62, 64, 65, 66, 69, 76, 80, 86
    };
    int slot5AF[22] = {
        0, 1, 3, 4, 5, 6, 7, 8, 9, 18, 25, 26, 28, 29, 30, 33, 38, 42, 46, 40, 47, 48
    };
    int slot6AF[8] = {
        0, 1, 3, 4, 5, 7, 17, 20
    };
    int slot11AF[4] = {
        2, 5, 7, 8
    };
    int slot11CM[3] = {
        2, 7, 8
    };
    int hairCM[1] = {-1};
    int hairCF[1] = {-1};
    int slot9AM[1] = {-1};
    int slot9AF[1] = {10};
    int slot9CM[1] = {-1};
    int slot9CF[1] = {-1};
    int slot10AM[1] = {-1};
    int slot10AF[1] = {-1};
    int slot10CM[1] = {-1};
    int slot10CF[1] = {-1};
    int slot11AM[2] = {
        1, 13
    };
    int slot11CF[1] = {-1};
    int slot2CM[1] = {-1};
    int slot2CF[1] = {-1};
    int slot3CM[1] = {1};
    int slot3CF[1] = {0};
    int slot4CM[1] = {1};
    int slot4CF[1] = {-1};
    int slot5CM[1] = {1};
    int slot5CF[1] = {-1};
    int slot6CM[1] = {-1};
    int slot6CF[1] = {-1};
    if (slot == 7) {
        return choice;
    }
    int* excluded = 0;
    int total = 0;
    int count = 0;
    switch ((unsigned int)slot) {
    case 0:
        total = ECount(unk194[7]);
        if (unk16C.unk0) {
            if (unk16C.unk4) {
                excluded = hairAM;
                count = 16;
            } else {
                excluded = hairCM;
                count = 1;
            }
        } else {
            if (unk16C.unk4) {
                excluded = hairAF;
                count = 14;
            } else {
                excluded = hairCF;
                count = 1;
            }
        }
        break;
    case 9:
        total = ECount(unk194[3]);
        if (unk16C.unk0) {
            if (unk16C.unk4) {
                excluded = slot9AM;
                count = 1;
            } else {
                excluded = slot9CM;
                count = 1;
            }
        } else {
            if (unk16C.unk4) {
                excluded = slot9AF;
                count = 1;
            } else {
                excluded = slot9CF;
                count = 1;
            }
        }
        break;
    case 10:
        total = ECount(unk194[4]);
        if (unk16C.unk0) {
            if (unk16C.unk4) {
                excluded = slot10AM;
                count = 1;
            } else {
                excluded = slot10CM;
                count = 1;
            }
        } else {
            if (unk16C.unk4) {
                excluded = slot10AF;
                count = 1;
            } else {
                excluded = slot10CF;
                count = 1;
            }
        }
        break;
    case 11:
        total = ECount(unk194[5]);
        if (unk16C.unk0) {
            if (unk16C.unk4) {
                excluded = slot11AM;
                count = 2;
            } else {
                excluded = slot11CM;
                count = 3;
            }
        } else {
            if (unk16C.unk4) {
                excluded = slot11AF;
                count = 4;
            } else {
                excluded = slot11CF;
                count = 1;
            }
        }
        break;
    case 2:
        total = ECount(unk194[6]);
        if (unk16C.unk0) {
            if (unk16C.unk4) {
                excluded = slot2AM;
                count = 34;
            } else {
                excluded = slot2CM;
                count = 1;
            }
        } else {
            if (unk16C.unk4) {
                excluded = slot2AF;
                count = 40;
            } else {
                excluded = slot2CF;
                count = 1;
            }
        }
        break;
    case 3:
        total = ECount(unk194[0]);
        if (unk16C.unk0) {
            if (unk16C.unk4) {
                excluded = slot3AM;
                count = 52;
            } else {
                excluded = slot3CM;
                count = 1;
            }
        } else {
            if (unk16C.unk4) {
                excluded = slot3AF;
                count = 57;
            } else {
                excluded = slot3CF;
                count = 1;
            }
        }
        break;
    case 4:
        total = ECount(unk194[1]);
        if (unk16C.unk0) {
            if (unk16C.unk4) {
                excluded = slot4AM;
                count = 48;
            } else {
                excluded = slot4CM;
                count = 1;
            }
        } else {
            if (unk16C.unk4) {
                excluded = slot4AF;
                count = 46;
            } else {
                excluded = slot4CF;
                count = 1;
            }
        }
        break;
    case 5:
        total = ECount(unk194[2]);
        if (unk16C.unk0) {
            if (unk16C.unk4) {
                excluded = slot5AM;
                count = 22;
            } else {
                excluded = slot5CM;
                count = 1;
            }
        } else {
            if (unk16C.unk4) {
                excluded = slot5AF;
                count = 22;
            } else {
                excluded = slot5CF;
                count = 1;
            }
        }
        break;
    case 6:
        total = ECount(unk194[8]);
        if (unk16C.unk0) {
            if (unk16C.unk4) {
                excluded = slot6AM;
                count = 9;
            } else {
                excluded = slot6CM;
                count = 1;
            }
        } else {
            if (unk16C.unk4) {
                excluded = slot6AF;
                count = 8;
            } else {
                excluded = slot6CF;
                count = 1;
            }
        }
        break;
    }
    if (count == 1 && excluded[0] == -1) {
        return choice;
    }
    fn_80110C38(excluded, count, 4, (int (*)(const void*, const void*))fn_8001DB0C);
    unsigned int validCount = total - count;
    int* valid = (int*)fn_80169F1C(validCount * 4, 4);
    unsigned int index = 0;
    int value = 0;
    for (unsigned int i = 0; i < validCount; i++) {
        while (index < (unsigned int)count && value == excluded[index]) {
            index++;
            value++;
        }
        valid[i] = value;
        value++;
    }
    if (direction == 0) {
        for (index = 0; index < validCount && (unsigned int)valid[index] < (unsigned int)choice; index++) {
        }
        if (index == validCount) {
            index = 0;
        }
    } else if (direction == 1) {
        int last = validCount - 1;
        int k;
        for (k = last; k >= 0 && (unsigned int)valid[k] > (unsigned int)choice; k--) {
        }
        if (k == -1) {
            k = last;
        }
        index = k;
    }
    int result = valid[index];
    fn_80169EE8(valid);
    return result;
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
