#ifndef SIMS_UNK8003E844_H
#define SIMS_UNK8003E844_H

// What a request to the background loader is for: an interface of sixteen virtuals
// with defaults (vtable 0x80298848). It is defined ahead of the engine headers (its
// empty string opens the .rodata of sims/Unk8003E844.cpp).
//
// Its vtable and virtuals exist once in the binary, as *globals* at the end of that
// file, and engine code uses that copy. Compiled like this they are emitted in the
// right place but as local symbols, so the file cannot be linked from source yet.
// See "Inline virtuals shared between units" in CLAUDE.md for what was tried.
class Unk80298848 {
public:
    virtual ~Unk80298848() {}
    virtual int vfn2(int, int) { return 0; }
    virtual int vfn3(int, int) { return 0; }
    virtual int vfn4(int) { return 0; }
    virtual int vfn5() { return 0; }
    virtual int vfn6() { return 0; }
    virtual int vfn7() { return 13; }
    virtual int vfn8() { return 8; }
    virtual int vfn9() { return 2; }
    virtual int vfn10() { return 7; }
    virtual const char* vfn11() { return ""; }
    virtual const char* vfn12() { return ""; }
    virtual const char* vfn13() { return ""; }
    virtual const char* vfn14() { return ""; }
    virtual int vfn15() { return 0; }
    virtual void vfn16() {}
};

#endif
