#include "sims/cas/CASState.h"

// 0x80008934
void CASState::fn_80008934() {
    unk4 = 0;
}

// 0x80008940
CASState::~CASState() {
}

// 0x80008968
void CASState::Startup(int arg) {
    unk8 = arg;
    unkC = 0;
    unk0 = 0;
    unk4 = new CASTarget;
    unk4->fn_8000D010();
    unk0 = 1;
}

// 0x800089D8
void CASState::Shutdown() {
    if (unk4 != 0) {
        delete unk4;
    }
    unk4 = 0;
}

// 0x80008A30
void CASState::fn_80008A30() {
    unk4->fn_8000F9D8();
}

// 0x80008A54
void CASState::Update() {
    if (unkC == 0) {
        unkC = 1;
    }
    unk4->vfn3();
}
