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

/* 0x8013071C: transform a point by a 2x3 matrix {a, b, c, d, tx, ty} (the movie's affine form):
   out.x = a * in.x + c * in.y + tx, out.y = b * in.x + d * in.y + ty */
struct AptPoint {
    float x;
    float y;
};
struct AptMatrix {
    float a, b, c, d, tx, ty;
};
void fn_8013071C(AptPoint* in, AptMatrix* m, AptPoint* out) asm("fn_8013071C");
void fn_8013071C(AptPoint* in, AptMatrix* m, AptPoint* out)
{
    out->x = m->a * in->x + m->c * *(&in->x + 1) + m->tx;
    *(&out->x + 1) = m->b * in->x + m->d * *(&in->x + 1) + m->ty;
    return;
    return;
}

/* The Apt player context (0x3F3C bytes, pointed to by lbl_8037D0F4). +0x3E24 counts the queued events and +0x3E28 holds them. */
struct AptPlayer {
    char pad[0x3E24];
    int eventCount;          /* 0x3E24 */
    unsigned events[1];      /* 0x3E28 */
    void Unk80131010(unsigned ev) asm("fn_80131010");
    void Unk801312E0(int a, int b, unsigned ev) asm("fn_801312E0");
    void Unk80131630(int a, int b, int* x, int* y) asm("fn_80131630");
    void Unk80131A10(int x, int a, int b) asm("fn_80131A10");
    void Unk80131D08(unsigned ev) asm("fn_80131D08");
    void Unk80131E04() asm("fn_80131E04");
};

/* 0x80131D08: run one queued event. The low two bits are its kind: 0 is handled by 0x80131010; 1 packs two fields
   (bits 17-31 and 10-16) and a third (bits 2-9) that are handed on. */
void AptPlayer::Unk80131D08(unsigned ev)
{
    int a;
    int b;
    int c;
    int q;
    int p;
    if ((ev & 3) == 0) {
        Unk80131010(ev);
    } else if ((ev & 3) == 1) {
        p = 0;
        a = (ev >> 17) & 0x7FFF;
        b = (ev >> 10) & 0x7F;
        c = (ev >> 2) & 0xFF;
        Unk801312E0(a, b, ev);
        Unk80131630(a, b, &p, &q);
        if (q == 0) {
            Unk80131A10(p, a, b);
        }
    }
    return;
    return;
    return;
}

/* 0x80131E04: run all queued events and clear the queue */
void AptPlayer::Unk80131E04()
{
    int i = 0;
    while (i < eventCount) {
        Unk80131D08(events[i]);
        i++;
    }
    eventCount = 0;
    return;
    return;
}

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

/* 0x80132854, 0x801328BC: release functions that keep their argument on the stack */
void fn_80133F70(AptValue*) asm("fn_80133F70");
void fn_80133FC0(AptValue*) asm("fn_80133FC0");
AptValue* fn_801334B0(AptValue*) asm("fn_801334B0");
AptValue* fn_801334E0(AptValue*) asm("fn_801334E0");
void fn_80132854(AptValue* v) asm("fn_80132854");
void fn_80132854(AptValue* v)
{
    v->DecRef();
    if (v->getRefCount() == 0) {
        fn_80133F70(fn_801334B0(v));
    }
    return;
    return;
}
void fn_801328BC(AptValue* v) asm("fn_801328BC");
void fn_801328BC(AptValue* v)
{
    v->DecRef();
    if (v->getRefCount() == 0) {
        fn_80133FC0(fn_801334E0(v));
    }
    return;
    return;
}

/* 0x80132924: release a value of the next type: drop a reference; at zero, tear down its parts in two steps */
AptValue* fn_8012C154(AptValue*, int) asm("fn_8012C154");
void fn_801330C8(AptValue*) asm("fn_801330C8");
void fn_80133A14(AptValue*) asm("fn_80133A14");
void fn_80132924(AptValue* v) asm("fn_80132924");
void fn_80132924(AptValue* v)
{
    v->DecRef();
    if (v->getRefCount() == 0) {
        if (!v->isUndefined()) {
            fn_801330C8(fn_8012C154(v, 0));
        }
        fn_80133A14(fn_8012C154(v, 1));
    }
    return;
    return;
}

