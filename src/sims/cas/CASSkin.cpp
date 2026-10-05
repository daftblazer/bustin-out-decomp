#include "sims/cas/CASSim.h"

// Hue, saturation and lightness offsets of the eight skin tones.
EVec3 lbl_802E5A8C(0.007f, -0.006f, -0.03f);
EVec3 lbl_802E5A98(0.015f, 0.04f, -0.1f);
EVec3 lbl_802E5AA4(0.028f, -0.16f, -0.2f);
EVec3 lbl_802E5AB0(0.015f, -0.08f, -0.3f);
EVec3 lbl_802E5ABC(0.015f, -0.04f, -0.35f);
EVec3 lbl_802E5AC8(0.03f, -0.08f, -0.4f);
EVec3 lbl_802E5AD4(0.03f, -0.12f, -0.48f);
EVec3 lbl_802E5AE0(0.0f, -0.0125f, 0.045f);

void fn_8003E350(void* resource);
unsigned int fn_8003E3E8(void* resource);

// 0x8001EE8C
Unk8001EE8C::Unk8001EE8C() {
    unk0[0] = 0;
    unk0[1] = 0;
    unk0[2] = 0;
    unk0[3] = 0;
    unk0[4] = 0;
    unk0[5] = 0;
    unk0[6] = 0;
    unk0[7] = 0;
    unk0[8] = 0;
    unk0[9] = 0;
    unk0[10] = 0;
    unk0[11] = 0;
    unk0[12] = 0;
    unk0[13] = 0;
    unk0[14] = 0;
    unk0[15] = 0;
    unk0[16] = 0;
    unk44 = 0;
    unk48 = 0;
    unk4C = 0;
    unk50 = 0;
    unk4094 = 0;
    unk4098 = 0;
    fn_8001F34C();
}

// 0x8001EF1C
Unk8001EE8C::~Unk8001EE8C() {
    fn_8001FAE0();
}

// 0x8001EF5C
void fn_8001EF5C(void* resource, int* done) {
    if (resource) {
        fn_8003E350(resource);
        *done = 1;
    }
}

// 0x8001EF98
void Unk8001EE8C::fn_8001EF98(void* resource, unsigned int* out) {
    if (resource) {
        unsigned int value = fn_8003E3E8(resource);
        if (value & 0xFF000000) {
            *out = fn_80022B3C(*out, value);
        }
    }
}

// 0x8001EFEC
// Composites the layer images into the 256x256 skin texture, one pixel from
// every layer at a time. The texture is stored in 4x4 tiles, eight to a row.
// NON_MATCHING: one instruction. The add that packs the blue bits has its operands the
// other way round (add r0,r0,r9 in the original, add r0,r9,r0 here); the original
// also uses ori for the 0x8000, which every form that gets the rest right turns into
// an add. Ten forms of the packing expression tried.
void Unk8001EE8C::fn_8001EFEC() {
    int any = 0;
    fn_8001EF5C(unk0[0], &any);
    fn_8001EF5C(unk0[1], &any);
    fn_8001EF5C(unk0[2], &any);
    fn_8001EF5C(unk0[5], &any);
    fn_8001EF5C(unk0[3], &any);
    fn_8001EF5C(unk0[4], &any);
    fn_8001EF5C(unk0[6], &any);
    fn_8001EF5C(unk0[7], &any);
    fn_8001EF5C(unk0[8], &any);
    fn_8001EF5C(unk0[9], &any);
    fn_8001EF5C(unk0[11], &any);
    fn_8001EF5C(unk0[10], &any);
    fn_8001EF5C(unk0[12], &any);
    fn_8001EF5C(unk0[15], &any);
    fn_8001EF5C(unk0[16], &any);
    fn_8001EF5C(unk0[13], &any);
    fn_8001EF5C(unk0[14], &any);
    if (any) {
        unsigned char block = 0;
        unsigned char column = 0;
        unsigned char row = 0;
        unsigned char sub = 0;
        int offset = 0;
        unk50->vfn5(2);
        int a;
        int b;
        unsigned short* out = (unsigned short*)unk50->vfn6(0, &a, &b);
        for (unsigned int i = 0; i <= 0xFFFF; i++) {
            unsigned int color = fn_8003E3E8(unk0[0]) & 0xFFFFFF;
            fn_8001EF98(unk0[1], &color);
            fn_8001EF98(unk0[2], &color);
            fn_8001EF98(unk0[5], &color);
            fn_8001EF98(unk0[3], &color);
            fn_8001EF98(unk0[4], &color);
            fn_8001EF98(unk0[6], &color);
            fn_8001EF98(unk0[7], &color);
            fn_8001EF98(unk0[8], &color);
            fn_8001EF98(unk0[9], &color);
            fn_8001EF98(unk0[11], &color);
            fn_8001EF98(unk0[10], &color);
            fn_8001EF98(unk0[12], &color);
            fn_8001EF98(unk0[15], &color);
            fn_8001EF98(unk0[16], &color);
            fn_8001EF98(unk0[13], &color);
            fn_8001EF98(unk0[14], &color);
            sub++;
            unsigned char rgb[3];
            rgb[0] = (color >> 3) & 0x1F;
            rgb[1] = (color >> 11) & 0x1F;
            rgb[2] = (color >> 19) & 0x1F;
            out[offset] = rgb[2] + ((rgb[0] << 10) + 0x8000U | (rgb[1] << 5));
            if (sub <= 3) {
                offset++;
            } else {
                column++;
                if (column <= 0x3F) {
                    sub = 0;
                    offset += 0xD;
                } else {
                    row++;
                    if (row <= 3) {
                        offset = row * 4 + block * 0x400;
                        sub = 0;
                        column = 0;
                    } else {
                        block++;
                        sub = 0;
                        row = 0;
                        column = 0;
                        offset = block << 10;
                    }
                }
            }
        }
        unk50->vfn8();
    }
}

