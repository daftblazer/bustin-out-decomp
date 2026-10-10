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
