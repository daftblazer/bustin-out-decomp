// Game code at 0x801F6614-0x8021A398: trivial functions (empty virtuals, getters, setters, destructors). Compiled at -O2.
// Each is named by address with an asm label so it keeps the symbol of the original.

extern "C" int fn_801C5074(int, int);
extern "C" int fn_801F6C8C(int);
extern "C" int fn_801FC4C8(int, int, int, int, int);
extern "C" int fn_801FCB34(int, int, int, int, int);
extern "C" int fn_801FCBA0(int, int, int, int, int);
extern "C" int fn_80218C54(int);
extern "C" int fn_8021A32C(int, int);
extern "C" int fn_802316EC(int);
extern "C" int fn_8023C304(int, int);
extern "C" int fn_8023C40C(int);
extern "C" int fn_8023F1B4(int);
extern "C" void fn_801B8A60(void*);
extern char lbl_802C9648[];
extern char lbl_802CA1A0[];
extern char lbl_802CA1E0[];
extern char lbl_802CAAF8[];
extern char lbl_802CB660[];
extern char lbl_802CB698[];
extern int lbl_8037D3D0;
extern int lbl_8037D3E0;
extern int lbl_8037D3E8;
extern int lbl_8037D3F0;
extern int lbl_8037D3F8;
extern int lbl_8037D400;
extern int lbl_8037D408;
extern int lbl_8037D410;
extern int lbl_8037D418;
extern int lbl_8037D420;
extern int lbl_8037D428;
extern int lbl_8037D430;
extern int lbl_8037D438;
extern int lbl_8037D440;
extern int lbl_8037D448;
extern int lbl_8037D450;
extern int lbl_8037D458;
extern int lbl_8037D478;
extern int lbl_8037D480;
extern int lbl_8037D944;
extern int lbl_8037D988;

// 0x801F6AE0
void fn_801F6AE0(char* self, int a) asm("fn_801F6AE0");
void fn_801F6AE0(char* self, int a)
{
    fn_8023C304((int)a, (int)a);
}

// 0x801F6C38
void fn_801F6C38(char* self, int a) asm("fn_801F6C38");
void fn_801F6C38(char* self, int a)
{
    *(short*)((char*)self + 4) = a;
    *(int*)((char*)self + 0) = (int)lbl_802CA1A0;
}

// 0x801F6C84
int fn_801F6C84(char* self) asm("fn_801F6C84");
int fn_801F6C84(char* self)
{
    return *(short*)((char*)self + 4);
}

// 0x801F978C
int fn_801F978C(char* self) asm("fn_801F978C");
int fn_801F978C(char* self)
{
    return -1;
}

// 0x801FB760
void fn_801FB760(char* self, int a) asm("fn_801FB760");
void fn_801FB760(char* self, int a)
{
    fn_801FCB34((int)self, (int)a, (int)1413567572, (int)1, (int)0);
}

// 0x801FB790
void fn_801FB790(char* self, int a) asm("fn_801FB790");
void fn_801FB790(char* self, int a)
{
    fn_801FCBA0((int)self, (int)a, (int)1413567572, (int)1, (int)0);
}

// 0x801FC088
void fn_801FC088(void* self) asm("fn_801FC088");
void fn_801FC088(void* self)
{
}

// 0x801FC08C
void fn_801FC08C(void* self) asm("fn_801FC08C");
void fn_801FC08C(void* self)
{
}

// 0x801FC090
void fn_801FC090(void* self) asm("fn_801FC090");
void fn_801FC090(void* self)
{
}

// 0x801FC094
void fn_801FC094(void* self) asm("fn_801FC094");
void fn_801FC094(void* self)
{
}

// 0x801FC098
int fn_801FC098(char* self) asm("fn_801FC098");
int fn_801FC098(char* self)
{
    return 1;
}

// 0x801FC594
void fn_801FC594(char* self, int a, int b, int c) asm("fn_801FC594");
void fn_801FC594(char* self, int a, int b, int c)
{
    fn_801FC4C8((int)self, (int)a, (int)b, (int)0, (int)c);
}

