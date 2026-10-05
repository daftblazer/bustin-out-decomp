#include "sims/cas/CASSim.h"

// Hue, saturation and lightness offsets (unidentified use).
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
void Unk8001EE8C::fn_8001EF98(void* resource, int* out) {
    if (resource) {
        unsigned int value = fn_8003E3E8(resource);
        if (value & 0xFF000000) {
            *out = fn_80022B3C(*out, value);
        }
    }
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
