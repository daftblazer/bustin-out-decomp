#ifndef SIMS_UNK8003AA6C_H
#define SIMS_UNK8003AA6C_H

#include "sims/Unk80026864.h"

class Unk8003AA6C;
typedef void (Unk8003AA6C::*Unk8003AA6CDraw)(struct ERC* rc, const EVec2& at);

// A per-player in-game screen (0xBC bytes with its virtual base) that turns button
// presses into messages for its parent and draws through a table indexed by the
// current mode. The name is unknown.
class Unk8003AA6C : public UnkTargetBase, public virtual Unk802A2AC0 {
public:
    Unk8003AA6C(int player);
    virtual ~Unk8003AA6C();
    virtual void vfn2();                               // update
    virtual void vfn3(struct ERC* rc);                 // draw
    virtual void vfn2(int newMode);                    // Unk802A2AC0
    virtual void vfn3();                               // Unk802A2AC0 (empty)

    void fn_8003B61C(struct ERC* rc, const EVec2& at);
    void fn_8003B6A4(struct ERC* rc, const EVec2& at);
    void fn_8003B710(struct ERC* rc, const EVec2& at);
    void fn_8003B730(struct ERC* rc, const EVec2& at);
    void fn_8003B750(struct ERC* rc, const EVec2& at);
    void fn_8003B770(struct ERC* rc, const EVec2& at);

    EVec2 unk4C;
    Unk8003AA6CDraw unk54[12];   // per mode
};

#endif
