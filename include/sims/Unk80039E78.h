#ifndef SIMS_UNK80039E78_H
#define SIMS_UNK80039E78_H

#include "engine/EVec3.h"

struct ERC;
class E3DWindow;
struct ERFont;

// Text held in a caller-supplied buffer of 16-bit characters (functions at 0x8023C868).
struct Unk8023C868 {
    Unk8023C868(unsigned short* buffer, int capacity);       // 0x8023C868
    int fn_8023C8A8();                                       // length
    void fn_8023C8CC();                                      // clear
    void fn_8023C8DC(const unsigned short* text, int limit); // assign
    const unsigned short* fn_8023C9EC();                     // characters
    int unk0;
    int unk4;
};

// A message box with a wrapped text and a list of choices (0x890 bytes, vtable
// pointer at 0x88C). The name is unknown.
class Unk80039E78 {
public:
    Unk80039E78();
    virtual ~Unk80039E78();
    virtual void fn_80039F1C();     // load the font and the cursor
    virtual void fn_8003A6AC();     // release them

    void fn_8003A0C0(EVec2* position, int count, int* items, int text, int copy, int cancel, float width);
    int fn_8003A500();
    void fn_8003A734(ERC* rc, int draw, int centred);

    ERFont* unk0;               // font
    void* unk4;                      // cursor texture
    float unk8;                      // cursor animation phase
    int unkC;                        // the text was copied into unk14
    const unsigned short* unk10;     // the text, when it was not
    Unk8023C868 unk14;
    unsigned short unk1C[0x400];
    int unk81C;                      // the text did not fit
    unsigned int unk820;             // first line shown
    unsigned int unk824;             // lines counted
    int unk828;                      // selected choice
    int unk82C;
    int unk830;
    int unk834;                      // cancelling makes a sound
    E3DWindow* unk838;
    EVec2 unk83C;
    EVec2 unk844;
    EVec2 unk84C;                    // size
    EVec2 unk854;                    // position
    float unk85C;
    float unk860;
    EVec2 unk864;
    EVec2 unk86C;                    // margin
    float unk874;
    float unk878;
    EVec2 unk87C;                    // text cursor
    int* unk884;                     // choices (texts)
    unsigned int unk888;             // number of choices
};

#endif
