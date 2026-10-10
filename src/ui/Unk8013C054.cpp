// UI library (Flash-style display list), 0x8013C054-0x801440C4. Compiled at -O0.
//
// Functions are in address order, and that matters: at -O0 this compiler leaves state behind from one function to the next.
// Whether a void function ends in two unreachable branches (`b; b`) depends on what came before it in the file: a `switch`
// turns them on, and a function that returns the value of a variable (`return c;`, `return r;`, `return global;`) turns them off.
// A `return f(x);` or a constant does not. So a near miss that is only a pair of branches off usually means a function
// that is not written yet (or one out of order) sits earlier in the unit.

struct UiShape;
// per-character data block (first word is the clip depth)
struct UiClip {
    int clipDepth;           // 0x00
    int unk4;
    UiShape* shape;          // 0x08
    int unkC;
    int unk10;
    void* text;              // 0x14
};

struct UiRect {
    float xmin, ymin, xmax, ymax;
};

struct UiProps {
    float f[12];             // f[11] (0x2C) is _visible
    static void* operator new(unsigned n);   // 0x80142DC8
};

struct UiObj {
    unsigned flags;          // 0x00 type in the low 15 bits, 0x8000 = alternate flag
    int depth;               // 0x04
    int name;                // 0x08
    char padC[0x44 - 0xC];
    struct UiProps* props;   // 0x44
    void* parent;            // 0x48
    UiClip* clip;            // 0x4C
    UiObj* prev;             // 0x50
    UiObj* next;             // 0x54
    int unk58;               // 0x58
    int unk5C;               // 0x5C
    UiObj(int type, unsigned fill, int zero);   // 0x8012C21C
    static void* operator new(unsigned n);       // 0x8012C3F4
    UiClip* GetClip();
    void GetBounds(UiRect* out);
    void DrawForBounds(void* ctx, void* out);
    void Draw(void* ctx, int flag);
    void Unk80140DC4();
    void Unk80141040(int idx, float v);
    UiClip* GetDataE();       // 0x80131FCC
    UiClip* GetTextData();    // 0x8013356C
    UiClip* GetShapeData();   // 0x80131FF8
    int IsType11();
    int IsType7();
    int IsType6();
    int IsTypeC();
    int IsTypeF();
    int IsType10();
};

struct UiClipStack {
    UiObj* items[32];        // 0x00
    int count;               // 0x80
    UiClipStack();
    void Free(register int flag);
    void Insert(UiObj* o);
    void Remove(int i);
    UiObj* At(int i);
    int Count();
};

struct UiAllocTable {
    void* (*alloc)(unsigned);        // 0x00
    void* slot4;                     // 0x04
    void (*free)(void*, unsigned);   // 0x08
    char pad0C[0x10 - 0x0C];
    void (*slot10)(int);             // 0x10
    char pad14[0x24 - 0x14];
    void (*slot24)(void*);           // 0x24
    char pad28[0x44 - 0x28];
    void (*drawText)(void*);         // 0x44
    char pad48[0x50 - 0x48];
    void (*slot50)(void*);           // 0x50
    char pad54[0x70 - 0x54];
    void (*twoPart)(void*);          // 0x70
    void (*drawShape)(void*, void*); // 0x74
    void (*slot78)(void*, void*, void*); // 0x78
};
extern UiAllocTable lbl_8033D1E0;
extern void* lbl_8037D124;     // -0x62bc(r13): context that collects bounds instead of drawing

extern "C" UiObj* fn_8012C21C(void* mem, int type, unsigned fill, int zero);
extern "C" void* fn_8012C3F4(unsigned n);
extern "C" void fn_8012CA5C(UiObj* o, int zero);
extern "C" void fn_8012C544(void* self);
extern "C" void fn_80139E1C(void* self);

// head of a sibling list: a dummy UiObj whose next is the first child
struct UiHead {
    UiObj* first;            // 0x00
    static void* operator new(unsigned n);
    static void Delete(void* p, unsigned n);
    UiHead();
    void Destroy(int flag);
    static void Free(UiHead* p);
};

// base of the per-character data blocks (0x8012C544)
struct UiBase {
    int unk0;
    int parentDepth;         // 0x04: depth of the clip the character sits in, -1 for none
    void* res;               // 0x08: the character definition
    int unkC;
    UiBase();
};

extern "C" void fn_8012C800(UiObj* o);

// open-addressed set of instances, 256 slots (0x8013E24C-0x8013E2C4) and 128 slots (0x8013E370-0x8013E3E8)
struct UiObjSet256 {
    int count;               // 0x00
    UiObj* items[256];       // 0x04
    int Contains(UiObj* o);
    void Add(UiObj* o);
};
struct UiObjSet128 {
    int count;               // 0x00
    UiObj* items[128];       // 0x04
    int Contains(UiObj* o);
    void Add(UiObj* o);
};

// a drawable piece: 1 = shape, 0xB = empty
struct UiShape {
    int type;                // 0x00
    int unk4;
    char bounds[0x10];       // 0x08
    void* data;              // 0x18
    void Draw(void* ctx, void* flag, void* matrix);
    void DrawMask(void* ctx, void* flag, void* matrix);
};
extern "C" void fn_80147A70(void* ctx, void* flag, void* bounds);

struct UiAction {
    int type;                // 0x00
    int arg;                 // 0x04
};
struct UiFrame {
    int count;               // 0x00
    UiAction** items;        // 0x04
};
// timeline of a movie clip: one UiFrame per frame (8 bytes each)
extern "C" void* fn_8012D6E0(void* dict, int name);
extern "C" int fn_801321E4(void* v);

struct UiTimeline {
    int unk0;
    UiFrame* frames;         // 0x04
    void* names;             // 0x08
    void RunFrameA(int a, int frame);
    void RunFrameB(int a, int frame);
    int Lookup(int name);
};
extern char lbl_8033D2A8[];          // graphics state
extern void* lbl_8037D0F4;           // -0x62ec(r13): the player context
extern void* lbl_8037BE84;           // -0x755c(r13)
extern "C" void fn_8014ADB4(void* gfx, int arg, int a, int b);
extern "C" void fn_801396A4(void* player, void* arg, int a, void* b);

