// Game code at 0x80087A5C-0x800B3AA4: trivial functions (empty virtuals, getters, setters, destructors). Compiled at -O2.
// Each is named by address with an asm label so it keeps the symbol of the original.

extern "C" int fn_8006186C(int, int);
extern "C" int fn_8008818C(int);
extern "C" int fn_8008A2FC(int, int, int);
extern "C" int fn_800914D0(int);
extern "C" int fn_800916B8(int);
extern "C" int fn_800A77A8(int);
extern "C" int fn_800AA4D0(int);
extern "C" int fn_800AF300(int);
extern "C" int fn_800B392C(int, int);
extern "C" int fn_8015B42C(int);
extern "C" int fn_80169EE8(int);
extern "C" int fn_80177628(int, int, int, int);
extern "C" int fn_8018643C(int);
extern "C" int fn_80187438(int, int);
extern "C" int fn_80187538(int, int);
extern "C" int fn_80188754(int);
extern "C" int fn_801887C8(int);
extern "C" int fn_801894D0(int);
extern "C" int fn_801895D4(int);
extern "C" int fn_801E59A4(int);
extern "C" int fn_802316EC(int);
extern "C" void fn_801B8A60(void*);
extern char lbl_80299CD8[];
extern char lbl_802A4998[];
extern char lbl_802A6830[];
extern char lbl_802A92C0[];
extern char lbl_802A987C[];
extern char lbl_802A9910[];
extern char lbl_80340AB8[];
extern int lbl_8037B7C4;
extern int lbl_8037D96C;
extern int lbl_8037D9B4;

// 0x8008AEA0
void fn_8008AEA0(void* self) asm("fn_8008AEA0");
void fn_8008AEA0(void* self)
{
}

// 0x8008AEA4
void fn_8008AEA4(void* self) asm("fn_8008AEA4");
void fn_8008AEA4(void* self)
{
}

// 0x8008AF84
void fn_8008AF84(void* self) asm("fn_8008AF84");
void fn_8008AF84(void* self)
{
}

// 0x8008AF88
void fn_8008AF88(void* self) asm("fn_8008AF88");
void fn_8008AF88(void* self)
{
}

// 0x8008AFE0
void fn_8008AFE0(void* self) asm("fn_8008AFE0");
void fn_8008AFE0(void* self)
{
}

// 0x8008AFE4
void fn_8008AFE4(void* self) asm("fn_8008AFE4");
void fn_8008AFE4(void* self)
{
}

// 0x8008AFE8
void fn_8008AFE8(char* self, int a) asm("fn_8008AFE8");
void fn_8008AFE8(char* self, int a)
{
    fn_8008A2FC((int)self, (int)*(int*)((char*)a + 56), (int)5);
}

// 0x8008B010
void fn_8008B010(char* self, int a) asm("fn_8008B010");
void fn_8008B010(char* self, int a)
{
    fn_8008A2FC((int)self, (int)*(int*)((char*)a + 56), (int)0);
}

// 0x8008B038
void fn_8008B038(char* self) asm("fn_8008B038");
void fn_8008B038(char* self)
{
    *(int*)(self + 0x1F4) = 1;
}

// 0x8008B044
void fn_8008B044(char* self) asm("fn_8008B044");
void fn_8008B044(char* self)
{
    *(int*)(self + 0x1F4) = 1;
}

// 0x8008B050
void fn_8008B050(void* self) asm("fn_8008B050");
void fn_8008B050(void* self)
{
}

// 0x8008B054
void fn_8008B054(void* self) asm("fn_8008B054");
void fn_8008B054(void* self)
{
}

// 0x8008B058
void fn_8008B058(void* self) asm("fn_8008B058");
void fn_8008B058(void* self)
{
}

// 0x8008B05C
void fn_8008B05C(void* self) asm("fn_8008B05C");
void fn_8008B05C(void* self)
{
}

// 0x8008B060
void fn_8008B060(void* self) asm("fn_8008B060");
void fn_8008B060(void* self)
{
}

// 0x8008B064
void fn_8008B064(void* self) asm("fn_8008B064");
void fn_8008B064(void* self)
{
}

// 0x8008B304
void fn_8008B304(void* self) asm("fn_8008B304");
void fn_8008B304(void* self)
{
}

// 0x8008B3FC
void fn_8008B3FC(char* self) asm("fn_8008B3FC");
void fn_8008B3FC(char* self)
{
    fn_800A77A8((int)((int)self + 568));
}