// 0x8001F34C
// Creates the 256x256 skin texture and the three shaders that use it, and
// loads the first layer.
// NON_MATCHING: 470 instructions vs 485, frame 0x298 vs 0x2B0. The three inline
// shader-description constructors are the bulk of the function; the original keeps
// separate temporaries for the vectors (0xD8 and 0xE8) and more addresses in saved
// registers, so nearly every instruction differs. Two variants tried.
void Unk8001EE8C::fn_8001F34C() {
    ETextureDesc desc;
    EMaterialDesc material;
    desc.unk8 = (desc.unk8 | 0x80) & ~3;
    desc.unk14 = 0;
    desc.unk19 = 0;
    desc.unk1B = 0;
    desc.unk10 = 0x100;
    desc.unk1C = "*charedskin*";
    desc.unk18 = 0x82;
    desc.unk1A = 0x10;
    desc.unk12 = 0x100;
    material.stages[0].unk0 = unk50 = lbl_8037C198->vfn20(&desc);
    unk44 = lbl_8037C198->vfn30(&material);
    EMaterialDesc material2;
    material2.stages[0].unk0 = unk50;
    material2.unkC = 2;
    material2.stages[1].unk0 = lbl_80340B80.fn_80177628(0xD958C63C, 0, 0)->unk20;
    material2.stages[1].unk15 = 1;
    material2.stages[1].unk16 = 2;
    material2.stages[1].unk4 |= 0x40;
    material2.stages[1].unk14 = 0;
    material2.stages[1].unk10 = 0;
    material2.stages[1].unk11 = 2;
    material2.stages[1].unk12 = 1;
    material2.stages[1].unk13 = 1;
    unk48 = lbl_8037C198->vfn30(&material2);
    EMaterialDesc material3;
    material3.stages[0].unk0 = unk50;
    material3.unkC = 2;
    material3.stages[1].unk0 = lbl_80340B80.fn_80177628(0x3EB7D688, 0, 0)->unk20;
    material3.stages[1].unk15 = 1;
    material3.stages[1].unk16 = 2;
    material3.stages[1].unk4 |= 0x40;
    material3.stages[1].unk14 = 0;
    material3.stages[1].unk10 = 0;
    material3.stages[1].unk11 = 2;
    material3.stages[1].unk12 = 1;
    material3.stages[1].unk13 = 1;
    unk4C = lbl_8037C198->vfn30(&material3);
    signed char one = 1;
    signed char* p = &unk406C[15];
    for (int i = 16; i > 0; i--) {
        *p-- = one;
    }
    unk406C[0] = 0;
    unk406C[6] = 0;
    unk406C[7] = 0;
    unk406C[8] = 0;
    unk406C[9] = 0;
    unk0[11] = (Unk80021CEC*)lbl_802E5E1C.fn_80177628(0xC9E921E7, 0, 0);
    fn_8001FEA8(11, 0xD57882B9);
    unk408C = 0;
    unk4090 = 0;
}

