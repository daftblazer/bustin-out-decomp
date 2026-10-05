#ifndef ENGINE_UNK8018A44C_H
#define ENGINE_UNK8018A44C_H

#include "engine/Unk8018643C.h"

struct Unk8003C95C;

// Caption of a text button: an owned wide string or a pointer to a looked-up one.
struct Unk8018A154 {
    ~Unk8018A154();
    const unsigned short* Get() const {
        if (unk0) {
            return unk0 + 1;
        }
        return unk4 ? *unk4 : 0;
    }
    unsigned short* unk0;         // owned text, behind a two-byte header
    const unsigned short** unk4;
    int unk8;
};

// Text button (0xBC bytes; destructor 0x8018A44C). The name is unknown.
class Unk8018A44C : public Unk8018643C {
public:
    virtual ~Unk8018A44C();
    const unsigned short* GetText() const {
        if (unkA0.unk0) {
            return unkA0.unk0 + 1;
        }
        return unkA0.unk4 ? *unkA0.unk4 : 0;
    }

    Unk8003C95C* unk80;   // font
    int unk84;
    int unk88;            // alignment
    int unk8C;
    float unk90;          // text size
    char unk94[0xA0 - 0x94];
    Unk8018A154 unkA0;    // caption
    char unkAC[0xB0 - 0xAC];
    EVec3 unkB0;          // text position (x, -, y)
};

// The same with its own vtable (0x802BF8D8); its destructor (0x8018918C) is empty.
class Unk8018918C : public Unk8018A44C {
public:
    virtual ~Unk8018918C() {}
    virtual void vfn2(); // defined in the engine, which is where the vtable lives
};

#endif
