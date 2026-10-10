// Game code at 0x802372E4-0x80252B4C: trivial functions (empty virtuals, getters, setters, destructors). Compiled at -O2.
// Each is named by address with an asm label so it keeps the symbol of the original.

extern "C" int fn_80111FF8(int);
extern "C" int fn_801C2760(int);
extern "C" int fn_8023C304(int, int);
extern "C" int fn_8023EF78(int);
extern "C" int fn_802401CC(int);
extern "C" int fn_80240288(int);
extern "C" int fn_802424CC(int);
extern "C" int fn_80249BB8(int, int, int);
extern "C" int fn_80252AB0(int, int);
extern "C" void fn_801B8A60(void*);
extern char lbl_80299CD8[];
extern char lbl_802C9648[];
extern char lbl_802CEEB0[];
extern char lbl_802CF098[];
extern char lbl_802CF1C8[];
extern char lbl_802CF2A8[];
extern char lbl_802CF470[];
extern char lbl_802CF7D8[];
extern char lbl_802CFA58[];
extern int lbl_8037C5E8;
extern int lbl_8037C604;
extern int lbl_8037D530;
extern int lbl_8037D560;

// 0x80238468
int fn_80238468(char* self) asm("fn_80238468");
int fn_80238468(char* self)
{
    return *(short*)((char*)self + 1088);
}

// 0x80238570
int fn_80238570(char* self) asm("fn_80238570");
int fn_80238570(char* self)
{
    return *(int*)(self + 0x598);
}

// 0x80238694
int fn_80238694(char* self) asm("fn_80238694");
int fn_80238694(char* self)
{
    return *(int*)(self + 0x4BC);
}

// 0x8023896C
int fn_8023896C(char* self) asm("fn_8023896C");
int fn_8023896C(char* self)
{
    return *(short*)((char*)self + 1112);
}

// 0x8023899C
int fn_8023899C(char* self) asm("fn_8023899C");
int fn_8023899C(char* self)
{
    return 0;
}

// 0x80239C14
void fn_80239C14(char* self, int a) asm("fn_80239C14");
void fn_80239C14(char* self, int a)
{
    *(short*)((char*)self + 1142) = a;
}

// 0x80239C1C
void fn_80239C1C(char* self, int a) asm("fn_80239C1C");
void fn_80239C1C(char* self, int a)
{
    *(short*)((char*)self + 1144) = a;
}

// 0x80239C24
void fn_80239C24(char* self, int a) asm("fn_80239C24");
void fn_80239C24(char* self, int a)
{
    *(short*)((char*)self + 1146) = a;
}

