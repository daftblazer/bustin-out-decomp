#ifndef ENGINE_ESTATICOBJECT_H
#define ENGINE_ESTATICOBJECT_H

// A global object that is constructed at start-up and never destroyed.
//
// The original's static initialisers construct their global objects but have no
// branch that destroys them and no _GLOBAL_.D function, even for classes with a
// virtual destructor. No compiler flag or version available here does that for a
// plain `T object;` (the compiler always registers the destruction). Holding the
// object in the storage of a wrapper that has no destructor gives exactly the
// original's code, so that is how these globals are declared. The wrapper and its
// name are a reconstruction: nothing in the binary names it.

inline void* operator new(unsigned int, int* place) { return place; }

template <class T>
struct EStaticObject {
    EStaticObject() { new (storage) T; }
    T* operator->() { return (T*)storage; }
    T& operator*() { return *(T*)storage; }
    operator T*() { return (T*)storage; }

    int storage[(sizeof(T) + 3) / 4];
};

#endif