/* 0x80132D9C: shut the Apt player down: release the shared values and the object tables */
extern char lbl_8033D2A8[];
extern AptValue* lbl_8037D108;
extern AptValue* lbl_8037D110;
extern AptValue* lbl_8037D114;
extern AptValue* lbl_8037D118;
extern AptValue* lbl_8037D11C;
extern AptValue* lbl_8037D120;
extern AptValue* lbl_8037D124;
extern AptValue* lbl_8037D128;
extern AptValue* lbl_8037D12C;
void fn_8014A9A8(void*) asm("fn_8014A9A8");
void fn_80134010(AptValue*) asm("fn_80134010");
void fn_80134060(AptValue*) asm("fn_80134060");
void fn_801340B0(AptValue*) asm("fn_801340B0");
void fn_801340F4(AptValue*) asm("fn_801340F4");
void fn_80134138(AptValue*) asm("fn_80134138");
void fn_80133ED8(AptValue*) asm("fn_80133ED8");
void fn_8013417C(AptValue*) asm("fn_8013417C");
void fn_80133914(AptValue*) asm("fn_80133914");
void fn_80132D9C(int unused) asm("fn_80132D9C");
void fn_80132D9C(int unused)
{
    fn_8014A9A8(lbl_8033D2A8);
    fn_80134010(lbl_8037D11C);
    fn_80134060(lbl_8037D120);
    fn_801340B0(lbl_8037D110);
    fn_801340F4(lbl_8037D128);
    fn_80134138(lbl_8037D124);
    fn_80133ED8(lbl_8037D12C);
    fn_8013417C(lbl_8037D108);
    lbl_8037D108 = 0;
    fn_80133914(lbl_8037D114);
    lbl_8037D114 = 0;
    fn_80133914(lbl_8037D118);
    lbl_8037D118 = 0;
    return;
    return;
}

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

/* classes that only carry a sized free */
struct AptFreeA { static void operator delete(register void* p, register unsigned n) asm("fn_80134AB4"); };
struct AptFreeB { static void operator delete(register void* p, register unsigned n) asm("fn_80134C98"); };
struct AptFreeC { static void operator delete(register void* p, register unsigned n) asm("fn_80134CF0"); };

/* empty functions that take only `this` */
struct AptNop {
    void Nop1() asm("fn_80133BDC");
    void Nop2() asm("fn_80133CA8");
    void Nop3() asm("fn_80133D84");
    void Nop4() asm("fn_80133E60");
};

/* ---- per-type boilerplate: delete wrappers, releases and allocators (0x80133914-) ---- */

#define APT_PROTO_DESTROY(fn) void fn(AptValue*, int) asm(#fn);

#define APT_PROTO_ID(fn) AptValue* fn(AptValue*) asm(#fn);

APT_PROTO_ID(fn_8012F420)
APT_PROTO_ID(fn_80133480)
APT_PROTO_ID(fn_80133510)
void fn_80133914(AptValue*) asm("fn_80133914");
void fn_8013395C(AptValue*) asm("fn_8013395C");
void fn_80133A14(AptValue*) asm("fn_80133A14");
void fn_80133A5C(AptValue*) asm("fn_80133A5C");
void fn_80133ABC(AptValue*) asm("fn_80133ABC");
void fn_80133B1C(AptValue*) asm("fn_80133B1C");
void fn_80133ED8(AptValue*) asm("fn_80133ED8");
void fn_80133F20(AptValue*) asm("fn_80133F20");
void fn_80133F70(AptValue*) asm("fn_80133F70");
void fn_80133FC0(AptValue*) asm("fn_80133FC0");
void fn_80134010(AptValue*) asm("fn_80134010");
void fn_80134060(AptValue*) asm("fn_80134060");
void fn_8013417C(AptValue*) asm("fn_8013417C");
void fn_80134448(AptValue*) asm("fn_80134448");
void fn_80134498(AptValue*) asm("fn_80134498");
void fn_801344E8(AptValue*) asm("fn_801344E8");
void fn_80134538(AptValue*) asm("fn_80134538");
void fn_80134588(AptValue*) asm("fn_80134588");
void fn_801345D8(AptValue*) asm("fn_801345D8");
void fn_80134628(AptValue*) asm("fn_80134628");
void fn_80134678(AptValue*) asm("fn_80134678");
void fn_80134974(AptValue*) asm("fn_80134974");
void fn_801349BC(AptValue*) asm("fn_801349BC");
void fn_80134BC0(AptValue*) asm("fn_80134BC0");
void fn_80134C08(AptValue*) asm("fn_80134C08");
void fn_80134C50(AptValue*) asm("fn_80134C50");
#define APT_PROTO_W(fn) void fn(AptValue*) asm(#fn);

/* 0x80133914: delete a value through its destructor */
APT_PROTO_DESTROY(fn_80134A04)
void fn_80133914(register AptValue* p)
{
    if (p) {
        fn_80134A04(p, 3);
    }
    return;
}

/* 0x8013395C: release a value of this type */
void fn_8013395C(register AptValue* v)
{
    v->DecRef();
    if (v->getRefCount() == 0) {
        fn_80133914(fn_80133480(v));
    }
}

