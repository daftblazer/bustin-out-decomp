#ifndef ENGINE_ENEW_H
#define ENGINE_ENEW_H

// The global operator new of the units that define storable classes: 16-byte
// aligned, from the engine's heap. A unit gets its own local copy of each (the
// symbol is `__builtin_new`, like the runtime's), emitted after its inline virtual
// functions. Include this AFTER the class headers: the creation functions in the
// class bodies call these out of line, so they must not have been defined yet when
// those bodies are compiled. The header's real name is unknown.

void* fn_80169F1C(unsigned int size, int align);

inline void* operator new(unsigned int size) { return fn_80169F1C(size, 16); }
inline void* operator new(unsigned int, void* place) { return place; }

#endif
