#ifndef ENGINE_UNK801C3E10_H
#define ENGINE_UNK801C3E10_H

// The engine's string object (constructors at 0x801C3E10 and 0x801C3E30, destructor
// at 0x801C3E78). Eight bytes: fn_8003F038 keeps one at sp+8 with the next local at sp+0x10.
struct Unk801C3E10 {
    Unk801C3E10();                     // 0x801C3E10
    Unk801C3E10(const char* text);     // 0x801C3E30
    ~Unk801C3E10();                    // 0x801C3E78
    char unk0[8];
};

#endif
