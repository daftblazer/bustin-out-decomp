#include "engine/e_storable.h"
#include "engine/e_resource.h"
#include "engine/e_rfont.h"
#include "engine/e_shader.h"
#include "engine/e_rshader.h"
#include "engine/e_texture.h"
#define EOR_BUILD_TIME "21:41:21"
#include "engine/e_engine.h"
#include "sims/e_simsapp_title.h"
#include <string.h>
#include "engine/EStaticObject.h"
#include "sims/ECheats.h"
#include "engine/EController.h"
#include "engine/ResourceManagers.h"
#include "sims/cas/CASTarget.h"

extern unsigned char lbl_8037B498; // language the debug menu was opened with
struct Unk802E30B8 {
    void fn_800644D8();
};
extern Unk802E30B8* lbl_802E30B8[3]; // part of a larger object (addressed without r13); size guessed
void* fn_80169F1C(unsigned int size, int align);
void fn_80169EE8(void* ptr);

// Path builder over a caller-supplied buffer (constructor 0x8023C2A0).
struct Unk8023C2A0 {
    Unk8023C2A0() { fn_8023C2A0(buffer, sizeof(buffer)); }
    void fn_8023C2A0(char* buffer, int size);
    void fn_8023C314(const char* text, int length); // append
    void fn_8023C45C(const Unk8023C2A0& other);     // assign
    const char* fn_8023C40C();
    char unk0[8];
    char buffer[0x104];
    char unk10C[4];
};

// Disc file (DVDFileInfo) and the calls on it.
struct Unk801225D0 {
    char unk0[0x34];
    unsigned int length;
    char unk38[0x40 - 0x38];
};
extern "C" {
int fn_801225D0(const char* path, Unk801225D0* file);
int fn_801229D0(Unk801225D0* file, void* buffer, int length, int offset, int priority);
int fn_80122698(Unk801225D0* file);
}
extern unsigned char lbl_802B6491[]; // character class table

// The debug menu entry for the lighting test; all its members are inline.
class Unk8002657C : public EDebugMenuItem {
public:
    virtual void GetDescription(char* out) { strcpy(out, "InitLights: L = Hot Sync -- R = ReCompute"); }
    virtual void GetValue(char* out) { *out = 0; }
    virtual void ButtonPress(int button) {}
    virtual void ButtonPress(int button, float amount) {}
    virtual ~Unk8002657C() {}
};
// Constructed at start-up and never destroyed (see engine/EStaticObject.h).
EStaticObject<Unk8002657C> lbl_802E5B1C;

// 0x8002436C
Unk8002436C::Unk8002436C() {
    count = 0;
    fn_80111C78(values, 0, sizeof(values));
}

// 0x800243B0
void Unk8002436C::fn_800243B0(int value) {
    values[count] = value;
    count++;
}

// 0x800243D0
void Unk8002436C::fn_800243D0() {
    count = 0;
    fn_80111C78(values, 0, sizeof(values));
}

// 0x80024404
void fn_80024404(int value) {
    *(int*)((char*)&lbl_802E6700 + 0x22C) = value;
}

// 0x80024410
ECheats::ECheats() {
    EmptyLookupList();
    unk100 = 0;
}

// 0x80024480
ECheats::~ECheats() {
    EmptyLookupList();
}

// Registering a setting. These have to be macros: the name is copied with an
// inline (builtin) strcpy, which the compiler only expands for a literal.
#define ADD_CHEAT(name_, type_, var_) \
    { \
        lookup = new ECheatLookup; \
        strcpy(lookup->name, name_); \
        lookup->type = type_; \
        lookup->var = var_; \
        Insert(lookup); \
    }
#define ADD_HIDDEN_CHEAT(name_, type_, var_) \
    { \
        lookup = new ECheatLookup; \
        lookup->unk50 = 0; \
        strcpy(lookup->name, name_); \
        lookup->type = type_; \
        lookup->var = var_; \
        Insert(lookup); \
    }

