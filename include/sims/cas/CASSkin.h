#ifndef SIMS_CAS_CASSKIN_H
#define SIMS_CAS_CASSKIN_H

#include "engine/EVec3.h"
#include "engine/ResourceManagers.h"

void fn_801767FC(void* resource);
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
    void fn_8001EF98(void* resource, unsigned int* color); // blend a layer's next pixel in
    void fn_8001EFEC();
    void fn_8001F34C();
    void fn_8001FAE0();
    void fn_8001FD00();
    void fn_8001FEA8(int layer, unsigned int textureId); // load a layer's image
    // Loads a skin layer and shifts its palette by the current skin tone.
    void LoadSkinLayer(int slot, int layer, unsigned int textureId);
    // Loads any other layer and remembers its palette.
    void LoadLayer(int slot, int index, unsigned int textureId) {
        if (unk0[slot]) {
            fn_80021D40(unk0[slot], index);
            fn_801767FC(unk0[slot]);
            unk0[slot] = 0;
        }
        if (textureId != 0) {
            unk0[slot] = (Unk80021CEC*)lbl_802E5E1C.fn_80177628(textureId, 0, 0);
            fn_80021CEC(unk0[slot], index);
        }
    }
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
    unsigned int fn_80022778(const EVec3& hsl);              // hue, saturation, lightness to 0x00BBGGRR
    void fn_80022940(unsigned int rgb, EVec3* hsl);          // and back
    unsigned int fn_80022B3C(unsigned int dst, unsigned int src); // blend one colour over another
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
    char unk408C;
    int unk4090;
    int unk4094;
    int unk4098;
};
typedef Unk8001EE8C Unk800226F0;

// Hue, saturation and lightness offsets of the eight skin tones.
extern EVec3 lbl_802E5A8C;
extern EVec3 lbl_802E5A98;
extern EVec3 lbl_802E5AA4;
extern EVec3 lbl_802E5AB0;
extern EVec3 lbl_802E5ABC;
extern EVec3 lbl_802E5AC8;
extern EVec3 lbl_802E5AD4;
extern EVec3 lbl_802E5AE0;

inline void Unk8001EE8C::LoadSkinLayer(int slot, int layer, unsigned int textureId) {
    if (unk0[slot]) {
        fn_80021D40(unk0[slot], slot);
        fn_801767FC(unk0[slot]);
        unk0[slot] = 0;
    }
    if (textureId != 0) {
        unk0[slot] = (Unk80021CEC*)lbl_802E5E1C.fn_80177628(textureId, 0, 0);
        fn_80021CEC(unk0[slot], slot);
        EVec3 hsl;
        hsl[0] = hsl[1] = hsl[2] = 0.0f;
        unsigned int count = 0x100;
        if (unk0[slot]->unk3C) {
            count = 0x10;
        }
        unsigned int* palette = unk0[slot]->unk24;
        float dh;
        float ds;
        float dl;
        switch (unk406C[0]) {
        case 7:
            dh = lbl_802E5AE0.x; ds = lbl_802E5AE0.y; dl = lbl_802E5AE0.z;
            break;
        case 1:
            dh = lbl_802E5A98.x; ds = lbl_802E5A98.y; dl = lbl_802E5A98.z;
            break;
        case 2:
            dh = lbl_802E5AA4.x; ds = lbl_802E5AA4.y; dl = lbl_802E5AA4.z;
            break;
        case 3:
            dh = lbl_802E5AB0.x; ds = lbl_802E5AB0.y; dl = lbl_802E5AB0.z;
            break;
        case 4:
            dh = lbl_802E5ABC.x; ds = lbl_802E5ABC.y; dl = lbl_802E5ABC.z;
            break;
        case 5:
            dh = lbl_802E5AC8.x; ds = lbl_802E5AC8.y; dl = lbl_802E5AC8.z;
            break;
        case 6:
            dh = lbl_802E5AD4.x; ds = lbl_802E5AD4.y; dl = lbl_802E5AD4.z;
            break;
        default:
            dh = lbl_802E5A8C.x; ds = lbl_802E5A8C.y; dl = lbl_802E5A8C.z;
            break;
        }
        for (unsigned int i = 0; i < count; i++) {
            unsigned int color = unk6C[layer - 1][i];
            unsigned int alpha = color & 0xFF000000;
            if (alpha) {
                fn_80022940(color, &hsl);
                float h = hsl[0] + dh;
                if (h > 1.0f) {
                    hsl[0] = h - 1.0f;
                } else if (h < 0.0f) {
                    hsl[0] = h + 1.0f;
                } else {
                    hsl[0] = h;
                }
                float s = hsl[1] + ds;
                if (s > 1.0f) {
                    hsl[1] = 1.0f;
                } else if (s < 0.0f) {
                    hsl[1] = 0.0f;
                } else {
                    hsl[1] = s;
                }
                float l = hsl[2] + dl;
                if (l > 1.0f) {
                    hsl[2] = 1.0f;
                } else if (l < 0.0f) {
                    hsl[2] = 0.0f;
                } else {
                    hsl[2] = l;
                }
                palette[i] = alpha + fn_80022778(EVec3(hsl[0], hsl[1], hsl[2]));
            } else {
                palette[i] = alpha;
            }
        }
    }
}

void fn_8001EF5C(void* resource, int* done);

#endif
