#ifndef ENGINE_EMAT4_H
#define ENGINE_EMAT4_H

#include <new>

#include "engine/EVec3.h"

// Four-component vector.
class EVec4 {
public:
    EVec4(float x_, float y_, float z_, float w_) : x(x_), y(y_), z(z_), w(w_) {}

    float x, y, z, w;
};

// 4x4 matrix, row-major with the translation in row 3. Class name from The
// Sims 2's symbol map.
class EMat4 {
public:
    // Overwrite the translation row (zeroed to transform a direction). The
    // original writes it through a constructed four-float object, which is why
    // the compiler does not fold the zeros into the following transform.
    void SetRow3(float x, float y, float z, float w) { new (m[3]) EVec4(x, y, z, w); }

    // Copy as eight 64-bit words; the window code copies matrices this way.
    void Copy64(const EMat4& other) {
        unsigned long long* dst = (unsigned long long*)this;
        const unsigned long long* src = (const unsigned long long*)&other;
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
        dst[3] = src[3];
        dst[4] = src[4];
        dst[5] = src[5];
        dst[6] = src[6];
        dst[7] = src[7];
    }
    void fn_801B2AFC();                              // set identity
    void fn_801B2888(const EMat4* a, const EMat4* b); // this = a concatenated with b
    void fn_801B3024(const EVec3& axis, float angle); // rotate about an axis
    void fn_801B3388(float angle);                   // rotate about Z
    void fn_801B2988(const EVec3& offset);           // translate
    void fn_801B3834(float fov, float aspect, float nearPlane, float farPlane); // perspective
    void fn_801B3494(const EVec3& scale);            // scale
    void fn_801B345C(const EVec3& offset);           // translate (other side)

    float m[4][4];
};

// Transform a point.
inline EVec3 operator*(const EVec3& v, const EMat4& mat) {
    return EVec3(v.x * mat.m[0][0] + v.y * mat.m[1][0] + v.z * mat.m[2][0] + mat.m[3][0],
                 v.x * mat.m[0][1] + v.y * mat.m[1][1] + v.z * mat.m[2][1] + mat.m[3][1],
                 v.x * mat.m[0][2] + v.y * mat.m[1][2] + v.z * mat.m[2][2] + mat.m[3][2]);
}

#endif
