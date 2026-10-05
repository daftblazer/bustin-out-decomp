#ifndef SIMS_CAS_CASSTATE_H
#define SIMS_CAS_CASSTATE_H

#include "sims/cas/CASTarget.h"

// Owner of the Create-A-Sim screen: creates it on start-up and tears it down
// again. The class name is provisional.
class CASState {
public:
    void fn_80008934();
    ~CASState();
    void Startup(int arg);
    void Shutdown();
    void fn_80008A30();
    void Update();

    int unk0;          // 1 once started
    CASTarget* unk4;
    int unk8;
    int unkC;          // set on the first update
};

#endif
