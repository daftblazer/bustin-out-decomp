#include "engine/e_storable.h"
#include "engine/e_resource.h"
#include "engine/e_rfont.h"
#include "engine/e_texture.h"
#include "engine/e_shader.h"
#include "engine/e_rshader.h"
#define EOR_BUILD_TIME "21:41:27"
#include "engine/e_engine.h"
#include "sims/e_simsapp_title.h"
#include "sims/cas/CASTarget.h"
#include "sims/cas/CASSim.h"
#include "sims/EGlobal.h"
#include "engine/EController.h"
#include "engine/E3DWindow.h"

extern "C" void* fn_80111C78(void* dst, int value, unsigned int size); // memset

// 0x80039E78
Unk80039E78::Unk80039E78() : unk14(unk1C, 0x400) {
    unk0 = 0;
    unk838 = 0;
    unk4 = 0;
}

// 0x80039ED0
Unk80039E78::~Unk80039E78() {
    fn_8003A6AC();
}

// 0x80039F1C
void Unk80039E78::fn_80039F1C() {
    if (unk0) {
        fn_801767FC(unk0);
        unk0 = 0;
    }
    unk0 = (Unk8003C95C*)lbl_8033F964.fn_80177628(lbl_802E6700.fn_800655D8(), 0, 0);
    EVec2 screen((float)lbl_8037C198->unk14, (float)lbl_8037C198->unk18);
    unk83C = EVec2(0.6f, 0.5f);
    unk844 = EVec2(0.2f, 0.15f);
    unk4 = lbl_80340AB8.fn_80177628(0xDA8131BB, 0, 0);
    unk82C = 0;
    unk10 = 0;
    unk8 = 0.0f;
    unk14.fn_8023C8CC();
    unk81C = 0;
    unk820 = 0;
    unk86C = EVec2(10.0f / screen.x, 4.0f / screen.y);
    unk838 = new E3DWindow;
}

// Height of the list of choices. Inline in the original (its result slot is not
// shared with the caller's locals); it belongs in the class as a member.
inline float M39Height(Unk80039E78* self) {
    float height = 0.0f;
    for (unsigned int i = 0; i < self->unk888; i++) {
        height += self->unk0->fn_8003D550((const unsigned short*)self->unk884[i], 1, 0).y;
        if (i < self->unk888 - 1) {
            height += self->unk0->fn_8003DC1C(0);
        }
    }
    return height;
}

// 0x8003A0C0
// Opens the box: stores the text and the choices and lays everything out.
// NON_MATCHING: same length (272), 17 instructions, all in the window rectangle at
// the end: the original computes and stores it in the order x1, x0, y0, y1, here
// x1, y1, x0, y0. About sixty variants tried (all 24 orders of named locals, all 24
// orders of assignments in a constructor body, inline helpers, vector forms).
void Unk80039E78::fn_8003A0C0(EVec2* position, int count, int* items, int text, int copy, int cancel, float width) {
    unk834 = cancel;
    unk844 = *position;
    unk83C.x = width;
    unk888 = count;
    unk884 = items;
    unkC = copy;
    if (copy) {
        unk14.fn_8023C8CC();
        unk14.fn_8023C8DC((const unsigned short*)text, 0x3FF);
    } else {
        unk10 = (const unsigned short*)text;
    }
    unk828 = 0;
    EVec2 screen((float)lbl_8037C198->unk14, (float)lbl_8037C198->unk18);
    unk854 = EVec2(0.0f, 0.0f);
    unk84C = EVec2(unk83C.x - 32.0f / screen.x, 0.0f);
    unk87C = EVec2(unk854.x + unk86C.x, unk854.y + unk86C.y + unk878);
    unk81C = 0;
    unk824 = 0;
    unk0->fn_8003C95C(1, 16.0f, 1.0f);
    unk0->unk64 = lbl_802E6964;
    fn_8003A734(0, 0, 0);
    float extentY;
    if (unkC) {
        extentY = unk0->fn_8003D550(unk14.fn_8023C9EC(), 1, 0).y;
    } else {
        extentY = unk0->fn_8003D550(unk10, 1, 0).y;
    }
    unk84C.y = (float)unk824 * (extentY + unk0->fn_8003DC1C(0)) + (unk86C.y + unk86C.y);
    if (unk824 == 1) {
        unk830 = unk824;
    } else {
        unk830 = 0;
    }
    EVec2 margin(5.0f / screen.x, 5.0f / screen.y);
    EVec2 box(0.0f, 0.0f);
    box = unk84C;
    unk85C = box.x;
    float height = M39Height(this);
    unk860 = height;
    box.y += height + margin.y;
    EVec2 at(unk844.x + 16.0f / screen.x, unk844.y + 16.0f / screen.y);
    unk83C.y = box.y + 32.0f / screen.y;
    unk854 = at;
    at.y += unk84C.y + margin.y;
    unk864 = at;
    ERectF rect(unk854.x + unk86C.x - 1.0f / screen.x, unk854.y + unk86C.y - 1.0f / screen.y,
                unk854.x + unk84C.x - unk86C.x + 1.0f / screen.x, unk854.y + unk84C.y - unk86C.y + 1.0f / screen.y);
    unk838->fn_8018B584(rect);
}

