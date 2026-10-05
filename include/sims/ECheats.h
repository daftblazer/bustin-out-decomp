#ifndef SIMS_ECHEATS_H
#define SIMS_ECHEATS_H

#include "sims/EGlobal.h"

extern "C" {
void* fn_80111C78(void* dst, int value, unsigned int size); // memset
int fn_80111ECC(const char* a, const char* b);              // strcmp
char* fn_80111F74(char* dst, const char* src);              // strcpy
void fn_80112064(char* text);                               // lower-case in place
int fn_80110874(const char* text);                          // atoi
int fn_8010F710(char* out, const char* format, ...);        // sprintf
int fn_801AE714(const char* text);                          // string hash
}

// Base of the debug menu's entries: two links, then the vtable pointer
// (constructor 0x8015E8BC). Name inferred from ECheatDMI in The Sims 2.
class EDebugMenuItem {
public:
    EDebugMenuItem();
    void* unk0;
    void* unk4;
    virtual void GetDescription(char* out) = 0;
    virtual void GetValue(char* out) = 0;
    virtual void ButtonPress(int button) = 0;
    virtual void ButtonPress(int button, float amount) = 0;
};

// The debug menu (0x8033F66C).
struct Unk8033F66C {
    void fn_8015E904(EDebugMenuItem* item); // add
    void fn_8015E94C(EDebugMenuItem* item); // remove
    char unk0[0x1C];
};
extern Unk8033F66C lbl_8033F66C;

class ECheatDMI;

// One named setting: an entry of ECheats' hash table (0x54 bytes). Class and
// method names from The Sims 2's symbol map.
class ECheatLookup {
public:
    ECheatLookup();
    static int hash(const char* name);
    int compare(const char* name) const;

    ECheatLookup* next;
    char name[0x40];
    int type;        // 1 bool, 2 byte, 3 signed byte, 4 short, 5 small count, 6 string
    void* var;
    ECheatDMI* dmi;  // its debug menu entry while the menu is enabled
    int unk50;       // shown in the debug menu
};

// Debug menu entry that edits one ECheatLookup.
class ECheatDMI : public EDebugMenuItem {
public:
    ECheatDMI(ECheatLookup* lookup_) { lookup = lookup_; }
    virtual void GetDescription(char* out);
    virtual void GetValue(char* out);
    virtual void ButtonPress(int button);
    virtual void ButtonPress(int button, float amount);

    ECheatLookup* lookup;
};

// A list of up to sixteen values (constructor 0x8002436C); ECheats keeps 65 of them.
struct Unk8002436C {
    Unk8002436C();
    void fn_800243B0(int value); // append
    void fn_800243D0();          // clear

    int count;
    int values[16];
};

struct Unk80024410Entry {
    void Reset() {
        list.fn_800243D0();
        unk44 = 0;
    }
    Unk8002436C list;
    void (*unk44)(int);
    int unk48;
};

// The hash table itself; its constructor and destructor are inline.
struct ECheatTable {
    ECheatTable() { fn_80111C78(buckets, 0, sizeof(buckets)); }
    ~ECheatTable() {
        for (int i = 0; i <= 0x3F; i++) {
            ECheatLookup* lookup = buckets[i];
            if (lookup) {
                buckets[i] = 0;
                do {
                    ECheatLookup* dead = lookup;
                    lookup = lookup->next;
                    delete dead;
                } while (lookup);
            }
        }
    }
    ECheatLookup* buckets[0x40];
};

// Position in ECheats' table.
struct ECheatIterator {
    ECheatIterator() {}
    ECheatIterator(class ECheats* table_) {
        bucket = 0;
        node = 0;
        table = table_;
    }
    bool operator==(const ECheatIterator& other) const {
        return bucket == other.bucket && node == other.node && table == other.table;
    }
    inline void Next();

    class ECheats* table;
    int bucket;
    ECheatLookup* node;
};

// Named game settings ("cheats") that can be set from /runtime/system.cnf and
// edited in the debug menu. Class and most method names from The Sims 2.
class ECheats {
public:
    ECheats();
    ~ECheats();
    void Init(EGlobal& global);
    void Reset();
    void EmptyLookupList();
    void ReadCheatsFile();
    void WriteCheatsFile();
    void fn_80025A68(const Unk8002436C& list, void (*callback)(int), int arg);
    void Update();
    void fn_80025B14();
    void EnableCheats();
    void DisableCheats();

    inline ECheatIterator begin();
    ECheatIterator end() {
        ECheatIterator it(this);
        it.bucket = 0x40;
        return it;
    }
    void Insert(ECheatLookup* lookup) {
        int index = fn_801AE714(lookup->name) & 0x3F;
        lookup->next = table.buckets[index];
        table.buckets[index] = lookup;
    }

    ECheatTable table;
    int unk100;                 // set once the settings file has been read
    int unk104;                 // debug menu shown
    Unk8002436C unk108;
    int unk14C;                 // number of entries used
    Unk80024410Entry unk150[0x40];
};

#define ECHEAT_FIND_BUCKET(it) \
    if ((it).bucket <= 0x3F) { \
        if ((it).table->table.buckets[(it).bucket]) { \
            (it).node = (it).table->table.buckets[(it).bucket]; \
        } else { \
            for (;;) { \
                (it).bucket++; \
                if ((it).bucket > 0x3F) { \
                    break; \
                } \
                if ((it).table->table.buckets[(it).bucket]) { \
                    (it).node = (it).table->table.buckets[(it).bucket]; \
                    break; \
                } \
            } \
        } \
    }

inline ECheatIterator ECheats::begin() {
    ECheatIterator it(this);
    it.bucket = 0;
    ECHEAT_FIND_BUCKET(it)
    return it;
}

inline void ECheatIterator::Next() {
    if (node) {
        node = node->next;
        if (node == 0) {
            bucket++;
        }
    }
    if (node == 0) {
        ECHEAT_FIND_BUCKET(*this)
    }
}

void fn_80024404(int value);

#endif
