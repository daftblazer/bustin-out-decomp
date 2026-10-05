#ifndef ENGINE_EVEC3_H
#define ENGINE_EVEC3_H

// Two-component vector. Class name from The Sims 2's symbol map.
class EVec2 {
public:
    float x, y;
};

// Three-component vector. Class name from The Sims 2's symbol map.
class EVec3 {
public:
    EVec3() {}
    EVec3(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}
    // Copy construction goes float by float in the original (lfs/stfs), while
    // assignment copies words, i.e. the copy constructor is user-defined and
    // operator= is the compiler's.
    EVec3(const EVec3& other) : x(other.x), y(other.y), z(other.z) {}
    EVec3 operator*(float scale) const { return EVec3(x * scale, y * scale, z * scale); }

    float Length() const;
    EVec3& Normalize();
    EVec3& operator+=(const EVec3& other) {
        x += other.x;
        y += other.y;
        z += other.z;
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

// Vector length. This is the Dolphin SDK's PSVECMag (0x80122240).
extern "C" float fn_80122240(const EVec3* v);

inline float EVec3::Length() const { return fn_80122240(this); }

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
