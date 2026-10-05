#ifndef SIMS_CAS_CASSIM_H
#define SIMS_CAS_CASSIM_H

#include "engine/ELightSet.h"
#include "engine/EMat4.h"
#include "engine/EVec3.h"
#include "sims/cas/CASSkin.h"
#include "engine/ResourceManagers.h"
#include "engine/Unk801543AC.h"
#include <new.h>
#include "sims/cas/CASSelectors.h"
#include "sims/cas/CASWidgets.h"

struct Unk80182DE0Inner;
struct ETextureLike;
class Unk80018374;

// The sim model shown on the Create-A-Sim screen (the source file at
// 0x80018310) and the types it shares with the screen.


// Description of one sim (0xF8 bytes); copied whole.
struct CASSimDesc {
    unsigned char unk0[0xC];
    Unk801CC464 unkC;
    unsigned short unk28[0x20]; // first name
    unsigned short unk68[0x20]; // family name
    ETextureLike* unkA8;        // small copy of the skin texture
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
    void fn_8015AB78(float);
    float fn_8015A82C(int);
    void fn_8015980C(int);
    void fn_801598A8(int, int);
    void fn_80159FE4(int, float, float, float);
    void fn_80159CBC(int channel, float weight);
    void fn_8015A100(int channel, float, float, float, float);
    void SetUnk54(float value) { unk54 = value; }
    void SetCallback(void (*callback)(Unk80018374*, int, int, EMat4*), void* owner) {
        unk6C = owner;
        unk68 = callback;
    }
    void fn_80157BD0(const EMat4* transform, int);
    void fn_80156954();
    char unk0[4];
    int unk4;
    char unk8[0x18 - 0x8];
    struct Unk80156438Inner {
        char unk0[0x24];
        int unk24;
    }* unk18;
    char unk1C[0x2C - 0x1C];
    struct Unk801B5CE8 {
        int fn_801B5CE8(int, int);
        char unk0[4];
    } unk2C;
    char unk30[0x54 - 0x30];
    float unk54;
    char unk58[0x68 - 0x58];
    void (*unk68)(Unk80018374*, int, int, EMat4*); // callback applied to the bone matrices
    void* unk6C;         // its owner
    virtual ~Unk80156438();

};


class Unk80018374;

// Narrow string holder (constructor 0x801B9FEC); the destructor frees the text.
struct Unk801B9FEC {
    Unk801B9FEC();
    Unk801B9FEC(const char* text); // 0x801BA070
    Unk801B9FEC(const char* a, const char* b); // 0x801B9F30: the two joined
    ~Unk801B9FEC() { fn_801B9FF8(unk0); }
    void fn_801B9FF8(void*);
    void fn_801BA18C(int capacity);
    char* unk0;
};

struct CASAnimStep;

// Data set resource with named nodes.
struct Unk801800FC {
    void fn_8017FF7C();
    int fn_801800FC(const char* name);
    int Find(const char* name) { return fn_801800FC(name); }
    unsigned int** fn_8018021C(int node, const char* name);
    unsigned int** Get(int node, const char* name) { return fn_8018021C(node, name); }
};

// Texture object: vtable pointer at 0x24.
struct ETextureLike {
    char unk0[0x24];
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5(int mode);                 // lock
    virtual void* vfn6(int, int* a, int* b);     // palette
    virtual void* vfn7();                        // pixels
    virtual void vfn8();                         // unlock
};
// Texture description passed to the renderer (0x20 bytes); the constructor sets
// the defaults.
struct ETextureDesc {
    ETextureDesc() {
        unk0 = 0;
        unk18 = 1;
        unk10 = 0x40;
        unkC = 0.0f;
        unk12 = 0x40;
        unk1A = 0x20;
        unk19 = 0;
        unk1B = 0;
        unk1C = 0;
        unk4 = 0;
        unk8 = 0;
        unk14 = 0;
        unk16 = 0;
    }
    int unk0;
    int unk4;
    int unk8;            // flags
    float unkC;
    unsigned short unk10; // width
    unsigned short unk12; // height
    unsigned short unk14; // palette entries
    unsigned short unk16;
    unsigned char unk18;  // format
    unsigned char unk19;
    unsigned char unk1A;  // bits per pixel
    unsigned char unk1B;  // bits per palette entry
    const char* unk1C;    // name
};
// Material: its texture at 0x14, vtable pointer at 0xB8; slot 2 applies it.
struct Unk80182DE0Inner {
    char unk0[0x14];
    ETextureLike* unk14;
    char unk18[0xB8 - 0x18];
    virtual void vfn1();
    virtual void vfn2(ERC* rc);
    virtual void vfn3(ERC* rc);
};
// Description of a material (0xD0 bytes), as handed to the renderer. Only the
// fields the sim's material sets are named; the layout is partly guessed.
struct EMaterialStage {
    EMaterialStage() {
        unk0 = 0;
        unk4 = 8;
        unk8 = 0x18;
        unk10 = 0;
        unk11 = 1;
        unk12 = 0;
        unk13 = 1;
        unk14 = 0x80;
        unk15 = 0;
        unk16 = 0;
        unkC = 0.5f;
    }
    void* unk0;          // texture
    int unk4;            // flags
    int unk8;
    float unkC;
    unsigned char unk10, unk11, unk12, unk13, unk14, unk15, unk16;
};
struct EMaterialDesc {
    int unk0;
    int unk4;
    int unk8;
    unsigned char unkC;
    unsigned char unkD;
    int unk10;
    EMaterialStage stages[2];   // 0x14
    EColorF unk44;              // 0x44
    EVec3 unk54;
    EVec3 unk60;
    char unk6C[0x7C - 0x6C];
    float unk7C;
    float unk80;
    float unk84;
    char unk88[0x8C - 0x88];
    EVec2 unk8C[4];
    char unkAC[0xD0 - 0xAC];
};

