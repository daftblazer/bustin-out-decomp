/* Apt: Electronic Arts' ActionScript/Flash runtime, 0x8012AD10-0x80151F80.
   Compiled at -O0. Member functions carry an asm label with their fn_XXXXXXXX name so
   symbols.txt does not have to change; the comment next to each says what it is
   (names from The Sims 2's symbol map where the structure agrees). */
#ifndef UI_APT_H
#define UI_APT_H

/* After a constructor (or a function that returns a local) the compiler emits only the one
   branch to the epilogue for a `return`; the original has the usual three in places, which
   `do { return x; } while (0)` reproduces. Void functions get their two the same way. */
#define APT_RETURN(x) do { return (x); } while (0)

struct AptValue;

/* User callbacks the host fills in at 0x8033D1E0 (.bss, 0x7C bytes). */
struct AptUserFunctions {
    void* (*alloc)(unsigned size);              /* 0x00 */
    void (*free)(void* p);                      /* 0x04 */
    void (*freeSized)(void* p, unsigned size);  /* 0x08: defaults to fn_8012AD10 (calls free) */
    void* slotC[4];
    void (*slot1C)(char*);                      /* 0x1C */
    void* rest[25];
};
extern AptUserFunctions lbl_8033D1E0;

/* The header word of every Apt value (reference-counted object).
   bits 0-14: type, index into the per-type handler table at 0x802D67B4
   bit 15 (0x8000): "defined" flag, set by the constructor
   bits 16-31: reference count */
struct AptValue {
    unsigned header;

    AptValue(int type) asm("fn_8012C8FC");
    int getVtblIndex() const asm("fn_8012C7C8");
    int isUndefined() const asm("fn_8012C8A4");
    int getRefCount() const asm("fn_8012C95C");
    int getIsDefined() const asm("fn_8012C998");
    void setRefCount(int n) asm("fn_8012C9D0");
    void setVtblIndex(int t) asm("fn_8012CA18");
    void setIsDefined(int d) asm("fn_8012CA5C");
    void AddRef() asm("fn_8012C800");
    int isType0B() const asm("fn_8012CAA8");
    int isType18() const asm("fn_8012CB18");
    int isType17() const asm("fn_8012CB88");
    int isCIH(int includeUndefined) const asm("fn_8012C188");
    int isType12(int includeUndefined) const asm("fn_8012C37C");
};

/* Slot of an AptNativeHash: key is an AptString, value any AptValue. */
struct AptHashItem {
    AptValue* key;    /* 0 = empty, lbl_8037D108 = deleted */
    AptValue* value;
};

/* The strings are AptValues too: +4 is the characters. */
struct AptString {
    unsigned header;
    char* chars;
    char* GetInternalString() asm("fn_8012D9C4");
};

/* Open-addressing hash table of 1 << bits slots, at most 16 probes before it doubles. */
struct AptNativeHash {
    int bits;            /* 0x00 */
    AptHashItem* items;  /* 0x04 */

    AptNativeHash(int n) asm("fn_8012CE60");
    ~AptNativeHash();   /* 0x8012CCB0, symbol _._13AptNativeHash */
    AptHashItem* GetFirstItem() asm("fn_8012D878");
    AptHashItem* GetNextItem(AptHashItem* item) asm("fn_8012D934");
};

extern void (*lbl_802D67B4[0x1D])(AptValue*);  /* per-type release handlers, index = AptValue type */
/* the handler for value v, as the original reads it: base + type * 4 */
#define APT_HANDLER(v) (*(void (**)(AptValue*))((char*)lbl_802D67B4 + (v)->getVtblIndex() * 4))

extern AptValue* lbl_8037D108;                   /* marks a deleted hash slot */

unsigned fn_8012CC2C(const char* s, unsigned seed) asm("fn_8012CC2C");   /* hash of a string: h = h * 33 + c */
void* fn_8012CBF8(unsigned size, void* p, int) asm("fn_8012CBF8");        /* placement new */

#endif
