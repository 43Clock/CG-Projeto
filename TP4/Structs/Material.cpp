//
// Created by clock on 28/05/21.
//

#include "Material.h"


Material::Material(int tipo, Ponto* cores, float shine){
    this->tipo = tipo;
    this->colors[0] = cores->getX();
    this->colors[1] = cores->getY();
    this->colors[2] = cores->getZ();
    this->colors[3] = 1.0f;
    this->shininess = shine;
}


void Material::draw(){
    switch (tipo) {
        case 1:
            glMaterialfv(GL_FRONT,GL_DIFFUSE,colors);
            break;
        case 2:
            glMaterialfv(GL_FRONT,GL_SPECULAR,colors);
            glMaterialf(GL_FRONT,GL_SHININESS,shininess);
            break;
        case 3:
            glMaterialfv(GL_FRONT,GL_EMISSION,colors);
            break;
        case 4:
            glMaterialfv(GL_FRONT,GL_AMBIENT,colors);
            break;
    }
}