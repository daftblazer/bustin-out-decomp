// Flash player: String values and the String / Color native methods.
// -O0, see tools/tu_ui.sh. Plain functions of this unit are in Unk8014FD8C_c.c.

extern "C" {
unsigned long fn_80111FF8(const char* s);             // strlen
char* fn_80111F74(char* d, const char* s);            // strcpy
extern void* (*lbl_8033D1E0[16])(unsigned);           // host callbacks, entry 0 allocates
}

extern "C" int fn_8012C7C8(void* obj);                    // type tag
extern "C" int lbl_802D67B4[];                         // per-type release function
extern "C" void* lbl_8037BF74;
extern "C" void* lbl_8037BF78;
extern "C" void* lbl_8037BF7C;
extern "C" void* lbl_8037BF80;
extern "C" void* lbl_8037BF84;
extern "C" void* lbl_8037BF88;
extern "C" void* lbl_8037BF8C;
extern "C" void* lbl_8037BF90;
extern "C" void* lbl_8037BF94;
extern "C" void* lbl_8037BF98;
extern "C" void* lbl_8037BF9C;
extern "C" void* lbl_8037BFA0;

// drop a reference through the release function of the object's type
#define RELEASE(g)                                                                 \
    if (g) {                                                                       \
        (*(void (**)(void*))((char*)lbl_802D67B4 + fn_8012C7C8(g) * 4))(g);        \
        g = 0;                                                                     \
    }

class Unk8014FD8C_Obj;

class Unk8012C8FC {                 // base of every ActionScript value
public:
    Unk8012C8FC(int type);
    int header;
};

// String value (type 1): a heap copy of the text at +4
class Unk8014FD8C : public Unk8012C8FC {
public:
    Unk8014FD8C(const char* text);
    ~Unk8014FD8C();
    static void* operator new(unsigned size);       // 0x8012C44C, defined elsewhere
    static void operator delete(void* p, unsigned size);
    char* text;
};

Unk8014FD8C::Unk8014FD8C(const char* s) : Unk8012C8FC(1)
{
    int size = fn_80111FF8(s) + 1;
    text = (char*)lbl_8033D1E0[0](size);
    fn_80111F74(text, s);
}

Unk8014FD8C::~Unk8014FD8C()
{
    RELEASE(lbl_8037BF74)
    RELEASE(lbl_8037BF78)
    RELEASE(lbl_8037BF7C)
    RELEASE(lbl_8037BF80)
    RELEASE(lbl_8037BF84)
    RELEASE(lbl_8037BF88)
    RELEASE(lbl_8037BF8C)
    RELEASE(lbl_8037BF90)
    RELEASE(lbl_8037BF94)
    RELEASE(lbl_8037BF98)
    RELEASE(lbl_8037BF9C)
    RELEASE(lbl_8037BFA0)
    ((void (*)(void*))lbl_8033D1E0[1])(text);
    text = 0;
    text = 0;
}

// Number value (0x8012F4C0), allocator 0x8012F50C, defined elsewhere
class Unk8012F4C0 : public Unk8012C8FC {
public:
    Unk8012F4C0(int v);
    static void* operator new(unsigned size);
    int value;
};

// Array value (0x8012D9F0), allocator 0x8012F6C4, defined elsewhere
class Unk8012D9F0 : public Unk8012C8FC {
public:
    Unk8012D9F0();
    static void* operator new(unsigned size);
    void fn_8012DF6C(int index, Unk8014FD8C_Obj* value);    // set element
    int unk4[5];
};

extern "C" const char lbl_802B6491[];                      // character class table, indexed from -1
// the C library's tolower/toupper macros: a statement expression with its own temporary
#define TO_LOWER(x) ({ int c_ = (x); ((char)(*(c_ + lbl_802B6491) & 1)) ? c_ + 0x20 : c_; })
#define TO_UPPER(x) ({ int c_ = (x); ((char)(*(c_ + lbl_802B6491) & 2)) ? c_ - 0x20 : c_; })

