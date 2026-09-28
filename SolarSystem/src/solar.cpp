/*
 * camera.cpp
 *
 *  Created on: Dec 1, 2024
 *      Author: Dylan
 */


#include <cstdio>
#include "RGBpixmap.hpp"
#include "Solar.hpp"
#include <GL/glut.h>
#include <cmath>

GLuint sunTexture, mercuryTexture, venusTexture, earthTexture, moonTexture, marsTexture, jupiterTexture, saturnTexture, uranusTexture, neptuneTexture;

// Constants for orbital motion
const float MERCURY_ORBIT_RADIUS = 1.5f; // Mercury is closer to the Sun
const float VENUS_ORBIT_RADIUS = 2.5f;
const float EARTH_ORBIT_RADIUS = 4.0f;   // Adjust Earth's position to be farther out
const float MOON_ORBIT_RADIUS = 0.5f;
const float MARS_ORBIT_RADIUS = 5.5f;            // Mars's average orbital radius
const float JUPITER_ORBIT_RADIUS = 7.5f;         // Jupiter's average orbital radius
const float SATURN_ORBIT_RADIUS = 9.5f;          // Saturn's average orbital radius
const float URANUS_ORBIT_RADIUS = 11.5f;         // Uranus's average orbital radius
const float NEPTUNE_ORBIT_RADIUS = 13.5f;        // Neptune's average orbital radius

const float MERCURY_ORBIT_SPEED = 124.09f; // Mercury completes orbit in 88 Earth days
const float VENUS_ORBIT_SPEED = 48.0f;    // Venus completes orbit in 225 Earth days
const float EARTH_ORBIT_SPEED = 30.0f;            // Degrees per second
const float MOON_ORBIT_SPEED = 360.0f;             // Degrees per second
const float MARS_ORBIT_SPEED = 15.72f;      // Mars completes orbit in 687 Earth days
const float JUPITER_ORBIT_SPEED = 2.49f;  // Jupiter completes orbit in 4331 Earth days
const float SATURN_ORBIT_SPEED = 1.0f;  // Saturn completes orbit in 10747 Earth days
const float URANUS_ORBIT_SPEED = 0.35f;  // Uranus completes orbit in 30589 Earth days
const float NEPTUNE_ORBIT_SPEED = 0.18f; // Neptune completes orbit in 59800 Earth days

RGBpixmap pix[10]; // Expanded to include all planets

Solar::Solar() : showOrbitPaths(false), showNameTags(false){
    // Load textures
    pix[0].readBMPFile("textures/sun.bmp");
    pix[1].readBMPFile("textures/mercury.bmp");
    pix[4].readBMPFile("textures/venus.bmp");
    pix[2].readBMPFile("textures/earth.bmp");
    pix[3].readBMPFile("textures/moon.bmp");
    pix[4].readBMPFile("textures/mars.bmp");
    pix[5].readBMPFile("textures/jupiter.bmp");
    pix[6].readBMPFile("textures/saturn.bmp");
    pix[7].readBMPFile("textures/uranus.bmp");
    pix[8].readBMPFile("textures/neptune.bmp");


    // Set textures
    pix[0].setTexture(sunTexture);
    pix[1].setTexture(mercuryTexture);
    pix[2].setTexture(venusTexture);
    pix[3].setTexture(earthTexture);
    pix[4].setTexture(marsTexture);
    pix[5].setTexture(jupiterTexture);
    pix[6].setTexture(saturnTexture);
    pix[7].setTexture(uranusTexture);
    pix[8].setTexture(neptuneTexture);

    // Assign textures to the spheres
    sun = new Sphere(1.0f);
    sun->setTexture(sunTexture);

    mercury = new Sphere(0.2f); // Mercury is smaller than Earth
    mercury->setTexture(mercuryTexture);

    venus = new Sphere(0.45f); // Venus is slightly smaller than Earth
    venus->setTexture(venusTexture);

    earth = new Sphere(0.5f);
    earth->setTexture(earthTexture);

    moon = new Sphere(0.2f);
    moon->setTexture(moonTexture);

    mars = new Sphere(0.4f); // Mars is smaller than Earth but larger than Mercury
    mars->setTexture(marsTexture);

    jupiter = new Sphere(1.1f); // Jupiter is the largest planet
    jupiter->setTexture(jupiterTexture);

    saturn = new Sphere(1.0f); // Saturn is slightly smaller than Jupiter
    saturn->setTexture(saturnTexture);

    uranus = new Sphere(0.8f); // Uranus is smaller than Saturn
    uranus->setTexture(uranusTexture);

    neptune = new Sphere(0.8f); // Neptune is similar in size to Uranus
    neptune->setTexture(neptuneTexture);

}

