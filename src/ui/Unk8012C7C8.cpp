/* Apt runtime: value header accessors and the native hash table. 0x8012C7C8-0x8012F420. Compiled at -O0. */
#include "ui/Apt.h"
#include <string.h>

extern AptValue* lbl_8037D110;  /* the shared "undefined" value */

// 0x8012C7C8
int AptValue::getVtblIndex() const { return header & 0x7FFF; }

// 0x8012C800
void AptValue::AddRef()
{
    if (this == lbl_8037D110 || isType0B() || isType18() || isType17()) {
    } else {
        setRefCount(getRefCount() + 1);
    }
}

// 0x8012C8A4
int AptValue::isUndefined() const { return getIsDefined() == 0; }

// 0x8012C8FC
AptValue::AptValue(register int type)
{
    setVtblIndex(type);
    setRefCount(0);
    setIsDefined(1);
}

// 0x8012C95C
int AptValue::getRefCount() const { APT_RETURN((header & 0xFFFF0000) >> 16); }

// 0x8012C998
int AptValue::getIsDefined() const { APT_RETURN(header & 0x8000); }

// 0x8012C9D0
void AptValue::setRefCount(register int n)
{
    do {
        header = header & 0xFFFF;
        header = header | (n << 16);
    } while (0);
}

// 0x8012CA18
void AptValue::setVtblIndex(register int t)
{
    do {
        header = header & ~0x7FFF;
        header = header | t;
    } while (0);
}

// 0x8012CA5C
void AptValue::setIsDefined(register int d)
{
    do {
        header = header & ~0x8000;
        if (d) header = header | 0x8000;
    } while (0);
}

// 0x8012CAA8
int AptValue::isType0B() const { APT_RETURN(getVtblIndex() == 0xB && !isUndefined()); }

// 0x8012CB18
int AptValue::isType18() const { APT_RETURN(getVtblIndex() == 0x18 && !isUndefined()); }

// 0x8012CB88
int AptValue::isType17() const { APT_RETURN(getVtblIndex() == 0x17 && !isUndefined()); }

// 0x8012CBF8
void* fn_8012CBF8(unsigned size, void* p, register int) { return p; }

// 0x8012CC2C
unsigned fn_8012CC2C(const char* s, unsigned seed)
{
    unsigned h = seed;
    unsigned c;
    do {
        c = (unsigned char)*s++;
        h = (h << 5) + h + c;
    } while (c);
    return h;
}

// 0x8012CCB0
AptNativeHash::~AptNativeHash()
{
    int i;
    for (i = 0; i < (1 << bits); i++) {
        if (items[i].key && items[i].key != lbl_8037D108) {
            APT_HANDLER(items[i].key)(items[i].key);
            APT_HANDLER(items[i].value)(items[i].value);
        }
    }
    lbl_8033D1E0.free(items);
    items = 0;
}

// 0x8012CE60
AptNativeHash::AptNativeHash(int n)
{
    bits = n;
    items = (AptHashItem*)lbl_8033D1E0.alloc(8 << bits);
    memset(items, 0, 8 << bits);
}

// 0x8012D9C4
char* AptString::GetInternalString() { return chars; }
