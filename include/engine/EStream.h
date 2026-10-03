#ifndef ENGINE_ESTREAM_H
#define ENGINE_ESTREAM_H

#include "engine/TArray.h"

// Serialization stream. Class name from The Sims 2's symbol map; the virtual
// function names are provisional.
class EStream {
public:
    EStream();
    virtual ~EStream();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void Read(void* data, int size); // slot 5

    char unk0[0x18];
};

template <class T, class Allocator>
EStream& operator>>(EStream& stream, TArray<T, Allocator>& array) {
    int count;
    stream.Read(&count, sizeof(int));
    array.SetSize(count, 0);
    for (int i = 0; i < count; i++) {
        stream.Read(&array.mData[i], sizeof(T));
    }
    return stream;
}

#endif
