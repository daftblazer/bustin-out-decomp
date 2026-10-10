/* ActionScript value/object library, 0x801352FC-0x8013C054. Compiled as C at -O0. */

typedef struct {
    void* (*alloc)(unsigned);        /* 0x00 */
    void* slot4;                     /* 0x04 */
    void (*free)(void*, unsigned);   /* 0x08 */
    void* rest[15];
} UiAllocTable;
extern UiAllocTable lbl_8033D1E0;

typedef void (*ReleaseFn)(void*);
extern ReleaseFn lbl_802D67B4[29];           /* release function per object type */
extern int fn_8012C7C8(void* obj);          /* object type index (low 15 bits of word 0) */
extern void fn_8012CCB0(void* p, int flag);
extern void fn_8012F564(void* p, int flag);

extern void* lbl_8037BEF4;
extern void* lbl_8037BEF8;
extern void* lbl_8037BEFC;

void fn_801365A4(void*, int);

#define RELEASE(p) if (p) { (*(ReleaseFn*)((char*)lbl_802D67B4 + fn_8012C7C8(p) * 4))(p); p = 0; }

void fn_801352FC(register char* self, register int flag) {
    RELEASE(lbl_8037BEF4);
    RELEASE(lbl_8037BEF8);
    fn_8012CCB0(self + 4, 0);
    if (flag & 1) fn_801365A4(self, 0xc);
}
