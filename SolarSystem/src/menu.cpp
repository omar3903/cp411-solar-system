/*
 * camera.cpp
 *
 *  Created on: Dec 1, 2024
 *      Author: Dylan
 */



#include <cstdio>
#include "Menu.hpp"
#include "Solar.hpp"
#include "Camera.hpp"
#include <GL/glut.h>

bool mouseCameraControlEnabled = false; // Global flag for mouse control
bool cameraKeyboardControlEnabled = false; // Default to keyboard control off
bool mouseSpeedControlEnabled = false; // Adjust speed with the mouse
bool sunlightEnabled = true; // Default to sunlight on
extern Solar solarSystem; // Reference to the solar system
extern Camera camera;     // Reference to the camera

void Menu::create() {
    // Create speed adjustment submenu
    int speedMenu = glutCreateMenu(speedMenuCallback);
    printf("Speed adjustment submenu created with ID: %d\n", speedMenu); // Debug print
    glutAddMenuEntry("0.5x", 1);
    glutAddMenuEntry("1.0x", 2);
    glutAddMenuEntry("5.0x", 3);
    glutAddMenuEntry("100.0x", 4);
    glutAddMenuEntry("Mouse-Controlled Speed", 5); // New option for mouse controlled speed

    // Create Camera submenu
    int cameraMenuID = glutCreateMenu(cameraMenuCallback);
    glutAddMenuEntry("Reset Camera", 1);
    glutAddMenuEntry("Top View", 2);
    glutAddMenuEntry("Side View", 3);
    glutAddMenuEntry("Keyboard Control Toggle", 4); // Toggle keyboard control
    glutAddMenuEntry("Mouse Control Toggle", 5); // New option for mouse control

    // Create main menu
    glutCreateMenu(mainMenu);
    printf("Main menu created.\n"); // Debug print
    glutAddMenuEntry("Reset Camera", 1);
    glutAddSubMenu("Camera", cameraMenuID); // Attach camera submenu
    glutAddSubMenu("Adjust Speed", speedMenu); // Attach speed submenu
    glutAddMenuEntry("Toggle Sunlight", 3); // New option to toggle sunlight
    glutAddMenuEntry("Toggle Name Tags", 4);
    glutAddMenuEntry("Toggle Orbit Paths", 5);
    glutAddMenuEntry("Quit", 2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    printf("Menus attached to right mouse button.\n"); // Debug print
}


void Menu::speedMenuCallback(int option) {
    printf("speedMenuCallback triggered with option: %d\n", option); // Debug print
    switch (option) {
        case 1: Solar::setSpeedMultiplier(0.5f); break;
        case 2: Solar::setSpeedMultiplier(1.0f); break;
        case 3: Solar::setSpeedMultiplier(5.0f); break;
        case 4: Solar::setSpeedMultiplier(100.0f); break;
        case 5:
            printf("Mouse-controlled speed adjustment enabled.\n");
            mouseSpeedControlEnabled = true; // Enable speed control
            mouseCameraControlEnabled = false; // Disable camera control
            glutMouseFunc(mouseButtonHandler); // Enable mouse button handler
            break;
        default:
            printf("Invalid speed menu option: %d\n", option);
            break;
    }
    glutPostRedisplay();
}


void Menu::mainMenu(int option) {
    switch (option) {
    case 1: // Reset camera
        camera.setPosition(0.0f, 0.0f, 10.0f);
        camera.lookAt(0.0f, 0.0f, 0.0f);
        break;
    case 2: // Quit application
        exit(0);
        break;
    case 3: // Toggle sunlight
        sunlightEnabled = !sunlightEnabled; // Toggle sunlight state
        printf("Sunlight toggled: %s\n", sunlightEnabled ? "ON" : "OFF");
        break;
    case 4: // Toggle name tags
        solarSystem.toggleNameTags();
        break;
    case 5: // Toggle
    	solarSystem.toggleOrbitPaths();
    	break;
    }
    glutPostRedisplay();
}

bool mouseAdjustingSpeed = false; // Global flag for mouse adjustment state

void mouseControlSpeed(int x, int y) {
    if (mouseAdjustingSpeed) {
        // Map mouse X-coordinate to a speed multiplier
        float newSpeed = (float)x / 100.0f; // Adjust scaling factor as needed
        if (newSpeed < 0.1f) newSpeed = 0.1f; // Clamp to minimum speed
        if (newSpeed > 5.0f) newSpeed = 5.0f; // Clamp to maximum speed

        Solar::setSpeedMultiplier(newSpeed);
        printf("Mouse-controlled speed set to: %.2f (Mouse X: %d)\n", newSpeed, x);
    }
}

void mouseMotionHandler(int x, int y) {
    static int lastX = -1, lastY = -1; // Track last mouse position

    if (!mouseCameraControlEnabled) return; // Do nothing if mouse control is disabled

    // Initialize last positions on first movement
    if (lastX == -1 || lastY == -1) {
        lastX = x;
        lastY = y;
        return;
    }

    int deltaX = x - lastX;
    int deltaY = y - lastY;

    // Adjust camera based on mouse movement
    camera.rotate(deltaX * 0.2f);   // Horizontal rotation
    camera.elevate(-deltaY * 0.2f); // Vertical elevation

    lastX = x;
    lastY = y;

    glutPostRedisplay(); // Request redraw
}

void mouseButtonHandler(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            if (mouseCameraControlEnabled) {
                printf("Mouse control for camera enabled.\n");
                glutMotionFunc(mouseMotionHandler); // Use motion for camera
            } else if (mouseSpeedControlEnabled) {
                printf("Mouse control for speed enabled.\n");
                mouseAdjustingSpeed = true; // Enable speed adjustment
                glutMotionFunc(mouseControlSpeed); // Use motion for speed
            }
        } else if (state == GLUT_UP) {
            printf("Left mouse button released.\n");
            mouseAdjustingSpeed = false; // Disable speed adjustment
            glutMotionFunc(NULL); // Stop motion tracking
        }
    }
}


