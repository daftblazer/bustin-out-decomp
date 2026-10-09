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

#endif
