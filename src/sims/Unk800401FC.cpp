#include "engine/e_storable.h"
#include "engine/e_resource.h"
#include "engine/e_rfont.h"
#include "engine/e_texture.h"
#include "engine/e_shader.h"
#include "engine/e_rshader.h"
#define EOR_BUILD_TIME "21:41:33"
#include "engine/e_engine.h"
#include "engine/e_rcharacter.h"
#include "engine/e_submodelshader.h"
#include "engine/e_submodel.h"
#include "engine/e_rmodel.h"
#include "engine/e_ranim.h"
#include "sims/Unk80297B74.h"
#include "engine/e_instance.h"
#include "sims/Unk800401FC.h"
#include "sims/Unk800421C0Sim.h"
#include "sims/EGlobal.h"
#include "engine/ResourceManagers.h"
#include "engine/ERFont.h"
#include "engine/EController.h"
#include "sims/cas/CASWidgets.h"
#include "sims/ESimsCam.h"

// The dialog boxes (unit 0x800401FC): the dialog screen, its texts, and the object
// that queues dialogs. Every function has source except a two-instruction accessor
// at 0x80044C5C (an inline `Get()` the original emits out of line; ours is inlined).
// 33 of 51 functions match; the rest carry notes. The unit's .rodata is byte-identical
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
Unk8003B870String* fn_80218174(int id);
Unk800669ACResult fn_80218044(int id, ...);
int fn_80217F2C(int id);
int fn_800D1E94(const unsigned short* text, const unsigned short* tag, const unsigned short* a, Unk8003B870String* out);
void fn_800D2EFC(const unsigned short* text, Unk8003B870String* out);
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
extern Unk8003B870String lbl_8037D3B4;
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

// Shown when a text is missing (16-bit characters).
static const unsigned short lbl_8029918C[] = {'M', 'i', 's', 's', 'i', 'n', 'g', ' ', 'S', 't',
                                              'r', 'i', 'n', 'g', '!', '!', '!', 0};

// The sprites of the dialog frame and its icons, shared by all dialogs.
Unk80181824* lbl_8037B520 = 0;
Unk80181824* lbl_8037B524 = 0;
Unk80181824* lbl_8037B528 = 0;
Unk80181824* lbl_8037B52C = 0;
Unk80181824* lbl_8037B530 = 0;
Unk80181824* lbl_8037B534 = 0;
Unk80181824* lbl_8037B538 = 0;
Unk80181824* lbl_8037B53C = 0;
Unk80181824* lbl_8037B540 = 0;
Unk80181824* lbl_8037B544 = 0;
Unk80181824* lbl_8037B548 = 0;
Unk80181824* lbl_8037B54C = 0;

// Layout positions, as fractions of the screen.
EVec2 lbl_8037CAB8(0.184375f, 0.175f);
EVec2 lbl_8037CAC0(0.2f, 0.28f);
EVec2 lbl_8037CAC8(0.6390625f, 0.545f);
EVec2 lbl_8037CAD0(0.5428125f, 0.26624998f);
EVec2 lbl_8037CAD8(0.603125f, 0.2958333f);
EVec2 lbl_8037CAE0(0.603125f, 0.05f);
EVec2 lbl_8037CAE8(0.603125f, 0.05f);
int lbl_8037CAF0;                     // the kind of the dialog being made

// 0x800401FC
Unk800401FC::Unk800401FC() {
    unkC = lbl_8029918C;
    unk20 = 0;
    unk2C = 0;
    unk30 = 0;
}

inline ERectF MakeRect(const EVec2& position, const EVec2& size) {
    EVec2 from(position);
    EVec2 to(from + size);
    return ERectF(from.x, from.y, to.x, to.y);
}

// 0x80040274
// NON_MATCHING: 115 instructions against 117. Same calls and stores; the inline
// constructor of the fade state initialises its members in another order (the range
// at 0x30 comes first in the original) and the window rectangle is built from a copy
// of the position kept in two registers.
Unk80040274::Unk80040274() {
    unk54 = 0;
    unk68 = 0;
    unk6C = 0;
    unk84 = 0;
    unk80 = 0;
    unk7C = 0;
    unk60 = 0;
    unk64 = new E3DWindow;
    unk4C = new Unk8004024C;
    unk50 = new Unk800401FC;
    unk70 = 2;
    unk64->fn_8018B584(MakeRect(lbl_8037CAC0, lbl_8037CAD8));
    unkB0 = 0;
    unkC0 = 0.5f;
    unkC4 = 1;
    unk58 = 0;
    unk88 = 0;
    unk8C = 0;
    unk9C = 0;
    unkA0 = 0;
    unkB4 = 0.0f;
    unkB8 = 0.0f;
    unkA4 = 0;
    unkA8 = 0;
    unkBC = 0.5f;
    for (int i = 0; i < 3; i++) {
        unkD4[i] = 0.0f;
        unkC8[i] = 0.0f;
    }
    unkEC = 0;
    unk48 = 0;
}

// 0x80040448
Unk80040274::~Unk80040274() {
    if ((unsigned int)(unk7C - 7) > 1 && unkB0 != 0) {
        fn_80106164(lbl_802E6700.unk90, "hideDialog", 0, 0, 0);
    }
    ((Unk80108290*)lbl_802E6700.unk90)->fn_80108290(this);
    fn_80040DE0();
    if (unk58) {
        delete unk58;
        unk58 = 0;
    }
    if (unk50) {
        delete unk50;
    }
    unk50 = 0;
    if (unk4C) {
        delete unk4C;
    }
    unk4C = 0;
    if (unk64) {
        delete unk64;
    }
    unk64 = 0;
    lbl_8037C0D0 = fn_80061B00;
    lbl_8037C0CC = fn_80061AD4;
    lbl_8037C0D4 = fn_80061B2C;
}

// 0x80044CBC (emitted at the end: it is defined after the destructor that calls it)
inline bool IsNode(Unk80026864Node* node) {
    return node != 0 ? true : false;
}
// NON_MATCHING (this copy, the one inlined in fn_80040DE0, and DeleteDialogs in
// fn_8004406C): the original keeps the node in r9 and frees r3 for the item; this
// keeps the node in r3. Same instructions otherwise. An iterator object (tried) puts
// the node in memory instead.
inline void Unk800401FC::Clear() {
    unk20 = 0;
    lbl_8037C198->vfn8();
    Unk80026864Node* next;
    for (Unk80026864Node* node = unk0.tail; IsNode(node); node = next) {
        Unk8003B870String* text = (Unk8003B870String*)node->item;
        next = node->prev;
        if (unk0.owns && text) {
            delete text;
        }
    }
    unk0.fn_801B4760();
}

// 0x800405F4
void Unk80040274::vfn25() {
    if (lbl_802E6700.unkBC) {
        ((UnkTargetBase*)lbl_802E6700.unkBC)->vfn7(0, 0x1E);
    }
}