struct UiDisplayList {
    UiHead* head;            // 0x00
    UiDisplayList();
    ~UiDisplayList();
    void Clear();
    void Update();
    void DrawUnmasked(void* ctx, int flag);
    UiHead* GetHead();
    void SetHead(UiHead* h);
    void Release(UiObj* o);
    void Remove(int id);
    void RemoveDynamic(UiObj* id);
    void RemoveHandle(int* id);
    void DrawOne(void* ctx, UiObj* o, int flag);
    void Draw(void* ctx, int flag);
};

struct UiDataA : UiBase {
    int unk10;               // 0x10
    int unk14;
    UiDisplayList list;      // 0x18
    UiDataA();
    static void* operator new(unsigned n);
};
struct UiDataB : UiBase {
    int unk10, unk14, unk18, unk1C;
    int unk20;
    UiDataB();
    static void* operator new(unsigned n);
};
struct UiDataC : UiBase {
    int frame;               // 0x10
    unsigned flags14;        // 0x14
    int unk18, unk1C;
    UiDataC();
    static void* operator new(unsigned n);
};
struct UiDataD : UiBase {
    UiDataD();
    static void* operator new(unsigned n);
};
struct UiDataE : UiBase {
    UiDataE();
    static void* operator new(unsigned n);
};
struct UiDataF : UiBase {
    int unk10;
    UiDataF();
    static void* operator new(unsigned n);
};

extern "C" void fn_8013BCEC(UiHead* head, int id, int zero, void* outA, UiObj** outB);
extern "C" void* fn_80151A24(void* parent);
extern "C" UiObj* fn_8012D820(void* dict, int name);
extern "C" void fn_8012D480(void* dict, int name);
extern "C" void fn_80132F5C(UiObj* o);


extern "C" int fn_8012C7C8(UiObj* o);
extern "C" int fn_8012C8A4(UiObj* o);
extern "C" int fn_80139D88(UiObj* o);
extern "C" void fn_8014747C(void* ctx);
extern "C" void fn_801475C0(void* ctx, void* cxform);
extern "C" void fn_80147764(void* ctx);
extern "C" void fn_80147A00(void* ctx, void* matrix);
extern "C" void fn_8014041C(UiObj* o, void* ctx, int flag);
extern "C" void fn_801477DC(void* ctx);
extern "C" void fn_80147520(void* ctx);

extern "C" void fn_80133A14(UiObj* o);

extern "C" int fn_80132114(UiObj* o, int flag);
extern "C" int fn_8013209C(UiObj* o, int flag);
extern "C" void fn_80140BBC(UiObj* o, void* ctx, int flag);
extern "C" void fn_80146B8C(UiObj* o);

#define UI_TYPE_TEST(name, t) \
    int UiObj::name() { \
        register int r = 0; \
        if (fn_8012C7C8(this) == t && !fn_8012C8A4(this)) { \
            r = 1; \
        } \
        return r; \
    }

extern "C" void* fn_80131FCC(UiObj* o);
extern "C" void* fn_80131FF8(UiObj* o);
extern "C" UiClip* fn_8013356C(UiObj* o);


// data block of a movie clip (type 0xD/0x12), as UiObj::Draw sees it
struct UiMovieData {
    int clipDepth;           // 0x00
    int unk4;
    struct UiMovieRes* res;  // 0x08 definition; its UiTimeline starts at +8
    void* dict;              // 0x0C member dictionary (swapped for a scratch object while rewinding)
    int frame;               // 0x10 current frame
    unsigned pad14 : 25;     // 0x14
    unsigned stopped : 1;    // set by 0x801411C4 from its third argument
    unsigned mode : 2;       // 1 = drawn by the host, 2 = drawn here
    unsigned rest14 : 4;
    int unk18;
    UiDisplayList list;      // 0x1C
};
struct UiFontTable;
struct UiMovieRes {
    int unk0;
    struct UiFontTable* fonts; // 0x04
    UiTimeline tl;           // 0x08: unk0 = frame count
};
struct UiFont {
    int unk0;
    int unk4;
    void* handle;            // 0x08 host font
    int unkC;
    UiShape** glyphs;        // 0x10
};
struct UiGlyph {
    short index;
    short advance;
};
struct UiTextRec {
    int font;                // 0x00
    char cx[0x20];           // 0x04
    float x;                 // 0x24
    float y;                 // 0x28
    float h;                 // 0x2C
    int count;               // 0x30
    UiGlyph* glyphs;         // 0x34
};
struct UiTextRes {
    int unk0;
    struct UiFontTable* fonts; // 0x04
    char pad[0x30 - 8];
    int count;               // 0x30
    char* recs;              // 0x34 records of 0x38 bytes
};
struct UiFontTable {
    char pad[0x18];
    UiFont** items;          // 0x18
};
struct UiTextData {
    int unk0;
    int unk4;
    UiTextRes* res;          // 0x08
};
struct UiTwoPart {
    int unk0;
    int unk4;
    struct UiTwoRes* res;    // 0x08
    char pad[0x10 - 0xC];
    float ratio;             // 0x10
};
struct UiTwoRes {
    char pad[8];
    UiShape* a;              // 0x08
    UiShape* b;              // 0x0C
};
struct UiOneShape {
    int unk0;
    int unk4;
    UiShape* shape;          // 0x08
};
struct UiMat {
    float f[6];
};
extern UiMat lbl_8033D270;
extern "C" void fn_801475C0(void* ctx, void* cx);
extern "C" void* fn_80149C3C(void* gfx, UiObj* o, int a, const char* name, int b, int c);
extern "C" void* fn_80131E8C(void* v);
extern "C" void* fn_8012D9C4(void* v);
extern "C" void fn_80139B58(void* list, UiObj* o, void* m);
extern "C" void fn_8013FD90(UiObj* o, void* parent);
extern "C" void fn_801476B4(void* ctx, void* m);
extern "C" UiTextData* fn_80133598(UiObj* o);
extern "C" UiTwoPart* fn_801335C4(UiObj* o);
extern "C" UiOneShape* fn_801335F0(UiObj* o);
extern void (*lbl_802D67B4[])(void*);

