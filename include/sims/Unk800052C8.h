#ifndef SIMS_UNK800052C8_H
#define SIMS_UNK800052C8_H

#include "engine/EVec3.h"

// Small helper object built at 0x800B07DC and 0x800B084C (two per caller). It
// looks up a resource, creates a 0x17C-byte engine object for it and registers
// that with the level. Purpose and name unknown.

void* fn_801AD52C(unsigned int size, int tag);

// 0x17C bytes, ctor at 0x8016BC18.
struct Unk8016BC18 {
    Unk8016BC18();
    void fn_8016C750(void*);
    void* operator new(unsigned int size) { return fn_801AD52C(size, 9); }

    char unk0[0x17C];
};

struct Unk80340120Resource {
    int unk0;
    void* unk4;
};

struct Unk80340120 {
    Unk80340120Resource* fn_80177628(unsigned int id, int, int);
    char unk0[0x100]; // size unknown
};

struct Unk80179D60 {
    void fn_80179D60(Unk8016BC18*, int);
};

struct Unk802E67B0Target {
    char unk0[0x1C];
    Unk80179D60* unk1C;
};

struct Unk802E67B0 {
    Unk802E67B0Target* unk0;
    char unk4[0x100]; // size unknown
};

struct Unk800052C8Source {
    unsigned int unk0;
    int unk4;
    float unk8, unkC, unk10; // position, as three plain floats
};

struct Unk802E6700;
extern Unk802E6700 lbl_802E6700;
extern Unk80340120 lbl_80340120;
extern Unk802E67B0 lbl_802E67B0;
void fn_80068DE8(Unk802E6700*, Unk80340120Resource*, Unk8016BC18*);

class Unk800052C8 {
public:
    Unk800052C8(unsigned int resourceId, int unk, Unk800052C8Source* source);
    ~Unk800052C8();

    int unk0;
    unsigned int unk4;
    Unk8016BC18* unk8;
    Unk80340120Resource* unkC;
    EVec3 unk10;
};

#endif