// The controllers that may answer: the first player's and, with two players, the second's.
inline EController* FirstPad() {
    return lbl_8037C11C->fn_8015E5FC(lbl_8037C11C->fn_8015E614(0));
}
inline EController* SecondPad() {
    EController* pad = 0;
    if (lbl_802E6700.fn_800655C4() && lbl_8037C11C->fn_8015E564(1)) {
        pad = lbl_8037C11C->fn_8015E5FC(lbl_8037C11C->fn_8015E614(1));
    }
    return pad;
}

// Whether a button is held by whoever may answer: 0 the first player, 1 the second,
// otherwise either.
inline int HeldBy(int who, EController* first, EController* second, int button) {
    int held = 0;
    if (who != 0 && second != 0) {
        if (who == 1) {
            held = second->fn_8015DF98(button);
        } else if (first->fn_8015DF98(button) || second->fn_8015DF98(button)) {
            held = 1;
        }
    } else {
        held = first->fn_8015DF98(button);
    }
    return held;
}

// 0x80040640
// Per frame: fades the dialog in, reads the buttons and scrolls the body.
// NON_MATCHING: 462 instructions against 488. The original keeps a separate copy of
// the sound-and-answer code for each button test; here some of them merge.
void Unk80040274::vfn2() {
    if (((Unk80108290*)lbl_802E6700.unk90)->fn_801082CC() == 0) {
        return;
    }
    EController* first = FirstPad();
    EController* second = SecondPad();
    Unk8004024C* fade = unk4C;
    float still;
    if (fade->IsStill()) {
        still = fade->unk40 + lbl_8037BFC8;
    } else {
        still = 0.0f;
    }
    fade->unk40 = still;
    if (fade->unk40 < fade->unk3C) {
        fade->unk30.Add(lbl_8037BFC8);
    }
    if (unk7C == 3) {
        if (unk58) {
            fn_80106774(lbl_802E6700.unk90, 0, 0, 0, 1);
            unk58->vfn2();
            switch (((Unk800C6704*)unk58)->fn_800CAEF0()) {
            case 1: {
                Unk801BA678 text(((Unk800C6704*)unk58)->fn_800C6FAC()->Get());
                unk5C.fn_801BA860(text.Get());
                if (unk58) {
                    delete unk58;
                }
                unk58 = 0;
                unk80 = 2;
                unk54->unk0 = fn_80042228();
                break;
            }
            case 2:
                ((Unk800C6704*)unk58)->fn_800C6F08(GetText("default_text_baby"), 9);
                break;
            }
        }
        if (unk7C == 3) {
            goto scroll;
        }
    }
    if (unk80 != 1) {
        unk80 = 1;
    } else {
        if (first->fn_8015E204(5) || (second && second->fn_8015E204(5))) {
            lbl_8037D96C->fn_8006186C(0xCF99DB1E);
            unk80 = 2;
            goto answer;
        }
        if (unk80 == 2) {
            return;
        }
        if ((unsigned int)(unk7C - 1) <= 1) {
            if (first->fn_8015E204(5) || (second && second->fn_8015E204(5))) {
                lbl_8037D96C->fn_8006186C(0xCF99DB1E);
                unk80 = 2;
                goto answer;
            }
            if (first->fn_8015E204(7) || (second && second->fn_8015E204(7))) {
                lbl_8037D96C->fn_8006186C(0x867A1F00);
                unk80 = 4;
                goto answer;
            }
            if (unk7C == 2) {
                if (first->fn_8015E024(0x10) || (second && second->fn_8015E024(0x10))) {
                    lbl_8037D96C->fn_8006186C(0x048AE94F);
                    unk80 = 3;
                    goto answer;
                }
            }
        }
    }
    if (unk58 == 0 && unk4C->TimedOut()) {
        if (unk7C == 1) {
            lbl_8037D96C->fn_8006186C(0x048AE94F);
            unk80 = 3;
        } else if (unk7C == 2) {
            lbl_8037D96C->fn_8006186C(0x048AE94F);
            unk80 = 4;
        } else {
            lbl_8037D96C->fn_8006186C(0xCF99DB1E);
            unk80 = 2;
        }
    answer:
        unk54->unk0 = fn_80042228();
        return;
    }
scroll:
    if (unk98 != 0) {
        return;
    }
    if (unk7C == 3) {
        return;
    }
    int up = HeldBy(unk70, first, second, 0x33);
    float held;
    if (up) {
        if (unkB4 == 0.0f) {
            unk9C = 1;
            unkBC = 0.5f;
            unkA4 = 0;
        }
        held = unkB4 + lbl_8037BFC8;
    } else {
        held = 0.0f;
    }
    unkB4 = held;
    int down = HeldBy(unk70, first, second, 0x34);
    if (down) {
        if (unkB8 == 0.0f) {
            unkA0 = 1;
            unkC0 = 0.5f;
            unkA8 = 0;
        }
        held = unkB8 + lbl_8037BFC8;
    } else {
        held = 0.0f;
    }
    unkB8 = held;
    if (unkB4 > unkBC) {
        int flip = unkA4 ^ 1;
        unk9C = flip;
        unkBC = unkBC + 0.025f;
        unkA4 = flip;
    }
    if (unkB8 > unkC0) {
        int flip = unkA8 ^ 1;
        unkA0 = flip;
        unkC0 = unkC0 + 0.025f;
        unkA8 = flip;
    }
    if (unkA0) {
        unkA0 = 0;
        if (unk88 < unk50->unk20 - 5) {
            if (lbl_8037C0D4) {
                lbl_8037C0D4();
            }
            unkF0 = 1;
            unk88++;
        } else if (unkF0) {
            lbl_8037D96C->fn_8006186C(0x3804219F);
            unkF0 = 0;
        }
    }
    if (unk9C) {
        unk9C = 0;
        if (unk88 > 0) {
            if (lbl_8037C0D4) {
                lbl_8037C0D4();
            }
            unkF0 = 1;
            unk88--;
        } else if (unkF0) {
            lbl_8037D96C->fn_8006186C(0x3804219F);
            unkF0 = 0;
        }
    }
}

// 0x80040DE0
// NON_MATCHING: the inlined Clear() (see there): node in r3 instead of r9.
void Unk80040274::fn_80040DE0() {
    unk50->Clear();
    if (lbl_802E6700.unkBC) {
        ((UnkTargetBase*)lbl_802E6700.unkBC)->vfn7(0, 0x1F);
    }
}

