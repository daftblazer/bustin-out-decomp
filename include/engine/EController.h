#ifndef ENGINE_ECONTROLLER_H
#define ENGINE_ECONTROLLER_H

// Controller input. EController is named in The Sims 2's symbol map
// (PlayerCheats::Capture(EController*)); method names are provisional.

struct Unk8015CAA0 {
    void fn_8015CAA0(void*);
};

struct EController {
    int fn_8015E304();              // currently pressed buttons
    void fn_8015DFEC(int);
    float fn_8015DEE4(int, int);    // stick axis value
    int fn_8015E0F8(int);           // button just pressed
};

// Controller manager singleton at 0x8037C11C.
struct Unk8037C11C {
    Unk8015CAA0* fn_8015E574(int);
    void fn_8015E550(int);
    int fn_8015E614(int);
    EController* fn_8015E5FC(int);
};

extern Unk8037C11C* lbl_8037C11C;

// Frame time in seconds.
extern float lbl_8037BFC8;

#endif
