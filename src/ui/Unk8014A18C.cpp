// Flash (ActionScript 1) player: bytecode interpreter, value-type predicates and
// the global VM object. Compiled at -O0 (tools/tu_ui.sh); `register` marks the
// parameters and locals the original kept in registers. The URL-query helpers at
// 8014E9F0-8014ED9C are plain C, see Unk8014A18C_c.c.

extern "C" {

int fn_8012C7C8(void* obj);           // object type tag
int fn_8012C8A4(void* obj);

// 4-byte list heads inside the VM object
struct VmList0 { int head; };
struct VmList1 { int head; };
struct VmList2 { int head; };

VmList0* fn_8014EE18(VmList0* p)
{
    p->head = 0;
    return p;
}

VmList1* fn_8014EE48(VmList1* p)
{
    p->head = 0;
    return p;
}

VmList2* fn_8014EE78(VmList2* p)
{
    p->head = 0;
    return p;
}

// the 0x614-byte VM object
struct Vm {
    VmList0 a;          // 0x000 (0x404 bytes)
    char pad[0x400];
    VmList1 b;          // 0x404
    char padb[0x80];
    VmList2 c;          // 0x488
    char padc[0x80];
    VmList2 d;          // 0x50C
    char padd[0x80];
    VmList2 e;          // 0x590
    char pade[0x80];
};

Vm* fn_8014EEA8(Vm* p)
{
    fn_8014EE18(&p->a);
    fn_8014EE48(&p->b);
    fn_8014EE78(&p->c);
    fn_8014EE78(&p->d);
    fn_8014EE78(&p->e);
    return p;
}

extern Vm lbl_8033D2A8;

void fn_8014EF18(int initialize, int priority)
{
    if (priority == 0xFFFF && initialize != 0)
        fn_8014EEA8(&lbl_8033D2A8);
}
}
