//
// Created by clock on 08/03/21.
//

#include "cone.h"


Forma *cone(float raio,float altura, int slices,int stacks){
    float angle = 0.0f;
    float division = (float)M_PI*2/(float)slices;
    float hip = sqrt(raio * raio + altura * altura);
    Forma *f = new Forma();
    for(int i = 0;i<slices;i++) {
        f->inserePonto(new Ponto(0.0f,0.0f,0.0f));
        f->insereNormal(new Ponto(0.0f,-1.0f,0.0f));
        f->insereTextura(new Ponto(0.0f,0.0f,0.0f));

        f->inserePonto(new Ponto(raio*sin(angle+division),0.0f,raio*cos(angle+division)));
        f->insereNormal(new Ponto(0.0f,-1.0f,0.0f));
        f->insereTextura(new Ponto(0.0f,0.0f,0.0f));

        f->inserePonto(new Ponto(raio*sin(angle),0.0f,raio*cos(angle)));
        f->insereNormal(new Ponto(0.0f,-1.0f,0.0f));
        f->insereTextura(new Ponto(0.0f,0.0f,0.0f));

        for(int j = 0;j<stacks;j++){
            float raio_atual = raio - (float) ((raio / (float) stacks) * (float) (j + 1));
            float raio_ant = raio - (float) ((raio / (float) stacks) * (float) (j));
            float altura_atual = (float) ((altura / (float) stacks) * (float) (j+1));
            float altura_ant = (float) ((altura / (float) stacks) * (float) (j));
            if(j!=stacks-1) {
                f->inserePonto(new Ponto(raio_atual * sin(angle + division),altura_atual,raio_atual * cos(angle + division)));
                f->insereNormal(new Ponto(raio_atual * sin(angle + division),altura_atual,raio_atual * cos(angle + division)));
                f->insereTextura(new Ponto(0.0f,0.0f,0.0f));

                f->inserePonto(new Ponto(raio_ant * sin(angle),altura_ant,raio_ant * cos(angle)));
                f->insereNormal(new Ponto(raio_ant * sin(angle),altura_ant,raio_ant * cos(angle)));
                f->insereTextura(new Ponto(0.0f,0.0f,0.0f));

                f->inserePonto(new Ponto(raio_ant * sin(angle + division),altura_ant,raio_ant * cos(angle + division)));
                f->insereNormal(new Ponto(raio_ant * sin(angle + division),altura_ant,raio_ant * cos(angle + division)));
                f->insereTextura(new Ponto(0.0f,0.0f,0.0f));


                f->inserePonto(new Ponto(raio_atual * sin(angle + division),altura_atual,raio_atual * cos(angle + division)));
                f->insereNormal(new Ponto(raio_atual * sin(angle + division),altura_atual,raio_atual * cos(angle + division)));
                f->insereTextura(new Ponto(0.0f,0.0f,0.0f));

                f->inserePonto(new Ponto(raio_atual * sin(angle),altura_atual,raio_atual * cos(angle)));
                f->insereNormal(new Ponto(raio_atual * sin(angle),altura_atual,raio_atual * cos(angle)));
                f->insereTextura(new Ponto(0.0f,0.0f,0.0f));

                f->inserePonto(new Ponto(raio_ant * sin(angle),altura_ant,raio_ant * cos(angle)));
                f->insereNormal(new Ponto(raio_ant * sin(angle),altura_ant,raio_ant * cos(angle)));
                f->insereTextura(new Ponto(0.0f,0.0f,0.0f));
            } else{
                f->inserePonto(new Ponto(raio_atual * sin(angle + division),altura_atual,raio_atual * cos(angle + division)));
                f->insereNormal(new Ponto(raio_atual * sin(angle + division),altura_atual,raio_atual * cos(angle + division)));
                f->insereTextura(new Ponto(0.0f,0.0f,0.0f));

                f->inserePonto(new Ponto(raio_ant * sin(angle),altura_ant,raio_ant * cos(angle)));
                f->insereNormal(new Ponto(raio_ant * sin(angle),altura_ant,raio_ant * cos(angle)));
                f->insereTextura(new Ponto(0.0f,0.0f,0.0f));

                f->inserePonto(new Ponto(raio_ant * sin(angle + division),altura_ant,raio_ant * cos(angle + division)));
                f->insereNormal(new Ponto(raio_ant * sin(angle + division),altura_ant,raio_ant * cos(angle + division)));
                f->insereTextura(new Ponto(0.0f,0.0f,0.0f));
            }
        }
        angle += division;
    }
    return f;
}