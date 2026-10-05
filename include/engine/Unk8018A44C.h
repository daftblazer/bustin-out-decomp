#ifndef ENGINE_UNK8018A44C_H
#define ENGINE_UNK8018A44C_H

#include "engine/UnkTargetBase.h"

// Engine button (0xBC bytes; destructor 0x8018A44C, vtable 0x802BF8D8). The
// name is unknown.
class Unk8018A44C : public UnkTargetBase {
public:
    virtual ~Unk8018A44C();
    virtual void vfn2();
    virtual void vfn3(struct ERC* rc);

    char unk48[0xBC - 0x48];
};

#endif
