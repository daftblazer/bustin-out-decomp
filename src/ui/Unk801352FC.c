/* ActionScript (Apt) value/object library, 0x801352FC-0x8013C054. Compiled as C at -O0.
   Parameters declared `register` are the ones the original keeps in r29-r31
   (`this` and the destructor's in-charge flag). */

typedef struct {
    void* (*alloc)(unsigned);        /* 0x00 */
    void* slot4;                     /* 0x04 */
    void (*free)(void*, unsigned);   /* 0x08 */
    void* slotC[3];                  /* 0x0C */
    void (*hook18)(void*, int);      /* 0x18: trace hook, called with (&{tag, word}, 8) */
    void* slot1C[9];                 /* 0x1C */
    void (*release40)(void*);        /* 0x40: releases the object at +0x14 of the 0x24-byte class */
    void* rest[2];
} UiAllocTable;
extern UiAllocTable lbl_8033D1E0;

/* .sdata object handles (released by the shutdown functions) */
extern void* lbl_8037BEB0;
extern void* lbl_8037BEB4;
extern void* lbl_8037BEB8;
extern void* lbl_8037BEBC;
extern void* lbl_8037BEC0;
extern void* lbl_8037BEC4;
extern void* lbl_8037BEC8;
extern void* lbl_8037BECC;
extern void* lbl_8037BED0;
extern void* lbl_8037BED4;
extern void* lbl_8037BED8;
extern void* lbl_8037BEDC;
extern void* lbl_8037BEE0;
extern void* lbl_8037BEE4;
extern void* lbl_8037BEE8;
extern void* lbl_8037BEEC;
extern void* lbl_8037BEF0;
extern void* lbl_8037BEF4;
extern void* lbl_8037BEF8;
extern void* lbl_8037BEFC;
extern void* lbl_8037BF00;
extern void* lbl_8037BF04;
extern void* lbl_8037BF08;
extern void* lbl_8037BF0C;
extern void* lbl_8037BF10;
extern void* lbl_8037BF14;
extern void* lbl_8037BF18;
extern void* lbl_8037BF1C;
extern void* lbl_8037BF20;
extern void* lbl_8037BF24;
extern void* lbl_8037BF28;
extern void* lbl_8037BF2C;
extern void* lbl_8037BF30;
extern void* lbl_8037BF34;
extern void* lbl_8037BF38;
extern void* lbl_8037BF3C;
extern void* lbl_8037BF40;
extern void* lbl_8037BF44;
extern void* lbl_8037BF48;
extern void* lbl_8037BF4C;
extern void* lbl_8037BF50;
extern void* lbl_8037BF54;
extern void* lbl_8037BF58;
extern void* lbl_8037BF5C;
extern void* lbl_8037BF60;
extern void* lbl_8037BF64;
extern void* lbl_8037BF68;
extern void* lbl_8037BF6C;

typedef void (*ReleaseFn)(void*);
extern ReleaseFn lbl_802D67B4[29];          /* release function per object type */
extern int fn_8012C7C8(void* obj);          /* object type index (low 15 bits of word 0) */
extern void fn_8012CCB0(void* p, int flag);
extern void fn_8012F564(void* p, int flag);
extern void fn_80133ED8(void* p);
extern void fn_8013D198(void* p, int flag);
extern void fn_801B8A60(void* p);           /* operator delete */

#define RELEASE(p) if (p) { (*(ReleaseFn*)((char*)lbl_802D67B4 + fn_8012C7C8(p) * 4))(p); p = 0; }
#define MEMBER(T, off) (*(T*)((char*)self + (off)))

void fn_801365A4(register void* p, register unsigned n);
void fn_801365FC(register void* p, register unsigned n);
void fn_80136654(register void* p, register unsigned n);
void fn_801366AC(register void* p, register unsigned n);
void fn_80136754(register void* p, register unsigned n);
void fn_801367AC(register void* p, register unsigned n);
void fn_80136804(register void* p, register unsigned n);
void fn_8013685C(register void* p, register unsigned n);
void fn_801368B4(register void* p, register unsigned n);
void fn_8013690C(register void* p, register unsigned n);
void fn_80136964(register void* p, register unsigned n);
void fn_80135530(register char* self, register int flag);
void fn_80136704(register char* self, register int flag);

