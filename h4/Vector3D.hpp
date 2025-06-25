#pragma once

#include <cmath>

class Vector3D {
private:
    float _x, _y, _z;

public:
    Vector3D() : _x(0), _y(0), _z(0) {}
    Vector3D(float x, float y, float z) : _x(x), _y(y), _z(z) {}

    float x() const { return _x; }
    float y() const { return _y; }
    float z() const { return _z; }

    Vector3D operator+(const Vector3D& other) const {
        return Vector3D(_x + other._x, _y + other._y, _z + other._z);
    }

    Vector3D operator-(const Vector3D& other) const {
        return Vector3D(_x - other._x, _y - other._y, _z - other._z);
    }

    float dotProduct(const Vector3D& other) const {
        return _x * other._x + _y * other._y + _z * other._z;
    }

    Vector3D crossProduct(const Vector3D& other) const {
        return Vector3D(
            _y * other._z - _z * other._y,
            _z * other._x - _x * other._z,
            _x * other._y - _y * other._x
        );
    }

    float length() const {
        return std::sqrt(this->dotProduct(*this));
    }

    void normalize() {
        float len = length();
        if (len > 0.0f) {
            _x /= len;
            _y /= len;
            _z /= len;
        }
    }

    Vector3D getNormalized() const {
        float len = length();
        if (len == 0.0f) return *this;
        return Vector3D(_x / len, _y / len, _z / len);
    }
};
