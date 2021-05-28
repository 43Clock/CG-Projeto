//
// Created by clock on 29/03/21.
//

#ifndef GENERATOR_TRANSFORMACAO_H
#define GENERATOR_TRANSFORMACAO_H
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif
#define _USE_MATH_DEFINES
#include <math.h>
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
        vector<Ponto*> curvePoints;
        GLuint buffer;
    public:
        Translate(const string& s, float x, float y, float z,float time,vector<Ponto*>);
        float getTime();
        void apply();


    vector<Ponto *> createCurvePoints();

    void renderCatmullRomCurve();

    void createVBO();
};


#endif //GENERATOR_TRANSFORMACAO_H
