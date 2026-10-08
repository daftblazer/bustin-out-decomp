#include "engine/e_storable.h"
#include "engine/e_resource.h"
#include "engine/e_rfont.h"
#include "engine/e_texture.h"
#include "engine/e_shader.h"
#include "engine/e_rshader.h"
#include "sims/Unk8003B870.h"
#include "engine/ERFont.h"
#include "engine/ResourceManagers.h"
#include "engine/EController.h"

// Unit 0x8003B870 is three source files by its header strings (0x80297D18,
// 0x80297EB0, 0x80297F80). This is the first; the second has no functions of its
// own in the binary (only its header strings), the third is sims/ERFont.cpp.


struct Unk80181824 {
    void fn_80181824(ERC* rc);
};

// The first argument of vfn2.
struct Unk8003BAB8A {
    char unk0[0xC];
    int unkC;
};
// The sim's side of it (vtable pointer at 0x1C).
struct Unk8003BAB8Info {
    int unk0;
};
struct Unk8003BAB8Record {
    char unk0[0x16];
    short unk16;
};
struct Unk8003BAB8SimC {
    char unk0[0x18];
    void* unk18;
};
struct Unk8003BAB8Sim {
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
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn20();
    virtual void vfn21();
    virtual void vfn22();
    virtual void vfn23();
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
    virtual void vfn44(Unk8003B870String* text, Unk8003BAB8A* a, int, int* flag, int);
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
    virtual void vfn64();
    virtual void vfn65();
    virtual void vfn66();
    virtual void vfn67();
    virtual void vfn68();
    virtual void vfn69();
    virtual void vfn70();
    virtual void vfn71();
    virtual void vfn72();
    virtual void vfn73();
    virtual void vfn74();
    virtual void vfn75();
    virtual void vfn76();
    virtual void vfn77();
    virtual void vfn78();
    virtual void vfn79();
    virtual void vfn80();
    virtual void vfn81();
    virtual void vfn82();
    virtual void vfn83();
    virtual void vfn84();
    virtual void vfn85();
    virtual void vfn86();
    virtual void vfn87();
    virtual void vfn88();
    virtual void vfn89();
    virtual void vfn90();
    virtual void vfn91();
    virtual void vfn92();
    virtual void vfn93();
    virtual void vfn94();
    virtual void vfn95();
    virtual void vfn96();
    virtual void vfn97();
    virtual void vfn98();
    virtual void vfn99();
    virtual void vfn100();
    virtual void vfn101();
    virtual void vfn102();
    virtual void vfn103();
    virtual void vfn104();
    virtual void vfn105();
    virtual void vfn106();
    virtual void vfn107();
    virtual void vfn108();
    virtual void vfn109();
    virtual void vfn110();
    virtual void vfn111();
    virtual void vfn112();
    virtual void vfn113();
    virtual void vfn114();
    virtual void vfn115();
    virtual void vfn116();
    virtual void vfn117();
    virtual void vfn118();
    virtual Unk8003BAB8Info* vfn119();
    virtual void vfn120();
    virtual void vfn121();
    virtual void vfn122();
    virtual void vfn123();
    virtual void vfn124();
    virtual void vfn125();
    virtual void vfn126();
    virtual void vfn127();
    virtual void vfn128();
    virtual void vfn129();
    virtual void vfn130();
    virtual void vfn131();
    virtual void vfn132();
    virtual void vfn133();
    virtual void vfn134();
    virtual void vfn135();
    virtual void vfn136();
    virtual void vfn137();
    virtual void vfn138();
    virtual void vfn139();
    virtual void vfn140();
    virtual void vfn141();
    virtual void vfn142();
    virtual void vfn143();
    virtual void vfn144();
    virtual void vfn145();
    virtual void vfn146();
    virtual void vfn147();
    virtual void vfn148();
    virtual void vfn149();
    virtual void vfn150();
    virtual void vfn151();
    virtual void vfn152();
    virtual void vfn153();
    virtual void vfn154();
    virtual void vfn155();
    virtual void vfn156();
    virtual void vfn157();
    virtual void vfn158();
    virtual void vfn159();
    virtual void vfn160();
    virtual void vfn161();
    virtual void vfn162();
    virtual void vfn163();
    virtual void vfn164();
    virtual void vfn165();
    virtual void vfn166();
    virtual Unk8003BAB8Record* vfn167();
};
// The table the texts are looked up in.
struct Unk8023CDDCResult {
    const unsigned short** unk0;
};
struct Unk8023CDDC {
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual Unk8023CDDCResult vfn6(int key, ...);
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
    virtual void vfn19(int id, int, int);
};
Unk8023CDDC* fn_8023CDDC();
void fn_8023CE04(Unk8023CDDC* table);
// Holds the table while it is in use.
struct Unk8023CDDCHandle {
    Unk8023CDDCHandle() { table = 0; }
    void Close() {
        fn_8023CE04(table);
        table = 0;
    }
    ~Unk8023CDDCHandle() { Close(); }
    void Open() {
        Close();
        table = fn_8023CDDC();
    }
    Unk8023CDDC* operator->() { return table; }
    Unk8023CDDC* table;
};
int fn_801C27C8(int id);
int fn_80217F2C(Unk8003BAB8Info* info);

