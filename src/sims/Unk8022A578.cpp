// Game code at 0x8022A578-0x80231A18: trivial functions (empty virtuals, getters, setters, destructors). Compiled at -O2.
// Each is named by address with an asm label so it keeps the symbol of the original.

extern "C" void fn_801B8A60(void*);
extern char lbl_802CDF80[];

// 0x8022A5D8
void fn_8022A5D8(char* self) asm("fn_8022A5D8");
void fn_8022A5D8(char* self)
{
    *(int*)(self + 0x8) = 0;
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

// 0x8022FAD4
int fn_8022FAD4(char* self) asm("fn_8022FAD4");
int fn_8022FAD4(char* self)
{
    return *(int*)(self + 0x4);
}

// 0x8022FC0C
void fn_8022FC0C(void* self) asm("fn_8022FC0C");
void fn_8022FC0C(void* self)
{
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

// 0x80231720
void fn_80231720(void* self) asm("fn_80231720");
void fn_80231720(void* self)
{
}

