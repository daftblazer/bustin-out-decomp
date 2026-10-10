// Flash (ActionScript 1) player: the global VM object (static initialiser at the
// end of the unit). Compiled at -O0 (tools/tu_ui.sh). The interpreter itself and
// the type predicates are plain C functions, see Unk8014A18C_c.c.

// 4-byte list heads inside the VM object
class Unk8014EE18 {
public:
    Unk8014EE18();
    int head;
};

class Unk8014EE48 {
public:
    Unk8014EE48();
    int head;
};

class Unk8014EE78 {
public:
    Unk8014EE78();
    int head;
};

// The VM object, 0x614 bytes (global at 0x8033D2A8)
class Unk8014EEA8 {
public:
    Unk8014EEA8();
    Unk8014EE18 a;      // 0x000 (0x404 bytes)
    char pad[0x400];
    Unk8014EE48 b;      // 0x404
    char padb[0x80];
    Unk8014EE78 c;      // 0x488
    char padc[0x80];
    Unk8014EE78 d;      // 0x50C
    char padd[0x80];
    Unk8014EE78 e;      // 0x590
    char pade[0x80];
};

Unk8014EE18::Unk8014EE18() { head = 0; }
Unk8014EE48::Unk8014EE48() { head = 0; }
Unk8014EE78::Unk8014EE78() { head = 0; }
Unk8014EEA8::Unk8014EEA8() {}

Unk8014EEA8 lbl_8033D2A8;

// Allocation callback table supplied by the host (lbl_8033D1E0, entry 0 allocates).
extern "C" void* (*lbl_8033D1E0[16])(unsigned);

class Unk8012C8FC {                 // base of every ActionScript value
public:
    Unk8012C8FC(int type);
    int header;
};

class Unk8012F5C0 : public Unk8012C8FC {   // base of the object-like values
public:
    Unk8012F5C0(int type, int n);
    int members[2];                 // 0x04: property bag
};

class Unk8012CE60 {                 // member holder embedded at +4
public:
    Unk8012CE60(int n);
    int head;
    int count;
};

extern void fn_8012C800(void* obj);                       // add a reference
extern int fn_8012D400(void* bag, const char* name, void* value);   // set member

class Unk8014F358 : public Unk8012C8FC {
public:
    Unk8014F358(int v);
    static void* operator new(unsigned size);
    int unk4;
};

Unk8014F358::Unk8014F358(register int v) : Unk8012C8FC(4) { unk4 = v; }
void* Unk8014F358::operator new(register unsigned size) { return lbl_8033D1E0[0](size); }

class Unk8014F3FC : public Unk8012C8FC {
public:
    Unk8014F3FC(int v);
    static void* operator new(unsigned size);
    int unk4;
};

Unk8014F3FC::Unk8014F3FC(register int v) : Unk8012C8FC(5) { unk4 = v; }
void* Unk8014F3FC::operator new(register unsigned size) { return lbl_8033D1E0[0](size); }

class Unk8014F4A0 : public Unk8012C8FC {
public:
    Unk8014F4A0(int v);
    static void* operator new(unsigned size);
    int unk4;
};

Unk8014F4A0::Unk8014F4A0(register int v) : Unk8012C8FC(8) { unk4 = v; }
void* Unk8014F4A0::operator new(register unsigned size) { return lbl_8033D1E0[0](size); }

class Unk8014F544 : public Unk8012C8FC {
public:
    Unk8014F544();
    static void* operator new(unsigned size);
    Unk8012CE60 unk4;
};

Unk8014F544::Unk8014F544() : Unk8012C8FC(0x1b), unk4(4) {}
void* Unk8014F544::operator new(register unsigned size) { return lbl_8033D1E0[0](size); }

class Unk8014F5F0 {
public:
    static void* operator new(unsigned size);
};

void* Unk8014F5F0::operator new(register unsigned size) { return lbl_8033D1E0[0](size); }

// Function-object wrapper around a native callback (0x8012F61C / 0x8012F66C)
class Unk8012F61C : public Unk8012F5C0 {
public:
    Unk8012F61C(void* fn);
    static void* operator new(unsigned size);
    void* fn;
};

extern "C" int fn_8012BFC4(void* a, const char* b);
extern "C" void* fn_8012C154(void* a, int i);
extern "C" int fn_8012C188(void* a, int i);
extern "C" int fn_80132114(void* a, int i);
extern "C" void fn_8026FA38(void* calendar);              // OSCalendarTimeToTicks
extern "C" const char lbl_802B76F8[];                     // "prototype"
extern "C" const char lbl_802B7704[];                     // "setRGB"
extern "C" void* lbl_8037BEFC;                            // cached Color prototype
extern "C" void fn_8013BAF0();                            // Color.setRGB native

class Unk8014F648 : public Unk8012F5C0 {
public:
    Unk8014F648(register int a, register int b, register int c, register int d);
    static void* operator new(register unsigned size);
    int unkC;
    int unk10;
    int unk14;
    int unk18;
};

Unk8014F648::Unk8014F648(register int a, register int b, register int c, register int d) : Unk8012F5C0(10, 4)
{
    unkC = b;
    unk10 = a;
    unk18 = d;
    fn_8012C800((void*)unk18);
    unk14 = c;
    Unk8014F544* proto = new Unk8014F544();
    fn_8012D400((char*)this + 4, lbl_802B76F8, proto);
}

