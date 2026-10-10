// Game code at 0x8019479C-0x801A6F04: trivial functions (empty virtuals, getters, setters, destructors). Compiled at -O2.
// Each is named by address with an asm label so it keeps the symbol of the original.

extern "C" int fn_80169EE8(int);
extern "C" int fn_80169F1C(int, int);
extern "C" int fn_80170A64(int);
extern "C" int fn_80170A98(int);
extern "C" int fn_80197154(int);
extern "C" int fn_801A2868(int);
extern "C" int fn_801A63C0(int);
extern "C" int fn_801A6E84(int, int);
extern "C" int fn_801A6F04(int);
extern "C" int fn_801A6F9C(int);
extern "C" int fn_80279238(int, int, int);
extern "C" int fn_80289888(int);
extern "C" int fn_8028D7E4(int);
extern char lbl_802C11D0[];
extern char lbl_80350858[];
extern char lbl_80350878[];
extern char lbl_80351BC8[];
extern char lbl_80351BE8[];
extern char lbl_80351DF0[];
extern char lbl_80351E10[];
extern char lbl_80351E30[];
extern char lbl_80353220[];
extern char lbl_80353240[];
extern char lbl_80353780[];
extern int lbl_8037C220;
extern int lbl_8037C264;
extern int lbl_8037C268;
extern short lbl_8037C262;

// 0x80194B30
void fn_80194B30(void* self) asm("fn_80194B30");
void fn_80194B30(void* self)
{
}

// 0x80195BB4
void fn_80195BB4(char* self) asm("fn_80195BB4");
void fn_80195BB4(char* self)
{
    fn_80279238((int)(int)lbl_80353220, (int)self, (int)1);
}

// 0x80195FB4
void fn_80195FB4(char* self) asm("fn_80195FB4");
void fn_80195FB4(char* self)
{
    fn_80279238((int)(int)lbl_80353240, (int)self, (int)0);
}

// 0x801967A8
void fn_801967A8(char* self) asm("fn_801967A8");
void fn_801967A8(char* self)
{
    fn_80279238((int)(int)lbl_80351E10, (int)self, (int)1);
}

// 0x8019680C
void fn_8019680C(char* self) asm("fn_8019680C");
void fn_8019680C(char* self)
{
    fn_80279238((int)(int)lbl_80351DF0, (int)self, (int)1);
}

// 0x80196870
void fn_80196870(char* self) asm("fn_80196870");
void fn_80196870(char* self)
{
    fn_80279238((int)(int)lbl_80351E30, (int)self, (int)1);
}

// 0x80196B84
void fn_80196B84(char* self) asm("fn_80196B84");
void fn_80196B84(char* self)
{
    fn_80279238((int)(int)lbl_80351BC8, (int)self, (int)0);
}

// 0x80196BF4
void fn_80196BF4(char* self) asm("fn_80196BF4");
void fn_80196BF4(char* self)
{
    fn_80279238((int)(int)lbl_80351BE8, (int)self, (int)1);
}

// 0x801970B4
void fn_801970B4(char* self) asm("fn_801970B4");
void fn_801970B4(char* self)
{
    fn_80279238((int)(int)lbl_80350858, (int)self, (int)0);
}

// 0x80197124
void fn_80197124(char* self) asm("fn_80197124");
void fn_80197124(char* self)
{
    fn_80279238((int)(int)lbl_80350878, (int)self, (int)1);
}

// 0x80197430
void fn_80197430(char* self) asm("fn_80197430");
void fn_80197430(char* self)
{
    *(int*)((char*)self + 68) = (int)lbl_802C11D0;
    fn_80170A64((int)self);
}

// 0x80197460
void fn_80197460(char* self) asm("fn_80197460");
void fn_80197460(char* self)
{
    fn_80170A98((int)self);
}

// 0x80199388
void fn_80199388(char* self) asm("fn_80199388");
void fn_80199388(char* self)
{
    fn_801A63C0((int)(int)lbl_80353780);
}

// 0x801995B8
void fn_801995B8(char* self) asm("fn_801995B8");
void fn_801995B8(char* self)
{
    fn_801A2868((int)(int)lbl_80353780);
}

// 0x801995E0
void fn_801995E0(void* self) asm("fn_801995E0");
void fn_801995E0(void* self)
{
}

// 0x8019A2C4
void fn_8019A2C4(void* self) asm("fn_8019A2C4");
void fn_8019A2C4(void* self)
{
}

// 0x8019A2C8
void fn_8019A2C8(char* self) asm("fn_8019A2C8");
void fn_8019A2C8(char* self)
{
    fn_80169F1C((int)self, (int)32);
}

// 0x8019A2EC
void fn_8019A2EC(char* self) asm("fn_8019A2EC");
void fn_8019A2EC(char* self)
{
    fn_80169EE8((int)self);
}

// 0x8019B670
void fn_8019B670(void* self) asm("fn_8019B670");
void fn_8019B670(void* self)
{
}

// 0x8019B674
void fn_8019B674(char* self) asm("fn_8019B674");
void fn_8019B674(char* self)
{
    lbl_8037C268 = 1;
    lbl_8037C264 = 0;
    fn_80289888((int)self);
}

// 0x801A213C
void fn_801A213C(char* self, int a) asm("fn_801A213C");
void fn_801A213C(char* self, int a)
{
    *(int*)((char*)self + 1356) = *(int*)((char*)a + 4);
}

// 0x801A217C
void fn_801A217C(char* self) asm("fn_801A217C");
void fn_801A217C(char* self)
{
    fn_801A6F04((int)*(int*)((char*)self + 1352));
}

// 0x801A21A0
void fn_801A21A0(char* self) asm("fn_801A21A0");
void fn_801A21A0(char* self)
{
    fn_801A6F9C((int)*(int*)((char*)self + 1352));
}

// 0x801A2828
void fn_801A2828(void* self) asm("fn_801A2828");
void fn_801A2828(void* self)
{
}

// 0x801A3F0C
void fn_801A3F0C(void* self) asm("fn_801A3F0C");
void fn_801A3F0C(void* self)
{
}

// 0x801A515C
void fn_801A515C(char* self) asm("fn_801A515C");
void fn_801A515C(char* self)
{
    fn_8028D7E4((int)self);
}

// 0x801A6AD8
void fn_801A6AD8(void* self) asm("fn_801A6AD8");
void fn_801A6AD8(void* self)
{
}

// 0x801A6ED8
void fn_801A6ED8(char* self) asm("fn_801A6ED8");
void fn_801A6ED8(char* self)
{
    fn_801A6E84((int)1, (int)(0 | 65535));
}

