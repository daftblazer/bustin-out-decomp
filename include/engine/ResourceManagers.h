#ifndef ENGINE_RESOURCEMANAGERS_H
#define ENGINE_RESOURCEMANAGERS_H

#include "engine/EResourceManager.h"
#include "engine/EStaticObject.h"

// Global resource managers. They share the lookup method at 0x80177628, so they
// are probably instances of one class (or of classes with a common base); until
// that is established each has its own placeholder type.

// These three globals share the method at 0x80177628 (resource managers?).
struct Unk803401C4 {
    void* fn_80177628(unsigned int id, int, int); // look up / load a resource by id
    void fn_801777B0(unsigned int id);            // reload
    char unk0[0xA4];
    int unkA4; // default language
};

struct Unk80340AB8 {
    void* fn_80177628(unsigned int id, int, int); // look up / load a resource by id
    char unk0[0x6C];
};

struct Unk8033F5C4 {
    void* fn_80177628(unsigned int id, int, int); // look up / load a resource by id
    char unk0[0xA4];
};

struct Unk8033FA38 {
    void* fn_80177628(unsigned int id, int, int); // look up / load a resource by id
    char unk0[0x100]; // size unknown
};

struct Unk8033F964 {
    void* fn_80177628(unsigned int id, int, int); // look up / load a resource by id
    char unk0[0x100]; // size unknown
};
extern Unk8033F964 lbl_8033F964; // fonts
extern Unk8033FA38 lbl_8033FA38;
extern Unk803401C4 lbl_803401C4;
extern Unk80340AB8 lbl_80340AB8;
extern Unk8033F5C4 lbl_8033F5C4;

// Manager of the run-length encoded textures (ERRleTexture); defined in
// sims/Unk8003DE78.cpp. Its own name is unknown.
class Unk802E5E1C : public EResourceManager {
public:
    virtual EHeap* GetHeap();
    virtual EResource* AllocateAndLoadResource(EFile* file, unsigned int, unsigned int);
};
extern EStaticObject<Unk802E5E1C> lbl_802E5E1C;

#endif