extern "C" UiMovieData* fn_8013DD0C(UiObj* o);

#define UI_REC ((UiTextRec*)(td->res->recs + i * 0x38))

extern "C" float fn_8010E288(float a);
extern "C" float fn_8010E450(float a);

extern "C" float fn_8010DD60(float y, float x);

extern "C" void fn_8013D104(UiDisplayList* list, void* remove);

// PlaceObject command (an UiAction body): flags, depth, character, optional matrix / colour transform / ratio / name / clip actions
struct UiPlace {
    unsigned flags;          // 0x00: 1 move, 2 create, 4 matrix, 8 colour transform, 0x20 ratio-style int at 0x30, 0x40/0x80 name, clip actions
    int depth;               // 0x04
    int character;           // 0x08
    float matrix[6];         // 0x0C
    float cxform[2];         // 0x24 colour transform words
    float ratio;             // 0x2C
    int unk30;
    int unk34;
    int unk38;
};
extern "C" void fn_8013C8CC(register UiDisplayList* list, int a, int b, int c, int d, UiObj* parent, int e, int f, float ratio, void* cx, void* mat, int g);
extern "C" void fn_8013CB40(UiDisplayList* list, int a, int b, int c, int d, UiObj* parent, int e, int f, float ratio, void* cx, void* mat, int g);
extern "C" void fn_8013C690(void* dst, void* src);

extern "C" UiObj* fn_8012C154(void* h, int zero);
extern "C" void* fn_801489D4(void* gfx, int zero);
extern "C" int fn_80131EEC(void* v);
extern "C" void fn_801462CC(UiObj* o, int frame);
extern "C" void fn_8013D6A0(UiDisplayList* list, UiHead* a, void* b, void* c);
extern int lbl_8037D110;      // -0x62d0(r13): returned by the script natives

extern "C" void fn_8012C4A4(void* p, int n);
extern "C" void fn_80134B68(void* p, int n);

extern "C" UiObj* fn_8013BF10(UiHead* head, int depth, int type, void* data);
extern "C" void fn_8013BFCC(UiHead* head, int depth, UiObj* o);
extern "C" void* fn_8012C44C(int size);
extern "C" void* fn_8014FD8C(void* mem, const char* text);
extern "C" void fn_8012CEF0(void* set, void* key, UiObj* o);
extern "C" int fn_80111ECC(const char* a, const char* b);
extern "C" void fn_8013CF5C(UiDisplayList* list, UiObj* o);

// The object at 0x8037D0F8 (0x6708 bytes): a pool of 64 reference-counted entries (0x114 bytes each, count at +0x4500)
// and, after it, a table of named entries (0x110 bytes each from +0x4508, name at +0 and a key at +0x100, count at +0x4504).
struct UiPoolEntry {
    int used;                // 0x000
    char pad4[0x100 - 4];
    char* ptr100;            // 0x100
    void* ptr104;            // 0x104
    int unk108;              // 0x108
    int refs;                // 0x10C
    int unk110;
};
struct UiNameEntry {
    char name[0x100];        // 0x000
    int key;                 // 0x100
    char pad104[0x110 - 0x104];
};
struct UiNamedPool {
    UiPoolEntry pool[64];    // 0x0000
    int active;              // 0x4500
    int nameCount;           // 0x4504
    UiNameEntry names[32];   // 0x4508
    UiNameEntry* Unk801435F0(int key);
    UiNameEntry* Unk8014351C(const char* name);
    UiPoolEntry* Unk80143694(UiPoolEntry* e);
    UiPoolEntry* Unk8014373C(UiPoolEntry* e);
    UiPoolEntry* Unk801436DC(const char* name);
    void Unk801437F8(int key);
    int Unk8014384C(const char* name);
    void Unk801438A8(UiPoolEntry* e);
    UiPoolEntry* Unk80143B74();
    void Unk80143400(UiNameEntry* e);
    void Unk80143E30(int a, int b, int c, int d);
};
extern UiNamedPool* lbl_8037D0F8;     // -0x62e8(r13)
extern "C" void fn_80142ED8(const char* name, char* out);
extern "C" void fn_801375F8(void* a, int b);

// 0x8013C054: remove from the sibling list
extern "C" UiObj* fn_8013C054(UiObj* self) {
    if (self->prev) {
        self->prev->next = self->next;
    }
    if (self->next) {
        self->next->prev = self->prev;
    }
    self->prev = 0;
    self->next = 0;
    return self;
}

