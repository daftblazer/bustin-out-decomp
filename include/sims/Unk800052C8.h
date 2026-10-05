#ifndef SIMS_UNK800052C8_H
#define SIMS_UNK800052C8_H

#include "engine/EMat4.h"
#include "engine/EVec3.h"
#include "sims/EGlobal.h"

// Small helper object built at 0x800B07DC and 0x800B084C (two per caller). It
// looks up a resource, creates a 0x17C-byte engine object for it and registers
// that with the level. Purpose and name unknown.

void* fn_801AD52C(unsigned int size, int tag);

// 0x17C bytes, ctor at 0x8016BC18.
struct Unk8016BC18 {
    Unk8016BC18();
    void fn_8016C750(void*);
    void fn_8016C944(int);
    void SetUnkE4(const EVec3& v) { unkE4 = v; }
    void fn_8016C878(EVec3*, int);
    void* operator new(unsigned int size) { return fn_801AD52C(size, 9); }

    char unk0[0xE4];
    EVec3 unkE4;
    char unkF0[0x17C - 0xF0];
};

struct Unk80340120Resource {
    int unk0;
    void* unk4;
    char unk8[0x2C - 0x8];
    EVec3 unk2C;
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

// Object with its vtable pointer at 0x1C; slot 88 tests a flag.
struct Unk800053D4Inner {
    char unk0[0x1C];
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn20();
    virtual void vfn21();
    virtual void vfn22();
    virtual void vfn23();
    virtual void vfn24();
    virtual void vfn25();
    virtual void vfn26();
    virtual void vfn27();
    virtual void vfn28();
    virtual void vfn29();
    virtual void vfn30();
    virtual void vfn31();
    virtual void vfn32();
    virtual void vfn33();
    virtual void vfn34();
    virtual void vfn35();
    virtual void vfn36();
    virtual void vfn37();
    virtual void vfn38();
    virtual void vfn39();
    virtual void vfn40();
    virtual void vfn41();
    virtual void vfn42();
    virtual void vfn43();
    virtual void vfn44();
    virtual void vfn45();
    virtual void vfn46();
    virtual void vfn47();
    virtual void vfn48();
    virtual void vfn49();
    virtual void vfn50();
    virtual void vfn51();
    virtual void vfn52();
    virtual void vfn53();
    virtual void vfn54();
    virtual void vfn55();
    virtual void vfn56();
    virtual void vfn57();
    virtual void vfn58();
    virtual void vfn59();
    virtual void vfn60();
    virtual void vfn61();
    virtual void vfn62();
    virtual void vfn63();
    virtual int vfn64();
    virtual void vfn65();
    virtual void vfn66();
    virtual void vfn67();
    virtual void vfn68();
    virtual void vfn69();
    virtual void vfn70();
    virtual void vfn71();
    virtual void vfn72();
    virtual void vfn73();
    virtual void vfn74();
    virtual void vfn75();
    virtual void vfn76();
    virtual void vfn77();
    virtual void vfn78();
    virtual void vfn79();
    virtual void vfn80();
    virtual void vfn81();
    virtual void vfn82();
    virtual void vfn83();
    virtual void vfn84();
    virtual void vfn85();
    virtual void vfn86();
    virtual void vfn87();
    virtual int vfn88(int);
};

// Skeleton-like object: slot 35 fetches the matrix of a node.
struct Unk800053D4Skeleton {
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn20();
    virtual void vfn21();
    virtual void vfn22();
    virtual void vfn23();
    virtual void vfn24();
    virtual void vfn25();
    virtual void vfn26();
    virtual void vfn27();
    virtual void vfn28();
    virtual void vfn29();
    virtual void vfn30();
    virtual void vfn31();
    virtual void vfn32();
    virtual void vfn33();
    virtual void vfn34();
    virtual void vfn35(unsigned int node, EMat4* out);
};

// Owner of the helper: first member points at the object above, vtable pointer at 4.
struct Unk800053D4Owner {
    Unk800053D4Inner* unk0;
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn20();
    virtual void vfn21();
    virtual void vfn22();
    virtual void vfn23();
    virtual void vfn24();
    virtual void vfn25();
    virtual void vfn26();
    virtual void vfn27();
    virtual void vfn28();
    virtual void vfn29();
    virtual void vfn30();
    virtual void vfn31();
    virtual void vfn32();
    virtual void vfn33();
    virtual void vfn34();
    virtual void vfn35();
    virtual void vfn36();
    virtual Unk800053D4Skeleton* vfn37();
};

struct Unk800052C8Source {
    unsigned int unk0;
    int unk4;
    float unk8, unkC, unk10; // position, as three plain floats
};

extern Unk80340120 lbl_80340120;
extern Unk802E67B0 lbl_802E67B0;

class Unk800052C8 {
public:
    Unk800052C8(unsigned int resourceId, Unk800053D4Owner* owner, Unk800052C8Source* source);
    void Update();
    ~Unk800052C8();

    Unk800053D4Owner* unk0;
    unsigned int unk4;
    Unk8016BC18* unk8;
    Unk80340120Resource* unkC;
    EVec3 unk10;
};

#endif
