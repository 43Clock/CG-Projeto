//
// Created by clock on 07/03/21.
//

#include "box.h"

Forma* box(float x,float y,float z,int div){
    Forma *f = new Forma();
    for (int i = 0; i < div; ++i) {
        for (int j = 0; j < div; ++j) {
            //Front Face
            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)i,y/2.0f-(y/(float)div)*(float)j,z/2.0f));
            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i+1),y/2.0f-(y/(float)div)*(float)(j+1),z/2.0f));
            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i),y/2.0f-(y/(float)div)*(float)(j+1),z/2.0f));

            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i),y/2.0f-(y/(float)div)*(float)(j),z/2.0f));
            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i+1),y/2.0f-(y/(float)div)*(float)(j),z/2.0f));
            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i+1),y/2.0f-(y/(float)div)*(float)(j+1),z/2.0f));

            //Back Face
            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)i,y/2.0f-(y/(float)div)*(float)j,-z/2.0f));
            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i),y/2.0f-(y/(float)div)*(float)(j+1),-z/2.0f));
            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i+1),y/2.0f-(y/(float)div)*(float)(j+1),-z/2.0f));

            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i),y/2.0f-(y/(float)div)*(float)(j),-z/2.0f));
            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i+1),y/2.0f-(y/(float)div)*(float)(j+1),-z/2.0f));
            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i+1),y/2.0f-(y/(float)div)*(float)(j),-z/2.0f));

            //Right Face
            f->inserePonto(new Ponto(x/2.0f,y/2.0f-(y/(float) div)*(float)(j),z/2.0f-(z/(float) div)*(float)(i)));
            f->inserePonto(new Ponto(x/2.0f,y/2.0f-(y/(float) div)*(float)(j+1),z/2.0f-(z/(float) div)*(float)(i)));
            f->inserePonto(new Ponto(x/2.0f,y/2.0f-(y/(float) div)*(float)(j+1),z/2.0f-(z/(float) div)*(float)(i+1)));

            f->inserePonto(new Ponto(x/2.0f,y/2.0f-(y/(float) div)*(float)(j),z/2.0f-(z/(float) div)*(float)(i)));
            f->inserePonto(new Ponto(x/2.0f,y/2.0f-(y/(float) div)*(float)(j+1),z/2.0f-(z/(float) div)*(float)(i+1)));
            f->inserePonto(new Ponto(x/2.0f,y/2.0f-(y/(float) div)*(float)(j),z/2.0f-(z/(float) div)*(float)(i+1)));

            //Left Face
            f->inserePonto(new Ponto(-x/2.0f,y/2.0f-(y/(float)div)*(float)(j),z/2.0f-(z/(float) div)*(float)(i)));
            f->inserePonto(new Ponto(-x/2.0f,y/2.0f-(y/(float) div)*(float)(j+1),z/2.0f-(z/(float) div)*(float)(i+1)));
            f->inserePonto(new Ponto(-x/2.0f,y/2.0f-(y/(float) div)*(float)(j+1),z/2.0f-(z/(float) div)*(float)(i)));

            f->inserePonto(new Ponto(-x/2.0f,y/2.0f-(y/(float) div)*(float)(j),z/2.0f-(z/(float) div)*(float)(i)));
            f->inserePonto(new Ponto(-x/2.0f,y/2.0f-(y/(float) div)*(float)(j),z/2.0f-(z/(float) div)*(float)(i+1)));
            f->inserePonto(new Ponto(-x/2.0f,y/2.0f-(y/(float) div)*(float)(j+1),z/2.0f-(z/(float) div)*(float)(i+1)));

            //Top Face
            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i),y/2.0f,z/2.0f-(z/(float) div)*(float)(j+1)));
            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i+1),y/2.0f,z/2.0f-(z/(float) div)*(float)(j)));
            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i),y/2.0f,z/2.0f-(z/(float) div)*(float)(j)));

            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i),y/2.0f,z/2.0f-(z/(float) div)*(float)(j+1)));
            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i+1),y/2.0f,z/2.0f-(z/(float) div)*(float)(j+1)));
            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i+1),y/2.0f,z/2.0f-(z/(float) div)*(float)(j)));

            //Down Face
            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i),-y/2.0f,z/2.0f-(z/(float) div)*(float)(j+1)));
            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i),-y/2.0f,z/2.0f-(z/(float) div)*(float)(j)));
            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i+1),-y/2.0f,z/2.0f-(z/(float) div)*(float)(j)));

            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i),-y/2.0f,z/2.0f-(z/(float) div)*(float)(j+1)));
            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i+1),-y/2.0f,z/2.0f-(z/(float) div)*(float)(j)));
            f->inserePonto(new Ponto(x/2.0f-(x/(float)div)*(float)(i+1),-y/2.0f,z/2.0f-(z/(float) div)*(float)(j+1)));

        }
    }

    /*
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
    f->inserePonto(new Ponto(-x/2.0f,0,-z/2.0f));*/

    return f;

}