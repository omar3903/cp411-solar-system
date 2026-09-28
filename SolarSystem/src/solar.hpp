/*
 * camera.hpp
 *
 *  Created on: Dec 1, 2024
 *      Author: Dylan
 */


#ifndef SOLAR_HPP
#define SOLAR_HPP

#include "Sphere.hpp"
#include <vector>

class Solar {
private:
    Sphere* sun;
    Sphere* mercury;
    Sphere* venus;
    Sphere* earth;
    Sphere* moon;
    Sphere* mars;
    Sphere* jupiter;
    Sphere* saturn;
    Sphere* uranus;
    Sphere* neptune;

    float mercuryOrbitAngle;
    float venusOrbitAngle;
    float earthOrbitAngle;
    float moonOrbitAngle;
    float marsOrbitAngle;
    float jupiterOrbitAngle;
    float saturnOrbitAngle;
    float uranusOrbitAngle;
    float neptuneOrbitAngle;

    bool showOrbitPaths; // Default to not showing orbit paths
    bool showNameTags; // Default to not showing name tags
    static float speedMultiplier; // Speed multiplier for planetary rotation

public:
    Solar();
    ~Solar();

    void update(float deltaTime); // Update positions based on elapsed time
    void draw();                  // Render the solar system
    void initializeTextures();
    void drawOrbit(float radius);
    void drawText(const char* text, float x, float y, float z);
    void toggleNameTags() {
            showNameTags = !showNameTags;
    }
    void toggleOrbitPaths() {
            showOrbitPaths = !showOrbitPaths;
        }

    static void setSpeedMultiplier(float multiplier); // Adjust speed
    static float getSpeedMultiplier();               // Get current speed
};

#endif
