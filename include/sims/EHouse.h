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
// One entry of the house's object list (next at 0x10, the object at 0x18).
struct Unk801B5358Node {
    char unk0[0x10];
    Unk801B5358Node* unk10;
    int unk14;
    void* unk18;
};
struct Unk801B5358 {
    Unk801B5358();                                             // 0x801B5358
    ~Unk801B5358() { fn_801B5D40(); }
    void fn_801B5D40();                                        // 0x801B5D40
    void fn_801B5704(int a, int b, int c);                     // 0x801B5704
    Unk801B5358Node* unk0;                                     // first entry
    char unk4[8];
};
class Unk801641A4 {
public:
    Unk801641A4();                                             // 0x801641A4
    virtual ~Unk801641A4();                                    // 0x80164248
    char unk4[0x74];                                           // (the vtable pointer follows, at 0x74)
};

// The loaded level resource (the engine's ERLevel in The Sims 2).
class ERLevel {
public:
    void Update();                                             // 0x8017A778 (ERLevel::Update in The Sims 2)
    void fn_8017AA14(ERC* rc);                                 // 0x8017AA14
    void fn_8017BE44();                                        // 0x8017BE44
    void fn_8017BF6C(void* object);                            // 0x8017BF6C
};
// The house's walls (0xA0 bytes; constructor 0x80055C60).
class Unk80055C60 {
public:
    Unk80055C60();                                             // 0x80055C60
    ~Unk80055C60();                                            // 0x80055D54
    int unk0;
    char unk4[0x9C];
    void fn_80056598(int state);
    void fn_80056914(int a);
    void fn_8005653C(ERC* rc);
};
// The house's objects (0x14 bytes; constructor 0x8007F234).
class Unk8007F234 {
public:
    void fn_8007FFE4(ERC* rc);                                 // 0x8007FFE4
};
void fn_8016C9A4(void* object);
void fn_8002A234(void* a, void* b);

const char* GetHouseNameText(int index);                       // 0x80049ADC

class EHouse {
public:
    ~EHouse();                                                 // 0x80049D50
    const char* GetHouseName();                                // 0x80049B7C
    void Init();                                               // 0x80049DA4
    void BuildHouse();                                         // 0x80049DE0 (guess)
    void fn_8004A90C();                                        // sets the room light scale
    void fn_8004ABB8();                                        // cleans up (called by the destructor)
    void fn_80049FB4(int state);                               // sets the wall state
    void fn_8004A0B4(ERC* rc);                                 // draws (guess: Draw)
    void DestroyWalls();                                       // 0x8004ACBC
    void fn_8004B578(int a, int b);                            // 0x8004B578
    void fn_8004B634();                                        // 0x8004B634
    void fn_8004B740(Unk8007F234* object);                     // 0x8004B740
    void SetNextWallMode();                                    // 0x80049FFC (guess)
    void fn_8004A110();                                        // runs one step of the house
    void fn_8004A91C();
    void fn_8004AE38();
    void fn_8004AFC0();
    void fn_8004B5AC();

    int unk0;                                                  // who made it
    Unk8007F234* unk4;
    Unk80055C60* unk8;
    int unkC;
    int unk10;
    int unk14;                                                 // 1 once built
    int unk18;
    ERLevel* unk1C;                                            // the level
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
