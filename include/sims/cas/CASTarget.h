#ifndef SIMS_CAS_CASTARGET_H
#define SIMS_CAS_CASTARGET_H

void* fn_80169F1C(unsigned int size, int align); // aligned allocate
extern "C" void* fn_80111C78(void*, int, unsigned int); // memset

// Base of the game's screen objects: 0x44 bytes of data, then the vtable
// pointer (ctor 0x8018867C, dtor 0x80188754). Real name unknown; the screens
// built on it are called "...Target" in The Sims 2's symbol map.
class UnkTargetBase {
public:
    UnkTargetBase();
    virtual ~UnkTargetBase(); // slot 1
    virtual void vfn2();
    virtual void vfn3();      // per-frame update

    char unk0[0x44];
};

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
