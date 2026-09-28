/*
 * RGBpixmap.hpp
 *
 *  Created on: Dec 1, 2024
 *      Author: Dylan
 */

#ifndef RGBPIXMAP_HPP
#define RGBPIXMAP_HPP

#include <GL/glut.h>

class RGBpixmap {
private:
    int width, height;
    GLubyte* pixelData;

public:
    RGBpixmap();
    ~RGBpixmap();

    bool readBMPFile(const char* filename); // Load BMP file
    void setTexture(GLuint& textureID); // Bind data to OpenGL texture
};

#endif

