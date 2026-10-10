/* Apt runtime: value classes, their allocators and type tests. 0x8012F420-0x801352FC. Compiled at -O0. */
#include "ui/Apt.h"

/* 0x8012F420, 0x80131E8C, 0x80131EBC, ...: identity functions on an Apt value (they return their argument) */
struct AptSelf {
    AptSelf* Self() asm("fn_8012F420");
    AptSelf* Self2() asm("fn_80131E8C");
    AptSelf* Self3() asm("fn_80131EBC");
    AptSelf* Self4() asm("fn_80133480");
    AptSelf* Self5() asm("fn_801334B0");
    AptSelf* Self6() asm("fn_801334E0");
    AptSelf* Self7() asm("fn_80133510");
    int Const100() asm("fn_8013218C");
    int Const80() asm("fn_801321BC");
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

/* The identity functions at 0x80131E8C and 0x80131EBC */
AptSelf* AptSelf::Self2() { do { return this; } while (0); }
AptSelf* AptSelf::Self3() { do { return this; } while (0); }

/* 0x80131EEC: a defined value of type 1 */
int AptValue::isType01() const
{
    register int r = 0;
    if (getVtblIndex() == 1 && !isUndefined()) {
        r = 1;
    }
    return r; do { } while (0);
}

/* 0x80131F5C: a defined value of type 0xA */
int AptValue::isType0A() const
{
    register int r = 0;
    if (getVtblIndex() == 0xA && !isUndefined()) {
        r = 1;
    }
    return r; do { } while (0);
}

/* The instance node (0x60 bytes): +0x4C is its data block */
struct AptInst {
    char pad[0x4C];
    void* data;
    void* Data1() asm("fn_80131FCC");
    void* Data2() asm("fn_80131FF8");
    void* Data3() asm("fn_80133540");
    void* Data4() asm("fn_8013356C");
    void* Data5() asm("fn_80133598");
    void* Data6() asm("fn_801335C4");
    void* Data7() asm("fn_801335F0");
};
void* AptInst::Data1() { return data; }
void* AptInst::Data2() { return data; }

/* 0x80132024: a value of type 0xD (when the flag is clear it must be defined) */
int AptValue::isType0D(register int f) const
{
    register int r = 0;
    if (getVtblIndex() == 0xD && (f || !isUndefined())) {
        r = 1;
    }
    if (1) { return r; }
}

/* 0x8013209C: the same for type 0xE */
int AptValue::isType0E(register int f) const
{
    register int r = 0;
    if (getVtblIndex() == 0xE && (f || !isUndefined())) {
        r = 1;
    }
    if (1) { return r; }
}

/* 0x80132114: type 0xD or 0x12 */
int AptValue::isType0D12(register int f) const
{
    register int r = 0;
    if (isType0D(f) || isType12(f)) {
        r = 1;
    }
    if (1) { return r; }
}

/* 0x8013218C, 0x801321BC */
int AptSelf::Const100() { do { return 0x100; } while (0); }
int AptSelf::Const80() { return 0x80; }

/* the shared undefined value */
extern AptValue* lbl_8037D110;
/* 0x801329BC */
AptValue* fn_801329BC(int a, int b) asm("fn_801329BC");
AptValue* fn_801329BC(int a, int b) { do { return lbl_8037D110; } while (0); }

AptSelf* AptSelf::Self4() { do { return this; } while (0); }
AptSelf* AptSelf::Self5() { do { return this; } while (0); }
AptSelf* AptSelf::Self6() { do { return this; } while (0); }
AptSelf* AptSelf::Self7() { do { return this; } while (0); }

void* AptInst::Data3() { return data; }
void* AptInst::Data4() { return data; }
void* AptInst::Data5() { return data; }
void* AptInst::Data6() { return data; }
void* AptInst::Data7() { return data; }

/* 0x8013342C: drop a reference without freeing */
void AptValue::DecRef()
{
    setRefCount(getRefCount() - 1);
    return;
    return;
}

/* 0x8013361C: free a block of a known size through the user callbacks */
struct AptBlock {
    static void operator delete(register void* p, register unsigned n) asm("fn_8013361C");
};
void AptBlock::operator delete(register void* p, register unsigned n) { lbl_8033D1E0.freeSized(p, n); }

/* 0x80133674 ...: release a value of one type: drop a reference and, when none is left, tear it down in two steps */
#define APT_RELEASE(fn, step1, step2) \
    void* step1(AptValue*) asm(#step1); \
    void step2(void*) asm(#step2); \
    extern "C" void fn(register AptValue* v) \
    { \
        v->DecRef(); \
        if (v->getRefCount() == 0) { \
            step2(step1(v)); \
        } \
    }
APT_RELEASE(fn_80133674, fn_801346F8, fn_80134848)
APT_RELEASE(fn_801336D4, fn_80134728, fn_80134884)
APT_RELEASE(fn_80133734, fn_80134788, fn_801348C0)
APT_RELEASE(fn_80133794, fn_80134758, fn_801348FC)
APT_RELEASE(fn_801337F4, fn_801346C8, fn_80134938)
APT_RELEASE(fn_80133854, fn_80134818, fn_80134974)
APT_RELEASE(fn_801338B4, fn_801347E8, fn_801349BC)
