#ifndef SIMS_UNK8003B870_H
#define SIMS_UNK8003B870_H

// A per-player panel that shows up to five lines of text for a choice the player is
// asked to make with the four face buttons (0x4C bytes, vtable pointer at 0x48).
// The name is unknown.

#include "engine/BString2.h"

struct ERC;
struct Unk80181824;


class Unk8003B870 {
public:
    Unk8003B870(int player);
    virtual ~Unk8003B870();
    virtual long long vfn2(struct Unk8003BAB8A* a, unsigned char* b, struct Unk8003BAB8Sim* sim);

    void fn_8003B9E0();
    void fn_8003BFEC();
    void fn_8003C0F0(ERC* rc);

    int unk0;                    // player
    int unk4;                    // 1 while the panel is up
    int unk8;                    // buttons pressed this frame
    int unkC;
    int unk10;
    int unk14;
    BString2 unk18;
    BString2 unk1C;
    BString2 unk20;
    BString2 unk24;
    BString2 unk28;
    Unk80181824* unk2C;          // button sprites
    Unk80181824* unk30;
    Unk80181824* unk34;
    Unk80181824* unk38;
    Unk8003BAB8A* unk3C;         // what the texts were made for
    unsigned char* unk40;
    Unk8003BAB8Sim* unk44;
};

#endif
