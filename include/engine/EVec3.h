#ifndef ENGINE_EVEC3_H
#define ENGINE_EVEC3_H

// Two-component vector. Class name from The Sims 2's symbol map.
class EVec2 {
public:
    EVec2() {}
    EVec2(float x_, float y_) : x(x_), y(y_) {}
    // User-defined, like EVec3's: this also keeps EVec2 locals in memory from
    // their declaration, which fixes their stack order.
    EVec2(const EVec2& other) : x(other.x), y(other.y) {}
    float x, y;
};

// Three-component vector. Class name from The Sims 2's symbol map.
inline EVec2 operator+(const EVec2& a, const EVec2& b) { return EVec2(a.x + b.x, a.y + b.y); }
inline EVec2 operator*(const EVec2& v, float scale) { return EVec2(v.x * scale, v.y * scale); }

class EVec3 {
public:
    EVec3() {}
    // All three components the same (stores z, then y, then x).
    explicit EVec3(float value) { x = y = z = value; }
    EVec3(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}
    // Copy construction goes float by float in the original (lfs/stfs), while
    // assignment copies words, i.e. the copy constructor is user-defined and
    // operator= is the compiler's.
    EVec3(const EVec3& other) : x(other.x), y(other.y), z(other.z) {}
    EVec3 operator*(float scale) const { return EVec3(x * scale, y * scale, z * scale); }

    EVec3 operator-() const { return EVec3(-x, -y, -z); }
    float& operator[](int index) { return (&x)[index]; }
    // (name invented) zeroes z, then y, then x, as the colour code's vectors are.
    void Zero() { z = 0.0f; y = 0.0f; x = 0.0f; }
    // Cross product.
    EVec3 Cross(const EVec3& other) const {
        return EVec3(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
    }
    float Dot(const EVec3& other) const;
    float Length() const;
    float LengthSquared() const;
    EVec3& Normalize();
    EVec3& operator+=(const EVec3& other) {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    EVec3& operator*=(float scale) {
        x *= scale;
        y *= scale;
        z *= scale;
        return *this;
    }

    void Set(float x_, float y_, float z_) {
        x = x_;
        y = y_;
        z = z_;
    }

    float x, y, z;
};

inline EVec3 operator+(const EVec3& a, const EVec3& b) { return EVec3(a.x + b.x, a.y + b.y, a.z + b.z); }
inline EVec3 operator-(const EVec3& a, const EVec3& b) { return EVec3(a.x - b.x, a.y - b.y, a.z - b.z); }
inline EVec3 operator*(float scale, const EVec3& v) { return EVec3(scale * v.x, scale * v.y, scale * v.z); }

// Single-precision arc cosine from the C library (0x8010DB14).
extern "C" float fn_8010DB14(float x);

// Absolute value as a macro: the original compares both signs explicitly, where an
// inline function would be turned into a single fabs instruction.
#define EABS(value) ((value) >= 0.0f ? (value) : -(value))

// Vector length. This is the Dolphin SDK's PSVECMag (0x80122240).
extern "C" float fn_80122240(const EVec3* v);

inline float EVec3::Length() const { return fn_80122240(this); }

// Squared length. This is the Dolphin SDK's PSVECSquareMag (0x80122228).
extern "C" float fn_80122228(const EVec3* v);

inline float EVec3::LengthSquared() const { return fn_80122228(this); }

// Dot product. This is the Dolphin SDK's PSVECDotProduct (0x80122284).
extern "C" float fn_80122284(const EVec3* a, const EVec3* b);
inline float EVec3::Dot(const EVec3& other) const { return fn_80122284(this, &other); }
// Degrees to radians. An inline function: the multiplication is not folded even
// for constant arguments.
inline float EDegToRad(float degrees) { return degrees * 0.017453292f; }
// Vector normalize. This is the Dolphin SDK's PSVECNormalize (0x801221E4).
extern "C" void fn_801221E4(const EVec3* src, EVec3* dst);

// Normalizes in place (unless zero) and returns itself.
inline EVec3& EVec3::Normalize() {
    if (x != 0.0f || y != 0.0f || z != 0.0f) {
        fn_801221E4(this, this);
    }
    return *this;
}

#endif
