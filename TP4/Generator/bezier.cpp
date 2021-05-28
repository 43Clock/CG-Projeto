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

void dUBezier(vector<float> controlPoints[],vector<int> indexes,float u,float v,float *res){
    Ponto * pts[4];
    Ponto * pontosCurva[4];
    for (int i = 0; i < 4; ++i) {
        pts[0] = new Ponto(controlPoints[indexes.at(i)].at(0),controlPoints[indexes.at(i)].at(1),controlPoints[indexes.at(i)].at(2));
        pts[1] = new Ponto(controlPoints[indexes.at(i+4)].at(0),controlPoints[indexes.at(i+4)].at(1),controlPoints[indexes.at(i+4)].at(2));
        pts[2] = new Ponto(controlPoints[indexes.at(i+8)].at(0),controlPoints[indexes.at(i+8)].at(1),controlPoints[indexes.at(i+8)].at(2));
        pts[3] = new Ponto(controlPoints[indexes.at(i+12)].at(0),controlPoints[indexes.at(i+12)].at(1),controlPoints[indexes.at(i+12)].at(2));
        pontosCurva[i] = calculaBezierPoint(pts[0]->getValues(),pts[1]->getValues(),pts[2]->getValues(),pts[4]->getValues(),v);
    }
    float b0 = -3 * powf((1-u),2);
    float b1 = 3 * (3*powf(u,2) - 4*u + 1);
    float b2 = 3*(2*u - 3*powf(u,2));
    float b3 = 3 * u * u;

    res[0] = pontosCurva[0]->getX()*b0 + pontosCurva[1]->getX()*b1 + pontosCurva[2]->getX()*b2 +  pontosCurva[3]->getX()*b3;
    res[1] = pontosCurva[0]->getY()*b0 + pontosCurva[1]->getY()*b1 + pontosCurva[2]->getY()*b2 +  pontosCurva[3]->getY()*b3;
    res[2] = pontosCurva[0]->getZ()*b0 + pontosCurva[1]->getZ()*b1 + pontosCurva[2]->getZ()*b2 +  pontosCurva[3]->getZ()*b3;
}