// Off-screen render target: vtable pointer at 0x1C; slot 10 copies it into a texture.
struct ERenderTarget {
    char unk0[0x1C];
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10(ETextureLike* texture);
};
// Size and clear colour of a render target (0x20 bytes).
struct EViewportDesc {
    int unk0;   // width
    int unk4;   // height
    int unk8;
    EVec3 unkC; // clear colour
    int unk18;
    int unk1C;
};
// Colour quantizer (0x1CF8 bytes): collects colours, builds a palette, maps
// colours to palette indices.
struct Unk801B7464 {
    Unk801B7464();
    ~Unk801B7464();
    void fn_801B7538(int maxColors, int, int, int, int);
    void fn_801B79B4(const unsigned char* rgb);            // add a sample
    void fn_801B8308();                                    // build the palette
    int fn_801B8630();                                     // palette size
    void fn_801B8638(int index, unsigned char* rgb);       // palette entry
    unsigned char fn_801B8664(const unsigned char* rgb);   // nearest index
    void fn_801B74E8();
    char unk0[0x1CF8];
};
void fn_801AD298(const void* pixels, int width, int height, unsigned char* rgbaOut);

// The renderer: screen size in pixels, and the texture and material caches.
struct CASScreenInfoBase {
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual ERC* vfn13(int);                        // begin drawing
    virtual void vfn14(ERC* rc);                    // end drawing
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual ETextureLike* vfn20(ETextureDesc* desc); // create a texture
    virtual void vfn21(void* texture);               // release a texture
    virtual int vfn22(void* texture);
    virtual struct ERenderTarget* vfn23(struct EViewportDesc* desc); // create a render target
    virtual void vfn24(ERenderTarget* target);       // release it
    virtual void vfn25();
    virtual void vfn26();
    virtual void vfn27();
    virtual void vfn28();
    virtual void vfn29();
    virtual Unk80182DE0Inner* vfn30(EMaterialDesc* desc); // create a material
    virtual void vfn31(void* material);              // release a material
    virtual int vfn32(void* material);
    virtual void vfn33();
    virtual void vfn34();
    virtual void vfn35();
    virtual void vfn36();
    virtual float vfn37(); // pixel aspect
    virtual void vfn38();
    virtual void vfn39();
    virtual void vfn40();
    virtual void vfn41();
    virtual void vfn42();
    virtual void vfn43();
    virtual void vfn44();
};
struct CASScreenInfo : CASScreenInfoBase {
    char unk4[0x10];
    int unk14; // width
    int unk18; // height
};
extern CASScreenInfo* lbl_8037C198;