void fn_801352FC(register char* self, register int flag) {
    RELEASE(lbl_8037BEF4);
    RELEASE(lbl_8037BEF8);
    fn_8012CCB0(self + 4, 0);
    if (flag & 1) fn_801365A4(self, 0xc);
}

void fn_801353F0(register char* self, register int flag) {
    RELEASE(lbl_8037BEFC);
    if (MEMBER(void*, 0xc)) {
        (*(ReleaseFn*)((char*)lbl_802D67B4 + fn_8012C7C8(MEMBER(void*, 0xc)) * 4))(MEMBER(void*, 0xc));
    }
    fn_8012F564(self, 0);
    if (flag & 1) fn_801365FC(self, 0x10);
}

void fn_801354D8(register void* p, register unsigned n) {
    lbl_8033D1E0.free(p, n);
}

void fn_80135530(register char* self, register int flag) {
    if (MEMBER(void*, 0xc)) {
        fn_80133ED8(MEMBER(void*, 0xc));
        MEMBER(void*, 0xc) = 0;
    }
    RELEASE(lbl_8037BF04);
    RELEASE(lbl_8037BF00);
    RELEASE(lbl_8037BF1C);
    RELEASE(lbl_8037BF18);
    RELEASE(lbl_8037BF10);
    RELEASE(lbl_8037BF14);
    RELEASE(lbl_8037BF0C);
    RELEASE(lbl_8037BF08);
    if (flag & 1) {
        fn_801B8A60(self);
    } else {
    }
}

void fn_801357F8(register char* self, register int flag) {
    fn_8013D198(self + 0x18, 2);
    fn_80135530(self, 0);
    if (flag & 1) fn_80136654(self, 0x1c);
}

void fn_80135860(register char* self, register int flag) {
    if (MEMBER(void*, 0x10)) {
        (*(ReleaseFn*)((char*)lbl_802D67B4 + fn_8012C7C8(MEMBER(void*, 0x10)) * 4))(MEMBER(void*, 0x10));
    }
    if (MEMBER(void*, 0x18)) {
        (*(ReleaseFn*)((char*)lbl_802D67B4 + fn_8012C7C8(MEMBER(void*, 0x18)) * 4))(MEMBER(void*, 0x18));
    }
    if (MEMBER(void*, 0x1c)) {
        (*(ReleaseFn*)((char*)lbl_802D67B4 + fn_8012C7C8(MEMBER(void*, 0x1c)) * 4))(MEMBER(void*, 0x1c));
    }
    MEMBER(int, 0x1c) = 0;
    MEMBER(int, 0x10) = 0;
    MEMBER(int, 0x18) = 0;
    MEMBER(int, 0x20) = 0;
    if (MEMBER(void*, 0x14)) {
        lbl_8033D1E0.release40(MEMBER(void*, 0x14));
        MEMBER(void*, 0x14) = 0;
    }
    fn_80135530(self, 0);
    if (flag & 1) fn_801366AC(self, 0x24);
}

void fn_801359D8(register char* self, register int flag) {
    fn_80136704(self, 0);
    if (flag & 1) fn_80136754(self, 0x20);
}

void fn_80135A30(register char* self, register int flag) {
    fn_80135530(self, 0);
    if (flag & 1) fn_801367AC(self, 0x10);
}

void fn_80135A88(register char* self, register int flag) {
    fn_80135530(self, 0);
    if (flag & 1) fn_80136804(self, 0x10);
}

void fn_80135AE0(register char* self, register int flag) {
    fn_80135530(self, 0);
    if (flag & 1) fn_8013685C(self, 0x14);
}

void fn_80135B38(register void* p, register unsigned n) {
    lbl_8033D1E0.free(p, n);
}

void fn_80135B90(register void* p, register unsigned n) {
    lbl_8033D1E0.free(p, n);
}

void fn_80135BE8(register void* p, register unsigned n) {
    lbl_8033D1E0.free(p, n);
}

void fn_80135C40(register void* p, register unsigned n) {
    lbl_8033D1E0.free(p, n);
}

void fn_80135C98(register void* p, register unsigned n) {
    lbl_8033D1E0.free(p, n);
}

