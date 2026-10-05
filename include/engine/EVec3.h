#ifndef ENGINE_EVEC3_H
#define ENGINE_EVEC3_H

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

#endif
