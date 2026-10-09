#ifndef SIMS_UNK8003B870_H
#define SIMS_UNK8003B870_H

// A per-player panel that shows up to five lines of text for a choice the player is
// asked to make with the four face buttons (0x4C bytes, vtable pointer at 0x48).
// The name is unknown.

struct ERC;
struct Unk80181824;

// The engine's string class as this file uses it (4 bytes; constructor 0x801C4E90).
struct Unk8003B870String {
    Unk8003B870String();                             // 0x801C4E90
    Unk8003B870String(unsigned char character, int count);   // 0x801C5024
    Unk8003B870String(const unsigned short* text);   // 0x801C4FDC
    Unk8003B870String(const Unk8003B870String& other, int start, int count);   // 0x801C4EB0
    Unk8003B870String(const wchar_t* text);          // 0x801C60F0
    void fn_801C54EC(const Unk8003B870String& other, int start, int count);   // append
    int fn_801C6058();                               // non-zero when it has text
    ~Unk8003B870String();                            // 0x801C5074
    Unk8003B870String& operator=(const Unk8003B870String& other);   // 0x801C50B4
    Unk8003B870String& operator=(const unsigned short* text);       // 0x801C5148
    void fn_801C5704(int start, int count);          // erase
    void fn_801C55CC(const unsigned short* text);    // assign
    const unsigned short* fn_801C5B24();             // characters
    int fn_801C6020(const Unk8003B870String& other); // non-zero when different
    int operator!=(const Unk8003B870String& other) { return fn_801C6020(other); }
    void* unk0;
};

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
    Unk8003B870String unk18;
    Unk8003B870String unk1C;
    Unk8003B870String unk20;
    Unk8003B870String unk24;
    Unk8003B870String unk28;
    Unk80181824* unk2C;          // button sprites
    Unk80181824* unk30;
    Unk80181824* unk34;
    Unk80181824* unk38;
    Unk8003BAB8A* unk3C;         // what the texts were made for
    unsigned char* unk40;
    Unk8003BAB8Sim* unk44;
};

#endif
