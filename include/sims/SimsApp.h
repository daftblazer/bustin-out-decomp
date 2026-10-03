#ifndef SIMS_SIMSAPP_H
#define SIMS_SIMSAPP_H

// NOTE: The retail disc has no symbols. Class, member and function names in
// this project are provisional unless stated otherwise.

struct SimsAppUnk478 {
    ~SimsAppUnk478();
    void Stop();
};

struct SimsAppUnk2B3C {
    char unk0[0x9C];
    virtual ~SimsAppUnk2B3C();
};

struct Unk802E6700 {
    char unk0[0x100]; // size unknown
    void Begin();
    void End();
};

struct Unk80340094 {
    char unk0[0x100]; // size unknown
    void Shutdown();
};

struct Unk802E5E1C {
    char unk0[0x100]; // size unknown
    void Shutdown();
};

extern Unk802E6700 lbl_802E6700;
extern Unk80340094 lbl_80340094;
extern Unk802E5E1C lbl_802E5E1C;
extern void* lbl_8037C3D8;

void fn_801CD9A8(void*);
void fn_800FD840();
void fn_801B8A60(void*);

// The game's application object (derives from an engine application class).
class SimsApp {
public:
    void Shutdown();

    char unk0[0x478];
    SimsAppUnk478* unk478;
    char unk47C[0x2B3C - 0x47C];
    SimsAppUnk2B3C* unk2B3C;
    char unk2B40;
    int unk2B44;
    char unk2B48[0x2B60 - 0x2B48];
    void* unk2B60;
};

#endif
