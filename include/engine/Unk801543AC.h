#ifndef ENGINE_UNK801543AC_H
#define ENGINE_UNK801543AC_H

#include "engine/E3DWindow.h"
#include "engine/EMat4.h"

// 3D view built on E3DWindow: adds the view matrix and related state. 0x310
// bytes, constructor 0x801543AC, vtable 0x802A7BC8. The real name is unknown.
// It has no destructor of its own, so an owner destroys it by calling
// E3DWindow's destructor directly (flag 0, no vtable store). Both the game
// camera and the Create-A-Sim screen hold one as a member.
class Unk801543AC : public E3DWindow {
public:
    Unk801543AC();
    void fn_801546D8(const EMat4* matrix); // set the view matrix

    EMat4 unkA0; // view matrix
    char unkE0[0x310 - 0xE0];
};

#endif