// 0x80040EAC
// Draws the dialog: its title, body, icon and buttons.
// NON_MATCHING: 182 instructions against 181; same calls in the same order, the
// unused title size and position are computed in a different order.
void Unk80040274::vfn3(ERC* rc) {
    if (unk7C == 3) {
        if (unk58) {
            unk58->vfn3(rc);
        }
        return;
    }
    lbl_802E6700.unkE4->fn_80181824(rc);
    float half = 0.5f;
    float middle = unk64->Left() + (unk64->Right() - unk64->Left()) * half;
    EVec2 size = lbl_802E6700.unkEC->DoGetStringSize(unk50->unk10.fn_801C5B24(), true, 0);
    size.x += 0.1f;
    lbl_802E6700.unkEC->SetSize(true, lbl_8037B504, 1.0f);
    lbl_802E6700.unkEC->unk64 = lbl_802E6964;
    lbl_802E6700.unkEC->Select(rc);
    lbl_802E6700.unkE4->fn_80181824(rc);
    EVec2 position(lbl_8037CAC0.x, lbl_8037CAC0.y + lbl_8037CAD8.y + lbl_8037B50C);
    float width = lbl_8037CAE8.x;
    switch (unk7C) {
    case 0:
    case 10:
        position.x = middle - width * 0.3f * half;
        break;
    case 1:
        position.x = middle - width * 0.6f * half;
        break;
    case 2:
        break;
    }
    if (unk48 == 1) {
        lbl_802E6700.unkEC->SetSize(true, 18.0f, 1.0f);
        lbl_802E6700.unkEC->unk64 = lbl_802E6964;
        lbl_802E6700.unkEC->DrawDs(rc, unk50->unk10.fn_801C5B24(), &unkE4, 2, 2, 0, 2.0f, 1.0f);
        fn_800411A8(rc, 1);
        if (unk94) {
            fn_80044974(rc);
        }
        switch (unk7C) {
        case 2:
            fn_800417F0(rc);
            break;
        case 1:
            fn_80041CB0(rc);
            break;
        case 0:
        case 3:
        case 4:
        case 10:
            fn_80041F74(rc);
            break;
        }
    }
}

// 0x80041180
void fn_80041180() {
    fn_800B772C();
}

// 0x800411A0
void fn_800411A0() {
}

// 0x800411A4
void fn_800411A4() {
}

// The ERTexture header strings sit here in the original's .rodata, between the
// constants of the function above and the one below, not with the other header
// strings at the top. Why is not known (an include this late is unusual); this
// reproduces the bytes.
#include "engine/e_rtexture.h"

// 0x800411A8
// Draws the body text and, when it scrolls, the arrows above and below it.
// NON_MATCHING: 401 instructions against 402; the arrow positions are computed in a
// different register order. Constants are in the original's order.
void Unk80040274::fn_800411A8(ERC* rc, int flag) {
    if (((Unk80108290*)lbl_802E6700.unk90)->fn_801082CC() == 0) {
        return;
    }
    lbl_802E6700.unkEC->SetSize(true, lbl_8037B504, 1.0f);
    lbl_802E6700.unkEC->Select(rc);
    EController* first = FirstPad();
    EController* second = SecondPad();
    float spacing = lbl_8037B550 * lbl_802E6700.unkEC->GetLineSpacing(0);
    bool plain = false;
    if (flag == 0 || unk98 != 0) {
        plain = true;
    }
    E3DWindow* window = unk64;
    if (!plain) {
        if (unk88 > 0) {
            Unk80181824Image* image = SpriteTexture(lbl_8037B520)->unk20;
            float width = (float)image->unk10 / (float)lbl_8037C198->unk14;
            float x = window->Left() + (window->Right() - window->Left() - width) * 0.5f;
            float height = (float)image->unk12 / (float)lbl_8037C198->unk18 - 0.012f;
            float gap = 3.0f / (float)lbl_8037C198->unk18;
            float y = window->Top() - height - gap;
            if (first->fn_8015DF98(0x33) || (second && second->fn_8015DF98(0x33))) {
                lbl_8037B528->fn_80181824(rc);
                rc->vfn49(EVec2(x, y - 0.015f), EVec2(1.0f), EColorF(1.0f), 0.0f);
            } else {
                lbl_8037B520->fn_80181824(rc);
                rc->vfn49(EVec2(x, y - 0.015f), EVec2(1.0f), EColorF(1.0f), 0.0f);
            }
        }
        if (unk88 < unk50->unk20 - 5) {
            Unk80181824Image* image = SpriteTexture(lbl_8037B520)->unk20;
            float width = (float)image->unk10 / (float)lbl_8037C198->unk14;
            float gap = 3.0f / (float)lbl_8037C198->unk18;
            float y = window->Bottom() + gap;
            float x = window->Left() + (window->Right() - window->Left() - width) * 0.5f;
            if (first->fn_8015DF98(0x34) || (second && second->fn_8015DF98(0x34))) {
                lbl_8037B52C->fn_80181824(rc);
                rc->vfn49(EVec2(x, y), EVec2(1.0f), EColorF(1.0f), 0.0f);
            } else {
                lbl_8037B524->fn_80181824(rc);
                rc->vfn49(EVec2(x, y), EVec2(1.0f), EColorF(1.0f), 0.0f);
            }
        }
    }
    unk64->fn_8018B044(rc);
    lbl_802E6700.unkEC->Select(rc);
    EVec2 extent(0.0f);
    float middle = unk64->Left() + (unk64->Right() - unk64->Left()) * 0.5f;
    float y = unk50->unk24;
    for (Unk80026864Node* node = unk50->unk0.head; node != 0; node = node->next) {
        Unk8003B870String* line = (Unk8003B870String*)node->item;
        if (plain || unk8C >= unk88) {
            lbl_802E6700.unkEC->unk64 = lbl_802E6964;
            lbl_802E6700.unkEC->DrawDs(rc, line->fn_801C5B24(), &EVec2(middle, y), 2, 0, &extent, 2.0f, 1.0f);
            y = extent.y + spacing;
        } else {
            unk8C++;
        }
    }
    unk8C = 0;
    lbl_802E6700.fn_80066614(rc);
}

