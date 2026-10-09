#include "engine/e_storable.h"
#include "engine/e_resource.h"
#include "engine/e_instance.h"
#include "engine/e_ilight.h"
#include "engine/e_ipointlight.h"
#include "engine/e_rlevel.h"
#include "engine/e_engine.h"
#include "engine/e_particle.h"
#include "engine/e_igameinstance.h"
#include "engine/e_iparticleemit.h"
#include "engine/e_rparticletype.h"
#include "engine/e_rfont.h"
#include "engine/e_texture.h"
#include "sims/Unk800052C8.h"

// 0x800052C8
Unk800052C8::Unk800052C8(unsigned int resourceId, Unk800053D4Owner* owner, Unk800052C8Source* source) {
    unk4 = source->unk0;
    unk10.Set(source->unk8, source->unkC, source->unk10);
    unk0 = owner;
    unkC = (Unk80340120Resource*)lbl_80340120.fn_80177628(resourceId, 0, 0);
    unk8 = new Unk8016BC18;
    lbl_802E67B0.unk0->unk1C->fn_80179D60(unk8, 0);
    unk8->fn_8016C750(unkC->unk4);
}

// 0x80005374
Unk800052C8::~Unk800052C8() {
    lbl_802E6700.fn_80068DE8(unkC, unk8);
    unkC = 0;
    unk8 = 0;
    unk0 = 0;
}

// 0x800053D4
void Unk800052C8::Update() {
    if (unk0->unk0->vfn88(0x22)) {
        unk8->fn_8016C944(0);
        return;
    }
    unk8->fn_8016C944(1);
    EMat4 mat;
    unk0->vfn37()->vfn35(unk4, &mat);
    EVec3 position = unk10;
    position = position * mat;
    unk8->fn_8016C878(&position, 0);
    EVec3 direction = unkC->unk2C;
    mat.SetRow3(0.0f, 0.0f, 0.0f, 0.0f);
    direction = direction * mat;
    unk8->SetUnkE4(direction);
}
