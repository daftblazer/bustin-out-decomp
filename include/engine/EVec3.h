#ifndef ENGINE_EVEC3_H
#define ENGINE_EVEC3_H

// Three-component vector. Class name from The Sims 2's symbol map.
class EVec3 {
public:
    EVec3() {}
    EVec3(float x_, float y_, float z_) : x(x_), y(y_), z(z_) {}
    // Copies go float by float in the original (lfs/stfs), not as words.
    EVec3(const EVec3& other) : x(other.x), y(other.y), z(other.z) {}
    EVec3& operator=(const EVec3& other) {
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    void Set(float x_, float y_, float z_) {
        x = x_;
        y = y_;
        z = z_;
    }

    float x, y, z;
};

#endif