// 0x8001FAE0
// Releases the materials, the composited texture and the two resources.
void Unk8001EE8C::fn_8001FAE0() {
    fn_80022C6C();
    if (unk44) {
        if (lbl_8037C198->vfn32(unk44)) {
            lbl_8037C198->vfn8();
        }
        lbl_8037C198->vfn31(unk44);
        unk44 = 0;
    }
    if (unk4C) {
        if (lbl_8037C198->vfn32(unk4C)) {
            lbl_8037C198->vfn8();
        }
        lbl_8037C198->vfn31(unk4C);
        unk4C = 0;
    }
    if (unk48) {
        if (lbl_8037C198->vfn32(unk48)) {
            lbl_8037C198->vfn8();
        }
        lbl_8037C198->vfn31(unk48);
        unk48 = 0;
    }
    if (unk50) {
        if (lbl_8037C198->vfn22(unk50)) {
            lbl_8037C198->vfn8();
        }
        lbl_8037C198->vfn21(unk50);
        unk50 = 0;
    }
    lbl_80340B80.fn_801778B4(0x3EB7D688);
    lbl_80340B80.fn_801778B4(0xD958C63C);
}

// 0x8001FD00
// Restores every layer's palette and resets the choices.
void Unk8001EE8C::fn_8001FD00() {
    if (unk0[1]) {
        fn_80021D40(unk0[1], 1);
    }
    if (unk0[2]) {
        fn_80021D40(unk0[2], 2);
    }
    if (unk0[3]) {
        fn_80021D40(unk0[3], 3);
    }
    if (unk0[4]) {
        fn_80021D40(unk0[4], 4);
    }
    if (unk0[5]) {
        fn_80021D40(unk0[5], 5);
    }
    if (unk0[6]) {
        fn_80021D40(unk0[6], 6);
    }
    if (unk0[7]) {
        fn_80021D40(unk0[7], 7);
    }
    if (unk0[8]) {
        fn_80021D40(unk0[8], 8);
    }
    if (unk0[9]) {
        fn_80021D40(unk0[9], 9);
    }
    if (unk0[10]) {
        fn_80021D40(unk0[10], 10);
    }
    if (unk0[12]) {
        fn_80021D40(unk0[12], 11);
    }
    if (unk0[13]) {
        fn_80021D40(unk0[13], 12);
    }
    if (unk0[15]) {
        fn_80021D40(unk0[15], 14);
    }
    if (unk0[16]) {
        fn_80021D40(unk0[16], 15);
    }
    signed char* p = unk406C + 16;
    for (int i = 16; i > 0; i--) {
        *--p = 1;
    }
    unk406C[0] = 0;
    unk406C[6] = 0;
    unk406C[7] = 0;
    unk406C[8] = 0;
    unk406C[9] = 0;
}

// 0x8001FEA8
// Replaces the image of one texture layer. The first head image loaded picks
// the body type; skin layers are recoloured to the current skin tone.
// NON_MATCHING: 1019 instructions vs 1043, frame 0x70 vs 0x80. Control flow and calls
// agree; the four inlined skin-layer blocks differ. The original keeps the address of
// the HSL vector in a register (zeroing z and y through it, x directly) and has 16
// more bytes of locals, and its saturation/lightness clamps store in each branch.
// Four variants tried (tone as floats or a copied vector, chained and indexed zeroing).
void Unk8001EE8C::fn_8001FEA8(int layer, unsigned int textureId) {
    if (unk4098 == 0 && layer == 1) {
        switch (textureId) {
        case 0x29F28D35:
        case 0x4D9094C3:
            unk4094 = 0;
            break;
        case 0x78EEA303:
        case 0x5E63299A:
            unk4094 = 1;
            break;
        case 0x4FA86F95:
        case 0x2BCA7663:
            unk4094 = 2;
            break;
        case 0x98EDFAE4:
        case 0xBE60707D:
            unk4094 = 3;
            break;
        }
        unk4098 = 1;
    }
    switch (layer) {
    case 1:
        if (unk0[0]) {
            fn_801767FC(unk0[0]);
            unk0[0] = 0;
        }
        if (textureId != 0) {
            unk0[0] = (Unk80021CEC*)lbl_802E5E1C.fn_80177628(textureId, 0, 0);
        }
        break;
    case 7:
        LoadSkinLayer(6, layer, textureId);
        break;
    case 8:
        LoadSkinLayer(7, layer, textureId);
        break;
    case 9:
        LoadSkinLayer(8, layer, textureId);
        break;
    case 10:
        LoadSkinLayer(9, layer, textureId);
        break;
    case 2:
        LoadLayer(1, 1, textureId);
        break;
    case 3:
        LoadLayer(2, 2, textureId);
        break;
    case 4:
        LoadLayer(3, 3, textureId);
        break;
    case 5:
        LoadLayer(4, 4, textureId);
        break;
    case 6:
        LoadLayer(5, 5, textureId);
        break;
    case 11:
        LoadLayer(10, 10, textureId);
        break;
    case 12:
        LoadLayer(12, 11, textureId);
        break;
    case 15:
        LoadLayer(15, 14, textureId);
        break;
    case 16:
        LoadLayer(16, 15, textureId);
        break;
    case 13:
        LoadLayer(13, 12, textureId);
        break;
    case 14:
        LoadLayer(14, 13, textureId);
        break;
    }
    if (layer != 13 && layer != 1 && layer != 7) {
        unk406C[layer - 1] = 1;
    }
}

