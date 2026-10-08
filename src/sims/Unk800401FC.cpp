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

// 0x80042358
int Unk80040274::vfn24(void* a, void* b, void* c, void* d) {
    return 1;
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
    dialog->vfn23(a, b);
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