// 0x8008B878
void fn_8008B878(char* self) asm("fn_8008B878");
void fn_8008B878(char* self)
{
    fn_8008818C((int)self);
}

// 0x8008BE6C
void fn_8008BE6C(void* self) asm("fn_8008BE6C");
void fn_8008BE6C(void* self)
{
}

// 0x80090298
void fn_80090298(char* self) asm("fn_80090298");
void fn_80090298(char* self)
{
    fn_80169EE8((int)self);
}

// 0x80090304
void fn_80090304(char* self) asm("fn_80090304");
void fn_80090304(char* self)
{
    *(int*)((char*)self + 68) = (int)lbl_802A4998;
    fn_80188754((int)self);
}

// 0x80090BA8
void fn_80090BA8(char* self) asm("fn_80090BA8");
void fn_80090BA8(char* self)
{
    fn_800914D0((int)self);
}

// 0x800915E0
void fn_800915E0(void* self) asm("fn_800915E0");
void fn_800915E0(void* self)
{
}

// 0x80091C14
void fn_80091C14(char* self) asm("fn_80091C14");
void fn_80091C14(char* self)
{
    *(int*)((char*)self + 52) = *(int*)((char*)self + 16);
    lbl_8037B7C4 = 1;
}

// 0x80091C74
void fn_80091C74(char* self) asm("fn_80091C74");
void fn_80091C74(char* self)
{
    *(int*)((char*)self + 16) = *(int*)((char*)self + 52);
}

// 0x80091D34
void fn_80091D34(char* self) asm("fn_80091D34");
void fn_80091D34(char* self)
{
    fn_802316EC((int)self);
}

// 0x80091D54
void fn_80091D54(char* self) asm("fn_80091D54");
void fn_80091D54(char* self)
{
    fn_800916B8((int)*(int*)((char*)self + 4));
}

// 0x80091D78
int fn_80091D78(char* self) asm("fn_80091D78");
int fn_80091D78(char* self)
{
    return *(int*)(self + 0x8);
}

// 0x80097C68
void fn_80097C68(char* self) asm("fn_80097C68");
void fn_80097C68(char* self)
{
    fn_80187438((int)self, (int)1);
}

// 0x80097C8C
void fn_80097C8C(char* self) asm("fn_80097C8C");
void fn_80097C8C(char* self)
{
    fn_80187538((int)self, (int)1);
}

// 0x80098444
void fn_80098444(void* self) asm("fn_80098444");
void fn_80098444(void* self)
{
}

// 0x8009BB24
void fn_8009BB24(char* self) asm("fn_8009BB24");
void fn_8009BB24(char* self)
{
    fn_80187438((int)self, (int)1);
}

// 0x8009BB48
void fn_8009BB48(char* self) asm("fn_8009BB48");
void fn_8009BB48(char* self)
{
    fn_80187538((int)self, (int)1);
}

// 0x8009C9EC
void fn_8009C9EC(char* self) asm("fn_8009C9EC");
void fn_8009C9EC(char* self)
{
    *(int*)((char*)self + 68) = (int)lbl_802A6830;
    fn_8018643C((int)self);
}

// 0x8009CE68
void fn_8009CE68(char* self) asm("fn_8009CE68");
void fn_8009CE68(char* self)
{
    fn_801894D0((int)self);
}

// 0x8009CE88
void fn_8009CE88(char* self) asm("fn_8009CE88");
void fn_8009CE88(char* self)
{
    fn_801895D4((int)self);
}

// 0x800A04EC
void fn_800A04EC(char* self) asm("fn_800A04EC");
void fn_800A04EC(char* self)
{
    fn_8006186C((int)lbl_8037D96C, (int)939794847);
}

// 0x800A2910
void fn_800A2910(char* self, int a) asm("fn_800A2910");
void fn_800A2910(char* self, int a)
{
    *(int*)((char*)self + 6504) = a;
}

// 0x800AA4B0
void fn_800AA4B0(char* self) asm("fn_800AA4B0");
void fn_800AA4B0(char* self)
{
    fn_800AA4D0((int)self);
}

// 0x800AAA68
void fn_800AAA68(char* self) asm("fn_800AAA68");
void fn_800AAA68(char* self)
{
    fn_801887C8((int)self);
}

// 0x800AB234
void fn_800AB234(void* self) asm("fn_800AB234");
void fn_800AB234(void* self)
{
}

// 0x800AB798
void fn_800AB798(void* self) asm("fn_800AB798");
void fn_800AB798(void* self)
{
}

