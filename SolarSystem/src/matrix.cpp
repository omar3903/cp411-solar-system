/*
 * camera.cpp
 *
 *  Created on: Dec 1, 2024
 *      Author: Dylan
 */




#include "Matrix.hpp"
#include <cmath>

Matrix::Matrix() {
    setIdentity();
}

void Matrix::setIdentity() {
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            mat[i][j] = (i == j) ? 1.0f : 0.0f;
}

void Matrix::translate(float x, float y, float z) {
    mat[0][3] += x;
    mat[1][3] += y;
    mat[2][3] += z;
}

void Matrix::scale(float sx, float sy, float sz) {
    mat[0][0] *= sx;
    mat[1][1] *= sy;
    mat[2][2] *= sz;
}

void Matrix::rotateY(float angleDegrees) {
    float radians = angleDegrees * 3.14159f / 180.0f;
    float cosA = cos(radians);
    float sinA = sin(radians);

    mat[0][0] = cosA;
    mat[0][2] = sinA;
    mat[2][0] = -sinA;
    mat[2][2] = cosA;
}

const float* Matrix::getMatrix() const {
    return &mat[0][0];
}
