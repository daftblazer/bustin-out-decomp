#ifndef ENGINE_UNKTARGETBASE_H
#define ENGINE_UNKTARGETBASE_H

#include "engine/EVec3.h"

extern "C" void fn_8024254C(unsigned short* dst, const unsigned short* src); // wide string copy

// Inline wrapper: its parameters make the call load the source before the
// destination.
inline void ECopyText(unsigned short* dst, const unsigned short* src) { fn_8024254C(dst, src); }

// Wide string holder (constructor 0x801BA678); assignment copies the text.
struct Unk801BA678 {
    Unk801BA678();
    ~Unk801BA678() { fn_801BA694(unk0); }
    void fn_801BA694(unsigned short* text);
    void fn_801BA0F4(const unsigned short* text);
    Unk801BA678& operator=(const Unk801BA678& other) {
        fn_801BA0F4(other.unk0);
        return *this;
    }
    unsigned short* Get() const { return unk0; }
    void Assign(const Unk801BA678& other) { ECopyText(unk0, other.unk0); }

    unsigned short* unk0; // text buffer
};

// 12-byte container at the start of every screen object; assignment empties
// it and then copies.
struct Unk801B4760 {
    void fn_801B4760();
    void fn_801B4670(const Unk801B4760& other);
    Unk801B4760& operator=(const Unk801B4760& other) {
        fn_801B4760();
        fn_801B4670(other);
        return *this;
    }

    char unk0[0xC];
};

// Base of the game's screen and widget objects: 0x44 bytes of data, then the
// vtable pointer (ctor 0x8018867C, dtor 0x80188754, update 0x801887C8). The
// real name is unknown; screens built on it are called "...Target" in The
// Sims 2's symbol map. The member layout comes from the compiler-generated
// assignment operators of two derived classes.
class UnkTargetBase {
public:
    UnkTargetBase();
    virtual ~UnkTargetBase();                             // slot 1
    virtual void vfn2();
    virtual void vfn3();                                  // per-frame update
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7(UnkTargetBase* sender, int message); // slot 7

    void fn_801887C8(); // base update

    Unk801B4760 unk0;
    int unkC;
    int unk10;
    Unk801BA678 unk14;
    int unk18;   // flags: 2 = visible, 4 = active, 8 = focused
    int unk1C;
    EVec3 unk20; // x = width
    EVec3 unk2C; // x and z = screen position
    int unk38;   // player index
    int unk3C;
    int unk40;
};

#endif