// 0x800417F0
// Draws the buttons of a three-button dialog; the first has a shadow.
// NON_MATCHING: 305 instructions against 304; the shadow's position temporaries are
// laid out differently (not yet worked through).
void Unk80040274::fn_800417F0(ERC* rc) {
    if (((Unk80108290*)lbl_802E6700.unk90)->fn_801082CC() == 0) {
        return;
    }
    if (unkD4[0] == 0.0f || unkC8[0] == 0.0f || unkD4[1] == 0.0f || unkC8[1] == 0.0f || unkD4[2] == 0.0f ||
        unkC8[2] == 0.0f) {
        return;
    }
    EController* first = FirstPad();
    EController* second = SecondPad();
    ERFont* font = lbl_802E6700.unkEC;
    float size = 13.0f;
    float x = unkD4[0];
    float y = unkC8[0];
    font->Select(rc);
    font->SetSize(true, size, 1.0f);
    font->unk64 = lbl_802E6974;
    {
        const void* text = unk50->unk1C.fn_801C5B24();
        EVec2 position(x, y);
        EVec2 offset(0.0025f);
        EVec2 shadow(position + offset);
        font->DoDrawAlign(rc, text, true, shadow, 2, 2, 0);
    }
    if (first->fn_8015E204(5) || (second && second->fn_8015E204(5))) {
        font->unk64 = lbl_802E6A34;
        EVec2 at(x, y);
        font->DoDrawAlign(rc, unk50->unk1C.fn_801C5B24(), true, at, 2, 2, 0);
    } else {
        font->unk64 = lbl_802E6964;
        EVec2 at(x, y);
        font->DoDrawAlign(rc, unk50->unk1C.fn_801C5B24(), true, at, 2, 2, 0);
    }
    x = unkD4[1];
    y = unkC8[1];
    font->Select(rc);
    font->SetSize(true, size, 1.0f);
    if (first->fn_8015E024(0x10) || (second && second->fn_8015E024(0x10))) {
        font->unk64 = lbl_802E6A34;
    } else {
        font->unk64 = lbl_802E6964;
    }
    font->DrawDs(rc, unk50->unk18.fn_801C5B24(), &EVec2(x, y), 2, 2, 0, 2.0f, 1.0f);
    x = unkD4[2];
    y = unkC8[2];
    font->Select(rc);
    font->SetSize(true, size, 1.0f);
    if (first->fn_8015E204(7) || (second && second->fn_8015E204(7))) {
        font->unk64 = lbl_802E6A34;
    } else {
        font->unk64 = lbl_802E6964;
    }
    font->DrawDs(rc, unk50->unk14.fn_801C5B24(), &EVec2(x, y), 2, 2, 0, 2.0f, 1.0f);
}

// 0x80041CB0
// Draws the buttons of a two-button dialog.
// NON_MATCHING: 2 of 177 instructions. In the first SetSize call the original loads
// the size (fmr f1) before `li r4, 1`; here they are the other way round. The second
// call, written the same way, matches.
void Unk80040274::fn_80041CB0(ERC* rc) {
    if (((Unk80108290*)lbl_802E6700.unk90)->fn_801082CC() == 0) {
        return;
    }
    if (unkD4[0] == 0.0f || unkC8[0] == 0.0f || unkD4[2] == 0.0f || unkC8[2] == 0.0f) {
        return;
    }
    EController* first = FirstPad();
    EController* second = SecondPad();
    ERFont* font = lbl_802E6700.unkEC;
    float size = 15.0f;
    float x = unkD4[0];
    float y = unkC8[0];
    font->Select(rc);
    font->SetSize(true, size, 1.0f);
    if (first->fn_8015E204(5) || (second && second->fn_8015E204(5))) {
        font->unk64 = lbl_802E6A34;
    } else {
        font->unk64 = lbl_802E6964;
    }
    font->DrawDs(rc, unk50->unk1C.fn_801C5B24(), &EVec2(x, y), 2, 2, 0, 2.0f, 1.0f);
    x = unkD4[2];
    y = unkC8[2];
    font->SetSize(true, size, 1.0f);
    if (first->fn_8015E204(7) || (second && second->fn_8015E204(7))) {
        font->unk64 = lbl_802E6A34;
    } else {
        font->unk64 = lbl_802E6964;
    }
    font->DrawDs(rc, unk50->unk18.fn_801C5B24(), &EVec2(x, y), 2, 2, 0, 2.0f, 1.0f);
}

// 0x80041F74
// Draws the button of a one-button dialog.
void Unk80040274::fn_80041F74(ERC* rc) {
    if (((Unk80108290*)lbl_802E6700.unk90)->fn_801082CC() == 0) {
        return;
    }
    if (unkD4[0] == 0.0f || unkC8[0] == 0.0f) {
        return;
    }
    EController* first = FirstPad();
    EController* second = SecondPad();
    ERFont* font = lbl_802E6700.unkEC;
    float small = 12.0f;
    float large = 15.0f;
    font->Select(rc);
    if (unkC4 == 1) {
        font->SetSize(true, large, 1.0f);
    } else {
        font->SetSize(true, small, 1.0f);
    }
    float x = unkD4[0];
    float y = unkC8[0];
    if (first->fn_8015E204(5) || (second && second->fn_8015E204(5))) {
        font->unk64 = lbl_802E6A34;
    } else {
        font->unk64 = lbl_802E6964;
    }
    font->DrawDs(rc, unk50->unk1C.fn_801C5B24(), &EVec2(x, y), 2, 2, 0, 2.0f, 1.0f);
}

// 0x80042170
void Unk80040274::vfn19(Unk8003B870String* text) {
    Unk8003B870String typed(unk5C.Get());
    *text = typed;
}

// 0x800421C0
void Unk80040274::vfn20(Unk800421C0Sim* sim) {
    unk68 = sim;
    if (sim) {
        unk6C = sim->vfn119();
    } else {
        unk6C = 0;
    }
}

// 0x80042218
void Unk80040274::vfn21(int id) {
    unk6C = id;
    unk68 = 0;
}

// 0x80042228
// Acts on the answer; returns 1 when the dialog is finished with.
long long Unk80040274::fn_80042228() {
    switch (unk80) {
    case 0:
    case 1:
        return 0;
    case 2:
        if (unk7C == 3) {
            vfn19(&lbl_8037D3B4);
        }
        break;
    case 3:
        if (unk7C == 2) {
            int choice = unk78;
            Unk80042228Record* record = unk68 ? (Unk80042228Record*)unk68->vfn167() : 0;
            record->unk16[choice] = 0;
        }
        return 0;
    case 4:
        if (unk7C == 2) {
            int choice = unk78;
            Unk80042228Record* record = unk68 ? (Unk80042228Record*)unk68->vfn167() : 0;
            record->unk16[choice] = 1;
        }
        return 0;
    }
    return 1;
}

// 0x80042358
int Unk80040274::vfn24(void* a, void* b, void* c, void* d) {
    return 1;
}

// 0x80042360
// Sets up a dialog with a title and one button.
// NON_MATCHING: 101 instructions against 100. The frame is 8 bytes larger and the
// address of the size temporary is kept in a saved register; the original passes
// sp+0x10 directly and copies x before y.
int Unk80040274::vfn23(Unk8003B870String* body, const char* title) {
    Unk8003B870String text((const unsigned short*)GetTextB(title));
    unk70 = 2;
    unk7C = 0;
    unk78 = 0;
    unk84 = unk68 ? unk68->vfn111() : 0;
    unk50->unk10 = text;
    lbl_802E6700.unkEC->SetSize(true, lbl_8037B504, 1.0f);
    unk50->unk1C = (const unsigned short*)GetTextB("ok");
    Unk800401FC* texts = unk50;
    EVec2 size = lbl_802E6700.unkEC->DoGetStringSize(texts->unk1C.fn_801C5B24(), true, 0);
    texts->unk34 = size;
    unk50->unk18.fn_801C5704(0, -1);
    unk50->unk14.fn_801C5704(0, -1);
    fn_80043110(body, 0);
    return 1;
}

