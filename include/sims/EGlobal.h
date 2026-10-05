#ifndef SIMS_EGLOBAL_H
#define SIMS_EGLOBAL_H

// The game's global state singleton at 0x802E6700. The class name comes from
// The Sims 2's symbol map (EGlobal::AllocSpriteRenderer lines up with one of
// its methods here); member and most method names are provisional.

class ESimsCam;
struct SimsAppUnk2B50Base;
struct ESimsCamUnkBC;
struct Unk800053D4Owner;
struct Unk80340120Resource;
struct Unk8016BC18;

struct Unk800669ACResult {
    int* ptr;
};

class EGlobal {
public:
    void Begin();                 // 0x8006887C
    void End();                   // 0x800661E0
    int fn_800655C4();
    unsigned int fn_800655D8();
    void fn_800656D8();
    Unk800669ACResult fn_800669AC(const char* format, ...);
    Unk800669ACResult fn_800667EC(const char* format, ...);
    Unk800669ACResult fn_8006670C(const char* format, ...);
    void fn_80068DE8(Unk80340120Resource*, Unk8016BC18*);
    void fn_800690E0(int);

    Unk800053D4Owner* GetUnk9C(int player) { return unk9C[player]; }
    void* GetUnk90() { return unk90; }
    int GetUnkA4() { return unkA4; }
    int GetUnk214() { return unk214; }

    struct {
        unsigned short unk0;        // 0x00 buttons allowed in cheat codes
        unsigned short codes[8][6]; // 0x02 button sequences, zero-terminated
        unsigned short masks[8];    // 0x62 buttons used by each sequence
    } cheats;
    char unk72[0x90 - 0x72];
    void* unk90;
    char unk94[0x9C - 0x94];
    Unk800053D4Owner* unk9C[2];   // per player
    int unkA4;
    struct Unk324* unkA8[4];      // per player, set from ESimsCam+0x324
    char unkB8[0xBC - 0xB8];
    ESimsCamUnkBC* unkBC;
    char unkC0[0xEC - 0xC0];
    struct Unk8003C95C* unkEC;    // default font
    char unkF0[0x118 - 0xF0];
    struct EGlobalUnk118* unk118;
    char unk11C[0x170 - 0x11C];
    int unk170;
    char unk174[0x17C - 0x174];
    int unk17C;
    char unk180[0x214 - 0x180];
    int unk214;
};

extern EGlobal lbl_802E6700;

// Looks up a localized string by name; null when it does not exist.
inline int GetText(const char* name) {
    Unk800669ACResult result = lbl_802E6700.fn_800667EC(name);
    return result.ptr ? *result.ptr : 0;
}

// As GetText, through the other look-up (0x8006670C).
inline int GetTextB(const char* name) {
    Unk800669ACResult result = lbl_802E6700.fn_8006670C(name);
    return result.ptr ? *result.ptr : 0;
}

#endif
