//
// Created by clock on 29/03/21.
//

#include "Grupo.h"

void Grupo::adicionaForma(Forma *f) {
    this->formas.push_back(f);
}

void Grupo::adicionaGrupo(Grupo* g) {
    this->grupos.push_back(g);
}

void Grupo::adicionaTransformacao(Transformacao *t) {
    this->transformacoes.push_back(t);
}

vector<Transformacao *> Grupo::getTransformacoes() {
    return this->transformacoes;
}

vector<Forma *> Grupo::getFormas() {
    return this->formas;
}

vector<Grupo *> Grupo::getGrupos() {
    return this->grupos;
}

void Grupo::createVBO(){
    vector<float> pts;
    for (Forma *f: formas) {
        for(Ponto *p:f->getPontos()){
            pts.push_back(p->getX());
            pts.push_back(p->getY());
            pts.push_back(p->getZ());
        }
    }
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER,pts.size()*sizeof(float),pts.data(),GL_STATIC_DRAW);
}

void Grupo::draw(){
    int s = 0;
    for(Forma *f:formas){
        s+=f->getSize();
    }
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glVertexPointer(3, GL_FLOAT, 0, 0);
    glDrawArrays(GL_TRIANGLES, 0, s * 3);
}