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

void fn_80147764(register RState* s) {
    /* NON_MATCHING: register allocation of the index temporaries */
    (s->mdepth++)[s->mstack] = s->m;
}

void fn_801477DC(register RState* s) {
    s->m = (--s->mdepth)[s->mstack];
    lbl_8033D1E0[0x6c / 4](&s->m);
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
