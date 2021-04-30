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