// 0x8013C0E0: create or reuse the instance at a depth for a PlaceObject, give it its character data, name and parent
// NON_MATCHING: the control flow, locals and calls follow the original (372 instructions against 364), but the flag updates on the new movie clip data reload the pointer, which shifts the rest of the function
extern "C" void fn_8013C0E0(register UiDisplayList* list, int depth, UiMovieRes* ch, const char* name, UiObj* parent,
                             int force, int userdata, UiObj** outObj, int* outCreated) {
    int created;
    UiObj* where;
    UiObj* found;
    UiObj* obj;
    UiBase* data;
    int type;
    created = 0;
    obj = 0;
    fn_8013BCEC(list->head, depth, (int)name, &where, &found);
    if (found) {
        if (force) {
            fn_8013CF5C(list, found);
            created = 1;
        } else if (fn_8012C8A4(found)) {
            if (name) {
                if (fn_80111ECC(name, (const char*)fn_8012D9C4((void*)found->name)) == 0) {
                    fn_8012CA5C(found, 1);
                    obj = found;
                }
            }
            created = 1;
        } else {
            obj = found;
            created = 0;
        }
    } else {
        created = 1;
    }
    if (created) {
        data = 0;
        if (*(int*)ch == 5) {
            UiDataC* d;
            data = d = new UiDataC;
            type = 0xD;
            d->frame = -1;
            d->flags14 |= 0x80;
            d->flags14 |= 0x40;
        } else if (*(int*)ch == 4) {
            UiDataA* d;
            data = d = new UiDataA;
            type = 0xE;
            d->unk14 = 0;
        } else if (*(int*)ch == 2) {
            UiDataB* d;
            data = d = new UiDataB;
            type = 0xF;
            data->res = ch;
            d->unk20 = *(int*)((char*)ch + 0x20);
        } else if (*(int*)ch == 10) {
            UiDataE* d;
            data = d = new UiDataE;
            type = 0x10;
        } else if (*(int*)ch == 1) {
            UiDataD* d;
            data = d = new UiDataD;
            type = 0xC;
        } else if (*(int*)ch == 8) {
            UiDataF* d;
            data = d = new UiDataF;
            type = 0x11;
        }
        if (fn_80132114(parent, 0)) {
            data->parentDepth = fn_8013DD0C(parent)->frame;
        } else {
            data->parentDepth = -1;
        }
        if (!obj) {
            obj = fn_8013BF10(list->head, depth, type, data);
        } else {
            if (depth != obj->depth) {
                fn_8013C054(obj);
                fn_8013BFCC(list->head, depth, obj);
                (*(void (**)(void*))((char*)lbl_802D67B4 + fn_8012C7C8(obj) * 4))(obj);
            }
            obj->clip = (UiClip*)data;
        }
        if (type == 0xD || type == 0xE) {
            int* counter = (int*)((char*)lbl_8037D0F4 + 0x1808);
            *(UiObj**)((char*)lbl_8037D0F4 + 0x1408 + *counter * 4) = obj;
            (*counter)++;
            fn_8012C800(obj);
        } else if (type == 0xF) {
            fn_8013FD90(obj, parent);
        }
        if (name) {
            void* str = fn_8014FD8C(fn_8012C44C(8), name);
            if (obj->name) {
                (*(void (**)(void*))((char*)lbl_802D67B4 + fn_8012C7C8((UiObj*)obj->name) * 4))((void*)obj->name);
            }
            obj->name = (int)str;
            fn_8012C800((UiObj*)str);
            fn_8012CEF0(((UiClip*)fn_80131FF8(parent))->shape, str, obj);
        }
    }
    fn_8012C800(parent);
    if (obj->parent) {
        (*(void (**)(void*))((char*)lbl_802D67B4 + fn_8012C7C8((UiObj*)obj->parent) * 4))(obj->parent);
    }
    obj->parent = parent;
    obj->clip->shape = (UiShape*)ch;
    obj->clip->clipDepth = userdata;
    *outObj = obj;
    *outCreated = created;
}

// 0x8013C8CC: PlaceObject helper: copy the colour transform record into a local object, then create or update the instance
extern "C" void fn_8013C8CC(register UiDisplayList* list, int a, int b, int c, int d, UiObj* parent, int e, int f, float ratio, void* cx, void* mat, int g) {
    char copy[0x20];
    void* p;
    if (cx) {
        fn_8013C690(copy, cx);
        fn_8013CB40(list, a, b, c, d, parent, e, f, ratio, copy, mat, g);
    } else {
        p = 0;
        fn_8013CB40(list, a, b, c, d, parent, e, f, ratio, p, mat, g);
    }
}

// 0x8013CD18: run one PlaceObject command
extern "C" void fn_8013CD18(register UiDisplayList* list, UiPlace* rec, UiObj* parent) {
    if (rec->flags & 2) {
        int ch = (int)((UiMovieRes*)parent->clip->shape)->fonts->items[rec->character];
        fn_8013C8CC(list, 0, rec->depth, ch, rec->flags & 0x20 ? rec->unk30 : 0, parent, 0, rec->unk34, rec->ratio,
                    rec->flags & 8 ? &rec->cxform : 0, rec->flags & 4 ? &rec->matrix : 0, rec->flags & 0x80 ? rec->unk38 : 0);
    } else if (rec->flags & 1) {
        int found;
        UiObj* where;
        fn_8013BCEC(list->head, rec->depth, 0, &found, &where);
        fn_8013C8CC(list, (int)where, 0, 0, 0, parent, 0, -1, rec->ratio,
                    rec->flags & 8 ? &rec->cxform : 0, rec->flags & 4 ? &rec->matrix : 0, rec->flags & 0x80 ? rec->unk38 : 0);
    }
}

// 0x8013CF5C: drop an instance from its parent's name table and free it
void UiDisplayList::Release(UiObj* o) {
    if (o && !fn_8012C8A4(o)) {
        void* par = o->parent;
        void* dict;
        if (par) {
            dict = fn_80151A24(par);
            if (o->name) {
                if (fn_8012D820(dict, o->name) == o) {
                    fn_8012D480(dict, o->name);
                }
            }
        }
        fn_80132F5C(o);
    }
}

// 0x8013D020
void UiDisplayList::Remove(int id) {
    int a;
    UiObj* b;
    fn_8013BCEC(head, id, 0, &a, &b);
    Release(b);
}

// 0x8013D080: release an instance only when it was made at run time (depth above 0x3FFF)
void UiDisplayList::RemoveDynamic(UiObj* id) {
    int a = 0;
    UiObj* b = 0;
    fn_8013BCEC(head, id->depth, 0, &a, &b);
    if (b->depth > 0x3FFF) {
        Release(b);
    }
}

// 0x8013D104
void UiDisplayList::RemoveHandle(int* id) {
    Remove(*id);
}

// 0x8013D148
UiDisplayList::UiDisplayList() {
    head = new UiHead;
}

// 0x8013D198
UiDisplayList::~UiDisplayList() {
    Clear();
    UiHead::Free(head);
}

// 0x8013D1F8: draw one object with its own colour transform and matrix
void UiDisplayList::DrawOne(void* ctx, UiObj* o, int flag) {
    fn_8014747C(ctx);
    fn_801475C0(ctx, (char*)o + 0x24);
    fn_80147764(ctx);
    fn_80147A00(ctx, (char*)o + 0xc);
    fn_8014041C(o, ctx, flag);
    fn_801477DC(ctx);
    fn_80147520(ctx);
}

