//
// Created by clock on 07/03/21.
//

#include "box.h"

Forma* box(float x,float y,float z,int div){
    Forma *f = new Forma();

    //Front
    f->inserePonto(new Ponto(x/2.0f,y,z/2.0f));
    f->inserePonto(new Ponto(-x/2.0f,0,z/2.0f));
    f->inserePonto(new Ponto(x/2.0f,0,z/2.0f));

    f->inserePonto(new Ponto(x/2.0f,y,z/2.0f));
    f->inserePonto(new Ponto(-x/2.0f,y,z/2.0f));
    f->inserePonto(new Ponto(-x/2.0f,0,z/2.0f));

    //Right
    f->inserePonto(new Ponto(x/2.0f,y,-z/2.0f));
    f->inserePonto(new Ponto(x/2.0f,0,z/2.0f));
    f->inserePonto(new Ponto(x/2.0f,0,-z/2.0f));

    f->inserePonto(new Ponto(x/2.0f,y,-z/2.0f));
    f->inserePonto(new Ponto(x/2.0f,y,z/2.0f));
    f->inserePonto(new Ponto(x/2.0f,0,z/2.0f));

    //Back
    f->inserePonto(new Ponto(x/2.0f,y,-z/2.0f));
    f->inserePonto(new Ponto(x/2.0f,0,-z/2.0f));
    f->inserePonto(new Ponto(-x/2.0f,0,-z/2.0f));

    f->inserePonto(new Ponto(x/2.0f,y,-z/2.0f));
    f->inserePonto(new Ponto(-x/2.0f,0,-z/2.0f));
    f->inserePonto(new Ponto(-x/2.0f,y,-z/2.0f));

    //Left
    f->inserePonto(new Ponto(-x/2.0f,y,z/2.0f));
    f->inserePonto(new Ponto(-x/2.0f,0,-z/2.0f));
    f->inserePonto(new Ponto(-x/2.0f,0,z/2.0f));

    f->inserePonto(new Ponto(-x/2.0f,y,z/2.0f));
    f->inserePonto(new Ponto(-x/2.0f,y,-z/2.0f));
    f->inserePonto(new Ponto(-x/2.0f,0,-z/2.0f));

    //Top
    f->inserePonto(new Ponto(x/2.0f,y,-z/2.0f));
    f->inserePonto(new Ponto(-x/2.0f,y,z/2.0f));
    f->inserePonto(new Ponto(x/2.0f,y,z/2.0f));

    f->inserePonto(new Ponto(x/2.0f,y,-z/2.0f));
    f->inserePonto(new Ponto(-x/2.0f,y,-z/2.0f));
    f->inserePonto(new Ponto(-x/2.0f,y,z/2.0f));

    //Down
    f->inserePonto(new Ponto(x/2.0f,0,-z/2.0f));
    f->inserePonto(new Ponto(x/2.0f,0,z/2.0f));
    f->inserePonto(new Ponto(-x/2.0f,0,z/2.0f));

    f->inserePonto(new Ponto(x/2.0f,0,-z/2.0f));
    f->inserePonto(new Ponto(-x/2.0f,0,z/2.0f));
    f->inserePonto(new Ponto(-x/2.0f,0,-z/2.0f));

    return f;

}