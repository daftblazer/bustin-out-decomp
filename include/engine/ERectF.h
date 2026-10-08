#ifndef ENGINE_ERECTF_H
#define ENGINE_ERECTF_H

// Four floats built with one constructor call: used as a normalized viewport
// rectangle (0, 0, 1, 1). The real class name is unknown.
struct ERectF {
    float unk0, unk4, unk8, unkC;
    ERectF(float a, float b, float c, float d) : unk0(a), unk4(b), unk8(c), unkC(d) {}
    ERectF(const ERectF& other) : unk0(other.unk0), unk4(other.unk4), unk8(other.unk8), unkC(other.unkC) {}
    ERectF() {}
};

#endif
