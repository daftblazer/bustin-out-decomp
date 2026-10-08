#include "engine/e_storable.h"
#include "engine/e_resource.h"
#include "sims/e_rrletexture.h"

// The manager of the run-length encoded textures: its two overrides and the
// manager object itself.

// 0xC bytes; the first word is non-zero while the heap below may not be used.
struct Unk802F76EC {
    int unk0;
    int unk4;
    int unk8;
};
extern Unk802F76EC lbl_802F76EC;
struct EHeap {
    char unk0[0x70];
};
extern EHeap lbl_8033F710;

// 0x8003DE78
EHeap* Unk802E5E1C::GetHeap() {
    if (lbl_802F76EC.unk0 == 0) {
        return &lbl_8033F710;
    }
    return 0;
}

// 0x8003DE98
EResource* Unk802E5E1C::AllocateAndLoadResource(EFile* file, unsigned int, unsigned int) {
    ERRleTexture* texture = new ERRleTexture;
    texture->fn_8003E084(file);
    return texture;
}

// NON_MATCHING (static initialiser 0x8003DEF8): 27 instructions vs 22, as in
// sims/ECheats.cpp. The original only constructs the manager; here the compiler also
// emits the branch that destroys it and a _GLOBAL_.D function, because the class has
// a (virtual, implicit) destructor. All five compiler versions do this. A wrapper
// object without a destructor that constructs the manager in its own storage would
// give the original's code, but there is no evidence for one.
Unk802E5E1C lbl_802E5E1C;
