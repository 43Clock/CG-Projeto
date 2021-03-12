//
// Created by clock on 08/03/21.
//

#include "cone.h"


Forma *cone(float raio,float altura, int slices,int stacks){
    float angle = 0.0f;
    float division = (float)M_PI*2/(float)slices;
    Forma *f = new Forma();
    for(int i = 0;i<slices;i++) {
        f->inserePonto(new Ponto(0.0f,0.0f,0.0f));
        f->inserePonto(new Ponto(raio*sin(angle+division),0.0f,raio*cos(angle+division)));
        f->inserePonto(new Ponto(raio*sin(angle),0.0f,raio*cos(angle)));
        for(int j = 0;j<stacks;j++){
            if(j!=stacks-1) {
                f->inserePonto(new Ponto((raio - (float) ((raio / (float) stacks) * (float) (j + 1))) * sin(angle + division),
                                            (float) ((altura / (float) stacks) * (float) (j + 1)),
                                            (raio - (float) ((raio / (float) stacks) * (float) (j + 1))) * cos(angle + division)));
                f->inserePonto(new Ponto((raio - (float) ((raio / (float) stacks) * (float) (j))) * sin(angle),
                                            (float) ((altura / (float) stacks) * (float) (j)),
                                            (raio - (float) ((raio / (float) stacks) * (float) (j))) * cos(angle)));
                f->inserePonto(new Ponto((raio - (float) ((raio / (float) stacks) * (float) (j))) * sin(angle + division),
                                            (float) ((altura / (float) stacks) * (float) (j)),
                                            (raio - (float) ((raio / (float) stacks) * (float) (j))) * cos(angle + division)));


                f->inserePonto(new Ponto((raio - (float) ((raio / (float) stacks) * (float) (j + 1))) * sin(angle + division),
                                            (float) ((altura / (float) stacks) * (float) (j + 1)),
                                            (raio - (float) ((raio / (float) stacks) * (float) (j + 1))) * cos(angle + division)));
                f->inserePonto(new Ponto((raio - (float) ((raio / (float) stacks) * (float) (j + 1))) * sin(angle),
                                            (float) ((altura / (float) stacks) * (float) (j + 1)),
                                            (raio - (float) ((raio / (float) stacks) * (float) (j + 1))) * cos(angle)));
                f->inserePonto(new Ponto((raio - (float) ((raio / (float) stacks) * (float) (j))) * sin(angle),
                                            (float) ((altura / (float) stacks) * (float) (j)),
                                            (raio - (float) ((raio / (float) stacks) * (float) (j))) * cos(angle)));
            } else{
                f->inserePonto(new Ponto((raio - (float) ((raio / (float) stacks) * (float) (j + 1))) * sin(angle + division),
                                            (float) ((altura / (float) stacks) * (float) (j + 1)),
                                            (raio - (float) ((raio / (float) stacks) * (float) (j + 1))) * cos(angle + division)));
                f->inserePonto(new Ponto((raio - (float) ((raio / (float) stacks) * (float) (j))) * sin(angle),
                                            (float) ((altura / (float) stacks) * (float) (j)),
                                            (raio - (float) ((raio / (float) stacks) * (float) (j))) * cos(angle)));
                f->inserePonto(new Ponto((raio - (float) ((raio / (float) stacks) * (float) (j))) * sin(angle + division),
                                            (float) ((altura / (float) stacks) * (float) (j)),
                                            (raio - (float) ((raio / (float) stacks) * (float) (j))) * cos(angle + division)));
            }
        }
        angle += division;
    }
    return f;
}