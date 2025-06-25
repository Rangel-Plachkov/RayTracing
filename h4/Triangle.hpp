#pragma once

#include "Vector3D.hpp"

class Triangle3D {
private:
    Vector3D _v0, _v1, _v2;

public: 
    Triangle3D(const Vector3D& v0, const Vector3D& v1, const Vector3D& v2): _v0(v0), _v1(v1), _v2(v2) {}

    Vector3D v0() const { return _v0; }
    Vector3D v1() const { return _v1; }
    Vector3D v2() const { return _v2; }

    Vector3D normal() const {
        Vector3D edge1 = _v1 - _v0;
        Vector3D edge2 = _v2 - _v0;
        return edge1.crossProduct(edge2);
    }

};
