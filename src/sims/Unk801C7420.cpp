// Game code at 0x801C7420-0x801CDADC: trivial functions (empty virtuals, getters, setters, destructors). Compiled at -O2.
// Each is named by address with an asm label so it keeps the symbol of the original.

extern "C" void fn_801B8A60(void*);
extern char lbl_802C6368[];
// 0x801CBC04
void fn_801CBC04(void* self) asm("fn_801CBC04");
void fn_801CBC04(void* self)
{
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
    *(int*)(self + 0xC) = a;
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
    *(int*)(self + 0x10) = a;
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
    *(int*)(self + 0x18) = a;
}

// 0x801CD6C0
void fn_801CD6C0(char* self, int a) asm("fn_801CD6C0");
void fn_801CD6C0(char* self, int a)
{
    *(int*)(self + 0x1C) = a;
    *(int*)(self + 0x20) = 0;
}

// 0x801CD808
int fn_801CD808(char* self) asm("fn_801CD808");
int fn_801CD808(char* self)
{
    return *(int*)(self + 0x8);
}

