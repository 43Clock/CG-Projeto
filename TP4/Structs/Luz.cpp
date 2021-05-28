//
// Created by clock on 28/05/21.
//

#include "Luz.h"

Luz::Luz(int tipo, float* pos) {
    this->tipo = tipo;
    this->posicao[0] = pos[0];
    this->posicao[1] = pos[1];
    this->posicao[2] = pos[2];
    this->posicao[3] = tipo == 0 ? 1.0 : 0.0;
}

Luz::Luz(int tipo, float *pos, float * dir ,float *aux) {
    this->tipo = tipo;
    this->posicao[0] = pos[0];
    this->posicao[1] = pos[1];
    this->posicao[2] = pos[2];
    this->posicao[3] = 1.0;

    this->direcao[0] = dir[0];
    this->direcao[1] = dir[1];
    this->direcao[2] = dir[2];

    this->extras[0] = aux[0];
    this->extras[1] = aux[1];
}

void Luz::draw() {

    GLfloat dark[4] = {0.2,0.2,0.2,1.0};
    GLfloat white[4] = {1.0,1.0,1.0,1.0};

    glLightfv(GL_LIGHT0, GL_POSITION, posicao);

    //light colors
    glLightfv(GL_LIGHT0, GL_AMBIENT, dark);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white);

    if (tipo == 2){
        glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, direcao);
        glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, extras[0]);
        glLightf(GL_LIGHT0,GL_SPOT_EXPONENT, extras[1]);
    }
}