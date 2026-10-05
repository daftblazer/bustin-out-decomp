#include "sims/cas/CASSim.h"

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