// 0x800218D8
int Unk8001EE8C::fn_800218D8(int layer) {
    switch (layer) {
    case 1:
    case 7:
    case 8:
    case 9:
    case 10:
        return unk406C[0];
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
        return unk406C[layer - 1];
    }
    return 0;
}

// 0x80021928
void Unk8001EE8C::fn_80021928(int layer) {
    fn_80020EF4(layer, fn_800218D8(layer) + 1, 1);
}

// 0x8002196C
// Previous choice, wrapping to the last one of the layer's kind.
void Unk8001EE8C::fn_8002196C(int layer) {
    int choice = fn_800218D8(layer);
    int previous = 0;
    if (choice == 0) {
        switch (layer) {
        case 1:
        case 7:
        case 8:
        case 9:
        case 10:
            previous = 7;
            break;
        case 12:
        case 13:
        case 14:
            previous = 10;
            break;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 11:
        case 15:
        case 16:
            previous = 0x20;
            break;
        }
    } else {
        previous = choice - 1;
    }
    fn_80020EF4(layer, previous, 1);
}

// 0x80021A14
// Reduces the composited texture to 256 colours and writes the palette and the
// indices into the given texture.
void Unk8001EE8C::fn_80021A14(ETextureLike* texture) {
    unsigned char color[3];
    unsigned char sub = 0;
    unsigned char column = 0;
    int first = 1;
    int offset = 0;
    unk50->vfn5(1);
    int a;
    int b;
    unsigned short* source = (unsigned short*)unk50->vfn6(0, &a, &b);
    Unk801B7464 quantizer;
    unsigned short* p = source;
    int i;
    quantizer.fn_801B7538(0x100, 0x7C00, 0, 0, 1);
    for (i = 0; i < 0x10000; i++) {
        color[0] = ((*p >> 10) & 0x1F) << 3;
        color[1] = ((*p >> 5) & 0x1F) << 3;
        color[2] = (*p & 0x1F) << 3;
        p++;
        quantizer.fn_801B79B4(color);
    }
    quantizer.fn_801B8308();
    texture->vfn5(2);
    unsigned short* palette = (unsigned short*)texture->vfn7();
    int colors = quantizer.fn_801B8630();
    for (i = 0; i < colors; i++) {
        quantizer.fn_801B8638(i, color);
        color[0] >>= 3;
        color[1] >>= 3;
        color[2] >>= 3;
        palette[i] = 0x8000;
        palette[i] += color[0] << 10;
        palette[i] += color[1] << 5;
        palette[i] += color[2];
    }
    unsigned char* indices = (unsigned char*)texture->vfn6(0, &a, &b);
    unsigned short* q = source;
    for (i = 0; i < 0x10000; i++) {
        color[0] = ((*q >> 10) & 0x1F) << 3;
        color[1] = ((*q >> 5) & 0x1F) << 3;
        color[2] = (*q & 0x1F) << 3;
        indices[offset] = quantizer.fn_801B8664(color);
        sub++;
        if (sub > 3) {
            sub = 0;
            column++;
            if (column <= 3) {
                offset += 5;
            } else {
                column = 0;
                if (first) {
                    first = 0;
                    offset -= 0x17;
                } else {
                    first = 1;
                    offset++;
                }
            }
        } else {
            offset++;
        }
        q++;
    }
    texture->vfn8();
    unk50->vfn8();
}

