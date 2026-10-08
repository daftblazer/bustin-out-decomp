#include "engine/e_storable.h"
#include "engine/e_resource.h"
#include "sims/e_rrletexture.h"

// ERRleTexture (c:/eor/src2/games/sims/ESrc/e_rrletexture.cpp).

// The file as this unit reads it (vtable pointer at 0x18; slot 5 reads bytes).
struct EFile {
    char unk0[0x18];
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void Read(void* buffer, int size);
};

// Allocation from the texture manager, tagged with the place and a description.
// The line numbers are the original's.
#define RLE_FILE "c:/eor/src2/games/sims/ESrc/e_rrletexture.cpp"
#define RLE_ALLOC(size, line, name) lbl_802E5E1C->fn_80177EBC(size, RLE_FILE, line, name)

// Reverses the bytes of a 32-bit value in place. A macro working through one
// pointer variable of the enclosing function: because that pointer is assigned in
// more than one place the compiler cannot tell what it points at, and reloads the
// palette pointer after the byte stores, as the original does.
#define RLE_SWAP32(value) \
    bytes = (unsigned char*)&value; \
    a = bytes[3]; \
    b = bytes[0]; \
    bytes[0] = a; \
    bytes[3] = b; \
    b = bytes[1]; \
    a = bytes[2]; \
    bytes[2] = b; \
    bytes[1] = a

EStorableClass ERRleTexture::sInfo;
static int lbl_8037CAA0 = fn_801BBFCC(&ERRleTexture::sInfo, fn_8003E6E8, fn_8003E710, fn_8003E73C, 0, "ERRleTexture",
                                      &EResource::sInfo);

// 0x8003DF9C
ERRleTexture::ERRleTexture() {
    unk20 = 0;
    unk24 = 0;
}

// 0x8003DFE4
ERRleTexture::~ERRleTexture() {
    if (unk20) {
        lbl_802E5E1C->fn_80177FE0(unk20);
        unk20 = 0;
    }
    if (unk24) {
        lbl_802E5E1C->fn_80177FE0(unk24);
        unk24 = 0;
    }
}

// 0x8003E084
// Reads the texture: the palette (16 or 256 colours, byte-swapped), then the image.
void ERRleTexture::fn_8003E084(EFile* file) {
    unsigned char depth;
    file->Read(&depth, 1);
    int i;
    int colour;
    unsigned char* bytes;
    unsigned char a;
    unsigned char b;
    if (depth == 0x10) {
        unk3C = 1;
        if (unk24) {
            lbl_802E5E1C->fn_80177FE0(unk24);
        }
        unk24 = (int*)RLE_ALLOC(0x40, 82, "RLE Texture 16 color palette");
        file->Read(unk24, 0x40);
        for (i = 0; i < 0x10; i++) {
            colour = unk24[i];
            RLE_SWAP32(colour);
            unk24[i] = colour;
        }
    } else {
        unk3C = 0;
        if (unk24) {
            lbl_802E5E1C->fn_80177FE0(unk24);
        }
        unk24 = (int*)RLE_ALLOC(0x400, 118, "RLE Texture 256 color palette");
        file->Read(unk24, 0x400);
        for (i = 0; i < 0x100; i++) {
            colour = unk24[i];
            RLE_SWAP32(colour);
            unk24[i] = colour;
        }
    }
    file->Read(&unk34, 4);
    if (unk20) {
        lbl_802E5E1C->fn_80177FE0(unk20);
        unk20 = 0;
    }
    unk20 = (unsigned char*)RLE_ALLOC(unk34, 155, "RLE Texture image data");
    file->Read(unk20, unk34);
    unk29 = 0;
    unk38 = 1;
    unk30 = 0;
    unk2A = fn_8003E628();
    unsigned int run = unk2A;
    if (run >> 7) {
        unk28 = 1;
        unk2A = -run;
    } else {
        unk28 = 0;
        if (unk3C) {
            unk2C = unk24[fn_8003E5DC()];
        } else {
            unk2C = unk24[fn_8003E628()];
        }
    }
}

// 0x8003E350
// Goes back to the first pixel.
void ERRleTexture::fn_8003E350() {
    unk29 = 0;
    unk38 = 1;
    unk30 = 0;
    unk2A = fn_8003E628();
    unsigned int run = unk2A;
    if (run >> 7) {
        unk28 = 1;
        unk2A = -run;
    } else {
        unk28 = 0;
        if (unk3C) {
            unk2C = unk24[fn_8003E5DC()];
        } else {
            unk2C = unk24[fn_8003E628()];
        }
    }
}

// 0x8003E3E8
int ERRleTexture::fn_8003E3E8() {
    int colour;
    if (unk3C == 0) {
        colour = fn_8003E520();
    } else {
        colour = fn_8003E41C();
    }
    return colour;
}

// 0x8003E41C
int ERRleTexture::fn_8003E41C() {
    int colour;
    if (unk28 == 1) {
        colour = unk24[fn_8003E5DC()];
        unk29++;
        if (unk29 >= unk2A) {
            unk29 = 0;
            unk2A = fn_8003E628();
            unk2C = unk24[fn_8003E5DC()];
            unk28 = 0;
        }
    } else {
        colour = unk2C;
        unk29++;
        if (unk29 >= unk2A) {
            unk29 = 0;
            unk2A = fn_8003E628();
            unsigned int run = unk2A;
            if (run >> 7) {
                unk2A = -run;
                unk28 = 1;
            } else {
                unk28 = 0;
                unk2C = unk24[fn_8003E5DC()];
            }
        }
    }
    return colour;
}

// 0x8003E520
int ERRleTexture::fn_8003E520() {
    int colour;
    if (unk28 == 1) {
        colour = unk24[fn_8003E628()];
    } else {
        colour = unk2C;
    }
    unk29++;
    if (unk29 >= unk2A) {
        unk29 = 0;
        unk2A = fn_8003E628();
        unsigned int run = unk2A;
        if (run >> 7) {
            unk2A = -run;
            unk28 = 1;
        } else {
            unk28 = 0;
            unk2C = unk24[fn_8003E628()];
        }
    }
    return colour;
}

// 0x8003E5DC
int ERRleTexture::fn_8003E5DC() {
    int value;
    if (unk38) {
        unsigned char byte = *(unk20 + unk30);
        unk38 = 0;
        value = byte >> 4;
    } else {
        int at = unk30;
        unsigned char byte = *(unk20 + at);
        unk38 = 1;
        unk30 = at + 1;
        value = byte & 0xF;
    }
    return value;
}

// 0x8003E628
int ERRleTexture::fn_8003E628() {
    int value;
    if (unk38) {
        int at = unk30;
        value = *(unk20 + at);
        unk30 = at + 1;
    } else {
        int high = *(unk20 + unk30);
        unk30++;
        value = (high << 4) & 0xF0;
        value |= *(unk20 + unk30) >> 4;
    }
    return value;
}
