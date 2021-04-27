#include <fstream>
#include <sstream>
#include <cstring>
#include "bezier.h"
using namespace std;

Ponto * calculaBezierPoint(float *p1,float *p2,float *p3,float *p4,float t) {
    float point[3];
    float b0 = (1 - t) * (1 - t) * (1 - t);
    float b1 = 3 * t * (1 - t) * (1 - t);
    float b2 = 3 * t * t * (1 - t);
    float b3 = t * t * t ;
    point[0] = b0 * p1[0] + b1 * p2[0] + b2 * p3[0] + b3 * p4[0];
    point[1] = b0 * p1[1] + b1 * p2[1] + b2 * p3[1] + b3 * p4[1];
    point[2] = b0 * p1[2] + b1 * p2[2] + b2 * p3[2] + b3 * p4[2];
    return (new Ponto(point[0], point[1], point[2]));
}

Ponto * calculaBezierPatch(vector<float> controlPoints[],vector<int> indexes,float u,float v){
    float temp[4][3], res[16][3];
    Ponto *p, *ret;
    int k = 0, j = 0;
    for (int i = 0; i < 16; ++i) {
        temp[j][0] = controlPoints[indexes[i]][0];
        temp[j][1] = controlPoints[indexes[i]][1];
        temp[j][2] = controlPoints[indexes[i]][2];
        j++;
        //Com 4 pontos podemos fazer o calculo de Bezier
        if(j%4 == 0) {
            p = calculaBezierPoint(temp[0], temp[1], temp[2], temp[3],u);
            res[k][0] = p->getX();
            res[k][1] = p->getY();
            res[k][2] = p->getZ();
            k++;
            j = 0;
        }
    }
    ret = calculaBezierPoint(res[0], res[1], res[2], res[3], v);
    return ret;
}

Forma* bezierPatch(float tess,char *path){
    Forma *f = new Forma();
    ifstream file;
    file.open(path);
    if(!file.is_open()) return NULL;
    string line;
    getline(file,line);
    int n_patches = atoi(line.c_str());
    vector<int> patches[n_patches];
    for (int i = 0; i < n_patches; ++i) {
        getline(file,line);
        char*temp;
        char*linha = const_cast<char *>(line.c_str());
        temp = strtok(linha, ",");
        patches[i].push_back(atoi(temp));
        while((temp = strtok(NULL,","))){
            patches[i].push_back(atoi(temp));
        }
    }
    getline(file, line);
    int n_control = atoi(line.c_str());
    vector<float> controls[n_control];
    for (int i = 0; i < n_control; ++i) {
        getline(file,line);
        char*temp;
        char*linha = const_cast<char *>(line.c_str());
        temp = strtok(linha, ",");
        controls[i].push_back(atof(temp));
        while((temp = strtok(NULL,","))){
            controls[i].push_back(atof(temp));
        }
    }
    float u1,v1,u2,v2, inc = 1.0f/tess;
    Ponto *res[n_patches][4];

    for (int i = 0; i < n_patches; ++i) {
        for (int j = 0; j < tess; ++j) {
            for (int k = 0; k < tess; ++k) {
                u1 = j * inc;
                v1 = k * inc;
                u2 = (j+1) * inc;
                v2 = (k+1) * inc;

                res[i][0] = calculaBezierPatch(controls,patches[i],u1,v1);
                res[i][1] = calculaBezierPatch(controls,patches[i],u2,v1);
                res[i][2] = calculaBezierPatch(controls,patches[i],u1,v2);
                res[i][3] = calculaBezierPatch(controls,patches[i],u2,v2);

                //0,1,3
                f->inserePonto(new Ponto(res[i][0]->getX(), res[i][0]->getY(), res[i][0]->getZ()));
                f->inserePonto(new Ponto(res[i][1]->getX(), res[i][1]->getY(), res[i][1]->getZ()));
                f->inserePonto(new Ponto(res[i][3]->getX(), res[i][3]->getY(), res[i][3]->getZ()));

                //0,3,2
                f->inserePonto(new Ponto(res[i][0]->getX(), res[i][0]->getY(), res[i][0]->getZ()));
                f->inserePonto(new Ponto(res[i][3]->getX(), res[i][3]->getY(), res[i][3]->getZ()));
                f->inserePonto(new Ponto(res[i][2]->getX(), res[i][2]->getY(), res[i][2]->getZ()));
            }
        }
    }
    return f;
}