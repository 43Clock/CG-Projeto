//
// Created by clock on 07/03/21.
//

#ifndef PROJETO_PONTO_H
#define PROJETO_PONTO_H

#include <cmath>

class Ponto {
    private:
        float x;
        float y;
        float z;

    public:
    Ponto(float x,float y,float z);
    float getX();
    float getY();
    float getZ();

    Ponto *normaliza();

    Ponto *toUv();

    float *getValues();
};


#endif //PROJETO_PONTO_H
