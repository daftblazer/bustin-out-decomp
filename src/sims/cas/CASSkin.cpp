#include "sims/cas/CASSim.h"

void fn_8003E350(void* resource);
unsigned int fn_8003E3E8(void* resource);

// 0x8001EE8C
Unk8001EE8C::Unk8001EE8C() {
    unk4098 = 0;
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
