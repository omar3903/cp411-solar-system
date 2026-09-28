#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <GL/glut.h>

class Sphere {
private:
    float radius;
    float x, y, z; // Position
    float r, g, b; // Color
    GLuint textureID; // Texture ID for sphere

public:
    Sphere(float size);
    void setPosition(float newX, float newY, float newZ);
    void setColor(float red, float green, float blue);
    void setTexture(GLuint texID); // Method to bind texture
    float getX() const;
    float getY() const;
    float getZ() const;
    void draw() const; // Render sphere
};

#endif