Solar::~Solar() {
    delete sun;
    delete mercury; // Delete Mercury
    delete venus;
    delete earth;
    delete moon;
    delete mars;
    delete jupiter;
    delete saturn;
    delete uranus;
    delete neptune;
}

void Solar::update(float deltaTime) {
    // Update orbital angles with speed multiplier

    mercuryOrbitAngle += MERCURY_ORBIT_SPEED * deltaTime * speedMultiplier;
    venusOrbitAngle += VENUS_ORBIT_SPEED * deltaTime * speedMultiplier;
    earthOrbitAngle += EARTH_ORBIT_SPEED * deltaTime * speedMultiplier;
    moonOrbitAngle += MOON_ORBIT_SPEED * deltaTime * speedMultiplier;
    marsOrbitAngle += MARS_ORBIT_SPEED * deltaTime * speedMultiplier;
    jupiterOrbitAngle += JUPITER_ORBIT_SPEED * deltaTime * speedMultiplier;
    saturnOrbitAngle += SATURN_ORBIT_SPEED * deltaTime * speedMultiplier;
    uranusOrbitAngle += URANUS_ORBIT_SPEED * deltaTime * speedMultiplier;
    neptuneOrbitAngle += NEPTUNE_ORBIT_SPEED * deltaTime * speedMultiplier;

    // Convert degrees to radians for calculations
    float mercuryRad = mercuryOrbitAngle * M_PI / 180.0f;
    float venusRad = venusOrbitAngle * M_PI / 180.0f;
    float earthRad = earthOrbitAngle * M_PI / 180.0f;
    float moonRad = moonOrbitAngle * M_PI / 180.0f;
    float marsRad = marsOrbitAngle * M_PI / 180.0f;
    float jupiterRad = jupiterOrbitAngle * M_PI / 180.0f;
    float saturnRad = saturnOrbitAngle * M_PI / 180.0f;
    float uranusRad = uranusOrbitAngle * M_PI / 180.0f;
    float neptuneRad = neptuneOrbitAngle * M_PI / 180.0f;


    // Update Mercury position
    mercury->setPosition(MERCURY_ORBIT_RADIUS * cos(mercuryRad), 0.0f, MERCURY_ORBIT_RADIUS * sin(mercuryRad));

    venus->setPosition(VENUS_ORBIT_RADIUS * cos(venusRad), 0.0f, VENUS_ORBIT_RADIUS * sin(venusRad));

    // Update Earth position
    earth->setPosition(EARTH_ORBIT_RADIUS * cos(earthRad), 0.0f, EARTH_ORBIT_RADIUS * sin(earthRad));

    // Update Moon position relative to Earth
    float moonX = earth->getX() + (MOON_ORBIT_RADIUS * 1.5f) * cos(moonRad);
    float moonZ = earth->getZ() + (MOON_ORBIT_RADIUS * 1.5f) * sin(moonRad);
    moon->setPosition(moonX, 0.0f, moonZ);

    // Update Mars position
    mars->setPosition(MARS_ORBIT_RADIUS * cos(marsRad), 0.0f, MARS_ORBIT_RADIUS * sin(marsRad));

    // Update Jupiter position
    jupiter->setPosition(JUPITER_ORBIT_RADIUS * cos(jupiterRad), 0.0f, JUPITER_ORBIT_RADIUS * sin(jupiterRad));

    // Update Saturn position
    saturn->setPosition(SATURN_ORBIT_RADIUS * cos(saturnRad), 0.0f, SATURN_ORBIT_RADIUS * sin(saturnRad));

    // Update Uranus position
    uranus->setPosition(URANUS_ORBIT_RADIUS * cos(uranusRad), 0.0f, URANUS_ORBIT_RADIUS * sin(uranusRad));

    // Update Neptune position
    neptune->setPosition(NEPTUNE_ORBIT_RADIUS * cos(neptuneRad), 0.0f, NEPTUNE_ORBIT_RADIUS * sin(neptuneRad));
}

