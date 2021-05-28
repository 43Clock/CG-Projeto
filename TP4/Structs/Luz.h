//
// Created by clock on 28/05/21.
//

#ifndef PROJETO_LUZ_H
#define PROJETO_LUZ_H

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

class Luz {

private:
    int tipo;
    float posicao[4];
    float direcao[3];
    float extras[2];

public:
    Luz(int tipo, float *pos);
    Luz(int tipo, float *pos, float * dir ,float *aux);
    void draw();
    
};


#endif //PROJETO_LUZ_H
