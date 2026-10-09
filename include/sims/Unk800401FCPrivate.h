#ifndef SIMS_UNK800401FCPRIVATE_H
#define SIMS_UNK800401FCPRIVATE_H

// Declarations shared by the dialog source files (sims/Unk800401FC.cpp and the
// status dialog in sims/Unk80044D84.cpp): what they use of other units.

#include "sims/Unk800401FC.h"
#include "sims/Unk800421C0Sim.h"
#include "sims/EGlobal.h"
#include "engine/ResourceManagers.h"
#include "engine/ERFont.h"
#include "engine/EController.h"
#include "sims/cas/CASWidgets.h"
#include "sims/ESimsCam.h"

// The dialog boxes (unit 0x800401FC): the dialog screen, its texts, and the object
// that queues dialogs. Every function has source.
// 37 of 51 functions match; the rest carry notes. The unit's .rodata is byte-identical
// to the original, which also fixes the order constants are first used in.

// A sprite, as far as this file reads it: its texture and that texture's size.
struct Unk80181824Image {
    char unk0[0x10];
    unsigned short unk10;             // width in pixels
    unsigned short unk12;             // height in pixels
};
struct Unk80181824Texture {
    char unk0[0x20];
    Unk80181824Image* unk20;
};
inline Unk80181824Texture* SpriteTexture(Unk80181824* sprite) {
    return *(Unk80181824Texture**)((char*)sprite + 0x24);
}

// The script viewer (lbl_802E6700.unk90).
struct Unk80108290 {
    void fn_80108290(void* owner);
    int fn_8010826C(void* owner);
    void fn_801082BC(int);
    int fn_801082CC();
};
extern "C" void fn_80106164(void* viewer, const char* command, ...);
extern "C" int fn_80111ECC(const char* a, const char* b);              // strcmp
extern "C" int fn_8010F7F0(const char* text, const char* format, ...); // sscanf
extern "C" int fn_8010F710(char* out, const char* format, ...);        // sprintf
extern "C" int fn_80110874(const char* text);                          // atoi
int fn_801BA640(const unsigned short* text);                           // length
void fn_800B772C();

// A table of localized strings (vtable pointer at 0): slot 6 looks one up.
struct Unk80043034Table {
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual Unk800669ACResult vfn6(int key, ...);
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19(int id, int, int);            // selects the string set
};
Unk80043034Table* fn_8023CDDC();
void fn_8023CE04(Unk80043034Table* table);
// Holds a string table for as long as it is in scope.
struct Unk8023CDDC {
    Unk8023CDDC() : table(0) {}
    Unk8023CDDC(const Unk8023CDDC& other);   // declared: gives locals their 8-byte-aligned slot
    ~Unk8023CDDC() {
        fn_8023CE04(table);
        table = 0;
    }
    Unk80043034Table* table;
};
// What a dialog is made from (first argument of slot 22).
struct Unk800424F0Source {
    char unk0[4];
    unsigned short unk4;
    char unk6[0xC - 6];
    void* unkC;
};
int fn_801C27C8(void* a);
int fn_802186F4(int id);
BString2* fn_80218174(int id);
Unk800669ACResult fn_80218044(int id, ...);
int fn_80217F2C(int id);
int fn_800D1E94(const unsigned short* text, const unsigned short* tag, const unsigned short* a, BString2* out);
void fn_800D2EFC(const unsigned short* text, BString2* out);
int fn_80106774(void* viewer, int, int, int, int);   // next UI event
// The text-entry screen (declared as in sims/cas/CASTarget.h).
class Unk800C6704 : public UnkTargetBase {
public:
    Unk800C6704(int, int, int, int, int, int, int, float, float, float, int, int, int, int, int, int, int, int,
                int, int, int, int, int, int, int, int);
    int fn_800CAEF0();                  // 0 while open, 1 accepted, 2 cancelled
    Unk801BA678* fn_800C6FAC();         // the entered text
    void fn_800C6F08(int text, int);
    char unk48[0x178 - 0x48];
};
extern unsigned short lbl_802E5F9C[0x80];   // one line of body text being measured
extern float lbl_8037B550;
extern const float lbl_8037ED4C;
extern const float lbl_8037ED50;
extern const float lbl_8037ED54;
extern EVec2 lbl_8037CB38;
extern EVec2 lbl_8037CB40;
void fn_80061A50();
void fn_80061A7C();
void fn_80061AA8();
// What a sim's slot 167 returns: flags per choice.
struct Unk80042228Record {
    char unk0[0x16];
    short unk16[1];
};
extern BString2 lbl_8037D3B4;
extern float lbl_8037B500;
extern float lbl_8037B504;
extern float lbl_8037B50C;
extern EColorF lbl_802E6974;           // shadow colour
extern EColorF lbl_802E6A34;           // text colour while its button is held

// The display is lbl_8037C198 (sims/ESimsCam.h): slot 8 is told when a dialog's
// texts go away; its size in pixels is at 0x14 and 0x18.

// Callbacks another unit installs while a dialog is up.
extern void (*lbl_8037C0CC)();
extern void (*lbl_8037C0D0)();
extern void (*lbl_8037C0D4)();   // called when the body scrolls
void fn_80061AD4();
void fn_80061B00();
void fn_80061B2C();

// The dialog class of another unit (0xE28 bytes, constructor 0x800CBF40).
class Unk800CBF40 : public Unk80040274 {
public:
    Unk800CBF40();
    char unkF4[0xE28 - 0xF4];
};


// Defined in sims/Unk800401FC.cpp.
extern Unk80181824* lbl_8037B520;
extern Unk80181824* lbl_8037B524;
extern Unk80181824* lbl_8037B528;
extern Unk80181824* lbl_8037B52C;
extern EVec2 lbl_8037CAC0;
extern EVec2 lbl_8037CAD8;
void fn_80043034(Unk80043034Table* table, BString2* out, int key, const unsigned short* fallback, int);
void fn_800411A0(ERC* rc, float left, float top, float right, float bottom, float alpha);

#endif
