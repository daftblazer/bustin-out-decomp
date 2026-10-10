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
