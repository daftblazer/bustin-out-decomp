#include "engine/e_storable.h"
#include "engine/e_resource.h"
#include "engine/e_rfont.h"
#include "engine/e_texture.h"
#include "engine/e_shader.h"
#include "engine/e_rshader.h"
#include "engine/ERFont.h"
#include "engine/ResourceManagers.h"
#include "engine/ENew.h"

// ERFont: the engine's bitmap font.

struct Unk80181824 {
    void fn_80181824(ERC* rc);   // select a texture
};
void fn_80160508(EFontSize* size);                    // delete a size record
EFile& fn_801BA4A8(EFile& file, int& value);             // file >> int
EFile& fn_801B8ECC(EFile& file, ERFontSizeList& list);   // file >> list of sizes

// The screen the fonts are scaled for.
struct Unk8037C198Screen {
    char unk0[0x14];
    int unk14;   // width
    int unk18;   // height
};
extern Unk8037C198Screen* lbl_8037C198;
struct EWindow {
    float unk0;              // width
    char unk4[0x10];
    float unk14;             // height
};
extern EWindow* lbl_8037C0DC;

static EVec2 lbl_8037CA94(1.0f, 1.0f);
EStorableClass lbl_803795A8;
static int lbl_8037CA9C = fn_801BBFCC(&lbl_803795A8, fn_8003DD38, fn_8003DD60, fn_8003DD8C, 0,
                                      "ERFont", &lbl_803794E0);

// Sets all four components of a colour (in the original presumably a member of the
// colour class; alpha is stored first).
inline void ERFontSetColor(EColorF& colour, float value) {
    colour.r = colour.g = colour.b = colour.a = value;
}

// 0x8003C784
ERFont::ERFont() {
    unk60 = 0;
    unk5C = 1.0f;
    unk58 = -1.0f;
    ERFontSetColor(unk64, 1.0f);
    unk74 = -1;
}

// 0x8003C804
ERFont::~ERFont() {
    Deallocate();
}

// 0x8003C868
void ERFont::Deallocate() {
    for (ERFontSizeNode* node = unk20.head; node; node = node->next) {
        fn_80160508(node->item);
    }
}

// 0x8003C8AC
void ERFont::vfn10(EFile& file) {
    unk60 = 0;
    Load(file);
}

// 0x8003C8D4
void ERFont::Load(EFile& file) {
    Deallocate();
    fn_801BA4A8(file, unk18);
    fn_801B8ECC(file, unk20);
    if (unk20.head) {
        unk60 = unk20.head->item;
        unk58 = (float)unk60->unk4;
    }
}

inline float EFabs(float value) { return __builtin_fabsf(value); }

// 0x8003C95C
// Sets the size and aspect to draw at; with `pick` also chooses the size record
// closest to it (preferring a larger one, or a smaller one within a factor of two).
// NON_MATCHING: 89 instructions vs 92. The original has the start of the loop body
// (fetch the record, compute the difference, test for an exact match) twice, once
// before the loop and once after stepping to the next node, with `best = record`
// after each; here the exact match shares one exit. Four variants tried (a flag,
// one condition, a chain of ifs with continue).
void ERFont::SetSize(bool pick, float size, float aspect) {
    size *= lbl_8037CA94.y;
    if (lbl_8037CA94.x != 0.0f) {
        aspect *= lbl_8037CA94.y / lbl_8037CA94.x;
    }
    if (pick) {
        EFontSize* best = 0;
        float bestDiff = 0.0f;
        for (ERFontSizeNode* node = unk20.head; node; node = node->next) {
            EFontSize* candidate = node->item;
            float diff = (float)candidate->unk4 - size;
            if (diff == 0.0f) {
                best = candidate;
                break;
            }
            if (best == 0 ||
                (diff < 0.0f ? diff > bestDiff
                             : (EFabs(diff) < EFabs(bestDiff) ||
                                (bestDiff < 0.0f && (float)candidate->unk4 / size <= 2.0f)))) {
                bestDiff = diff;
                best = candidate;
            }
        }
        unk60 = best;
    }
    unk5C = aspect;
    unk58 = size;
}

// 0x8003CACC
void ERFont::SelectPage(ERC* rc, int page) {
    if (unk74 != page) {
        unk74 = page;
        unk60->Page(page)->unk8->fn_80181824(rc);
    }
}

