#ifndef ENGINE_EAPP_H
#define ENGINE_EAPP_H

// Engine application base classes. Names are provisional (no symbols on disc).

// Root application class (ctor at 0x801BE840). Introduces the vtable pointer,
// which GCC 2.95 places after its data members, at 0x338.
class EAppBase {
public:
    EAppBase();
    virtual ~EAppBase();                // slot 1

    char unk0[0x338];
};

// Engine application class (ctor 0x8015BE60, dtor 0x8015BEC4, vtable 0x802B82D0).
class EApp : public EAppBase {
public:
    EApp();
    virtual ~EApp();
    virtual void vfn2();
    virtual const char* vfn3();
    virtual const char* vfn4();
    virtual const char* GetBuildVersion();
    virtual const char* GetAppName();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual int GetEventTableSize();
    virtual void vfn17(int);
    virtual bool vfn18();
    virtual void vfn19(int);
    virtual void vfn20(int);
    virtual void SetGameState(int);
    virtual void vfn22();
    virtual void vfn23();
    virtual void Update();
    virtual void vfn25();
    virtual void vfn26();
    virtual void vfn27();
    virtual void Shutdown();            // slot 28

    void fn_8015C6D4(int);

    char unk33C[0x348 - 0x33C];
    int mArgc;      // 0x348
    char** mArgv;   // 0x34C
    char unk350[0x450 - 0x350];
    int unk450;
    char unk454[0x468 - 0x454];
    int unk468;
    char unk46C[0x478 - 0x46C];
};

#endif