void dVBezier(vector<float> controlPoints[],vector<int> indexes,float u,float v,float *res){
    Ponto * pts[4];
    Ponto * pontosCurva[4];
    for (int i = 0; i < 4; ++i) {
        pts[0] = new Ponto(controlPoints[indexes.at(i)].at(0),controlPoints[indexes.at(i)].at(1),controlPoints[indexes.at(i)].at(2));
        pts[1] = new Ponto(controlPoints[indexes.at(i+4)].at(0),controlPoints[indexes.at(i+4)].at(1),controlPoints[indexes.at(i+4)].at(2));
        pts[2] = new Ponto(controlPoints[indexes.at(i+8)].at(0),controlPoints[indexes.at(i+8)].at(1),controlPoints[indexes.at(i+8)].at(2));
        pts[3] = new Ponto(controlPoints[indexes.at(i+12)].at(0),controlPoints[indexes.at(i+12)].at(1),controlPoints[indexes.at(i+12)].at(2));
        pontosCurva[i] = calculaBezierPoint(pts[0]->getValues(),pts[1]->getValues(),pts[2]->getValues(),pts[4]->getValues(),u);
    }
    float b0 = -3 * powf((1-v),2);
    float b1 = 3 * (3*powf(v,2) - 4*v + 1);
    float b2 = 3*(2*v - 3*powf(v,2));
    float b3 = 3 * v * v;

    res[0] = pontosCurva[0]->getX()*b0 + pontosCurva[1]->getX()*b1 + pontosCurva[2]->getX()*b2 +  pontosCurva[3]->getX()*b3;
    res[1] = pontosCurva[0]->getY()*b0 + pontosCurva[1]->getY()*b1 + pontosCurva[2]->getY()*b2 +  pontosCurva[3]->getY()*b3;
    res[2] = pontosCurva[0]->getZ()*b0 + pontosCurva[1]->getZ()*b1 + pontosCurva[2]->getZ()*b2 +  pontosCurva[3]->getZ()*b3;

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

void cross(float *a, float *b, float *res) {

    res[0] = a[1]*b[2] - a[2]*b[1];
    res[1] = a[2]*b[0] - a[0]*b[2];
    res[2] = a[0]*b[1] - a[1]*b[0];
}

void normalize(float *a) {
    if(a[0] == 0 && a[1] == 0 && a[2] == 0){
        a[0] = 0;
        a[1] = 0;
        a[2] = 0;
    }else{
        float l = sqrt(a[0]*a[0] + a[1] * a[1] + a[2] * a[2]);
        a[0] = a[0]/l;
        a[1] = a[1]/l;
        a[2] = a[2]/l;
    }
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
    file.close();
    float u1,v1,u2,v2, t = 1.0f / tess;
    Ponto *res[n_patches][4];
    float res1 [3], res2 [3], res3[3];
    for (int i = 0; i < n_patches; ++i) {
        for (int j = 0; j < tess; ++j) {
            for (int k = 0; k < tess; ++k) {
                u1 = j * t;
                v1 = k * t;
                u2 = (j+1) * t;
                v2 = (k+1) * t;

                res[i][0] = calculaBezierPatch(controls,patches[i],u1,v1);
                res[i][1] = calculaBezierPatch(controls,patches[i],u2,v1);
                res[i][2] = calculaBezierPatch(controls,patches[i],u1,v2);
                res[i][3] = calculaBezierPatch(controls,patches[i],u2,v2);

                //0,1,3
                f->inserePonto(new Ponto(res[i][0]->getX(), res[i][0]->getY(), res[i][0]->getZ()));
                dUBezier(controls,patches[i],u1,v1,res1);
                dVBezier(controls,patches[i],u1,v1,res2);
                cross(res1,res2,res3);
                normalize(res3);
                f->insereNormal(new Ponto(res3[0],res3[1],res3[2]));
                f->insereTextura(new Ponto(u1,v1,0));

                f->inserePonto(new Ponto(res[i][1]->getX(), res[i][1]->getY(), res[i][1]->getZ()));
                dUBezier(controls,patches[i],u2,v1,res1);
                dVBezier(controls,patches[i],u2,v1,res2);
                cross(res1,res2,res3);
                normalize(res3);
                f->insereNormal(new Ponto(res3[0],res3[1],res3[2]));
                f->insereTextura(new Ponto(u2,v1,0));

                f->inserePonto(new Ponto(res[i][3]->getX(), res[i][3]->getY(), res[i][3]->getZ()));
                dUBezier(controls,patches[i],u2,v2,res1);
                dVBezier(controls,patches[i],u2,v2,res2);
                cross(res1,res2,res3);
                normalize(res3);
                f->insereNormal(new Ponto(res3[0],res3[1],res3[2]));
                f->insereTextura(new Ponto(u2,v2,0));

                //0,3,2
                f->inserePonto(new Ponto(res[i][0]->getX(), res[i][0]->getY(), res[i][0]->getZ()));
                dUBezier(controls,patches[i],u1,v1,res1);
                dVBezier(controls,patches[i],u1,v1,res2);
                cross(res1,res2,res3);
                normalize(res3);
                f->insereNormal(new Ponto(res3[0],res3[1],res3[2]));
                f->insereTextura(new Ponto(u1,v1,0));

                f->inserePonto(new Ponto(res[i][3]->getX(), res[i][3]->getY(), res[i][3]->getZ()));
                dUBezier(controls,patches[i],u2,v2,res1);
                dVBezier(controls,patches[i],u2,v2,res2);
                cross(res1,res2,res3);
                normalize(res3);
                f->insereNormal(new Ponto(res3[0],res3[1],res3[2]));
                f->insereTextura(new Ponto(u2,v2,0));

                f->inserePonto(new Ponto(res[i][2]->getX(), res[i][2]->getY(), res[i][2]->getZ()));
                dUBezier(controls,patches[i],u1,v2,res1);
                dVBezier(controls,patches[i],u1,v2,res2);
                cross(res1,res2,res3);
                normalize(res3);
                f->insereNormal(new Ponto(res3[0],res3[1],res3[2]));
                f->insereTextura(new Ponto(u1,v2,0));
            }
        }
    }
    return f;
}