#ifndef ENGINE_UNK8018643C_H
#define ENGINE_UNK8018643C_H

#include "engine/UnkTargetBase.h"

struct ERC;
struct EColorF;

// Screen object of 0x80 bytes (destructor 0x8018643C): the base of the text
// buttons and the type of their child pieces. The name is unknown.
class Unk8018643C : public UnkTargetBase {
public:
    virtual ~Unk8018643C();
    virtual void vfn19(ERC* rc, int, const EColorF& color, int); // draw in a colour

    char unk48[0x80 - 0x48];
};

// Node of the child list at the start of every screen object.
struct Unk801B4760Node {
    Unk8018643C* item;
    int unk4;
    Unk801B4760Node* next;
};

#endif
