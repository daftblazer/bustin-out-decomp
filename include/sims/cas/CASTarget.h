#ifndef SIMS_CAS_CASTARGET_H
#define SIMS_CAS_CASTARGET_H

#include "engine/UnkTargetBase.h"
#include "engine/ResourceManagers.h"
#include "sims/EGlobal.h"
#include "sims/cas/CASWidgets.h"

void* fn_80169F1C(unsigned int size, int align); // aligned allocate
extern "C" void* fn_80111C78(void*, int, unsigned int); // memset

// 0xE0-byte member repeated five times (one per editable feature); its
// method at 0x80015900 returns the current choice.
struct CASTargetUnk533C {
    short fn_80015900();
    char unk0[0xE0];
};

struct E3DWindowLike {
    void fn_801546D8(void* window);
};

void fn_8010826C(void* viewer);
void fn_801066A0(void* viewer, const char* name, int);
extern "C" void fn_80106164(void* viewer, const char* command, ...);
unsigned char fn_80061FE0(short* choices);
void fn_80062134(unsigned char);

// The Create-A-Sim / Create-A-Family screen (0x5D30 bytes, ctor 0x80008AA0).
// Named after The Sims 2's CASTarget; whether this game used that exact name
// is not known. Members are generated from CASTarget.fields.
class CASTarget : public UnkTargetBase {
public:
    CASTarget();
    virtual ~CASTarget();
    void fn_8000B03C(E3DWindowLike* window);
    void fn_8000C588();
    void fn_8000CBD8();
    void fn_8000D010();
    void fn_8000F9D8();
    void fn_80014110();
    void fn_80014188(ERC* rc, const unsigned short* text, int a, EVec2* position, int b);
    void fn_80014378();
    void fn_80014564();
    void fn_80014A88();

    // Zero-filled on allocation.
    void* operator new(unsigned int size) {
        void* ptr = fn_80169F1C(size, 16);
        fn_80111C78(ptr, 0, size);
        return ptr;
    }

#include "sims/cas/CASTarget.inc"
};

extern int lbl_8037CA80;
extern int lbl_8037C230;

#endif
