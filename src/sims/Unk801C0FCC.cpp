// Game code at 0x801C0FCC-0x801C41D8: trivial functions (empty virtuals, getters, setters, destructors). Compiled at -O2.
// Each is named by address with an asm label so it keeps the symbol of the original.

extern "C" int fn_801C15E4(int, int, int, int);
extern "C" int fn_801C416C(int, int);
extern "C" void fn_801B8A60(void*);
extern char lbl_802C3760[];
extern char lbl_802C4CC0[];
extern char lbl_802C4D08[];
extern char lbl_802C4DB0[];
extern char lbl_802C4DD0[];
extern char lbl_8035AB80[];

// 0x801C16BC
void fn_801C16BC(char* self, int a) asm("fn_801C16BC");
void fn_801C16BC(char* self, int a)
{
    fn_801C15E4((int)self, (int)a, (int)*(int*)((char*)self + 4), (int)1);
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

// 0x801C1720
int fn_801C1720(char* self) asm("fn_801C1720");
int fn_801C1720(char* self)
{
    return 0;
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

// 0x801C1764
int fn_801C1764(char* self) asm("fn_801C1764");
int fn_801C1764(char* self)
{
    return 0;
}

// 0x801C176C
int fn_801C176C(char* self) asm("fn_801C176C");
int fn_801C176C(char* self)
{
    return *(int*)(self + 0x1C);
}

// 0x801C1774
int fn_801C1774(char* self) asm("fn_801C1774");
int fn_801C1774(char* self)
{
    return 0;
}

// 0x801C1C18
int fn_801C1C18(char* self) asm("fn_801C1C18");
int fn_801C1C18(char* self)
{
    return 0;
}

// 0x801C1C7C
int fn_801C1C7C(char* self) asm("fn_801C1C7C");
int fn_801C1C7C(char* self)
{
    return *(int*)(self + 0x40);
}

// 0x801C1C84
int fn_801C1C84(char* self) asm("fn_801C1C84");
int fn_801C1C84(char* self)
{
    return 1;
}

// 0x801C1CF8
int fn_801C1CF8(char* self) asm("fn_801C1CF8");
int fn_801C1CF8(char* self)
{
    return 0;
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

// 0x801C244C
int fn_801C244C(char* self) asm("fn_801C244C");
int fn_801C244C(char* self)
{
    return 0;
}

// 0x801C2454
int fn_801C2454(char* self) asm("fn_801C2454");
int fn_801C2454(char* self)
{
    return 0;
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

// 0x801C2724
int fn_801C2724(char* self) asm("fn_801C2724");
int fn_801C2724(char* self)
{
    return *(short*)((char*)*(int*)((char*)self + 8) + 4);
}

// 0x801C2730
int fn_801C2730(char* self) asm("fn_801C2730");
int fn_801C2730(char* self)
{
    return *(int*)(self + 0x4);
}

// 0x801C2758
int fn_801C2758(char* self) asm("fn_801C2758");
int fn_801C2758(char* self)
{
    return 0;
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

// 0x801C38E0
int fn_801C38E0(char* self) asm("fn_801C38E0");
int fn_801C38E0(char* self)
{
    return 0;
}

// 0x801C38E8
int fn_801C38E8(char* self) asm("fn_801C38E8");
int fn_801C38E8(char* self)
{
    return 0;
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

// 0x801C39C8
int fn_801C39C8(char* self) asm("fn_801C39C8");
int fn_801C39C8(char* self)
{
    return *(int*)((char*)*(int*)((char*)self + 0) + 12);
}

// 0x801C3A18
int fn_801C3A18(char* self) asm("fn_801C3A18");
int fn_801C3A18(char* self)
{
    return *(int*)((char*)*(int*)((char*)self + 0) + 0);
}

// 0x801C3A24
int fn_801C3A24(char* self) asm("fn_801C3A24");
int fn_801C3A24(char* self)
{
    return 0;
}

// 0x801C3C7C
int fn_801C3C7C(char* self) asm("fn_801C3C7C");
int fn_801C3C7C(char* self)
{
    return 0;
}

// 0x801C40D8
int fn_801C40D8(char* self) asm("fn_801C40D8");
int fn_801C40D8(char* self)
{
    return *(int*)((char*)*(int*)((char*)self + 0) + 4);
}

// 0x801C40E4
int fn_801C40E4(char* self) asm("fn_801C40E4");
int fn_801C40E4(char* self)
{
    return *(int*)((char*)*(int*)((char*)self + 0) + 8);
}

// 0x801C41AC
void fn_801C41AC(char* self) asm("fn_801C41AC");
void fn_801C41AC(char* self)
{
    fn_801C416C((int)1, (int)(0 | 65535));
}

