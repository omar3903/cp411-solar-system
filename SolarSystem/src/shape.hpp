/*
 * camera.hpp
 *
 *  Created on: Dec 1, 2024
 *      Author: Dylan
 */

#ifndef SHAPE_HPP
#define SHAPE_HPP

class Shape {
protected:
    float x, y, z; // Position
    float r, g, b; // Color

public:
    Shape();
    virtual ~Shape();

    void setPosition(float newX, float newY, float newZ);
    void setColor(float red, float green, float blue);

    virtual void draw() const = 0; // Pure virtual function
};

#endif