// One glyph of a size record, as the character map gives it.
struct ERFontGlyph {
    int unk0;
    int unk4;               // left edge on the page
    int unk8;               // right edge on the page
    unsigned short unkC;    // row on the page
    unsigned short unkE;    // page
};
// The page's dimensions, after the texture.
struct ERFontPageSize : EFontPage {
    int unkC;               // width
    int unk10;              // height
};
// Look-up in one of the font's maps (0x801B12D8): true when the key is present.
int fn_801B12D8(void* map, unsigned int key, void* out);
// The render context as the font uses it.
struct ERFontRC {
    char unk0[0x44];
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn20();
    virtual void vfn21();
    virtual void vfn22();
    virtual void vfn23();
    virtual void vfn24();
    virtual void vfn25();
    virtual void vfn26();
    virtual void vfn27();
    virtual void vfn28();
    virtual void vfn29();
    virtual void vfn30();
    virtual void vfn31();
    virtual void vfn32();
    virtual void vfn33();
    virtual void vfn34();
    virtual void vfn35();
    virtual void vfn36();
    virtual void vfn37();
    virtual void vfn38();
    virtual void vfn39(int state, int value);
    virtual void vfn40(int state, int value);
    virtual void vfn41();
    virtual void vfn42();
    virtual void vfn43();
    virtual void vfn44();
    virtual void vfn45();
    virtual void vfn46();
    virtual void vfn47();
    virtual void vfn48(int count, float* quads, EColorF* colour, float depth);
};

inline unsigned int ERFontChar(const void* text, bool wide, int index) {
    if (wide) {
        return ((const unsigned short*)text)[index];
    }
    return ((const unsigned char*)text)[index];
}
inline float ERFontRound(float value) { return (float)(int)(value + 0.5f); }

