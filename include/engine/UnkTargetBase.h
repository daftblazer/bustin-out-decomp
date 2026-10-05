#ifndef ENGINE_UNKTARGETBASE_H
#define ENGINE_UNKTARGETBASE_H

#include "engine/EVec3.h"

extern "C" void fn_8024254C(unsigned short* dst, const unsigned short* src); // wide string copy

// Wide string holder (constructor 0x801BA678); assignment copies the text.
struct Unk801BA678 {
    Unk801BA678();
    ~Unk801BA678() { fn_801BA694(unk0); }
    void fn_801BA694(unsigned short* text);
    void fn_801BA0F4(const unsigned short* text);
    void fn_801BA958(int capacity, int);
    Unk801BA678(const char* text);                       // 0x801BA6D4
    Unk801BA678(const unsigned short* text);             // 0x801BA7CC
    int fn_801BA934() const;                             // length
    void fn_801BA860(const unsigned short* text);        // assign
    void fn_801BAF74(unsigned short character);          // strip leading
    int fn_801BAEE8(unsigned short character);
    Unk801BA678 fn_801BAC38(int length) const;           // first `length` characters
    Unk801BA678& operator=(const Unk801BA678& other) {
        fn_801BA0F4(other.unk0);
        return *this;
    }
    unsigned short* Get() const { return unk0; }
    void Assign(const Unk801BA678& other) { fn_8024254C(unk0, other.unk0); }

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
    virtual void vfn2();                                  // slot 2: per-frame update
    virtual void vfn3(struct ERC* rc);                    // slot 3: draw
    virtual void vfn4(const EVec3& size);                  // slot 4
    virtual void vfn5();
    virtual void vfn6(const EVec2& position);              // slot 6
    virtual void vfn7(UnkTargetBase* sender, int message); // slot 7
    virtual void vfn8(const char* name, const char* value); // slot 8: UI script variable set
    virtual char* vfn9(const char* name);                  // slot 9: UI script variable look-up
    virtual void vfn10(int flags, int set);
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14(UnkTargetBase* child);              // slot 14: add a child
    virtual void vfn15(UnkTargetBase* child);              // slot 15
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();                                  // last slot (vtables are 0x98 bytes)

    void fn_801887C8(); // base update
    void fn_80188B10(UnkTargetBase* child); // detach a child
    void fn_80188850(struct ERC* rc); // base draw
    void fn_801888F4(int flags, int set);

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
