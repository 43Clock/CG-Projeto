//
// Created by clock on 08/03/21.
//

#include "sphere.h"

Ponto* shpere_texture(float alpha,float beta) {
    float du = (1.0 / (2.0*M_PI)) * (-alpha) + 1.0;
    float dy = (1.0 / (M_PI)) * (beta + (M_PI / 2.0));

    return new Ponto(1-du,dy,0);
}

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
            f->insereNormal(new Ponto(cos(beta_atual)*sin(alpha+division),sin(beta_atual),cos(beta_atual)*cos(alpha+division)));
            f->insereTextura(shpere_texture(alpha+division,beta_atual));

            f->inserePonto(new Ponto(raio*cos(beta_ant)*sin(alpha),raio*sin(beta_ant),raio*cos(beta_ant)*cos(alpha)));
            f->insereNormal(new Ponto(cos(beta_ant)*sin(alpha),sin(beta_ant),cos(beta_ant)*cos(alpha)));
            f->insereTextura(shpere_texture(alpha,beta_ant));

            f->inserePonto(new Ponto(raio*cos(beta_ant)*sin(alpha+division),raio*sin(beta_ant),raio*cos(beta_ant)*cos(alpha+division)));
            f->insereNormal(new Ponto(cos(beta_ant)*sin(alpha+division),sin(beta_ant),cos(beta_ant)*cos(alpha+division)));
            f->insereTextura(shpere_texture(alpha+division,beta_ant));



            f->inserePonto(new Ponto(raio * cos(beta_atual) * sin(alpha + division), raio * sin(beta_atual),raio * cos(beta_atual) * cos(alpha + division)));
            f->insereNormal(new Ponto(cos(beta_atual) * sin(alpha + division), sin(beta_atual),cos(beta_atual) * cos(alpha + division)));
            f->insereTextura(shpere_texture(alpha+division,beta_atual));

            f->inserePonto(new Ponto(raio * cos(beta_atual) * sin(alpha), raio * sin(beta_atual),raio * cos(beta_atual) * cos(alpha)));
            f->insereNormal(new Ponto(cos(beta_atual) * sin(alpha), sin(beta_atual),cos(beta_atual) * cos(alpha)));
            f->insereTextura(shpere_texture(alpha,beta_atual));

            f->inserePonto(new Ponto(raio * cos(beta_ant) * sin(alpha), raio * sin(beta_ant),raio * cos(beta_ant) * cos(alpha)));
            f->insereNormal(new Ponto(cos(beta_ant) * sin(alpha), sin(beta_ant),cos(beta_ant) * cos(alpha)));
            f->insereTextura(shpere_texture(alpha,beta_ant));

        }
        alpha+=division;
    }
    return f;
}