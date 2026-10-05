#ifndef ENGINE_HEADER_STRINGS_H
#define ENGINE_HEADER_STRINGS_H

// Stand-in for the engine headers the game's source files include.
//
// GCC emits the string literals of inline functions even when the functions
// themselves are never emitted, so every unit's .rodata starts with the strings
// from the headers it included, in include order. The original headers have not
// been fully reconstructed; the ones whose names are known (from their __FILE__
// strings) are real headers included below in the original order, and this file
// still carries the class-name strings whose headers are not identified. The __FILE__ strings give the original header names, and their
// "../../../engine/" prefix shows the game sources sat three directories below
// the source root (e.g. games/sims/ESrc/).

// class names (headers not identified)
inline const char* EngineHeaderString0() { return "EStorable"; }
inline const char* EngineHeaderString1() { return "EResource"; }
inline const char* EngineHeaderString2() { return "EFontCharacter"; }
inline const char* EngineHeaderString3() { return "EFontPage"; }
inline const char* EngineHeaderString4() { return "EFontSize"; }
inline const char* EngineHeaderString5() { return "EFontData"; }
inline const char* EngineHeaderString6() { return "ERFont"; }

#include "engine/e_texture.h"

#include "engine/e_shader.h"

#include "engine/e_rshader.h"

// class names (headers not identified)
inline const char* EngineHeaderString15() { return "EInstance"; }
inline const char* EngineHeaderString16() { return "EParticle"; }
inline const char* EngineHeaderString17() { return "EIGameInstance"; }
inline const char* EngineHeaderString18() { return "EIParticleEmit"; }
inline const char* EngineHeaderString19() { return "ERFlash"; }
inline const char* EngineHeaderString20() { return "EILight"; }
inline const char* EngineHeaderString21() { return "EIPointLight"; }
inline const char* EngineHeaderString22() { return "ERLevel"; }
inline const char* EngineHeaderString23() { return "ERCharacter"; }

#include "engine/e_submodelshader.h"

#include "engine/e_submodel.h"

#include "engine/e_rmodel.h"

#include "engine/e_ranim.h"

// class names (headers not identified)
inline const char* EngineHeaderString38() { return "N/A"; }
inline const char* EngineHeaderString39() { return "EIStaticModel"; }
inline const char* EngineHeaderString40() { return "ISimInstance"; }
inline const char* EngineHeaderString41() { return "ESim"; }

#endif
