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
// The engine's instance class as far as the house uses it: something with a virtual
// destructor in slot 6 (EInstance in The Sims 2). Lights derive from it.
// The virtuals come from a base without data (the vtable pointer is at offset 0).
class EInstanceBase {
public:
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual ~EInstanceBase();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
};
class EInstance : public EInstanceBase {
public:
    // Gives the instance its callback (and marks it, unless it is marked already).
    void SetCallback(int (*callback)()) {
        unk2C = callback;
        if (unk8 == 0) {
            unk8 = 1;
        }
    }
    int unk4;
    int unk8;
    char unkC[0x2C - 0xC];
    int (*unk2C)();
    char unk30[0x3C - 0x30];
    int unk3C;
};
class EILight : public EInstance {
};
// The two lights a house makes for itself (0xC0 and 0xB4 bytes).
class Unk80163510 : public EILight {
public:
    Unk80163510();                                             // 0x80163510
    char unk40[0xC0 - 0x40];
};
class Unk80163BB0 : public EILight {
public:
    Unk80163BB0();                                             // 0x80163BB0
    char unk40[0xB4 - 0x40];
};
// Derived from the second one; its vtable is at 0x802C9318, in the engine.
class Unk802C9318 : public Unk80163BB0 {
public:
    Unk802C9318() {}
    virtual void vfn1();
};
// The level's bounds and the sphere around them.
struct Unk801ADFAC {
    EVec3 unk0;
    float unkC;
};
struct Unk8017A638 {
    EVec3 unk0;
    EVec3 unkC;
    void fn_801ADFAC(Unk801ADFAC* sphere);                     // 0x801ADFAC
};

// One entry of the house's object list (next at 0x10, the object at 0x18).
struct Unk801B5358Node {
    char unk0[0x10];
    Unk801B5358Node* unk10;
    int unk14;
    EInstance* unk18;
    void* unk1C;                                               // a resource held for it
};
struct Unk801B5358 {
    Unk801B5358();                                             // 0x801B5358
    ~Unk801B5358() { fn_801B5D40(); }
    void fn_801B5D40();                                        // 0x801B5D40
    void fn_801B5704(int a, int b, int c);                     // 0x801B5704
    void fn_801B5B08(Unk801B5358Node* node);                   // takes one entry out
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
    char unk0[0x20];
    float unk20;
    void Update();                                             // 0x8017A778 (ERLevel::Update in The Sims 2)
    void fn_8017AA14(ERC* rc);                                 // 0x8017AA14
    void fn_8017BE44();                                        // 0x8017BE44
    void fn_8017BF6C(Unk8002EF48* descriptor);                 // 0x8017BF6C: puts an object into the level
    void RemoveLight(EILight* light);                          // 0x80179EAC (ERLevel::RemoveLight in The Sims 2)
    void fn_8017B8C0(int a);
    void fn_8017B5B0(int a);
    void fn_80179E68(EILight* light);                         // 0x80179E68: adds a light
    void fn_8017BCF0(int room, const EVec3& position);        // 0x8017BCF0
    void fn_8017BE20();
    Unk8017A638 fn_8017A638();                                 // 0x8017A638: bounds
    void fn_8017B7FC();                                        // 0x8017B7FC
    void fn_80176860();                                        // 0x80176860: takes a reference
};
// The house's walls (0xA0 bytes; constructor 0x80055C60).
class Unk80055C60 {
public:
    Unk80055C60();                                             // 0x80055C60
    ~Unk80055C60();                                            // 0x80055D54
    int unk0;
    char unk4[0x9C];
    void fn_80056FFC();                                        // 0x80056FFC
    void fn_80056598(int state);
    void fn_80056914(int a);
    void fn_8005653C(ERC* rc);
};
// The house's objects (0x14 bytes). The name is from The Sims 2: its constructor, destructor,
// RemoveObjectsFromHouse and PostLoad have the same sizes here (`=` hints at 0x8007F234,
// 0x8007F2F4, 0x8007FAB8 and 0x8007FE38).
class EHouse;
class EIObjectMan {
public:
    EIObjectMan(EHouse* house);                                // 0x8007F234
    void fn_8007F278();                                        // 0x8007F278
    void PostLoad();                                           // 0x8007FE38 (EIObjectMan::PostLoad in The Sims 2)
    ~EIObjectMan();                                            // 0x8007F2F4
    void RemoveObjectsFromHouse(ERLevel* level);
    void fn_8007FFE8(int a);                                   // 0x8007FFE8
    void fn_8007FFE4(ERC* rc);                                 // 0x8007FFE4
    char unk0[0x14];
};
void fn_8016C9A4(EInstance* object);
void fn_801767FC(void* resource);                              // releases a resource
void fn_80075ABC();
class EHouse;
void fn_80075B60(EHouse* house);                               // 0x80075B60
void fn_8002A234(void* a, void* b);

const char* GetHouseNameText(int index);                       // 0x80049ADC

class EHouse {
public:
    EHouse(EVec2& position, int id, ERLevel* level, bool makeObjects, bool makeWalls, bool unused,
           bool owner);                                        // 0x80049BA0
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
    void fn_8004B740(Unk8002EF48* descriptor);                 // 0x8004B740
    void fn_8004B6A4(Unk80026864* object);                     // 0x8004B6A4
    void CleanUpRoomLights();                                  // 0x8004B4A0 (guess)
    void SetNextWallMode();                                    // 0x80049FFC (guess)
    void fn_8004A110();                                        // runs one step of the house
    void fn_8004A91C();
    void fn_8004AD08();
    void fn_8004B10C();
    void fn_8004AE38();
    void fn_8004AFC0();
    float fn_8004B300(int room);
    void fn_8004B5AC();

    int unk0;                                                  // who made it
    EIObjectMan* unk4;
    Unk80055C60* unk8;
    int unkC;
    int unk10;
    int unk14;                                                 // 1 once built
    int unk18;
    ERLevel* unk1C;                                            // the level
    int unk20;                                                 // wall state
    EILight* unk24;                                            // the sun / ambient light
    EILight* unk28;
    EILight** unk2C;                                           // one light per room
    int unk30;                                                 // how many
    float unk34;
    float unk38;
    int unk3C;                                                 // which house (1 to 16)
    char unk40[0x4C - 0x40];
    Unk801B5358 unk4C;
    Unk801641A4 unk58;
    Unk8002EF48 unkD0;
    char unkF8[0x104 - 0xF8];
    EVec3 unk104;                                              // where the object was put
    float unk110;
};

#endif
