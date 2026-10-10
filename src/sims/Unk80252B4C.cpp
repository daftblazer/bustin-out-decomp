// Game code at 0x80252B4C-0x8025F394: trivial functions (empty virtuals, getters, setters, destructors). Compiled at -O2.
// Each is named by address with an asm label so it keeps the symbol of the original.

extern "C" void fn_801B8A60(void*);
extern char lbl_802D02C8[];
extern int lbl_8037D560;
// 0x80252F90
void fn_80252F90(char* self, int flag) asm("fn_80252F90");
void fn_80252F90(char* self, int flag)
{
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x80253A58
int fn_80253A58(char* self) asm("fn_80253A58");
int fn_80253A58(char* self)
{
    return *(int*)(self + 0xC);
}

// 0x80255FB4
void fn_80255FB4(char* self, int a) asm("fn_80255FB4");
void fn_80255FB4(char* self, int a)
{
    *(int*)(self + 0x0) = a;
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

// 0x80257E68
int fn_80257E68(char* self) asm("fn_80257E68");
int fn_80257E68(char* self)
{
    return *(int*)(self + 0x8);
}

// 0x80257F60
int fn_80257F60(char* self) asm("fn_80257F60");
int fn_80257F60(char* self)
{
    return *(int*)(self + 0x18);
}

// 0x802583D8
void fn_802583D8(char* self, int a) asm("fn_802583D8");
void fn_802583D8(char* self, int a)
{
    *(int*)(self + 0x24) = a;
}

// 0x8025D4D0
void fn_8025D4D0(char* self, int a) asm("fn_8025D4D0");
void fn_8025D4D0(char* self, int a)
{
    *(int*)(self + 0x0) = a;
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
    *(int*)(self + 0x4) = a;
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

// 0x8025ED60
char* fn_8025ED60(char* self) asm("fn_8025ED60");
char* fn_8025ED60(char* self)
{
    return self + 0x18;
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

// 0x8025F06C
int fn_8025F06C(char* self) asm("fn_8025F06C");
int fn_8025F06C(char* self)
{
    return *(int*)(self + 0xB4);
}

// 0x8025F150
int fn_8025F150(char* self) asm("fn_8025F150");
int fn_8025F150(char* self)
{
    return *(int*)(self + 0x1C0);
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

