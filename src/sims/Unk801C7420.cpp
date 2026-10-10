// Game code at 0x801C7420-0x801CDADC: trivial functions (empty virtuals, getters, setters, destructors). Compiled at -O2.
// Each is named by address with an asm label so it keeps the symbol of the original.

extern "C" int fn_801CDA70(int, int);
extern "C" int fn_801D2BD8(int);
extern "C" int fn_802306D0(int, int, int);
extern "C" int fn_802316EC(int);
extern "C" void fn_801B8A60(void*);
extern char lbl_802C6368[];
extern int lbl_8037C3E4;
extern int lbl_8037C3E8;
extern int lbl_8037C3EC;

// 0x801C7420
void fn_801C7420(char* self) asm("fn_801C7420");
void fn_801C7420(char* self)
{
    fn_801D2BD8((int)*(int*)((char*)self + 0));
}

// 0x801CBBFC
int fn_801CBBFC(char* self) asm("fn_801CBBFC");
int fn_801CBBFC(char* self)
{
    return 0;
}

// 0x801CBC04
void fn_801CBC04(void* self) asm("fn_801CBC04");
void fn_801CBC04(void* self)
{
}

// 0x801CBE24
int fn_801CBE24(char* self) asm("fn_801CBE24");
int fn_801CBE24(char* self)
{
    return 1129665107;
}

// 0x801CBE30
int fn_801CBE30(char* self) asm("fn_801CBE30");
int fn_801CBE30(char* self)
{
    return 2147483647;
}

// 0x801CBFD8
int fn_801CBFD8(char* self) asm("fn_801CBFD8");
int fn_801CBFD8(char* self)
{
    return 0;
}

// 0x801CC0A4
int fn_801CC0A4(char* self) asm("fn_801CC0A4");
int fn_801CC0A4(char* self)
{
    return 0;
}

// 0x801CC458
int fn_801CC458(char* self) asm("fn_801CC458");
int fn_801CC458(char* self)
{
    return *(int*)(self + 0x18);
}

// 0x801CC460
void fn_801CC460(void* self) asm("fn_801CC460");
void fn_801CC460(void* self)
{
}

// 0x801CC928
void fn_801CC928(char* self, int flag) asm("fn_801CC928");
void fn_801CC928(char* self, int flag)
{
    *(char**)(self + 0) = lbl_802C6368;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x801CCEEC
int fn_801CCEEC(char* self) asm("fn_801CCEEC");
int fn_801CCEEC(char* self)
{
    return 0;
}

// 0x801CD134
void fn_801CD134(char* self, int a) asm("fn_801CD134");
void fn_801CD134(char* self, int a)
{
    fn_802306D0((int)a, (int)self, (int)1);
}

// 0x801CD660
int fn_801CD660(char* self) asm("fn_801CD660");
int fn_801CD660(char* self)
{
    return *(int*)(self + 0x8);
}

// 0x801CD668
int fn_801CD668(char* self) asm("fn_801CD668");
int fn_801CD668(char* self)
{
    return *(int*)(self + 0xC);
}

// 0x801CD670
void fn_801CD670(char* self, int a) asm("fn_801CD670");
void fn_801CD670(char* self, int a)
{
    *(int*)((char*)self + 12) = a;
}

// 0x801CD678
int fn_801CD678(char* self) asm("fn_801CD678");
int fn_801CD678(char* self)
{
    return *(int*)(self + 0x10);
}

// 0x801CD680
void fn_801CD680(char* self, int a) asm("fn_801CD680");
void fn_801CD680(char* self, int a)
{
    *(int*)((char*)self + 16) = a;
}

// 0x801CD688
int fn_801CD688(char* self) asm("fn_801CD688");
int fn_801CD688(char* self)
{
    return *(int*)(self + 0x14);
}

// 0x801CD6B0
int fn_801CD6B0(char* self) asm("fn_801CD6B0");
int fn_801CD6B0(char* self)
{
    return *(int*)(self + 0x18);
}

// 0x801CD6B8
void fn_801CD6B8(char* self, int a) asm("fn_801CD6B8");
void fn_801CD6B8(char* self, int a)
{
    *(int*)((char*)self + 24) = a;
}

// 0x801CD6C0
void fn_801CD6C0(char* self, int a) asm("fn_801CD6C0");
void fn_801CD6C0(char* self, int a)
{
    *(int*)((char*)self + 28) = a;
    *(int*)((char*)self + 32) = 0;
}

// 0x801CD7B0
void fn_801CD7B0(char* self) asm("fn_801CD7B0");
void fn_801CD7B0(char* self)
{
    fn_802316EC((int)self);
}

// 0x801CD808
int fn_801CD808(char* self) asm("fn_801CD808");
int fn_801CD808(char* self)
{
    return *(int*)(self + 0x8);
}

// 0x801CDAB0
void fn_801CDAB0(char* self) asm("fn_801CDAB0");
void fn_801CDAB0(char* self)
{
    fn_801CDA70((int)1, (int)(0 | 65535));
}

