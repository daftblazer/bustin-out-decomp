/* Apt runtime: character instance constructor and allocation wrappers. 0x8012BFC4-0x8012C7C8. Compiled at -O0. */
#include "ui/Apt.h"

// 0x8012C188
int AptValue::isCIH(register int includeUndefined) const
{
    return getVtblIndex() > 0xB && getVtblIndex() <= 0x13 && (includeUndefined || !isUndefined());
}

// 0x8012C37C
int AptValue::isType12(register int includeUndefined) const
{
    register int r = 0;
    if (getVtblIndex() == 0x12) {
        if (includeUndefined || !isUndefined()) r = 1;
    }
    return r;
}