/* 0x801339BC */
struct AptAlloc801339BC {
    static void* operator new(register unsigned n) asm("fn_801339BC");
};
void* AptAlloc801339BC::operator new(register unsigned n) { return lbl_8033D1E0.alloc(n); }

/* 0x80133A14: delete a value through its destructor */
APT_PROTO_DESTROY(fn_80132E40)
void fn_80133A14(register AptValue* p)
{
    if (p) {
        fn_80132E40(p, 3);
    }
    return;
}

/* 0x80133A5C: release a value of this type */
void fn_80133A5C(register AptValue* v)
{
    v->DecRef();
    if (v->getRefCount() == 0) {
        fn_80134BC0(fn_8012F420(v));
    }
}

/* 0x80133ABC: release a value of this type */
void fn_80133ABC(register AptValue* v)
{
    v->DecRef();
    if (v->getRefCount() == 0) {
        fn_80134C08(fn_80133510(v));
    }
}

/* 0x80133B1C: release a value of this type */
APT_PROTO_ID(fn_801347B8)
void fn_80133B1C(register AptValue* v)
{
    v->DecRef();
    if (v->getRefCount() == 0) {
        fn_80134C50(fn_801347B8(v));
    }
}

/* 0x80133B7C: the shared value of type 3: undefined, reference count 0x8000 (never freed) */
struct AptV3 : AptValue {
    AptV3() asm("fn_80133B7C");
};
AptV3::AptV3() : AptValue(3)
{
    setIsDefined(0);
    setRefCount(0 | 0x8000);
}

/* 0x80133BDC */
void AptNop::Nop1() {}

/* 0x80133BFC */
struct AptAlloc80133BFC {
    static void* operator new(register unsigned n) asm("fn_80133BFC");
};
void* AptAlloc80133BFC::operator new(register unsigned n) { return lbl_8033D1E0.alloc(n); }

/* 0x80133C54: the same for type 0xB */
struct AptV0B : AptValue {
    AptV0B() asm("fn_80133C54");
};
AptV0B::AptV0B() : AptValue(0xB)
{
    setRefCount(0 | 0x8000);
}

/* 0x80133CA8 */
void AptNop::Nop2() {}

/* 0x80133CC8 */
struct AptAlloc80133CC8 {
    static void* operator new(register unsigned n) asm("fn_80133CC8");
};
void* AptAlloc80133CC8::operator new(register unsigned n) { return lbl_8033D1E0.alloc(n); }

/* 0x80133D20: the same for type 0x17, which also owns a hash of 16 slots */
struct AptV17 : AptValue, AptNativeHash {
    AptV17() asm("fn_80133D20");
};
AptV17::AptV17() : AptValue(0x17), AptNativeHash(4)
{
    setRefCount(0 | 0x8000);
}

/* 0x80133D84 */
void AptNop::Nop3() {}

/* 0x80133DA4 */
struct AptAlloc80133DA4 {
    static void* operator new(register unsigned n) asm("fn_80133DA4");
};
void* AptAlloc80133DA4::operator new(register unsigned n) { return lbl_8033D1E0.alloc(n); }

/* 0x80133E60 */
void AptNop::Nop4() {}

/* 0x80133E80 */
struct AptAlloc80133E80 {
    static void* operator new(register unsigned n) asm("fn_80133E80");
};
void* AptAlloc80133E80::operator new(register unsigned n) { return lbl_8033D1E0.alloc(n); }

/* 0x80133ED8: delete a value through its destructor */
APT_PROTO_DESTROY(fn_80134B68)
void fn_80133ED8(register AptValue* p)
{
    if (p) {
        fn_80134B68(p, 3);
    }
    return;
}

/* 0x80133F20: delete a value through its destructor */
APT_PROTO_DESTROY(fn_80134A5C)
void fn_80133F20(register AptValue* p)
{
    if (p) {
        fn_80134A5C(p, 3);
    }
    return;
    return;
    return;
}

/* 0x80133F70: delete a value through its destructor */
APT_PROTO_DESTROY(fn_80134B0C)
void fn_80133F70(register AptValue* p)
{
    if (p) {
        fn_80134B0C(p, 3);
    }
    return;
    return;
    return;
}

/* 0x80133FC0: delete a value through its destructor */
APT_PROTO_DESTROY(fn_801353F0)
void fn_80133FC0(register AptValue* p)
{
    if (p) {
        fn_801353F0(p, 3);
    }
    return;
    return;
    return;
}

/* 0x80134010: delete a value through its destructor */
APT_PROTO_DESTROY(fn_80134D48)
void fn_80134010(register AptValue* p)
{
    if (p) {
        fn_80134D48(p, 3);
    }
    return;
    return;
    return;
}

/* 0x80134060: delete a value through its destructor */
APT_PROTO_DESTROY(fn_801352FC)
void fn_80134060(register AptValue* p)
{
    if (p) {
        fn_801352FC(p, 3);
    }
    return;
    return;
    return;
}

