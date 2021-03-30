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
