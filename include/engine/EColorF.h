#ifndef ENGINE_ECOLORF_H
#define ENGINE_ECOLORF_H

// RGBA colour as four floats; copied as words. The name is provisional.
struct EColorF {
    EColorF() {}
    EColorF(float r_, float g_, float b_, float a_) : r(r_), g(g_), b(b_), a(a_) {}
    explicit EColorF(float value) { r = g = b = a = value; }
    // User-defined (float by float), as for the vector classes; assignment is the compiler's.
    EColorF(const EColorF& other) : r(other.r), g(other.g), b(other.b), a(other.a) {}
    float r, g, b, a;
};

#endif