// 0x8013D28C: draw the children in order; an object with a clip depth masks everything up to it
void UiDisplayList::Draw(void* ctx, int flag) {
    UiObj* cur = head->first->next;
    UiClipStack stack;
    while (cur) {
        if (!fn_8012C8A4(cur) && !fn_80139D88(cur)) {
            if (cur->clip->clipDepth >= 0) {
                stack.Insert(cur);
                DrawOne(ctx, cur, 1);
            } else {
                while (stack.Count() > 0 && stack.At(stack.Count() - 1)->clip->clipDepth < cur->depth) {
                    DrawOne(ctx, stack.At(stack.Count() - 1), -1);
                    stack.Remove(stack.Count() - 1);
                }
                DrawOne(ctx, cur, flag);
            }
        } else {
        }
        cur = cur->next;
    }
    while (stack.Count() > 0) {
        DrawOne(ctx, stack.At(0), -1);
        stack.Remove(0);
    }
    stack.Free(2);
}

// 0x8013D4AC: draw the children that are not clip layers
void UiDisplayList::DrawUnmasked(void* ctx, int flag) {
    UiObj* cur = head->first->next;
    while (cur) {
        if (cur->clip->clipDepth < 0) {
            fn_80140BBC(cur, ctx, flag);
        }
        cur = cur->next;
    }
}

// 0x8013D538
void UiDisplayList::Update() {
    UiObj* cur = head->first->next;
    while (cur) {
        if (fn_80132114(cur, 0) || fn_8013209C(cur, 0)) {
            fn_80146B8C(cur);
        }
        cur = cur->next;
    }
}

// 0x8013D5D4: release every child
void UiDisplayList::Clear() {
    UiObj* cur = head->first->next;
    UiObj* nx;
    while (cur) {
        nx = cur->next;
        Release(cur);
        cur = nx;
    }
}

// 0x8013D648
UiHead* UiDisplayList::GetHead() {
    return head;
}

// 0x8013D674
void UiDisplayList::SetHead(UiHead* h) {
    head = h;
}

// 0x8013DD0C
UiClip* UiObj::GetClip() {
    return clip;
}

// 0x8013DD38
UI_TYPE_TEST(IsType11, 0x11)

// 0x8013DDA0
UiHead::UiHead() {
    first = new UiObj(7, 0xBAADF00D, 0);
    fn_8012CA5C(first, 0);
    first->depth = -1;
    first->next = 0;
    first->prev = 0;
}

// 0x8013DE30
void* UiHead::operator new(register unsigned n) {
    void* (*f)(unsigned) = lbl_8033D1E0.alloc;
    return f(n);
}

// 0x8013DE88
UiDataA::UiDataA() {
    unk10 = 0;
}

// 0x8013DEDC
void* UiDataA::operator new(register unsigned n) {
    return lbl_8033D1E0.alloc(n);
}

// 0x8013DF34
UiDataB::UiDataB() {
    unk10 = 0;
    unk14 = 0;
    unk18 = 0;
    unk1C = 0;
}

// 0x8013DF94
void* UiDataB::operator new(register unsigned n) {
    return lbl_8033D1E0.alloc(n);
}

// 0x8013DFEC
UiDataC::UiDataC() {
}

// 0x8013E02C
void* UiDataC::operator new(register unsigned n) {
    return lbl_8033D1E0.alloc(n);
}

// 0x8013E084
UiDataD::UiDataD() {
}

// 0x8013E0C4
void* UiDataD::operator new(register unsigned n) {
    return lbl_8033D1E0.alloc(n);
}

// 0x8013E11C
UiDataE::UiDataE() {
}

// 0x8013E15C
void* UiDataE::operator new(register unsigned n) {
    return lbl_8033D1E0.alloc(n);
}

// 0x8013E1B4
UiDataF::UiDataF() {
}

// 0x8013E1F4
void* UiDataF::operator new(register unsigned n) {
    return lbl_8033D1E0.alloc(n);
}

// 0x8013E24C
int UiObjSet256::Contains(register UiObj* o) {
    int i = 0;
    while (i <= 255) {
        if (items[i] == o) {
            return 1;
        }
        i++;
    }
    return 0;
}

// 0x8013E2C4
void UiObjSet256::Add(register UiObj* o) {
    int i;
    count++;
    i = count;
    while (items[i] != 0) {
        if (i <= 254) {
            i++;
        } else {
            i = 0;
        }
    }
    items[i] = o;
    fn_8012C800(o);
}

// 0x8013E370
int UiObjSet128::Contains(register UiObj* o) {
    int i = 0;
    while (i <= 127) {
        if (items[i] == o) {
            return 1;
        }
        i++;
    }
    return 0;
}

// 0x8013E3E8
void UiObjSet128::Add(register UiObj* o) {
    int i;
    count++;
    i = count;
    while (items[i] != 0) {
        if (i <= 126) {
            i++;
        } else {
            i = 0;
        }
    }
    items[i] = o;
    fn_8012C800(o);
}

// 0x8013E494
void UiHead::Free(register UiHead* p) {
    if (p) {
        p->Destroy(3);
        return;
    }
}

// 0x8013E4DC
UiClipStack::UiClipStack() {
    count = 0;
}

// 0x8013E50C
void UiClipStack::Free(register int flag) {
    if (flag & 1) {
        delete this;
        return;
    }
}

// 0x8013E558: insert, kept sorted by clip depth (largest first)
void UiClipStack::Insert(register UiObj* o) {
    int i;
    int j;
    for (i = 0; i < count && items[i]->clip->clipDepth >= o->clip->clipDepth; i++) {
    }
    for (j = count; j > i; j--) {
        items[j] = items[j - 1];
    }
    items[i] = o;
    count++;
}

// 0x8013E640
void UiClipStack::Remove(register int i) {
    while (i < count - 1) {
        items[i] = items[i + 1];
        i++;
    }
    count--;
}

// 0x8013E6A8
UiObj* UiClipStack::At(register int i) {
    return items[i];
}

// 0x8013E6E0
int UiClipStack::Count() {
    return count;
}

