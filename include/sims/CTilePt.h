#ifndef SIMS_CTILEPT_H
#define SIMS_CTILEPT_H

#include "engine/EVec3.h"

struct ETilePair;

// A tile position: column, row and level in one byte each (3 bytes; an object on the
// stack still takes an 8-byte slot). The class name and the method order are from
// The Sims 2's symbol map, where the constructors, the destructor, assignment, the
// compound operators and the accessors have the same sizes as here. Members that
// have not been checked against it keep their addresses as names.
struct CTilePt {
    CTilePt();                                         // 0x801C6EF4: level = 0
    CTilePt(const CTilePt& other);                     // 0x801C6F00
    CTilePt(const ETilePair& subTile, int level);      // 0x801C6F20: sub-tile units, 16 per tile
    CTilePt(int tileX, int tileY, int level);          // 0x801C6F44
    ~CTilePt();                                        // 0x801C6FCC
    CTilePt& operator=(const CTilePt& other);          // 0x801C6FF4
    int operator==(const CTilePt& other) const;        // 0x801C7014
    int operator!=(const CTilePt& other) const;        // 0x801C7054
    void fn_801C70F4(const CTilePt* step);             // 0x801C70F4: += or -= (Sims 2 has += first)
    void fn_801C711C(const CTilePt* step);             // 0x801C711C
    CTilePt operator+(const CTilePt& step) const;      // 0x801C7144
    EVec3 GetEVec3() const;                            // 0x801C6DEC
    int fn_801C7204();                                 // GetRow / GetColumn by position
    int fn_801C721C();
    int fn_801C727C();                                 // tile x
    int fn_801C7288();                                 // tile y
    void fn_801C72D4(int y, int x, int level);         // Set

    signed char x;
    signed char y;
    char unk2;                                         // level
};

#endif