void fn_80043034(Unk80043034Table* table, Unk8003B870String* out, int key, const unsigned short* fallback, int);

inline EVec2 TextSize(Unk8003B870String& text) {
    return lbl_802E6700.unkEC->DoGetStringSize(text.fn_801C5B24(), true, 0);
}

// 0x800424F0
// Sets a dialog up from its description: who may answer, the kind, the title, the
// body and the button texts. Kind 3 shows the text-entry screen instead.
// NON_MATCHING: 772 instructions against 721 and a frame of 0x108 against 0xD8: the
// original reuses three stack slots for the strings in the motive loop and one slot
// for the three text sizes; here each temporary gets its own.
int Unk80040274::vfn22(Unk800424F0Source* source, unsigned char* b, void* c) {
    int who = b[5] & 0xF;
    if (who == 1) {
        unk70 = 0;
    } else if (who == 2) {
        unk70 = 1;
    } else {
        unk70 = 2;
    }
    Unk8003B870String title = fn_802186F4(unk6C) ? Unk8003B870String(*fn_80218174(unk6C), 0, -1)
                                                  : Unk8003B870String((const unsigned short*)TextOf(fn_80218044(unk6C)));
    unk50->unk10 = title;
    unk7C = b[5] >> 4;
    unk78 = (b[7] >> 4) & 7;
    if (source) {
        unk84 = source->unk4;
    } else {
        unk84 = 0;
    }
    Unk8023CDDC strings;
    fn_8023CE04(strings.table);
    strings.table = 0;
    strings.table = fn_8023CDDC();
    if (source) {
        unk84 = source->unk4;
    } else {
        unk84 = 0;
    }
    int set;
    if (source) {
        set = fn_801C27C8(source->unkC);
    } else {
        set = *(int*)unk6C;
        if (set == 0) {
            set = fn_80217F2C(unk6C);
        }
    }
    strings.table->vfn19(set, 0x12D, 0);
    Unk8003B870String body;
    if (unk7C != 3) {
        fn_80043034(strings.table, &unk50->unk10, b[6], unk50->unk10.fn_801C5B24(), 1);
    } else {
        fn_80043034(strings.table, &unk50->unk10, b[2], unk50->unk10.fn_801C5B24(), 1);
    }
    lbl_802E6700.unkEC->SetSize(true, lbl_8037B504, 1.0f);
    if (unk7C != 3) {
        fn_80043034(strings.table, &body, b[2], 0, 1);
        unk50->unkC = (const unsigned short*)TextOf(strings.table->vfn6(b[2]));
    }
    switch (unk7C) {
    case 2:
        fn_80043034(strings.table, &unk50->unk14, b[0], (const unsigned short*)GetTextB("cancel"), 1);
        unk50->unk44 = TextSize(unk50->unk14);
        fn_80043034(strings.table, &unk50->unk18, b[4], (const unsigned short*)GetTextB("no"), 1);
        unk50->unk3C = TextSize(unk50->unk18);
        fn_80043034(strings.table, &unk50->unk1C, b[3], (const unsigned short*)GetTextB("yes"), 1);
        unk50->unk34 = TextSize(unk50->unk1C);
        break;
    case 1:
        fn_80043034(strings.table, &unk50->unk18, b[4], (const unsigned short*)GetTextB("no"), 1);
        unk50->unk3C = TextSize(unk50->unk18);
        fn_80043034(strings.table, &unk50->unk1C, b[3], (const unsigned short*)GetTextB("yes"), 1);
        unk50->unk34 = TextSize(unk50->unk1C);
        unk50->unk14.fn_801C5704(0, -1);
        break;
    case 0:
    case 3:
    case 4:
    case 10:
        fn_80043034(strings.table, &unk50->unk1C, b[3], (const unsigned short*)GetTextB("ok"), 1);
        unk50->unk34 = TextSize(unk50->unk1C);
        unk50->unk18.fn_801C5704(0, -1);
        unk50->unk14.fn_801C5704(0, -1);
        break;
    }
    if (unk68) {
        int state = 0;
        unk68->vfn44(&unk50->unk1C, source, 0, &state, c);
        unk68->vfn44(&unk50->unk10, source, 0, &state, c);
        if (unk50->unk18.fn_801C6058()) {
            unk68->vfn44(&unk50->unk18, source, 0, &state, c);
        }
        if (unk50->unk18.fn_801C6058()) {
            unk68->vfn44(&unk50->unk14, source, 0, &state, c);
        }
        unk94 = 0;
        unk90 = 8;
        // A motive named in the body picks the icon and is taken out of the text.
        for (int i = 0; i <= 7; i++) {
            Unk8003B870String tag;
            switch (i) {
            case 0:
                tag.fn_801C54EC(Unk8003B870String(L"Hunger"), 0, -1);
                break;
            case 1:
                tag.fn_801C54EC(Unk8003B870String(L"Comfort"), 0, -1);
                break;
            case 2:
                tag.fn_801C54EC(Unk8003B870String(L"Hygiene"), 0, -1);
                break;
            case 3:
                tag.fn_801C54EC(Unk8003B870String(L"Bladder"), 0, -1);
                break;
            case 4:
                tag.fn_801C54EC(Unk8003B870String(L"Energy"), 0, -1);
                break;
            case 5:
                tag.fn_801C54EC(Unk8003B870String(L"Fun"), 0, -1);
                break;
            case 6:
                tag.fn_801C54EC(Unk8003B870String(L"Room"), 0, -1);
                break;
            case 7:
                tag.fn_801C54EC(Unk8003B870String(L"Social"), 0, -1);
                break;
            }
            Unk8003B870String separator;
            separator.fn_801C54EC(Unk8003B870String(L""), 0, -1);
            Unk8003B870String rest;
            unk94 = fn_800D1E94(body.fn_801C5B24(), tag.fn_801C5B24(), separator.fn_801C5B24(), &rest);
            if (unk94 != 0) {
                body = rest;
                unk90 = i;
                break;
            }
        }
        fn_800D2EFC(body.fn_801C5B24(), &body);
        unk68->vfn44(&body, source, 0, &state, c);
    }
    if (unk7C != 3) {
        fn_80043110(&body, 0);
    } else {
        Unk801BA678 wide(unk50->unk10.fn_801C5B24());
        unk58 = new Unk800C6704(GetText("default_text_baby"), 9, 0, (int)wide.Get(), 0, 0, 0, 0.5f, 100.0f, 100.0f,
                                0x26, 0, 0x10, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0);
        unk5C.fn_801BA958(0x40, 0);
        unk80 = 1;
        lbl_8037C0D0 = fn_80061A7C;
        lbl_8037C0CC = fn_80061A50;
        lbl_8037C0D4 = fn_80061AA8;
    }
    return 1;
}

