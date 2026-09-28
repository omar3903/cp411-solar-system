/*
 * camera.cpp
 *
 *  Created on: Dec 1, 2024
 *      Author: Dylan
 */




#include "Vector.hpp"
#include <cmath>

Vector::Vector(float xVal, float yVal, float zVal) : x(xVal), y(yVal), z(zVal) {}

float Vector::magnitude() const {
    return sqrt(x * x + y * y + z * z);
}

Vector Vector::normalize() const {
    float mag = magnitude();
    return Vector(x / mag, y / mag, z / mag);
}

Vector Vector::cross(const Vector& other) const {
    return Vector(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    );
}
