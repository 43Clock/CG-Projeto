//
// Created by clock on 29/03/21.
//

#ifndef GENERATOR_TRANSFORMACAO_H
#define GENERATOR_TRANSFORMACAO_H

#include <string>

using namespace std;

class Transformacao {
    private:
        string tipo;
        float x;
        float y;
        float z;
        float angle; //if exists

    public:
        Transformacao(const string& ,float,float,float,float);

        const string &getTipo() const;
        float getX() const;
        float getY() const;
        float getZ() const;
        float getAngle() const;
};

#endif //GENERATOR_TRANSFORMACAO_H
