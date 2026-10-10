typedef struct Slot {
    int used;      /* 0x00 */
    int type;      /* 0x04 */
    int state;     /* 0x08 */
    char pad[0x114 - 12];
} Slot;

typedef struct Player {
    char pad[0x4500];
    int count;
} Player;

typedef struct CXForm {
    float mul[4];   /* 0x00 r,g,b,a multipliers */
    float add[4];   /* 0x10 r,g,b,a offsets */
} CXForm;

/* x' = m00 * x + m01 * y + tx;  y' = m10 * x + m11 * y + ty */
typedef struct Matrix {
    float m00, m01, m10, m11, tx, ty;
} Matrix;

typedef struct RectF {
    float xmin, ymin, xmax, ymax;
} RectF;

/* display state: color transform, matrix, and a 32-entry-deep color transform stack */
typedef struct RState {
    CXForm cx;              /* 0x00 */
    Matrix m;               /* 0x20 */
    CXForm stack[16];       /* 0x038 color transform stack (depth at 0x3B8) */
    Matrix mstack[16];      /* 0x238 matrix stack (depth at 0x3BC) */
    int depth;              /* 0x3B8 */
    int mdepth;             /* 0x3BC */
} RState;

extern Matrix lbl_8033D270;            /* identity matrix, filled at run time */
extern void (*lbl_8033D1E0[])(void*);  /* renderer callback table, filled at run time */

typedef struct Entry10C {
    char data[0x100];
    int id;                 /* 0x100 */
    char pad[8];
} Entry10C;

typedef struct EntryList {
    int count;              /* 0x00 */
    Entry10C entries[1];    /* 0x04, stride 0x10C */
} EntryList;

typedef struct PlayerA {
    int unk0;               /* 0x0000 */
    char pad4[0x4304 - 4];
    int unk4304;
    char pad4308[0x4488 - 0x4308];
    int unk4488;
} PlayerA;

extern int fn_8012C7C8(void*);
extern void fn_8014373C(void*, void*);
extern void (*lbl_8033D1E0[])(void*);

typedef struct NamePool {
    char names[8][0x100];   /* interned names, 256 bytes each */
    int count;              /* 0x800 */
} NamePool;

/* ActionScript Date getters. 80133510 returns the broken-down time of a Date
   object: seconds at 0x0C, minutes 0x10, hours 0x14, day of month 0x18,
   month 0x1C, year-1900 0x20, weekday 0x24. */
extern void* fn_8012F50C(int);
extern void* fn_8012F4C0(void*, int);
extern int* fn_80133510(void*);


extern char lbl_8033D2A8[];     /* ActionScript call arguments */
extern void* lbl_8037D110;      /* the undefined value */
extern void* fn_801489D4(void*, int);
extern int fn_801321E4(void*);
extern void fn_8026FA38(void*);

/* A display-list node (movie clip / button / ...) as far as the path builders see it. */
typedef struct DNode {
    int unk0;
    int level;              /* 0x04 _level number, for a root node */
    int name;               /* 0x08 instance name value, or 0 */
    char pad[0x48 - 0xC];
    struct DNode* parent;   /* 0x48 */
} DNode;

extern void fn_801498B0(DNode*, char*);
extern void fn_8014973C(DNode*, char*);

extern int sprintf(char*, const char*, ...);
extern char* strcat(char*, const char*);
extern unsigned strlen(const char*);
extern char* fn_8012D9C4(void*);
extern void* fn_8012C44C(int);
extern int fn_8014FD8C(void*, char*);
extern void fn_8012C800(void*);
extern char* fn_80131FF8(DNode*);
extern void fn_8012D400(void*, char*, DNode*);

extern void fn_80147D08(void*, void*, int, void*);
extern void fn_8013A3A4(void*);
extern int fn_8014FAE4(void*, void*);

typedef struct NamedValue {
    char name[0x100];
    void* value;            /* 0x100 */
    int unk104;             /* 0x104 */
    int unk108;             /* 0x108 */
} NamedValue;

/* name -> value table: count, entries (stride 0x10C), then a list of pointers that were added */
typedef struct NamedList {
    int count;              /* 0x0000 */
    NamedValue entries[64]; /* 0x0004 */
    char pad[0x4304 - 4 - 64 * 0x10C];
    int nvals;              /* 0x4304 */
    void* vals[1];          /* 0x4308 */
} NamedList;

extern int strcmp(const char*, const char*);
extern char* strcpy(char*, const char*);

