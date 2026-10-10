/* ActionScript (Apt) value/object library, 0x801352FC-0x8013C054. Compiled as C at -O0.
   Parameters declared `register` are the ones the original keeps in r29-r31
   (`this` and the destructor's in-charge flag). */

typedef struct {
    void* (*alloc)(unsigned);        /* 0x00 */
    void* slot4;                     /* 0x04 */
    void (*free)(void*, unsigned);   /* 0x08 */
    void* slotC[13];                 /* 0x0C */
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
#define MEMBER(T, off) (*(T*)(self + (off)))

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