// 0x8003A500
// Handles the buttons: -2 cancelled, -1 still open, otherwise the choice made.
int Unk80039E78::fn_8003A500() {
    if (!((UnkViewer*)lbl_802E6700.unk90)->fn_801082CC()) {
        return 0;
    }
    EController* controller = lbl_8037C11C->fn_8015E5FC(lbl_8037C11C->fn_8015E614(lbl_802E6700.unk138));
    if (controller->fn_8015E0F8(7)) {
        if (unk834 == 1 && lbl_8037D96C) {
            lbl_8037D96C->fn_8006186C(0x048AE94F);
        }
        return -2;
    }
    if (controller->fn_8015E0F8(5)) {
        if (lbl_8037D96C) {
            lbl_8037D96C->fn_8006186C(0xCF99DB1E);
        }
        return unk828;
    }
    if (controller->fn_8015E0F8(1)) {
        unk828--;
        if (unk828 < 0) {
            unk828 = 0;
        } else if (lbl_8037D96C) {
            lbl_8037D96C->fn_8006186C(0x867A1F00);
        }
    } else if (controller->fn_8015E0F8(2)) {
        unk828++;
        if ((unsigned int)unk828 > unk888 - 1) {
            unk828 = unk888 - 1;
        } else if (lbl_8037D96C) {
            lbl_8037D96C->fn_8006186C(0x867A1F00);
        }
    }
    unk8 += lbl_8037BFC8 * 5.0f;
    if (unk8 > 6.2831855f) {
        unk8 = 0.0f;
    }
    return -1;
}

// 0x8003A6AC
void Unk80039E78::fn_8003A6AC() {
    if (unk0) {
        fn_801767FC(unk0);
        unk0 = 0;
    }
    if (unk4) {
        fn_801767FC(unk4);
        unk4 = 0;
    }
    if (unk838) {
        delete unk838;
        unk838 = 0;
    }
}

// 0x8003A734
// Breaks the text into lines that fit the box and, with `draw`, draws the ones from
// unk820 on (left aligned, or centred); the lines skipped are counted in unk824.
// NON_MATCHING: same length (206), 73 instructions differ, nearly all register
// numbers: the original has `this` in r30 and the text pointer in r29 (here r29 and
// r28) and keeps the address of the extent's return slot in r28. The line buffer is
// at the bottom of the original's frame and the unused extent at 0x208; here the
// extent comes out below the buffer. About fourteen variants tried (scopes of the
// buffer, the extent and the terminator; forms of the two selections at the start).
void Unk80039E78::fn_8003A734(ERC* rc, int draw, int centred) {
    if (unkC == 0 ? unk10 == 0 : unk14.fn_8023C8A8() == 0) {
        return;
    }
    if (draw) {
        unk0->fn_8003DBE8(rc);
    }
    float width = unk84C.x - (unk86C.x + unk86C.x);
    float left = unk87C.x;
    float lineHeight = unk0->fn_8003DC1C(0);
    const unsigned short* text = unkC ? unk14.fn_8023C9EC() : unk10;
    EVec2 size;
    unsigned short zero = 0;
    while (*text != 0) {
        unsigned short line[0x100];
        fn_80111C78(line, 0, sizeof(line));
        int length = 0;
        bool ended = false;
        unsigned short* out = line;
        int lastBreak = 0;
        while (*text != 0 && !ended) {
            *out = *text;
            if (*text == 10) {
                text++;
                ended = true;
            } else {
                size = unk0->fn_8003D550(out, 1, 0);
                if (fn_800430EC(*text)) {
                    lastBreak = length;
                }
                bool over = unk0->fn_8003D550(line, 1, 0).x > width;
                if (over) {
                    ended = true;
                    int back = length - lastBreak;
                    if (back != 0) {
                        if (length == back) {
                            back = 0;
                            text--;
                        }
                        length -= back;
                        text -= back;
                        line[length] = zero;
                    } else {
                        line[length] = back;
                    }
                    length--;
                }
                length++;
                out++;
                text++;
                if (length > 0xFD) {
                    break;
                }
            }
        }
        if (ended || line[0] != 0) {
            line[length] = zero;
            if (unk824 >= unk820 && draw) {
                if (centred == 0) {
                    unk0->fn_8003D740(rc, line, 1, unk87C, 0, 0, (int)&unk87C);
                } else {
                    EVec2 at(unk84C.x * 0.5f + unk854.x, unk87C.y);
                    unk0->fn_8003D740(rc, line, 1, at, 2, 0, (int)&unk87C);
                }
                unk87C.x = left;
                unk87C.y += lineHeight;
                if (unk87C.y > unk854.y + unk84C.y - unk86C.y - unk878) {
                    unk81C = 1;
                }
            } else {
                unk824++;
            }
        }
    }
}
