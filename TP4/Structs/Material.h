//
// Created by clock on 28/05/21.
//

#ifndef GENERATOR_MATERIAL_H
#define GENERATOR_MATERIAL_H

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif
#include <iostream>

#include "Ponto.h"

class Material {
private:
    int tipo;

    float colors[4];
    //float diffuse[4]; 	// tipo 1
    //float specular[4]; 	// tipo 2,shine
    //float emissive[4]; 	// tipo 3
    //float ambient[4]; 	// tipo 4
    float shininess;
public:
    Material(int tipo, Ponto *cores, float shine);
    void draw();
};


#endif //GENERATOR_MATERIAL_H
