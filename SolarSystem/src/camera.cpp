/*
 * camera.cpp
 *
 *  Created on: Dec 1, 2024
 *      Author: Dylan
 */



#include "Camera.hpp"
#include <GL/glut.h>
#include <cmath>
#include <cstdio> // For debug prints

// Predefined positions and target for optional views
const float TOP_VIEW_POSITION[3] = {0.0f, 10.0f, 0.0f};
const float SIDE_VIEW_POSITION[3] = {10.0f, 0.0f, 0.0f};
const float CENTER_VIEW[3] = {0.0f, 0.0f, 0.0f}; // Default look-at target

Camera::Camera() {
    // Initialize with default values
    radius = 15.0f;        // Initial distance from center
    theta = 0.0f;          // Initial horizontal angle
    phi = 45.0f;           // Initial vertical angle (45 degrees)

    centerX = 0.0f;        // Looking at origin
    centerY = 0.0f;
    centerZ = 0.0f;

    zoomSpeed = 0.1f;
    rotateSpeed = 2.0f;

    updatePosition();
}

void Camera::updatePosition() {
    // Convert spherical coordinates to Cartesian
    float phiRad = phi * M_PI / 180.0f;
    float thetaRad = theta * M_PI / 180.0f;

    posX = radius * cos(phiRad) * cos(thetaRad);
    posY = radius * sin(phiRad);
    posZ = radius * cos(phiRad) * sin(thetaRad);
}

void Camera::zoom(float factor) {
    // Adjust radius with zoom speed and constraints
    radius += factor * zoomSpeed;

    // Constrain zoom range
    if (radius < 5.0f) radius = 5.0f;       // Minimum zoom
    if (radius > 30.0f) radius = 30.0f;     // Maximum zoom

    updatePosition();
}

void Camera::rotate(float dTheta) {
    // Update horizontal angle
    theta += dTheta * rotateSpeed;

    // Keep theta in [0, 360] range
    while (theta >= 360.0f) theta -= 360.0f;
    while (theta < 0.0f) theta += 360.0f;

    updatePosition();
}

void Camera::elevate(float dPhi) {
    // Update vertical angle with constraints
    phi += dPhi * rotateSpeed;

    // Constrain vertical angle to prevent flipping
    if (phi > 89.0f) phi = 89.0f;
    if (phi < -89.0f) phi = -89.0f;

    updatePosition();
}

void Camera::reset() {
    // Reset to default viewing position
    radius = 15.0f;
    theta = 0.0f;
    phi = 45.0f;

    updatePosition();
}

void Camera::applyView() {
    // Apply the view transformation
    gluLookAt(posX, posY, posZ,        // Camera position
              centerX, centerY, centerZ, // Look at center
              0.0f, 1.0f, 0.0f);        // Up vector
}

void Camera::setPredefinedView(const float* position, const float* target) {
    setPosition(position[0], position[1], position[2]);
    lookAt(target[0], target[1], target[2]);
}

void Camera::setPosition(float x, float y, float z) {
    posX = x;
    posY = y;
    posZ = z;
    printf("Camera Position Updated: (%f, %f, %f)\n", posX, posY, posZ);
}

void Camera::lookAt(float x, float y, float z) {
    centerX = x;
    centerY = y;
    centerZ = z;
    printf("Camera Target Updated: (%f, %f, %f)\n", centerX, centerY, centerZ);
}