void fn_80135CF0(register char* self, register int flag) {
    fn_8012CCB0(self + 4, 0);
    if (flag & 1) fn_801368B4(self, 0xc);
}

void fn_80135D4C(register void* p, register unsigned n) {
    lbl_8033D1E0.free(p, n);
}

void fn_80135DA4(register void* p, register unsigned n) {
    lbl_8033D1E0.free(p, n);
}

void fn_80135DFC(register void* p, register unsigned n) {
    lbl_8033D1E0.free(p, n);
}

void fn_80135E54(register void* p, register unsigned n) {
    lbl_8033D1E0.free(p, n);
}

void fn_80135EAC(register char* self, register int flag) {
    RELEASE(lbl_8037BF20);
    RELEASE(lbl_8037BF24);
    RELEASE(lbl_8037BF28);
    RELEASE(lbl_8037BF2C);
    RELEASE(lbl_8037BF30);
    RELEASE(lbl_8037BF34);
    RELEASE(lbl_8037BF38);
    RELEASE(lbl_8037BF3C);
    RELEASE(lbl_8037BF40);
    RELEASE(lbl_8037BF44);
    RELEASE(lbl_8037BF48);
    RELEASE(lbl_8037BF4C);
    RELEASE(lbl_8037BF50);
    RELEASE(lbl_8037BF54);
    RELEASE(lbl_8037BF58);
    RELEASE(lbl_8037BF5C);
    RELEASE(lbl_8037BF60);
    fn_8012F564(self, 0);
    if (flag & 1) fn_8013690C(self, 0x30);
}

void fn_80136410(register char* self, register int flag) {
    RELEASE(lbl_8037BF64);
    RELEASE(lbl_8037BF68);
    RELEASE(lbl_8037BF6C);
    fn_8012F564(self, 0);
    if (flag & 1) fn_80136964(self, 0x14);
}

void fn_8013654C(register void* p, register unsigned n) {
    lbl_8033D1E0.free(p, n);
}

void fn_801365A4(register void* p, register unsigned n) {
    lbl_8033D1E0.free(p, n);
}

void fn_801365FC(register void* p, register unsigned n) {
    lbl_8033D1E0.free(p, n);
}

void fn_80136654(register void* p, register unsigned n) {
    lbl_8033D1E0.free(p, n);
}

void fn_801366AC(register void* p, register unsigned n) {
    lbl_8033D1E0.free(p, n);
}

void fn_80136704(register char* self, register int flag) {
    fn_8013D198(self + 0x1c, 2);
    fn_80135530(self, flag);
}

void fn_80136754(register void* p, register unsigned n) {
    lbl_8033D1E0.free(p, n);
}

void fn_801367AC(register void* p, register unsigned n) {
    lbl_8033D1E0.free(p, n);
}

void fn_80136804(register void* p, register unsigned n) {
    lbl_8033D1E0.free(p, n);
}

void fn_8013685C(register void* p, register unsigned n) {
    lbl_8033D1E0.free(p, n);
}

void fn_801368B4(register void* p, register unsigned n) {
    lbl_8033D1E0.free(p, n);
}

void fn_8013690C(register void* p, register unsigned n) {
    lbl_8033D1E0.free(p, n);
}

void fn_80136964(register void* p, register unsigned n) {
    lbl_8033D1E0.free(p, n);
}


typedef struct { char pad[0x1c]; int f1c; } AptFile;
extern void fn_801369BC(register char* self, int a, AptFile* p, int c);

void fn_801374A8(register char* self, int a, AptFile* p, int c) {
    AptFile* base = p;
    if (p->f1c) {
        *(&p->f1c) = (int)base + p->f1c;
    }
    *(int*)(self + 0x30) = 0;
    fn_801369BC(self, a, p, c);
    if (p->f1c) {
        *(&p->f1c) = p->f1c - (int)base;
    }
    return;
    return;
}

typedef struct { char pad[0xc]; int count; int* ids; } AptIdList;

int fn_80137568(register AptIdList* self, int id) {
    int i = 0;
    while (i < self->count) {
        if (self->ids[i] == id) return i;
        i++;
    }
    return -1;
    return;
    return;
}

