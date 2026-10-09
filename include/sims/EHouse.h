#ifndef SIMS_EHOUSE_H
#define SIMS_EHOUSE_H

#include "sims/Unk80026864.h"

// A house on a lot (unit 0x80049ADC). The class name and the order of its methods are from
// The Sims 2's symbol map (EHouse: GetHouseName, the constructor, the destructor, Init,
// BuildHouse, SetWallState, SetNextWallMode, Draw, Update ...). GetHouseName and Init have
// the same sizes in both games; the other methods have different sizes (this game's
// constructor is 0x1B0 bytes, the Sims 2's 0x284), so their names are guesses by position
// and shape and are marked in the source. Member names keep their offsets.

struct ERC;
struct Unk801B5358 {
    Unk801B5358();                                             // 0x801B5358
    ~Unk801B5358() { fn_801B5D40(); }
    void fn_801B5D40();                                        // 0x801B5D40
    char unk0[0xC];
};
class Unk801641A4 {
public:
    Unk801641A4();                                             // 0x801641A4
    virtual ~Unk801641A4();                                    // 0x80164248
    char unk4[0x74];                                           // (the vtable pointer follows, at 0x74)
};

const char* GetHouseNameText(int index);                       // 0x80049ADC

class EHouse {
public:
    ~EHouse();                                                 // 0x80049D50
    const char* GetHouseName();                                // 0x80049B7C
    void Init();                                               // 0x80049DA4
    void BuildHouse();                                         // 0x80049DE0 (guess)
    void fn_8004A90C();                                        // sets the room light scale
    void fn_8004ABB8();                                        // cleans up (called by the destructor)

    int unk0;                                                  // who made it
    void* unk4;
    void* unk8;
    int unkC;
    int unk10;
    int unk14;                                                 // 1 once built
    int unk18;
    void* unk1C;                                               // the level (ERLevel)
    int unk20;                                                 // wall state
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    float unk34;
    float unk38;
    int unk3C;                                                 // which house (1 to 16)
    char unk40[0x4C - 0x40];
    Unk801B5358 unk4C;
    Unk801641A4 unk58;
    Unk8002EF48 unkD0;
    char unkF8[0x110 - 0xF8];
    float unk110;
};

#endif
