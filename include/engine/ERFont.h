#ifndef ENGINE_ERFONT_H
#define ENGINE_ERFONT_H

#include "engine/EStorable.h"
#include "engine/EVec3.h"

struct ERC;
struct EWindow;
struct Unk80181824;

// Four floats with a float-wise copy constructor (see CASWidgets.h, which has the
// same class; it lives here so the font can hold one).
#ifndef ECOLORF_DEFINED
#define ECOLORF_DEFINED
struct EColorF {
    EColorF() {}
    EColorF(float r_, float g_, float b_, float a_) : r(r_), g(g_), b(b_), a(a_) {}
    EColorF(float value) { r = g = b = a = value; }
    EColorF(const EColorF& other) : r(other.r), g(other.g), b(other.b), a(other.a) {}
    float r, g, b, a;
};
#endif

// One texture page of a font size. The class name is from the header strings.
struct EFontPage {
    int unk0;
    unsigned int unk4;       // texture id
    Unk80181824* unk8;       // the texture, once loaded
};

// One size a font was built in ("EFontSize" in the header strings).
struct EFontSize {
    int unk0;
    int unk4;                // nominal size
    int unk8;
    int unkC;                // 1: positions are snapped to pixels
    char unk10[0x10];
    EFontPage** unk20;       // pages
    int unk24;               // number of pages

    EFontPage*& Page(int index) { return unk20[index]; }
    int NumPages() const { return unk24; }
};

// The list of sizes (constructor 0x801606FC, destructor 0x80160770).
struct ERFontSizeNode {
    EFontSize* item;
    ERFontSizeNode* prev;
    ERFontSizeNode* next;
};
struct ERFontSizeList {
    ERFontSizeList();
    ~ERFontSizeList();
    int unk0;
    ERFontSizeNode* head;
    char unk8[8];
};

extern EStorableClass lbl_803795A8;   // ERFont's record
EStorable* fn_8003DD38();
EStorable* fn_8003DD60(void* place);
void fn_8003DD8C(EStorable* object);

// A bitmap font resource (0x78 bytes). Class and method names are from The Sims 2's
// symbol map, which lists ERFont's methods in the same order; the ones whose size is
// identical there are ERFont(), Deallocate, SetSize, LoadFont and Select. The others
// are matched by position and by what they do.
class ERFont : public EResource {
public:
    ERFont();
    virtual ~ERFont();
    virtual void vfn10(EFile& file);

    void Deallocate();
    void Load(EFile& file);
    void SetSize(bool pick, float size, float aspect);
    void SelectPage(ERC* rc, int page);
    void DoDraw(const void* text, bool wide, bool noSnapX, bool noSnapY, const EVec2& position, ERC* rc,
                EVec2* size, EWindow* window);
    EVec2 DoGetStringSize(const void* text, bool wide, EWindow* window);
    void SnapPosToPixel(EVec2& position, bool snapX, bool snapY, EWindow* window);
    void DoDrawAlign(ERC* rc, const void* text, bool wide, EVec2 position, int alignX, int alignY, EVec2* size);
    void DrawDs(ERC* rc, const void* text, EVec2* position, int alignX, int alignY, EVec2* size, float offsetX,
                float offsetY);
    void LoadFont();
    void Select(ERC* rc);
    float GetLineSpacing(EWindow* window);

    E_STORABLE_BODY(ERFont, lbl_803795A8, fn_8003DD38, fn_8003DD60, fn_8003DD8C)

    int unk18;
    int unk1C;
    ERFontSizeList unk20;
    int unk30;
    int unk34;
    char unk38[0x58 - 0x38];
    float unk58;             // current size
    float unk5C;             // current aspect
    EFontSize* unk60;        // the size record in use
    EColorF unk64;           // colour
    int unk74;               // page selected in the render context (-1: none)
};

#endif
