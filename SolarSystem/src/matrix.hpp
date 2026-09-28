/*
 * camera.hpp
 *
 *  Created on: Dec 1, 2024
 *      Author: Dylan
 */

#ifndef MATRIX_HPP
#define MATRIX_HPP

class Matrix {
private:
    float mat[4][4]; // 4x4 matrix

public:
    Matrix(); // Constructor initializes to identity matrix
    void setIdentity();
    void translate(float x, float y, float z);
    void scale(float sx, float sy, float sz);
    void rotateY(float angleDegrees);
    const float* getMatrix() const; // For OpenGL functions
};

#endif

