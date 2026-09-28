//============================================================================
// Name        : SolarSystem.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <GL/glut.h>
#include <cstdio>
#include "solar.hpp"
#include "camera.hpp"
#include "menu.hpp"
#include "light.hpp"

// Global objects
Solar solarSystem;
Camera camera;
Light light;
extern bool sunlightEnabled; // Declare sunlight flag

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    camera.applyView(); // Apply camera transformation

    if (sunlightEnabled) {
        // Sunlight mode Light comes from the sun's position
        float sunX = 0.0f, sunY = 0.0f, sunZ = 0.0f; // Replace with sun's position
        light.setPosition(sunX, sunY, sunZ);
        light.enable(); // Enable sunlight
    } else {
        // Extremely bright global ambient light for non-sunlight mode
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);

        GLfloat brightAmbient[] = { 3.0f, 3.0f, 3.0f, 1.0f }; // Triple brightness because it was too dark
        glLightfv(GL_LIGHT0, GL_AMBIENT, brightAmbient);

        // Disable other lights to avoid interference
        glDisable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
    }

    solarSystem.draw(); // Render the solar system

    glutSwapBuffers();
}




void update(int value) {
    float deltaTime = 0.016f; // 60 FPS
    solarSystem.update(deltaTime);
    glutPostRedisplay();      // Mark the window for redrawing
    glutTimerFunc(16, update, 0);
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)width / (double)height, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void initOpenGL() {
    glEnable(GL_DEPTH_TEST); // Enable depth testing
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color

    camera.setPosition(0.0f, 0.0f, 10.0f); // Set initial camera position
    camera.lookAt(0.0f, 0.0f, 0.0f);       // Look at the origin
}

int main(int argc, char** argv) {
    printf("Initializing GLUT...\n");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    printf("Creating OpenGL context...\n");
    glutCreateWindow("Solar System Simulation");
    printf("OpenGL context created.\n");

    // Check OpenGL version
    const char* glVersion = (const char*)glGetString(GL_VERSION);
    if (glVersion) {
        printf("OpenGL Version: %s\n", glVersion);
    } else {
        printf("Error: OpenGL context not initialized.\n");
    }

    initOpenGL(); // Initialize OpenGL settings
    printf("OpenGL initialized.\n");

    // Initialize textures here
    solarSystem.initializeTextures();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(16, update, 0);
    glutKeyboardFunc(keyboardCallback); // Attach the keyboard callback

    Menu::create(); // Create the right-click menu

    glutMainLoop();
    return 0;
}

