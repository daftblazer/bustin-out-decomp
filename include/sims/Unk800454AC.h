#ifndef SIMS_UNK800454AC_H
#define SIMS_UNK800454AC_H

#include "engine/UnkTargetBase.h"
#include "engine/BString2.h"
#include "sims/Unk80026864List.h"
#include "sims/Unk800401FC.h"

// The action queue display (unit 0x800454AC, "Action Queue Manager"): the icons of
// the actions a sim has queued. The Sims 2 has ActionQueue and ActionQueueHUD; its
// functions do not line up with these by size, so the names here are placeholders.

struct ERC;

// One icon of the queue (0x108 bytes).
class Unk80047840 : public UnkTargetBase {
public:
    Unk80047840();
    virtual ~Unk80047840();
    virtual void vfn2();
    virtual void vfn3(ERC* rc);
    virtual void vfn7(UnkTargetBase* sender, int message) {}     // 0x80049A18

    void fn_80049094(int flag);
    void fn_80049400(unsigned int id);
    void fn_80049498(void* icon);
    void fn_8004950C();

    void* unk48[13];                  // sprites; unk48[11] (0x74) is the action's icon
    char unk7C[0x84 - 0x7C];
    int unk84;
    char unk88[0xD0 - 0x88];
    BString2 unkD0;
    Unk8004024CRange unkD4;
    Unk8004024CRange unkE0;           // how far it has faded in
    char unkEC[0xF4 - 0xEC];
    char unkF4;                       // its place in the pool (-1: none)
    Unk80047840* unkF8;               // next in the pool
    int unkFC;                        // 1: the icon has changed
    unsigned char unk100;             // where the icon came from: 0 none, 1 a resource id, 2 given
    unsigned int unk104;              // the resource id
};

// The pool the icons come from: ten of them, handed out and taken back.
struct Unk80045650 {
    void fn_80045650();                       // makes the ten icons (not a constructor: it returns nothing)
    ~Unk80045650();
    int fn_800456BC(Unk80047840* item);       // give one back
    Unk80047840* fn_80045720();               // take one

    Unk80047840* unk0;                // all of them, chained through unkF8
    int unk4;                         // how many are free
    Unk80026864ListBase unk8;         // the free ones (never initialised: the pool is in zeroed memory)
};

// The action queue's input listener (unit 0x800454AC). It is built from three classes:
//  - Unk80049AA8: a listener interface, only a vtable pointer (vtable 0x80299CD8);
//  - Unk801E58D4: a large engine base class (constructor 0x801E58D4, destructor 0x801E59A4),
//    0x20 bytes with its vtable pointer at 0x1C; only the slots overridden here are named;
//  - Unk800455D4: the 0x28-byte object made at 0x800455A8, derived from both.
// The real manager (constructor 0x800495C4, vtable 0x80299A20) is built on this and is not
// written yet.

class Unk80049AA8 {
public:
    virtual int vfn1() = 0;                                  // __pure_virtual
    virtual ~Unk80049AA8() {}                                // 0x80049AA8
};

class Unk801E58D4 {
public:
    Unk801E58D4(int a, int b);                               // 0x801E58D4
    virtual ~Unk801E58D4();                                  // 0x801E59A4
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual int vfn8();                                      // 0x80049590 in the listener
    virtual void vfn9();
    virtual void vfn10();
    virtual const char* vfn11();                             // 0x800498C4 in the listener
    virtual void vfn12();

    int (*unk0)(void* self, char* out);                      // called back with the input
    int unk4;
    int unk8;
    short unkC;
    int unk10;
    int unk14;
    int unk18;
};

struct Unk8037B554Owner;
int fn_800495C4(Unk8037B554Owner* owner);                    // the manager's constructor (not written yet)
extern Unk8037B554Owner* lbl_8037B554;                       // the manager, once made

class Unk800455D4 : public Unk801E58D4, public Unk80049AA8 {
public:
    Unk800455D4();                                           // 0x800455D4
    virtual ~Unk800455D4() {}                                // 0x80049A1C
    virtual int vfn8() {                                     // 0x80049590
        if (lbl_8037B554) {
            return fn_800495C4(lbl_8037B554);
        }
        return 0;
    }
    virtual const char* vfn11() { return "Action Queue Manager"; }   // 0x800498C4
    virtual int vfn1() { return vfn8(); }                    // 0x800499A4
    static int fn_800498A8(Unk800455D4* self, char* out) {   // the callback
        *out = self->unk24;
        self->unk24 = 0;
        return 0;
    }

    char unk24;
};

void fn_800455A8();                                          // makes the listener

#endif