// 0x8013E70C
void UiHead::Destroy(register int flag) {
    fn_80133A14(first);
    if (flag & 1) {
        Delete(this, 4);
    }
}

// 0x8013E760
void UiHead::Delete(register void* p, register unsigned n) {
    lbl_8033D1E0.free(p, n);
}

// 0x8013F62C: run the commands of one frame of a timeline (type 3 place object, 4 remove object, 5 and 6 host calls)
extern "C" void fn_8013F62C(register UiTimeline* tl, UiDisplayList* list, UiObj* o, int frame) {
    int i = 0;
    UiAction* act;
    while (i < tl->frames[frame].count) {
        act = tl->frames[frame].items[i];
        switch (act->type) {
        case 5:
            lbl_8033D1E0.slot10(act->arg);
            break;
        case 3:
            fn_8013CD18(list, (UiPlace*)&act->arg, o);
            break;
        case 1:
        case 2:
            break;
            break;
        case 4:
            fn_8013D104(list, &act->arg);
            break;
            break;
        case 6:
            lbl_8033D1E0.slot50(((UiMovieRes*)o->clip->shape)->fonts->items[act->arg]->handle);
            break;
        case 7:
        case 8:
            break;
        }
        i++;
    }
}

// 0x8013F7E4
void UiTimeline::RunFrameA(int a, int frame) {
    int i = 0;
    UiAction* act;
    while (i < frames[frame].count) {
        act = frames[frame].items[i];
        if (act->type == 1) {
            fn_8014ADB4(lbl_8033D2A8, act->arg, a, -1);
        }
        i++;
    }
}

// 0x8013F8C0
void UiTimeline::RunFrameB(int a, int frame) {
    int i = 0;
    UiAction* act;
    while (i < frames[frame].count) {
        act = frames[frame].items[i];
        if (act->type == 1) {
            fn_801396A4(lbl_8037D0F4, &act->arg, a, lbl_8037BE84);
        }
        i++;
    }
}

// 0x8013F99C: frame number of a named label, -1 when missing
int UiTimeline::Lookup(int name) {
    void* v = fn_8012D6E0(names, name);
    if (v) {
        return fn_801321E4(v);
    } else {
        return -1;
    }
}

// 0x8013FAF4: draw a shape through host slot 0x74
void UiShape::Draw(void* ctx, void* flag, void* matrix) {
    if (matrix) {
        fn_80147764(ctx);
        fn_80147A00(ctx, matrix);
    }
    switch (type) {
    case 1:
        lbl_8033D1E0.drawShape(data, flag);
        break;
        break;
    case 0xB:
        break;
    }
    if (matrix) {
        fn_801477DC(ctx);
    }
}

// 0x8013FBB4: same walk for the mask pre-pass
void UiShape::DrawMask(void* ctx, void* flag, void* matrix) {
    if (matrix) {
        fn_80147764(ctx);
        fn_80147A00(ctx, matrix);
    }
    switch (type) {
    case 1:
        fn_80147A70(ctx, flag, (char*)this + 8);
        break;
    case 0xB:
        break;
    }
    if (matrix) {
        fn_801477DC(ctx);
    }
}

// 0x8014041C: draw one object, by type
void UiObj::Draw(void* ctx, int flag) {
    if (props && !(props->f[11] >= 0.5f)) {
        return;
    }
    if (fn_80132114(this, 0)) {
        UiMovieData* md = fn_8013DD0C(this);
        void* t;
        if (md->mode == 0) {
            t = md->dict ? fn_8012D6E0(md->dict, (int)"_type") : 0;
            if (t) {
                md->mode = 1;
            } else {
                md->mode = 2;
            }
        }
        if (md->mode == 1) {
            UiObj* first;
            void* a;
            register UiAllocTable* tbl;
            register void* b;
            register void* c;
            t = md->dict ? fn_8012D6E0(md->dict, (int)"_type") : 0;
            first = md->list.head->first->next;
            a = fn_80149C3C(lbl_8033D2A8, this, 0, "_target", 1, 1);
            fn_8012C800((UiObj*)a);
            tbl = &lbl_8033D1E0;
            b = fn_8012D9C4(fn_80131E8C(t));
            c = fn_8012D9C4(fn_80131E8C(a));
            tbl->slot78(b, c, fn_801335F0(first)->shape->data);
            (*(void (**)(void*))((char*)lbl_802D67B4 + fn_8012C7C8((UiObj*)a) * 4))(a);
        } else {
            md->list.Draw(ctx, flag);
        }
    } else if (fn_8013209C(this, 0)) {
        float m[6];
        void* d;
        fn_801476B4(ctx, m);
        fn_80139B58(lbl_8037D0F4, this, m);
        d = fn_80131FCC(this);
        ((UiDisplayList*)((char*)d + 0x18))->Draw(ctx, flag);
    } else if (IsTypeF()) {
        UiClip* td = fn_8013356C(this);
        fn_8013FD90(this, parent);
        if (td->text) {
            lbl_8033D1E0.drawText(td->text);
        }
    } else if (IsType10()) {
        UiTextData* td = fn_80133598(this);
        UiMat m;
        float fx, fy, adv, h;
        int i, j;
        fn_80147764(ctx);
        fn_80147A00(ctx, (char*)td->res + 0x18);
        m = lbl_8033D270;
        fx = -100000000.0f;
        fy = -100000000.0f;
        adv = 0.0f;
        h = 1.0f;
        i = 0;
        while (i < td->res->count) {
            UiFont* font;
            fn_8014747C(ctx);
            fn_801475C0(ctx, td->res->recs + i * 0x38 + 4);
            font = td->res->fonts->items[UI_REC->font];
            if (fx != UI_REC->x || fy != UI_REC->y) {
                adv = 0.0f;
                h = 1.0f;
            }
            fx = UI_REC->x;
            fy = UI_REC->y;
            h = UI_REC->h;
            j = 0;
            while (j < UI_REC->count) {
                UiGlyph* g;
                m.f[4] = fx + adv;
                m.f[5] = fy;
                m.f[0] = h;
                m.f[3] = h;
                g = &UI_REC->glyphs[j];
                font->glyphs[g->index]->Draw(ctx, (void*)flag, &m);
                adv = adv + g->advance * 0.05f;
                j++;
            }
            fn_80147520(ctx);
            i++;
        }
        fn_801477DC(ctx);
    } else if (IsType11()) {
        UiTwoPart* tp = fn_801335C4(this);
        fn_8014747C(ctx);
        *(float*)ctx = 1.0f - tp->ratio;
        lbl_8033D1E0.twoPart(ctx);
        tp->res->a->Draw(ctx, (void*)flag, 0);
        *(float*)ctx = tp->ratio;
        lbl_8033D1E0.twoPart(ctx);
        tp->res->b->Draw(ctx, (void*)flag, 0);
        fn_80147520(ctx);
    } else if (IsTypeC()) {
        UiOneShape* os = fn_801335F0(this);
        os->shape->Draw(ctx, (void*)flag, 0);
    }
    return;
}

