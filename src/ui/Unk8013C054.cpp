// UI library (Flash-style display list), 0x8013C054-0x801440C4. Compiled at -O0.

struct UiClip {
    int clipDepth;           // 0x00
};

struct UiObj {
    unsigned flags;          // 0x00 type in the low 15 bits, 0x8000 = alternate flag
    int depth;               // 0x04
    int name;                // 0x08
    char padC[0x48 - 0xC];
    void* parent;            // 0x48
    UiClip* clip;            // 0x4C
    UiObj* prev;             // 0x50
    UiObj* next;             // 0x54
    int unk58;               // 0x58
    int unk5C;               // 0x5C
    UiObj(int type, unsigned fill, int zero);   // 0x8012C21C
    static void* operator new(unsigned n);       // 0x8012C3F4
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
    void* rest[28];
};
extern UiAllocTable lbl_8033D1E0;

extern "C" UiObj* fn_8012C21C(void* mem, int type, unsigned fill, int zero);
extern "C" void* fn_8012C3F4(unsigned n);
extern "C" void fn_8012CA5C(UiObj* o, int zero);
extern "C" void fn_8012C544(void* self);
extern "C" void fn_80139E1C(void* self);

// head of a sibling list: a dummy UiObj whose next is the first child
struct UiHead {
    UiObj* first;            // 0x00
    static void* operator new(unsigned n);
    UiHead();
};

// base of the per-character data blocks (0x8012C544)
struct UiBase {
    char unk0[0x10];
    UiBase();
};

struct UiDisplayList {
    UiHead* head;            // 0x00
    UiDisplayList();
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

extern "C" void fn_8013BCEC(void* owner, int id, int zero, void* outA, UiObj** outB);
extern "C" void* fn_80151A24(void* parent);
extern "C" UiObj* fn_8012D820(void* dict, int name);
extern "C" void fn_8012D480(void* dict, int name);
extern "C" void fn_80132F5C(UiObj* o);

// owner of the instances that scripts attach by id (0x8013CF5C-0x8013D104)
struct UiResolver {
    void* owner;             // 0x00
    void Release(UiObj* o);
    void Remove(int id);
    void RemoveDynamic(UiObj* id);
    void RemoveHandle(int* id);
};

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
void UiResolver::Release(UiObj* o) {
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
void UiResolver::Remove(int id) {
    int a;
    UiObj* b;
    fn_8013BCEC(owner, id, 0, &a, &b);
    Release(b);
}

// 0x8013D080: release an instance only when it was made at run time (depth above 0x3FFF)
void UiResolver::RemoveDynamic(UiObj* id) {
    int a = 0;
    UiObj* b = 0;
    fn_8013BCEC(owner, id->depth, 0, &a, &b);
    if (b->depth > 0x3FFF) {
        Release(b);
    }
}

// 0x8013D104
void UiResolver::RemoveHandle(int* id) {
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
