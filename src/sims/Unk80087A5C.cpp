// Game code at 0x80087A5C-0x800B3AA4: trivial functions (empty virtuals, getters, setters, destructors). Compiled at -O2.
// Each is named by address with an asm label so it keeps the symbol of the original.

extern "C" void fn_801B8A60(void*);
extern char lbl_80299CD8[];
extern char lbl_802A92C0[];
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

// 0x8008BE6C
void fn_8008BE6C(void* self) asm("fn_8008BE6C");
void fn_8008BE6C(void* self)
{
}

// 0x800915E0
void fn_800915E0(void* self) asm("fn_800915E0");
void fn_800915E0(void* self)
{
}

// 0x80091D78
int fn_80091D78(char* self) asm("fn_80091D78");
int fn_80091D78(char* self)
{
    return *(int*)(self + 0x8);
}

// 0x80098444
void fn_80098444(void* self) asm("fn_80098444");
void fn_80098444(void* self)
{
}

// 0x800A2910
void fn_800A2910(char* self, int a) asm("fn_800A2910");
void fn_800A2910(char* self, int a)
{
    *(int*)(self + 0x1968) = a;
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

// 0x800B1084
void fn_800B1084(void* self) asm("fn_800B1084");
void fn_800B1084(void* self)
{
}

// 0x800B2C9C
void fn_800B2C9C(char* self, int a) asm("fn_800B2C9C");
void fn_800B2C9C(char* self, int a)
{
    *(int*)(self + 0xAC) = a;
}

// 0x800B2CA4
void fn_800B2CA4(char* self, int a) asm("fn_800B2CA4");
void fn_800B2CA4(char* self, int a)
{
    *(int*)(self + 0xB0) = a;
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

