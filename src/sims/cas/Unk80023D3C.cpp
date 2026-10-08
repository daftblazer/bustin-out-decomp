#include "engine/e_texture.h"
#include "engine/e_shader.h"
#include "engine/e_rshader.h"
#include "engine/e_submodelshader.h"
#include "engine/e_submodel.h"
#include "engine/e_rmodel.h"
#include "engine/e_ranim.h"
#include "sims/cas/Unk80023D3C.h"
#include "sims/cas/CASSim.h"
#include "engine/EController.h"

extern "C" float fn_8010E450(float); // sinf
extern void (*lbl_8037C0CC)();

EColorF lbl_802E5AEC(0.43f, 0.08f, 0.08f, 0.75f);
EColorF lbl_802E5AFC(0.08f, 0.43f, 0.43f, 0.75f);
EColorF lbl_802E5B0C(0.25f, 0.25f, 0.25f, 0.75f);

// 0x80023D3C
// NON_MATCHING: six instructions at the entry are in a different order, exactly as in
// ~Unk800230AC (the original stores the vtable pointer before loading unkC4). Three
// variants tried.
Unk80023D3C::~Unk80023D3C() {
    if (unkC4) {
        fn_801767FC(unkC4);
        unkC4 = 0;
    }
}

// 0x80023DA4
// NON_MATCHING: 15 instructions, all in the pulsing-sprite block: the original keeps
// the screen height and the sprite height in f31 and the constant 40 and the width in
// f30; here the two registers are exchanged. Eleven arrangements of the locals tried.
void Unk80023D3C::vfn3(ERC* rc) {
    if (unk18 & 2) {
        if (unk18 & 4) {
            if (unk18 & 8) {
                // The focused button's sprite pulses behind it.
                EVec2 screen((float)lbl_8037C198->unk14, (float)lbl_8037C198->unk18);
                float pulse = (fn_8010E450(unkC0) * 0.5f + 1.0f) * 8.0f;
                EVec2 centre(unk2C.x + 16.0f / screen.x, unk2C.z + 16.0f / screen.y);
                float width = 40.0f / screen.x + pulse / screen.x;
                float height = 40.0f / screen.y + pulse / screen.y;
                unkC4->fn_80181824(rc);
                float x0 = centre.x - width * 0.5f;
                float y0 = centre.y - height * 0.5f;
                float y1 = y0 + height;
                float x1 = x0 + width;
                rc->vfn47(EVec2(x0, y0), EVec2(x1, y1), EVec2(0.0f, 1.0f), EVec2(1.0f, 0.0f), lbl_802E69C4, 0.0f);
            }
        }
        if (unk80) {
            unk80->SetSize(1, unk90, 1.0f);
            if (unk18 & 4) {
                if (unk18 & 8) {
                    unk80->unk64 = lbl_802E69C4;
                } else if (unk18 & 0x10) {
                    unk80->unk64 = lbl_802E6964;
                } else {
                    unk80->unk64 = lbl_802E69E4;
                }
            } else {
                if (unk18 & 8) {
                    unk80->unk64 = lbl_802E5AFC;
                } else if (unk18 & 0x10) {
                    unk80->unk64 = lbl_802E69E4;
                } else {
                    unk80->unk64 = lbl_802E5B0C;
                }
            }
            unk80->Select(rc);
            if (GetText() != 0) {
                const unsigned short* text = GetText();
                EVec2 at(unkB0.x + 0.005f, unkB0.z);
                unk80->DoDrawAlign(rc, text, 1, at, unk88, unk8C, 0);
            }
        }
        for (Unk801B4760Node* node = *(Unk801B4760Node**)&unk0; EIsValid(node); node = node->next) {
            Unk8018643C* child = node->item;
            if (child->unk18 & 2) {
                if (child->unk18 & 4) {
                    if (child->unk18 & 8) {
                        child->vfn19(rc, 0, lbl_802E69C4, 0);
                    } else if (unk18 & 0x10) {
                        child->vfn19(rc, 0, lbl_802E6964, 0);
                    } else {
                        child->vfn19(rc, 0, lbl_802E69E4, 0);
                    }
                } else {
                    if (child->unk18 & 8) {
                        child->vfn19(rc, 0, lbl_802E5AFC, 0);
                    } else if (unk18 & 0x10) {
                        child->vfn19(rc, 0, lbl_802E69E4, 0);
                    } else {
                        child->vfn19(rc, 0, lbl_802E5B0C, 0);
                    }
                }
            }
        }
    }
}

// 0x8002421C
void Unk80023D3C::vfn2() {
    EController* controller = lbl_8037C11C->fn_8015E5FC(lbl_8037C11C->fn_8015E614(0));
    if (controller->fn_8015E0F8(5)) {
        vfn7(this, unkBC);
        if (lbl_8037C0CC) {
            lbl_8037C0CC();
        }
    }
    unkC0 += lbl_8037BFC8 * 5.0f;
}