// 0x80043034
// Looks a string up in a table; uses the fallback when there is none or it is empty.
// NON_MATCHING: 42 instructions against 46. The original tests the looked-up text
// through two separate null checks (cr7 kept across them) and loads the virtual's
// address before its this-offset.
void fn_80043034(Unk80043034Table* table, Unk8003B870String* out, int key, const unsigned short* fallback, int) {
    Unk800669ACResult result = table->vfn6(key);
    if ((result.ptr ? *result.ptr : 0) != 0 && fn_801BA640((const unsigned short*)(result.ptr ? *result.ptr : 0)) != 0) {
        out->fn_801C55CC((const unsigned short*)(result.ptr ? *result.ptr : 0));
    } else if (fallback) {
        out->fn_801C55CC(fallback);
    }
}

// 0x800430EC
bool fn_800430EC(int character) {
    if (character == ' ') {
        return true;
    }
    return (unsigned int)(character - 9) <= 4;
}

// 0x80043110
// Places the dialog's window and breaks the body into lines that fit it.
// NON_MATCHING: 295 instructions against 301; the four window rectangles are built
// differently (the original stores the default corners first and reloads them).
void Unk80040274::fn_80043110(Unk8003B870String* body, int flag) {
    unk98 = 0;
    EVec2 from(lbl_8037CAC0);
    EVec2 to(from + lbl_8037CAD8);
    if (flag != 0) {
        float bottom = 0.32f - lbl_8037ED50;
        if (unk70 == 0) {
            unk64->fn_8018B584(ERectF(0.28f, lbl_8037ED50, lbl_8037ED54 - 0.025f, bottom));
        } else if (unk70 == 1) {
            unk64->fn_8018B584(ERectF(lbl_8037ED4C + 0.05f, 0.77f, 0.725f, bottom + 0.77f));
        } else {
            unk64->fn_8018B584(ERectF(from.x, from.y, to.x, to.y));
        }
    } else {
        unk64->fn_8018B584(ERectF(from.x, from.y, to.x, to.y));
    }
    unk50->Clear();
    unk50->unk20 = 0;
    float width = unk64->Right() - unk64->Left() - 0.1f;
    lbl_802E6700.unkEC->SetSize(true, lbl_8037B504, 1.0f);
    const unsigned short* in = body->fn_801C5B24();
    while (*in != 0) {
        fn_80111C78(lbl_802E5F9C, 0, 0x100);
        int length = 0;
        unsigned short* out = lbl_802E5F9C;
        bool done = false;
        int lastSpace = 0;
        while (*in != 0 && !done) {
            *out = *in;
            if (*in == '\n') {
                in++;
                done = true;
                continue;
            }
            if (fn_800430EC(*in)) {
                lastSpace = length;
            }
            EVec2 size = lbl_802E6700.unkEC->DoGetStringSize(lbl_802E5F9C, true, 0);
            if (size.x > width) {
                done = true;
                int back = length - lastSpace;
                if (back != 0) {
                    if (length == back) {
                        back = 0;
                        in--;
                    }
                    in -= back;
                    length -= back;
                    body->fn_801C5B24();
                    lbl_802E5F9C[length] = 0;
                } else {
                    lbl_802E5F9C[length] = back;
                }
                length--;
            }
            out++;
            in++;
            length++;
        }
        if (done || lbl_802E5F9C[0] != 0) {
            lbl_802E5F9C[length] = 0;
            Unk8003B870String line(lbl_802E5F9C);
            unk50->unk0.fn_801B4600(new Unk8003B870String(line, 0, -1));
            unk50->unk20++;
        }
    }
    EVec2 size = lbl_802E6700.unkEC->DoGetStringSize("A!Wyj^?}|", false, 0);
    float height = size.y;
    unk50->unk28 = lbl_8037B550 * lbl_802E6700.unkEC->GetLineSpacing(0);
    float needed = unk50->unk28 * (float)(unk50->unk20 - 1) + height * (float)unk50->unk20;
    if (unk64->Bottom() - unk64->Top() > needed) {
        unk64->SetBottom(unk64->Top() + needed + 0.005f);
        unk98 = 1;
    }
    fn_800435C4(flag);
}

// 0x800435C4
// Works out where the dialog goes and starts it fading in.
// NON_MATCHING: 144 instructions against 151; the original adds the height terms one
// at a time in source order, here they are regrouped. Constants are in its order.
void Unk80040274::fn_800435C4(int flag) {
    unkF0 = 1;
    unk50->unk24 = unk64->Top();
    unk80 = 0;
    unk4C->unk3C = 120.0f;
    float line = 32.0f / (float)lbl_8037C198->unk18;
    lbl_802E6700.unkEC->SetSize(true, lbl_8037B504, 1.0f);
    float start = 0.0f;
    EVec2 size = lbl_802E6700.unkEC->DoGetStringSize("A!Wyj^?}|", false, 0);
    ERectF rect;
    if (flag == 0) {
        float gap = 0.08f;
        float height = unk64->Bottom() - unk64->Top() + 0.01f + size.y + gap + gap + line;
        rect.unk4 = unk64->Top() - gap - size.y;
        rect.unk0 = unk64->Left() - 0.05f;
        rect.unk8 = unk64->Right() + 0.05f;
        rect.unkC = rect.unk4 + height;
    } else {
        float height = unk64->Bottom() - unk64->Top() + 0.01f;
        rect.unk4 = unk64->Top() - 0.01f;
        rect.unk0 = unk64->Left() - 0.025f;
        rect.unk8 = unk64->Right() + 0.025f;
        rect.unkC = rect.unk4 + height;
    }
    unk4C->unk10 = rect;
    unk4C->unk30.Set(start, lbl_8037B500, start);
    fn_800448F4();
    unk4C->unk20 = unk4C->unk10;
}

// 0x80043820
Unk80043820::Unk80043820() {
    unk14 = 0;
    unk0 = 2;
}

// 0x80043860
Unk80043820::~Unk80043820() {
    fn_8004406C();
    fn_80043A40();
}

