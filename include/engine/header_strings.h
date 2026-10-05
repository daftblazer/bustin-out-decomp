#ifndef ENGINE_HEADER_STRINGS_H
#define ENGINE_HEADER_STRINGS_H

// The headers sims/ESimsApp.cpp includes, in its include order.
//
// GCC emits the string literals of inline functions even when the functions
// themselves are never emitted, so every unit's .rodata starts with the strings
// from the headers it included, in include order. Each header below is a
// stand-in that carries its original's strings; the __FILE__ strings give some
// of the names, and their "../../../engine/" prefix shows the game sources sat
// three directories below the source root (e.g. games/sims/ESrc/).

#include "engine/e_storable.h"
#include "engine/e_resource.h"
#include "engine/e_rfont.h"
#include "engine/e_texture.h"
#include "engine/e_shader.h"
#include "engine/e_rshader.h"
#include "engine/e_instance.h"
#include "engine/e_particle.h"
#include "engine/e_igameinstance.h"
#include "engine/e_iparticleemit.h"
#include "engine/e_rflash.h"
#include "engine/e_ilight.h"
#include "engine/e_rlevel.h"
#include "engine/e_rcharacter.h"
#include "engine/e_submodelshader.h"
#include "engine/e_submodel.h"
#include "engine/e_rmodel.h"
#include "engine/e_ranim.h"

#include "engine/e_istaticmodel.h"
#include "sims/i_siminstance.h"
#include "sims/e_sim.h"

#endif
