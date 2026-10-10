// Game code at 0x801C0FCC-0x801C41D8: trivial functions (empty virtuals, getters, setters, destructors). Compiled at -O2.
// Each is named by address with an asm label so it keeps the symbol of the original.

extern "C" void fn_801B8A60(void*);
extern char lbl_802C3760[];
extern char lbl_802C4D08[];
extern char lbl_802C4DB0[];
extern char lbl_802C4DD0[];
// 0x801C131C
void fn_801C131C(char* self) asm("fn_801C131C");
void fn_801C131C(char* self)
{
    *(int*)(self + 0x0) = 0;
    *(int*)(self + 0x8) = 0;
    *(int*)(self + 0x4) = 0;
}

// 0x801C16E4
void fn_801C16E4(char* self, int flag) asm("fn_801C16E4");
void fn_801C16E4(char* self, int flag)
{
    *(char**)(self + 0x18) = lbl_802C3760;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x801C1718
int fn_801C1718(char* self) asm("fn_801C1718");
int fn_801C1718(char* self)
{
    return *(int*)(self + 0x20);
}

// 0x801C1728
void fn_801C1728(char* self, int flag) asm("fn_801C1728");
void fn_801C1728(char* self, int flag)
{
    *(char**)(self + 0x18) = lbl_802C3760;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x801C175C
int fn_801C175C(char* self) asm("fn_801C175C");
int fn_801C175C(char* self)
{
    return *(int*)(self + 0x20);
}

// 0x801C176C
int fn_801C176C(char* self) asm("fn_801C176C");
int fn_801C176C(char* self)
{
    return *(int*)(self + 0x1C);
}

// 0x801C1C7C
int fn_801C1C7C(char* self) asm("fn_801C1C7C");
int fn_801C1C7C(char* self)
{
    return *(int*)(self + 0x40);
}

// 0x801C1D00
int fn_801C1D00(char* self) asm("fn_801C1D00");
int fn_801C1D00(char* self)
{
    return *(int*)(self + 0x58);
}

// 0x801C1D08
int fn_801C1D08(char* self) asm("fn_801C1D08");
int fn_801C1D08(char* self)
{
    return *(int*)(self + 0x54);
}

// 0x801C1D10
int fn_801C1D10(char* self) asm("fn_801C1D10");
int fn_801C1D10(char* self)
{
    return *(int*)(self + 0x50);
}

// 0x801C1D18
char* fn_801C1D18(char* self) asm("fn_801C1D18");
char* fn_801C1D18(char* self)
{
    return self + 0x4;
}

// 0x801C1D20
char* fn_801C1D20(char* self) asm("fn_801C1D20");
char* fn_801C1D20(char* self)
{
    return self + 0x5C;
}

// 0x801C1D28
char* fn_801C1D28(char* self) asm("fn_801C1D28");
char* fn_801C1D28(char* self)
{
    return self + 0x5F;
}

// 0x801C1D30
char* fn_801C1D30(char* self) asm("fn_801C1D30");
char* fn_801C1D30(char* self)
{
    return self + 0x15F;
}

// 0x801C1D38
char* fn_801C1D38(char* self) asm("fn_801C1D38");
char* fn_801C1D38(char* self)
{
    return self + 0x25F;
}

// 0x801C24C8
void fn_801C24C8(void* self) asm("fn_801C24C8");
void fn_801C24C8(void* self)
{
}

// 0x801C24CC
void fn_801C24CC(void* self) asm("fn_801C24CC");
void fn_801C24CC(void* self)
{
}

// 0x801C25B0
void fn_801C25B0(char* self, int flag) asm("fn_801C25B0");
void fn_801C25B0(char* self, int flag)
{
    *(char**)(self + 0) = lbl_802C4D08;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x801C26F0
void fn_801C26F0(char* self, int flag) asm("fn_801C26F0");
void fn_801C26F0(char* self, int flag)
{
    *(char**)(self + 0) = lbl_802C4D08;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x801C2730
int fn_801C2730(char* self) asm("fn_801C2730");
int fn_801C2730(char* self)
{
    return *(int*)(self + 0x4);
}

// 0x801C2760
void fn_801C2760(char* self, int flag) asm("fn_801C2760");
void fn_801C2760(char* self, int flag)
{
    *(char**)(self + 0) = lbl_802C4DD0;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x801C2794
void fn_801C2794(char* self, int flag) asm("fn_801C2794");
void fn_801C2794(char* self, int flag)
{
    *(char**)(self + 0x14) = lbl_802C4DB0;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x801C27FC
int fn_801C27FC(char* self) asm("fn_801C27FC");
int fn_801C27FC(char* self)
{
    return *(int*)(self + 0x0);
}

// 0x801C2804
int fn_801C2804(char* self) asm("fn_801C2804");
int fn_801C2804(char* self)
{
    return *(int*)(self + 0x4);
}

// 0x801C3968
void fn_801C3968(void* self) asm("fn_801C3968");
void fn_801C3968(void* self)
{
}

// 0x801C396C
void fn_801C396C(void* self) asm("fn_801C396C");
void fn_801C396C(void* self)
{
}

