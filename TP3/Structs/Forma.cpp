//
// Created by clock on 07/03/21.
//

#include "Forma.h"

void Forma::inserePonto(Ponto *p) {
    this->pontos.push_back(p);
}

vector<Ponto *> Forma::getPontos() {
    return this->pontos;
}

int Forma::getSize(){
    return pontos.size();
}

void Forma::createVBO(){
    vector<float> pts;
    for (Ponto *p :pontos) {
        pts.push_back(p->getX());
        pts.push_back(p->getY());
        pts.push_back(p->getZ());
    }
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER,pts.size()*sizeof(float),pts.data(),GL_STATIC_DRAW);
}

void Forma::draw(){
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glVertexPointer(3, GL_FLOAT, 0, 0);
    glDrawArrays(GL_TRIANGLES, 0, getSize() * 3);
}