// 0x8003CB10
// Lays out a string and, when a render context is given, draws it: one pass per
// texture page, sending the glyph quads (positions and texture coordinates, eight
// floats each) in batches of 22. `size` gets where the text ends.
// NON_MATCHING: structured draft of a 656-instruction function. The early exit, the
// scaling and snapping, the per-page counts, the glyph and kerning look-ups, the
// batches and the final size follow the original; the eight floats of a quad and
// the register and stack layout have not been compared instruction by instruction.
void ERFont::DoDraw(const void* text, bool wide, bool snapX, bool snapY, const EVec2& position, ERC* rc, EVec2* size,
                    EWindow* window) {
    if (text == 0 || lbl_8037CA94.x == 0.0f || lbl_8037CA94.y == 0.0f) {
        if (size) {
            *size = EVec2(0.0f);
        }
        return;
    }
    LoadFont();
    EVec2 pen(position);
    if (window == 0) {
        window = lbl_8037C0DC;
    }
    float width;
    if (window) {
        width = window->unk0;
    } else {
        width = (float)lbl_8037C198->unk14;
    }
    float height;
    if (window) {
        height = window->unk14;
    } else {
        height = (float)lbl_8037C198->unk18;
    }
    pen.x *= width;
    pen.y *= height;
    float pixelY = 1.0f / height;
    float pixelX = 1.0f / width;
    if (unk60->unkC == 1) {
        if (snapX) {
            pen.x = ERFontRound(pen.x);
        }
        if (snapY) {
            pen.y = ERFontRound(pen.y);
        }
    }
    float lineScale = unk58 / (float)unk40;
    float glyphScale = unk58 / (float)unk60->unk4;
    int pages = unk60->unk24;
    EVec2 start(0.0f);
    float top = pen.y - ((float)unk34 * lineScale + 1.0f);
    float bottom = (float)unk60->unk8 * glyphScale + top - 1.0f;
    float space = (float)unk44 * lineScale * unk5C;
    float lineHeight = (float)unk30 * lineScale + 1.0f;
    ERFontRC* context = (ERFontRC*)rc;
    int counts[0x40];
    int first;
    int last;
    int i;
    if (context) {
        context->vfn39(0x8000, 0);
        context->vfn39(0x40, 0);
        first = 0;
        if (unk74 != -1) {
            first = unk74;
        }
        last = first + pages - 1;
        start = pen;
        if (pages > 1) {
            for (i = 0; i < pages; i++) {
                counts[i] = 0;
            }
            for (i = 0; ERFontChar(text, wide, i) != 0; i++) {
                ERFontGlyph* glyph;
                if (fn_801B12D8(&unk60->unk10, ERFontChar(text, wide, i), &glyph)) {
                    counts[glyph->unkE]++;
                }
            }
        } else {
            for (i = 0; ERFontChar(text, wide, i) != 0; i++) {
            }
            counts[0] = i;
        }
    } else {
        last = 0;
        first = 0;
    }
    for (int page = first; page <= last; page++) {
        int index = page % pages;
        if (context && counts[index] == 0) {
            continue;
        }
        float texelX = 0.0f;
        float texelY = 0.0f;
        float quads[0x16 * 8];
        float* quad = quads;
        int count = 0;
        if (context) {
            SelectPage(rc, index);
            pen = start;
            ERFontPageSize* sheet = (ERFontPageSize*)unk60->Page(index);
            texelX = 1.0f / (float)sheet->unkC;
            texelY = 1.0f / (float)sheet->unk10;
        }
        int at = 0;
        unsigned int current = ERFontChar(text, wide, 0);
        while (current != 0) {
            at++;
            unsigned int next = ERFontChar(text, wide, at);
            ERFontGlyph* glyph;
            if (fn_801B12D8(&unk60->unk10, current, &glyph)) {
                float left = pen.x - 1.0f;
                float right = (float)(glyph->unk8 - glyph->unk4) * unk5C * glyphScale + left;
                if (context && glyph->unkE == unk74) {
                    int row = glyph->unkC;
                    int rowHeight = unk60->unk8;
                    quad[0] = left * pixelX;
                    quad[1] = top * pixelY;
                    quad[2] = right * pixelX;
                    quad[3] = bottom * pixelY;
                    quad[4] = (float)glyph->unk4 * texelX;
                    quad[5] = (float)(row * rowHeight) * texelY;
                    quad[6] = (float)glyph->unk8 * texelX;
                    quad[7] = (float)((row + 1) * rowHeight - 1) * texelY;
                    quad += 8;
                    count++;
                    if (count > 0x15) {
                        context->vfn48(count, quads, &unk64, 0.0f);
                        count = 0;
                        quad = quads;
                    }
                }
                pen.x = right - 1.0f;
            } else {
                pen.x = pen.x + space;
            }
            if (next != 0) {
                int kerning;
                if (!fn_801B12D8(&unk48, (current << 16) | next, &kerning)) {
                    kerning = unk38;
                }
                float advance = (float)kerning * unk5C;
                if (unk60->unkC == 1) {
                    if (advance < 0.0f) {
                        advance = (float)(int)(advance + -0.5f);
                    } else {
                        advance = (float)(int)(advance + 0.5f);
                    }
                }
                pen.x = advance * lineScale + pen.x;
            }
            current = next;
        }
        if (context && count > 0) {
            context->vfn48(count, quads, &unk64, 0.0f);
        }
    }
    if (size) {
        EVec2 end(pen.x, top + lineHeight);
        if (unk60->unkC == 1) {
            if (snapX) {
                end.x = ERFontRound(end.x);
            }
            if (snapY) {
                end.y = ERFontRound(end.y);
            }
        }
        size->x = end.x * pixelX;
        size->y = end.y * pixelY;
    }
    if (context) {
        context->vfn40(0x8000, 0);
    }
}

// 0x8003D550
EVec2 ERFont::DoGetStringSize(const void* text, bool wide, EWindow* window) {
    EVec2 size;
    DoDraw(text, wide, false, false, EVec2(0.0f), 0, &size, window);
    return size;
}

// 0x8003D5C4
// Rounds a normalized position to whole pixels of the window (or of the screen).
void ERFont::SnapPosToPixel(EVec2& position, bool snapX, bool snapY, EWindow* window) {
    if (!snapX && !snapY) {
        return;
    }
    if (window == 0) {
        window = lbl_8037C0DC;
    }
    float width;
    if (window) {
        width = window->unk0;
    } else {
        width = (float)lbl_8037C198->unk14;
    }
    float height;
    if (window) {
        height = window->unk14;
    } else {
        height = (float)lbl_8037C198->unk18;
    }
    position.x *= width;
    position.y *= height;
    float pixelX = 1.0f / width;
    float pixelY = 1.0f / height;
    if (snapX) {
        position.x = (float)(int)(position.x + 0.5f);
    }
    if (snapY) {
        position.y = (float)(int)(position.y + 0.5f);
    }
    position.x *= pixelX;
    position.y *= pixelY;
}

