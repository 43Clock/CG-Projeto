//
// Created by clock on 07/03/21.
//

#ifndef PROJETO_FORMA_H
#define PROJETO_FORMA_H

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif
#include <IL/il.h>
#include <vector>
#include "Ponto.h"
#include "Material.h"

using namespace std;

class Forma {
    private:
        vector<Ponto*> pontos;
        vector<Ponto*> normal;
        vector<Ponto*> textura;
        vector<Material*> material;
        GLuint pontosVBO,normalVBO,texturaVBO,texID;

    public:
    void inserePonto(Ponto *p);
    void insereNormal(Ponto *p);
    void insereTextura(Ponto *p);
    void insereMaterial(Material *p);
    vector<Ponto*> getPontos();
    vector<Ponto*> getNormal();
    vector<Ponto*> getTextura();
    int getSize();

    void createVBO();

    void draw();

    void loadTexture(string path);
};


#endif //PROJETO_FORMA_H