extern unsigned lbl_802D67B4[];   /* per-type release handlers */
extern void* memmove(void*, const void*, unsigned);

int fn_80144198(register Player* p) {
    int i;
    int remaining = p->count;
    for (i = 0; i <= 63; i++) {
        Slot* s;
        if (remaining == 0) break;
        s = (Slot*)((char*)p + i * 0x114);
        if (s->used != 0) {
            if (s->state == 1 || s->state == 0) return 0;
            if (s->state == 2) continue;
            if (s->type != 6) return 0;
            remaining--;
        }
    }
    return 1;
}

PlayerA* fn_80144320(register PlayerA* p) {
    p->unk0 = 0;
    p->unk4488 = 0;
    p->unk4304 = 0;
    return p;
}

void fn_801443F8(register NamedList* l, char* name, void* value, int arg) {
    int i;
    register int idx;
    if (value == 0) {
        i = 0;
        while (i < l->count) {
            if (strcmp(l->entries[i].name, name) == 0)
                return;
            i++;
        }
    }
    if (value != 0)
        /* NON_MATCHING: one register copy (mr r10,r29 vs mr r10,r11) */
        l->vals[idx = l->nvals++] = value;
    strcpy(l->entries[l->count].name, name);
    l->entries[l->count].value = value;
    l->entries[l->count].unk104 = 0;
    l->entries[l->count].unk108 = arg;
    if (value != 0)
        fn_8012C800(value);
    l->count++;
}

Entry10C* fn_80144544(register EntryList* l, int id) {
    int i;
    i = 0;
    while (i < l->count) {
        if (l->entries[i].id == id)
            return &l->entries[i];
        i++;
    }
    return 0;
}

/* remove entry e from the table, releasing its value.
   NON_MATCHING: the original builds the handler-table address after the type call; here it is hoisted into r29 */
void fn_801445D0(register NamedList* l, NamedValue* e) {
    int i;
    void (*h)(void*);
    i = 0;
    while (i < l->count) {
        if (&l->entries[i] == e) {
            if (l->entries[i].value != 0) {
                h = (void (*)(void*))lbl_802D67B4[fn_8012C7C8(l->entries[i].value)];
                h(l->entries[i].value);
            }
            memmove(&l->entries[i], &l->entries[i + 1], (l->count - i - 1) * 0x10C);
            l->count--;
            return;
        }
        i++;
    }
}

int fn_80144D28(register void* v) {
    return fn_8012C7C8(v) == 3;
    return;
    return;
}

/* callback slot 0 of the renderer table */
int fn_80144D80(register void* a) {
    return ((int (*)(void*))lbl_8033D1E0[0])(a);
}

/* callback slot 2 */
void fn_80144DD8(register void* a, register void* b) {
    ((void (*)(void*, void*))lbl_8033D1E0[2])(a, b);
}

/* callback slot 2 */
void fn_80144E30(register void* a, register void* b) {
    ((void (*)(void*, void*))lbl_8033D1E0[2])(a, b);
}

NamePool* fn_80144E88(register NamePool* p) {
    p->count = 0;
    return p;
}

void* fn_80144FD0(void* self, int nargs) {
    register void* res;
    res = fn_8012F50C(8);
    return fn_8012F4C0(res, fn_80133510(self)[6]);
}

void* fn_80145034(void* self, int nargs) {
    register void* res;
    res = fn_8012F50C(8);
    return fn_8012F4C0(res, fn_80133510(self)[9]);
}

void* fn_80145098(void* self, int nargs) {
    register void* res;
    res = fn_8012F50C(8);
    return fn_8012F4C0(res, fn_80133510(self)[8] + 0x76c);
}

void* fn_80145104(void* self, int nargs) {
    register void* res;
    res = fn_8012F50C(8);
    return fn_8012F4C0(res, fn_80133510(self)[5]);
}

/* getMilliseconds: always 0 */
void* fn_80145168(void* self, int nargs) {
    return fn_8012F4C0(fn_8012F50C(8), 0);
}

void* fn_801451C0(void* self, int nargs) {
    register void* res;
    res = fn_8012F50C(8);
    return fn_8012F4C0(res, fn_80133510(self)[4]);
}

void* fn_80145224(void* self, int nargs) {
    register void* res;
    res = fn_8012F50C(8);
    return fn_8012F4C0(res, fn_80133510(self)[7]);
}

void* fn_80145288(void* self, int nargs) {
    register void* res;
    res = fn_8012F50C(8);
    return fn_8012F4C0(res, fn_80133510(self)[3]);
}

