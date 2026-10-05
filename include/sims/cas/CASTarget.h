#ifndef SIMS_CAS_CASTARGET_H
#define SIMS_CAS_CASTARGET_H

#include "engine/UnkTargetBase.h"

void* fn_80169F1C(unsigned int size, int align); // aligned allocate
extern "C" void* fn_80111C78(void*, int, unsigned int); // memset

// The Create-A-Sim / Create-A-Family screen (0x5D30 bytes, ctor 0x80008AA0).
// Named after The Sims 2's CASTarget; whether this game used that exact name
// is not known.
class CASTarget : public UnkTargetBase {
public:
    CASTarget();
    virtual ~CASTarget();
    void fn_8000D010();
    void fn_8000F9D8();

    // Zero-filled on allocation.
    void* operator new(unsigned int size) {
        void* ptr = fn_80169F1C(size, 16);
        fn_80111C78(ptr, 0, size);
        return ptr;
    }

    char unk48[0x5D30 - 0x48];
};

#endif
