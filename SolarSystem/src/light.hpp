/*
 * camera.hpp
 *
 *  Created on: Dec 1, 2024
 *      Author: Dylan
 */

#ifndef LIGHT_HPP
#define LIGHT_HPP

class Light {
private:
    float position[4];
    float ambient[4];
    float diffuse[4];
    float specular[4];

public:
    Light();
    void setPosition(float x, float y, float z);
    void enable() const;
    void disable() const;
};

#endif
