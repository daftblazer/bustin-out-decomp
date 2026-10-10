/* Apt runtime: value classes, their allocators and type tests. 0x8012F420-0x801352FC. Compiled at -O0. */
#include "ui/Apt.h"

/* 0x8012F420, 0x80131E8C, 0x80131EBC, ...: identity functions on an Apt value (they return their argument) */
struct AptSelf {
    AptSelf* Self() asm("fn_8012F420");
};
AptSelf* AptSelf::Self() { if (1) { return this; } }

/* 0x8012F450: a value of type 0x16 that is defined */
extern "C" int fn_8012F450(register AptValue* v)
{
    register int r = 0;
    if (v->getVtblIndex() == 0x16 && !v->isUndefined()) {
        r = 1;
    }
    if (1) { return r; }
}

/* 0x8012F4C0: a value of type 7 holding one word (+4) */
struct AptWord : AptValue {
    int word;
    AptWord(register int w) asm("fn_8012F4C0");
    static void* operator new(register unsigned n) asm("fn_8012F50C");
};

AptWord::AptWord(register int w) : AptValue(7)
{
    word = w;
}

/* 0x8012F50C */
void* AptWord::operator new(register unsigned n) { return lbl_8033D1E0.alloc(n); }

/* 0x8012F5C0: a value that owns a native hash of 1 << bits slots at +4 */
struct AptObject : AptValue, AptNativeHash {
    AptObject(register int type, register int bits) asm("fn_8012F5C0");
    static void* operator new(register unsigned n) asm("fn_8012F66C");
    static void operator delete(register void* p, register unsigned n) asm("fn_8012F774");
};

AptObject::AptObject(register int type, register int bits) : AptValue(type), AptNativeHash(bits) {}

/* 0x8012F564 */
/* 0x8012F564: destroy an object value; flag bit 0 also frees it. The hash destructor is called with flag 0
   (called as a plain function so the flag is ours to choose). */
void AptObjectDtor(AptNativeHash* h, int flag) asm("_._13AptNativeHash");
extern "C" void fn_8012F564(register AptObject* self, register int flags)
{
    AptObjectDtor((AptNativeHash*)((char*)self + 4), 0);
    if (flags & 1) {
        AptObject::operator delete(self, 0xC);
    }
}

/* 0x8012F61C: an object value of type 9 with 16 slots and one more word at +0xC */
struct AptFunc : AptObject {
    int word;
    AptFunc(register int w) asm("fn_8012F61C");
    static void* operator new(register unsigned n) asm("fn_8012F6C4");
    static void operator delete(register void* p, register unsigned n) asm("fn_8012F71C");
};
AptFunc::AptFunc(register int w) : AptObject(9, 4)
{
    word = w;
}

/* 0x8012F66C */
void* AptObject::operator new(register unsigned n) { return lbl_8033D1E0.alloc(n); }

/* 0x8012F774 */
void AptObject::operator delete(register void* p, register unsigned n) { lbl_8033D1E0.freeSized(p, n); }

/* 0x8012F6C4 */
void* AptFunc::operator new(register unsigned n) { return lbl_8033D1E0.alloc(n); }

/* 0x8012F71C */
void AptFunc::operator delete(register void* p, register unsigned n) { lbl_8033D1E0.freeSized(p, n); }