// 0x80239DDC
void fn_80239DDC(char* self, int flag) asm("fn_80239DDC");
void fn_80239DDC(char* self, int flag)
{
    *(char**)(self + 0) = lbl_802CEEB0;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x80239E3C
int fn_80239E3C(char* self) asm("fn_80239E3C");
int fn_80239E3C(char* self)
{
    return *(short*)((char*)self + 1094);
}

// 0x80239E44
void fn_80239E44(char* self, int a) asm("fn_80239E44");
void fn_80239E44(char* self, int a)
{
    *(short*)((char*)self + 1094) = a;
}

// 0x80239E4C
int fn_80239E4C(char* self) asm("fn_80239E4C");
int fn_80239E4C(char* self)
{
    return *(int*)(self + 0x490);
}

// 0x80239E8C
void fn_80239E8C(char* self, int a) asm("fn_80239E8C");
void fn_80239E8C(char* self, int a)
{
    *(short*)((char*)self + 1064) = a;
}

// 0x80239EDC
int fn_80239EDC(char* self) asm("fn_80239EDC");
int fn_80239EDC(char* self)
{
    return *(int*)(self + 0x4A0);
}

// 0x80239EE4
void fn_80239EE4(char* self, int a) asm("fn_80239EE4");
void fn_80239EE4(char* self, int a)
{
    *(int*)((char*)self + 1184) = a;
}

// 0x80239EEC
int fn_80239EEC(char* self) asm("fn_80239EEC");
int fn_80239EEC(char* self)
{
    return *(int*)(self + 0x4A8);
}

// 0x80239F24
int fn_80239F24(char* self) asm("fn_80239F24");
int fn_80239F24(char* self)
{
    return *(int*)(self + 0x4A4);
}

// 0x80239F5C
int fn_80239F5C(char* self) asm("fn_80239F5C");
int fn_80239F5C(char* self)
{
    return *(int*)(self + 0x4B0);
}

// 0x80239F64
void fn_80239F64(char* self, int a) asm("fn_80239F64");
void fn_80239F64(char* self, int a)
{
    *(int*)((char*)self + 1200) = a;
}

// 0x80239F6C
void fn_80239F6C(char* self, int a) asm("fn_80239F6C");
void fn_80239F6C(char* self, int a)
{
    *(int*)((char*)self + 1448) = a;
}

// 0x80239F74
int fn_80239F74(char* self) asm("fn_80239F74");
int fn_80239F74(char* self)
{
    return *(int*)(self + 0x5A8);
}

// 0x80239F94
void fn_80239F94(char* self, int flag) asm("fn_80239F94");
void fn_80239F94(char* self, int flag)
{
    *(char**)(self + 0) = lbl_80299CD8;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x8023AD48
void fn_8023AD48(char* self) asm("fn_8023AD48");
void fn_8023AD48(char* self)
{
    *(int*)((char*)self + 32) = (*(int*)((char*)self + 32) | 256);
}

// 0x8023AD58
void fn_8023AD58(char* self) asm("fn_8023AD58");
void fn_8023AD58(char* self)
{
    *(int*)(self + 0x38) = -3;
}

// 0x8023AD64
void fn_8023AD64(char* self) asm("fn_8023AD64");
void fn_8023AD64(char* self)
{
    *(int*)(self + 0x38) = -2;
}

// 0x8023B09C
void fn_8023B09C(char* self, int flag) asm("fn_8023B09C");
void fn_8023B09C(char* self, int flag)
{
    *(char**)(self + 0x10) = lbl_802C9648;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x8023C244
int fn_8023C244(void) asm("fn_8023C244");
int fn_8023C244(void)
{
    return lbl_8037D530;
}

// 0x8023C2D8
int fn_8023C2D8(char* self) asm("fn_8023C2D8");
int fn_8023C2D8(char* self)
{
    return *(int*)(self + 0x4);
}

// 0x8023C2E0
void fn_8023C2E0(char* self) asm("fn_8023C2E0");
void fn_8023C2E0(char* self)
{
    fn_80111FF8((int)*(int*)((char*)self + 0));
}

// 0x8023C304
void fn_8023C304(char* self) asm("fn_8023C304");
void fn_8023C304(char* self)
{
    *(char*)((char*)*(int*)((char*)self + 0) + 0) = 0;
}

// 0x8023C40C
int fn_8023C40C(char* self) asm("fn_8023C40C");
int fn_8023C40C(char* self)
{
    return *(int*)(self + 0x0);
}

// 0x8023C414
int fn_8023C414(char* self) asm("fn_8023C414");
int fn_8023C414(char* self)
{
    return *(int*)(self + 0x0);
}

// 0x8023C8A0
int fn_8023C8A0(char* self) asm("fn_8023C8A0");
int fn_8023C8A0(char* self)
{
    return *(int*)(self + 0x4);
}

// 0x8023C8A8
void fn_8023C8A8(char* self) asm("fn_8023C8A8");
void fn_8023C8A8(char* self)
{
    fn_802424CC((int)*(int*)((char*)self + 0));
}

// 0x8023C8CC
void fn_8023C8CC(char* self) asm("fn_8023C8CC");
void fn_8023C8CC(char* self)
{
    *(short*)((char*)*(int*)((char*)self + 0) + 0) = 0;
}

// 0x8023C9EC
int fn_8023C9EC(char* self) asm("fn_8023C9EC");
int fn_8023C9EC(char* self)
{
    return *(int*)(self + 0x0);
}

// 0x8023C9F4
int fn_8023C9F4(char* self) asm("fn_8023C9F4");
int fn_8023C9F4(char* self)
{
    return *(int*)(self + 0x0);
}

// 0x8023CE6C
void fn_8023CE6C(char* self, int flag) asm("fn_8023CE6C");
void fn_8023CE6C(char* self, int flag)
{
    *(char**)(self + 0) = lbl_802CF2A8;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x8023CF10
void fn_8023CF10(char* self, int flag) asm("fn_8023CF10");
void fn_8023CF10(char* self, int flag)
{
    *(char**)(self + 0) = lbl_802CF2A8;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x8023CF44
void fn_8023CF44(void* self) asm("fn_8023CF44");
void fn_8023CF44(void* self)
{
}

// 0x8023D068
void fn_8023D068(void* self) asm("fn_8023D068");
void fn_8023D068(void* self)
{
}

// 0x8023D06C
void fn_8023D06C(void* self) asm("fn_8023D06C");
void fn_8023D06C(void* self)
{
}

// 0x8023D070
void fn_8023D070(void* self) asm("fn_8023D070");
void fn_8023D070(void* self)
{
}

// 0x8023D074
void fn_8023D074(void* self) asm("fn_8023D074");
void fn_8023D074(void* self)
{
}

// 0x8023D078
int fn_8023D078(char* self) asm("fn_8023D078");
int fn_8023D078(char* self)
{
    return 0;
}

// 0x8023D080
void fn_8023D080(void* self) asm("fn_8023D080");
void fn_8023D080(void* self)
{
}

// 0x8023D084
void fn_8023D084(char* self, int a) asm("fn_8023D084");
void fn_8023D084(char* self, int a)
{
    fn_8023C304((int)a, (int)a);
}

// 0x8023D0A8
void fn_8023D0A8(void* self) asm("fn_8023D0A8");
void fn_8023D0A8(void* self)
{
}

// 0x8023D2BC
int fn_8023D2BC(char* self) asm("fn_8023D2BC");
int fn_8023D2BC(char* self)
{
    return 0;
}

// 0x8023D2C4
int fn_8023D2C4(char* self) asm("fn_8023D2C4");
int fn_8023D2C4(char* self)
{
    return 0;
}

// 0x8023D2CC
int fn_8023D2CC(char* self) asm("fn_8023D2CC");
int fn_8023D2CC(char* self)
{
    return 0;
}

// 0x8023D2EC
int fn_8023D2EC(char* self) asm("fn_8023D2EC");
int fn_8023D2EC(char* self)
{
    return 0;
}

// 0x8023D2F4
void fn_8023D2F4(void* self) asm("fn_8023D2F4");
void fn_8023D2F4(void* self)
{
}

// 0x8023D2F8
void fn_8023D2F8(void* self) asm("fn_8023D2F8");
void fn_8023D2F8(void* self)
{
}

// 0x8023DE20
void fn_8023DE20(char* self, int flag) asm("fn_8023DE20");
void fn_8023DE20(char* self, int flag)
{
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x8023E348
void fn_8023E348(char* self) asm("fn_8023E348");
void fn_8023E348(char* self)
{
    *(int*)(self + 0x0) = 0;
}

// 0x8023E4C0
int fn_8023E4C0(char* self) asm("fn_8023E4C0");
int fn_8023E4C0(char* self)
{
    return 30;
}

// 0x8023E644
void fn_8023E644(char* self, int flag) asm("fn_8023E644");
void fn_8023E644(char* self, int flag)
{
    *(char**)(self + 0x1c) = lbl_802CF470;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x8023E834
void fn_8023E834(char* self, int a) asm("fn_8023E834");
void fn_8023E834(char* self, int a)
{
    *(short*)((char*)self + 48) = a;
}

// 0x8023E83C
int fn_8023E83C(char* self) asm("fn_8023E83C");
int fn_8023E83C(char* self)
{
    return *(short*)((char*)self + 48);
}

// 0x8023E844
void fn_8023E844(char* self) asm("fn_8023E844");
void fn_8023E844(char* self)
{
    *(short*)((char*)self + 48) = 0;
}

// 0x8023E850
void fn_8023E850(char* self) asm("fn_8023E850");
void fn_8023E850(char* self)
{
    fn_80240288((int)((int)self + 8));
}

// 0x8023F194
void fn_8023F194(char* self) asm("fn_8023F194");
void fn_8023F194(char* self)
{
    fn_8023EF78((int)self);
}

// 0x8023F8D8
void fn_8023F8D8(char* self) asm("fn_8023F8D8");
void fn_8023F8D8(char* self)
{
    fn_802401CC((int)((int)self + 8));
}

// 0x8023F924
void fn_8023F924(void* self) asm("fn_8023F924");
void fn_8023F924(void* self)
{
}

// 0x8023FC80
char* fn_8023FC80(char* self) asm("fn_8023FC80");
char* fn_8023FC80(char* self)
{
    return self + 0x10;
}

// 0x802401C0
void fn_802401C0(char* self) asm("fn_802401C0");
void fn_802401C0(char* self)
{
    *(int*)((char*)self + 12) = *(int*)((char*)self + 8);
}

// 0x802403BC
int fn_802403BC(char* self) asm("fn_802403BC");
int fn_802403BC(char* self)
{
    return *(int*)(self + 0x4);
}

// 0x802403C4
int fn_802403C4(char* self) asm("fn_802403C4");
int fn_802403C4(char* self)
{
    return *(int*)(self + 0x4);
}

// 0x802403CC
int fn_802403CC(char* self) asm("fn_802403CC");
int fn_802403CC(char* self)
{
    return *(int*)(self + 0x28);
}

// 0x802403D4
void fn_802403D4(char* self, int a) asm("fn_802403D4");
void fn_802403D4(char* self, int a)
{
    *(int*)((char*)self + 52) = a;
}

// 0x802403DC
int fn_802403DC(char* self) asm("fn_802403DC");
int fn_802403DC(char* self)
{
    return *(int*)(self + 0x34);
}

// 0x80242F10
int fn_80242F10(char* self) asm("fn_80242F10");
int fn_80242F10(char* self)
{
    return *(int*)(self + 0x18);
}

// 0x80242F18
int fn_80242F18(char* self) asm("fn_80242F18");
int fn_80242F18(char* self)
{
    return *(int*)(self + 0x24);
}

// 0x80248480
int fn_80248480(char* self) asm("fn_80248480");
int fn_80248480(char* self)
{
    return *(int*)(self + 0x14);
}

// 0x80248488
int fn_80248488(char* self) asm("fn_80248488");
int fn_80248488(char* self)
{
    return 64;
}

// 0x80248C10
void fn_80248C10(char* self, int flag) asm("fn_80248C10");
void fn_80248C10(char* self, int flag)
{
    *(char**)(self + 0) = lbl_802CF7D8;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x80248C44
int fn_80248C44(char* self) asm("fn_80248C44");
int fn_80248C44(char* self)
{
    return *(int*)(self + 0x2C);
}

// 0x80248C4C
int fn_80248C4C(char* self) asm("fn_80248C4C");
int fn_80248C4C(char* self)
{
    return *(int*)(self + 0x30);
}

// 0x80248C54
void fn_80248C54(void* self) asm("fn_80248C54");
void fn_80248C54(void* self)
{
}

// 0x80248C58
void fn_80248C58(void* self) asm("fn_80248C58");
void fn_80248C58(void* self)
{
}

// 0x80248C5C
void fn_80248C5C(void* self) asm("fn_80248C5C");
void fn_80248C5C(void* self)
{
}

// 0x80248C60
int fn_80248C60(char* self) asm("fn_80248C60");
int fn_80248C60(char* self)
{
    return 0;
}

// 0x80248C68
int fn_80248C68(char* self) asm("fn_80248C68");
int fn_80248C68(char* self)
{
    return 0;
}

// 0x80248C70
int fn_80248C70(char* self) asm("fn_80248C70");
int fn_80248C70(char* self)
{
    return 0;
}

// 0x80248C78
void fn_80248C78(char* self, int a) asm("fn_80248C78");
void fn_80248C78(char* self, int a)
{
    *(int*)((char*)self + 4) = a;
    *(int*)((char*)self + 0) = (int)lbl_802CFA58;
}

// 0x80248D00
void fn_80248D00(char* self) asm("fn_80248D00");
void fn_80248D00(char* self)
{
    fn_801C2760((int)self);
}

// 0x8024969C
void fn_8024969C(char* self, int a) asm("fn_8024969C");
void fn_8024969C(char* self, int a)
{
    *(int*)((char*)self + 88) = a;
}

// 0x802496F0
char* fn_802496F0(char* self) asm("fn_802496F0");
char* fn_802496F0(char* self)
{
    return self + 0x10;
}

// 0x80249B80
void fn_80249B80(void* self) asm("fn_80249B80");
void fn_80249B80(void* self)
{
}

// 0x8024C3E4
void fn_8024C3E4(char* self, int a) asm("fn_8024C3E4");
void fn_8024C3E4(char* self, int a)
{
    fn_80249BB8((int)self, (int)a, (int)1);
}

// 0x8024F82C
void fn_8024F82C(void* self) asm("fn_8024F82C");
void fn_8024F82C(void* self)
{
}

// 0x8024FB00
void fn_8024FB00(void* self) asm("fn_8024FB00");
void fn_8024FB00(void* self)
{
}

// 0x8024FB04
void fn_8024FB04(void* self) asm("fn_8024FB04");
void fn_8024FB04(void* self)
{
}

// 0x8024FE1C
int fn_8024FE1C(void) asm("fn_8024FE1C");
int fn_8024FE1C(void)
{
    return lbl_8037D560;
}

// 0x80252AF0
int fn_80252AF0(char* self) asm("fn_80252AF0");
int fn_80252AF0(char* self)
{
    *(int*)((char*)self + 0) = 0;
    return 1;
}

// 0x80252B20
void fn_80252B20(char* self) asm("fn_80252B20");
void fn_80252B20(char* self)
{
    fn_80252AB0((int)1, (int)(0 | 65535));
}

