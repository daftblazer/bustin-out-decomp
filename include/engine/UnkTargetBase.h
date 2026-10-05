#ifndef ENGINE_UNKTARGETBASE_H
#define ENGINE_UNKTARGETBASE_H

// Base of the game's screen and widget objects: 0x44 bytes of data, then the
// vtable pointer (ctor 0x8018867C, dtor 0x80188754, update 0x801887C8). The
// real name is unknown; screens built on it are called "...Target" in The
// Sims 2's symbol map.
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

    char unk0[0x18];
    int unk18;   // flags: 2 = visible, 4 = active, 8 = focused
    char unk1C[0x20 - 0x1C];
    float unk20;
    char unk24[0x2C - 0x24];
    float unk2C; // x
    char unk30[0x34 - 0x30];
    float unk34; // y
    int unk38;   // player index
    char unk3C[0x44 - 0x3C];
};

#endif
