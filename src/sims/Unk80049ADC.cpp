#include "engine/e_storable.h"
#include "engine/e_instance.h"
#include "engine/e_ilight.h"
#include "engine/e_idirlight.h"
#include "engine/e_resource.h"
#include "engine/e_rfont.h"
#include "engine/e_texture.h"
#include "engine/e_ifloor.h"
#include "engine/e_igameinstance.h"
#include "engine/e_istaticmodel.h"
#include "engine/e_rcharacter.h"
#include "engine/e_shader.h"
#include "engine/e_rshader.h"
#include "engine/e_submodelshader.h"
#include "engine/e_submodel.h"
#include "engine/e_rmodel.h"
#include "engine/e_ranim.h"
#include "sims/i_siminstance.h"
#include "sims/i_simsobjectmodel.h"
#include "sims/i_simswallobjectmodel.h"
#include "sims/i_simsmultitileobjectmodel.h"
#include "sims/i_simscountertopobject.h"
#include "sims/i_shrubobject.h"
#define EOR_BUILD_TIME "21:41:35"
#include "engine/e_engine.h"
#include "engine/e_ipointlight.h"
#include "engine/e_rlevel.h"
#include "engine/e_iwallpart2.h"
#include "engine/e_ifencewall.h"
#include "engine/e_iamblight.h"
#include "engine/e_ipointamblight.h"
#include "sims/Unk80297B74.h"
#include "engine/e_particle.h"
#include "engine/e_iparticleemit.h"
#include "engine/e_rparticletype.h"
#include "engine/e_ispotlight.h"
#include "sims/EHouse.h"

// The level loader (third source file of the unit at 0x80044D84: 0x80049ADC to
// 0x8004BCBC, build time 21:41:35). It sets up a lot: the level objects, the lights,
// the particle effects and the house to load. IN PROGRESS: only the small functions are
// written. The names are unknown (The Sims 2's ERLevel is the engine's level class, not
// this one); the object is called after its constructor.

// 0x80049ADC
// The name of one of the sixteen houses (1 to 16; anything else gives the nearest).
const char* GetHouseNameText(int index) {
    const char* names[16] = {"house 01", "house 02", "house 03", "house 04", "house 05", "house 06",
                             "house 07", "house 08", "house 09", "house 10", "house 11", "house 12",
                             "house 13", "house 14", "house 15", "house 16"};
    int i = index - 1;
    if (i < 0) {
        i = 0;
    }
    if (i > 15) {
        i = 15;
    }
    return names[i];
}

// 0x80049B7C
const char* EHouse::GetHouseName() {
    return GetHouseNameText(unk3C);
}

// 0x80049D50
EHouse::~EHouse() {
    fn_8004ABB8();
}

// 0x80049DA4
void EHouse::Init() {
    BuildHouse();
    unk14 = 1;
}

// 0x80049DD8
// A callback the houses' objects are given; it never has anything to say.
int fn_80049DD8() {
    return 0;
}

// 0x8004A90C
void EHouse::fn_8004A90C() {
    unk110 = 0.0f;
}

// 0x8004B104
short fn_8004B104(int value) {
    return value;
}
