#ifndef SIMS_UNK800401FC_H
#define SIMS_UNK800401FC_H

#include "engine/UnkTargetBase.h"
#include "engine/E3DWindow.h"
#include "sims/Unk8003B870.h"
#include "sims/Unk80026864List.h"

// The dialog boxes (unit 0x800401FC): the dialog screen itself, the texts it shows
// and the object that queues dialogs and shows one at a time. The names are unknown;
// The Sims 2 has a reworked dialog system (DlgWrapper, MDITarget, UIDialog) whose
// functions do not line up with these.

extern "C" void* fn_80111C78(void* dst, int value, unsigned int size); // memset

struct ERC;
class ERFont;
struct Unk80181824;
class Unk80043820;

// The texts of a dialog (0x54 bytes).
struct Unk800401FC {
    Unk800401FC();
    ~Unk800401FC() { Clear(); }
    void Clear();                     // 0x80044CBC

    Unk80026864List unk0;             // the body, one string per line
    const unsigned short* unkC;       // shown when a text is missing
    Unk8003B870String unk10;          // title
    Unk8003B870String unk14;          // button texts
    Unk8003B870String unk18;
    Unk8003B870String unk1C;
    int unk20;                        // number of lines
    float unk24;                      // where the body starts, y
    float unk28;                      // gap between lines
    int unk2C;
    int unk30;
    EVec2 unk34;                      // sizes of the button texts
    EVec2 unk3C;
    EVec2 unk44;
    EVec2 unk4C;                      // size of the title
};

// How a dialog fades and grows (0x44 bytes).
struct Unk8004024CRange {
    Unk8004024CRange(float lo, float hi) : unk0(lo), unk4(hi) { unk8 = unk0; }
    void Add(float amount) {
        unk8 += amount;
        float value;
        if (unk8 < unk0) {
            value = unk0;
        } else if (unk8 > unk4) {
            value = unk4;
        } else {
            value = unk8;
        }
        unk8 = value;
    }
    void Set(float lo, float hi, float current) {
        unk8 = current;
        unk0 = lo;
        unk4 = hi;
        float value;
        if (unk8 < unk0) {
            value = unk0;
        } else if (unk8 > unk4) {
            value = unk4;
        } else {
            value = unk8;
        }
        unk8 = value;
    }
    float unk0;
    float unk4;
    float unk8;                       // current, kept between the two
};
struct Unk8004024C {
    Unk8004024C() : unk20(0.0f, 0.0f, 0.0f, 0.0f), unk30(0.0f, 0.0f), unk3C(0.0f), unk40(0.0f) {
        unk10 = unk20;
        unk0 = unk10;
    }
    void* operator new(unsigned int size) { return fn_80169F1C(size, 16); }
    void operator delete(void* ptr) { fn_80169EE8(ptr); }
    bool IsStill() const {
        return unk20.unk0 == unk10.unk0 && unk20.unk4 == unk10.unk4 && unk20.unk8 == unk10.unk8 &&
               unk20.unkC == unk10.unkC;
    }
    bool TimedOut() const { return unk40 >= unk3C; }
    ERectF unk0;
    ERectF unk10;                     // where it is going
    ERectF unk20;                     // where it is
    Unk8004024CRange unk30;           // how far it has faded in
    float unk3C;                      // how long it waits before answering itself
    float unk40;                      // how long it has been still
};

// A dialog box (0xF4 bytes).
class Unk80040274 : public UnkTargetBase {
public:
    Unk80040274();
    virtual ~Unk80040274();
    virtual void vfn2();
    virtual void vfn3(ERC* rc);
    virtual void vfn8(const char* name, const char* value);
    virtual char* vfn9(const char* name);
    virtual void vfn18() { delete this; }                       // 0x80044C64
    virtual void vfn19(Unk8003B870String* text);                 // 0x80042170
    virtual void vfn20(struct Unk800421C0Sim* sim);              // 0x800421C0
    virtual void vfn21(int id);                                  // 0x80042218
    virtual int vfn22(struct Unk800424F0Source* source, unsigned char* b, void* c);   // 0x800424F0
    virtual int vfn23(Unk8003B870String* body, const char* title);   // 0x80042360
    virtual int vfn24(void* a, void* b, void* c, void* d);       // 0x80042358
    virtual void vfn25();                                        // 0x800405F4

    void fn_80040DE0();
    void fn_800411A8(ERC* rc, int flag);
    void fn_800417F0(ERC* rc);
    void fn_80041CB0(ERC* rc);
    void fn_80041F74(ERC* rc);
    long long fn_80042228();
    void fn_80043110(Unk8003B870String* body, int flag);
    void fn_800435C4(int flag);
    ERectF fn_80044174();
    float fn_800441C0();
    void fn_800448F4();
    void fn_80044974(ERC* rc);

    void* operator new(unsigned int size) {
        void* block = fn_80169F1C(size, 16);
        fn_80111C78(block, 0, size);
        return block;
    }
    void operator delete(void* ptr) { fn_80169EE8(ptr); }

    int unk48;                        // 1 while the script wants it drawn
    Unk8004024C* unk4C;
    Unk800401FC* unk50;
    Unk80043820* unk54;               // who to tell the answer
    UnkTargetBase* unk58;             // a screen shown in its place (type 3)
    Unk801BA678 unk5C;                // text typed in
    unsigned char* unk60;
    E3DWindow* unk64;
    Unk800421C0Sim* unk68;
    int unk6C;
    int unk70;                        // which players may answer
    int unk74;
    int unk78;
    int unk7C;                        // kind: 0 one button, 1 two, 2 three, 3 a screen
    int unk80;                        // 1 waiting, 2 to 4 the button pressed
    short unk84;
    int unk88;                        // first line shown
    int unk8C;
    int unk90;                        // icon
    int unk94;                        // non-zero when it has an icon
    int unk98;
    int unk9C;                        // scroll up / down requests
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;                        // 1 once the script has been told
    float unkB4;                      // how long up / down have been held
    float unkB8;
    float unkBC;                      // when they repeat next
    float unkC0;
    int unkC4;
    float unkC8[3];                   // button positions, y
    float unkD4[3];                   // button positions, x
    float unkE0;
    EVec2 unkE4;                      // title position
    int unkEC;
    int unkF0;
};

// Queues dialogs and shows one at a time (0x1C bytes, vtable pointer at 0x18).
class Unk80043820 {
public:
    Unk80043820();
    static void fn_80043A40();
    void fn_80043BF0();
    void fn_80043C84(ERC* rc);
    void fn_8004406C();
    Unk80040274* fn_80044128();
    static void fn_800438B8();

    long long unk0;                   // the last answer
    Unk80026864List unk8;             // dialogs waiting
    Unk80040274* unk14;               // the one showing

    virtual ~Unk80043820();
    virtual int vfn2(void* a, unsigned char* b, Unk800421C0Sim* sim, int id, void* c);
    virtual int vfn3(void* a, void* b, Unk800421C0Sim* sim);
    virtual int vfn4(void* a, void* b, void* c, void* d);
    virtual void vfn5();
    virtual int vfn6() {                                         // 0x80044CA4
        if (unk14 != 0) {
            return 1;
        }
        return 0;
    }
    virtual long long vfn7();
    virtual void vfn8();
};

#endif