/* Apt VM context (0x3F3C bytes). */
typedef struct { int count; int items[2049]; } AptList;       /* 0x180C: count, then item pointers */
typedef struct { int used; void* obj; float interval; float remaining; } AptSlot;  /* 0x10 bytes: a setInterval timer */
typedef struct AptCtx {
    char pad0[0x1400];
    char* f1400;                 /* message queue read pointer */
    char* f1404;                 /* message queue write pointer */
    void* roots[256];            /* 0x1408: root objects */
    int rootCount;               /* 0x1808 */
    AptList list;                /* 0x180C */
    char f3814[0x3a18 - 0x3814]; /* 0x3814 */
    int f3a18;
    int f3a1c;
    AptSlot slots[64];           /* 0x3A20 */
    int f3e20;
    int evCount;                 /* 0x3E24: queued event words */
    unsigned evWords[64];        /* 0x3E28 */
    int f3f28, f3f2c, f3f30, f3f34, f3f38;
} AptCtx;

extern void fn_80139E1C(register char* self);
extern void fn_801437F8(void* a, int b);
extern void fn_80139FBC(register void* p, register unsigned n);
extern void* lbl_8037D0F8;

char* fn_801384E8(register char* self, int a) {
    fn_80139E1C(self);
    *(int*)(self + 0x20) = 0;
    *(int*)(self + 8) = a;
    return self;
}

void fn_8013853C(register char* self, int flag) {
    fn_801437F8(lbl_8037D0F8, *(int*)(self + 8));
    fn_80136704(self, 0);
    if (flag & 1) fn_80139FBC(self, 0x24);
}

extern void fn_8013A014(void* p);
extern void fn_8013A160(void* p);
extern void fn_8013D148(void* p);
extern void fn_8013954C(register struct AptCtx* self);
extern void* fn_80111C78(void* p, int c, unsigned n);   /* memset */

/* Apt VM context constructor (object is at least 0x3F3C bytes). */
AptCtx* fn_80138A50(register AptCtx* self) {
    fn_8013A014(&self->list);
    fn_8013A160(self->f3814);
    fn_8013D148(&self->f3a18);
    fn_8013D148(&self->f3a1c);
    self->f1400 = self->f1404 = (char*)self;
    self->rootCount = 0;
    fn_8013954C(self);
    self->evCount = 0;
    self->f3f28 = 0;
    self->f3f2c = 0;
    self->f3f30 = -1;
    self->f3f34 = -1;
    MEMBER(int, 0x1c10) = 0;
    fn_80111C78(self->slots, 0, 0x400);
    self->f3e20 = 0;
    self->f3f38 = 0;
    return self;
}

extern int fn_8013218C(void* list);
extern void fn_80134210(void* list, int item);
extern void fn_80139AA4(register void* self);
extern void fn_8013A1A0(void* p, int flag);
extern void fn_8013A054(void* p, int flag);
extern void fn_80139ECC(register void* p, register unsigned n);

/* Apt VM context destructor. */
void fn_80138B28(register AptCtx* self, int flag) {
    int count = self->list.count;
    int i = 0;
    while (i < fn_8013218C(&self->list)) {
        if (self->list.items[i]) {
            fn_80134210(&self->list, self->list.items[i]);
            count--;
            if (count == 0) break;
        }
        i++;
    }
    i = 0;
    while (i <= 0x3f) {
        if (count == self->f3e20) break;
        if (self->slots[i].used == 0) goto next;
        count++;
        (*(ReleaseFn*)((char*)lbl_802D67B4 + fn_8012C7C8(self->slots[i].obj) * 4))(self->slots[i].obj);
        self->slots[i].used = 0;
    next:
        i++;
    }
    fn_80139AA4(self);
    fn_8013D198(&self->f3a1c, 2);
    fn_8013D198(&self->f3a18, 2);
    fn_8013A1A0(self->f3814, 2);
    fn_8013A054(&self->list, 2);
    if (flag & 1) fn_80139ECC(self, 0x3f3c);
}

typedef struct { char pad[0x61c]; int curId; char pad2[0x100]; } AptMachine;
extern AptMachine lbl_8033D2A8;
typedef struct { char pad[0x18]; int f18; } AptClip;
extern AptClip* fn_80131EBC(void* obj);
extern int fn_80139DF0(AptClip* c);
extern void fn_8014A254(void* g, int a, AptClip* c, int b);
extern void fn_80148994(void* g);

