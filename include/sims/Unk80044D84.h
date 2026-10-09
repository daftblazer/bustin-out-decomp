#ifndef SIMS_UNK80044D84_H
#define SIMS_UNK80044D84_H

#include "sims/Unk800401FC.h"

// A dialog that only shows a text for a while and takes no answer (0xFC bytes): the
// dialog class with a timer. The name is unknown.
class Unk80044D84 : public Unk80040274 {
public:
    virtual ~Unk80044D84();                                      // 0x800453FC
    virtual void vfn2();
    virtual void vfn3(ERC* rc);
    virtual void vfn18() { delete this; }                        // 0x8004546C
    virtual void vfn26(struct Unk800424F0Source* source, unsigned char* b);   // 0x80044D84

    void fn_80044F6C();
    void operator delete(void* ptr);                            // 0x8004544C

    int unkF4;                        // 1 while it is showing
    float unkF8;                      // seconds left
};

#endif
