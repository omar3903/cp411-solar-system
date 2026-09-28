/*
 * camera.cpp
 *
 *  Created on: Dec 1, 2024
 *      Author: Dylan
 */



#include "Light.hpp"
#include <GL/glut.h>

Light::Light() {
    // Default position and properties
    position[0] = 0.0f; position[1] = 5.0f; position[2] = 5.0f; position[3] = 1.0f;
    ambient[0] = 0.2f; ambient[1] = 0.2f; ambient[2] = 0.2f; ambient[3] = 1.0f;
    diffuse[0] = 0.8f; diffuse[1] = 0.8f; diffuse[2] = 0.8f; diffuse[3] = 1.0f;
    specular[0] = 1.0f; specular[1] = 1.0f; specular[2] = 1.0f; specular[3] = 1.0f;
}

void Light::setPosition(float x, float y, float z) {
    position[0] = x;
    position[1] = y;
    position[2] = z;
}

void Light::enable() const {
    glEnable(GL_LIGHTING);          // Enable lighting
    glEnable(GL_LIGHT0);            // Enable light
    glLightfv(GL_LIGHT0, GL_POSITION, position); // Set light position
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);   // Set ambient light
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);   // Set diffuse light
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular); // Set specular light
}

void Light::disable() const {
    glDisable(GL_LIGHT0);           // Disable light
    glDisable(GL_LIGHTING);         // Disable lighting
}

