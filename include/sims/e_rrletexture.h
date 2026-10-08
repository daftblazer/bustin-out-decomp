#ifndef SIMS_E_RRLETEXTURE_H
#define SIMS_E_RRLETEXTURE_H

// The run-length encoded texture resource (c:/eor/src2/games/sims/ESrc/e_rrletexture.h).
// Reconstructed from the strings its inline functions leave in every unit that
// includes it; the functions themselves are not known yet, so each string is
// carried by a stand-in. The file name comes from the __FILE__ string.

inline const char* ERRleTextureHeaderString0() { return "ERRleTexture"; }

#include "engine/EStorable.h"
#include "engine/ResourceManagers.h"

// The class as far as it is known (0x40 bytes; constructor 0x8003DF9C). Its operator
// new allocates from the texture manager and names the place it was called from;
// that is where the header's file name and the third string come from. The line
// number (44) is the original's.
class ERRleTexture : public EResource {
public:
    ERRleTexture();
    virtual ~ERRleTexture();
    void fn_8003E084(EFile* file);                        // load

    void* operator new(unsigned int size) {
        return lbl_802E5E1C.fn_80177EBC(size, "c:/eor/src2/games/sims/ESrc/e_rrletexture.h", 44,
                                        "ERRleTexture operator new");
    }

    char unk18[0x40 - 0x18];
};

#endif
