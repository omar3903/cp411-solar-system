/*
 * camera.hpp
 *
 *  Created on: Dec 1, 2024
 *      Author: Dylan
 */

#ifndef VECTOR_HPP
#define VECTOR_HPP

class Vector {
public:
    float x, y, z;

    Vector(float xVal = 0.0f, float yVal = 0.0f, float zVal = 0.0f);
    float magnitude() const;
    Vector normalize() const;
    Vector cross(const Vector& other) const;
};

#endif
