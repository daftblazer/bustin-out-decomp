#ifndef SIMS_UNK80026864_H
#define SIMS_UNK80026864_H

#include "engine/UnkTargetBase.h"
#include "sims/EGlobal.h"
#include "sims/Unk800052C8.h"
#include "engine/ELightSet.h"

extern "C" void* fn_80111C78(void* dst, int value, unsigned int size); // memset
void fn_80169EE8(void* ptr);
void fn_801767FC(void* resource);

// Virtual base of the in-game screens (vtable 0x802A2AC0): one word and three virtuals.
class Unk802A2AC0 {
public:
    Unk802A2AC0() { mode = 0; }
    // True for four of the modes (8 to 11).
    bool IsBuildMode() const { return mode == 8 || mode == 10 || mode == 11 || mode == 9; }
    bool IsMode8Or10() const { return mode == 8 || mode == 10; }
    int mode;   // current mode
    virtual ~Unk802A2AC0() {}
    virtual void vfn2(int);   // not inline: the vtable lives with its definition
    virtual void vfn3();
};

// Doubly linked list of pointers (first node, last node, "owns its items" flag).
// It shares its clearing function (0x801B4760) with the screen objects' child list.
struct Unk80026864Node {
    void* item;
    Unk80026864Node* prev;
    Unk80026864Node* next;
};
struct Unk80026864List {
    Unk80026864List() {
        tail = 0;
        head = 0;
        owns = 1;
    }
    ~Unk80026864List() { fn_801B4760(); }
    void fn_801B4760();                 // clear
    void Clear() {
        if (head) {
            fn_801B4760();
        }
    }
    void fn_801B4600(void* item);       // append
    int fn_801B484C(void* item);        // contains

    Unk80026864Node* Head() const { return head; }
    Unk80026864Node* Tail() const { return tail; }

    Unk80026864Node* head;
    Unk80026864Node* tail;
    int owns;
};

// 0x28 bytes of zeroed words (constructor 0x8002EF48).
struct Unk8002EF48 {
    Unk8002EF48() { fn_8002EF48(); }
    void fn_8002EF48(); // zero everything
    int unk0, unk4, unk8, unkC, unk10, unk14, unk18, unk1C, unk20, unk24;
};

class Unk80026864;
typedef int (Unk80026864::*Unk80026864Handler)();

// The in-game object cursor and selection screen (0x1D0 bytes with its virtual
// base). The name is unknown; it is one of the "...Target" screens.
class Unk80026864 : public UnkTargetBase, public virtual Unk802A2AC0 {
public:
    Unk80026864(int player);
    virtual ~Unk80026864();
    virtual void vfn2();                               // update
    virtual void vfn3(struct ERC* rc);                 // draw (empty)
    virtual void vfn4(const EVec3& position);
    virtual void vfn7(UnkTargetBase* sender, int message);
    virtual void vfn18(int flags, int set);
    virtual void vfn2(int);                            // Unk802A2AC0
    virtual void vfn3();                               // Unk802A2AC0 (empty)

    void fn_80026C78();                                // create the cursor meshes, load resources
    void fn_8002775C(int value);
    void fn_80027780();                                // release everything
    int fn_80027BF0();                                 // confirm button, selection of several
    int fn_80027D24();                                 // confirm button, single selection
    void fn_80027FCC(struct Unk800053D4Inner* object);
    void fn_800285D4();
    void fn_800286CC();
    void fn_80028BB0(int notify);
    int fn_80028F30();
    void fn_8002A0F4(void* definition);
    void fn_8002A1BC(struct ERC* rc);
    void fn_8002A234(struct ERC* rc);
    float fn_8002B9D0();
    void fn_8002BA04(int forward);
    void fn_8002BB64(int* tileX, int* tileY);
    EVec2 fn_8002BD98();
    void fn_8002BC5C(EVec2* out);
    void fn_8002C158();
    struct Unk800053D4Inner* fn_8002C7B4(int kind);
    static void fn_8002C940();
    void fn_8002D1CC();
    int fn_8002D270(int a, int b);
    void fn_8002D2A8(EVec3* out);
    EVec3* fn_8002D2C8();
    void fn_8002D2D0();
    void fn_8002BE48(struct Unk800053D4Inner* object);
    int fn_80028860();
    void* fn_80028E84();
    static void fn_80028ECC();
    void fn_8003043C();
    void fn_80033C3C();
    void fn_80031980();
    void fn_8002917C();
    void fn_80029BF8();
    void fn_80033BAC();
    void fn_8002F1BC();
    void fn_80031928();
    void Common() {
        fn_80033BAC();
        fn_8002F1BC();
        fn_80031928();
    }
    void fn_8002A0A8();
    void fn_8002D1D0();
    int fn_80027AD8();                                 // run the current state's handler
    void fn_80027EAC();                                // move the cursor to the player's sim
    int fn_800290B0();
    int fn_80031324();
    int fn_80033974();
    int fn_80033754();
    int fn_80033954();
    static void fn_8002ED34();
    void fn_8002C370(struct Unk800053D4Inner* object);

#include "sims/Unk80026864.inc"
};

// Two points, both zero to begin with.
struct Unk802E5B28 {
    Unk802E5B28() { unk0 = unkC = EVec3(0.0f); }
    EVec3 unk0;
    EVec3 unkC;
};

void fn_800266C0(int* id);
void fn_800266EC(Unk800053D4Inner* object, Unk80026864List* out);
void fn_8002ECE8(void* arg);
int fn_8002ED14(int arg);

#endif
