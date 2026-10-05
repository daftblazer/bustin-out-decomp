#include "sims/Unk800052C8.h"

// 0x800052C8
Unk800052C8::Unk800052C8(unsigned int resourceId, int unk, Unk800052C8Source* source) {
    unk4 = source->unk0;
    unk10.Set(source->unk8, source->unkC, source->unk10);
    unk0 = unk;
    unkC = lbl_80340120.fn_80177628(resourceId, 0, 0);
    unk8 = new Unk8016BC18;
    lbl_802E67B0.unk0->unk1C->fn_80179D60(unk8, 0);
    unk8->fn_8016C750(unkC->unk4);
}

// 0x80005374
Unk800052C8::~Unk800052C8() {
    fn_80068DE8(&lbl_802E6700, unkC, unk8);
    unkC = 0;
    unk8 = 0;
    unk0 = 0;
}
