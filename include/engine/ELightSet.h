#ifndef ENGINE_ELIGHTSET_H
#define ENGINE_ELIGHTSET_H

#include "engine/EVec3.h"

// The name is provisional; the layout comes from two functions that fill one in.
// Lighting set-up handed to the render context (0xE0 bytes).
struct ELightSet {
    struct Directional {
        EVec3 color;
        EVec3 direction;
    };
    struct Point {
        EVec3 position;
        float range;
        EVec3 color;
        float unk1C;
    };
    EVec3 ambient;
    int unkC;
    Directional directional[3];
    Point point[4];
    int numDirectional;
    int numPoint;
};

#endif