// The sim being shown: its model, outfit resources and current choices.
// 0x19C bytes. The class name is provisional.
class Unk80018374 {
public:
    Unk80018374(CASSimDesc* desc, Unk8001EE8C* owner, int);
    Unk80018374(int, int, Unk8001EE8C* owner);
    ~Unk80018374() { fn_8001A67C(); }
    void fn_8001857C(int, int, Unk8001EE8C* owner);
    void fn_80018F5C(CASSimDesc* desc, Unk8001EE8C* owner);
    void fn_8001A19C(); // fill in the light set
    void fn_8001A67C();
    void fn_8001A908(ERC* rc, float turn, int); // draw
    void fn_8001AB8C(unsigned int animationId);
    int fn_8001AC00();
    int fn_8001B378(CASAnimStep** steps, unsigned int step, int which);
    void fn_8001AC88();
    void fn_8001AE1C(int, CASTargetUnk533C* selectors);
    void fn_8001B53C(int slot, unsigned int modelId);
    void fn_8001B850(int slot);
    void fn_8001B8E4(int slot, unsigned int choice); // set a slot's choice and load its model and textures
    int fn_8001BF1C(unsigned int slot); // current choice for a slot
    void fn_8001C028(int slot); // next choice
    void fn_8001C0A4(int slot); // previous choice
    void fn_8001C240();
    void fn_8001C2F4();
    void fn_8001C384();
    void fn_8001C3B8(); // render the portrait into unkCC
    ETextureLike* fn_8001D04C();
    void fn_8001D6D8(ERC* rc); // draw the shadow
    void fn_8001D844(const Unk801B9FEC& suffix);
    void fn_800198DC(); // set up as adult male
    void fn_80019AEC(); // adult female
    void fn_80019CFC(); // child male
    void fn_80019F4C(); // child female
    int fn_8001DB38(int slot, int choice, int);
    void fn_8001E6E8(int, int);
    int fn_8001E794(int adult, int male, int slot, int choice); // true when the choice is still locked
    int fn_8001E9D8(int adult, int male, int slot, int choice); // true when the choice starts out locked
    void SetUnk154(EVec3 position) { unk154 = position; }
    // Looks up the list called `name` + `suffix`.
    void* FindList(int list, const char* name, const char* suffix) {
        Unk801B9FEC key(name, suffix);
        return unk18C->fn_8018021C(list, key.unk0);
    }

    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    float unk20;
    int unk24;
    unsigned int unk28;   // animation being loaded
    int unk2C;
    unsigned int unk30;   // current step
    int unk34;
    int unk38;
    int unk3C;
    int unk40; // which side the sim is seen from
    int unk44;
    unsigned int** unk48; // animation id lists: idle, sitting, sit down, stand up,
    unsigned int** unk4C; // and three for reacting to the mirror
    unsigned int** unk50;
    unsigned int** unk54;
    unsigned int** unk58;
    unsigned int** unk5C;
    unsigned int** unk60;
    unsigned int** unk64; // reactions: upper body, shoes, hair, trousers
    unsigned int** unk68;
    unsigned int** unk6C;
    unsigned int** unk70;
    unsigned int*** unk74; // idle animation lists: standing, sitting
    unsigned int*** unk78;
    CASAnimStep** unk7C;  // body-language sequences for the five personality traits
    CASAnimStep** unk80;
    CASAnimStep** unk84;
    CASAnimStep** unk88;
    CASAnimStep** unk8C;
    Unk8033FF34Resource* unk90[11]; // per-slot models (slots 1 to 11)
    Unk8033FF34Resource* unkBC;     // slot 0 model
    Unk8033FF34Resource* unkC0;     // slot 8 model
    struct Unk8017CE68* unkC4; // shadow model
    Unk800226F0* unkC8;
    ETextureLike* unkCC;        // skin texture
    Unk80182DE0Inner* unkD0;    // material used when unkC is set
    void* unkD4;
    void* unkD8;
    struct ELightSet* unkDC;
    Unk80156438 unkE0;
    EVec3 unk154; // position in the line-up
    EVec3 unk160; // scale
    Unk801CC464 unk16C;
    Unk801800FC* unk188;  // "Sim::Table" data set
    Unk801800FC* unk18C;  // animation id lists
    Unk801800FC* unk190;  // data set
    int** unk194;         // nine lists of choices, one per slot kind
    unsigned int unk198;  // animation waiting for its resource to load
};

struct Unk8017CE68 {
    void fn_8017CE68(ERC* rc);
};
struct Unk8037C0E0 {
    char unk0[0xA0];
    EMat4 unkA0;
};
extern Unk8037C0E0* lbl_8037C0E0; // the active view
EMat4& fn_80015070(EMat4& dst, const EMat4& src);
extern "C" int fn_801115C4(); // rand
void fn_80169D7C();
void fn_801B2680();
extern "C" void* fn_80111AE8(void* dst, const void* src, ...); // memcpy (called without a full prototype)
void fn_80156964(const EVec3* position, const EVec3* rotation, const EVec3* scale, EMat4* out);
extern int lbl_8037BFBC;
void fn_800183D0();
class Unk80018374;
void fn_8001D2C0(Unk80018374* sim, int, int, EMat4* bones); // per-frame bone callback

// Placement form whose result the compiler null-checks (it has an empty
// exception specification). The original checks the address of the member it
// constructs; the project's ordinary placement new must not, see CLAUDE.md.
struct ECheckedPlace {};
inline void* operator new(size_t, void* place, ECheckedPlace) throw() { return place; }

