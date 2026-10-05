#ifndef SIMS_ESIMSCAM_H
#define SIMS_ESIMSCAM_H

#include "engine/EVec3.h"

// The game camera. Class and method names follow The Sims 2's symbol map where
// the functions line up; member names are provisional.
class ESimsCam {
public:
    float GetCurZoomRatio();
    float GetNearPlane();
    float GetFarPlane();
    float GetFov();

    char unk0[0x3A4];
    float unk3A4; // current zoom distance
};

#endif