// 0x80021CEC
void Unk8001EE8C::fn_80021CEC(Unk80021CEC* image, int index) {
    unsigned int count = 0x100;
    unsigned int* palette = image->unk24;
    if (image->unk3C) {
        count = 0x10;
    }
    for (unsigned int i = 0; i < count; i++) {
        unk6C[index][i] = palette[i];
    }
}

// 0x80021D40
void Unk8001EE8C::fn_80021D40(Unk80021CEC* image, int index) {
    unsigned int count = 0x100;
    unsigned int* palette = image->unk24;
    if (image->unk3C) {
        count = 0x10;
    }
    for (unsigned int i = 0; i < count; i++) {
        palette[i] = unk6C[index][i];
    }
}

// 0x80021D94
void Unk8001EE8C::fn_80021D94() {
    for (int i = 0; i < 16; i++) {
        unk407C[i] = unk406C[i];
    }
}

// 0x800226F0
void Unk8001EE8C::fn_800226F0(Unk801CC464* out) {
    out->unk8[10] = unk406C[1];
    out->unk8[11] = unk406C[3];
    out->unk8[12] = unk406C[5];
    out->unk8[8] = unk406C[0];
    out->unk8[9] = unk406C[12];
    out->unk8[14] = unk406C[10];
}

// 0x80022724
void Unk8001EE8C::fn_80022724(Unk801CC464* choices) {
    unk406C[0] = choices->unk8[8];
    unk406C[1] = choices->unk8[10];
    unk406C[3] = choices->unk8[11];
    unk406C[5] = choices->unk8[12];
    unk406C[12] = choices->unk8[9];
    unk406C[10] = choices->unk8[14];
    fn_80021D94();
}

// 0x80022778
unsigned int Unk8001EE8C::fn_80022778(const EVec3& hsl) {
    float h = hsl.x;
    float s = hsl.y;
    float l = hsl.z;
    float r;
    float g;
    float b;
    float v;
    if (l <= 0.5f) {
        v = l * (s + 1.0f);
    } else {
        v = l + s - l * s;
    }
    if (v <= 0.0f) {
        r = g = b = 0.0f;
    } else {
        float m = l + l - v;
        float sv = (v - m) / v;
        h *= 6.0f;
        int sextant = (int)h;
        float vsf = v * sv * (h - sextant);
        float mid1 = m + vsf;
        float mid2 = v - vsf;
        switch (sextant) {
        case 0:
            r = v;
            g = mid1;
            b = m;
            break;
        case 1:
            g = v;
            r = mid2;
            b = m;
            break;
        case 2:
            g = v;
            r = m;
            b = mid1;
            break;
        case 3:
            r = m;
            g = mid2;
            b = v;
            break;
        case 4:
            r = mid1;
            g = m;
            b = v;
            break;
        case 5:
            r = v;
            g = m;
            b = mid2;
            break;
        case 6:
            r = v;
            g = m;
            b = mid2;
            break;
        default:
            r = g = b = 0.0f;
            break;
        }
    }
    return (unsigned char)(int)(r * 255.0f) + (((int)(g * 255.0f) << 8) & 0xFF00) +
           (((int)(b * 255.0f) << 16) & 0xFF0000);
}

// 0x80022940
void Unk8001EE8C::fn_80022940(unsigned int rgb, EVec3* hsl) {
    float r = (rgb & 0xFF) / 255.0f;
    float g = ((rgb >> 8) & 0xFF) / 255.0f;
    float b = ((rgb >> 16) & 0xFF) / 255.0f;
    float max = r > g ? r : g;
    max = max > b ? max : b;
    float min = r < g ? r : g;
    min = min < b ? min : b;
    if (max == min) {
        hsl->x = 1.0f;
        hsl->y = 0.0f;
        hsl->z = min;
        return;
    }
    double sum = min + max;
    float delta = max - min;
    double ddelta = delta;
    hsl->y = delta;
    hsl->z = sum * 0.5;
    hsl->y = (hsl->z <= 0.5) ? ddelta / sum : ddelta / (2.0 - max - min);
    float bc = (max - b) / delta;
    float rc = (max - r) / delta;
    float gc = (max - g) / delta;
    if (r == max) {
        hsl->x = (g == min) ? 5.0 + bc : 1.0 - gc;
    } else if (g == max) {
        hsl->x = (r == min) ? 3.0 + rc : 3.0 - bc;
    } else {
        hsl->x = (r == min) ? 3.0 + gc : 5.0 - rc;
    }
    hsl->x /= 6.0f;
}

