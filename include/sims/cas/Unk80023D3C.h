#ifndef SIMS_CAS_UNK80023D3C_H
#define SIMS_CAS_UNK80023D3C_H

#include "engine/Unk8018A44C.h"
#include "sims/cas/CASWidgets.h"

// Text colours of the family screens' buttons.
extern EColorF lbl_802E5AEC;
extern EColorF lbl_802E5AFC; // focused, inactive
extern EColorF lbl_802E5B0C; // inactive

// Small polymorphic class (0x14 bytes of data, then the vtable pointer) whose only
// virtual is an inline destructor. Its vtable is emitted in each unit that includes
// this header and the destructor once, at 0x80023D08. Other units build one on the
// stack next to their text-drawing calls.
// NON_MATCHING (0x80023D08): the destructor below is the right code, but nothing in
// Unk800230AC.cpp makes the compiler emit it or the vtable; what triggers them in the
// original (a use in a header function, or a template instance chosen through the
// repository) has not been found.
struct Unk80023D08 {
    char unk0[0x14];
    virtual ~Unk80023D08() {}
};

// Menu button of the family screens (0xC8 bytes). The name is unknown.
class Unk80023D3C : public Unk8018918C {
public:
    virtual ~Unk80023D3C();
    virtual void vfn2();          // update
    virtual void vfn3(ERC* rc);   // draw

    int unkBC;            // message sent when pressed
    float unkC0;          // animation time
    Unk80181824* unkC4;   // sprite
};

#endif
