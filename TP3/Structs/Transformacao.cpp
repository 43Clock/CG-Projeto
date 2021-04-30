//
// Created by clock on 29/03/21.
//

#include "Transformacao.h"

Transformacao::Transformacao(const string& s, float x, float y, float z) {
    this->tipo = s;
    this->x = x;
    this->y = y;
    this->z = z;
}

Rotate::Rotate(const string& s, float x, float y, float z,float angle,float time): Transformacao(s,x,y,z) {
    this->tipo = s;
    this->x = x;
    this->y = y;
    this->z = z;
    this->angle = angle;
    this->time = time;
}

Translate::Translate(const string &s, float x, float y, float z, float time,vector<Ponto*> pontos) : Transformacao(s,x,y,z){
    this->tipo = s;
    this->x = x;
    this->y = y;
    this->z = z;
    this->time = time;
    this->pontos = pontos;
    if(this->time != 0) {
        this->curvePoints = createCurvePoints();
    }
}

void Translate::createVBO(){
    if(this->time != 0) {
        vector<float> pts;
        for (Ponto *p :this->curvePoints) {
            pts.push_back(p->getX());
            pts.push_back(p->getY());
            pts.push_back(p->getZ());
        }
        glGenBuffers(1, &buffer);
        glBindBuffer(GL_ARRAY_BUFFER, buffer);
        glBufferData(GL_ARRAY_BUFFER,pts.size()*sizeof(float),pts.data(),GL_STATIC_DRAW);
    }
}

const string &Transformacao::getTipo() const {
    return tipo;
}

float Transformacao::getX() const {
    return x;
}

float Transformacao::getY() const {
    return y;
}

float Transformacao::getZ() const {
    return z;
}

void Transformacao::apply() {
    if(this->getTipo() =="scale") {
        glScalef(this->x, this->y, this->z);
    }
    else if(this->getTipo() == "color"){
        glColor3f(this->x, this->y, this->z);
    }
}

float Rotate::getAngle() {
    return this->angle;
}

void Rotate::apply() {
    if (this->time == 0 || this->angle != 0) {
        glRotatef(this->angle, this->x, this->y, this->z);
    } else {
        float aux = glutGet(GLUT_ELAPSED_TIME)%(int)(this->time*1000); //*1000 para passar para ms
        glRotatef(((aux / (this->time * 1000)) * 360), this->x, this->y, this->z);
    }
}

float Rotate::getTime() {
    return time;
}

float Translate::getTime() {
    return time;
}

void buildRotMatrix(float *x, float *y, float *z, float *m) {

    m[0] = x[0]; m[1] = x[1]; m[2] = x[2]; m[3] = 0;
    m[4] = y[0]; m[5] = y[1]; m[6] = y[2]; m[7] = 0;
    m[8] = z[0]; m[9] = z[1]; m[10] = z[2]; m[11] = 0;
    m[12] = 0; m[13] = 0; m[14] = 0; m[15] = 1;
}


void cross(float *a, float *b, float *res) {

    res[0] = a[1]*b[2] - a[2]*b[1];
    res[1] = a[2]*b[0] - a[0]*b[2];
    res[2] = a[0]*b[1] - a[1]*b[0];
}


void normalize(float *a) {

    float l = sqrt(a[0]*a[0] + a[1] * a[1] + a[2] * a[2]);
    a[0] = a[0]/l;
    a[1] = a[1]/l;
    a[2] = a[2]/l;
}


float length(float *v) {

    float res = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    return res;
}

void multMatrixVector(float *m, float *v, float *res) {

    for (int j = 0; j < 4; ++j) {
        res[j] = 0;
        for (int k = 0; k < 4; ++k) {
            res[j] += v[k] * m[j * 4 + k];
        }
    }

}