// 0x80022B3C
// Blends src over dst. The top bit of src's alpha selects between a blend
// weight and an alpha value to keep.
// NON_MATCHING: 75 instructions vs 76. The original copies dst into r3 right after
// taking src's alpha and keeps the weight in r31 with src left in r5; here dst stays
// in r4, so the channel arithmetic uses different registers and comes out in a
// different order (blue first instead of red). Eight variants tried (result written
// back into dst, a separate result variable, byte and word channel locals).
unsigned int Unk8001EE8C::fn_80022B3C(unsigned int dst, unsigned int src) {
    unsigned int alpha = src >> 24;
    int weight = 0xFF;
    unsigned int outAlpha = 0;
    if (!(alpha & 0x80)) {
        weight = (alpha << 1) & 0xFE;
    } else {
        outAlpha = (unsigned int)((float)(int)(alpha - 0x80) * 2.007874f);
    }
    if (weight != 0xFF) {
        int inverse = 0xFF - weight;
        unsigned int r = (weight * (src & 0xFF) + inverse * (dst & 0xFF)) / 0xFF;
        unsigned int g = (weight * ((src >> 8) & 0xFF) + inverse * ((dst >> 8) & 0xFF)) / 0xFF;
        unsigned int b = (weight * ((src >> 16) & 0xFF) + inverse * ((dst >> 16) & 0xFF)) / 0xFF;
        return (outAlpha << 24) | ((b & 0xFF) << 16) | ((g & 0xFF) << 8) | (r & 0xFF);
    }
    return (outAlpha << 24) | (src & 0xFFFFFF);
}

// 0x80022C6C
// Restores the palettes and releases the layer images.
void Unk8001EE8C::fn_80022C6C() {
    if (unk0[0]) {
        fn_801767FC(unk0[0]);
        unk0[0] = 0;
    }
    if (unk0[1]) {
        fn_80021D40(unk0[1], 1);
        fn_801767FC(unk0[1]);
        unk0[1] = 0;
    }
    if (unk0[2]) {
        fn_80021D40(unk0[2], 2);
        fn_801767FC(unk0[2]);
        unk0[2] = 0;
    }
    if (unk0[3]) {
        fn_80021D40(unk0[3], 3);
        fn_801767FC(unk0[3]);
        unk0[3] = 0;
    }
    if (unk0[4]) {
        fn_80021D40(unk0[4], 4);
        fn_801767FC(unk0[4]);
        unk0[4] = 0;
    }
    if (unk0[5]) {
        fn_80021D40(unk0[5], 5);
        fn_801767FC(unk0[5]);
        unk0[5] = 0;
    }
    if (unk0[6]) {
        fn_80021D40(unk0[6], 6);
        fn_801767FC(unk0[6]);
        unk0[6] = 0;
    }
    if (unk0[7]) {
        fn_80021D40(unk0[7], 7);
        fn_801767FC(unk0[7]);
        unk0[7] = 0;
    }
    if (unk0[8]) {
        fn_80021D40(unk0[8], 8);
        fn_801767FC(unk0[8]);
        unk0[8] = 0;
    }
    if (unk0[9]) {
        fn_80021D40(unk0[9], 9);
        fn_801767FC(unk0[9]);
        unk0[9] = 0;
    }
    if (unk0[10]) {
        fn_80021D40(unk0[10], 10);
        fn_801767FC(unk0[10]);
        unk0[10] = 0;
    }
    if (unk0[11]) {
        fn_801767FC(unk0[11]);
        unk0[11] = 0;
    }
    if (unk0[12]) {
        fn_80021D40(unk0[12], 11);
        fn_801767FC(unk0[12]);
        unk0[12] = 0;
    }
    if (unk0[13]) {
        fn_80021D40(unk0[13], 12);
        fn_801767FC(unk0[13]);
        unk0[13] = 0;
    }
    if (unk0[14]) {
        fn_801767FC(unk0[14]);
        unk0[14] = 0;
    }
    if (unk0[15]) {
        fn_80021D40(unk0[15], 14);
        fn_801767FC(unk0[15]);
        unk0[15] = 0;
    }
    if (unk0[16]) {
        fn_80021D40(unk0[16], 15);
        fn_801767FC(unk0[16]);
        unk0[16] = 0;
    }
}