// 0x80024500
// Registers every setting with the EGlobal field it controls, then reads the
// settings file.
// NON_MATCHING: 2 instructions. Two of the hidden settings (directionY, directionZ)
// clear their flag from the function's second zero register (r23) in the original and
// from the first (r28) here. Six variants tried.
void ECheats::Init(EGlobal& global) {
    int i;
    ECheatLookup* lookup;
    unk108.fn_800243D0();
    unk14C = 0;
    for (i = 0; i < 0x40; i++) {
        unk150[i].Reset();
    }
    Unk8002436C buttons;
    buttons.fn_800243B0(1);
    buttons.fn_800243B0(2);
    buttons.fn_800243B0(4);
    buttons.fn_800243B0(8);
    fn_80025A68(buttons, fn_80024404, 1);
    EmptyLookupList();
    ADD_CHEAT("soundon", 1, &global.unk140);
    ADD_CHEAT("freeitems", 1, &global.unk144);
    ADD_CHEAT("memory_display", 1, &global.unk148);
    ADD_CHEAT("unlock_all_items", 1, &global.unk14C);
    ADD_CHEAT("unlock_all_houses", 1, &global.unk150);
    ADD_CHEAT("unlock_party_motel", 1, &global.unk154);
    ADD_CHEAT("unlock_freeplay_mode", 1, &global.unk158);
    ADD_CHEAT("debug_interactions", 1, &global.unk15C);
    ADD_CHEAT("animation_name_display", 1, &global.unk160);
    ADD_CHEAT("display_fps", 1, &global.unk164);
    ADD_CHEAT("localization_test", 2, &global.unk1B0);
    ADD_CHEAT("resource_test", 1, &global.unk194);
    ADD_CHEAT("cheatmenu", 1, &global.unk178);
    ADD_CHEAT("tutorial_stage", 2, &global.unk1A8);
    ADD_CHEAT("tutorial_house", 2, &global.unk1A9);
    ADD_CHEAT("enable_npc_reset", 1, &global.unk18C);
    ADD_CHEAT("eor_artsend_debug", 1, &global.unk168);
    ADD_CHEAT("Cam_Tilt", 1, &global.unk16C);
    ADD_CHEAT("Cam_First_Per", 1, &global.unk170);
    ADD_CHEAT("grab_any_object", 1, &global.unk174);
    ADD_CHEAT("cas_start_as_male", 1, &global.unk17C);
    // The first hidden setting clears its flag after the name is copied, the
    // others before; the original evidently wrote these out one by one.
    lookup = new ECheatLookup;
    strcpy(lookup->name, "ambientIntensity");
    lookup->unk50 = 0;
    lookup->type = 2;
    lookup->var = &global.unk1AA;
    Insert(lookup);
    ADD_HIDDEN_CHEAT("directionIntensity", 2, &global.unk1AB);
    ADD_HIDDEN_CHEAT("cameraIntensity", 2, &global.unk1AC);
    ADD_HIDDEN_CHEAT("directionX", 2, &global.unk1AD);
    ADD_HIDDEN_CHEAT("directionY", 2, &global.unk1AE);
    ADD_HIDDEN_CHEAT("directionZ", 2, &global.unk1AF);
    ADD_HIDDEN_CHEAT("lobby_server", 2, &global.unk1A0);
    ADD_HIDDEN_CHEAT("dnas_enabled", 1, &global.unk198);
    ADD_HIDDEN_CHEAT("lobby_thumbnails", 1, &global.unk19C);
    ADD_HIDDEN_CHEAT("lobby_select_delay", 4, &global.unk1A2);
    ADD_HIDDEN_CHEAT("dnas_error", 4, &global.unk1A4);
    ADD_HIDDEN_CHEAT("lobby_error", 4, &global.unk1A6);
    ADD_HIDDEN_CHEAT("boot2", 6, global.unk1B1);
    ADD_CHEAT("draw_safe_rect", 1, &global.unk180);
    ADD_CHEAT("draw_flash_output", 1, &global.unk184);
    ADD_CHEAT("draw_motive_values", 1, &global.unk188);
    ADD_CHEAT("print_sound_calls", 1, &global.unk190);
    lbl_802E6700.unk194 = 0;
    int sound = lbl_802E6700.unk140;
    ReadCheatsFile();
    WriteCheatsFile();
    if (sound == 0) {
        lbl_802E6700.unk140 = sound;
    }
    unk104 = 0;
}