void getCatmullRomPoint(float t, int *indices, float *pos, float *deriv, vector<Ponto *> pontos) {
    float t2 = t * t;
    float t3 = t2 * t;
    float posAux[4], derivAux[4];

    Ponto *p0 = pontos[indices[0]];
    Ponto *p1 = pontos[indices[1]];
    Ponto *p2 = pontos[indices[2]];
    Ponto *p3 = pontos[indices[3]];
    // catmull-rom matrix
    float m[4][4] = {{-0.5f, 1.5f,  -1.5f, 0.5f},
                     {1.0f,  -2.5f, 2.0f,  -0.5f},
                     {-0.5f, 0.0f,  0.5f,  0.0f},
                     {0.0f,  1.0f,  0.0f,  0.0f}};

    pos[0] = 0;
    pos[1] = 0;
    pos[2] = 0;

    deriv[0] = 0;
    deriv[1] = 0;
    deriv[2] = 0;
    // Compute A = M * P
    posAux[0] = t3*m[0][0] + t2*m[1][0] + t*m[2][0] + m[3][0];
    posAux[1] = t3*m[0][1] + t2*m[1][1] + t*m[2][1] + m[3][1];
    posAux[2] = t3*m[0][2] + t2*m[1][2] + t*m[2][2] + m[3][2];
    posAux[3] = t3*m[0][3] + t2*m[1][3] + t*m[2][3] + m[3][3];

    derivAux[0] = (3*t2)*m[0][0] +(2*t)*m[1][0] + m[2][0];
    derivAux[1] = (3*t2)*m[0][1] +(2*t)*m[1][1] + m[2][1];
    derivAux[2] = (3*t2)*m[0][2] +(2*t)*m[1][2] + m[2][2];
    derivAux[3] = (3*t2)*m[0][3] +(2*t)*m[1][3] + m[2][3];

    // Compute pos = T * A

    pos[0] = posAux[0]*p0->getX() +posAux[1]*p1->getX()+posAux[2]*p2->getX()+posAux[3]*p3->getX();
    pos[1] = posAux[0]*p0->getY() +posAux[1]*p1->getY()+posAux[2]*p2->getY()+posAux[3]*p3->getY();
    pos[2] = posAux[0]*p0->getZ() +posAux[1]*p1->getZ()+posAux[2]*p2->getZ()+posAux[3]*p3->getZ();

    // compute deriv = T' * A

    deriv[0] = derivAux[0]*p0->getX() +derivAux[1]*p1->getX()+derivAux[2]*p2->getX()+derivAux[3]*p3->getX();
    deriv[1] = derivAux[0]*p0->getY() +derivAux[1]*p1->getY()+derivAux[2]*p2->getY()+derivAux[3]*p3->getY();
    deriv[2] = derivAux[0]*p0->getZ() +derivAux[1]*p1->getZ()+derivAux[2]*p2->getZ()+derivAux[3]*p3->getZ();
}


// given  global t, returns the point in the curve
void getGlobalCatmullRomPoint(float gt, float *pos, float *deriv, vector<Ponto*> pontos) {
    int nPontos = pontos.size();
    float t = gt * nPontos; // this is the real global t
    int index = floor(t);  // which segment
    t = t - index; // where within  the segment

    // indices store the points
    int indices[4];
    indices[0] = (index + nPontos-1)%nPontos;
    indices[1] = (indices[0]+1)%nPontos;
    indices[2] = (indices[1]+1)%nPontos;
    indices[3] = (indices[2]+1)%nPontos;

    getCatmullRomPoint(t, indices,pos,deriv,pontos);
}

vector<Ponto*> Translate::createCurvePoints(){
    float pos[3], deriv[3];
    float t = 0;
    vector<Ponto*> curvePoints;
    while (t<1) {
        getGlobalCatmullRomPoint(t, pos, deriv,this->pontos);
        Ponto *p = new Ponto(pos[0], pos[1], pos[2]);
        curvePoints.push_back(p);
        t+=0.01;//Smaller value == more detail
    }
    return curvePoints;
}

void rotateCurve(float *deriv, float *y){
    float z[3];

    cross(deriv, y, z);
    cross(z, deriv, y);

    normalize(deriv);
    normalize(y);
    normalize(z);

    float m[4][4];
    buildRotMatrix(deriv, y, z, (float *) m);
    glMultMatrixf((float*)m);
}

void Translate::renderCatmullRomCurve(){
    glBindBuffer(GL_ARRAY_BUFFER, this->buffer);
    glVertexPointer(3, GL_FLOAT, 0, nullptr);
    glDrawArrays(GL_LINE_LOOP, 0, this->curvePoints.size());
}

void Translate::apply() {
    if (time == 0) {
        glTranslatef(x, y, z);
    }else{
        float aux = glutGet(GLUT_ELAPSED_TIME)%(int)(this->time*1000); //*1000 para passar para ms
        float gt = aux / (time * 1000);
        float pos[3], deriv[3], zero[3];
        zero[0] = 0;
        zero[1] = 1;
        zero[2] = 0;

        renderCatmullRomCurve();

        getGlobalCatmullRomPoint(gt, pos, deriv, this->pontos);
        glTranslatef(pos[0], pos[1], pos[2]);
        rotateCurve(deriv,zero);
    }

}
