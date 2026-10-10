// Game code at 0x8026CB70-0x8026FE50: trivial functions (empty virtuals, getters, setters, destructors). Compiled at -O2.
// Each is named by address with an asm label so it keeps the symbol of the original.

extern "C" void fn_801B8A60(void*);
extern char lbl_802D19E8[];
// 0x8026D088
void fn_8026D088(char* self) asm("fn_8026D088");
void fn_8026D088(char* self)
{
    *(char*)(self + 0x0) = 0;
}

// 0x8026D0A4
void fn_8026D0A4(char* self, int flag) asm("fn_8026D0A4");
void fn_8026D0A4(char* self, int flag)
{
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x8026D0DC
void fn_8026D0DC(char* self, int a) asm("fn_8026D0DC");
void fn_8026D0DC(char* self, int a)
{
    *(char*)(self + 0x0) = a;
}

// 0x8026D2CC
void fn_8026D2CC(char* self, int flag) asm("fn_8026D2CC");
void fn_8026D2CC(char* self, int flag)
{
    *(char**)(self + 0) = lbl_802D19E8;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x8026D368
void fn_8026D368(void* self) asm("fn_8026D368");
void fn_8026D368(void* self)
{
}

// 0x8026D36C
void fn_8026D36C(void* self) asm("fn_8026D36C");
void fn_8026D36C(void* self)
{
}

// 0x8026D370
void fn_8026D370(void* self) asm("fn_8026D370");
void fn_8026D370(void* self)
{
}

// 0x8026D374
void fn_8026D374(void* self) asm("fn_8026D374");
void fn_8026D374(void* self)
{
}

// 0x8026D378
void fn_8026D378(void* self) asm("fn_8026D378");
void fn_8026D378(void* self)
{
}

// 0x8026D37C
void fn_8026D37C(void* self) asm("fn_8026D37C");
void fn_8026D37C(void* self)
{
}

// 0x8026D388
void fn_8026D388(void* self) asm("fn_8026D388");
void fn_8026D388(void* self)
{
}

// 0x8026D38C
void fn_8026D38C(void* self) asm("fn_8026D38C");
void fn_8026D38C(void* self)
{
}

// 0x8026D390
void fn_8026D390(void* self) asm("fn_8026D390");
void fn_8026D390(void* self)
{
}

// 0x8026D39C
void fn_8026D39C(void* self) asm("fn_8026D39C");
void fn_8026D39C(void* self)
{
}

// 0x8026D3A0
void fn_8026D3A0(void* self) asm("fn_8026D3A0");
void fn_8026D3A0(void* self)
{
}

// 0x8026D3A4
void fn_8026D3A4(void* self) asm("fn_8026D3A4");
void fn_8026D3A4(void* self)
{
}