// 0x801FCC74
void fn_801FCC74(char* self, int flag) asm("fn_801FCC74");
void fn_801FCC74(char* self, int flag)
{
    *(char**)(self + 0) = lbl_802CA1E0;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x801FCD10
void fn_801FCD10(char* self) asm("fn_801FCD10");
void fn_801FCD10(char* self)
{
    fn_8023C40C((int)((int)self + 1328));
}

// 0x801FCD34
int fn_801FCD34(char* self) asm("fn_801FCD34");
int fn_801FCD34(char* self)
{
    return *(int*)(self + 0x420);
}

// 0x801FCD3C
char* fn_801FCD3C(char* self) asm("fn_801FCD3C");
char* fn_801FCD3C(char* self)
{
    return self + 0x4;
}

// 0x801FCD44
int fn_801FCD44(char* self) asm("fn_801FCD44");
int fn_801FCD44(char* self)
{
    return *(int*)(self + 0x66C);
}

// 0x801FCD4C
int fn_801FCD4C(char* self) asm("fn_801FCD4C");
int fn_801FCD4C(char* self)
{
    return *(int*)(self + 0x684);
}

// 0x801FCD54
int fn_801FCD54(char* self) asm("fn_801FCD54");
int fn_801FCD54(char* self)
{
    return *(int*)(self + 0x680);
}

// 0x801FCD5C
int fn_801FCD5C(char* self) asm("fn_801FCD5C");
int fn_801FCD5C(char* self)
{
    return *(int*)(self + 0x688);
}

// 0x801FCD84
void fn_801FCD84(char* self) asm("fn_801FCD84");
void fn_801FCD84(char* self)
{
    fn_802316EC((int)self);
}

// 0x801FCDA4
void fn_801FCDA4(char* self) asm("fn_801FCDA4");
void fn_801FCDA4(char* self)
{
    fn_802316EC((int)self);
}

// 0x801FCDC4
void fn_801FCDC4(char* self) asm("fn_801FCDC4");
void fn_801FCDC4(char* self)
{
    fn_802316EC((int)self);
}

// 0x801FCE1C
int fn_801FCE1C(char* self) asm("fn_801FCE1C");
int fn_801FCE1C(char* self)
{
    return *(int*)(self + 0x8);
}

// 0x801FCE24
void fn_801FCE24(char* self) asm("fn_801FCE24");
void fn_801FCE24(char* self)
{
    fn_801F6C8C((int)*(int*)((char*)self + 4));
}

// 0x801FCE48
int fn_801FCE48(char* self) asm("fn_801FCE48");
int fn_801FCE48(char* self)
{
    return *(int*)(self + 0x8);
}

// 0x801FCE50
void fn_801FCE50(char* self) asm("fn_801FCE50");
void fn_801FCE50(char* self)
{
    fn_80218C54((int)*(int*)((char*)self + 4));
}

// 0x801FCE74
int fn_801FCE74(char* self) asm("fn_801FCE74");
int fn_801FCE74(char* self)
{
    return *(int*)(self + 0x8);
}

// 0x801FDB6C
int fn_801FDB6C(void) asm("fn_801FDB6C");
int fn_801FDB6C(void)
{
    return lbl_8037D3D0;
}

// 0x802006F8
void fn_802006F8(char* self) asm("fn_802006F8");
void fn_802006F8(char* self)
{
    *(int*)((char*)self + 8264) = *(int*)((char*)self + 8260);
}

// 0x80202188
int fn_80202188(char* self) asm("fn_80202188");
int fn_80202188(char* self)
{
    return 0;
}

// 0x80202190
void fn_80202190(void* self) asm("fn_80202190");
void fn_80202190(void* self)
{
}

// 0x80202194
void fn_80202194(void* self) asm("fn_80202194");
void fn_80202194(void* self)
{
}

// 0x802023F8
void fn_802023F8(void* self) asm("fn_802023F8");
void fn_802023F8(void* self)
{
}

// 0x802023FC
void fn_802023FC(void* self) asm("fn_802023FC");
void fn_802023FC(void* self)
{
}

// 0x80202400
void fn_80202400(void* self) asm("fn_80202400");
void fn_80202400(void* self)
{
}

// 0x80202404
void fn_80202404(void* self) asm("fn_80202404");
void fn_80202404(void* self)
{
}

// 0x80203D74
void fn_80203D74(char* self, int flag) asm("fn_80203D74");
void fn_80203D74(char* self, int flag)
{
    *(char**)(self + 0) = lbl_802CAAF8;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x80203DA8
void fn_80203DA8(char* self, int flag) asm("fn_80203DA8");
void fn_80203DA8(char* self, int flag)
{
    *(char**)(self + 0x10) = lbl_802C9648;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x80203DDC
int fn_80203DDC(void) asm("fn_80203DDC");
int fn_80203DDC(void)
{
    return lbl_8037D988;
}

// 0x80203E34
int fn_80203E34(void) asm("fn_80203E34");
int fn_80203E34(void)
{
    return lbl_8037D944;
}

// 0x80203EDC
void fn_80203EDC(char* self) asm("fn_80203EDC");
void fn_80203EDC(char* self)
{
    fn_802316EC((int)self);
}

// 0x80203F34
int fn_80203F34(char* self) asm("fn_80203F34");
int fn_80203F34(char* self)
{
    return *(int*)(self + 0x8);
}

// 0x8020463C
void fn_8020463C(char* self) asm("fn_8020463C");
void fn_8020463C(char* self)
{
    fn_8023F1B4((int)*(int*)((char*)self + 0));
}

// 0x80206A5C
void fn_80206A5C(char* self) asm("fn_80206A5C");
void fn_80206A5C(char* self)
{
    fn_801C5074((int)(int)&lbl_8037D3E0, (int)2);
}

// 0x80206A84
void fn_80206A84(char* self) asm("fn_80206A84");
void fn_80206A84(char* self)
{
    fn_801C5074((int)(int)&lbl_8037D3E8, (int)2);
}

// 0x80206AAC
void fn_80206AAC(char* self) asm("fn_80206AAC");
void fn_80206AAC(char* self)
{
    fn_801C5074((int)(int)&lbl_8037D3F0, (int)2);
}

// 0x80206AD4
void fn_80206AD4(char* self) asm("fn_80206AD4");
void fn_80206AD4(char* self)
{
    fn_801C5074((int)(int)&lbl_8037D3F8, (int)2);
}

// 0x80206AFC
void fn_80206AFC(char* self) asm("fn_80206AFC");
void fn_80206AFC(char* self)
{
    fn_801C5074((int)(int)&lbl_8037D400, (int)2);
}

// 0x80206B24
void fn_80206B24(char* self) asm("fn_80206B24");
void fn_80206B24(char* self)
{
    fn_801C5074((int)(int)&lbl_8037D408, (int)2);
}

// 0x80206B4C
void fn_80206B4C(char* self) asm("fn_80206B4C");
void fn_80206B4C(char* self)
{
    fn_801C5074((int)(int)&lbl_8037D410, (int)2);
}

// 0x80206B74
void fn_80206B74(char* self) asm("fn_80206B74");
void fn_80206B74(char* self)
{
    fn_801C5074((int)(int)&lbl_8037D418, (int)2);
}

// 0x80206B9C
void fn_80206B9C(char* self) asm("fn_80206B9C");
void fn_80206B9C(char* self)
{
    fn_801C5074((int)(int)&lbl_8037D420, (int)2);
}

// 0x80206BC4
void fn_80206BC4(char* self) asm("fn_80206BC4");
void fn_80206BC4(char* self)
{
    fn_801C5074((int)(int)&lbl_8037D428, (int)2);
}

// 0x80206BEC
void fn_80206BEC(char* self) asm("fn_80206BEC");
void fn_80206BEC(char* self)
{
    fn_801C5074((int)(int)&lbl_8037D430, (int)2);
}

// 0x80206C14
void fn_80206C14(char* self) asm("fn_80206C14");
void fn_80206C14(char* self)
{
    fn_801C5074((int)(int)&lbl_8037D438, (int)2);
}

// 0x80206C3C
void fn_80206C3C(char* self) asm("fn_80206C3C");
void fn_80206C3C(char* self)
{
    fn_801C5074((int)(int)&lbl_8037D440, (int)2);
}

// 0x80206C64
void fn_80206C64(char* self) asm("fn_80206C64");
void fn_80206C64(char* self)
{
    fn_801C5074((int)(int)&lbl_8037D448, (int)2);
}

// 0x80206C8C
void fn_80206C8C(char* self) asm("fn_80206C8C");
void fn_80206C8C(char* self)
{
    fn_801C5074((int)(int)&lbl_8037D450, (int)2);
}

// 0x80206CB4
void fn_80206CB4(char* self) asm("fn_80206CB4");
void fn_80206CB4(char* self)
{
    fn_801C5074((int)(int)&lbl_8037D458, (int)2);
}

// 0x8021607C
void fn_8021607C(void* self) asm("fn_8021607C");
void fn_8021607C(void* self)
{
}

// 0x80217200
void fn_80217200(char* self) asm("fn_80217200");
void fn_80217200(char* self)
{
    *(char*)((char*)self + 0) = 0;
}

// 0x80217D64
void fn_80217D64(char* self, int flag) asm("fn_80217D64");
void fn_80217D64(char* self, int flag)
{
    *(char**)(self + 0) = lbl_802CB698;
    if (flag & 1) {
        fn_801B8A60(self);
    }
}

// 0x80218038
int fn_80218038(char* self) asm("fn_80218038");
int fn_80218038(char* self)
{
    return *(int*)((char*)*(int*)((char*)self + 24) + 28);
}

// 0x8021814C
void fn_8021814C(char* self) asm("fn_8021814C");
void fn_8021814C(char* self)
{
    fn_801C5074((int)(int)&lbl_8037D478, (int)2);
}

// 0x8021821C
void fn_8021821C(char* self) asm("fn_8021821C");
void fn_8021821C(char* self)
{
    fn_801C5074((int)(int)&lbl_8037D480, (int)2);
}

// 0x8021A36C
void fn_8021A36C(char* self) asm("fn_8021A36C");
void fn_8021A36C(char* self)
{
    fn_8021A32C((int)1, (int)(0 | 65535));
}

