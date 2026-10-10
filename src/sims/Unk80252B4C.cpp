// Game code at 0x80252B4C-0x8025F394: trivial functions (empty virtuals, getters, setters, destructors). Compiled at -O2.
// Each is named by address with an asm label so it keeps the symbol of the original.

extern "C" int fn_80253424(int);
extern "C" int fn_80254340(int);
extern "C" int fn_8025521C(int, int);
extern "C" int fn_8025D0E0(int);
extern "C" int fn_8025D160(int);
extern "C" int fn_8025D5C0(int, int);
extern "C" int fn_8025DB8C(int);
extern "C" int fn_8025DD8C(int, int, int);
extern "C" int fn_8025DEB4(int, int);
extern "C" int fn_8025EC64(int, int);
extern "C" void fn_801B8A60(void*);
extern char lbl_802D02C8[];
extern char lbl_8035D0D0[];
extern int lbl_8037D560;

// 0x80252F90
void fn_80252F90(char* self, int flag) asm("fn_80252F90");
void fn_80252F90(char* self, int flag)
{
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x80253404
void fn_80253404(char* self) asm("fn_80253404");
void fn_80253404(char* self)
{
    fn_80253424((int)self);
}

// 0x80253A58
int fn_80253A58(char* self) asm("fn_80253A58");
int fn_80253A58(char* self)
{
    return *(int*)(self + 0xC);
}

// 0x80254320
void fn_80254320(char* self) asm("fn_80254320");
void fn_80254320(char* self)
{
    fn_80254340((int)self);
}

// 0x80255FB4
void fn_80255FB4(char* self, int a) asm("fn_80255FB4");
void fn_80255FB4(char* self, int a)
{
    *(int*)((char*)self + 0) = a;
}

// 0x802560FC
void fn_802560FC(char* self, int flag) asm("fn_802560FC");
void fn_802560FC(char* self, int flag)
{
    *(char**)(self + 0) = lbl_802D02C8;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x80256344
void fn_80256344(char* self, int a) asm("fn_80256344");
void fn_80256344(char* self, int a)
{
    *(int*)((char*)a + 56) = *(int*)((char*)self + 1028);
    *(int*)((char*)self + 1028) = a;
}

// 0x80256394
void fn_80256394(char* self, int a) asm("fn_80256394");
void fn_80256394(char* self, int a)
{
    *(int*)((char*)a + 36) = *(int*)((char*)self + 1032);
    *(int*)((char*)self + 1032) = a;
}

// 0x8025720C
void fn_8025720C(void* self) asm("fn_8025720C");
void fn_8025720C(void* self)
{
}

// 0x80257210
void fn_80257210(void* self) asm("fn_80257210");
void fn_80257210(void* self)
{
}

// 0x802572DC
int fn_802572DC(char* self) asm("fn_802572DC");
int fn_802572DC(char* self)
{
    return 1;
}

// 0x802577C8
int fn_802577C8(char* self) asm("fn_802577C8");
int fn_802577C8(char* self)
{
    return 1;
}

// 0x802577D0
int fn_802577D0(char* self) asm("fn_802577D0");
int fn_802577D0(char* self)
{
    return 1;
}

// 0x802577D8
int fn_802577D8(char* self) asm("fn_802577D8");
int fn_802577D8(char* self)
{
    return *(int*)(self + 0x20);
}

// 0x8025797C
int fn_8025797C(char* self) asm("fn_8025797C");
int fn_8025797C(char* self)
{
    return *(int*)(self + 0x24);
}

// 0x80257A2C
int fn_80257A2C(char* self) asm("fn_80257A2C");
int fn_80257A2C(char* self)
{
    return 22050;
}

// 0x80257A34
int fn_80257A34(char* self) asm("fn_80257A34");
int fn_80257A34(char* self)
{
    return 1;
}

// 0x80257A3C
int fn_80257A3C(char* self) asm("fn_80257A3C");
int fn_80257A3C(char* self)
{
    return 1;
}

// 0x80257CEC
int fn_80257CEC(char* self) asm("fn_80257CEC");
int fn_80257CEC(char* self)
{
    return 1;
}

// 0x80257E68
int fn_80257E68(char* self) asm("fn_80257E68");
int fn_80257E68(char* self)
{
    return *(int*)(self + 0x8);
}

// 0x80257F50
int fn_80257F50(char* self) asm("fn_80257F50");
int fn_80257F50(char* self)
{
    return 1;
}

// 0x80257F58
int fn_80257F58(char* self) asm("fn_80257F58");
int fn_80257F58(char* self)
{
    return 1;
}

// 0x80257F60
int fn_80257F60(char* self) asm("fn_80257F60");
int fn_80257F60(char* self)
{
    return *(int*)(self + 0x18);
}

// 0x80258104
int fn_80258104(char* self) asm("fn_80258104");
int fn_80258104(char* self)
{
    return 512;
}

// 0x80258190
int fn_80258190(char* self) asm("fn_80258190");
int fn_80258190(char* self)
{
    return 22050;
}

// 0x80258198
int fn_80258198(char* self) asm("fn_80258198");
int fn_80258198(char* self)
{
    return 1;
}

// 0x802581A0
int fn_802581A0(char* self) asm("fn_802581A0");
int fn_802581A0(char* self)
{
    return 1;
}

// 0x802583D8
void fn_802583D8(char* self, int a) asm("fn_802583D8");
void fn_802583D8(char* self, int a)
{
    *(int*)((char*)self + 36) = a;
}

// 0x80258410
int fn_80258410(char* self, int a) asm("fn_80258410");
int fn_80258410(char* self, int a)
{
    *(int*)((char*)self + 56) = a;
    return 1;
}

// 0x802586C8
int fn_802586C8(char* self) asm("fn_802586C8");
int fn_802586C8(char* self)
{
    return 1;
}

// 0x80258F00
void fn_80258F00(char* self) asm("fn_80258F00");
void fn_80258F00(char* self)
{
    fn_8025DB8C((int)*(int*)((char*)self + 92));
}

// 0x802590C0
void fn_802590C0(char* self) asm("fn_802590C0");
void fn_802590C0(char* self)
{
    fn_8025D160((int)(int)lbl_8035D0D0);
}

// 0x802590E8
int fn_802590E8(char* self) asm("fn_802590E8");
int fn_802590E8(char* self)
{
    return 0;
}

// 0x80259EB0
int fn_80259EB0(char* self) asm("fn_80259EB0");
int fn_80259EB0(char* self)
{
    return *(int*)((char*)*(int*)((char*)self + 808) + 16);
}

// 0x80259EBC
int fn_80259EBC(char* self) asm("fn_80259EBC");
int fn_80259EBC(char* self)
{
    return ((int)*(int*)((char*)self + 808) + 8);
}

// 0x8025A0F8
int fn_8025A0F8(char* self) asm("fn_8025A0F8");
int fn_8025A0F8(char* self)
{
    return 1;
}

// 0x8025AB70
void fn_8025AB70(char* self) asm("fn_8025AB70");
void fn_8025AB70(char* self)
{
    fn_8025D0E0((int)((int)self + 24));
}

// 0x8025C4C8
int fn_8025C4C8(char* self) asm("fn_8025C4C8");
int fn_8025C4C8(char* self)
{
    return 1;
}

// 0x8025C4D0
int fn_8025C4D0(char* self) asm("fn_8025C4D0");
int fn_8025C4D0(char* self)
{
    return 1;
}

// 0x8025C4D8
int fn_8025C4D8(char* self) asm("fn_8025C4D8");
int fn_8025C4D8(char* self)
{
    return 1;
}

// 0x8025C4E0
int fn_8025C4E0(char* self) asm("fn_8025C4E0");
int fn_8025C4E0(char* self)
{
    return 1;
}

// 0x8025CA64
int fn_8025CA64(char* self) asm("fn_8025CA64");
int fn_8025CA64(char* self)
{
    *(int*)((char*)self + 208) = ((int)*(int*)((char*)self + 208) + 1);
    return 1;
}

// 0x8025CA7C
int fn_8025CA7C(char* self) asm("fn_8025CA7C");
int fn_8025CA7C(char* self)
{
    *(int*)((char*)self + 208) = ((int)*(int*)((char*)self + 208) + -1);
    return 1;
}

// 0x8025CD18
int fn_8025CD18(char* self) asm("fn_8025CD18");
int fn_8025CD18(char* self)
{
    return 1;
}

// 0x8025D2D8
int fn_8025D2D8(char* self) asm("fn_8025D2D8");
int fn_8025D2D8(char* self)
{
    *(int*)((char*)self + 0) = 0;
    return 1;
}

// 0x8025D34C
int fn_8025D34C(char* self) asm("fn_8025D34C");
int fn_8025D34C(char* self)
{
    *(int*)((char*)self + 0) = 0;
    return 1;
}

// 0x8025D45C
void fn_8025D45C(char* self) asm("fn_8025D45C");
void fn_8025D45C(char* self)
{
    fn_8025DD8C((int)*(int*)((char*)lbl_8037D560 + 92), (int)*(int*)((char*)self + 0), (int)1);
}

// 0x8025D4A4
void fn_8025D4A4(char* self) asm("fn_8025D4A4");
void fn_8025D4A4(char* self)
{
    fn_8025DEB4((int)*(int*)((char*)lbl_8037D560 + 92), (int)*(int*)((char*)self + 0));
}

// 0x8025D4D0
void fn_8025D4D0(char* self, int a) asm("fn_8025D4D0");
void fn_8025D4D0(char* self, int a)
{
    *(int*)((char*)self + 0) = a;
}

// 0x8025ED10
int fn_8025ED10(char* self) asm("fn_8025ED10");
int fn_8025ED10(char* self)
{
    return *(int*)(self + 0x8);
}

// 0x8025ED18
void fn_8025ED18(char* self, int a) asm("fn_8025ED18");
void fn_8025ED18(char* self, int a)
{
    *(int*)((char*)self + 4) = a;
}

// 0x8025ED20
int fn_8025ED20(char* self, int a) asm("fn_8025ED20");
int fn_8025ED20(char* self, int a)
{
    *(int*)((char*)self + 172) = a;
    return 1;
}

// 0x8025ED2C
int fn_8025ED2C(char* self) asm("fn_8025ED2C");
int fn_8025ED2C(char* self)
{
    return *(int*)(self + 0xAC);
}

// 0x8025ED34
int fn_8025ED34(char* self) asm("fn_8025ED34");
int fn_8025ED34(char* self)
{
    return *(int*)(self + 0xC);
}

// 0x8025ED3C
int fn_8025ED3C(char* self) asm("fn_8025ED3C");
int fn_8025ED3C(char* self)
{
    return *(int*)(self + 0x14);
}

// 0x8025ED44
void fn_8025ED44(void* self) asm("fn_8025ED44");
void fn_8025ED44(void* self)
{
}

// 0x8025ED48
int fn_8025ED48(char* self) asm("fn_8025ED48");
int fn_8025ED48(char* self)
{
    return 1;
}

// 0x8025ED50
int fn_8025ED50(char* self) asm("fn_8025ED50");
int fn_8025ED50(char* self)
{
    return 0;
}

// 0x8025ED58
int fn_8025ED58(char* self) asm("fn_8025ED58");
int fn_8025ED58(char* self)
{
    return 0;
}

// 0x8025ED60
char* fn_8025ED60(char* self) asm("fn_8025ED60");
char* fn_8025ED60(char* self)
{
    return self + 0x18;
}

// 0x8025ED68
void fn_8025ED68(char* self) asm("fn_8025ED68");
void fn_8025ED68(char* self)
{
    fn_8025D160((int)((int)self + 24));
}

// 0x8025ED8C
void fn_8025ED8C(char* self) asm("fn_8025ED8C");
void fn_8025ED8C(char* self)
{
    fn_8025D0E0((int)((int)self + 24));
}

// 0x8025EDB0
int fn_8025EDB0(char* self) asm("fn_8025EDB0");
int fn_8025EDB0(char* self)
{
    return 0;
}

// 0x8025EDB8
int fn_8025EDB8(char* self) asm("fn_8025EDB8");
int fn_8025EDB8(char* self)
{
    return 0;
}

// 0x8025EDC0
int fn_8025EDC0(char* self) asm("fn_8025EDC0");
int fn_8025EDC0(char* self)
{
    return 0;
}

// 0x8025EDC8
int fn_8025EDC8(char* self) asm("fn_8025EDC8");
int fn_8025EDC8(char* self)
{
    return 0;
}

// 0x8025EDD0
int fn_8025EDD0(char* self) asm("fn_8025EDD0");
int fn_8025EDD0(char* self)
{
    return 1;
}

// 0x8025EDD8
int fn_8025EDD8(char* self) asm("fn_8025EDD8");
int fn_8025EDD8(char* self)
{
    return 1;
}

// 0x8025EDE0
int fn_8025EDE0(char* self) asm("fn_8025EDE0");
int fn_8025EDE0(char* self)
{
    return 16;
}

// 0x8025EDE8
int fn_8025EDE8(char* self) asm("fn_8025EDE8");
int fn_8025EDE8(char* self)
{
    return 64;
}

// 0x8025EE98
int fn_8025EE98(char* self) asm("fn_8025EE98");
int fn_8025EE98(char* self)
{
    return 1;
}

// 0x8025EEA0
int fn_8025EEA0(char* self) asm("fn_8025EEA0");
int fn_8025EEA0(char* self)
{
    return 1;
}

// 0x8025EEA8
int fn_8025EEA8(char* self) asm("fn_8025EEA8");
int fn_8025EEA8(char* self)
{
    return 1;
}

// 0x8025EEB0
int fn_8025EEB0(char* self) asm("fn_8025EEB0");
int fn_8025EEB0(char* self)
{
    return 1;
}

// 0x8025EEB8
int fn_8025EEB8(char* self) asm("fn_8025EEB8");
int fn_8025EEB8(char* self)
{
    return 1;
}

// 0x8025EEC0
int fn_8025EEC0(char* self) asm("fn_8025EEC0");
int fn_8025EEC0(char* self)
{
    return 1;
}

// 0x8025EEC8
int fn_8025EEC8(char* self) asm("fn_8025EEC8");
int fn_8025EEC8(char* self)
{
    return 1;
}

// 0x8025EED0
int fn_8025EED0(char* self) asm("fn_8025EED0");
int fn_8025EED0(char* self)
{
    return 1;
}

// 0x8025EED8
int fn_8025EED8(char* self) asm("fn_8025EED8");
int fn_8025EED8(char* self)
{
    return 1;
}

// 0x8025EEE0
int fn_8025EEE0(char* self) asm("fn_8025EEE0");
int fn_8025EEE0(char* self)
{
    return 1;
}

// 0x8025EEE8
int fn_8025EEE8(char* self) asm("fn_8025EEE8");
int fn_8025EEE8(char* self)
{
    return 1;
}

// 0x8025EEF0
int fn_8025EEF0(char* self) asm("fn_8025EEF0");
int fn_8025EEF0(char* self)
{
    return 1;
}

// 0x8025EEF8
int fn_8025EEF8(char* self) asm("fn_8025EEF8");
int fn_8025EEF8(char* self)
{
    return 1;
}

// 0x8025EF00
int fn_8025EF00(char* self) asm("fn_8025EF00");
int fn_8025EF00(char* self)
{
    return 1;
}

// 0x8025EF08
int fn_8025EF08(char* self) asm("fn_8025EF08");
int fn_8025EF08(char* self)
{
    return 1;
}

// 0x8025EF10
int fn_8025EF10(char* self) asm("fn_8025EF10");
int fn_8025EF10(char* self)
{
    return 1;
}

// 0x8025EF18
int fn_8025EF18(char* self) asm("fn_8025EF18");
int fn_8025EF18(char* self)
{
    return 1;
}

// 0x8025EF20
int fn_8025EF20(char* self) asm("fn_8025EF20");
int fn_8025EF20(char* self)
{
    return 1;
}

// 0x8025EF48
int fn_8025EF48(char* self) asm("fn_8025EF48");
int fn_8025EF48(char* self)
{
    return 0;
}

// 0x8025EF50
int fn_8025EF50(char* self) asm("fn_8025EF50");
int fn_8025EF50(char* self)
{
    return 1;
}

// 0x8025EF58
int fn_8025EF58(char* self) asm("fn_8025EF58");
int fn_8025EF58(char* self)
{
    return 1;
}

// 0x8025EF60
int fn_8025EF60(char* self) asm("fn_8025EF60");
int fn_8025EF60(char* self)
{
    return 1;
}

// 0x8025EF68
int fn_8025EF68(char* self) asm("fn_8025EF68");
int fn_8025EF68(char* self)
{
    return 1;
}

// 0x8025EF70
int fn_8025EF70(char* self) asm("fn_8025EF70");
int fn_8025EF70(char* self)
{
    return *(int*)(self + 0xE0);
}

// 0x8025EF78
int fn_8025EF78(char* self) asm("fn_8025EF78");
int fn_8025EF78(char* self)
{
    return *(int*)(self + 0xD4);
}

// 0x8025EF80
int fn_8025EF80(void) asm("fn_8025EF80");
int fn_8025EF80(void)
{
    return lbl_8037D560;
}

// 0x8025EF88
int fn_8025EF88(char* self) asm("fn_8025EF88");
int fn_8025EF88(char* self)
{
    return 1;
}

// 0x8025F034
int fn_8025F034(char* self) asm("fn_8025F034");
int fn_8025F034(char* self)
{
    return 1;
}

// 0x8025F03C
int fn_8025F03C(char* self) asm("fn_8025F03C");
int fn_8025F03C(char* self)
{
    return 1;
}

// 0x8025F044
int fn_8025F044(char* self) asm("fn_8025F044");
int fn_8025F044(char* self)
{
    return 1;
}

// 0x8025F04C
int fn_8025F04C(char* self) asm("fn_8025F04C");
int fn_8025F04C(char* self)
{
    return 1;
}

// 0x8025F054
int fn_8025F054(char* self) asm("fn_8025F054");
int fn_8025F054(char* self)
{
    return 1;
}

// 0x8025F05C
int fn_8025F05C(char* self) asm("fn_8025F05C");
int fn_8025F05C(char* self)
{
    return 1;
}

// 0x8025F064
int fn_8025F064(char* self) asm("fn_8025F064");
int fn_8025F064(char* self)
{
    return 0;
}

// 0x8025F06C
int fn_8025F06C(char* self) asm("fn_8025F06C");
int fn_8025F06C(char* self)
{
    return *(int*)(self + 0xB4);
}

// 0x8025F148
int fn_8025F148(char* self) asm("fn_8025F148");
int fn_8025F148(char* self)
{
    return 1;
}

// 0x8025F150
int fn_8025F150(char* self) asm("fn_8025F150");
int fn_8025F150(char* self)
{
    return *(int*)(self + 0x1C0);
}

// 0x8025F170
int fn_8025F170(char* self) asm("fn_8025F170");
int fn_8025F170(char* self)
{
    return 0;
}

// 0x8025F178
int fn_8025F178(char* self) asm("fn_8025F178");
int fn_8025F178(char* self)
{
    return 0;
}

// 0x8025F22C
void fn_8025F22C(char* self) asm("fn_8025F22C");
void fn_8025F22C(char* self)
{
    fn_8025D0E0((int)((int)self + 652));
}

// 0x8025F250
int fn_8025F250(char* self) asm("fn_8025F250");
int fn_8025F250(char* self)
{
    return 1;
}

// 0x8025F258
int fn_8025F258(char* self) asm("fn_8025F258");
int fn_8025F258(char* self)
{
    return *(int*)(self + 0x32C);
}

// 0x8025F260
int fn_8025F260(char* self) asm("fn_8025F260");
int fn_8025F260(char* self)
{
    return *(int*)(self + 0x330);
}

// 0x8025F268
int fn_8025F268(char* self) asm("fn_8025F268");
int fn_8025F268(char* self)
{
    return *(int*)(self + 0x334);
}

// 0x8025F270
int fn_8025F270(char* self) asm("fn_8025F270");
int fn_8025F270(char* self)
{
    return *(int*)(self + 0x338);
}

// 0x8025F278
int fn_8025F278(char* self) asm("fn_8025F278");
int fn_8025F278(char* self)
{
    return *(int*)(self + 0x328);
}

// 0x8025F280
int fn_8025F280(char* self) asm("fn_8025F280");
int fn_8025F280(char* self)
{
    return *(unsigned char*)((char*)self + 844);
}

// 0x8025F288
int fn_8025F288(char* self) asm("fn_8025F288");
int fn_8025F288(char* self)
{
    return *(unsigned char*)((char*)self + 845);
}

// 0x8025F33C
void fn_8025F33C(char* self) asm("fn_8025F33C");
void fn_8025F33C(char* self)
{
    fn_8025D5C0((int)*(int*)((char*)lbl_8037D560 + 92), (int)self);
}

// 0x8025F368
void fn_8025F368(char* self) asm("fn_8025F368");
void fn_8025F368(char* self)
{
    fn_8025EC64((int)1, (int)(0 | 65535));
}