// 0x800438B8
// Loads the sprites the dialogs share.
void Unk80043820::fn_800438B8() {
    if (lbl_8037B520 == 0) {
        Unk80340AB8* manager = &lbl_80340AB8;
        lbl_8037B520 = (Unk80181824*)manager->fn_80177628(0xFA2F98BD, 0, 0);
        lbl_8037B524 = (Unk80181824*)manager->fn_80177628(0x752750E0, 0, 0);
        lbl_8037B528 = (Unk80181824*)manager->fn_80177628(0xAAD6E519, 0, 0);
        lbl_8037B52C = (Unk80181824*)manager->fn_80177628(0xEC7E2978, 0, 0);
        lbl_8037B530 = (Unk80181824*)manager->fn_80177628(0x85B7F9DE, 0, 0);
        lbl_8037B534 = (Unk80181824*)manager->fn_80177628(0x848F0F41, 0, 0);
        lbl_8037B538 = (Unk80181824*)manager->fn_80177628(0x500D9FB0, 0, 0);
        lbl_8037B53C = (Unk80181824*)manager->fn_80177628(0xD6D2BE5E, 0, 0);
        lbl_8037B540 = (Unk80181824*)manager->fn_80177628(0xE2CE822F, 0, 0);
        lbl_8037B544 = (Unk80181824*)manager->fn_80177628(0xAAFBCF12, 0, 0);
        lbl_8037B548 = (Unk80181824*)manager->fn_80177628(0xB352A29A, 0, 0);
        lbl_8037B54C = (Unk80181824*)manager->fn_80177628(0x547F8E69, 0, 0);
    }
}

// 0x80043A40
void Unk80043820::fn_80043A40() {
    E_RELEASE_RESOURCE(lbl_8037B520);
    E_RELEASE_RESOURCE(lbl_8037B524);
    E_RELEASE_RESOURCE(lbl_8037B528);
    E_RELEASE_RESOURCE(lbl_8037B52C);
    E_RELEASE_RESOURCE(lbl_8037B530);
    E_RELEASE_RESOURCE(lbl_8037B534);
    E_RELEASE_RESOURCE(lbl_8037B538);
    E_RELEASE_RESOURCE(lbl_8037B53C);
    E_RELEASE_RESOURCE(lbl_8037B540);
    E_RELEASE_RESOURCE(lbl_8037B544);
    E_RELEASE_RESOURCE(lbl_8037B548);
    E_RELEASE_RESOURCE(lbl_8037B54C);
}

// 0x80043B7C
// The dialog showing is done with.
void Unk80043820::vfn8() {
    unk8.fn_801B484C(unk14);
    if (unk14) {
        delete unk14;
    }
    unk14 = 0;
    unk0 = 2;
}

// 0x80043BF0
void Unk80043820::fn_80043BF0() {
    if (unk14 == 0) {
        if (unk8.head != 0) {
            unk14 = fn_80044128();
            vfn5();
        }
    } else if (unk0 == 2) {
        unk14->vfn2();
    }
}

// 0x80043C84
void Unk80043820::fn_80043C84(ERC* rc) {
    if (unk14) {
        unk14->vfn3(rc);
    }
}

// 0x80043CC4
int Unk80043820::vfn2(void* a, unsigned char* b, Unk800421C0Sim* sim, int id, void* c) {
    Unk80040274* dialog;
    lbl_8037CAF0 = b[5] >> 4;
    if ((b[5] & 0xF0) == 0x70) {
        dialog = new Unk800CBF40;
    } else {
        dialog = new Unk80040274;
    }
    if (sim) {
        dialog->vfn20(sim);
    } else if (id) {
        dialog->vfn21(id);
    }
    dialog->unk60 = b;
    dialog->vfn22((Unk800424F0Source*)a, b, c);
    dialog->unk54 = this;
    if (unk14 == 0) {
        unk14 = dialog;
        vfn5();
    } else {
        vfn5();
        unk8.fn_801B4600(dialog);
    }
    return 1;
}

// 0x80043E38
int Unk80043820::vfn3(void* a, void* b, Unk800421C0Sim* sim) {
    lbl_8037CAF0 = 7;
    Unk80040274* dialog = new Unk80040274;
    if (sim) {
        dialog->vfn20(sim);
    }
    dialog->vfn23((Unk8003B870String*)a, (const char*)b);
    dialog->unk54 = this;
    if (unk14 == 0) {
        unk14 = dialog;
        vfn5();
    } else {
        vfn5();
        unk8.fn_801B4600(dialog);
    }
    return 1;
}

// 0x80043F38
int Unk80043820::vfn4(void* a, void* b, void* c, void* d) {
    lbl_8037CAF0 = 7;
    Unk80040274* dialog = new Unk800CBF40;
    dialog->vfn24(a, b, c, d);
    dialog->unk54 = this;
    if (unk14 == 0) {
        unk14 = dialog;
        vfn5();
    } else {
        vfn5();
        unk8.fn_801B4600(dialog);
    }
    return 1;
}

// 0x80044020
void Unk80043820::vfn5() {
    if (unk14) {
        unk14->vfn25();
    }
}

// 0x80044060
long long Unk80043820::vfn7() {
    return unk0;
}

inline void DeleteDialogs(Unk80026864List& list) {
    Unk80026864Node* next;
    for (Unk80026864Node* node = list.tail; IsNode(node); node = next) {
        Unk80040274* dialog = (Unk80040274*)node->item;
        next = node->prev;
        if (list.owns && dialog) {
            delete dialog;
        }
    }
    list.fn_801B4760();
}

// 0x8004406C
// NON_MATCHING: the delete loop keeps the node in r3 instead of r9 (see Clear()).
// Deletes the dialogs waiting and the one showing.
void Unk80043820::fn_8004406C() {
    DeleteDialogs(unk8);
    if (unk14) {
        delete unk14;
    }
    unk14 = 0;
}

// 0x80044128
// Takes the first dialog off the queue.
Unk80040274* Unk80043820::fn_80044128() {
    return (Unk80040274*)unk8.RemoveHead();
}

// 0x80044174
ERectF Unk80040274::fn_80044174() {
    ERectF rect(unk4C->unk10.unk0, unk4C->unk10.unk4, unk4C->unk10.unk8, unk4C->unk10.unkC);
    return rect;
}

inline float TextWidth(ERFont* font, Unk8003B870String& text) {
    EVec2 size = font->DoGetStringSize(text.fn_801C5B24(), true, 0);
    return size.x;
}

// 0x800441C0
// The width of the widest button text.
// NON_MATCHING: 98 instructions against 100. The original keeps one size slot at
// sp+8 with its address in r30 for the second and third calls and a 0x30 frame; an
// inline helper, named locals and `.x` on the call result all give other frames.
float Unk80040274::fn_800441C0() {
    ERFont* font = lbl_802E6700.unkEC;
    font->SetSize(true, 14.0f, 1.0f);
    float width;
    if (unk7C == 1) {
        float first = TextWidth(font, unk50->unk1C);
        float second = TextWidth(font, unk50->unk18);
        width = first;
        if (width < second) {
            width = second;
        }
    } else if (unk7C == 2) {
        float first = TextWidth(font, unk50->unk1C);
        float second = TextWidth(font, unk50->unk18);
        float third = TextWidth(font, unk50->unk14);
        width = first;
        if (width < second) {
            width = second;
        }
        if (width < third) {
            width = third;
        }
    } else {
        width = TextWidth(font, unk50->unk1C);
    }
    return width;
}

