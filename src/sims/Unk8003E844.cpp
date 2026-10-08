#include "sims/Unk8003E844.h"

// The kind of loader request this file uses (vtable 0x802987B8).
class Unk802987B8 : public Unk80298848 {
public:
    virtual int vfn2(int, int value) { return value; }
    virtual int vfn3(int, int value) { return value; }
    virtual int vfn4(int value) {
        unk4 = value;
        return value;
    }
    virtual int vfn5() { return unk4; }
    virtual int vfn6() { return 1; }
    virtual int vfn7() { return 0; }
    virtual int vfn8() { return 1; }
    virtual int vfn9() { return 0; }
    virtual int vfn10() { return 0; }
    virtual const char* vfn11() { return 0; }
    virtual const char* vfn12() { return 0; }
    virtual const char* vfn13() { return 0; }
    virtual const char* vfn14() { return 0; }
    virtual int vfn15() { return 0; }
    virtual void vfn16() {}
    int unk4;
};

#include "engine/e_storable.h"
#include "engine/e_instance.h"
#include "engine/e_igameinstance.h"
#include "engine/e_istaticmodel.h"
#include "engine/e_resource.h"
#include "engine/e_rcharacter.h"
#include "engine/e_rfont.h"
#include "engine/e_shader.h"
#include "engine/e_rshader.h"
#include "engine/e_texture.h"
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
#define EOR_BUILD_TIME "21:41:33"
#include "engine/e_engine.h"
#include "sims/e_sim.h"
#include "sims/e_simsapp_title.h"
#include <vector>
#include <algorithm>
#include "engine/EResourceManager.h"
#include "engine/EStaticObject.h"
#include "engine/Unk801C3E10.h"

// The manager that loads and unloads the resources of the objects on a lot
// (unit 0x8003E844). Its header strings name the object-model interfaces
// (ISimsObjectModel and others) between ISimInstance and the engine string.

struct EFile;
typedef std::vector<unsigned int> Unk8003E844Ids;

// A game object as this file sees it.
struct Unk8003E898Material {
    char unk0[0x44];
    unsigned int unk44;      // resource id
};
struct Unk8003E898Extra {
    char unk0[0x10];
    unsigned int unk10;      // resource id
};
struct Unk8003E898Definition {
    char unk0[0x14];
    short unk14;             // kind
    char unk16[0xC0 - 0x16];
    Unk8003E898Extra* unkC0;
};
struct Unk8003E898Object {
    char unk0[0x18];
    Unk8003E898Definition* unk18;
    char unk1C[0x34 - 0x1C];
    Unk8003E898Material* unk34;
    char unk38[0x78 - 0x38];
    int unk78;               // 1: its resources are wanted
    int unk7C;               // 1: its resources are loaded
    char unk80[0x550 - 0x80];
    int unk550;              // loads in progress
};
typedef std::vector<Unk8003E898Object*> Unk8003E844Objects;
int fn_80217FC4(Unk8003E898Object* object, Unk8003E898Object* other);
void fn_8005FB60(Unk8003E898Object* object, void* arg);

// The list of all objects (lbl_8037D988): slot 13 steps through it, slot 14 finds one.
struct Unk8037D988List {
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual Unk8003E898Object* vfn13(Unk8003E898Object* after);
    virtual Unk8003E898Object* vfn14(int id);
};
extern Unk8037D988List* lbl_8037D988;

struct Unk8033F5C4Manager : EResourceManager {
    char unkA4[0x100 - 0xA4];   // size unknown
};
extern Unk8033F5C4Manager lbl_8033F5C4;

// The lock every manager starts with (vtable pointer at offset 0): slot 2 takes it,
// slot 3 gives it back.
struct Unk8003F428Lock {
    virtual void vfn1();
    virtual void vfn2(int timeout);
    virtual void vfn3();
};
struct Unk8003F428Scope {
    Unk8003F428Scope(void* owner) : lock((Unk8003F428Lock*)owner) { lock->vfn2(-1); }
    ~Unk8003F428Scope() { lock->vfn3(); }
    Unk8003F428Lock* lock;
};

// The background loader (lbl_8037D1D0): slot 8 cancels, slot 11 queues a request.
struct Unk8037D1D0Loader {
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11(void* manager, int, void* kind, void* a, void* b, void* c, int);
};
extern Unk8037D1D0Loader* lbl_8037D1D0;
extern void* lbl_8037D94C;
void fn_801BE780(void* arg);

// The stream the object list is read from.
struct Unk802306D0 {
    void fn_802306D0(int* value, int count);
    void fn_80230530(short* value, int count);
    void fn_80230ACC(struct Unk801C3E10* text);
};

// The manager itself (0xBC bytes).
class Unk8003F178 : public EResourceManager {
public:
    Unk8003F178();
    virtual ~Unk8003F178();
    virtual int vfn6(EFile* file, void* arg);

