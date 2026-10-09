#include "engine/e_storable.h"
#include "engine/e_resource.h"
#include "engine/e_rfont.h"
#include "engine/e_texture.h"
#include "engine/e_engine.h"
#include "sims/e_simsapp_title.h"
#include "engine/e_rdataset.h"
#include "engine/e_instance.h"
#include "engine/e_ilight.h"
#include "engine/e_ipointlight.h"
#include "engine/e_rlevel.h"
#include "engine/e_shader.h"
#include "engine/e_rshader.h"
#include "engine/e_rcharacter.h"
#include "engine/e_submodelshader.h"
#include "engine/e_submodel.h"
#include "engine/e_rmodel.h"
#include "engine/e_ranim.h"
#include "engine/e_igameinstance.h"
#include "engine/e_istaticmodel.h"
#include "sims/i_siminstance.h"
#include "sims/e_sim.h"
#include "sims/cas/CASState.h"

// 0x80008934
void CASState::fn_80008934() {
    unk4 = 0;
}

// 0x80008940
CASState::~CASState() {
}

// 0x80008968
void CASState::Startup(int arg) {
    unk8 = arg;
    unkC = 0;
    unk0 = 0;
    unk4 = new CASTarget;
    unk4->fn_8000D010();
    unk0 = 1;
}

// 0x800089D8
void CASState::Shutdown() {
    if (unk4 != 0) {
        delete unk4;
    }
    unk4 = 0;
}

// 0x80008A30
void CASState::fn_80008A30() {
    unk4->fn_8000F9D8();
}

// 0x80008A54
void CASState::Draw(ERC* rc) {
    if (unkC == 0) {
        unkC = 1;
    }
    unk4->vfn3(rc);
}
