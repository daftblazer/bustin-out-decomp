#include "engine/e_texture.h"
#include "engine/e_shader.h"
#include "engine/e_rshader.h"
#include "engine/e_submodelshader.h"
#include "engine/e_submodel.h"
#include "engine/e_rmodel.h"
#include "engine/e_ranim.h"
#include "sims/cas/Unk800230AC.h"
#include "sims/EGlobal.h"
#include "engine/EController.h"

// 0x800230AC
// NON_MATCHING: six instructions at the entry are in a different order (the original
// stores the vtable pointer before loading unk7C; here the load is hoisted above the
// store). The rest, including the member destructors, is identical. Three variants
// tried (plain ifs, an inline member, a reference-taking helper).
Unk800230AC::~Unk800230AC() {
    if (unk7C) {
        fn_801767FC(unk7C);
        unk7C = 0;
    }
    if (unk80) {
        fn_801767FC(unk80);
        unk80 = 0;
    }
    if (unk84) {
        fn_801767FC(unk84);
        unk84 = 0;
    }
    if (unkDC8) {
        fn_801767FC(unkDC8);
        unkDC8 = 0;
    }
    int i;
    unk288[0].vfn15(&unk948);
    unk288[1].vfn15(&unk9C8);
    unk288[2].vfn15(&unkA48);
    unk288[3].vfn15(&unkAC8);
    for (i = 0; i < 4; i++) {
        unk88.vfn15(&unk288[i]);
    }
    unk5A8[0].vfn15(&unkBC8);
    unk5A8[1].vfn15(&unkC48);
    unk5A8[2].vfn15(&unkCC8);
    unk5A8[3].vfn15(&unkD48);
    for (i = 0; i < 4; i++) {
        unk188.vfn15(&unk5A8[i]);
    }
    vfn15(&unk88);
    vfn15(&unk188);
}

// 0x80023404
void Unk800230AC::vfn3(ERC* rc) {
    if (unk18 & 2) {
        if (unk70 == 2) {
            fn_80023488(rc);
        } else {
            fn_800236E4(rc);
        }
        if (unk48.AtEnd() && unk72) {
            fn_80188850(rc);
        }
    }
}

// 0x80023488
void Unk800230AC::fn_80023488(ERC* rc) {
    unk7C->fn_80181824(rc);
    rc->vfn47(EVec2(0.0f, 0.0f), EVec2(1.0f, unk54), EVec2(0.0f, 1.0f), EVec2(1.0f, 0.0f), EColorF(0.0f, 0.125f, 0.67f, 0.33f), 0.0f);
    unk80->fn_80181824(rc);
    rc->vfn49(EVec2(0.0f, unk54 - 0.1013f), EVec2(2.5f, 0.5f), EColorF(1.0f), 0.0f);
    rc->vfn49(EVec2(0.0f, unk54), EVec2(2.5f, 0.5f), EColorF(1.0f), 0.0f);
    if (unk70 == 1) {
        fn_80041180(rc, unk64, unk54 - 0.18485f, unk5C, 1.0f);
        fn_80041180(rc, 0.5f - unk6C * 0.5f, unk54 - 0.08f, unk6C, 1.0f);
    } else {
        fn_80041180(rc, unk60, unk54 - 0.18485f, unk58, 1.0f);
        fn_80041180(rc, 0.5f - unk68 * 0.5f, unk54 - 0.08f, unk68, 1.0f);
    }
}

// 0x800236E4
// NON_MATCHING: 306 instructions vs 305, 144 differing, same frame. In the family
// branch the original reaches its three temporaries through second copies of their
// addresses (r23-r25) and stores the caption position's y without reloading it; the
// other branch uses the first copies as here. Two variants tried (named locals with
// and without their own blocks).
void Unk800230AC::fn_800236E4(ERC* rc) {
    unk7C->fn_80181824(rc);
    rc->vfn47(EVec2(0.0f, 0.0f), EVec2(1.0f, 0.2f), EVec2(0.0f, 1.0f), EVec2(1.0f, 0.0f), EColorF(0.0f, 0.125f, 0.67f, 0.33f), 0.0f);
    unk80->fn_80181824(rc);
    rc->vfn49(EVec2(0.0f, 0.113f), EVec2(2.5f, 0.5f), EColorF(1.0f), 0.0f);
    rc->vfn49(EVec2(0.0f, 0.2f), EVec2(2.5f, 0.5f), EColorF(1.0f), 0.0f);
    if (unk70 == 1) {
        fn_80041180(rc, unk64, 0.0402f, unk5C, 1.0f);
        fn_80041180(rc, 0.5f - unk6C * 0.5f, 0.137f, unk6C, 1.0f);
        unkDC8->unk64 = lbl_802E6964;
        unkDC8->fn_8003C95C(1, 16.0f, 1.0f);
        unkDC8->fn_8003DBE8(rc);
        Unk800669ACResult result = lbl_802E6700.fn_800667EC("title");
        const unsigned short* text = (const unsigned short*)(result.ptr ? *result.ptr : 0);
        {
            EVec2 at(0.52f, 0.046f);
            unkDC8->fn_8003D740(rc, text, 1, at, 2, 0, 0);
        }
        {
            EVec2 position(0.5f - (unk5C - 0.04f) * 0.5f, 0.032f);
            unk84->fn_80181824(rc);
            rc->vfn49(position, EVec2(1.0f, 1.0f), EColorF(1.0f), 0.0f);
        }
    } else {
        fn_80041180(rc, unk60, 0.0358f, unk58, 1.0f);
        fn_80041180(rc, 0.5f - unk68 * 0.5f, 0.135f, unk68, 1.0f);
        unkDC8->unk64 = lbl_802E6964;
        unkDC8->fn_8003C95C(1, 16.0f, 1.0f);
        unkDC8->fn_8003DBE8(rc);
        Unk800669ACResult result = lbl_802E6700.fn_800667EC("create a family");
        const unsigned short* text = (const unsigned short*)(result.ptr ? *result.ptr : 0);
        {
            EVec2 at(0.52f, 0.07f);
            unkDC8->fn_8003D740(rc, text, 1, at, 2, 2, 0);
        }
        {
            EVec2 position(0.5f - (unk58 - 0.04f) * 0.5f, 0.032f);
            unk84->fn_80181824(rc);
            rc->vfn49(position, EVec2(1.0f, 1.0f), EColorF(1.0f), 0.0f);
        }
    }
}

// 0x80023BA8
void Unk800230AC::vfn2() {
    if (unkDCC && (unk18 & 4)) {
        unk48.Advance(lbl_8037BFC8);
        if (unk48.Cur() < unk48.Max()) {
            float t = 1.0f - unk48.Fraction();
            float lo = 0.0f;
            float hi = 0.2f;
            float eased = (-t * t * t + t * t + t) * hi + lo;
            if (unk72) {
                unk54 = eased;
            } else {
                unk54 = hi - eased;
            }
        } else if (!unk72) {
            unk48.Set(0.0f, 0.5f);
            unk70 = 2;
            unk72 = 1;
        } else {
            fn_801887C8();
            unk70 = unk71;
        }
    }
}