    float fn_8003F210();
    void fn_8003F3B4(void* arg);
    void fn_8003F428();
    void fn_8003F498();
    void fn_8003F514(Unk8003E898Object* object, void* arg);
    void fn_8003F5AC(Unk8003E898Object* object);
    void fn_8003F62C(Unk8003E898Object* object);
    void fn_8003F6C0(Unk8003E898Object* object);
    void fn_8003F75C(Unk8003E898Object* object, void* arg);
    void fn_8003F818();

    int unkA4;                   // 0 idle, 1 loading the list, 2 loading one object
    int unkA8;                   // resources loaded so far
    int unkAC;                   // resources to load
    int unkB0;                   // how many loads are under way
    Unk8003E898Object* volatile unkB4;   // the object being loaded (read back after every store)
    Unk8003E844Ids* unkB8;       // the list being loaded
};

// The file as vfn6 gets it: slot 5 gives the object the data is for.
struct Unk8003F294File {
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual Unk8003E898Object* vfn5();
};

EStaticObject<Unk8003F178> lbl_802E5EC0;
static EStaticObject<Unk802987B8> lbl_8037CAB0;

// 0x8003E844
bool fn_8003E844(Unk8003E844Ids& ids, unsigned int id) {
    bool found = false;
    int count = ids.size();
    for (int i = 0; i < count; i++) {
        if (ids[i] == id) {
            found = true;
            break;
        }
    }
    return found;
}

// 0x8003E898
// Adds the resources of one object to a list, each once.
void fn_8003E898(Unk8003E898Object* object, Unk8003E844Ids& ids) {
    Unk8003E898Material* material = object->unk34;
    Unk8003E898Extra* extra = object->unk18->unkC0;
    if (material->unk44 != 0 && !fn_8003E844(ids, material->unk44)) {
        ids.push_back(material->unk44);
    }
    if (extra != 0 && extra->unk10 != 0 && !fn_8003E844(ids, extra->unk10)) {
        ids.push_back(extra->unk10);
    }
}

// 0x8003EB64
// Collects the resources an object needs. An object without its own extra data
// stands for every object of its kind that has some and belongs to it.
void fn_8003EB64(Unk8003E898Object* object, Unk8003E844Ids& ids, Unk8003E844Objects* objects) {
    if (object->unk18->unkC0 == 0) {
        Unk8037D988List* list = lbl_8037D988;
        short kind = object->unk18->unk14;
        for (Unk8003E898Object* other = list->vfn13(0); other != 0; other = list->vfn13(other)) {
            if (other->unk18->unk14 == kind && other->unk18->unkC0 != 0 && fn_80217FC4(other, object)) {
                fn_8003E898(other, ids);
                if (objects) {
                    objects->push_back(other);
                }
            }
        }
    } else {
        fn_8003E898(object, ids);
        if (objects) {
            objects->push_back(object);
        }
    }
}

// 0x8003EEB4
// Orders resource ids by where they are in the archive.
bool fn_8003EEB4(const unsigned int& a, const unsigned int& b) {
    unsigned int offsetA = 0;
    unsigned int sizeA;
    unsigned int offsetB = 0;
    unsigned int sizeB;
    Unk8033F5C4Manager* manager = &lbl_8033F5C4;
    manager->fn_80176F6C(a, offsetA, sizeA);
    manager->fn_80176F6C(b, offsetB, sizeB);
    return offsetA < offsetB;
}

// 0x8003EF2C
// Loads the resources in a list, in archive order; counts them when asked.
void fn_8003EF2C(Unk8003E844Ids& ids, int* loaded) {
    int count = ids.size();
    if (count != 0) {
        std::sort(ids.begin(), ids.end(), fn_8003EEB4);
        for (int i = 0; i < count; i++) {
            lbl_8033F5C4.fn_80177628(ids[i], 0, 0);
            if (loaded) {
                (*loaded)++;
            }
        }
    }
}

// 0x8003EFD0
// Releases the resources in a list.
void fn_8003EFD0(Unk8003E844Ids& ids) {
    int count = ids.size();
    for (int i = 0; i < count; i++) {
        lbl_8033F5C4.fn_801778B4(ids[i]);
    }
}

// 0x8003F038
// Reads the list of objects from a stream and collects their resources.
void fn_8003F038(Unk8003E844Ids* ids, Unk802306D0* stream, int version) {
    Unk801C3E10 name;
    short a;
    short b;
    int id;
    int unused1 = 0;
    int unused2 = 0;
    Unk8037D988List* list = lbl_8037D988;
    stream->fn_802306D0(&id, 1);
    while (id != 0) {
        if (version > 0) {
            stream->fn_802306D0(&unused1, 1);
            stream->fn_802306D0(&unused2, 1);
        }
        stream->fn_80230530(&a, 1);
        if (version > 1) {
            stream->fn_80230530(&b, 1);
        } else {
            b = -1;
        }
        stream->fn_80230ACC(&name);
        Unk8003E898Object* object = list->vfn14(id);
        if (object) {
            fn_8003EB64(object, *ids, 0);
        }
        stream->fn_802306D0(&id, 1);
    }
}

// 0x8003F178
Unk8003F178::Unk8003F178() {
    unkA4 = 0;
    unkA8 = 0;
    unkAC = 0;
    unkB0 = 0;
    unkB4 = 0;
    unkB8 = 0;
    *(int*)&unk0[0x5C] = 1;
}

