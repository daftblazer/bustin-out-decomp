// Game code at 0x800F8F20-0x80105FBC: trivial functions (empty virtuals, getters, setters, destructors). Compiled at -O2.
// Each is named by address with an asm label so it keeps the symbol of the original.

extern "C" int fn_800657F0(int);
extern "C" int fn_8006583C(int);
extern "C" int fn_800F832C(int);
extern "C" int fn_800F8588(int);
extern "C" int fn_800F87A0(int);
extern "C" int fn_800F87FC(int);
extern "C" int fn_800FD09C(int);
extern "C" int fn_800FD0E8(int);
extern "C" int fn_800FD120(int);
extern "C" int fn_800FD6B4(int);
extern "C" int fn_800FD860(int);
extern "C" int fn_800FD8F0(int, int);
extern "C" int fn_80102EA0(int);
extern "C" int fn_80102F94(int);
extern "C" int fn_80105F08(int, int);
extern "C" int fn_80108A40(int);
extern "C" int fn_80108AF4(int);
extern "C" int fn_80108CE4(int);
extern "C" int fn_801B8A3C(int);
extern "C" int fn_80255D00(int);
extern "C" int fn_80255D88(int);
extern "C" void fn_801B8A60(void*);
extern char lbl_802A3900[];
extern char lbl_802E6700[];
extern char lbl_802F7658[];
extern char lbl_80331130[];
extern int lbl_8037BAE0;
extern int lbl_8037BAF8;
extern int lbl_8037BAFC;
extern int lbl_8037BB00;
extern int lbl_8037BB04;
extern int lbl_8037BB08;
extern int lbl_8037CE0C;
extern int lbl_8037D93C;
extern int lbl_8037D940;
extern int lbl_8037D9B8;

// 0x800F8F20
void fn_800F8F20(void* self) asm("fn_800F8F20");
void fn_800F8F20(void* self)
{
}

// 0x800F8F64
void fn_800F8F64(void* self) asm("fn_800F8F64");
void fn_800F8F64(void* self)
{
}

// 0x800F9224
void fn_800F9224(char* self) asm("fn_800F9224");
void fn_800F9224(char* self)
{
    *(int*)((char*)self + 24) = 0;
    fn_800F87A0((int)(int)lbl_802F7658);
}

// 0x800F92B4
void fn_800F92B4(char* self) asm("fn_800F92B4");
void fn_800F92B4(char* self)
{
    *(int*)(self + 0x18) = 0;
}

// 0x800F9398
void fn_800F9398(void* self) asm("fn_800F9398");
void fn_800F9398(void* self)
{
}

// 0x800F9420
void fn_800F9420(char* self) asm("fn_800F9420");
void fn_800F9420(char* self)
{
    fn_80255D00((int)lbl_8037D940);
}

// 0x800F9444
void fn_800F9444(char* self) asm("fn_800F9444");
void fn_800F9444(char* self)
{
    fn_80255D88((int)lbl_8037D940);
}

