// UI library (Flash-style display list), 0x8013C054-0x801440C4. Compiled at -O0.

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
    float f[11];
    float visible;           // 0x2C
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
    char pad0C[0x44 - 0x0C];
    void (*drawText)(void*);         // 0x44
    char pad48[0x70 - 0x48];
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
    char unk0[0x10];
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
    UiDataB();
    static void* operator new(unsigned n);
};
struct UiDataC : UiBase {
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
    UiDataF();
    static void* operator new(unsigned n);
};

extern "C" void fn_8013BCEC(UiHead* head, int id, int zero, void* outA, UiObj** outB);
extern "C" void* fn_80151A24(void* parent);
extern "C" UiObj* fn_8012D820(void* dict, int name);
extern "C" void fn_8012D480(void* dict, int name);
extern "C" void fn_80132F5C(UiObj* o);


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

// 0x8013E4DC
UiClipStack::UiClipStack() {
    count = 0;
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

// 0x8013E50C
void UiClipStack::Free(register int flag) {
    if (flag & 1) {
        delete this;
        return;
    }
}

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
    return lbl_8033D1E0.alloc(n);
}

// 0x8013D148
UiDisplayList::UiDisplayList() {
    head = new UiHead;
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

extern "C" void fn_80133A14(UiObj* o);

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

extern "C" int fn_80132114(UiObj* o, int flag);
extern "C" int fn_8013209C(UiObj* o, int flag);
extern "C" void fn_80140BBC(UiObj* o, void* ctx, int flag);
extern "C" void fn_80146B8C(UiObj* o);

// 0x8013E494
void UiHead::Free(register UiHead* p) {
    if (p) {
        p->Destroy(3);
        return;
    }
}

// 0x8013D198
UiDisplayList::~UiDisplayList() {
    Clear();
    UiHead::Free(head);
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

// 0x8013DD0C
UiClip* UiObj::GetClip() {
    return clip;
}

#define UI_TYPE_TEST(name, t) \
    int UiObj::name() { \
        register int r = 0; \
        if (fn_8012C7C8(this) == t && !fn_8012C8A4(this)) { \
            r = 1; \
        } \
        return r; \
    }

// 0x8013DD38
UI_TYPE_TEST(IsType11, 0x11)
// 0x80142BB0
// NON_MATCHING: the original has two more unreachable branches after the return
UI_TYPE_TEST(IsType7, 7)
// 0x80142C20
// NON_MATCHING: the original has two more unreachable branches after the return
UI_TYPE_TEST(IsType6, 6)
// 0x80142C90
UI_TYPE_TEST(IsTypeC, 0xC)
// 0x80142CF8
UI_TYPE_TEST(IsTypeF, 0xF)
// 0x80142D60
UI_TYPE_TEST(IsType10, 0x10)

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

// 0x80140D38: bounds {xmin, ymin, xmax, ymax} of an object, gathered by a draw pass with a collecting context
void UiObj::GetBounds(UiRect* out) {
    out->xmin = 1000000000.0f;
    out->xmax = -1000000000.0f;
    out->ymax = -1000000000.0f;
    out->ymin = 1000000000.0f;
    DrawForBounds(lbl_8037D124, out);
}

extern "C" void* fn_80131FCC(UiObj* o);
extern "C" void* fn_80131FF8(UiObj* o);
extern "C" UiClip* fn_8013356C(UiObj* o);


// data block of a movie clip (type 0xD/0x12), as UiObj::Draw sees it
struct UiMovieData {
    int clipDepth;           // 0x00
    int unk4;
    int unk8;
    void* dict;              // 0x0C member dictionary
    int unk10;
    unsigned pad14 : 26;     // 0x14
    unsigned mode : 2;       // 1 = drawn by the host, 2 = drawn here
    unsigned rest14 : 4;
    int unk18;
    UiDisplayList list;      // 0x1C
};
struct UiFont {
    char pad[0x10];
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

// 0x8014041C: draw one object, by type
void UiObj::Draw(void* ctx, int flag) {
    if (props && !(props->visible >= 0.5f)) {
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
