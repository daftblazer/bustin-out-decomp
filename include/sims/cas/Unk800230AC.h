#ifndef SIMS_CAS_UNK800230AC_H
#define SIMS_CAS_UNK800230AC_H

#include "engine/Unk80186FEC.h"
#include "engine/Unk8018643C.h"
#include "engine/E3DWindow.h"
#include "sims/cas/Unk80023D3C.h"

// A value that runs from `min` to `max`.
struct Unk800230ACTimer {
    void Advance(float dt) {
        cur += dt;
        float r;
        if (cur < min) {
            r = min;
        } else if (cur > max) {
            r = max;
        } else {
            r = cur;
        }
        cur = r;
    }
    void Set(float min_, float max_) {
        cur = min_;
        min = min_;
        max = max_;
        float r;
        if (cur < min) {
            r = min;
        } else if (cur > max) {
            r = max;
        } else {
            r = cur;
        }
        cur = r;
    }
    bool AtEnd() const { return cur == max; }
    bool Running() const { return cur < max; }
    float Fraction() const { return (max - cur) / (max - min); }

    float min;
    float max;
    float cur;
};

// The "create a family" / family menu screen of Create-A-Sim (0xDD0 bytes).
// The name is unknown.
class Unk800230AC : public UnkTargetBase {
public:
    virtual ~Unk800230AC();
    virtual void vfn2();          // update
    virtual void vfn3(ERC* rc);   // draw
    void fn_80023488(ERC* rc);    // draw while sliding in
    void fn_800236E4(ERC* rc);    // draw
    void operator delete(void* ptr) { fn_80169EE8(ptr); }

    Unk800230ACTimer unk48;
    float unk54;          // height of the panel
    float unk58;
    float unk5C;
    float unk60;
    float unk64;
    float unk68;
    float unk6C;
    char unk70;           // state: 1 = family, 2 = sliding
    char unk71;           // state to return to
    char unk72;
    char unk73;
    int unk74;
    int unk78;
    Unk80181824* unk7C;   // background
    Unk80181824* unk80;   // bar
    Unk80181824* unk84;   // title decoration
    Unk80186FEC unk88;    // first row of buttons
    Unk80186FEC unk188;   // second row
    Unk80023D3C unk288[4];
    Unk80023D3C unk5A8[4];
    Unk8018643C unk8C8;
    Unk8018643C unk948;
    Unk8018643C unk9C8;
    Unk8018643C unkA48;
    Unk8018643C unkAC8;
    Unk8018643C unkB48;
    Unk8018643C unkBC8;
    Unk8018643C unkC48;
    Unk8018643C unkCC8;
    Unk8018643C unkD48;
    Unk8003C95C* unkDC8;  // font
    int unkDCC;
};

void fn_80041180(ERC* rc, float, float, float, float);

#endif
