#ifndef SIMS_CAS_CASSKIN_H
#define SIMS_CAS_CASSKIN_H

struct Unk80182DE0Inner;
struct ETextureLike;

// The choices that describe one sim (0x1C bytes).
struct Unk801CC464 {
    Unk801CC464();
    Unk801CC464(const Unk801CC464& other);
    void fn_801CC688();
    int unk0;
    int unk4;
    signed char unk8[0x14]; // one choice per feature slot
};

// Paletted image: colour table at 0x24, 16 colours instead of 256 when unk3C is set.
struct Unk80021CEC {
    char unk0[0x24];
    unsigned int* unk24;
    char unk28[0x3C - 0x28];
    int unk3C;
};

// Builds and caches the sim's composited skin texture and its materials (the
// class of the source file at 0x8001EE8C). 0x409C bytes. The name is
// provisional; "Unk800226F0" is the same class.
struct Unk8001EE8C {
    Unk8001EE8C();
    ~Unk8001EE8C();
    void fn_8001EF98(void* resource, int* out);
    void fn_8001EFEC();
    void fn_8001F34C();
    void fn_8001FAE0();
    void fn_8001FD00();
    void fn_8001FEA8(int, unsigned int textureId);
    void fn_80020EF4(int layer, int choice, int);
    int fn_800218D8(int layer);              // current choice of a texture layer
    void fn_80021928(int layer);             // next
    void fn_8002196C(int layer);             // previous
    void fn_80021A14(ETextureLike* texture);
    void fn_80021CEC(Unk80021CEC* image, int index); // remember a palette
    void fn_80021D40(Unk80021CEC* image, int index); // put it back
    void fn_80021D94();
    void fn_80021DBC(int adult, int male);
    void fn_800226F0(Unk801CC464* out);      // store the layer choices in a description
    void fn_80022724(Unk801CC464* choices);  // and take them from one
    int fn_80022B3C(int, unsigned int);
    void fn_80022C6C();

    Unk80021CEC* unk0[17];    // source images of the texture layers
    Unk80182DE0Inner* unk44; // materials: head, body, clothes
    Unk80182DE0Inner* unk48;
    Unk80182DE0Inner* unk4C;
    ETextureLike* unk50;
    char unk54[0x6C - 0x54];
    unsigned int unk6C[16][0x100]; // saved palettes
    signed char unk406C[16];       // choice of each texture layer
    signed char unk407C[16];       // the same, as last applied
    char unk408C[0x4094 - 0x408C];
    int unk4094;
    int unk4098;
};
typedef Unk8001EE8C Unk800226F0;

void fn_8001EF5C(void* resource, int* done);

#endif
