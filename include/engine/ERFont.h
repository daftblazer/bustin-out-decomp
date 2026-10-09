#ifndef ENGINE_ERFONT_H
#define ENGINE_ERFONT_H

#include "engine/EStorable.h"
#include "engine/EVec3.h"
#include "engine/EColorF.h"

struct ERC;
struct EWindow;
struct Unk80181824;

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
    void DoDraw(const void* text, bool wide, bool snapX, bool snapY, const EVec2& position, ERC* rc,
                EVec2* size, EWindow* window);
    EVec2 DoGetStringSize(const void* text, bool wide, EWindow* window);
    // The public forms (inferred: the Sims 2 names carry "Do", and callers that take
    // the size through these compile like the original, which calls with the flag set).
    EVec2 GetStringSize(const unsigned short* text, EWindow* window = 0) { return DoGetStringSize(text, true, window); }
    EVec2 GetStringSize(const char* text, EWindow* window = 0) { return DoGetStringSize(text, false, window); }
    void SnapPosToPixel(EVec2& position, bool snapX, bool snapY, EWindow* window);
    void DoDrawAlign(ERC* rc, const void* text, bool wide, EVec2 position, int alignX, int alignY, EVec2* size);
    void DrawDs(ERC* rc, const void* text, EVec2* position, int alignX, int alignY, EVec2* size, float offsetX,
                float offsetY);
    void LoadFont();
    void Select(ERC* rc);
    float GetLineSpacing(EWindow* window);

    E_STORABLE_BODY(ERFont, fn_8003DD38, fn_8003DD60, fn_8003DD8C)
    void operator delete(void* ptr) { fn_80169EE8(ptr); }

    int unk18;
    int unk1C;
    ERFontSizeList unk20;
    int unk30;               // line height, in units of unk40
    int unk34;               // ascent
    int unk38;               // default kerning
    int unk3C;
    int unk40;               // design size
    int unk44;               // width of a missing character
    char unk48[0x58 - 0x48]; // kerning pairs (a map keyed by both characters)
    float unk58;             // current size
    float unk5C;             // current aspect
    EFontSize* unk60;        // the size record in use
    EColorF unk64;           // colour
    int unk74;               // page selected in the render context (-1: none)
};

#endif
