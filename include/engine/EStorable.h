#ifndef ENGINE_ESTORABLE_H
#define ENGINE_ESTORABLE_H

// The engine's base classes for objects that can be created by name and read from
// a file. Class names come from the header strings every unit carries ("EStorable",
// "EResource") and from The Sims 2's symbol map; member names are not known.

void* fn_80169F1C(unsigned int size, int align); // aligned allocate
void fn_80169EE8(void* ptr);                     // free

struct EFile;
class EStorable;

// What is registered for each storable class (0x18 bytes).
struct EStorableClass {
    char unk0[0xC];
    int unkC;
    int unk10;
    unsigned short unk14;
};

// Registers a class (0x801BBFCC): the record, the three functions that create and
// destroy an instance, a flag, the class name and the parent's record.
int fn_801BBFCC(EStorableClass* info, EStorable* (*create)(), EStorable* (*createAt)(void*),
                void (*destroy)(EStorable*), int flag, const char* name, EStorableClass* parent);

// No data members and the first virtual: the vtable pointer is at offset 0.
class EStorable {
public:
    virtual void Delete();                    // slot 1
    virtual EStorableClass* GetClass();       // slot 2
    virtual int vfn3();                       // slot 3: the record's unkC
    virtual int vfn4();                       // slot 4: the record's unk10
    virtual unsigned short vfn5();            // slot 5: the record's unk14
    virtual ~EStorable();                     // slot 6
};

// 0x18 bytes (constructor 0x801766C0, destructor 0x80176720).
class EResource : public EStorable {
public:
    EResource();
    virtual ~EResource();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10(EFile& file);          // slot 10: read from a file
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();

    char unk4[0x14];
};
extern EStorableClass lbl_803794E0;           // EResource's record

// The members every storable class defines. The three functions that create and
// destroy an instance are friends defined in the class body (static members would
// not be emitted under -fno-implement-inlines); their names are passed in because
// the original's are unknown. They use the global operator new of engine/ENew.h,
// which a source file includes after its class headers.
void* operator new(unsigned int size);
void* operator new(unsigned int size, void* place);
#define E_STORABLE_BODY(Class, info, create, createAt, destroy)                         \
    friend EStorable* create() { return new Class; }                                    \
    friend EStorable* createAt(void* place) { return new (place) Class; }               \
    friend void destroy(EStorable* object) { ((Class*)object)->Class::~Class(); }       \
    virtual void Delete() { delete this; }                                              \
    virtual EStorableClass* GetClass() { return &info; }                                \
    virtual int vfn3() { return info.unkC; }                                            \
    virtual int vfn4() { return info.unk10; }                                           \
    virtual unsigned short vfn5() { return info.unk14; }                                \
    void operator delete(void* ptr) { fn_80169EE8(ptr); }

#endif
