// Game code at 0x8022A578-0x80231A18: trivial functions (empty virtuals, getters, setters, destructors). Compiled at -O2.
// Each is named by address with an asm label so it keeps the symbol of the original.

extern "C" int fn_801D2BD8(int);
extern "C" int fn_802306D0(int);
extern "C" int fn_80231730(int, int);
extern "C" int fn_8023C304(int, int, int);
extern "C" void fn_801B8A60(void*);
extern char lbl_802CDF38[];
extern char lbl_802CDF80[];

// 0x8022A5D8
void fn_8022A5D8(char* self) asm("fn_8022A5D8");
void fn_8022A5D8(char* self)
{
    *(int*)(self + 0x8) = 0;
}

// 0x8022D554
void fn_8022D554(char* self) asm("fn_8022D554");
void fn_8022D554(char* self)
{
    fn_801D2BD8((int)*(int*)((char*)self + 0));
}

// 0x8022DE0C
int fn_8022DE0C(char* self) asm("fn_8022DE0C");
int fn_8022DE0C(char* self)
{
    return 1146048338;
}

// 0x8022F850
void fn_8022F850(void* self) asm("fn_8022F850");
void fn_8022F850(void* self)
{
}

// 0x8022F960
void fn_8022F960(char* self, int flag) asm("fn_8022F960");
void fn_8022F960(char* self, int flag)
{
    *(char**)(self + 0) = lbl_802CDF80;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x8022FA94
void fn_8022FA94(char* self, int flag) asm("fn_8022FA94");
void fn_8022FA94(char* self, int flag)
{
    *(char**)(self + 0) = lbl_802CDF80;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x8022FAC8
int fn_8022FAC8(char* self) asm("fn_8022FAC8");
int fn_8022FAC8(char* self)
{
    return *(short*)((char*)*(int*)((char*)self + 8) + 4);
}

// 0x8022FAD4
int fn_8022FAD4(char* self) asm("fn_8022FAD4");
int fn_8022FAD4(char* self)
{
    return *(int*)(self + 0x4);
}

// 0x8022FAFC
int fn_8022FAFC(char* self) asm("fn_8022FAFC");
int fn_8022FAFC(char* self)
{
    return 0;
}

// 0x8022FBA4
int fn_8022FBA4(char* self) asm("fn_8022FBA4");
int fn_8022FBA4(char* self)
{
    return -95;
}

// 0x8022FBAC
int fn_8022FBAC(char* self) asm("fn_8022FBAC");
int fn_8022FBAC(char* self)
{
    return -95;
}

// 0x8022FBF4
int fn_8022FBF4(char* self) asm("fn_8022FBF4");
int fn_8022FBF4(char* self)
{
    return 0;
}

// 0x8022FBFC
int fn_8022FBFC(char* self) asm("fn_8022FBFC");
int fn_8022FBFC(char* self)
{
    return 0;
}

// 0x8022FC04
int fn_8022FC04(char* self) asm("fn_8022FC04");
int fn_8022FC04(char* self)
{
    return 0;
}

// 0x8022FC0C
void fn_8022FC0C(void* self) asm("fn_8022FC0C");
void fn_8022FC0C(void* self)
{
}

// 0x8022FC10
int fn_8022FC10(char* self) asm("fn_8022FC10");
int fn_8022FC10(char* self)
{
    return 0;
}

// 0x8022FCD0
int fn_8022FCD0(char* self) asm("fn_8022FCD0");
int fn_8022FCD0(char* self)
{
    return 0;
}

// 0x8022FCD8
int fn_8022FCD8(char* self) asm("fn_8022FCD8");
int fn_8022FCD8(char* self)
{
    return 0;
}

// 0x8022FCE0
int fn_8022FCE0(char* self) asm("fn_8022FCE0");
int fn_8022FCE0(char* self)
{
    return 0;
}

// 0x8022FCE8
int fn_8022FCE8(char* self) asm("fn_8022FCE8");
int fn_8022FCE8(char* self)
{
    return 0;
}

// 0x8022FCF0
int fn_8022FCF0(char* self) asm("fn_8022FCF0");
int fn_8022FCF0(char* self)
{
    return 0;
}

// 0x8022FCF8
int fn_8022FCF8(char* self) asm("fn_8022FCF8");
int fn_8022FCF8(char* self)
{
    return 0;
}

// 0x8022FD00
int fn_8022FD00(char* self) asm("fn_8022FD00");
int fn_8022FD00(char* self)
{
    return 0;
}

// 0x8022FD08
void fn_8022FD08(char* self, int a, int b) asm("fn_8022FD08");
void fn_8022FD08(char* self, int a, int b)
{
    fn_8023C304((int)b, (int)a, (int)b);
}

// 0x8022FD2C
int fn_8022FD2C(char* self) asm("fn_8022FD2C");
int fn_8022FD2C(char* self)
{
    return 0;
}

// 0x8022FD4C
int fn_8022FD4C(char* self) asm("fn_8022FD4C");
int fn_8022FD4C(char* self)
{
    return 0;
}

// 0x8022FD54
void fn_8022FD54(char* self, int a, int b) asm("fn_8022FD54");
void fn_8022FD54(char* self, int a, int b)
{
    fn_8023C304((int)b, (int)a, (int)b);
}

// 0x8022FD78
int fn_8022FD78(char* self) asm("fn_8022FD78");
int fn_8022FD78(char* self)
{
    return 0;
}

// 0x8022FD80
void fn_8022FD80(void* self) asm("fn_8022FD80");
void fn_8022FD80(void* self)
{
}

// 0x8022FD84
void fn_8022FD84(void* self) asm("fn_8022FD84");
void fn_8022FD84(void* self)
{
}

// 0x8022FD88
int fn_8022FD88(char* self) asm("fn_8022FD88");
int fn_8022FD88(char* self)
{
    return 0;
}

// 0x8022FD90
void fn_8022FD90(void* self) asm("fn_8022FD90");
void fn_8022FD90(void* self)
{
}

// 0x8022FD94
void fn_8022FD94(void* self) asm("fn_8022FD94");
void fn_8022FD94(void* self)
{
}

// 0x8022FD98
void fn_8022FD98(void* self) asm("fn_8022FD98");
void fn_8022FD98(void* self)
{
}

// 0x8022FD9C
void fn_8022FD9C(void* self) asm("fn_8022FD9C");
void fn_8022FD9C(void* self)
{
}

// 0x8022FDA0
void fn_8022FDA0(void* self) asm("fn_8022FDA0");
void fn_8022FDA0(void* self)
{
}

// 0x8022FDA4
void fn_8022FDA4(void* self) asm("fn_8022FDA4");
void fn_8022FDA4(void* self)
{
}

// 0x8022FFEC
void fn_8022FFEC(char* self) asm("fn_8022FFEC");
void fn_8022FFEC(char* self)
{
    *(int*)(self + 0x18) = 1;
}

// 0x80230370
void fn_80230370(char* self) asm("fn_80230370");
void fn_80230370(char* self)
{
    *(int*)(self + 0x28) = 0;
}

// 0x802306B0
void fn_802306B0(char* self) asm("fn_802306B0");
void fn_802306B0(char* self)
{
    fn_802306D0((int)self);
}

// 0x80231720
void fn_80231720(void* self) asm("fn_80231720");
void fn_80231720(void* self)
{
}

// 0x80231724
int fn_80231724(char* self) asm("fn_80231724");
int fn_80231724(char* self)
{
    return 1382248302;
}

// 0x802319EC
void fn_802319EC(char* self) asm("fn_802319EC");
void fn_802319EC(char* self)
{
    fn_80231730((int)1, (int)(0 | 65535));
}

