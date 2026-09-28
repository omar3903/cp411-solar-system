/*
 * camera.cpp
 *
 *  Created on: Dec 1, 2024
 *      Author: Dylan
 */




#include "RGBpixmap.hpp"
#include <cstdio>
#include <cstdlib>



RGBpixmap::RGBpixmap() : width(0), height(0), pixelData(NULL) {}

RGBpixmap::~RGBpixmap() {
    if (pixelData) {
        free(pixelData);
    }
}

bool RGBpixmap::readBMPFile(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Error: Unable to open BMP file: %s\n", filename);
        return false;
    }

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file);

    width = *(int*)&header[18];
    height = *(int*)&header[22];
    int dataSize = 3 * width * height;

    pixelData = (GLubyte*)malloc(dataSize);
    fread(pixelData, sizeof(GLubyte), dataSize, file);
    fclose(file);

    // Convert BGR to RGB
    for (int i = 0; i < dataSize; i += 3) {
        GLubyte temp = pixelData[i];         // Save blue channel
        pixelData[i] = pixelData[i + 2];    // Set blue to red
        pixelData[i + 2] = temp;            // Set red to blue
    }

    return true;
}




void RGBpixmap::setTexture(GLuint& textureID) {
    printf("Entering setTexture. OpenGL context info: %s\n", glGetString(GL_VERSION));
    const char* glVersion = (const char*)glGetString(GL_VERSION);
    if (glVersion == NULL) {
        printf("Error: OpenGL context is not initialized.\n");
        return;
    } else {
        printf("OpenGL version: %s\n", glVersion);
    }

    // Generate texture ID
    glGenTextures(1, &textureID);
    if (textureID == 0) {
        printf("Error: glGenTextures failed\n");
        return;
    }

    glBindTexture(GL_TEXTURE_2D, textureID);

    // Set texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

    // Use pixel data from BMP file
    if (pixelData == NULL || width <= 0 || height <= 0) {
        printf("Error: Invalid pixel data (Width: %d, Height: %d)\n", width, height);
        return;
    }
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, pixelData);

    // Check for OpenGL errors
    GLenum error = glGetError();
    if (error != GL_NO_ERROR) {
        printf("OpenGL Error in setTexture: %d\n", error);
    } else {
        printf("Texture ID: %u successfully created (Width: %d, Height: %d)\n", textureID, width, height);
    }
}
