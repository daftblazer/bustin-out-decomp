#ifndef ENGINE_BSTRING2_H
#define ENGINE_BSTRING2_H

// The engine's string of 16-bit characters: one pointer to a shared, reference-counted
// record (0x10 bytes; the count is at 0xC). The class and method names are from The
// Sims 2's symbol map, where the methods come in the same order and most have the same
// size (BString2, basic_string_ref2). Its interface follows basic_string, with the
// position and count arguments written out by the callers (0, -1).
//
// Return types are those the matched callers need (a callee's return type changes the
// order its arguments are loaded in), not necessarily the original's: assign() and
// erase() return a reference in basic_string.
class BString2 {
public:
    BString2();                                                         // 0x801C4E90
    // With its default arguments this is the copy constructor. A user-declared copy
    // constructor matters: it gives every BString2 local an 8-byte-aligned stack slot.
    BString2(const BString2& str, int pos = 0, int n = -1);             // 0x801C4EB0
    BString2(const unsigned short* s);                                  // 0x801C4FDC
    BString2(unsigned char c, int n);                                   // 0x801C5024
    BString2(const wchar_t* s);                                         // 0x801C60F0 (32-bit characters)
    ~BString2();                                                        // 0x801C5074
    BString2& operator=(const BString2& str);                           // 0x801C50B4
    BString2& operator=(const unsigned short* s);                       // 0x801C5148
    BString2& assign(const BString2& str, int pos, int n);              // 0x801C54EC
    void assign(const unsigned short* s);                               // 0x801C55CC
    void erase(int pos, int n);                                         // 0x801C5704
    const unsigned short* c_str();                                      // 0x801C5B24
    int fn_801C6020(const BString2& str);                               // non-zero when different
    int operator!=(const BString2& str) { return fn_801C6020(str); }
    int length();                                                       // 0x801C6058

    // Not declared yet; identified by position and size against The Sims 2:
    //   0x801C4F74 BString2(const unsigned short*, unsigned, unsigned)
    //   0x801C519C operator+=(const BString2&)        0x801C5204 operator+=(const unsigned short*)
    //   0x801C5258 append(const BString2&, pos, n)    0x801C5300 append(const unsigned short*, n)
    //   0x801C5330 append(const unsigned short*)      0x801C5384 append(c, n)
    //   0x801C5620 assign(c, n)                       0x801C58FC replace(pos, n, const BString2&, pos, n)
    //   0x801C59DC replace(pos, n, const unsigned short*)
    //   0x801C5B78 find(const BString2&, pos)         0x801C5BE4 find(const unsigned short*, pos)
    //   0x801C5C3C find(c, pos)
    //   0x801C4284 delete_ref()   0x801C42DC ref_count()   0x801C42E8 point()   0x801C42F4 len()

    void* unk0;                                                         // the shared record
};

#endif