// The player's sim, as the global at lbl_8037D9A4 lists it.
struct Unk8003BFECOwnerB {
    char unk0[0x18];
    void* unk18;
};
struct Unk8003BFECOwnerA {
    char unk0[0x20];
    Unk8003BFECOwnerB* unk20;
};
struct Unk8003BFECOwner {
    Unk8003BFECOwnerA* unk0;
};
struct Unk8037D9A4 {
    char unk0[0x9C];
    Unk8003BFECOwner* unk9C[2];
};
extern Unk8037D9A4* lbl_8037D9A4;

// 0x8003B870
Unk8003B870::Unk8003B870(int player) {
    unk0 = player;
    unk4 = 0;
    unk2C = 0;
    unk30 = 0;
    unk34 = 0;
    unk38 = 0;
    unk3C = 0;
    unk40 = 0;
    unk44 = 0;
}

// 0x8003B8FC
Unk8003B870::~Unk8003B870() {
    E_RELEASE_RESOURCE(unk2C);
    E_RELEASE_RESOURCE(unk30);
    E_RELEASE_RESOURCE(unk34);
    E_RELEASE_RESOURCE(unk38);
}

// 0x8003B9E0
// Loads the four button sprites.
void Unk8003B870::fn_8003B9E0() {
    if (unk2C == 0) {
        unk2C = (Unk80181824*)lbl_80340AB8.fn_80177628(0x875049C1, 0, 0);
    }
    if (unk30 == 0) {
        unk30 = (Unk80181824*)lbl_80340AB8.fn_80177628(0x1E59187B, 0, 0);
    }
    if (unk34 == 0) {
        unk34 = (Unk80181824*)lbl_80340AB8.fn_80177628(0xE33BE101, 0, 0);
    }
    if (unk38 == 0) {
        unk38 = (Unk80181824*)lbl_80340AB8.fn_80177628(0x943CD197, 0, 0);
    }
}

// Looks up the text for one line and hands it to the sim, when the line changed.
#define UNK8003B870_LINE(member, index) \
    if (member != Unk8003B870String(b[index], 1)) { \
        Unk8023CDDCResult found = table->vfn6(b[index]); \
        member.fn_801C55CC(found.unk0 ? *found.unk0 : 0); \
        sim->vfn44(&member, a, 0, &flag, 0); \
    }

