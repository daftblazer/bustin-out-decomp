// Game code at 0x8026CB70-0x8026FE50: trivial functions (empty virtuals, getters, setters, destructors). Compiled at -O2.
// Each is named by address with an asm label so it keeps the symbol of the original.

extern "C" int fn_8010BC58(int);
extern "C" int fn_8010BC60(int);
extern "C" int fn_8010BC70(int);
extern "C" int fn_80112A9C(int, int, int);
extern "C" int fn_8026D2CC(int);
extern "C" int fn_8026DAA4(int);
extern "C" int fn_8026F568(int, int, int);
extern "C" int fn_8026F658(int, int);
extern "C" void fn_801B8A60(void*);
extern char lbl_802D1960[];
extern char lbl_802D19E8[];
extern int lbl_8037BD40;

// 0x8026D088
void fn_8026D088(char* self) asm("fn_8026D088");
void fn_8026D088(char* self)
{
    *(char*)((char*)self + 0) = 0;
}

// 0x8026D0A4
void fn_8026D0A4(char* self, int flag) asm("fn_8026D0A4");
void fn_8026D0A4(char* self, int flag)
{
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x8026D0DC
void fn_8026D0DC(char* self, int a) asm("fn_8026D0DC");
void fn_8026D0DC(char* self, int a)
{
    *(char*)((char*)self + 0) = a;
}

// 0x8026D2CC
void fn_8026D2CC(char* self, int flag) asm("fn_8026D2CC");
void fn_8026D2CC(char* self, int flag)
{
    *(char**)(self + 0) = lbl_802D19E8;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x8026D368
void fn_8026D368(void* self) asm("fn_8026D368");
void fn_8026D368(void* self)
{
}

// 0x8026D36C
void fn_8026D36C(void* self) asm("fn_8026D36C");
void fn_8026D36C(void* self)
{
}

// 0x8026D370
void fn_8026D370(void* self) asm("fn_8026D370");
void fn_8026D370(void* self)
{
}

// 0x8026D374
void fn_8026D374(void* self) asm("fn_8026D374");
void fn_8026D374(void* self)
{
}

// 0x8026D378
void fn_8026D378(void* self) asm("fn_8026D378");
void fn_8026D378(void* self)
{
}

// 0x8026D37C
void fn_8026D37C(void* self) asm("fn_8026D37C");
void fn_8026D37C(void* self)
{
}

// 0x8026D380
int fn_8026D380(char* self) asm("fn_8026D380");
int fn_8026D380(char* self)
{
    return 0;
}

// 0x8026D388
void fn_8026D388(void* self) asm("fn_8026D388");
void fn_8026D388(void* self)
{
}

// 0x8026D38C
void fn_8026D38C(void* self) asm("fn_8026D38C");
void fn_8026D38C(void* self)
{
}

// 0x8026D390
void fn_8026D390(void* self) asm("fn_8026D390");
void fn_8026D390(void* self)
{
}

// 0x8026D394
int fn_8026D394(char* self) asm("fn_8026D394");
int fn_8026D394(char* self)
{
    return 0;
}

// 0x8026D39C
void fn_8026D39C(void* self) asm("fn_8026D39C");
void fn_8026D39C(void* self)
{
}

// 0x8026D3A0
void fn_8026D3A0(void* self) asm("fn_8026D3A0");
void fn_8026D3A0(void* self)
{
}

// 0x8026D3A4
void fn_8026D3A4(void* self) asm("fn_8026D3A4");
void fn_8026D3A4(void* self)
{
}

// 0x8026D3BC
void fn_8026D3BC(char* self) asm("fn_8026D3BC");
void fn_8026D3BC(char* self)
{
    *(int*)((char*)self + 0) = (int)lbl_802D1960;
    fn_8026D2CC((int)self);
}

// 0x8026DAF4
void fn_8026DAF4(char* self) asm("fn_8026DAF4");
void fn_8026DAF4(char* self)
{
    fn_8026DAA4((int)self);
}

// 0x8026DB14
void fn_8026DB14(char* self) asm("fn_8026DB14");
void fn_8026DB14(char* self)
{
    fn_8010BC58((int)self);
}

// 0x8026DB34
int fn_8026DB34(char* self, int a) asm("fn_8026DB34");
int fn_8026DB34(char* self, int a)
{
    *(int*)((char*)a + 4) = 8192;
    return 0;
}

// 0x8026DB44
void fn_8026DB44(char* self) asm("fn_8026DB44");
void fn_8026DB44(char* self)
{
    fn_8010BC70((int)self);
}

// 0x8026DB64
void fn_8026DB64(char* self) asm("fn_8026DB64");
void fn_8026DB64(char* self)
{
    fn_8010BC60((int)self);
}

// 0x8026F3B8
void fn_8026F3B8(char* self, int a) asm("fn_8026F3B8");
void fn_8026F3B8(char* self, int a)
{
    fn_80112A9C((int)*(int*)((char*)lbl_8037BD40 + 8), (int)self, (int)a);
}

// 0x8026F540
void fn_8026F540(char* self, int a) asm("fn_8026F540");
void fn_8026F540(char* self, int a)
{
    fn_8026F568((int)self, (int)a, (int)((int)lbl_8037BD40 + 92));
}

// 0x8026F630
void fn_8026F630(char* self) asm("fn_8026F630");
void fn_8026F630(char* self)
{
    fn_8026F658((int)self, (int)((int)lbl_8037BD40 + 96));
}

