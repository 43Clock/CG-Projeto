//
// Created by clock on 07/03/21.
//

#ifndef PROJETO_FORMA_H
#define PROJETO_FORMA_H

#include <vector>
#include "Ponto.h"
using namespace std;

class Forma {
    private:
        vector<Ponto*> pontos;

    public:
    void inserePonto(Ponto *p);
    vector<Ponto*> getPontos();
};


#endif //PROJETO_FORMA_H
