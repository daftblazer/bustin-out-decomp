#ifndef ENGINE_ERESOURCEMANAGER_H
#define ENGINE_ERESOURCEMANAGER_H

// Base of the resource managers (0xA4 bytes, vtable pointer at 0xA0). The class name
// and the names GetHeap and AllocateAndLoadResource are from The Sims 2's symbol map
// (EResourceManager, ETextureManager::GetHeap, ETextureManager::AllocateAndLoadResource);
// the other members keep their addresses until they are decompiled.

struct EFile;
struct EHeap;
class EResource;

class EResourceManager {
public:
    EResourceManager();                                   // 0x80176AEC
    void Shutdown();
    void* fn_80177628(unsigned int id, int, int);         // look up / load a resource by id
    void* fn_80177EBC(unsigned int size, const char* file, int line, const char* name);   // allocate
    void fn_80177FE0(void* block);                        // free
    int fn_80176F6C(unsigned int id, unsigned int& offset, unsigned int& size);   // look up an id
    void fn_801778B4(unsigned int id);                    // drop a reference by id

    char unk0[0xA0];

    virtual ~EResourceManager();                          // 0x80176B64
    virtual void fn_80176C78(const char* name, int count);
    virtual void fn_80176BF4();
    virtual EHeap* GetHeap();                             // 0x80177D10
    virtual void vfn5();
    virtual int vfn6(EFile* file, void* arg);             // 0x80177C5C
    virtual EResource* AllocateAndLoadResource(EFile* file, unsigned int, unsigned int);   // 0x80177C30
};

#endif
