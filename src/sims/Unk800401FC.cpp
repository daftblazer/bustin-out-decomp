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

// The dialog boxes (unit 0x800401FC). STAGE 1 of the unit: the object that queues
// dialogs is complete; of the dialog itself only the constructor of its texts, the
// destructor and the small members are written. Still to write: the constructor
// (0x80040274), update (0x80040640), the drawing functions (0x80040EAC to 0x80041F74),
// the two set-up functions (0x80042360, 0x800424F0), the word wrapping (0x80043034 to
// 0x800435C4) and the script variables (0x80044174 to 0x80044974).

struct Unk80181824 {
    void fn_80181824(ERC* rc);
};

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
};
// What a sim's slot 167 returns: flags per choice.
struct Unk80042228Record {
    char unk0[0x16];
    short unk16[1];
};
extern Unk8003B870String lbl_8037D3B4;
extern float lbl_8037B504;

// The level (lbl_8037D998): slot 8 is told when a dialog's texts go away.
struct Unk8037D998Level {
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
};
extern Unk8037D998Level* lbl_8037D998;

// Callbacks another unit installs while a dialog is up.
extern void (*lbl_8037C0D0)();
extern void (*lbl_8037C0D4)();
extern void (*lbl_8037C0D8)();
void fn_80061AD4();
void fn_80061B00();
void fn_80061B2C();

// The dialog class of another unit (0xE28 bytes, constructor 0x800CBF40).
class Unk800CBF40 : public Unk80040274 {
public:
    Unk800CBF40();
    char unkF4[0xE28 - 0xF4];
};

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
    unkC = (const unsigned short*)L"Missing String!!!";
    unk20 = 0;
    unk2C = 0;
    unk30 = 0;
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
        fn_80169EE8(unk4C);
    }
    unk4C = 0;
    if (unk64) {
        delete unk64;
    }
    unk64 = 0;
    lbl_8037C0D4 = fn_80061B00;
    lbl_8037C0D0 = fn_80061AD4;
    lbl_8037C0D8 = fn_80061B2C;
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
    lbl_8037D998->vfn8();
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

// 0x80040DE0
// NON_MATCHING: the inlined Clear() (see there): node in r3 instead of r9.
void Unk80040274::fn_80040DE0() {
    unk50->Clear();
    if (lbl_802E6700.unkBC) {
        ((UnkTargetBase*)lbl_802E6700.unkBC)->vfn7(0, 0x1F);
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
int Unk80040274::vfn23(void* a, const char* title) {
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
    fn_80043110(a, 0);
    return 1;
}

// 0x80043034
// Looks a string up in a table; uses the fallback when there is none or it is empty.
// NON_MATCHING: 42 instructions against 46. The original tests the looked-up text
// through two separate null checks (cr7 kept across them) and loads the virtual's
// address before its this-offset.
void fn_80043034(Unk80043034Table* table, Unk8003B870String* out, int key, const unsigned short* fallback) {
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
    dialog->vfn22(a, b, c);
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
    dialog->vfn23(a, (const char*)b);
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
