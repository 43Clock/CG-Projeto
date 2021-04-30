//
// Created by clock on 29/03/21.
//

#ifndef GENERATOR_GRUPO_H
#define GENERATOR_GRUPO_H

#include <vector>
#include "Transformacao.h"
#include "Forma.h"

using namespace std;

class Grupo {
    private:
        vector<Transformacao*> transformacoes;
        vector<Forma*> formas;
        vector<Grupo*> grupos;
        GLuint buffer;

    public:
        void adicionaForma(Forma*);
        void adicionaGrupo(Grupo*);
        void adicionaTransformacao(Transformacao*);
        vector<Transformacao*> getTransformacoes();
        vector<Forma*> getFormas();
        vector<Grupo*> getGrupos();

    void createVBO();

    void draw();
};


#endif //GENERATOR_GRUPO_H