// Null test as an inline function (the original materialises the result).
inline bool EIsValid(const void* pointer) { return pointer != 0; }

// Element of a counted array; going through this inline accessor is what puts
// the array pointer first in the indexed load.
inline unsigned int& EAt(unsigned int* array, int index) { return array[index]; }

// Number of entries in one of the engine's counted arrays (the count is kept
// in the word before the data).
inline int ECount(const int* array) {
    int count = 0;
    if (array) {
        count = array[-1];
    }
    return count;
}

struct Unk8037D948 {
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual ERC* vfn13(int);                        // begin drawing
    virtual void vfn14(ERC* rc);                    // end drawing
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn20();
    virtual void vfn21();
    virtual void vfn22();
    virtual int vfn23(int word, int); // a 16-bit word of the unlock flags
    virtual void vfn24();
    virtual void vfn25();
    virtual void vfn26();
    virtual void vfn27();
    virtual void vfn28();
    virtual void vfn29();
    virtual void vfn30();
    virtual void vfn31();
    virtual void vfn32();
    virtual void vfn33();
    virtual void vfn34();
    virtual void vfn35();
    virtual void vfn36();
    virtual void vfn37();
    virtual void vfn38();
    virtual void vfn39();
    virtual void vfn40();
    virtual void vfn41();
    virtual void vfn42();
    virtual void vfn43();
    virtual void vfn44();
    virtual void vfn45();
    virtual void vfn46();
    virtual void vfn47();
    virtual void vfn48();
    virtual void vfn49();
    virtual void vfn50();
    virtual void vfn51();
    virtual void vfn52();
    virtual void vfn53();
    virtual void vfn54();
    virtual void vfn55();
    virtual void vfn56();
    virtual void vfn57();
    virtual void vfn58();
    virtual void vfn59();
    virtual void vfn60();
    virtual void vfn61();
    virtual void vfn62();
    virtual void vfn63();
    virtual void* vfn64();
};
extern Unk8037D948* lbl_8037D948;

// One entry of the "Bustin Out Unlockables" table: a choice of one slot kind
// that starts out locked for one gender and age.
struct CASLockEntry {
    int unk0;
    unsigned char unk4; // adult
    unsigned char unk5; // male
    int unk8;           // slot kind
    short unkC;         // choice
};
struct CASLockTable {
    int unk0;
    int unk4;
    CASLockEntry* unk8;
    CASLockEntry& At(int index) { return unk8[index]; }
};
// Entries of the choice tables: model, alternative model, then one or two textures.
struct CASChoice16 {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkC;
};
struct CASChoice12 {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
};

// One step of the body-shape animation sequence (0x18 bytes).
struct CASAnimStep {
    unsigned int unk0;  // animation to the next step
    unsigned int* unk4;
    unsigned int unk8;  // animation to the previous step
    float unkC;
    float unk10;
    unsigned int unk14; // animation last started from here
};
inline CASAnimStep& EStepAt(CASAnimStep* steps, unsigned int index) { return steps[index]; }

struct Unk80340B80 {
    struct Result {
        char unk0[0x20];
        void* unk20;
    };
    Result* fn_80177628(unsigned int id, int, int);
    void fn_801778B4(unsigned int id);
    char unk0[0x100]; // size unknown
};
extern Unk80340B80 lbl_80340B80;

// Resource manager used for the sim's animations.
struct Unk8033F3D8 {
    void fn_8017717C(unsigned int id, int);
    int fn_80177B24();
    void fn_801776C0(unsigned int id);
    int fn_801770C0(unsigned int id);
    void fn_801778B4(unsigned int id);
    char unk0[0x100]; // size unknown
};
extern Unk8033F3D8 lbl_8033F3D8;

// Lighting for the sim: ambient, then direction and colour of three directional
// lights, then position and colour of three point lights.
extern EVec3 lbl_802E5968; // start-up position
extern EVec3 lbl_802E5974; // start-up scale
extern EVec3 lbl_802E5980;
extern EVec3 lbl_802E598C, lbl_802E5998;
extern EVec3 lbl_802E59A4, lbl_802E59B0;
extern EVec3 lbl_802E59BC, lbl_802E59C8;
extern EVec3 lbl_802E59D4, lbl_802E59E0;
extern EVec3 lbl_802E59EC, lbl_802E59F8;
extern EVec3 lbl_802E5A04, lbl_802E5A10;

// Last choices made for each of the four body types, kept between sessions.
extern int lbl_8037B488; // set once the mirror reaction has played
extern Unk801CC464 lbl_802E5A1C;
extern Unk801CC464 lbl_802E5A38;
extern Unk801CC464 lbl_802E5A54;
extern Unk801CC464 lbl_802E5A70;

#endif