// 0x80140BBC: the mask/bounds pass; the same walk as the draw but nothing is rendered
void UiObj::DrawForBounds(void* ctx, void* out) {
    UiClip* data = GetShapeData();
    UiClip* td;
    fn_80147764(ctx);
    fn_80147A00(ctx, (char*)this + 0xC);
    if (fn_80132114(this, 0)) {
        td = GetClip();
        ((UiDisplayList*)((char*)td + 0x1C))->DrawUnmasked(ctx, (int)out);
    } else if (fn_8013209C(this, 0)) {
        td = GetDataE();
        ((UiDisplayList*)((char*)td + 0x18))->DrawUnmasked(ctx, (int)out);
    } else if (IsTypeF()) {
        td = GetTextData();
        if (td->text) {
            fn_80147A70(ctx, out, (char*)td->shape + 8);
        }
    } else {
        if (IsType11()) {
        } else {
            data->shape->DrawMask(ctx, out, 0);
        }
    }
    fn_801477DC(ctx);
}

// 0x80140D38: bounds {xmin, ymin, xmax, ymax} of an object, gathered by a draw pass with a collecting context
void UiObj::GetBounds(UiRect* out) {
    out->xmin = 1000000000.0f;
    out->xmax = -1000000000.0f;
    out->ymax = -1000000000.0f;
    out->ymin = 1000000000.0f;
    DrawForBounds(lbl_8037D124, out);
}

// 0x80140DC4: make the property block when there is none, from the object's matrix and colour transform
void UiObj::Unk80140DC4() {
    float a1, a2, angle, cs, sn, eps;
    if (!props) {
        props = new UiProps;
        props->f[0] = *(float*)((char*)this + 0x1C);
        props->f[1] = *(float*)((char*)this + 0x20);
        a1 = fn_8010DD60(*(float*)((char*)this + 0x10), *(float*)((char*)this + 0xC));
        a2 = fn_8010DD60(-*(float*)((char*)this + 0x14), *(float*)((char*)this + 0x18));
        angle = (a1 + a2) * 0.5f;
        props->f[6] = angle * 57.29578f;
        cs = fn_8010E288(angle);
        sn = fn_8010E450(angle);
        eps = 0.0001f;
        if (cs <= -0.0001f || cs >= 0.0001f) {
            props->f[2] = *(float*)((char*)this + 0xC) / cs * 100.0f;
            props->f[3] = *(float*)((char*)this + 0x18) / cs * 100.0f;
        } else if (sn <= -0.0001f || sn >= 0.0001f) {
            props->f[2] = *(float*)((char*)this + 0x10) / sn * 100.0f;
            props->f[3] = -*(float*)((char*)this + 0x14) / sn * 100.0f;
        } else {
            props->f[2] = 100.0f;
            props->f[3] = 100.0f;
        }
        props->f[7] = *(float*)((char*)this + 0x24) * 100.0f;
        props->f[8] = *(float*)((char*)this + 0x38) * 255.0f;
        props->f[9] = *(float*)((char*)this + 0x3C) * 255.0f;
        props->f[10] = *(float*)((char*)this + 0x40) * 255.0f;
        props->f[11] = 1.0f;
    }
}

// 0x80141040: set property idx of the object's property block, then rebuild its matrix and colour transform from it
void UiObj::Unk80141040(int idx, float v) {
    float angle, cs, sn, sx, sy;
    Unk80140DC4();
    idx[props->f] = v;
    angle = props->f[6] * 0.017453294f;
    cs = fn_8010E288(angle);
    sn = fn_8010E450(angle);
    sx = props->f[2] * 0.01f;
    sy = props->f[3] * 0.01f;
    *(float*)((char*)this + 0xC) = sx * cs;
    *(float*)((char*)this + 0x10) = sx * sn;
    *(float*)((char*)this + 0x14) = sy * -sn;
    *(float*)((char*)this + 0x18) = sy * cs;
    *(float*)((char*)this + 0x1C) = props->f[0];
    *(float*)((char*)this + 0x20) = props->f[1];
    *(float*)((char*)this + 0x24) = props->f[7] * 0.01f;
    *(float*)((char*)this + 0x38) = props->f[8] * 0.003921569f;
    *(float*)((char*)this + 0x3C) = props->f[9] * 0.003921569f;
    *(float*)((char*)this + 0x40) = props->f[10] * 0.003921569f;
}

// 0x801411C4: gotoAndPlay/gotoAndStop(frame or label): jump the clip to a frame, then set its stopped bit
// NON_MATCHING: two trailing branches short (compiler state left by earlier functions; see the note at the top of the file)
extern "C" int fn_801411C4(void* h, int arg, int stop) {
    void* v;
    int frame;
    register UiTimeline* tl;
    if (arg <= 0) {
        return lbl_8037D110;
    }
    v = fn_801489D4(lbl_8033D2A8, 0);
    if (fn_80139D88(fn_8012C154(h, 0))) {
        return lbl_8037D110;
    }
    if (fn_80131EEC(v)) {
        tl = (UiTimeline*)((char*)((UiClip*)fn_8013DD0C(fn_8012C154(h, 0)))->shape + 8);
        frame = tl->Lookup((int)fn_8012D9C4(fn_80131E8C(v))) + 1;
    } else {
        frame = fn_801321E4(v);
    }
    fn_801462CC(fn_8012C154(h, 0), frame - 1);
    {
        fn_8013DD0C(fn_8012C154(h, 0))->stopped = stop != 0 ? 1 : 0;
    }
    return lbl_8037D110;
}

