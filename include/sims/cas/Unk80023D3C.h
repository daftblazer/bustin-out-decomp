#ifndef SIMS_CAS_UNK80023D3C_H
#define SIMS_CAS_UNK80023D3C_H

#include "engine/Unk8018A44C.h"
#include "sims/cas/CASWidgets.h"

// Menu button of the family screens (0xC8 bytes). The name is unknown.
class Unk80023D3C : public Unk8018A44C {
public:
    virtual ~Unk80023D3C();
    virtual void vfn2();          // update
    virtual void vfn3(ERC* rc);   // draw

    int unkBC;            // message sent when pressed
    float unkC0;          // animation time
    Unk80181824* unkC4;   // sprite
};

#endif