void* fn_801452EC(void* self, int nargs) {
    register void* res;
    res = fn_8012F50C(8);
    return fn_8012F4C0(res, fn_80133510(self)[8]);
}

void* fn_80145350(void* self, int nargs) {
    register int* dst;
    register int* tm;
    if (nargs <= 0)
        return lbl_8037D110;
    tm = fn_80133510(self);
    /* NON_MATCHING: the store goes through tm (r29) instead of the copy dst (r30) */
    (dst = tm)[6] = fn_801321E4(fn_801489D4(lbl_8033D2A8, 0));
    fn_8026FA38((char*)fn_80133510(self) + 0xc);
    return lbl_8037D110;
}

void* fn_80145514(void* self, int nargs) {
    register int* dst;
    register int* tm;
    if (nargs <= 0)
        return lbl_8037D110;
    tm = fn_80133510(self);
    /* NON_MATCHING: the store goes through tm (r29) instead of the copy dst (r30) */
    (dst = tm)[5] = fn_801321E4(fn_801489D4(lbl_8033D2A8, 0));
    fn_8026FA38((char*)fn_80133510(self) + 0xc);
    return lbl_8037D110;
}

/* setMilliseconds: ignored */
void* fn_801455B8(void* self, int nargs) {
    return lbl_8037D110;
}

void* fn_801455E8(void* self, int nargs) {
    register int* dst;
    register int* tm;
    if (nargs <= 0)
        return lbl_8037D110;
    tm = fn_80133510(self);
    /* NON_MATCHING: the store goes through tm (r29) instead of the copy dst (r30) */
    (dst = tm)[4] = fn_801321E4(fn_801489D4(lbl_8033D2A8, 0));
    fn_8026FA38((char*)fn_80133510(self) + 0xc);
    return lbl_8037D110;
}

void* fn_8014568C(void* self, int nargs) {
    register int* dst;
    register int* tm;
    if (nargs <= 0)
        return lbl_8037D110;
    tm = fn_80133510(self);
    /* NON_MATCHING: the store goes through tm (r29) instead of the copy dst (r30) */
    (dst = tm)[7] = fn_801321E4(fn_801489D4(lbl_8033D2A8, 0));
    fn_8026FA38((char*)fn_80133510(self) + 0xc);
    return lbl_8037D110;
}

void* fn_80145730(void* self, int nargs) {
    register int* dst;
    register int* tm;
    if (nargs <= 0)
        return lbl_8037D110;
    tm = fn_80133510(self);
    /* NON_MATCHING: the store goes through tm (r29) instead of the copy dst (r30) */
    (dst = tm)[3] = fn_801321E4(fn_801489D4(lbl_8033D2A8, 0));
    fn_8026FA38((char*)fn_80133510(self) + 0xc);
    return lbl_8037D110;
}

RState* fn_8014739C(register RState* s) {
    s->cx.mul[0] = 1.0f;
    s->cx.mul[1] = 1.0f;
    s->cx.mul[2] = 1.0f;
    s->cx.mul[3] = 1.0f;
    s->cx.add[0] = 0.0f;
    s->cx.add[1] = 0.0f;
    s->cx.add[2] = 0.0f;
    s->cx.add[3] = 0.0f;
    s->m.m00 = 1.0f;
    s->m.m01 = 0.0f;
    s->m.m10 = 0.0f;
    s->m.m11 = 1.0f;
    s->m.tx = 0.0f;
    s->m.ty = 0.0f;
    s->depth = 0;
    s->mdepth = 0;
    return s;
}

void fn_8014747C(register RState* s) {
    /* NON_MATCHING: register allocation of the index temporaries (r0 vs r7) */
    (s->depth++)[s->stack] = s->cx;
}

void fn_80147520(register RState* s) {
    s->cx = (--s->depth)[s->stack];
}

void fn_801475C0(register RState* s, CXForm* o) {
    s->cx.mul[0] = s->cx.mul[0] * o->mul[0];
    s->cx.mul[1] = s->cx.mul[1] * o->mul[1];
    s->cx.mul[2] = s->cx.mul[2] * o->mul[2];
    s->cx.mul[3] = s->cx.mul[3] * o->mul[3];
    s->cx.add[0] = s->cx.add[0] + o->add[0];
    s->cx.add[1] = s->cx.add[1] + o->add[1];
    s->cx.add[2] = s->cx.add[2] + o->add[2];
    s->cx.add[3] = s->cx.add[3] + o->add[3];
    lbl_8033D1E0[0x70 / 4](s);
}

