#ifndef ENGINE_E_ENGINE_H
#define ENGINE_E_ENGINE_H

// Stand-in: the original header is not reconstructed. It only carries the strings
// that header's inline functions leave in every unit that includes it. The file
// name follows the engine's convention (class ERFoo -> e_rfoo.h) and is a guess.

inline const char* HeaderString_e_engine_0() { return "\\eor\\bin\\iop"; }
// The build time differs from unit to unit (the original used __TIME__), so a
// unit sets EOR_BUILD_TIME before including this header.
#ifndef EOR_BUILD_TIME
#define EOR_BUILD_TIME "21:41:12"
#endif
inline const char* HeaderString_e_engine_1() { return "EOR Engine v2.0 built " EOR_BUILD_TIME " Nov 13 2003 "; }
inline const char* HeaderString_e_engine_2() { return "Untitled"; }

#endif