/* Advance the setInterval timers by dt. */
void fn_80138D30(register AptCtx* self, int dt) {
    int i;
    int n = 0;
    for (i = 0; i <= 0x3f; i++) {
        AptClip* clip;
        int ok;
        if (n == self->f3e20) break;
        if (self->slots[i].used == 0) continue;
        n++;
        self->slots[i].remaining = self->slots[i].remaining - (float)dt;
        if (!(self->slots[i].remaining >= 0.0f)) {
        clip = fn_80131EBC(self->slots[i].obj);
        ok = fn_80139DF0(clip);
        if (ok) {
            fn_8014A254(&lbl_8033D2A8, clip->f18, clip, -1);
            fn_80148994(&lbl_8033D2A8);
            self->slots[i].remaining = self->slots[i].remaining + self->slots[i].interval;
        } else {
            (*(ReleaseFn*)((char*)lbl_802D67B4 + fn_8012C7C8(self->slots[i].obj) * 4))(self->slots[i].obj);
            self->slots[i].used = 0;
        }
        }
    }
}

typedef struct { char pad[0x10]; int f10; int f14; } AptInfo;
extern int fn_8013209C(void* o, int a);
extern AptInfo* fn_80131FCC(void* o);
extern void fn_80145F9C(void* o, int a);
extern int fn_80132024(void* o, int a);
extern AptInfo* fn_80133540(void* o);
extern void fn_80146B8C(void* o);

/* Release every root object (the display roots at 0x1408), then empty the list. */
void fn_80138F68(register AptCtx* self) {
    int i = 0;
    while (i < self->rootCount) {
        if (fn_8013209C(self->roots[i], 0)) {
            AptInfo* info = fn_80131FCC(self->roots[i]);
            if (info->f14 == 0) fn_80145F9C(self->roots[i], 1);
        } else if (fn_80132024(self->roots[i], 0)) {
            AptInfo* info = fn_80133540(self->roots[i]);
            if (info->f10 == -1) fn_80146B8C(self->roots[i]);
        }
        (*(ReleaseFn*)((char*)lbl_802D67B4 + fn_8012C7C8(self->roots[i]) * 4))(self->roots[i]);
        i++;
    }
    self->rootCount = 0;
}

typedef struct { int type; int id; int* a; int b; int c; } AptMsg;
extern int fn_8012C8A4(int v);
extern int fn_80139D88(int v);
extern void fn_8014ADB4(void* g, int a, int b, int c);
extern void fn_8013A2AC(void* p, int a);
extern void fn_8013A308(void* p);
extern void fn_8013A3A4(void* p);
extern char* fn_80139F24(void* self, char* p);
extern char lbl_8033D838[0x40];

#define MSG ((AptMsg*)msg)

/* Run the queued messages from the read pointer to the write pointer. */
void fn_80139110(register AptCtx* self) {
    char* msg;
    char* end;
    msg = self->f1400;
    while (msg != self->f1404) {
        end = self->f1404;
        if (MSG->type == 0) {
            lbl_8033D2A8.curId = MSG->id;
            if (!fn_8012C8A4(MSG->b) && !fn_80139D88(MSG->b)) {
                fn_8014ADB4(&lbl_8033D2A8, *MSG->a, MSG->b, -1);
                fn_80138F68(self);
            }
        } else if (MSG->type == 1) {
            lbl_8033D2A8.curId = MSG->id;
            fn_8013A2AC(lbl_8033D838, (int)MSG->a);
            fn_8014A254(&lbl_8033D2A8, (int)MSG->a, (AptClip*)MSG->b, MSG->c);
            fn_8013A308(lbl_8033D838);
            fn_8013A3A4(&lbl_8033D2A8);
        } else {
        }
        if ((unsigned)end > (unsigned)self->f1404) {
            msg = msg - (end - self->f1404);
        }
        msg = fn_80139F24(self, msg);
    }
    fn_80138F68(self);
    fn_8013954C(self);
}

extern int lbl_8037BE88;
extern int lbl_8037D0F0;

