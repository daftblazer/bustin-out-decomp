#ifndef ENGINE_E3DWINDOW_H
#define ENGINE_E3DWINDOW_H

#include "engine/ERectF.h"
#include "engine/EVec3.h"

struct ERC;
void* fn_80169F1C(unsigned int size, int align); // aligned allocate
void fn_80169EE8(void* ptr);                     // free

// View window: projection and viewport. 0xA0 bytes, vtable pointer at 0x9C
// (ctor 0x8018ABB0, dtor 0x8018AC98, vtable 0x802BFF70). The class name comes
// from The Sims 2's symbol map (ESimsCam::SetWinPos(E3DWindow&)).
class E3DWindow {
public:
    E3DWindow();
    virtual ~E3DWindow();              // slot 1
    virtual void fn_8018B044(ERC* rc); // slot 2
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();

    void fn_8018B584(const ERectF& rect);
    void fn_80154490(float fov, float aspect, float nearPlane, float farPlane);
    void fn_801547E0(const ERectF& rect);
    void fn_80154798(const EVec3& eye, const EVec3& target, const EVec3& up); // look-at
    void fn_80156130(const EVec3& world, EVec2* screen); // project to screen

    // The window's rectangle on the screen (0x60 to 0x6C).
    float Left() const { return *(float*)&mWindowData[0x60]; }
    float Top() const { return *(float*)&mWindowData[0x64]; }
    float Right() const { return *(float*)&mWindowData[0x68]; }
    float Bottom() const { return *(float*)&mWindowData[0x6C]; }
    void SetBottom(float value) { *(float*)&mWindowData[0x6C] = value; }
    void* operator new(unsigned int size) { return fn_80169F1C(size, 16); }
    void operator delete(void* ptr) { fn_80169EE8(ptr); }

    char mWindowData[0x9C];
};

#endif
