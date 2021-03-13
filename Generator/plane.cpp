//
// Created by clock on 07/03/21.
//

#include "plane.h"

Forma *plane(float size){
    Forma *f = new Forma();
    f->inserePonto(new Ponto(size/2.0f,0.0f,-size/2.0f));
    f->inserePonto(new Ponto(-size/2.0f,0.0f,size/2.0f));
    f->inserePonto(new Ponto(size/2.0f,0.0f,size/2.0f));

    f->inserePonto(new Ponto(size/2.0f,0.0f,-size/2.0f));
    f->inserePonto(new Ponto(-size/2.0f,0.0f,-size/2.0f));
    f->inserePonto(new Ponto(-size/2.0f,0.0f,size/2.0f));

    f->inserePonto(new Ponto(size/2.0f,0.0f,-size/2.0f));
    f->inserePonto(new Ponto(size/2.0f,0.0f,size/2.0f));
    f->inserePonto(new Ponto(-size/2.0f,0.0f,size/2.0f));

    f->inserePonto(new Ponto(size/2.0f,0.0f,-size/2.0f));
    f->inserePonto(new Ponto(-size/2.0f,0.0f,size/2.0f));
    f->inserePonto(new Ponto(-size/2.0f,0.0f,-size/2.0f));
    return f;
}