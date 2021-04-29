//
// Created by clock on 29/03/21.
//

#ifndef GENERATOR_TRANSFORMACAO_H
#define GENERATOR_TRANSFORMACAO_H

#include <string>
#include <vector>
#include "Ponto.h"

using namespace std;

class Transformacao {
    protected:
        string tipo;
        float x;
        float y;
        float z;

    public:
        Transformacao(const string& ,float,float,float);

        const string &getTipo() const;
        float getX() const;
        float getY() const;
        float getZ() const;
        virtual void apply();

};

class Rotate : public Transformacao {
    private:
        float angle;
        float time;
    public:
        Rotate(const string& s, float x, float y, float z,float angle,float time);
        float getAngle();
        float getTime();
        void apply();

};

class Translate : public Transformacao {
    private:
        float time;
        vector<Ponto*> pontos;
        //vector<Ponto*> curvePoints;
    public:
        Translate(const string& s, float x, float y, float z,float time,vector<Ponto*>);
        float getTime();
        void apply();


    vector<Ponto *> createCurvePoints();
};


#endif //GENERATOR_TRANSFORMACAO_H