// 0x80025518
void ECheats::Reset() {
    WriteCheatsFile();
    EmptyLookupList();
}

// 0x8002554C
void ECheats::EmptyLookupList() {
    for (int i = 0; i <= 0x3F; i++) {
        ECheatLookup* lookup = table.buckets[i];
        if (lookup) {
            table.buckets[i] = 0;
            do {
                ECheatLookup* dead = lookup;
                lookup = lookup->next;
                delete dead;
            } while (lookup);
        }
    }
}

// 0x800255B4
// Reads "name = value" lines from /runtime/system.cnf into the settings.
// NON_MATCHING: 288 instructions vs 300. Draft: the calls and the type switch are the
// original's; the line and token copying loops and the inlined table look-up differ.
// One variant tried.
void ECheats::ReadCheatsFile() {
    Unk8023C2A0 path;
    unk100 = 1;
    {
        Unk8023C2A0 root;
        root.fn_8023C314("", -1);
        path.fn_8023C45C(root);
    }
    path.fn_8023C314("/runtime/", -1);
    path.fn_8023C314("system.cnf", -1);
    Unk801225D0 file;
    if (fn_801225D0(path.fn_8023C40C(), &file)) {
        unsigned int size = (file.length + 0x1F) & ~0x1F;
        char* text = (char*)fn_80169F1C(size, 0x20);
        if (text) {
            fn_80111C78(text, 0, size);
            unsigned int pos = 0;
            fn_801229D0(&file, text, size, 0, 2);
            fn_80122698(&file);
            ECheatIterator found;
            found.node = 0;
            found.bucket = 0;
            while (pos < size && text[pos] != 0) {
                unsigned int start = pos;
                while (pos < size && text[pos] != '\n') {
                    pos++;
                }
                if (pos < size) {
                    pos++;
                }
                char line[0x100];
                int length = pos - start;
                for (int i = 0; i < length && i < 0x100; i++) {
                    line[i] = text[start + i];
                }
                if ((unsigned int)length <= 0xFF) {
                    line[length] = 0;
                } else {
                    line[0xFF] = 0;
                }
                if (line[0] != '#') {
                    char name[0x40];
                    char value[0x40];
                    name[0] = 0;
                    value[0] = 0;
                    int in = 0;
                    int out = 0;
                    while ((lbl_802B6491[line[in]] & 0x17) && line[in] != '=' && out < 0x40) {
                        name[out++] = line[in++];
                    }
                    name[out] = 0;
                    fn_80112064(name);
                    while (line[in] != 0 && (!(lbl_802B6491[line[in]] & 0x17) || line[in] == '=')) {
                        in++;
                    }
                    out = 0;
                    while ((lbl_802B6491[line[in]] & 0x17) && out < 0x40) {
                        value[out++] = line[in++];
                    }
                    value[out] = 0;
                    const char* key = name;
                    ECheatIterator it(this);
                    it.bucket = ECheatLookup::hash(name) & 0x3F;
                    ECheatLookup* lookup;
                    for (lookup = table.buckets[it.bucket]; lookup; lookup = lookup->next) {
                        if (lookup->compare(key)) {
                            it.node = lookup;
                            break;
                        }
                    }
                    if (lookup == 0) {
                        it.bucket = 0x40;
                    }
                    found = it;
                    if (!(found == end())) {
                        lookup = found.node;
                        switch (lookup->type) {
                        case 1:
                            *(int*)lookup->var = fn_80110874(value) != 0;
                            break;
                        case 2:
                        case 3:
                        case 5:
                            *(char*)lookup->var = fn_80110874(value);
                            break;
                        case 4:
                            *(short*)lookup->var = fn_80110874(value);
                            break;
                        case 6:
                            fn_80111F74((char*)lookup->var, value);
                            break;
                        }
                    }
                }
            }
            fn_80169EE8(text);
        }
    }
}

