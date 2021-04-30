//
// Created by clock on 07/03/21.
//

#ifndef PROJETO_FORMA_H
#define PROJETO_FORMA_H

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif
#include <vector>
#include "Ponto.h"
using namespace std;

class Forma {
    private:
        vector<Ponto*> pontos;
        GLuint buffer;

    public:
    void inserePonto(Ponto *p);
    vector<Ponto*> getPontos();

    int getSize();
};


#endif //PROJETO_FORMA_H
