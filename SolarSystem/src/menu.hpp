/*
 * camera.hpp
 *
 *  Created on: Dec 1, 2024
 *      Author: Dylan
 */

#ifndef MENU_HPP
#define MENU_HPP

class Menu {
public:
    static void create();
    static void mainMenu(int option);
    static void speedMenuCallback(int option); // New callback for speed adjustment
    static void cameraMenuCallback(int option);
};

void keyboardCallback(unsigned char key, int x, int y);
extern bool mouseCameraControlEnabled;
extern bool sunlightEnabled;
extern bool cameraKeyboardControlEnabled; // Declare the global variable
void mouseControlSpeed(int x, int y);
void mouseButtonHandler(int button, int state, int x, int y);
void mouseMotionHandler(int x, int y);

#endif

