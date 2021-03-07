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

