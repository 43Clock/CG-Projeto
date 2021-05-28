//
// Created by clock on 07/03/21.
//

#include "Forma.h"

void Forma::inserePonto(Ponto *p) {
    this->pontos.push_back(p);
}

void Forma::insereNormal(Ponto *p) {
    this->normal.push_back(p);
}

void Forma::insereTextura(Ponto *p) {
    this->textura.push_back(p);
}

void Forma::insereMaterial(Material *p) {
    this->material.push_back(p);
}

vector<Ponto *> Forma::getPontos() {
    return this->pontos;
}

vector<Ponto *> Forma::getNormal() {
    return this->normal;
}

vector<Ponto *> Forma::getTextura() {
    return this->textura;
}

int Forma::getSize(){
    return pontos.size();
}

void Forma::createVBO(){
    vector<float> pts;
    vector<float> normals;
    vector<float> texture;
        for(Ponto *p:this->pontos){
            pts.push_back(p->getX());
            pts.push_back(p->getY());
            pts.push_back(p->getZ());
        }
        for(Ponto *p:this->normal){
            normals.push_back(p->getX());
            normals.push_back(p->getY());
            normals.push_back(p->getZ());
        }
        for(Ponto *p:this->textura){
            texture.push_back(p->getX());
            texture.push_back(p->getY());
        }
    glGenBuffers(1, &pontosVBO);
    glBindBuffer(GL_ARRAY_BUFFER, pontosVBO);
    glBufferData(GL_ARRAY_BUFFER,pts.size()*sizeof(float),pts.data(),GL_STATIC_DRAW);

    glGenBuffers(1, &normalVBO);
    glBindBuffer(GL_ARRAY_BUFFER, normalVBO);
    glBufferData(GL_ARRAY_BUFFER,normals.size()*sizeof(float),normals.data(),GL_STATIC_DRAW);

    glGenBuffers(1, &texturaVBO);
    glBindBuffer(GL_ARRAY_BUFFER, texturaVBO);
    glBufferData(GL_ARRAY_BUFFER,texture.size()*sizeof(float),texture.data(),GL_STATIC_DRAW);
}

void Forma::draw(){
    if (material.size()!=0) {
        for (Material *m:this->material) {
            m->draw();
        }
    }else{
        float m[4] = {0,0,0,0};
        glMaterialfv(GL_FRONT, GL_EMISSION, m);
    }

    glBindBuffer(GL_ARRAY_BUFFER,pontosVBO);
    glVertexPointer(3,GL_FLOAT,0, 0);

    glBindBuffer(GL_ARRAY_BUFFER,normalVBO);
    glNormalPointer(GL_FLOAT,0,0);

    glBindBuffer(GL_ARRAY_BUFFER,texturaVBO);
    glTexCoordPointer(2,GL_FLOAT,0,0);

    glBindTexture(GL_TEXTURE_2D, texID);
    glDrawArrays(GL_TRIANGLES, 0, getSize() *3);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Forma::loadTexture(string path) {
    unsigned int tw,th, t;
    unsigned char *texData;
    ILuint img;
    ilEnable(IL_ORIGIN_SET);
    ilOriginFunc(IL_ORIGIN_LOWER_LEFT);
    ilGenImages(1, &img);
    ilBindImage(img);
    if(! ilLoadImage((ILstring) path.c_str()))
        cout << path;

    tw = ilGetInteger(IL_IMAGE_WIDTH);
    th = ilGetInteger(IL_IMAGE_HEIGHT);
    ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
    texData = ilGetData();
    glGenTextures(1, &texID);
    glBindTexture(GL_TEXTURE_2D, texID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tw, th, 0, GL_RGBA, GL_UNSIGNED_BYTE, texData);
    glBindTexture(GL_TEXTURE_2D, 0);
}