// Game code at 0x801E58D4-0x801F6614: trivial functions (empty virtuals, getters, setters, destructors). Compiled at -O2.
// Each is named by address with an asm label so it keeps the symbol of the original.

extern "C" void fn_801B8A60(void*);
extern char lbl_802C9648[];
extern int lbl_8037C478;
extern int lbl_8037C4AC;
extern int lbl_8037C4B0;
// 0x801E5EC4
void fn_801E5EC4(void) asm("fn_801E5EC4");
void fn_801E5EC4(void)
{
    lbl_8037C478 = 0;
}

// 0x801E62EC
void fn_801E62EC(char* self, int a) asm("fn_801E62EC");
void fn_801E62EC(char* self, int a)
{
    *(int*)(self + 0x4) = a;
}

// 0x801E62F4
int fn_801E62F4(char* self) asm("fn_801E62F4");
int fn_801E62F4(char* self)
{
    return *(int*)(self + 0x4);
}

// 0x801E62FC
void fn_801E62FC(char* self, int a) asm("fn_801E62FC");
void fn_801E62FC(char* self, int a)
{
    *(short*)(self + 0xC) = a;
}

// 0x801E6420
void fn_801E6420(void* self) asm("fn_801E6420");
void fn_801E6420(void* self)
{
}

// 0x801E70D8
void fn_801E70D8(void* self) asm("fn_801E70D8");
void fn_801E70D8(void* self)
{
}

// 0x801E722C
void fn_801E722C(void* self) asm("fn_801E722C");
void fn_801E722C(void* self)
{
}

// 0x801E7254
void fn_801E7254(void* self) asm("fn_801E7254");
void fn_801E7254(void* self)
{
}

// 0x801E7258
void fn_801E7258(void* self) asm("fn_801E7258");
void fn_801E7258(void* self)
{
}

// 0x801E7264
void fn_801E7264(void* self) asm("fn_801E7264");
void fn_801E7264(void* self)
{
}

// 0x801E7268
void fn_801E7268(void* self) asm("fn_801E7268");
void fn_801E7268(void* self)
{
}

// 0x801E7274
void fn_801E7274(void* self) asm("fn_801E7274");
void fn_801E7274(void* self)
{
}

// 0x801E7448
void fn_801E7448(void* self) asm("fn_801E7448");
void fn_801E7448(void* self)
{
}

// 0x801E744C
void fn_801E744C(void* self) asm("fn_801E744C");
void fn_801E744C(void* self)
{
}

// 0x801E7450
void fn_801E7450(void* self) asm("fn_801E7450");
void fn_801E7450(void* self)
{
}

// 0x801EBAE8
int fn_801EBAE8(void) asm("fn_801EBAE8");
int fn_801EBAE8(void)
{
    return lbl_8037C4AC;
}

// 0x801EBAF0
int fn_801EBAF0(void) asm("fn_801EBAF0");
int fn_801EBAF0(void)
{
    return lbl_8037C4B0;
}

// 0x801ED490
void fn_801ED490(void* self) asm("fn_801ED490");
void fn_801ED490(void* self)
{
}

// 0x801EF000
void fn_801EF000(char* self) asm("fn_801EF000");
void fn_801EF000(char* self)
{
    *(int*)(self + 0x0) = 0;
}

// 0x801F07CC
int fn_801F07CC(char* self) asm("fn_801F07CC");
int fn_801F07CC(char* self)
{
    return *(int*)(self + 0x110);
}

// 0x801F119C
void fn_801F119C(void* self) asm("fn_801F119C");
void fn_801F119C(void* self)
{
}

// 0x801F2E9C
void fn_801F2E9C(void* self) asm("fn_801F2E9C");
void fn_801F2E9C(void* self)
{
}

// 0x801F44A0
int fn_801F44A0(char* self) asm("fn_801F44A0");
int fn_801F44A0(char* self)
{
    return *(int*)(self + 0xE0);
}

// 0x801F44A8
void fn_801F44A8(char* self, int a) asm("fn_801F44A8");
void fn_801F44A8(char* self, int a)
{
    *(int*)(self + 0xE0) = a;
}

// 0x801F56C8
void fn_801F56C8(char* self) asm("fn_801F56C8");
void fn_801F56C8(char* self)
{
    *(int*)(self + 0x130) = 0;
}

// 0x801F5820
void fn_801F5820(char* self, int flag) asm("fn_801F5820");
void fn_801F5820(char* self, int flag)
{
    *(char**)(self + 0x10) = lbl_802C9648;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x801F5854
void fn_801F5854(char* self, int flag) asm("fn_801F5854");
void fn_801F5854(char* self, int flag)
{
    *(char**)(self + 0x10) = lbl_802C9648;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x801F58F0
int fn_801F58F0(char* self) asm("fn_801F58F0");
int fn_801F58F0(char* self)
{
    return *(int*)(self + 0xC);
}

// 0x801F58F8
void fn_801F58F8(void* self) asm("fn_801F58F8");
void fn_801F58F8(void* self)
{
}

// 0x801F5934
int fn_801F5934(char* self) asm("fn_801F5934");
int fn_801F5934(char* self)
{
    return *(int*)(self + 0x120);
}

// 0x801F5CFC
void fn_801F5CFC(void* self) asm("fn_801F5CFC");
void fn_801F5CFC(void* self)
{
}

// 0x801F5F44
char* fn_801F5F44(char* self) asm("fn_801F5F44");
char* fn_801F5F44(char* self)
{
    return self + 0xD0;
}

// 0x801F5F7C
int fn_801F5F7C(char* self) asm("fn_801F5F7C");
int fn_801F5F7C(char* self)
{
    return *(int*)(self + 0xB8);
}

// 0x801F60D0
int fn_801F60D0(char* self) asm("fn_801F60D0");
int fn_801F60D0(char* self)
{
    return *(int*)(self + 0xE8);
}

// 0x801F6220
char* fn_801F6220(char* self) asm("fn_801F6220");
char* fn_801F6220(char* self)
{
    return self + 0xC8;
}

// 0x801F624C
int fn_801F624C(char* self) asm("fn_801F624C");
int fn_801F624C(char* self)
{
    return *(int*)(self + 0xEC);
}

// 0x801F6254
int fn_801F6254(char* self) asm("fn_801F6254");
int fn_801F6254(char* self)
{
    return *(int*)(self + 0xEC);
}

// 0x801F62C8
int fn_801F62C8(char* self) asm("fn_801F62C8");
int fn_801F62C8(char* self)
{
    return *(int*)(self + 0xC0);
}

// 0x801F65DC
void fn_801F65DC(void* self) asm("fn_801F65DC");
void fn_801F65DC(void* self)
{
}

