// Game code at 0x801AFC44-0x801B8ECC: trivial functions (empty virtuals, getters, setters, destructors). Compiled at -O2.
// Each is named by address with an asm label so it keeps the symbol of the original.

extern "C" int fn_80111FF8(int);
extern "C" int fn_8015BD54(int, int);
extern "C" int fn_80169EE8(int);
extern "C" int fn_80169F1C(int, int);
extern "C" int fn_801B1BC4(int, int, int, int, int, int);
extern "C" int fn_801B4268(int, int);
extern "C" int fn_801B8A3C(int);
extern "C" int fn_801B8DCC(int, int);
extern "C" int fn_801BE728(int);
extern "C" int fn_801BE780(int);
extern "C" int fn_8027988C(int, int, int);
extern char lbl_802B8160[];
extern char lbl_802DB894[];
extern char lbl_802DB8C0[];
extern char lbl_80359B00[];
extern char lbl_80359B3C[];
extern char lbl_80359B78[];
extern char lbl_80359FB4[];
extern int lbl_8037C358;
extern int lbl_8037C36C;
extern int lbl_8037D28C;
extern int lbl_8037D290;
extern int lbl_8037D294;

// 0x801AFCDC
void fn_801AFCDC(char* self, int a, int b) asm("fn_801AFCDC");
void fn_801AFCDC(char* self, int a, int b)
{
    *(int*)((char*)self + 4) = b;
    *(int*)((char*)self + 0) = a;
    *(char*)((char*)a + 0) = 0;
}

// 0x801AFD80
void fn_801AFD80(char* self) asm("fn_801AFD80");
void fn_801AFD80(char* self)
{
    fn_80111FF8((int)*(int*)((char*)self + 0));
}

// 0x801B15BC
void fn_801B15BC(void* self) asm("fn_801B15BC");
void fn_801B15BC(void* self)
{
}

// 0x801B16D0
void fn_801B16D0(void* self) asm("fn_801B16D0");
void fn_801B16D0(void* self)
{
}

// 0x801B16D4
void fn_801B16D4(void* self) asm("fn_801B16D4");
void fn_801B16D4(void* self)
{
}

// 0x801B16D8
void fn_801B16D8(void* self) asm("fn_801B16D8");
void fn_801B16D8(void* self)
{
}

// 0x801B19A8
void fn_801B19A8(char* self, int a, int b, int c) asm("fn_801B19A8");
void fn_801B19A8(char* self, int a, int b, int c)
{
    fn_801B1BC4((int)self, (int)a, (int)b, (int)0, (int)0, (int)c);
}

// 0x801B2448
void fn_801B2448(void* self) asm("fn_801B2448");
void fn_801B2448(void* self)
{
}

// 0x801B278C
void fn_801B278C(void* self) asm("fn_801B278C");
void fn_801B278C(void* self)
{
}

// 0x801B2790
void fn_801B2790(void* self) asm("fn_801B2790");
void fn_801B2790(void* self)
{
}

// 0x801B2794
void fn_801B2794(char* self) asm("fn_801B2794");
void fn_801B2794(char* self)
{
    lbl_8037C358 = ((int)lbl_8037C358 + 1);
}

// 0x801B27A4
int fn_801B27A4(void) asm("fn_801B27A4");
int fn_801B27A4(void)
{
    return lbl_8037C358;
}

// 0x801B2888
void fn_801B2888(char* self, int a, int b) asm("fn_801B2888");
void fn_801B2888(char* self, int a, int b)
{
    fn_8027988C((int)a, (int)b, (int)self);
}

// 0x801B42F0
void fn_801B42F0(char* self) asm("fn_801B42F0");
void fn_801B42F0(char* self)
{
    fn_801BE728((int)((int)self + 4));
}

// 0x801B4314
void fn_801B4314(char* self) asm("fn_801B4314");
void fn_801B4314(char* self)
{
    fn_801BE780((int)((int)self + 4));
}

// 0x801B7774
void fn_801B7774(char* self) asm("fn_801B7774");
void fn_801B7774(char* self)
{
    fn_80169F1C((int)self, (int)4);
}

// 0x801B7798
void fn_801B7798(char* self) asm("fn_801B7798");
void fn_801B7798(char* self)
{
    fn_80169EE8((int)self);
}

// 0x801B8630
int fn_801B8630(char* self) asm("fn_801B8630");
int fn_801B8630(char* self)
{
    return *(int*)(self + 0x10A4);
}

// 0x801B89D8
void fn_801B89D8(char* self) asm("fn_801B89D8");
void fn_801B89D8(char* self)
{
    fn_80169F1C((int)self, (int)4);
}

// 0x801B8A1C
void fn_801B8A1C(char* self) asm("fn_801B8A1C");
void fn_801B8A1C(char* self)
{
    fn_80169EE8((int)self);
}

// 0x801B8A3C
void __builtin_new(char* self) asm("__builtin_new");
void __builtin_new(char* self)
{
    fn_80169F1C((int)self, (int)4);
}

// 0x801B8A60
void __builtin_delete(char* self) asm("__builtin_delete");
void __builtin_delete(char* self)
{
    fn_80169EE8((int)self);
}

// 0x801B8A80
void fn_801B8A80(char* self) asm("fn_801B8A80");
void fn_801B8A80(char* self)
{
    fn_80169F1C((int)self, (int)4);
}

// 0x801B8AA4
void fn_801B8AA4(char* self) asm("fn_801B8AA4");
void fn_801B8AA4(char* self)
{
    fn_80169EE8((int)self);
}

// 0x801B8AC4
void fn_801B8AC4(char* self) asm("fn_801B8AC4");
void fn_801B8AC4(char* self)
{
    fn_80169F1C((int)self, (int)4);
}

// 0x801B8AE8
void fn_801B8AE8(char* self) asm("fn_801B8AE8");
void fn_801B8AE8(char* self)
{
    fn_80169EE8((int)self);
}

// 0x801B8B74
void fn_801B8B74(char* self) asm("fn_801B8B74");
void fn_801B8B74(char* self)
{
    fn_801B4268((int)(int)lbl_80359FB4, (int)2);
}

// 0x801B8E6C
void fn_801B8E6C(char* self) asm("fn_801B8E6C");
void fn_801B8E6C(char* self)
{
    *(int*)((char*)self + 0) = (int)lbl_802B8160;
}

// 0x801B8E7C
void fn_801B8E7C(char* self) asm("fn_801B8E7C");
void fn_801B8E7C(char* self)
{
    fn_8015BD54((int)self, (int)2);
}

// 0x801B8EA0
void fn_801B8EA0(char* self) asm("fn_801B8EA0");
void fn_801B8EA0(char* self)
{
    fn_801B8DCC((int)1, (int)(0 | 65535));
}