// 0x80025A64
void ECheats::WriteCheatsFile() {
}

// 0x80025A68
void ECheats::fn_80025A68(const Unk8002436C& list, void (*callback)(int), int arg) {
    unk150[unk14C].list = list;
    unk150[unk14C].unk44 = callback;
    unk150[unk14C].unk48 = arg;
    unk14C++;
}

// 0x80025B14
void ECheats::fn_80025B14() {
}

// 0x80025B18
// Opens the debug menu when the "cheatmenu" setting is on and closes it again;
// a changed language reloads the text resources.
void ECheats::Update() {
    fn_80025B14();
    EController* controller = lbl_8037C11C->fn_8015E5FC(lbl_8037C11C->fn_8015E614(0));
    if (unk104 == 0) {
        if (lbl_802E6700.unk178 && controller->fn_8015E0F8(0xB)) {
            unk104 = 1;
            lbl_8037B498 = lbl_802E6700.unk1B0;
            EnableCheats();
            ReadCheatsFile();
        }
    } else if (controller->fn_8015E0F8(5) || controller->fn_8015E0F8(7)) {
        if (lbl_8037D988) {
            unk104 = 0;
            unsigned char language = lbl_802E6700.unk1B0;
            if (lbl_8037B498 != language) {
                lbl_803401C4.unkA4 = language;
                lbl_803401C4.fn_801777B0(0x2A2AF469);
                lbl_803401C4.fn_801777B0(0x4F40C4EC);
                lbl_803401C4.fn_801777B0(0x0C33DB41);
                lbl_8037D988->vfn59();
                lbl_803401C4.fn_801777B0(0x19A16F2D);
                lbl_803401C4.fn_801777B0(0xA173A1EE);
                lbl_802E6700.fn_80068054(0, 0x28);
                lbl_802E30B8[0]->fn_800644D8();
            }
            DisableCheats();
            WriteCheatsFile();
        }
    }
}

// 0x80025CB0
// NON_MATCHING: 119 instructions vs 138, frame 0x60 vs 0x70. The original keeps one
// more iterator on the stack (begin() and end() build a local and copy it to the
// returned temporary, which is then copied again) and reloads the table pointer on
// every step of the search for the first used bucket. Three variants tried.
void ECheats::EnableCheats() {
    for (ECheatIterator it = begin(); !(it == end()); it.Next()) {
        ECheatLookup* lookup = it.node;
        if (lookup->unk50) {
            ECheatDMI* item = new ECheatDMI(it.node);
            lookup->dmi = item;
            lbl_8033F66C.fn_8015E904(item);
        }
    }
    lbl_8033F66C.fn_8015E904(lbl_802E5B1C);
}

// 0x80025ED8
// NON_MATCHING: 112 instructions vs 131; the same iterator differences as EnableCheats.
void ECheats::DisableCheats() {
    for (ECheatIterator it = begin(); !(it == end()); it.Next()) {
        ECheatLookup* lookup = it.node;
        if (lookup->unk50) {
            lbl_8033F66C.fn_8015E94C(lookup->dmi);
            delete lookup->dmi;
            lookup->dmi = 0;
        }
    }
    lbl_8033F66C.fn_8015E94C(lbl_802E5B1C);
}

// 0x800260E4
ECheatLookup::ECheatLookup() {
    unk50 = 1;
    dmi = 0;
}

// 0x800260F8
int ECheatLookup::hash(const char* name) {
    return fn_801AE714(name);
}

// 0x80026118
int ECheatLookup::compare(const char* other) const {
    return fn_80111ECC(other, name) == 0;
}

// 0x8002614C
void ECheatDMI::GetDescription(char* out) {
    fn_80111F74(out, lookup->name);
}