/* Queue one event word (and trace it through the platform hook when enabled). */
void fn_801392B0(register AptCtx* self, unsigned word) {
    self->evWords[self->evCount] = word;
    self->evCount++;
    if (lbl_8037BE88) {
        struct { int tag; unsigned word; } rec;
        rec.tag = lbl_8037D0F0;
        rec.word = word;
        lbl_8033D1E0.hook18(&rec, 8);
    }
}

/* Event word type 1: [clip:15 | a:7 | 1 | b:8 | 0 0].
   NON_MATCHING: the compiler folds the `| 1` onto the clip term (ori r0,r0,1); the original keeps it on the a term. */
void fn_8013934C(register AptCtx* self, int clip, int a, int b) {
    unsigned word = ((clip & 0x7fff) << 17) | (((a & 0x7f) << 10) | 1 | ((b & 0xff) << 2));
    fn_801392B0(self, word);
}

/* Event word type 0: [clip:15 | 0 | value:15 | 0 0]. */
void fn_801393C8(register AptCtx* self, int clip, int value) {
    unsigned word = ((clip & 0x7fff) << 17) | ((value & 0x7fff) << 2);
    fn_801392B0(self, word);
}

typedef struct { char pad[8]; int f8; } AptKey;
extern AptKey* fn_80131FF8(void* o);

/* clearInterval: drop the timers whose clip belongs to `target`. */
void fn_8013942C(register AptCtx* self, void* target) {
    int i = 0;
    while (i <= 0x3f) {
        if (self->slots[i].used) {
            register AptClip* clip = fn_80131EBC(self->slots[i].obj);
            if (((AptInfo*)clip)->f14 == fn_80131FF8(target)->f8) {
                (*(ReleaseFn*)((char*)lbl_802D67B4 + fn_8012C7C8(self->slots[i].obj) * 4))(self->slots[i].obj);
                self->slots[i].used = 0;
            }
        }
        i++;
    }
}

#define RELEASE_OBJ(o) (*(ReleaseFn*)((char*)lbl_802D67B4 + fn_8012C7C8(o) * 4))(o)

/* Drop the queued messages without running them (releasing the objects they hold). */
void fn_8013954C(register AptCtx* self) {
    char* msg = self->f1400;
    while (msg != self->f1404) {
        if (MSG->type == 0) {
            RELEASE_OBJ((void*)MSG->b);
        } else if (MSG->type == 1) {
            RELEASE_OBJ(MSG->a);
            RELEASE_OBJ((void*)MSG->b);
        } else {
        }
        msg = fn_80139F24(self, msg);
    }
    self->f1400 = self->f1404 = (char*)self;
}

extern void fn_8012C800(void* o);                /* add a reference */
extern char* fn_80139F70(void* self, char* p);   /* previous queue slot */

#define TAIL ((AptMsg*)self->f1404)
#define HEAD ((AptMsg*)self->f1400)

/* Queue (at the tail) a message that calls `b` with id `c`; `b` gains a reference. */
void fn_801396A4(register AptCtx* self, int a, int b, int c) {
    char* next = fn_80139F24(self, self->f1404);
    if (next == self->f1400) return;
    {
        TAIL->type = 0;
        TAIL->a = (int*)a;
        TAIL->b = b;
        fn_8012C800((void*)b);
        TAIL->id = c;
        self->f1404 = next;
    }
}

/* Same, at the head of the queue. */
void fn_80139748(register AptCtx* self, int a, int b, int c) {
    char* next = fn_80139F70(self, self->f1400);
    if (next == self->f1404) return;
    {
        self->f1400 = next;
        HEAD->type = 0;
        HEAD->a = (int*)a;
        HEAD->b = b;
        fn_8012C800((void*)b);
        HEAD->id = c;
    }
}

/* Head-of-queue message of type 1: two referenced objects and a number. */
void fn_801397EC(register AptCtx* self, int a, int b, int c, int id) {
    char* next = fn_80139F70(self, self->f1400);
    if (next == self->f1404) return;
    {
        self->f1400 = next;
        HEAD->type = 1;
        HEAD->id = id;
        HEAD->a = (int*)a;
        fn_8012C800(HEAD->a);
        HEAD->b = b;
        fn_8012C800((void*)HEAD->b);
        HEAD->c = c;
    }
}