// 0x80044350
// A variable set by the UI script.
void Unk80040274::vfn8(const char* name, const char* value) {
    fn_80110874(value);
    if (fn_80111ECC("dialog_key_press", name) == 0) {
        return;
    }
    if (fn_80111ECC("dialog_current_button", name) == 0) {
        if (fn_80111ECC("1", value) == 0) {
            unkC4 = 1;
        } else if (fn_80111ECC("2", value) == 0) {
            unkC4 = 2;
        } else {
            unkC4 = 3;
        }
    } else if (fn_80111ECC("dialog_button_accept_x", name) == 0) {
        fn_8010F7F0(value, "%f", &unkD4[0]);
    } else if (fn_80111ECC("dialog_button_accept_y", name) == 0) {
        fn_8010F7F0(value, "%f", &unkC8[0]);
    } else if (fn_80111ECC("dialog_button_alt2_x", name) == 0) {
        fn_8010F7F0(value, "%f", &unkD4[1]);
    } else if (fn_80111ECC("dialog_button_alt2_y", name) == 0) {
        fn_8010F7F0(value, "%f", &unkC8[1]);
    } else if (fn_80111ECC("dialog_button_decline_x", name) == 0) {
        fn_8010F7F0(value, "%f", &unkD4[2]);
    } else if (fn_80111ECC("dialog_button_decline_y", name) == 0) {
        fn_8010F7F0(value, "%f", &unkC8[2]);
    } else if (fn_80111ECC("dialog_title_bar_x", name) == 0) {
        fn_8010F7F0(value, "%f", &unkE4.x);
    } else if (fn_80111ECC("dialog_title_bar_y", name) == 0) {
        fn_8010F7F0(value, "%f", &unkE4.y);
    } else {
        int different = fn_80111ECC("dialog_status", name);
        if (different == 0) {
            if (fn_80111ECC(value, "true") == 0) {
                unk48 = 1;
            } else {
                unk48 = different;
            }
        }
    }
}

// 0x800445EC
// A variable read by the UI script; the caller frees the text.
// NON_MATCHING: 197 instructions against 194; not yet compared in detail (the
// branches share one sprintf tail in the original).
char* Unk80040274::vfn9(const char* name) {
    char* text = (char*)fn_80169F1C(0x20, 4);
    ERectF rect = fn_80044174();
    float buttonWidth = fn_800441C0();
    text[0] = 0;
    if (fn_80111ECC("dialog_box_width", name) == 0) {
        fn_8010F710(text, "%f", 0.6f);
    } else if (fn_80111ECC("dialog_box_height", name) == 0) {
        float extra = 0.1f;
        float height;
        if (unk94) {
            height = rect.unkC - rect.unk4 + extra;
        } else {
            height = rect.unkC - rect.unk4;
        }
        fn_8010F710(text, "%f", height);
    } else if (fn_80111ECC("dialog_x", name) == 0) {
        fn_8010F710(text, "%f", 0.2f);
    } else if (fn_80111ECC("dialog_y", name) == 0) {
        fn_8010F710(text, "%f", 0.18f);
    } else if (fn_80111ECC("right", name) == 0) {
        fn_8010F710(text, "%f", rect.unk8);
    } else if (fn_80111ECC("bottom", name) == 0) {
        fn_8010F710(text, "%f", rect.unkC);
    } else if (fn_80111ECC("number_of_buttons", name) == 0) {
        int count;
        switch (unk7C) {
        case 0:
        case 10:
            count = 1;
            break;
        case 1:
            count = 2;
            break;
        case 2:
            count = 3;
            break;
        default:
            count = 0;
            break;
        }
        fn_8010F710(text, "%d", count);
    } else if (fn_80111ECC("UI_button_width", name) == 0) {
        fn_8010F710(text, "%f", buttonWidth);
    } else if (fn_80111ECC("is_critical_dialog", name) == 0) {
        fn_8010F710(text, "%d", 0);
    } else if (fn_80111ECC("dialog_title_bar_width", name) != 0) {
        fn_80169EE8(text);
        return 0;
    } else {
        lbl_802E6700.unkEC->SetSize(true, 20.0f, 1.0f);
        unk50->unk4C = lbl_802E6700.unkEC->DoGetStringSize(unk50->unk10.fn_801C5B24(), true, 0);
        unkE0 = unk50->unk4C.x;
        fn_8010F710(text, "%f", unkE0);
    }
    return text;
}

// 0x800448F4
// Tells the script the dialog is up, once.
void Unk80040274::fn_800448F4() {
    if (unkB0 == 0) {
        unkEC = ((Unk80108290*)lbl_802E6700.unk90)->fn_8010826C(this);
        ((Unk80108290*)lbl_802E6700.unk90)->fn_801082BC(0);
        fn_80106164(lbl_802E6700.unk90, "showDialog", 0, 0, 0);
        unkB0 = 1;
    }
}

// 0x80044974
// Draws the motive icon under the body.
// NON_MATCHING: 132 instructions, 52 differ. The original's frame is 8 bytes larger
// (an unused 8-byte local after the colour) and it loads the texture size later.
void Unk80040274::fn_80044974(ERC* rc) {
    EVec2 position;
    position.x = 0.45f;
    position.y = unk64->Bottom() + 0.02f;
    Unk80181824* icon;
    Unk80181824Texture* texture;
    switch (unk90) {
    case 0:
        icon = lbl_8037B530;
        texture = SpriteTexture(icon);
        icon->fn_80181824(rc);
        break;
    case 1:
        icon = lbl_8037B534;
        texture = SpriteTexture(icon);
        icon->fn_80181824(rc);
        break;
    case 2:
        icon = lbl_8037B538;
        texture = SpriteTexture(icon);
        icon->fn_80181824(rc);
        break;
    case 3:
        icon = lbl_8037B53C;
        texture = SpriteTexture(icon);
        icon->fn_80181824(rc);
        break;
    case 4:
        icon = lbl_8037B540;
        texture = SpriteTexture(icon);
        icon->fn_80181824(rc);
        break;
    case 5:
        icon = lbl_8037B544;
        texture = SpriteTexture(icon);
        icon->fn_80181824(rc);
        break;
    case 6:
        icon = lbl_8037B548;
        texture = SpriteTexture(icon);
        icon->fn_80181824(rc);
        break;
    case 7:
        icon = lbl_8037B54C;
        texture = SpriteTexture(icon);
        icon->fn_80181824(rc);
        break;
    }
    Unk80181824Image* image = texture->unk20;
    float height = (float)image->unk12 / (float)lbl_8037C198->unk18;
    float width = (float)image->unk10 / (float)lbl_8037C198->unk14;
    rc->vfn47(EVec2(position.x, position.y + 0.01f), EVec2(position.x + width, position.y + height), lbl_8037CB38,
              lbl_8037CB40, EColorF(lbl_802E6964), 0.0f);
}
