
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "../Structs/Forma.h"
#include "plane.h"
#include "box.h"
#include "cone.h"
#include "sphere.h"

using namespace std;

void writeFile(Forma *f,char *path){
    char paths[1024];
    char string[1024];
    strcpy(paths,"../3dObjects/");
    strcat(paths,path);
    ofstream file(paths);
    vector<Ponto*> pontos = f->getPontos();
    for(int i = 0;i<pontos.size();i++){
        Ponto *p = pontos.at(i);
        if(i != pontos.size()-1)
            sprintf(string,"%f %f %f\n",p->getX(),p->getY(),p->getZ());
        else sprintf(string,"%f %f %f",p->getX(),p->getY(),p->getZ());
        file << string;
    }
    file.close();
}

void geraPlano(char *size, char *path) {
    Forma *f = plane(atof(size));
    writeFile(f,path);
}

void geraBox(char *x, char *y, char *z, char *div, char *path){
    Forma *f = box(atof(x),atof(y),atof(z),atoi(div));
    writeFile(f,path);
}

void geraCone(char *raio,char *altura,char *slices,char *stacks,char *path){
    Forma *f = cone(atof(raio),atof(altura),atoi(slices),atoi(stacks));
    writeFile(f,path);
}

void geraEsfera(char *raio, char *slices, char *stacks, char *path) {
    Forma *f = sphere(atof(raio),atoi(slices),atoi(stacks));
    writeFile(f,path);
}

void imprimeAjuda(){
    cout<< "+---------------------------------------------------------------------+" <<endl;
    cout<< "|                                                                     |" <<endl;
    cout<< "| Como usar: ./generator <SHAPE> ... <FILE>                           |" <<endl;
    cout<< "|                         [-h]                                        |" <<endl;
    cout<< "|                                                                     |" <<endl;
    cout<< "|  SHAPE:                                                             |" <<endl;
    cout<< "|- plane <SIZE>                                                       |" <<endl;
    cout<< "| Cria um quadrado no plano XZ, centrado na origem.                   |" <<endl;
    cout<< "|                                                                     |" <<endl;
    cout<< "|- box <WIDTH> <HEIGHT> <LENGTH> <DIVISIONS>                          |" <<endl;
    cout<< "| Cria uma box com as dimens??es dadas e com um certo numero divis??es. |" <<endl;
    cout<< "|                                                                     |" <<endl;
    cout<< "|- sphere <RADIUS> <SLICES> <STACKS>                                  |" <<endl;
    cout<< "| Cria uma esfera com o raio, slices e stacks fornecidos              |" <<endl;
    cout<< "|                                                                     |" <<endl;
    cout<< "|- cone <RADIUS> <HEIGHT> <SLICES> <STACKS>                           |" <<endl;
    cout<< "| Cria um cone com o raio, altura, slices e stacks fornecidas         |" <<endl;
    cout<< "|                                                                     |" <<endl;
    cout<< "+---------------------------------------------------------------------+" <<endl;

}

int main(int argc, char **argv){
    if (argc <2){
        imprimeAjuda();
        return 1;
    }
    if(strcmp(argv[1],"plane")==0 && argc == 4){
        geraPlano(argv[2],argv[3]);
    }
    else if(strcmp(argv[1],"box")==0 && argc == 7){
        geraBox(argv[2],argv[3],argv[4],argv[5],argv[6]);
    }
    else if(strcmp(argv[1],"box")==0 && argc == 6){
        char um[2] = "1";
        geraBox(argv[2],argv[3],argv[4],um,argv[5]);
    }
    else if(strcmp(argv[1],"cone")==0 && argc == 7){
        geraCone(argv[2],argv[3],argv[4],argv[5],argv[6]);
    }
    else if(strcmp(argv[1],"sphere")== 0 && argc == 6){
        geraEsfera(argv[2],argv[3],argv[4],argv[5]);
    }
    else imprimeAjuda();
    return 0;
}
