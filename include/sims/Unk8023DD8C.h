#ifndef SIMS_UNK8023DD8C_H
#define SIMS_UNK8023DD8C_H

// What is on a tile: its walls, what covers each side of them and the floor
// (0x38 bytes; constructor 0x8023DD8C, destructor 0x8023DE20). One class: it used
// to be declared as a chain of placeholder structs, one per function, which made
// the compiler treat its temporaries differently from the original. The name is
// unknown. The assignment and the setter return the object: with `void` their
// callers load `this` before the other arguments, which the original does not do.
struct Unk8023DD8C {
    Unk8023DD8C();                                           // 0x8023DD8C
    ~Unk8023DD8C();                                          // 0x8023DE20
    Unk8023DD8C& fn_8023DE48(const Unk8023DD8C& other);      // 0x8023DE48: assignment
    int fn_8023DEA4(int mask);                               // has one of these walls
    int fn_8023DEBC();                                       // has any wall
    int fn_8023DED4(int wall);
    int fn_8023DF40(int wall);
    int fn_8023DFA8();
    int fn_8023E088(int wall, int side);                     // covering of one side of a wall
    Unk8023DD8C& fn_8023E110(int arg, int wall, int side);   // set it
    int fn_8023E1C4(int wall);                               // what is built on a wall
    void fn_8023E2FC(int wall);                              // remove a wall
    int fn_8023E354();                                       // first wall on the tile
    int fn_8023E3BC(int wall);                               // the one after
    int fn_8023E420(int half);                               // floor type on one half
    void fn_8023E43C(int flag, int which);
    int fn_8023D9B8(int wall);

    char unk0[0x38];
};

// The same data in the form the level stores it (constructor 0x8023DDC4); it has no
// destructor.
struct Unk8023DDC4 {
    Unk8023DDC4(const Unk8023DD8C& info);
    char unk0[0x38];
};

#endif
