//
// Created by clock on 29/03/21.
//

#include "Transformacao.h"

Transformacao::Transformacao(const string& s, float x, float y, float z,float angle) {
    this->tipo = s;
    this->x = x;
    this->y = y;
    this->z = z;
    this->angle = angle;
}

const string &Transformacao::getTipo() const {
    return tipo;
}

float Transformacao::getX() const {
    return x;
}

float Transformacao::getY() const {
    return y;
}

float Transformacao::getZ() const {
    return z;
}

float Transformacao::getAngle() const {
    return angle;
}