// ---- natives: (this value, argument count), arguments are read from the VM stack ----
class Unk8014FD8C_Obj;
extern "C" {
extern char lbl_8033D2A8[];                 // the VM object
extern Unk8014FD8C_Obj* lbl_8037D110;       // undefined value
Unk8014FD8C_Obj* fn_801489D4(void* vm, int i);          // peek i-th operand
int fn_801321E4(Unk8014FD8C_Obj* v);                    // ToInt
Unk8014FD8C_Obj* fn_80131E8C(Unk8014FD8C_Obj* v);
char* fn_8012D9C4(Unk8014FD8C_Obj* v);                  // string text
void fn_80132420(Unk8014FD8C_Obj* v, char* buf);        // ToString into a buffer
char* fn_80111DA0(char* d, const char* s);              // strcat
char* fn_8026F4D8(const char* h, const char* n);        // strstr
char* fn_8026F540(char* s, const char* delim);          // strtok
char* fn_80111F74(char* d, const char* s);              // strcpy

Unk8014FD8C_Obj* fn_80150228(Unk8014FD8C_Obj* self, int nargs)
{
    Unk8014FD8C_Obj* a0;
    int idx;
    char* s;
    char ch[2];
    Unk8014FD8C* r;

    a0 = fn_801489D4(lbl_8033D2A8, 0);
    idx = fn_801321E4(a0);
    s = fn_8012D9C4(fn_80131E8C(self));
    if (s != 0) {
        if (!(idx >= 0 && idx < (int)fn_80111FF8(s))) {
            return lbl_8037D110;
        } else {
            ch[0] = s[idx];
            ch[1] = 0;
            r = new Unk8014FD8C(ch);
            return (Unk8014FD8C_Obj*)r;
        }
    }
    return lbl_8037D110;
}

Unk8014FD8C_Obj* fn_80150338(Unk8014FD8C_Obj* self, int nargs)     // charCodeAt (not implemented)
{
    return lbl_8037D110;
}

Unk8014FD8C_Obj* fn_80150368(Unk8014FD8C_Obj* self, int nargs)     // concat
{
    char buf[0x100];
    int i;
    char tmp[0x100];
    Unk8014FD8C_Obj* a;

    fn_80132420(self, buf);
    for (i = 0; i < nargs; i++) {
        a = fn_801489D4(lbl_8033D2A8, i);
        fn_80132420(a, tmp);
        fn_80111DA0(buf, tmp);
    }
    a = (Unk8014FD8C_Obj*)new Unk8014FD8C(buf);
    return a;
}

Unk8014FD8C_Obj* fn_80150440(Unk8014FD8C_Obj* self, int nargs)     // fromCharCode (not implemented)
{
    return lbl_8037D110;
}

Unk8014FD8C_Obj* fn_80150470(Unk8014FD8C_Obj* self, int nargs)     // indexOf
{
    char buf[0x100];
    char needle[0x100];
    Unk8014FD8C_Obj* a;
    char* p;

    fn_80132420(self, buf);
    if (nargs == 0)
        return lbl_8037D110;
    a = fn_801489D4(lbl_8033D2A8, 0);
    fn_80132420(a, needle);
    p = fn_8026F4D8(buf, needle);
    if (p) {
        return (Unk8014FD8C_Obj*)new Unk8012F4C0(p - buf);
    } else {
        return (Unk8014FD8C_Obj*)new Unk8012F4C0(-1);
    }
}

Unk8014FD8C_Obj* fn_801505A4(Unk8014FD8C_Obj* self, int nargs)     // slice
{
    char buf[0x100];
    int start = -1;
    int end = 9999999;

    if (nargs == 0)
        return lbl_8037D110;
    if (nargs > 0) {
        Unk8014FD8C_Obj* a = fn_801489D4(lbl_8033D2A8, 0);
        start = fn_801321E4(a);
    }
    if (nargs > 1) {
        Unk8014FD8C_Obj* a = fn_801489D4(lbl_8033D2A8, 1);
        end = fn_801321E4(a);
    }
    fn_80132420(self, buf);
    int len = fn_80111FF8(buf);
    if (start < 0)
        start += len;
    if (end < 0)
        end += len;
    if (start >= len)
        start = len;
    if (end >= len)
        end = len;
    if (start > end) {
        int t = end;
        end = start;
        start = t;
    }
    if (end > start) {
        buf[end] = 0;
    } else {
        return lbl_8037D110;
    }
    Unk8014FD8C* r = new Unk8014FD8C(buf + start);
    return (Unk8014FD8C_Obj*)r;
}

Unk8014FD8C_Obj* fn_80150780(Unk8014FD8C_Obj* self, int nargs)     // split
{
    Unk8012D9F0* arr = new Unk8012D9F0();
    char sep[0x100];
    char str[0x100];

    if (nargs == 0) {
        arr->fn_8012DF6C(0, self);
    } else if (nargs > 0) {
        int limit = 99999999;
        Unk8014FD8C_Obj* a = fn_801489D4(lbl_8033D2A8, 0);
        char ch[2];
        fn_80132420(a, sep);
        fn_80111F74(str, fn_8012D9C4(fn_80131E8C(self)));
        if (nargs > 1)
            limit = fn_801321E4(fn_801489D4(lbl_8033D2A8, 1));
        if (sep[0] == 0) {
            ch[1] = 0;
            int i;
            Unk8014FD8C* o;
            for (i = 0; i < limit && str[i] != 0; i++) {
                ch[0] = str[i];
                o = new Unk8014FD8C(ch);
                arr->fn_8012DF6C(i, (Unk8014FD8C_Obj*)o);
            }
        } else {
            char* p = fn_8026F540(str, sep);
            int i;
            Unk8014FD8C* o;
            for (i = 0; i < limit && p != 0; i++) {
                o = new Unk8014FD8C(p);
                arr->fn_8012DF6C(i, (Unk8014FD8C_Obj*)o);
                p = fn_8026F540(0, sep);
            }
        }
    }
    return (Unk8014FD8C_Obj*)arr;
}

Unk8014FD8C_Obj* fn_801509D0(Unk8014FD8C_Obj* self, int nargs)     // substr
{
    char buf[0x100];
    int start = -1;
    int count = 9999999;

    if (nargs == 0)
        return lbl_8037D110;
    if (nargs > 0) {
        Unk8014FD8C_Obj* a = fn_801489D4(lbl_8033D2A8, 0);
        start = fn_801321E4(a);
    }
    if (nargs > 1) {
        Unk8014FD8C_Obj* a = fn_801489D4(lbl_8033D2A8, 1);
        count = fn_801321E4(a);
    }
    fn_80132420(self, buf);
    int len = fn_80111FF8(buf);
    if (start < 0)
        start += len;
    if (start + count >= len)
        count = len - start;
    if (count >= 0) {
        buf[start + count] = 0;
    } else {
        return lbl_8037D110;
    }
    Unk8014FD8C* r = new Unk8014FD8C(buf + start);
    return (Unk8014FD8C_Obj*)r;
}

Unk8014FD8C_Obj* fn_80150B64(Unk8014FD8C_Obj* self, int nargs)     // substring
{
    char buf[0x100];
    int start = -1;
    int end = 9999999;

    if (nargs == 0)
        return lbl_8037D110;
    if (nargs > 0) {
        Unk8014FD8C_Obj* a = fn_801489D4(lbl_8033D2A8, 0);
        start = fn_801321E4(a);
    }
    if (nargs > 1) {
        Unk8014FD8C_Obj* a = fn_801489D4(lbl_8033D2A8, 1);
        end = fn_801321E4(a);
    }
    fn_80132420(self, buf);
    int len = fn_80111FF8(buf);
    if (start < 0)
        start = 0;
    if (end < 0)
        end = 0;
    if (start >= len)
        start = len;
    if (end >= len)
        end = len;
    if (start > end) {
        int t = end;
        end = start;
        start = t;
    }
    if (end > start) {
        buf[end] = 0;
    } else {
        return lbl_8037D110;
    }
    Unk8014FD8C* r = new Unk8014FD8C(buf + start);
    return (Unk8014FD8C_Obj*)r;
}

Unk8014FD8C_Obj* fn_80150D30(Unk8014FD8C_Obj* self, int nargs)     // toLowerCase
{
    char buf[0x100];
    int len;
    int i;

    fn_80132420(self, buf);
    len = fn_80111FF8(buf);
    for (i = 0; i < len; i++)
        buf[i] = TO_LOWER(buf[i]);
    Unk8014FD8C* r = new Unk8014FD8C(buf);
    return (Unk8014FD8C_Obj*)r;
}

Unk8014FD8C_Obj* fn_80150E28(Unk8014FD8C_Obj* self, int nargs)     // toUpperCase
{
    char buf[0x100];
    int len;
    int i;

    fn_80132420(self, buf);
    len = fn_80111FF8(buf);
    for (i = 0; i < len; i++)
        buf[i] = TO_UPPER(buf[i]);
    Unk8014FD8C* r = new Unk8014FD8C(buf);
    return (Unk8014FD8C_Obj*)r;
}

Unk8014FD8C_Obj* fn_80150574(Unk8014FD8C_Obj* self, int nargs)     // lastIndexOf (not implemented)
{
    return lbl_8037D110;
}
}
