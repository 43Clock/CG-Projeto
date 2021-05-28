//
// Created by clock on 07/03/21.
//

#include "plane.h"

Forma *plane(float size){
    Forma *f = new Forma();
    //Face de cima
    f->inserePonto(new Ponto(size/2.0f,0.0f,-size/2.0f));
    f->inserePonto(new Ponto(-size/2.0f,0.0f,size/2.0f));
    f->inserePonto(new Ponto(size/2.0f,0.0f,size/2.0f));
    f->insereNormal(new Ponto(0,1,0));
    f->insereNormal(new Ponto(0,1,0));
    f->insereNormal(new Ponto(0,1,0));
    f->insereTextura(new Ponto(1,1,0));
    f->insereTextura(new Ponto(0,0,0));
    f->insereTextura(new Ponto(1,0,0));

    f->inserePonto(new Ponto(size/2.0f,0.0f,-size/2.0f));
    f->inserePonto(new Ponto(-size/2.0f,0.0f,-size/2.0f));
    f->inserePonto(new Ponto(-size/2.0f,0.0f,size/2.0f));
    f->insereNormal(new Ponto(0,1,0));
    f->insereNormal(new Ponto(0,1,0));
    f->insereNormal(new Ponto(0,1,0));
    f->insereTextura(new Ponto(1,1,0));
    f->insereTextura(new Ponto(0,1,0));
    f->insereTextura(new Ponto(0,0,0));

    //Face de baixo
    f->inserePonto(new Ponto(size/2.0f,0.0f,-size/2.0f));
    f->inserePonto(new Ponto(size/2.0f,0.0f,size/2.0f));
    f->inserePonto(new Ponto(-size/2.0f,0.0f,size/2.0f));
    f->insereNormal(new Ponto(0,-1,0));
    f->insereNormal(new Ponto(0,-1,0));
    f->insereNormal(new Ponto(0,-1,0));
    f->insereTextura(new Ponto(1,1,0));
    f->insereTextura(new Ponto(1,0,0));
    f->insereTextura(new Ponto(0,0,0));

    f->inserePonto(new Ponto(size/2.0f,0.0f,-size/2.0f));
    f->inserePonto(new Ponto(-size/2.0f,0.0f,size/2.0f));
    f->inserePonto(new Ponto(-size/2.0f,0.0f,-size/2.0f));
    f->insereNormal(new Ponto(0,-1,0));
    f->insereNormal(new Ponto(0,-1,0));
    f->insereNormal(new Ponto(0,-1,0));
    f->insereTextura(new Ponto(1,1,0));
    f->insereTextura(new Ponto(0,0,0));
    f->insereTextura(new Ponto(0,1,0));
    return f;
}