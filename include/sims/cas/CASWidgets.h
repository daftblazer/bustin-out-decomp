#ifndef SIMS_CAS_CASWIDGETS_H
#define SIMS_CAS_CASWIDGETS_H

#include "engine/EController.h"
#include "engine/EMat4.h"
#include "engine/EVec3.h"
#include "engine/UnkTargetBase.h"

// Two widgets used by the Create-A-Sim screen. Class names are provisional.

#include "engine/ERFont.h"

struct ERC;

extern EColorF lbl_802E69C4; // highlighted
extern EColorF lbl_802E6964; // normal
extern EColorF lbl_802E6954; // title
extern EColorF lbl_802E69E4; // disabled

struct Unk80181824 {
    void fn_80181824(ERC* rc);
};

// Render context: vtable pointer at 0x44.
struct ERC {
    char unk0[0x44];
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3(const void* vertices, int count); // draw a strip
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
    virtual void vfn22(void* object);                 // draw a recorded object
    virtual void vfn23();
    virtual void vfn24();
    virtual void vfn25();
    virtual void vfn26(int, int);
    virtual void vfn27();
    virtual void vfn28(EMat4* matrix, int);
    virtual void vfn29();
    virtual void vfn30(const EMat4* matrix); // set the view matrix
    virtual void vfn31(const EMat4* matrix); // set the projection
    virtual void vfn32();
    virtual void vfn33();
    virtual void vfn34();
    virtual void vfn35(int, int);
    virtual void vfn36(int flags);
    virtual void vfn37(int flags);
    virtual void vfn38(int);
    virtual void vfn39();
    virtual void vfn40();
    virtual void vfn41(int, int);
    virtual void vfn42();
    virtual void vfn43();
    virtual void vfn44(void* light);
    virtual void vfn45();
    virtual void vfn46();
    virtual void vfn47(const EVec2& corner0, const EVec2& corner1, const EVec2& uv0, const EVec2& uv1, const EColorF& color, float); // textured quad
    virtual void vfn48();
    virtual void vfn49(const EVec2& position, const EVec2& size, const EColorF& color, float); // tinted sprite
    virtual void vfn50();
    virtual void vfn51();
    virtual void vfn52();
    virtual void vfn53();
    virtual void vfn54(int, int, int, int);
    virtual void vfn55(int, int, int, float);
    virtual void vfn56(int, int, int);
    virtual void vfn57(void* target, int); // select the render target
    virtual void vfn58();
    virtual void vfn59();
    virtual void vfn60(int, int);
    virtual void vfn61(int, int, int, int, int, int);
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
};

// Callback invoked when a widget arrow is pressed (may be null).
extern void (*lbl_8037C0D4)();

void fn_801767FC(void* resource);

// Left/right selector with a caption (vtable 0x80292EA8).
class CASSelector : public UnkTargetBase {
public:
    virtual ~CASSelector();
    void Draw(ERC* rc);
    void Update();
    void ReleaseResources();
    void operator delete(void* ptr);

    EColorF unk48;        // left arrow colour
    EColorF unk58;        // right arrow colour
    const unsigned short** unk68; // caption
    int unk6C;            // message sent when moving right
    int unk70;            // message sent when moving left
    int unk74;
    ERFont* unk78;
    void* unk7C;
    Unk80181824* unk80;   // left arrow sprite
    Unk80181824* unk84;   // right arrow sprite
};

// A run of drawable pieces inside a model (16 bytes).
struct EModelGroup {
    struct Unk80184C00* unk0; // pieces, 0x24 bytes each
    int unk4;                 // how many
    char unk8[8];
};
struct Unk8033FF34Resource {
    char unk0[0x20];
    EModelGroup* unk20;
    int unk24; // number of groups
    char unk28[0x6C - 0x28];
    float unk6C;
    void fn_8017CC58(ERC* rc);
    void fn_8017CBEC(ERC* rc);
    void fn_8017D384(Unk8033FF34Resource* neighbour, float tolerance); // weld the seam shared with a neighbour
    void fn_8017DF14();
};
struct Unk8033FF34 {
    Unk8033FF34Resource* fn_80177628(unsigned int id, int, int);
    void fn_801778B4(unsigned int id);
    char unk0[0x100]; // size unknown
};
extern Unk8033FF34 lbl_8033FF34;

// Spinning 3D model button (vtable 0x80292E10).
class CASSpinner : public UnkTargetBase {
public:
    CASSpinner(unsigned char message);
    virtual ~CASSpinner();
    void Draw(ERC* rc);
    void Update();

    float unk48;          // rotation, radians
    EVec3 unk4C;
    unsigned char unk58;
    unsigned char unk59;  // message sent when pressed
    Unk8033FF34Resource* unk5C;
};

#endif
