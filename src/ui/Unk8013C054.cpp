// UI library (Flash-style display list), 0x8013C054-0x801440C4. Compiled at -O0.

struct UiClip {
    int clipDepth;           // 0x00
};

struct UiObj {
    unsigned flags;          // 0x00 type in the low 15 bits, 0x8000 = alternate flag
    int depth;               // 0x04
    char pad8[0x4C - 8];
    UiClip* clip;            // 0x4C
    UiObj* prev;             // 0x50
    UiObj* next;             // 0x54
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

struct UiHead {
    UiObj* first;            // 0x00 dummy head of the sibling list; first child is first->next
};

struct UiDisplayList {
    UiHead* head;            // 0x00
    void DrawOne(void* ctx, UiObj* o, int flag);
    void Draw(void* ctx, int flag);
};

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
