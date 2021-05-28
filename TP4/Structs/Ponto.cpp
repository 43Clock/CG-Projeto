//
// Created by clock on 07/03/21.
//

#include "Ponto.h"

Ponto::Ponto(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

float Ponto::getX() {
    return this->x;
}

float Ponto::getY() {
    return this->y;
}

float Ponto::getZ() {
    return this->z;
}

float *Ponto::getValues(){
    float *r = static_cast<float *>(malloc(sizeof(float) * 3));
    r[0] = x;
    r[1] = y;
    r[2] = z;
    return r;
}
