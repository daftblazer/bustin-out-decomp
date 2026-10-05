#ifndef SIMS_CAS_CASSIM_H
#define SIMS_CAS_CASSIM_H

#include "engine/EMat4.h"
#include "engine/EVec3.h"
#include "sims/cas/CASSelectors.h"
#include "sims/cas/CASWidgets.h"

// The sim model shown on the Create-A-Sim screen (the source file at
// 0x80018310) and the types it shares with the screen.

struct Unk8001EE8C {
    Unk8001EE8C();
    ~Unk8001EE8C();
    void fn_8001EFEC();
    void fn_8001F34C();
    void fn_8001FAE0();
    char unk0[4];
};

struct Unk801CC464 {
    Unk801CC464();
    Unk801CC464(const Unk801CC464& other);
    void fn_801CC688();
    int unk0;
    int unk4;
    signed char unk8[0x14]; // one choice per feature slot
};
// Description of one sim (0xF8 bytes); copied whole.
struct CASSimDesc {
    unsigned char unk0[0xC];
    Unk801CC464 unkC;
    unsigned short unk28[0x20]; // first name
    unsigned short unk68[0x20]; // family name
    int unkA8;
    int unkAC;
    int unkB0[14];
    char unkE8[0xF8 - 0xE8];
};
// A family of up to four sims.
struct CASFamily {
    CASSimDesc sims[4];
    int present[4];
    int unk3F0[4];
    void* unk400; // name object
};
extern "C" const unsigned short* fn_8023C9EC(void* name);
extern "C" void fn_8023C9FC(void* name, const unsigned short* text);
extern "C" void fn_8023CA3C(void* name, void* other);

// Animated model instance (0x74 bytes).
struct Unk80156438 {
    Unk80156438();
    void fn_80156700(unsigned int modelId);
    int fn_8015AA0C(int);  // animation finished
    void fn_8015A520(int); // restart
    void fn_801569F8(int, int, const EVec3& scale);
    void fn_8015B044(ERC* rc, Unk8033FF34Resource* model, const EMat4* transform); // draw
    void fn_80159994(int, unsigned int animationId);
    void SetUnk54(float value) { unk54 = value; }
    char unk0[0x54];
    float unk54;
    char unk58[0x70 - 0x58];
    virtual ~Unk80156438();
};

struct Unk800226F0 {
    void fn_800226F0(Unk801CC464* out);
    void fn_80021A14(int);
    void fn_80021D94();
    int fn_800218D8(int);
    void fn_80021928(int slot);
    void fn_8002196C(int slot);
};

// The sim being shown: its model, outfit resources and current choices.
// 0x19C bytes. The class name is provisional.
class Unk80018374 {
public:
    Unk80018374(CASSimDesc* desc, Unk8001EE8C* owner, int);
    Unk80018374(int, int, Unk8001EE8C* owner);
    ~Unk80018374() { fn_8001A67C(); }
    void fn_8001857C(int, int, Unk8001EE8C* owner);
    void fn_80018F5C(CASSimDesc* desc, Unk8001EE8C* owner);
    void fn_8001A67C();
    void fn_8001A908(ERC* rc, float turn, int); // draw
    void fn_8001AB8C(unsigned int animationId);
    int fn_8001AC00();
    void fn_8001AC88();
    void fn_8001AE1C(int, CASTargetUnk533C* selectors);
    void fn_8001B850(int slot);
    void fn_8001B8E4(int slot, int choice);
    int fn_8001BF1C(int slot);
    void fn_8001C028(int slot); // next choice
    void fn_8001C0A4(int slot); // previous choice
    void fn_8001C240();
    void fn_8001C2F4();
    void fn_8001C384();
    void fn_8001C3B8();
    int fn_8001D04C();
    int fn_8001DB38(int slot, int choice, int);
    void fn_8001E6E8(int, int);
    int fn_8001E794(int, int, int slot, int choice);
    int fn_8001E9D8(int, int, int slot, signed char choice); // true when the slot's choice is locked
    void SetUnk154(EVec3 position) { unk154 = position; }

    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    char unk18[0x2C - 0x18];
    int unk2C;
    char unk30[0x38 - 0x30];
    int unk38;
    int unk3C;
    int unk40; // which side the sim is seen from
    int unk44;
    char unk48[0x50 - 0x48];
    unsigned int** unk50; // animation id lists
    unsigned int** unk54;
    char unk58[0x90 - 0x58];
    void* unk90[7];       // per-slot resources (slots 1 to 7)
    char unkAC[0xBC - 0xAC];
    void* unkBC;          // slot 0 resource
    void* unkC0;          // slot 8 resource
    char unkC4[0xC8 - 0xC4];
    Unk800226F0* unkC8;
    char unkCC[0xD0 - 0xCC];
    struct UnkD0 {
        char unk0[0x14];
        int unk14;
    }* unkD0;
    char unkD4[0xE0 - 0xD4];
    Unk80156438 unkE0;
    EVec3 unk154; // position in the line-up
    char unk160[0x16C - 0x160];
    Unk801CC464 unk16C;
    char unk188[0x198 - 0x188];
    unsigned int unk198;  // animation waiting for its resource to load
};

// Resource manager used for the sim's animations.
struct Unk8033F3D8 {
    int fn_80177B24();
    void fn_801776C0(unsigned int id);
    int fn_801770C0(unsigned int id);
    void fn_801778B4(unsigned int id);
    char unk0[0x100]; // size unknown
};
extern Unk8033F3D8 lbl_8033F3D8;

// Last choices made for each of the four body types, kept between sessions.
extern Unk801CC464 lbl_802E5A1C;
extern Unk801CC464 lbl_802E5A38;
extern Unk801CC464 lbl_802E5A54;
extern Unk801CC464 lbl_802E5A70;

#endif
