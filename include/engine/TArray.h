#ifndef ENGINE_TARRAY_H
#define ENGINE_TARRAY_H

// Engine dynamic array. Names come from The Sims 2's symbol map
// (TArray<T, TArrayDefaultAllocator>::SetSize(int, int) etc.).

void* fn_80169F1C(unsigned int size, int align); // aligned allocate
void fn_80169EE8(void* ptr);                     // free

class TArrayDefaultAllocator {
public:
    static void* Allocate(unsigned int size) { return fn_80169F1C(size, 4); }
    static void Deallocate(void* ptr) { fn_80169EE8(ptr); }
};

template <class T, class Allocator = TArrayDefaultAllocator>
class TArray {
public:
    void Init();
    void SetSize(int size, int capacity);

    static void Construct(T* ptr, int count);
    static void Destruct(T* ptr, int count);
    static void Copy(T* dst, T* src, int count);

    T* mData;      // 0x0
    int mSize;     // 0x4
    int mCapacity; // 0x8
};

template <class T, class Allocator>
void TArray<T, Allocator>::Destruct(T* ptr, int count) {
    while (count--) {
        ptr->~T();
        ptr++;
    }
}

template <class T, class Allocator>
void TArray<T, Allocator>::Init() {
    mData = 0;
    mCapacity = 0;
    mSize = 0;
}

template <class T, class Allocator>
void TArray<T, Allocator>::Construct(T* ptr, int count) {
    while (count--) {
        new (ptr) T;
        ptr++;
    }
}

template <class T, class Allocator>
void TArray<T, Allocator>::Copy(T* dst, T* src, int count) {
    while (count--) {
        *dst++ = *src++;
    }
}

template <class T, class Allocator>
void TArray<T, Allocator>::SetSize(int size, int capacity) {
    if (capacity == 0) {
        capacity = size;
    }
    int oldSize = mSize;
    if (size < oldSize) {
        Destruct(mData + size, oldSize - size);
    }
    if (capacity == 0) {
        Allocator::Deallocate(mData);
        Init();
    } else {
        if (mCapacity != capacity) {
            T* data = (T*)Allocator::Allocate(capacity * sizeof(T));
            if (data == 0) {
                goto done;
            }
            if (mData) {
                int count = size;
                if (count > mSize) {
                    count = mSize;
                }
                Construct(data, count);
                Copy(data, mData, count);
                Destruct(mData, mSize);
                Allocator::Deallocate(mData);
            }
            mData = data;
            mCapacity = capacity;
        }
        mSize = size;
    }
done:
    if (size > oldSize) {
        Construct(mData + oldSize, size - oldSize);
    }
}

#endif
