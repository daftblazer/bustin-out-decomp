#ifndef SIMS_E_RRLETEXTURE_H
#define SIMS_E_RRLETEXTURE_H

// The run-length encoded texture resource (c:/eor/src2/games/sims/ESrc/e_rrletexture.h;
// the file name comes from the __FILE__ string its operator new leaves behind).

#include "engine/EStorable.h"
#include "engine/ResourceManagers.h"

// The class name as a string: some inline function of the original header uses it
// (every unit that includes the header carries it); which one is not known.
inline const char* ERRleTextureHeaderString0() { return "ERRleTexture"; }

EStorable* fn_8003E6E8();
EStorable* fn_8003E710(void* place);
void fn_8003E73C(EStorable* object);

// An image stored as runs of palette indices (0x40 bytes). The pixels are read back
// one at a time with Next(); the palette has 16 or 256 entries.
class ERRleTexture : public EResource {
public:
    ERRleTexture();
    virtual ~ERRleTexture();

    void fn_8003E084(EFile* file);       // load
    void fn_8003E350();                  // rewind
    int fn_8003E3E8();                   // next pixel
    int fn_8003E41C();                   // next pixel, 16 colours
    int fn_8003E520();                   // next pixel, 256 colours
    int fn_8003E5DC();                   // read half a byte
    int fn_8003E628();                   // read a byte (which may straddle two)

    E_STORABLE_BODY(ERRleTexture, fn_8003E6E8, fn_8003E710, fn_8003E73C)
    void operator delete(void* ptr) { lbl_802E5E1C->fn_80177FE0(ptr); }

    int unk18;
    int unk1C;
    unsigned char* unk20;    // image data
    int* unk24;              // palette
    unsigned char unk28;     // 1: the current run is literal pixels
    unsigned char unk29;     // position in the run
    unsigned char unk2A;     // length of the run
    int unk2C;               // colour of a repeated run
    int unk30;               // read position
    int unk34;               // size of the image data
    int unk38;               // 1: at a byte boundary
    int unk3C;               // 1: 16 colours (half a byte per index)
};

// The global operator new of the units that include this header: from the texture
// manager, naming the place. It is defined after the class, so the creation function
// in the class body calls it out of line (e_rrletexture.cpp has a local copy) while
// code further on has it inlined. The line number (44) is the original's.
inline void* operator new(unsigned int size) {
    return lbl_802E5E1C->fn_80177EBC(size, "c:/eor/src2/games/sims/ESrc/e_rrletexture.h", 44,
                                     "ERRleTexture operator new");
}
// Placement new comes after the class as well (see above).
#include <new>

#endif
