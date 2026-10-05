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
    Unk802A2AC0() { unk0 = 0; }
    int unk0;
    virtual ~Unk802A2AC0() {}
    virtual void vfn2(int);   // not inline: the vtable lives with its definition
    virtual void vfn3();
};

// Singly linked list of pointers with a count and an "owns its items" flag.
// It shares its clearing function (0x801B4760) with the screen objects' child list.
struct Unk80026864Node {
    void* item;
    Unk80026864Node* next;
};
struct Unk80026864List {
    Unk80026864List() {
        head = 0;
        count = 0;
        owns = 1;
    }
    ~Unk80026864List() { fn_801B4760(); }
    void fn_801B4760();                 // clear
    void Clear() {
        if (count) {
            fn_801B4760();
        }
    }
    void fn_801B4600(void* item);       // append
    int fn_801B484C(void* item);        // contains

    int count;
    Unk80026864Node* head;
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

    void fn_8002775C(int value);
    void fn_80027780();                                // release everything
    int fn_80027AD8();                                 // run the current state's handler
    void fn_80027EAC();                                // move the cursor to the player's sim
    int fn_800290B0();
    int fn_80031324();
    int fn_80033974();
    int fn_80033754();
    int fn_80033954();
    static void fn_8002ED34();
    void fn_8002C370(void* arg);

#include "sims/Unk80026864.inc"
};

// Two points, both zero to begin with.
struct Unk802E5B28 {
    Unk802E5B28() { unk0 = unkC = EVec3(0.0f); }
    EVec3 unk0;
    EVec3 unkC;
};

void fn_800266C0(int* id);
void fn_8002ECE8(void* arg);
int fn_8002ED14(int arg);

#endif
