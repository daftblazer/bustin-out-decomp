#ifndef ENGINE_UNK8018643C_H
#define ENGINE_UNK8018643C_H

#include "engine/UnkTargetBase.h"

// Screen object of 0x80 bytes (destructor 0x8018643C), used as the caption of
// a menu button. The name is unknown.
class Unk8018643C : public UnkTargetBase {
public:
    virtual ~Unk8018643C();

    char unk48[0x80 - 0x48];
};

#endif
