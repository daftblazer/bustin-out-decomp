#ifndef ENGINE_HEADER_STRINGS_H
#define ENGINE_HEADER_STRINGS_H

// Stand-in for the engine headers the game's source files include.
//
// GCC emits the string literals of inline functions even when the functions
// themselves are never emitted, so every unit's .rodata starts with the strings
// from the headers it included, in include order. The original headers have not
// been reconstructed yet; until they are, this file carries their strings in the
// right order. The __FILE__ strings give the original header names, and their
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

// engine/e_texture.h
inline const char* EngineHeaderString7() { return "../../../engine/e_texture.h"; }
inline const char* EngineHeaderString8() { return "class ETexture operator new"; }
inline const char* EngineHeaderString9() { return "base test\n"; }

// engine/e_shader.h
inline const char* EngineHeaderString10() { return "../../../engine/e_shader.h"; }
inline const char* EngineHeaderString11() { return "EShader Update operator new"; }

// engine/e_rshader.h
inline const char* EngineHeaderString12() { return "ERShader"; }
inline const char* EngineHeaderString13() { return "../../../engine/e_rshader.h"; }
inline const char* EngineHeaderString14() { return "ERShader operator new"; }

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

// engine/e_submodelshader.h
inline const char* EngineHeaderString24() { return "../../../engine/e_submodelshader.h"; }
inline const char* EngineHeaderString25() { return "Model Strip Array SetSize"; }

// engine/e_submodel.h
inline const char* EngineHeaderString26() { return "../../../engine/e_submodel.h"; }
inline const char* EngineHeaderString27() { return "SubModel Shader Array SetSize"; }

// engine/e_rmodel.h
inline const char* EngineHeaderString28() { return "../../../engine/e_rmodel.h"; }
inline const char* EngineHeaderString29() { return "Sub Model Array SetSize"; }
inline const char* EngineHeaderString30() { return "ERModel"; }
inline const char* EngineHeaderString31() { return "ERModel operator new"; }

// engine/e_ranim.h
inline const char* EngineHeaderString32() { return "EAnimNodeDataPos"; }
inline const char* EngineHeaderString33() { return "../../../engine/e_ranim.h"; }
inline const char* EngineHeaderString34() { return "ERAnim TArray SetSize"; }
inline const char* EngineHeaderString35() { return "ERAnimBitArray SetSize"; }
inline const char* EngineHeaderString36() { return "ERAnim"; }
inline const char* EngineHeaderString37() { return "ERAnim operator new"; }

// class names (headers not identified)
inline const char* EngineHeaderString38() { return "N/A"; }
inline const char* EngineHeaderString39() { return "EIStaticModel"; }
inline const char* EngineHeaderString40() { return "ISimInstance"; }
inline const char* EngineHeaderString41() { return "ESim"; }

#endif