void* Unk8014F648::operator new(register unsigned size) { return lbl_8033D1E0[0](size); }

class Unk8014F740 : public Unk8012C8FC {
public:
    Unk8014F740();
    static void* operator new(register unsigned size);
    Unk8012CE60 unk4;
};

Unk8014F740::Unk8014F740() : Unk8012C8FC(0x14), unk4(2) {}
void* Unk8014F740::operator new(register unsigned size) { return lbl_8033D1E0[0](size); }

// Date: the OSCalendarTime lives at +0xC
class Unk8014F7EC : public Unk8012F5C0 {
public:
    Unk8014F7EC(register int year, register int mon, register int mday, register int hour,
                register int min, register int sec);
    static void* operator new(register unsigned size);
    int sec;     // 0x0C
    int min;     // 0x10
    int hour;    // 0x14
    int mday;    // 0x18
    int mon;     // 0x1C
    int year;    // 0x20
    int unk24;
    int unk28;
    int unk2C;
};

Unk8014F7EC::Unk8014F7EC(register int y, register int mo, register int md, register int h,
                         register int mi, register int s) : Unk8012F5C0(0x1c, 4)
{
    year = y;
    if (y > 99)
        year = year - 1900;
    mon = mo;
    mday = md;
    hour = h;
    min = mi;
    sec = s;
    unk2C = -1;
    fn_8026FA38(&sec);
}

void* Unk8014F7EC::operator new(register unsigned size) { return lbl_8033D1E0[0](size); }

class Unk8014F8E4 {
public:
    static void* operator new(register unsigned size);
};

void* Unk8014F8E4::operator new(register unsigned size) { return lbl_8033D1E0[0](size); }

class Unk8014F93C : public Unk8012F5C0 {
public:
    Unk8014F93C(register void* arg);
    void* Unk8014F9F0(register void* a, register const char* name);
    void* unkC;
};

Unk8014F93C::Unk8014F93C(register void* arg) : Unk8012F5C0(0x19, 4)
{
    if (fn_8012C188(arg, 0) != 0 && fn_80132114(fn_8012C154(arg, 0), 0) != 0) {
        unkC = fn_8012C154(arg, 0);
        fn_8012C800(unkC);
    } else {
        unkC = 0;
    }
}

void* Unk8014F93C::Unk8014F9F0(register void* a, register const char* name)
{
    if (fn_8012BFC4((void*)name, lbl_802B7704) == 0) {
        if (lbl_8037BEFC == 0) {
            lbl_8037BEFC = new Unk8012F61C((void*)fn_8013BAF0);
            fn_8012C800(lbl_8037BEFC);
        }
        return lbl_8037BEFC;
    }
    return 0;
}

// Operand stack of object pointers: count at +0, entries from +4
extern "C" int fn_8012C7C8(void* obj);                    // type tag
extern "C" int lbl_802D67B4[32];             // per-type release

class Unk8014FAE4 {
public:
    void* fn_8014FAE4(register int i);       // i-th entry from the top
    int fn_8014FB34();                       // count
    void* fn_8014FCB0();                     // top
    void fn_8014FBB8(register void* obj);    // push
    void fn_8014FC14();                      // pop
    int count;
    void* items[0x100];
};

void Unk8014FAE4::fn_8014FBB8(register void* obj)
{
    items[count++] = obj;
    fn_8012C800(obj);
}

void Unk8014FAE4::fn_8014FC14()
{
    (*(void (**)(void*))((char*)lbl_802D67B4 + fn_8012C7C8(items[count - 1]) * 4))(items[count - 1]);
    count--;
}

inline void* Unk8014FAE4::fn_8014FAE4(register int i) { do { return items[count - i - 1]; } while (0); }
inline int Unk8014FAE4::fn_8014FB34() { do { return count; } while (0); }
inline void* Unk8014FAE4::fn_8014FCB0() { do { return fn_8014FAE4(0); } while (0); }

class Unk8014FA8C {
public:
    static void* operator new(register unsigned size);
};

void* Unk8014FA8C::operator new(register unsigned size) { return lbl_8033D1E0[0](size); }

class Unk8014FB68 {
public:
    void* fn_8014FD00(register int i);
    void* fn_8014FB68();
    int count;
    void* items[0x100];
};

inline void* Unk8014FB68::fn_8014FD00(register int i) { do { return items[count - i - 1]; } while (0); }
inline void* Unk8014FB68::fn_8014FB68() { do { return fn_8014FD00(0); } while (0); }

// (the original emits these inline members because other units call them; take their
// addresses so this scratch unit does as well)
void* (Unk8014FAE4::*keep0)(int) = &Unk8014FAE4::fn_8014FAE4;
int (Unk8014FAE4::*keep1)() = &Unk8014FAE4::fn_8014FB34;
void* (Unk8014FB68::*keep3)() = &Unk8014FB68::fn_8014FB68;
void* (Unk8014FAE4::*keep2)() = &Unk8014FAE4::fn_8014FCB0;
void* (Unk8014FB68::*keep4)(int) = &Unk8014FB68::fn_8014FD00;