// 0x8003D740
// Draws text with its position meaning the left/top (0), right/bottom (1) or
// centre (2) of the text on each axis.
// NON_MATCHING: 132 instructions vs 127; everything after the measuring step agrees.
// The original's two calls of DoGetStringSize share their last instructions and the
// assignment (both keep the return slot's address in r30); here they are separate
// and use r30 and r24. Seven variants tried (conditional expressions, a switch, an
// inline helper, a shared temporary).
void ERFont::DoDrawAlign(ERC* rc, const void* text, bool wide, EVec2 position, int alignX, int alignY, EVec2* size) {
    EVec2 extent(0.0f, 0.0f);
    if ((unsigned int)(alignX - 1) <= 1) {
        extent = DoGetStringSize(text, wide, 0);
    } else if ((unsigned int)(alignY - 1) <= 1) {
        extent = DoGetStringSize("", false, 0);
    }
    bool noSnapX;
    bool noSnapY;
    if (unk60->unkC == 1) {
        noSnapX = alignX == 1;
        noSnapY = alignY == 1;
        SnapPosToPixel(position, noSnapX, noSnapY, 0);
        noSnapX = !noSnapX;
        noSnapY = !noSnapY;
    } else {
        noSnapY = false;
        noSnapX = false;
    }
    EVec2 at;
    switch (alignX) {
    case 0:
        at.x = position.x;
        break;
    case 2:
        at.x = position.x - extent.x * 0.5f;
        break;
    case 1:
        at.x = position.x - extent.x;
        break;
    }
    switch (alignY) {
    case 0:
        at.y = position.y;
        break;
    case 2:
        at.y = position.y - extent.y * 0.5f;
        break;
    case 1:
        at.y = position.y - extent.y;
        break;
    }
    DoDraw(text, wide, noSnapX, noSnapY, at, rc, size, 0);
}

// 0x8003D93C
// Draws wide text with a drop shadow: once in black at `offset` pixels down and to
// the right with the given alpha, then normally.
// NON_MATCHING: 134 instructions vs 136. The original builds the pixel size in the
// stack slot that the by-value position of the two draw calls then reuses, and
// folds the shadow's x into one multiply-add; here the slots differ. Five variants
// tried (temporary or named pixel size, operator and component forms).
void ERFont::DrawDs(ERC* rc, const void* text, EVec2* position, int alignX, int alignY, EVec2* size, float offset,
                    float alpha) {
    if (offset < 1.0f) {
        offset = 1.0f;
    } else {
        offset = (float)(int)offset;
    }
    EVec2 pixel(1.0f / (float)lbl_8037C198->unk14, 1.0f / (float)lbl_8037C198->unk18);
    EVec2 at(offset * pixel);
    at += *position;
    EColorF saved(unk64);
    unk64 = EColorF(0.0f, 0.0f, 0.0f, alpha);
    DoDrawAlign(rc, text, true, at, alignX, alignY, 0);
    unk64 = saved;
    DoDrawAlign(rc, text, true, *position, alignX, alignY, &at);
    if (size) {
        *size = at;
    }
}

// 0x8003DB5C
// Loads the textures of the current size's pages.
void ERFont::LoadFont() {
    for (int i = 0; i < unk60->NumPages(); i++) {
        EFontPage* page = unk60->Page(i);
        if (page->unk8 == 0) {
            page->unk8 = (Unk80181824*)lbl_80340AB8.fn_80177628(page->unk4, 0, 0);
        }
    }
}

// 0x8003DBE8
void ERFont::Select(ERC* rc) {
    LoadFont();
    unk74 = -1;
}

// 0x8003DC1C
float ERFont::GetLineSpacing(EWindow* window) {
    EVec2 size;
    DoDraw("", false, false, false, EVec2(0.0f), 0, &size, window);
    return size.y / (float)(unk30 - unk34);
}
