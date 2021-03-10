
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include "../Structs/Forma.h"
#include "plane.h"
#include "box.h"
#include "cone.h"
#include "sphere.h"


void writeFile(Forma *f,char *path){
    char paths[1024];
    char string[1024];
    strcpy(paths,"../");
    strcat(paths,path);
    ofstream file(paths);
    vector<Ponto*> pontos = f->getPontos();
    for(int i = 0;i<pontos.size();i++){
        Ponto *p = pontos.at(i);
        if(i != pontos.size()-1)
            sprintf(string,"glVertex3f(%f,%f,%f);\n",p->getX(),p->getY(),p->getZ());
        else sprintf(string,"glVertex3f(%f,%f,%f);",p->getX(),p->getY(),p->getZ());
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

int main(int argc, char **argv){
    if (argc <2){
        return 1;
    }
    if(strcmp(argv[1],"plane")==0){
        geraPlano(argv[2],argv[3]);
    }
    if(strcmp(argv[1],"box")==0){
        geraBox(argv[2],argv[3],argv[4],argv[5],argv[6]);
    }
    if(strcmp(argv[1],"cone")==0){
        geraCone(argv[2],argv[3],argv[4],argv[5],argv[6]);
    }
    if(strcmp(argv[1],"sphere")==0){
        geraEsfera(argv[2],argv[3],argv[4],argv[5]);
    }
    return 0;
}