// 0x800AC570
void fn_800AC570(void* self) asm("fn_800AC570");
void fn_800AC570(void* self)
{
}

// 0x800AC574
void fn_800AC574(char* self) asm("fn_800AC574");
void fn_800AC574(char* self)
{
    *(int*)(self + 0x30) = 1;
}

// 0x800AD1B8
void fn_800AD1B8(void* self) asm("fn_800AD1B8");
void fn_800AD1B8(void* self)
{
}

// 0x800AD648
int fn_800AD648(char* self) asm("fn_800AD648");
int fn_800AD648(char* self)
{
    return 1;
}

// 0x800AD650
int fn_800AD650(char* self) asm("fn_800AD650");
int fn_800AD650(char* self)
{
    return 0;
}

// 0x800AD658
int fn_800AD658(char* self) asm("fn_800AD658");
int fn_800AD658(char* self)
{
    return 1;
}

// 0x800AD660
void fn_800AD660(void* self) asm("fn_800AD660");
void fn_800AD660(void* self)
{
}

// 0x800AD664
void fn_800AD664(void* self) asm("fn_800AD664");
void fn_800AD664(void* self)
{
}

// 0x800AD668
void fn_800AD668(void* self) asm("fn_800AD668");
void fn_800AD668(void* self)
{
}

// 0x800AD66C
void fn_800AD66C(void* self) asm("fn_800AD66C");
void fn_800AD66C(void* self)
{
}

// 0x800ADD0C
void fn_800ADD0C(void* self) asm("fn_800ADD0C");
void fn_800ADD0C(void* self)
{
}

// 0x800ADD10
void fn_800ADD10(void* self) asm("fn_800ADD10");
void fn_800ADD10(void* self)
{
}

// 0x800AFF50
void fn_800AFF50(char* self) asm("fn_800AFF50");
void fn_800AFF50(char* self)
{
    fn_8015B42C((int)((int)*(int*)((char*)self + 8) + 848));
}

// 0x800B0ABC
void fn_800B0ABC(char* self) asm("fn_800B0ABC");
void fn_800B0ABC(char* self)
{
    fn_800AF300((int)self);
}

// 0x800B1084
void fn_800B1084(void* self) asm("fn_800B1084");
void fn_800B1084(void* self)
{
}

// 0x800B1958
int fn_800B1958(char* self) asm("fn_800B1958");
int fn_800B1958(char* self)
{
    return 1;
}

// 0x800B2C9C
void fn_800B2C9C(char* self, int a) asm("fn_800B2C9C");
void fn_800B2C9C(char* self, int a)
{
    *(int*)((char*)self + 172) = a;
}

// 0x800B2CA4
void fn_800B2CA4(char* self, int a) asm("fn_800B2CA4");
void fn_800B2CA4(char* self, int a)
{
    *(int*)((char*)self + 176) = a;
}

// 0x800B2E44
void fn_800B2E44(char* self, int flag) asm("fn_800B2E44");
void fn_800B2E44(char* self, int flag)
{
    *(char**)(self + 0) = lbl_802A92C0;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x800B3730
int fn_800B3730(char* self) asm("fn_800B3730");
int fn_800B3730(char* self)
{
    return (int)lbl_802A987C;
}

// 0x800B3978
void fn_800B3978(char* self) asm("fn_800B3978");
void fn_800B3978(char* self)
{
    *(int*)((char*)self + 28) = (int)lbl_802A9910;
    fn_801E59A4((int)self);
}

// 0x800B39A8
void fn_800B39A8(char* self, int flag) asm("fn_800B39A8");
void fn_800B39A8(char* self, int flag)
{
    *(char**)(self + 0) = lbl_80299CD8;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x800B39DC
void fn_800B39DC(char* self, int flag) asm("fn_800B39DC");
void fn_800B39DC(char* self, int flag)
{
    *(char**)(self + 0) = lbl_80299CD8;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x800B3A10
void fn_800B3A10(char* self, int flag) asm("fn_800B3A10");
void fn_800B3A10(char* self, int flag)
{
    *(char**)(self + 0) = lbl_80299CD8;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x800B3A44
void fn_800B3A44(char* self, int flag) asm("fn_800B3A44");
void fn_800B3A44(char* self, int flag)
{
    *(char**)(self + 0) = lbl_80299CD8;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x800B3A78
void fn_800B3A78(char* self) asm("fn_800B3A78");
void fn_800B3A78(char* self)
{
    fn_800B392C((int)1, (int)(0 | 65535));
}

