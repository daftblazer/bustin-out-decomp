#ifndef ENGINE_UNK80186FEC_H
#define ENGINE_UNK80186FEC_H

#include "engine/UnkTargetBase.h"

// Screen object that groups other screen objects (0x100 bytes; destructor
// 0x80186FEC). The name is unknown.
class Unk80186FEC : public UnkTargetBase {
public:
    virtual ~Unk80186FEC();

    char unk48[0x100 - 0x48];
};

#endif
