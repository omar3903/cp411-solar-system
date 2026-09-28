/*
 * camera.hpp
 *
 *  Created on: Dec 1, 2024
 *      Author: Dylan
 */
#ifndef CAMERA_HPP
#define CAMERA_HPP

class Camera {
private:
    // Camera spherical coordinates for orbiting view
    float radius;      // Distance from origin
    float theta;       // Horizontal angle
    float phi;         // Vertical angle

    // Cartesian coordinates
    float posX, posY, posZ;

    // View center
    float centerX, centerY, centerZ;

    // Camera properties
    float zoomSpeed;
    float rotateSpeed;

    // Update Cartesian coordinates from spherical
    void updatePosition();

public:
    Camera();

    // Basic camera controls
    void zoom(float factor);     // Zoom in/out
    void rotate(float dTheta);   // Rotate horizontally
    void elevate(float dPhi);    // Change vertical angle

    // Reset camera to default position
    void reset();

    // Apply the view transformation
    void applyView();

    void setPosition(float x, float y, float z);
    void setPredefinedView(const float* position, const float* target);
    void lookAt(float x, float y, float z);
    void setUpVector(float x, float y, float z);

    // Getters for camera properties
    float getRadius() const { return radius; }
    float getTheta() const { return theta; }
    float getPhi() const { return phi; }
};

#endif