// 0x8003BAB8
// Puts the panel up for a choice: makes the five lines of text when what is asked
// has changed, then reports the button the player pressed (2: none yet, 1: one of
// the choices, which is noted in the sim's record, 0: the cancel button).
// NON_MATCHING: 336 instructions vs 333; the calls and their order agree. The stack
// is laid out differently (the original has 4 unused bytes after the table handle
// and 8 bytes for the temporary key string) and it keeps the key's address in two
// registers. Six variants tried (handle as a pointer, as a class with and without a
// destructor, 8 bytes wide; comparison through an inline operator).
long long Unk8003B870::vfn2(Unk8003BAB8A* a, unsigned char* b, Unk8003BAB8Sim* sim) {
    unk4 = 1;
    if (unk3C != a || unk40 != b || unk44 != sim) {
        Unk8003BAB8Info* info = sim ? sim->vfn119() : 0;
        int flag = 0;
        Unk8023CDDCHandle table;
        table.Open();
        int id;
        if (a) {
            id = fn_801C27C8(a->unkC);
        } else {
            id = info->unk0;
            if (id == 0) {
                id = fn_80217F2C(info);
            }
        }
        table->vfn19(id, 0x12D, 0);
        UNK8003B870_LINE(unk18, 6)
        UNK8003B870_LINE(unk1C, 3)
        UNK8003B870_LINE(unk20, 4)
        UNK8003B870_LINE(unk24, 0)
        UNK8003B870_LINE(unk28, 2)
    }
    unk3C = a;
    unk40 = b;
    unk44 = sim;
    if (unk8 == 1 || unkC == 1 || unk10 == 1 || unk14 == 1) {
        unk4 = 0;
        unk3C = 0;
        unk40 = 0;
        unk44 = 0;
        if (unkC == 1) {
            return 0;
        }
        int choice = unk8 == 1;
        if (unk14 == 1) {
            choice = 2;
        }
        if (unk10 == 1) {
            choice = 3;
        }
        Unk8003BAB8Record* record = sim ? sim->vfn167() : 0;
        record->unk16 = choice;
        return 1;
    }
    return 2;
}

// 0x8003BFEC
// Reads the four buttons while the panel is up, and takes it down when the sim it
// was put up for is no longer the player's.
void Unk8003B870::fn_8003BFEC() {
    EController* controller = lbl_8037C11C->fn_8015E5FC(lbl_8037C11C->fn_8015E614(unk0));
    Unk8037D9A4* global = lbl_8037D9A4;
    if (unk44) {
        Unk8003BFECOwner* owner = global->unk9C[unk0];
        if (owner == 0 || ((Unk8003BFECOwnerA*)unk44)->unk20->unk18 != owner->unk0->unk20->unk18) {
            unk4 = 0;
            unk3C = 0;
            unk40 = 0;
            unk44 = 0;
        }
    }
    if (unk4 == 1) {
        unk8 = controller->fn_8015E0F8(3);
        unkC = controller->fn_8015E0F8(1);
        unk10 = controller->fn_8015E0F8(4);
        unk14 = controller->fn_8015E0F8(2);
    } else {
        unk8 = 0;
        unkC = 0;
        unk10 = 0;
        unk14 = 0;
    }
}

struct Unk8003C0F0Global {
    char unk0[0xE4];
    Unk80181824* unkE4;      // panel background
    void* unkE8;
    ERFont* unkEC;           // the font
};
extern Unk8003C0F0Global lbl_802E6700;

// 0x8003C0F0
// Draws the panel: its frame, then each line of text with its button sprite.
// NON_MATCHING: skeleton of a 421-instruction function: only the test at the start,
// the font set-up and the first line are written; the frame's two sprites and the
// other four lines with their buttons are not reconstructed.
void Unk8003B870::fn_8003C0F0(ERC* rc) {
    if (unk4 != 1) {
        return;
    }
    lbl_802E6700.unkE4->fn_80181824(rc);
    lbl_802E6700.unkEC->SetSize(true, 16.0f, 1.0f);
    lbl_802E6700.unkEC->Select(rc);
    float centre;
    if (unk0 == 0) {
        centre = 0.25f;
    } else {
        centre = 0.75f;
    }
    EVec2 extent;
    extent = lbl_802E6700.unkEC->DoGetStringSize(unk18.fn_801C5B24(), true, 0);
    EVec2 at(centre - extent.x * 0.5f, 0.7f);
    lbl_802E6700.unkEC->DoDrawAlign(rc, unk18.fn_801C5B24(), true, at, 0, 0, 0);
}