void Menu::cameraMenuCallback(int option) {
    printf("Camera menu option selected: %d\n", option); // Debug print

    switch (option) {
        case 1: // Reset Camera
            camera.reset();
            cameraKeyboardControlEnabled = false; // Disable keyboard control
            mouseCameraControlEnabled = false;   // Disable mouse control
            glutMotionFunc(NULL); // Stop mouse tracking
            glutMouseFunc(NULL);
            break;
        case 2: // Top View
            camera.setPosition(0.0f, 20.0f, 0.1f);
            camera.lookAt(0.0f, 0.0f, 0.0f);
            cameraKeyboardControlEnabled = false;
            mouseCameraControlEnabled = false;
            glutMotionFunc(NULL);
            glutMouseFunc(NULL);
            break;
        case 3: // Side View
            camera.setPosition(10.0f, 0.0f, 0.0f);
            camera.lookAt(0.0f, 0.0f, 0.0f);
            cameraKeyboardControlEnabled = false;
            mouseCameraControlEnabled = false;
            glutMotionFunc(NULL);
            glutMouseFunc(NULL);
            break;
        case 4: // Toggle keyboard control
            cameraKeyboardControlEnabled = !cameraKeyboardControlEnabled;
            printf("Camera Keyboard Control %s\n", cameraKeyboardControlEnabled ? "Enabled" : "Disabled");
            break;
        case 5: // Toggle Mouse Control
            mouseCameraControlEnabled = !mouseCameraControlEnabled;
            mouseSpeedControlEnabled = false; // Disable speed control
            printf("Camera Mouse Control %s\n", mouseCameraControlEnabled ? "Enabled" : "Disabled");
            if (mouseCameraControlEnabled) {
                glutMotionFunc(mouseMotionHandler); // Enable mouse motion tracking
                glutMouseFunc(mouseButtonHandler); // Enable mouse button tracking
            } else {
                glutMotionFunc(NULL); // Disable mouse motion tracking
                glutMouseFunc(NULL);  // Disable mouse button tracking
            }
            break;
        default:
            printf("Unknown camera option: %d\n", option);
            break;
    }
    glutPostRedisplay();
}



// Handle keyboard input for camera controls
void keyboardCallback(unsigned char key, int x, int y) {
    if (!cameraKeyboardControlEnabled) return; // Ignore input if keyboard control is disabled

    switch (key) {
        case 'w': // Zoom in
            camera.zoom(-1.0f);
            break;
        case 's': // Zoom out
            camera.zoom(1.0f);
            break;
        case 'a': // Rotate left
            camera.rotate(-5.0f);
            break;
        case 'd': // Rotate right
            camera.rotate(5.0f);
            break;
        case 'q': // Elevate up
            camera.elevate(5.0f);
            break;
        case 'e': // Elevate down
            camera.elevate(-5.0f);
            break;
        case 'r':
            camera.reset();
            break;
        default:
            printf("Unrecognized key: %c\n", key);
            break;
    }
    glutPostRedisplay(); // Redraw the scene
}