// 0x80141350, 0x801413A8: the two entry points (play / stop)
extern "C" int fn_80141350(void* h, int arg) {
    do { return fn_801411C4(h, arg, 0); } while (0);
}
extern "C" int fn_801413A8(void* h, int arg) {
    do { return fn_801411C4(h, arg, 1); } while (0);
}

// 0x80142BB0
// NON_MATCHING: two unreachable trailing branches missing (compiler state left by earlier functions; see the note at the top of the file)
UI_TYPE_TEST(IsType7, 7)

// 0x80142C20
// NON_MATCHING: two unreachable trailing branches missing (compiler state left by earlier functions; see the note at the top of the file)
UI_TYPE_TEST(IsType6, 6)

// 0x80142C90
UI_TYPE_TEST(IsTypeC, 0xC)

// 0x80142CF8
UI_TYPE_TEST(IsTypeF, 0xF)

// 0x80142D60
UI_TYPE_TEST(IsType10, 0x10)

// 0x80142DC8: allocate through host slot 0
void* UiProps::operator new(register unsigned n) {
    return lbl_8033D1E0.alloc(n);
}

// 0x80143400: remove a named entry, moving the last one into its place
void UiNamedPool::Unk80143400(UiNameEntry* e) {
    int i = 0;
    while (!(i > 31)) {
        if (&names[i] == e) {
            names[i] = names[--nameCount];
            return;
        }
        i++;
    }
}

// 0x8014351C: find the named entry with this name (the name is normalised into a local buffer first)
UiNameEntry* UiNamedPool::Unk8014351C(const char* name) {
    char buf[0x100];
    int i;
    fn_80142ED8(name, buf);
    i = 0;
    while (i < nameCount) {
        if (fn_80111ECC(buf, names[i].name) == 0) {
            return &names[i];
        }
        i++;
    }
    return 0;
}

// 0x801435F0: find the named entry with this key
UiNameEntry* UiNamedPool::Unk801435F0(int key) {
    int i = 0;
    while (i < nameCount) {
        if (key == names[i].key) {
            return &names[i];
        }
        i++;
    }
    return 0;
}

// 0x80143694: take a reference
UiPoolEntry* UiNamedPool::Unk80143694(UiPoolEntry* e) {
    ++e->refs;
    return e;
}

// 0x801436DC: take a reference to the entry of this name
UiPoolEntry* UiNamedPool::Unk801436DC(const char* name) {
    UiNameEntry* e = Unk8014351C(name);
    return Unk80143694((UiPoolEntry*)e);
}

// 0x8014373C: drop a reference; the last one frees the entry
UiPoolEntry* UiNamedPool::Unk8014373C(UiPoolEntry* e) {
    --e->refs;
    if (e->refs == 0) {
        fn_801375F8(e->ptr100 + 8, e->unk108);
        lbl_8033D1E0.slot24(e->ptr104);
        Unk80143400((UiNameEntry*)e);
        return 0;
    }
    return e;
}

// 0x801437F8: drop a reference to the entry with this key
void UiNamedPool::Unk801437F8(int key) {
    UiNameEntry* e = Unk801435F0(key);
    Unk8014373C((UiPoolEntry*)e);
}

// 0x8014384C
int UiNamedPool::Unk8014384C(const char* name) {
    return Unk8014351C(name) != 0;
}

// 0x801438A8: return an entry to the pool
void UiNamedPool::Unk801438A8(UiPoolEntry* e) {
    e->used = 0;
    active = active - 1;
}

// 0x80143B74: take a free entry from the pool
UiPoolEntry* UiNamedPool::Unk80143B74() {
    int i = 0;
    while (!(i > 63)) {
        UiPoolEntry* e = &pool[i];
        if (e->used == 0) {
            e->used = 1;
            active = active + 1;
            return e;
        }
        i++;
    }
    return 0;
}

// 0x80143DDC
void fn_80143DDC(int a, int b, int c, int d) {
    lbl_8037D0F8->Unk80143E30(a, b, c, d);
}

// 0x801462CC: bring a movie clip to a frame; forwards by running each frame's commands, backwards by rebuilding from frame 0
extern "C" void fn_801462CC(register UiObj* o, int frame) {
    UiMovieData* md = fn_8013DD0C(o);
    int total = md->res->tl.unk0;
    int cur;
    if (frame < 0 || frame >= total) {
        return;
    }
    cur = md->frame;
    if (frame == cur) {
        return;
    } else if (frame == cur + 1) {
        fn_8013F62C(&md->res->tl, &md->list, o, frame);
    } else if (frame > cur) {
        int i = cur + 1;
        while (!(i > frame) && i < total) {
            fn_8013F62C(&md->res->tl, &md->list, o, i);
            i++;
        }
    } else {
        UiHead tmpHead;
        char tmpObj[8];
        UiHead* savedHead;
        UiHead* newHead;
        char* newObj;
        void* savedDict;
        fn_8012C4A4(tmpObj, 4);
        savedHead = md->list.GetHead();
        newHead = &tmpHead;
        newObj = tmpObj;
        md->list.SetHead(newHead);
        savedDict = md->dict;
        md->dict = newObj;
        md->list.Clear();
        md->frame = 0;
        while (!(md->frame > frame) && md->frame < md->res->tl.unk0) {
            fn_8013F62C(&md->res->tl, &md->list, o, md->frame);
            md->frame++;
        }
        md->list.SetHead(savedHead);
        md->dict = savedDict;
        fn_8013D6A0(&md->list, newHead, newObj, md->dict);
        fn_80134B68(tmpObj, 2);
        tmpHead.Destroy(2);
    }
    md->frame = frame;
    md->res->tl.RunFrameB((int)o, frame);
}
