//
// Created by clock on 31/03/21.
//

#include "torus.h"


Forma * torus(float r,float R,int slices,int stacks){
    Forma *f = new Forma();
    float division_slices = (float)(2*M_PI/slices);
    float division_stacks = (float)(2*M_PI/stacks);

    for (int i = 0; i < slices; ++i) {
        for (int j = 0; j < stacks; ++j) {
            f->inserePonto(new Ponto((R+r*cos(division_stacks*(j)))*cos(division_slices*(i+1)),r*sin(division_stacks*(j)),(R+r*cos(division_stacks*(j)))*sin(division_slices*(i+1))));
            f->inserePonto(new Ponto((R+r*cos(division_stacks*(j)))*cos(division_slices*(i)),r*sin(division_stacks*(j)),(R+r*cos(division_stacks*(j)))*sin(division_slices*(i))));
            f->inserePonto(new Ponto((R+r*cos(division_stacks*(j+1)))*cos(division_slices*(i)),r*sin(division_stacks*(j+1)),(R+r*cos(division_stacks*(j+1)))*sin(division_slices*(i))));
            f->inserePonto(new Ponto((R+r*cos(division_stacks*(j)))*cos(division_slices*(i+1)),r*sin(division_stacks*(j)),(R+r*cos(division_stacks*(j)))*sin(division_slices*(i+1))));
            f->inserePonto(new Ponto((R+r*cos(division_stacks*(j+1)))*cos(division_slices*(i)),r*sin(division_stacks*(j+1)),(R+r*cos(division_stacks*(j+1)))*sin(division_slices*(i))));
            f->inserePonto(new Ponto((R+r*cos(division_stacks*(j+1)))*cos(division_slices*(i+1)),r*sin(division_stacks*(j+1)),(R+r*cos(division_stacks*(j+1)))*sin(division_slices*(i+1))));

        }
    }
    return f;
}