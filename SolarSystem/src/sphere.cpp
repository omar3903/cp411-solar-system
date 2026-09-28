/*
 * camera.cpp
 *
 *  Created on: Dec 1, 2024
 *      Author: Dylan
 */

#include "Sphere.hpp"
#include <GL/glut.h>

// Persistent quadric object for spheres
static GLUquadric* quadric = NULL;

Sphere::Sphere(float size) : radius(size), x(0), y(0), z(0), r(1), g(1), b(1), textureID(0) {
    if (quadric == NULL) {
        quadric = gluNewQuadric();
        gluQuadricTexture(quadric, GL_TRUE); // Enable texture mapping
        gluQuadricNormals(quadric, GLU_SMOOTH); // Smooth normals for lighting
    }
}

void Sphere::setPosition(float newX, float newY, float newZ) {
    x = newX;
    y = newY;
    z = newZ;
}

void Sphere::setColor(float red, float green, float blue) {
    r = red;
    g = green;
    b = blue;
}

void Sphere::setTexture(GLuint texID) {
    textureID = texID;
}

float Sphere::getX() const { return x; }
float Sphere::getY() const { return y; }
float Sphere::getZ() const { return z; }

void Sphere::draw() const {
    glPushMatrix();
    glTranslatef(x, y, z); // Move to the sphere's position

    if (textureID > 0) {
        glEnable(GL_TEXTURE_2D); // Enable texturing
        glBindTexture(GL_TEXTURE_2D, textureID); // Bind the texture
        glColor3f(1.0, 1.0, 1.0); // Ensure no tinting
    } else {
        glColor3f(r, g, b); // Use fallback color
    }

    gluSphere(quadric, radius, 30, 30); // Draw the sphere

    if (textureID > 0) {
        glDisable(GL_TEXTURE_2D); // Disable texturing
    }

    glPopMatrix();
}