// 0x80026178
void ECheatDMI::GetValue(char* out) {
    switch (lookup->type) {
    case 1:
        if (*(int*)lookup->var == 0) {
            strcpy(out, "false");
        } else {
            strcpy(out, "true");
        }
        break;
    case 2:
    case 5:
        fn_8010F710(out, "%d", *(unsigned char*)lookup->var);
        break;
    case 3:
        fn_8010F710(out, "%d", *(signed char*)lookup->var);
        break;
    case 4:
        fn_8010F710(out, "%d", *(short*)lookup->var);
        break;
    default:
        *out = 0;
        break;
    }
}

// 0x80026284
// Steps the value down (button 0) or up (button 1). A short value falls
// through into the small-count case, as in the original.
void ECheatDMI::ButtonPress(int button) {
    switch (lookup->type) {
    case 1:
        if ((unsigned int)button <= 1) {
            *(int*)lookup->var ^= 1;
        }
        break;
    case 2:
        if (button == 0) {
            unsigned char* value = (unsigned char*)lookup->var;
            if (*value != 0) {
                *value = *value - 1;
            } else {
                *value = 0xFF;
            }
        } else if (button == 1) {
            unsigned char* value = (unsigned char*)lookup->var;
            if (*value <= 0xFE) {
                *value = *value + 1;
            } else {
                *value = 0;
            }
        }
        break;
    case 3:
        if (button == 0) {
            signed char* value = (signed char*)lookup->var;
            if (*value > -0x80) {
                *value = *value - 1;
            } else {
                *value = 0x7F;
            }
        } else if (button == 1) {
            signed char* value = (signed char*)lookup->var;
            if (*value <= 0x7E) {
                *value = *value + 1;
            } else {
                *value = -0x80;
            }
        }
        break;
    case 4:
        if (button == 0) {
            short* value = (short*)lookup->var;
            if (*value > -0x8000) {
                *value = *value - 1;
            } else {
                *value = 0x7FFF;
            }
        } else if (button == 1) {
            short* value = (short*)lookup->var;
            if (*value <= 0x7FFE) {
                *value = *value + 1;
            } else {
                *value = -0x8000;
            }
        }
    case 5:
        if (button == 0) {
            short* value = (short*)lookup->var;
            if (*value > 1) {
                *value = *value - 1;
            } else {
                *value = 1;
            }
        } else if (button == 1) {
            short* value = (short*)lookup->var;
            if (*value <= 7) {
                *value = *value + 1;
            } else {
                *value = 8;
            }
        }
        break;
    }
}

// 0x80026454
void ECheatDMI::ButtonPress(int button, float amount) {
    int scaled = (int)(amount * 10.0f);
    int step;
    if (scaled > 0) {
        step = scaled;
        if (step > 10) {
            step = 10;
        }
    } else {
        step = 1;
    }
    switch (lookup->type) {
    case 1:
        break;
    case 2: {
        unsigned char* value = (unsigned char*)lookup->var;
        int v = *value;
        if (button == 0) {
            v -= step;
        } else {
            v += step;
        }
        if (v >= 0) {
            if (v > 0xFF) {
                v = 0xFF;
            }
        } else {
            v = 0;
        }
        *value = v;
        break;
    }
    case 3: {
        signed char* value = (signed char*)lookup->var;
        int v = *value;
        if (button == 0) {
            v -= step;
        } else {
            v += step;
        }
        if (v >= -0x80) {
            if (v > 0x7F) {
                v = 0x7F;
            }
        } else {
            v = -0x80;
        }
        *value = v;
        break;
    }
    case 4: {
        short* value = (short*)lookup->var;
        int v = *value;
        if (button == 0) {
            v -= step;
        } else {
            v += step;
        }
        if (v >= -0x8000) {
            if (v > 0x7FFF) {
                v = 0x7FFF;
            }
        } else {
            v = -0x8000;
        }
        *value = v;
        break;
    }
    }
}