/* 0x801340B0 */
void fn_801340B0(register AptValue* p)
{
    AptFreeB::operator delete(p, 4);
    return;
    return;
}

/* 0x801340F4 */
void fn_801340F4(register AptValue* p)
{
    AptFreeC::operator delete(p, 4);
    return;
    return;
}

/* 0x80134138 */
void fn_80134138(register AptValue* p)
{
    AptFreeA::operator delete(p, 0x3C0);
    return;
    return;
}

/* 0x8013417C: delete a value through its destructor */
APT_PROTO_DESTROY(fn_8014FE18)
void fn_8013417C(register AptValue* p)
{
    if (p) {
        fn_8014FE18(p, 3);
    }
    return;
    return;
    return;
}

/* 0x801341CC */
void fn_801354D8(void*, unsigned) asm("fn_801354D8");
void fn_801341CC(register AptValue* p)
{
    fn_801354D8(p, 0x30);
}

/* 0x80134448: delete a value through its destructor */
APT_PROTO_DESTROY(fn_80135860)
void fn_80134448(register AptValue* p)
{
    if (p) {
        fn_80135860(p, 3);
    }
    return;
    return;
    return;
}

/* 0x80134498: delete a value through its destructor */
APT_PROTO_DESTROY(fn_80135A88)
void fn_80134498(register AptValue* p)
{
    if (p) {
        fn_80135A88(p, 3);
    }
    return;
    return;
    return;
}

/* 0x801344E8: delete a value through its destructor */
APT_PROTO_DESTROY(fn_801357F8)
void fn_801344E8(register AptValue* p)
{
    if (p) {
        fn_801357F8(p, 3);
    }
    return;
    return;
    return;
}

/* 0x80134538: delete a value through its destructor */
APT_PROTO_DESTROY(fn_801359D8)
void fn_80134538(register AptValue* p)
{
    if (p) {
        fn_801359D8(p, 3);
    }
    return;
    return;
    return;
}

/* 0x80134588: delete a value through its destructor */
APT_PROTO_DESTROY(fn_8013853C)
void fn_80134588(register AptValue* p)
{
    if (p) {
        fn_8013853C(p, 3);
    }
    return;
    return;
    return;
}

/* 0x801345D8: delete a value through its destructor */
APT_PROTO_DESTROY(fn_80135A30)
void fn_801345D8(register AptValue* p)
{
    if (p) {
        fn_80135A30(p, 3);
    }
    return;
    return;
    return;
}

/* 0x80134628: delete a value through its destructor */
APT_PROTO_DESTROY(fn_80135AE0)
void fn_80134628(register AptValue* p)
{
    if (p) {
        fn_80135AE0(p, 3);
    }
    return;
    return;
    return;
}

/* 0x80134678: delete a value through its destructor */
APT_PROTO_DESTROY(fn_80135530)
void fn_80134678(register AptValue* p)
{
    if (p) {
        fn_80135530(p, 3);
    }
    return;
    return;
    return;
}

/* 0x80134974: delete a value through its destructor */
APT_PROTO_DESTROY(fn_80135CF0)
void fn_80134974(register AptValue* p)
{
    if (p) {
        fn_80135CF0(p, 3);
    }
    return;
}

/* 0x801349BC: delete a value through its destructor */
APT_PROTO_DESTROY(fn_8012F564)
void fn_801349BC(register AptValue* p)
{
    if (p) {
        fn_8012F564(p, 3);
    }
    return;
}

/* 0x80134AB4: free a block of a known size */
void AptFreeA::operator delete(register void* p, register unsigned n) { lbl_8033D1E0.freeSized(p, n); }

/* 0x80134BC0: delete a value through its destructor */
APT_PROTO_DESTROY(fn_8012DA50)
void fn_80134BC0(register AptValue* p)
{
    if (p) {
        fn_8012DA50(p, 3);
    }
    return;
}

/* 0x80134C08: delete a value through its destructor */
APT_PROTO_DESTROY(fn_80135EAC)
void fn_80134C08(register AptValue* p)
{
    if (p) {
        fn_80135EAC(p, 3);
    }
    return;
}

/* 0x80134C50: delete a value through its destructor */
APT_PROTO_DESTROY(fn_80136410)
void fn_80134C50(register AptValue* p)
{
    if (p) {
        fn_80136410(p, 3);
    }
    return;
}

/* 0x80134C98 */
void AptFreeB::operator delete(register void* p, register unsigned n) { lbl_8033D1E0.freeSized(p, n); }

/* 0x80134CF0 */
void AptFreeC::operator delete(register void* p, register unsigned n) { lbl_8033D1E0.freeSized(p, n); }