void fn_801476B4(register RState* s, Matrix* out) {
    if (s->mdepth > 0)
        *out = s->m;
    else
        *out = lbl_8033D270;
}

void fn_80147764(register RState* s) {
    /* NON_MATCHING: register allocation of the index temporaries */
    (s->mdepth++)[s->mstack] = s->m;
}

void fn_801477DC(register RState* s) {
    s->m = (--s->mdepth)[s->mstack];
    lbl_8033D1E0[0x6c / 4](&s->m);
}

/* out = b * a (row vector convention); a is copied first so out may alias it */
void fn_80147884(Matrix* a, Matrix* b, Matrix* out) {
    Matrix t = *a;
    out->m00 = b->m00 * t.m00 + b->m01 * t.m10;
    out->m01 = b->m00 * t.m01 + b->m01 * t.m11;
    out->m10 = b->m10 * t.m00 + b->m11 * t.m10;
    out->m11 = b->m10 * t.m01 + b->m11 * t.m11;
    out->tx = b->tx * t.m00 + b->ty * t.m10 + t.tx;
    out->ty = b->tx * t.m01 + b->ty * t.m11 + t.ty;
}

void fn_80147A00(register RState* s, Matrix* o) {
    fn_80147884(&s->m, o, &s->m);
    lbl_8033D1E0[0x6c / 4](&s->m);
}

/* grow acc by the bounds of r transformed through the current matrix */
void fn_80147A70(register RState* s, RectF* acc, RectF* r) {
    float xs[4], ys[4], tx[4], ty[4];
    int i;
    xs[0] = r->xmin; ys[0] = r->ymin;
    xs[1] = r->xmax; ys[1] = r->ymin;
    xs[2] = r->xmax; ys[2] = r->ymax;
    xs[3] = r->xmin; ys[3] = r->ymax;
    i = 0;
    while (i <= 3) {
        tx[i] = s->m.m00 * xs[i] + s->m.m01 * ys[i] + s->m.tx;
        ty[i] = s->m.m10 * xs[i] + s->m.m11 * ys[i] + s->m.ty;
        i++;
    }
    i = 0;
    while (i <= 3) {
        if (!(tx[i] >= acc->xmin)) acc->xmin = tx[i];
        if (!(tx[i] <= acc->xmax)) acc->xmax = tx[i];
        if (!(ty[i] >= acc->ymin)) acc->ymin = ty[i];
        if (!(ty[i] <= acc->ymax)) acc->ymax = ty[i];
        i++;
    }
}

void fn_8014881C(void* a, void* b, void* c) {
    fn_80147D08(a, b, 0, c);
    return;
    return;
}

void fn_80148870(void* a, void* b, int c, void* d) {
    fn_80147D08(a, b, c, d);
    return;
    return;
}

void fn_80148994(register void* a) {
    fn_8013A3A4(a);
    return;
    return;
}

void* fn_801489D4(register void* a, int b) {
    return (void*)fn_8014FAE4(a, (void*)b);
    return;
    return;
}

/* build the slash-separated target path of a node into buf; unnamed nodes get "instanceN" */
/* NON_MATCHING: the original keeps the post-incremented store pointer in r30 and stores the name from r3 */
void fn_8014973C(DNode* node, char* buf) {
    DNode* parent;
    int level;
    char* end;
    if (node->parent == 0) {
        if (node->level != 0) {
            sprintf(buf, "_level%d", node->level);
            return;
        }
        return;
    }
    parent = node->parent;
    fn_8014973C(parent, buf);
    if (node->name != 0) {
        strcat(buf, "/");
        strcat(buf, fn_8012D9C4((void*)node->name));
        return;
    }
    level = node->level;
    end = buf + strlen(buf);
    *end++ = '/';
    sprintf(end, "instance%d", level);
    {
        register void* ctx;
        register DNode* n = node;
        n->name = fn_8014FD8C(fn_8012C44C(8), end);
        fn_8012C800((void*)node->name);
        ctx = *(void**)(fn_80131FF8(parent) + 0xC);
        fn_8012D400(ctx, end, node);
    }
}

/* target path with slashes; the root is "/" */
void fn_80149A14(DNode* node, char* buf) {
    buf[0] = 0;
    fn_8014973C(node, buf);
    if (buf[0] == 0) {
        buf[0] = '/';
        buf[1] = 0;
    }
}

/* target path with dots */
void fn_80149A90(DNode* node, char* buf) {
    buf[0] = 0;
    fn_801498B0(node, buf);
}