void Solar::draw() {
    // Make the sun emissive
    GLfloat sunEmission[] = { 1.0f, 1.0f, 0.0f, 1.0f }; // Bright yellow emission
    glMaterialfv(GL_FRONT, GL_EMISSION, sunEmission);

    sun->draw(); // Draw the sun

    // Disable emission for other objects
    GLfloat noEmission[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    glMaterialfv(GL_FRONT, GL_EMISSION, noEmission);

    // Draw orbit paths
    if (showOrbitPaths) {
        glColor3f(1.0f, 1.0f, 1.0f); // Set color for orbit paths
        drawOrbit(MERCURY_ORBIT_RADIUS);
        drawOrbit(VENUS_ORBIT_RADIUS);
        drawOrbit(EARTH_ORBIT_RADIUS);
        drawOrbit(MARS_ORBIT_RADIUS);
        drawOrbit(JUPITER_ORBIT_RADIUS);
        drawOrbit(SATURN_ORBIT_RADIUS);
        drawOrbit(URANUS_ORBIT_RADIUS);
        drawOrbit(NEPTUNE_ORBIT_RADIUS);
    }

    mercury->draw(); // Draw Mercury
    venus->draw();
    earth->draw();   // Draw the Earth
    moon->draw();    // Draw the Moon
    mars->draw();
    jupiter->draw();
    saturn->draw();
    uranus->draw();
    neptune->draw();

    // Draw name tags if enabled
    if (showNameTags) {
        drawText("Sun", 0.0f, 1.2f, 0.0f);
        drawText("Mercury", mercury->getX(), mercury->getY() + 0.5f, mercury->getZ());
        drawText("Venus", venus->getX(), venus->getY() + 0.5f, venus->getZ());
        drawText("Earth", earth->getX(), earth->getY() + 0.5f, earth->getZ());
        drawText("Moon", moon->getX(), moon->getY() + 0.5f, moon->getZ());
        drawText("Mars", mars->getX(), mars->getY() + 0.5f, mars->getZ());
        drawText("Jupiter", jupiter->getX(), jupiter->getY() + 1.5f, jupiter->getZ());
        drawText("Saturn", saturn->getX(), saturn->getY() + 1.5f, saturn->getZ());
        drawText("Uranus", uranus->getX(), uranus->getY() + 1.5f, uranus->getZ());
        drawText("Neptune", neptune->getX(), neptune->getY() + 1.5f, neptune->getZ());
    }
}

void Solar::initializeTextures() {
    printf("Initializing solar system textures...\n");

    // Load BMP files into pixmaps
    pix[0].readBMPFile("textures/sun.bmp");
    pix[1].readBMPFile("textures/mercury.bmp");
    pix[2].readBMPFile("textures/venus.bmp");
    pix[3].readBMPFile("textures/earth.bmp");
    pix[4].readBMPFile("textures/moon.bmp");
    pix[5].readBMPFile("textures/mars.bmp");
    pix[6].readBMPFile("textures/jupiter.bmp");
    pix[7].readBMPFile("textures/saturn.bmp");
    pix[8].readBMPFile("textures/uranus.bmp");
    pix[9].readBMPFile("textures/neptune.bmp");

    // Generate and bind texture IDs
    pix[0].setTexture(sunTexture);
    pix[1].setTexture(mercuryTexture);
    pix[2].setTexture(venusTexture);
    pix[3].setTexture(earthTexture);
    pix[4].setTexture(moonTexture);
    pix[5].setTexture(marsTexture);
    pix[6].setTexture(jupiterTexture);
    pix[7].setTexture(saturnTexture);
    pix[8].setTexture(uranusTexture);
    pix[9].setTexture(neptuneTexture);

    // Assign textures to spheres
    sun->setTexture(sunTexture);
    mercury->setTexture(mercuryTexture);
    venus->setTexture(venusTexture);
    earth->setTexture(earthTexture);
    moon->setTexture(moonTexture);
    mars->setTexture(marsTexture);
    jupiter->setTexture(jupiterTexture);
    saturn->setTexture(saturnTexture);
    uranus->setTexture(uranusTexture);
    neptune->setTexture(neptuneTexture);

    printf("Textures initialized.\n");
}

// Static member initialization
float Solar::speedMultiplier = 1.0f; // Default to normal speed

void Solar::setSpeedMultiplier(float multiplier) {
    speedMultiplier = multiplier;
    printf("Speed multiplier set to: %.2f\n", speedMultiplier);
}

float Solar::getSpeedMultiplier() {
    return speedMultiplier;
}

void Solar::drawOrbit(float radius) {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i += 5) { // Step through 360 degrees
        float theta = i * M_PI / 180.0f; // Convert degrees to radians
        float x = radius * cos(theta);  // X-coordinate
        float z = radius * sin(theta);  // Z-coordinate
        glVertex3f(x, 0.0f, z);
    }
    glEnd();
}

void Solar::drawText(const char* text, float x, float y, float z) {
    glRasterPos3f(x, y, z); // Set the position for the text
    for (const char* c = text; *c != '\0'; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c); // Draw each character
    }
}