// 0x800F9468
void fn_800F9468(char* self, int flag) asm("fn_800F9468");
void fn_800F9468(char* self, int flag)
{
    *(char**)(self + 0x10) = lbl_802A3900;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x800F949C
void fn_800F949C(char* self, int flag) asm("fn_800F949C");
void fn_800F949C(char* self, int flag)
{
    *(char**)(self + 0x10) = lbl_802A3900;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x800F94D0
void fn_800F94D0(char* self, int flag) asm("fn_800F94D0");
void fn_800F94D0(char* self, int flag)
{
    *(char**)(self + 0x10) = lbl_802A3900;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x800FBBC0
int fn_800FBBC0(char* self) asm("fn_800FBBC0");
int fn_800FBBC0(char* self)
{
    return *(int*)(self + 0xA8);
}

// 0x800FC838
void fn_800FC838(char* self, int flag) asm("fn_800FC838");
void fn_800FC838(char* self, int flag)
{
    *(char**)(self + 0x10) = lbl_802A3900;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x800FC8E4
void fn_800FC8E4(char* self) asm("fn_800FC8E4");
void fn_800FC8E4(char* self)
{
    fn_800F8588((int)(int)lbl_802F7658);
}

// 0x800FC90C
void fn_800FC90C(char* self, int flag) asm("fn_800FC90C");
void fn_800FC90C(char* self, int flag)
{
    *(char**)(self + 0x10) = lbl_802A3900;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x800FCABC
void fn_800FCABC(char* self, int flag) asm("fn_800FCABC");
void fn_800FCABC(char* self, int flag)
{
    *(char**)(self + 0x10) = lbl_802A3900;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x800FCAF0
void fn_800FCAF0(char* self) asm("fn_800FCAF0");
void fn_800FCAF0(char* self)
{
    fn_800F87A0((int)(int)lbl_802F7658);
}

// 0x800FCB18
void fn_800FCB18(char* self) asm("fn_800FCB18");
void fn_800FCB18(char* self)
{
    fn_800F87FC((int)(int)lbl_802F7658);
}

// 0x800FCCB0
void fn_800FCCB0(char* self, int flag) asm("fn_800FCCB0");
void fn_800FCCB0(char* self, int flag)
{
    *(char**)(self + 0x10) = lbl_802A3900;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x800FCCE4
void fn_800FCCE4(char* self) asm("fn_800FCCE4");
void fn_800FCCE4(char* self)
{
    *(int*)(self + 0x14) = 0;
}

// 0x800FCE30
void fn_800FCE30(char* self) asm("fn_800FCE30");
void fn_800FCE30(char* self)
{
    fn_800F8588((int)(int)lbl_802F7658);
}

// 0x800FCE58
void fn_800FCE58(char* self) asm("fn_800FCE58");
void fn_800FCE58(char* self)
{
    fn_800FD09C((int)*(int*)((char*)self + 4));
}

// 0x800FCE7C
void fn_800FCE7C(char* self) asm("fn_800FCE7C");
void fn_800FCE7C(char* self)
{
    fn_800FD0E8((int)*(int*)((char*)self + 4));
}

// 0x800FCEA0
void fn_800FCEA0(char* self) asm("fn_800FCEA0");
void fn_800FCEA0(char* self)
{
    fn_800FD120((int)*(int*)((char*)self + 4));
}

// 0x800FCEC4
int fn_800FCEC4(char* self) asm("fn_800FCEC4");
int fn_800FCEC4(char* self)
{
    return *(int*)((char*)*(int*)((char*)self + 4) + 136);
}

// 0x800FCED0
void fn_800FCED0(char* self) asm("fn_800FCED0");
void fn_800FCED0(char* self)
{
    *(int*)((char*)*(int*)((char*)self + 4) + 136) = 0;
}

// 0x800FD120
void fn_800FD120(char* self, int a) asm("fn_800FD120");
void fn_800FD120(char* self, int a)
{
    *(int*)((char*)self + 132) = a;
    *(int*)((char*)self + 128) = 1;
}

// 0x800FD130
int fn_800FD130(char* self) asm("fn_800FD130");
int fn_800FD130(char* self)
{
    return *(int*)((char*)*(int*)((char*)self + 52) + 0);
}

// 0x800FD354
float fn_800FD354(char* self) asm("fn_800FD354");
float fn_800FD354(char* self)
{
    return *(float*)(self + 0x48);
}

// 0x800FD8CC
void UpdateMachines__19StateMachineManagerf(char* self) asm("UpdateMachines__19StateMachineManagerf");
void UpdateMachines__19StateMachineManagerf(char* self)
{
    fn_800FD860((int)lbl_8037D93C);
}

// 0x800FD954
void DrawMachines__19StateMachineManagerP3ERC(char* self) asm("DrawMachines__19StateMachineManagerP3ERC");
void DrawMachines__19StateMachineManagerP3ERC(char* self)
{
    fn_800FD8F0((int)lbl_8037D93C, (int)self);
}

// 0x800FDCD4
void fn_800FDCD4(void* self) asm("fn_800FDCD4");
void fn_800FDCD4(void* self)
{
}

// 0x800FDCD8
void fn_800FDCD8(char* self) asm("fn_800FDCD8");
void fn_800FDCD8(char* self)
{
    fn_800FD6B4((int)((int)self + 52));
}

// 0x800FDCFC
void fn_800FDCFC(void* self) asm("fn_800FDCFC");
void fn_800FDCFC(void* self)
{
}

// 0x800FE598
void fn_800FE598(char* self) asm("fn_800FE598");
void fn_800FE598(char* self)
{
    fn_800F832C((int)(int)lbl_802F7658);
}

// 0x800FE770
void fn_800FE770(char* self) asm("fn_800FE770");
void fn_800FE770(char* self)
{
    fn_800F8588((int)(int)lbl_802F7658);
}

// 0x800FF06C
void fn_800FF06C(char* self) asm("fn_800FF06C");
void fn_800FF06C(char* self)
{
    fn_800F87FC((int)(int)lbl_802F7658);
}

// 0x800FF7E4
void fn_800FF7E4(char* self) asm("fn_800FF7E4");
void fn_800FF7E4(char* self)
{
    fn_800F87FC((int)(int)lbl_802F7658);
}

// 0x800FFE64
void fn_800FFE64(char* self) asm("fn_800FFE64");
void fn_800FFE64(char* self)
{
    fn_80102F94((int)*(int*)((char*)self + 4));
}

// 0x801003F8
void fn_801003F8(void* self) asm("fn_801003F8");
void fn_801003F8(void* self)
{
}

// 0x801030A8
void fn_801030A8(void* self) asm("fn_801030A8");
void fn_801030A8(void* self)
{
}

// 0x801030AC
void fn_801030AC(void* self) asm("fn_801030AC");
void fn_801030AC(void* self)
{
}

// 0x801030B0
void fn_801030B0(void* self) asm("fn_801030B0");
void fn_801030B0(void* self)
{
}

// 0x801030B4
void fn_801030B4(void* self) asm("fn_801030B4");
void fn_801030B4(void* self)
{
}

// 0x80103148
void fn_80103148(char* self, int flag) asm("fn_80103148");
void fn_80103148(char* self, int flag)
{
    *(char**)(self + 0x10) = lbl_802A3900;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x8010317C
void fn_8010317C(char* self, int flag) asm("fn_8010317C");
void fn_8010317C(char* self, int flag)
{
    *(char**)(self + 0x10) = lbl_802A3900;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x801031B0
void fn_801031B0(char* self, int flag) asm("fn_801031B0");
void fn_801031B0(char* self, int flag)
{
    *(char**)(self + 0x10) = lbl_802A3900;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x801031E4
void fn_801031E4(char* self, int flag) asm("fn_801031E4");
void fn_801031E4(char* self, int flag)
{
    *(char**)(self + 0x10) = lbl_802A3900;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x80103218
void fn_80103218(char* self, int flag) asm("fn_80103218");
void fn_80103218(char* self, int flag)
{
    *(char**)(self + 0x10) = lbl_802A3900;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x8010324C
void fn_8010324C(char* self, int flag) asm("fn_8010324C");
void fn_8010324C(char* self, int flag)
{
    *(char**)(self + 0x10) = lbl_802A3900;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x80103280
void fn_80103280(char* self, int flag) asm("fn_80103280");
void fn_80103280(char* self, int flag)
{
    *(char**)(self + 0x10) = lbl_802A3900;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x801032B4
void fn_801032B4(char* self, int flag) asm("fn_801032B4");
void fn_801032B4(char* self, int flag)
{
    *(char**)(self + 0x10) = lbl_802A3900;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x801032E8
void fn_801032E8(char* self, int flag) asm("fn_801032E8");
void fn_801032E8(char* self, int flag)
{
    *(char**)(self + 0x10) = lbl_802A3900;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x8010331C
void fn_8010331C(char* self, int flag) asm("fn_8010331C");
void fn_8010331C(char* self, int flag)
{
    *(char**)(self + 0x10) = lbl_802A3900;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x80103350
void fn_80103350(char* self, int flag) asm("fn_80103350");
void fn_80103350(char* self, int flag)
{
    *(char**)(self + 0x10) = lbl_802A3900;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x80103434
void fn_80103434(char* self, int flag) asm("fn_80103434");
void fn_80103434(char* self, int flag)
{
    *(char**)(self + 0x10) = lbl_802A3900;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x80103468
void fn_80103468(char* self, int flag) asm("fn_80103468");
void fn_80103468(char* self, int flag)
{
    *(char**)(self + 0x10) = lbl_802A3900;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x80103578
void fn_80103578(void* self) asm("fn_80103578");
void fn_80103578(void* self)
{
}

// 0x801037A0
void fn_801037A0(char* self, int flag) asm("fn_801037A0");
void fn_801037A0(char* self, int flag)
{
    *(char**)(self + 0x10) = lbl_802A3900;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x801038A8
void fn_801038A8(void* self) asm("fn_801038A8");
void fn_801038A8(void* self)
{
}

// 0x8010396C
void fn_8010396C(void* self) asm("fn_8010396C");
void fn_8010396C(void* self)
{
}

// 0x80103E6C
void fn_80103E6C(void* self) asm("fn_80103E6C");
void fn_80103E6C(void* self)
{
}

// 0x80103E70
void fn_80103E70(void* self) asm("fn_80103E70");
void fn_80103E70(void* self)
{
}

// 0x80104680
int fn_80104680(char* self) asm("fn_80104680");
int fn_80104680(char* self)
{
    return 0;
}

// 0x80104688
void fn_80104688(void* self) asm("fn_80104688");
void fn_80104688(void* self)
{
}

// 0x8010468C
void fn_8010468C(void* self) asm("fn_8010468C");
void fn_8010468C(void* self)
{
}

// 0x80104690
void fn_80104690(void* self) asm("fn_80104690");
void fn_80104690(void* self)
{
}

// 0x80104694
void fn_80104694(void* self) asm("fn_80104694");
void fn_80104694(void* self)
{
}

// 0x80104698
void fn_80104698(void* self) asm("fn_80104698");
void fn_80104698(void* self)
{
}

// 0x801046AC
void fn_801046AC(void* self) asm("fn_801046AC");
void fn_801046AC(void* self)
{
}

// 0x80104758
void fn_80104758(void* self) asm("fn_80104758");
void fn_80104758(void* self)
{
}

// 0x8010475C
int fn_8010475C(char* self) asm("fn_8010475C");
int fn_8010475C(char* self)
{
    return (int)lbl_80331130;
}

// 0x80104790
void fn_80104790(void* self) asm("fn_80104790");
void fn_80104790(void* self)
{
}

// 0x80104D78
void fn_80104D78(void* self) asm("fn_80104D78");
void fn_80104D78(void* self)
{
}

// 0x80104DB0
void fn_80104DB0(char* self) asm("fn_80104DB0");
void fn_80104DB0(char* self)
{
    fn_80108A40((int)lbl_8037BAE0);
}

// 0x80104DD4
void fn_80104DD4(char* self) asm("fn_80104DD4");
void fn_80104DD4(char* self)
{
    fn_80108AF4((int)self);
}

// 0x80104DF4
void fn_80104DF4(char* self) asm("fn_80104DF4");
void fn_80104DF4(char* self)
{
    fn_80108CE4((int)self);
}

// 0x80105F80
void fn_80105F80(char* self, int a) asm("fn_80105F80");
void fn_80105F80(char* self, int a)
{
    *(int*)((char*)a + 0) = *(int*)((char*)self + 4);
    *(int*)((char*)self + 4) = a;
}

// 0x80105F90
void fn_80105F90(char* self) asm("fn_80105F90");
void fn_80105F90(char* self)
{
    fn_80105F08((int)1, (int)(0 | 65535));
}

