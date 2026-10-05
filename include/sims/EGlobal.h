#ifndef SIMS_EGLOBAL_H
#define SIMS_EGLOBAL_H

// The game's global state singleton at 0x802E6700. The class name comes from
// The Sims 2's symbol map (EGlobal::AllocSpriteRenderer lines up with one of
// its methods here); member and most method names are provisional.

class ESimsCam;
struct SimsAppUnk2B50Base;
struct ESimsCamUnkBC;
struct Unk800053D4Owner;
struct Unk80340120Resource;
struct Unk8016BC18;

struct Unk800669ACResult {
    int* ptr;
};

class EGlobal {
public:
    void Begin();                 // 0x8006887C
    void End();                   // 0x800661E0
    int fn_800655C4();
    unsigned int fn_800655D8();
    void fn_800656D8();
    Unk800669ACResult fn_800669AC(const char* format, ...);
    Unk800669ACResult fn_800667EC(const char* format, ...);
    Unk800669ACResult fn_8006670C(const char* format, ...);
    void fn_80068DE8(Unk80340120Resource*, Unk8016BC18*);
    void fn_800690E0(int);
    void fn_80068054(int, int);
    int fn_800690B0(int);

    Unk800053D4Owner* GetUnk9C(int player) { return unk9C[player]; }
    void* GetUnk90() { return unk90; }
    int GetUnkA4() { return unkA4; }
    int GetUnk214() { return unk214; }

    struct {
        unsigned short unk0;        // 0x00 buttons allowed in cheat codes
        unsigned short codes[8][6]; // 0x02 button sequences, zero-terminated
        unsigned short masks[8];    // 0x62 buttons used by each sequence
    } cheats;
    char unk72[0x90 - 0x72];
    void* unk90;
    char unk94[0x9C - 0x94];
    Unk800053D4Owner* unk9C[2];   // per player
    int unkA4;
    struct Unk324* unkA8[4];      // per player, set from ESimsCam+0x324
    char unkB8[0xBC - 0xB8];
    ESimsCamUnkBC* unkBC;
    char unkC0[0xE4 - 0xC0];
    struct Unk80181824* unkE4;    // plain white texture
    char unkE8[0xEC - 0xE8];
    struct Unk8003C95C* unkEC;    // default font
    char unkF0[0x118 - 0xF0];
    struct EGlobalUnk118* unk118;
    char unk11C[0x140 - 0x11C];
    // Settings registered by ECheats::Init under the names in the comments.
    int unk140;             // soundon
    int unk144;             // freeitems
    int unk148;             // memory_display
    int unk14C;             // unlock_all_items
    int unk150;             // unlock_all_houses
    int unk154;             // unlock_party_motel
    int unk158;             // unlock_freeplay_mode
    int unk15C;             // debug_interactions
    int unk160;             // animation_name_display
    int unk164;             // display_fps
    int unk168;             // eor_artsend_debug
    int unk16C;             // Cam_Tilt
    int unk170;             // Cam_First_Per
    int unk174;             // grab_any_object
    int unk178;             // cheatmenu
    int unk17C;             // cas_start_as_male
    int unk180;             // draw_safe_rect
    int unk184;             // draw_flash_output
    int unk188;             // draw_motive_values
    int unk18C;             // enable_npc_reset
    int unk190;             // print_sound_calls
    int unk194;             // resource_test
    int unk198;             // dnas_enabled
    int unk19C;             // lobby_thumbnails
    unsigned char unk1A0;         // lobby_server
    char unk1A1;
    short unk1A2;                 // lobby_select_delay
    short unk1A4;                 // dnas_error
    short unk1A6;                 // lobby_error
    unsigned char unk1A8;         // tutorial_stage
    unsigned char unk1A9;         // tutorial_house
    unsigned char unk1AA;         // ambientIntensity
    unsigned char unk1AB;         // directionIntensity
    unsigned char unk1AC;         // cameraIntensity
    unsigned char unk1AD;         // directionX
    unsigned char unk1AE;         // directionY
    unsigned char unk1AF;         // directionZ
    unsigned char unk1B0;         // localization_test (language)
    char unk1B1[0x214 - 0x1B1];   // boot2
    int unk214;
};

extern EGlobal lbl_802E6700;

// Looks up a localized string by name; null when it does not exist.
inline int GetText(const char* name) {
    Unk800669ACResult result = lbl_802E6700.fn_800667EC(name);
    return result.ptr ? *result.ptr : 0;
}

// As GetText, through the other look-up (0x8006670C).
inline int GetTextB(const char* name) {
    Unk800669ACResult result = lbl_802E6700.fn_8006670C(name);
    return result.ptr ? *result.ptr : 0;
}

#endif
