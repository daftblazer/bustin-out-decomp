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

// 0x8003C784
// NON_MATCHING: not yet compared.
ERFont::ERFont() {
    unk60 = 0;
    unk58 = -1.0f;
    unk5C = 1.0f;
    unk64 = EColorF(1.0f);
    unk74 = -1;
}

// 0x8003C804
// NON_MATCHING: not yet compared.
ERFont::~ERFont() {
    Deallocate();
}

// 0x8003C868
// NON_MATCHING: not yet compared.
void ERFont::Deallocate() {
    for (ERFontSizeNode* node = unk20.head; node; node = node->next) {
        fn_80160508(node->item);
    }
}

// 0x8003C8AC
// NON_MATCHING: not yet compared.
void ERFont::vfn10(EFile& file) {
    unk60 = 0;
    Load(file);
}

// 0x8003C8D4
// NON_MATCHING: not yet compared.
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
// NON_MATCHING: not yet compared.
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
            bool take;
            if (best == 0) {
                take = true;
            } else if (diff < 0.0f) {
                take = diff > bestDiff;
            } else if (EFabs(diff) < EFabs(bestDiff)) {
                take = true;
            } else if (bestDiff >= 0.0f) {
                take = false;
            } else {
                take = (float)candidate->unk4 / size <= 2.0f;
            }
            if (take) {
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
// NON_MATCHING: not yet compared.
void ERFont::SelectPage(ERC* rc, int page) {
    if (unk74 != page) {
        unk74 = page;
        unk60->Page(page)->unk8->fn_80181824(rc);
    }
}

// 0x8003D550
// NON_MATCHING: not yet compared.
EVec2 ERFont::DoGetStringSize(const void* text, bool wide, EWindow* window) {
    EVec2 size;
    DoDraw(text, wide, false, false, EVec2(0.0f), 0, &size, window);
    return size;
}

// 0x8003D5C4
// Rounds a normalized position to whole pixels of the window (or of the screen).
// NON_MATCHING: not yet compared.
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
// NON_MATCHING: not yet compared.
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

// 0x8003DB5C
// Loads the textures of the current size's pages.
// NON_MATCHING: not yet compared.
void ERFont::LoadFont() {
    for (int i = 0; i < unk60->NumPages(); i++) {
        EFontPage* page = unk60->Page(i);
        if (page->unk8 == 0) {
            page->unk8 = (Unk80181824*)lbl_80340AB8.fn_80177628(page->unk4, 0, 0);
        }
    }
}

// 0x8003DBE8
// NON_MATCHING: not yet compared.
void ERFont::Select(ERC* rc) {
    LoadFont();
    unk74 = -1;
}

// 0x8003DC1C
// NON_MATCHING: not yet compared.
float ERFont::GetLineSpacing(EWindow* window) {
    EVec2 size;
    DoDraw("", false, false, false, EVec2(0.0f), 0, &size, window);
    return size.y / (float)(unk30 - unk34);
}
