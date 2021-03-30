//
// Created by clock on 08/03/21.
//

#include "sphere.h"

Forma* sphere(float raio,int slices, int stacks){
    Forma *f= new Forma();
    float beta = -M_PI/2;
    float alpha = 0.0f;
    float division = (float)M_PI*2/(float)slices;
    for (int i = 0; i < slices; ++i) {
        for (int j = 0; j < stacks; ++j) {
            float beta_atual = (float) (beta + ((float)M_PI/(float)stacks)*(float)(j+1));
            float beta_ant = (float) (beta + ((float)M_PI/(float)stacks)*(float)j);

            f->inserePonto(new Ponto(raio*cos(beta_atual)*sin(alpha+division),raio*sin(beta_atual),raio*cos(beta_atual)*cos(alpha+division)));
            f->inserePonto(new Ponto(raio*cos(beta_ant)*sin(alpha),raio*sin(beta_ant),raio*cos(beta_ant)*cos(alpha)));
            f->inserePonto(new Ponto(raio*cos(beta_ant)*sin(alpha+division),raio*sin(beta_ant),raio*cos(beta_ant)*cos(alpha+division)));

            f->inserePonto(new Ponto(raio * cos(beta_atual) * sin(alpha + division), raio * sin(beta_atual),raio * cos(beta_atual) * cos(alpha + division)));
            f->inserePonto(new Ponto(raio * cos(beta_atual) * sin(alpha), raio * sin(beta_atual),raio * cos(beta_atual) * cos(alpha)));
            f->inserePonto(new Ponto(raio * cos(beta_ant) * sin(alpha), raio * sin(beta_ant),raio * cos(beta_ant) * cos(alpha)));

        }
        alpha+=division;
    }
    return f;
}