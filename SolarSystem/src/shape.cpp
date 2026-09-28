/*
 * camera.cpp
 *
 *  Created on: Dec 1, 2024
 *      Author: Dylan
 */



#include "Shape.hpp"

Shape::Shape() : x(0), y(0), z(0), r(1), g(1), b(1) {}

Shape::~Shape() {}

void Shape::setPosition(float newX, float newY, float newZ) {
    x = newX;
    y = newY;
    z = newZ;
}

void Shape::setColor(float red, float green, float blue) {
    r = red;
    g = green;
    b = blue;
}