// 0x8003F1D8
Unk8003F178::~Unk8003F178() {
    *(int*)&unk0[0x5C] = 0;
}

// 0x8003F210
// How far the load of the list has got, 0 to 1 (-1 when none is under way).
float Unk8003F178::fn_8003F210() {
    if (unkA4 != 1) {
        return -1.0f;
    }
    if (unkAC == 0) {
        return 0.0f;
    }
    return (float)unkA8 / (float)unkAC;
}

// 0x8003F294
// Called by the loader with the data it has read.
int Unk8003F178::vfn6(EFile* file, void* arg) {
    switch (unkA4) {
    case 1:
        fn_8003F3B4(arg);
        unkA4 = 0;
        break;
    case 2: {
        Unk8003E898Object* object = ((Unk8003F294File*)file)->vfn5();
        if (object == 0) {
            unkB4 = (Unk8003E898Object*)arg;
            if (unkB4->unk78 == 1) {
                fn_8003F6C0(unkB4);
            }
            unkB4 = object;
        } else {
            Unk8003E898Object* target = ((Unk8003F294File*)file)->vfn5();
            fn_8005FB60(target, arg);
            Unk8003F428Scope lock(this);
            target->unk550--;
        }
        fn_8003F498();
        break;
    }
    }
    return 0;
}

// Reading a tagged chunk of a file into something: the reader object hands the
// stream to the Read function for the target's type (fn_8003F038 for the id list).
// A template in the original (its instance sits with the sort templates).
struct Unk802316EC {
    virtual ~Unk802316EC();
    virtual void vfn2(Unk802306D0* stream, int version) = 0;
    virtual unsigned int vfn3() = 0;
};
template <class T>
class Unk80298748 : public Unk802316EC {
public:
    virtual void vfn2(Unk802306D0* stream, int version) { fn_8003F038(unk4, stream, version); }
    Unk80298748(T* target, unsigned int tag) : unk4(target), unk8(tag) {}
    virtual unsigned int vfn3() { return unk8; }
    T* unk4;
    unsigned int unk8;
};
struct Unk802314F0 {
    int fn_802314F0(Unk802316EC* reader, void* file);
    char unk0[8];
};
template <class T>
int fn_8003FF70(T* target, void* file, unsigned int tag, int, int) {
    Unk80298748<T> reader(target, tag);
    Unk802314F0 chunk;
    return chunk.fn_802314F0(&reader, file);
}

// 0x8003F3B4
void Unk8003F178::fn_8003F3B4(void* arg) {
    fn_8003FF70(unkB8, lbl_8037D94C, 0x6F626A74, 0, 0);
    unkAC = unkB8->size();
    fn_801BE780(arg);
    fn_8003EF2C(*unkB8, &unkA8);
}

// 0x8003F428
void Unk8003F178::fn_8003F428() {
    Unk8003F428Scope lock(this);
    unkB0++;
}

// 0x8003F498
void Unk8003F178::fn_8003F498() {
    Unk8003F428Scope lock(this);
    unkB0--;
    if (unkB0 == 0) {
        unkA4 = unkB0;
    }
}

// 0x8003F514
void Unk8003F178::fn_8003F514(Unk8003E898Object* object, void* arg) {
    object->unk78 = 1;
    if (unkA4 != 0 || object->unk7C != 1) {
        fn_8003F428();
        unkA4 = 2;
        lbl_8037D1D0->vfn11(this, 1, (Unk802987B8*)lbl_8037CAB0, 0, object, arg, 0);
    }
}

// 0x8003F5AC
void Unk8003F178::fn_8003F5AC(Unk8003E898Object* object) {
    object->unk78 = 0;
    if (unkA4 != 0 || object->unk7C != 0) {
        if (unkB4 == object) {
            lbl_8037D1D0->vfn8();
        }
        fn_8003F62C(object);
    }
}

// 0x8003F62C
void Unk8003F178::fn_8003F62C(Unk8003E898Object* object) {
    if (object->unk7C != 0) {
        Unk8003E844Ids ids;
        fn_8003EB64(object, ids, 0);
        fn_8003EFD0(ids);
        object->unk7C = 0;
    }
}

// 0x8003F6C0
void Unk8003F178::fn_8003F6C0(Unk8003E898Object* object) {
    if (object->unk7C != 1) {
        Unk8003E844Ids ids;
        fn_8003EB64(object, ids, 0);
        fn_8003EF2C(ids, 0);
        object->unk7C = 1;
    }
}

// 0x8003F75C
void Unk8003F178::fn_8003F75C(Unk8003E898Object* object, void* arg) {
    fn_8003F428();
    unkA4 = 2;
    {
        Unk8003F428Scope lock(this);
        object->unk550++;
    }
    lbl_8037D1D0->vfn11(this, 1, (Unk802987B8*)lbl_8037CAB0, object, arg, 0, 0);
}

// 0x8003F818
void Unk8003F178::fn_8003F818() {
    lbl_8037D1D0->vfn8();
}
