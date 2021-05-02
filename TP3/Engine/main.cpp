#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "tinyxml2.h"
#include "../Structs/Forma.h"
#include "../Structs/Ponto.h"
#include "../Structs/Grupo.h"

float alpha = M_PI/4;
float beta = M_PI/4;
float radius = 400.0f;

float px = radius * cos(beta)*sin(alpha);
float pz = radius * cos(beta)*cos(alpha);
float py = radius * sin(beta);
float dx = 0.0f;
float dz = 0.0f;

int timebase;
float frames;
float fps;

int startX, startY, tracking = 0;
GLenum type = GL_FILL;

using namespace tinyxml2;
using namespace std;

vector<Grupo*> grupos;

void readFile(const char *path,Grupo *g){
    Forma *f = new Forma();
    ifstream file(path);
    string line;
    if(file.is_open()){
        while(getline(file,line)){
            stringstream separado(line);
            vector<string> temp;
            for (string s; separado >> s;) {
                temp.push_back(s);
            }
            f->inserePonto(new Ponto(atof(temp[0].c_str()),atof(temp[1].c_str()),atof(temp[2].c_str())));
        }
        g->adicionaForma(f);
    }
    else {
        printf("Ficheiro não existe!\n");
    }
}

void processaModels(XMLElement *x,Grupo *g){
    XMLElement *child = x->FirstChildElement();
    for(;child;child = child->NextSiblingElement()){
        readFile(child->Attribute("file"),g);
    }
}

void processaTranslate(XMLElement *child,Grupo *g){
    const char * xFile = child->Attribute("X");
    const char * yFile = child->Attribute("Y");
    const char * zFile = child->Attribute("Z");
    const char * timeFile = child->Attribute("time");
    float x = 0.0f,y=0.0f,z=0.0f,time = 0.0f;
    if(xFile){
        x = atof(xFile);
    }
    if(yFile){
        y = atof(yFile);
    }
    if(zFile){
        z = atof(zFile);
    }
    if (timeFile) {
        time = atof(timeFile);
    }
    XMLElement *childs = child->FirstChildElement();
    vector<Ponto*> pontos;
    for (;childs ;childs = childs->NextSiblingElement()) {
        float x = 0,y = 0,z = 0;
        childs->QueryFloatAttribute("X",&x);
        childs->QueryFloatAttribute("Y",&y);
        childs->QueryFloatAttribute("Z",&z);
        pontos.push_back(new Ponto(x, y, z));
    }
    Translate *t = new Translate("translate",x,y,z,time,pontos);
    t->createVBO();
    g->adicionaTransformacao(t);
}

void processaRotate(XMLElement *child,Grupo *g){
    const char * angleFile = child->Attribute("angle");
    const char * xFile = child->Attribute("axisX");
    const char * yFile = child->Attribute("axisY");
    const char * zFile = child->Attribute("axisZ");
    const char * timeFile = child->Attribute("time");
    float x = 0.0f,y=0.0f,z=0.0f,angle = 0.0f,time = 0.0f;
    if(xFile){
        x = atof(xFile);
    }
    if(yFile){
        y = atof(yFile);
    }
    if(zFile){
        z = atof(zFile);
    }
    if(angleFile && !timeFile){
        angle = atof(angleFile);
    }
    if (timeFile) {
        time = atof(timeFile);
    }
    g->adicionaTransformacao(new Rotate("rotate",x,y,z,angle,time));
}

void processaScale(XMLElement *child,Grupo *g){
    const char * xFile = child->Attribute("X");
    const char * yFile = child->Attribute("Y");
    const char * zFile = child->Attribute("Z");
    float x = 0.0f,y=0.0f,z=0.0f;
    if(xFile){
        x = atof(xFile);
    }
    if(yFile){
        y = atof(yFile);
    }
    if(zFile){
        z = atof(zFile);
    }
    g->adicionaTransformacao(new Transformacao("scale",x,y,z));
}

void processaColor(XMLElement *child,Grupo *g){
    const char * xFile = child->Attribute("R");
    const char * yFile = child->Attribute("G");
    const char * zFile = child->Attribute("B");
    float x = 0.0f,y=0.0f,z=0.0f;
    if(xFile){
        x = atof(xFile)/255;
    }
    if(yFile){
        y = atof(yFile)/255;
    }
    if(zFile){
        z = atof(zFile)/255;
    }
    g->adicionaTransformacao(new Transformacao("color",x,y,z));
}

void processaGroup(XMLElement *x,Grupo *g){
    XMLElement *group = x;
    XMLElement *child = group->FirstChildElement();
    bool flag = true;
    for(;child;child = child->NextSiblingElement()){
        string tipo = child->Name();
        if(tipo.compare("translate") == 0){
            processaTranslate(child,g);
        }
        else if(tipo.compare("rotate") == 0){
            processaRotate(child,g);
        }
        else if(tipo == "scale"){
            processaScale(child,g);
        }
        else if(tipo == "group"){
            Grupo *novo = new Grupo();
            processaGroup(child,novo);
            g->adicionaGrupo(novo);
        }
        else if(tipo == "models" && flag){
            processaModels(child,g);
            flag = false;
        }
        else if(tipo == "color"){
            processaColor(child,g);
        }
    }
    g->createVBO();
}

void desenhaGrupo(Grupo *g) {
    vector<Transformacao*> transform = g->getTransformacoes();
    vector<Grupo*> gs = g->getGrupos();
    vector<Forma*> fs = g->getFormas();
    glPushMatrix();
    for (Transformacao* t : transform) {
        t->apply();
    }
    g->draw();
    for(Grupo * gp:gs){
        desenhaGrupo(gp);
    }
    glColor3f(1,1,1);
    glPopMatrix();
}

void readXML(char *path){
    XMLDocument ficheiro;
    XMLError erro = ficheiro.LoadFile(path);
    int grupoAtual = 0;
    if(!erro){
        XMLElement *x = ficheiro.FirstChildElement()->FirstChildElement();
        while(x){
            grupos.push_back(new Grupo());
            processaGroup(x,grupos.at(grupoAtual));
            grupoAtual++;
            x = x->NextSiblingElement();
        }
    }else {
        printf("Ficheiro não existe/inválido");
        exit(1);
    }
}


void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window with zero width).
	if(h == 0)
		h = 1;

	// compute window's aspect ratio
	float ratio = w * 1.0 / h;

	// Set the projection matrix as current
	glMatrixMode(GL_PROJECTION);
	// Load Identity Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
    glViewport(0, 0, w, h);

	// Set perspective
	gluPerspective(45.0f ,ratio, 1.0f ,1000.0f);

	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);
}

void renderScene(void) {

	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	glLoadIdentity();
	gluLookAt(px, py, pz,
              dx, 0.0, dz,
              0.0f, 1.0f, 0.0f);
// put the geometric transformations here

    glColor3f(1,1,1);

// put drawing instructions here
    glPolygonMode(GL_FRONT_AND_BACK,type);
    for(Grupo *g:grupos){
        desenhaGrupo(g);
    }
    frames++;
    int time = glutGet(GLUT_ELAPSED_TIME);
    if (time - timebase>1000){
        fps = frames*1000.0/(time-timebase);
        timebase = time;
        frames = 0;
    }
    char title[1024];
    sprintf(title,"%f FPS",fps);
    glutSetWindowTitle(title);
	// End of frame
	glutSwapBuffers();
	glutPostRedisplay();
}



void controlAngles(){
    if (beta>90.0f) beta = 90.0f;
    if (beta<-90.0f) beta = -90.0f;
}
void processMouseButton(int button, int state, int xx, int yy){
    cout<<beta<<endl;
    if (state == GLUT_DOWN)  {
        startX = xx;
        startY = yy;
        if (button == GLUT_LEFT_BUTTON)
            tracking = 1;
        else if (button == GLUT_RIGHT_BUTTON)
            tracking = 2;
        else
            tracking = 0;
    }
    else if (state == GLUT_UP) {
        if (tracking == 1) {
            alpha += (xx - startX);
            beta += (yy - startY);
            controlAngles();
        }
        else if (tracking == 2) {

            radius -= yy - startY;
            if (radius < 3)
                radius = 3.0;
        }
        tracking = 0;
    }
}

float min(float a,float b) {
    return a>b?b:a;
}

float max(float a,float b) {
    return a>b?a:b;
}

void processKeyboard(unsigned char key,int x,int y){
    switch (key) {
        case 'i':
            type = GL_FILL;
            glutPostRedisplay();
            break;
        case 'o':
            type = GL_LINE;
            glutPostRedisplay();
            break;
        case 'p':
            type = GL_POINT;
            glutPostRedisplay();
            break;
    }
}

void processMouseMotion(int xx, int yy) {

    int deltaX, deltaY;
    int alphaAux, betaAux;
    int rAux;

    if (!tracking)
        return;
    deltaX = xx - startX;
    deltaY = yy - startY;
    if (tracking == 1) {


        alphaAux = alpha + deltaX;
        betaAux = beta + deltaY;

        if (betaAux > 85.0)
            betaAux = 85.0;
        else if (betaAux < -85.0)
            betaAux = -85.0;

        rAux = radius;
    }
    else if (tracking == 2) {

        alphaAux = alpha;
        betaAux = beta;
        rAux = radius - deltaY;
        if (rAux < 3)
            rAux = 3;
    }
    px = rAux * sin(alphaAux * 3.14 / 180.0) * cos(betaAux * 3.14 / 180.0);
    pz = rAux * cos(alphaAux * 3.14 / 180.0) * cos(betaAux * 3.14 / 180.0);
    py = rAux * 							     sin(betaAux * 3.14 / 180.0);

}

void imprimeAjuda (){
    cout<< "+---------------------------------------------------------------------+" <<endl;
    cout<< "|                                                                     |" <<endl;
    cout<< "| Como usar: ./engine <XMLFile>                                       |" <<endl;
    cout<< "|                       [-h]                                          |" <<endl;
    cout<< "|                                                                     |" <<endl;
    cout<< "|  XMLFile:                                                           |" <<endl;
    cout<< "|  Path para o ficheiro XML que contem a informação sobre             |" <<endl;
    cout<< "|  quais figuras desenhar.                                            |" <<endl;
    cout<< "|                                                                     |" <<endl;
    cout<< "|  Comandos (Mover):                                                  |" <<endl;
    cout<< "|- W:                                                                 |" <<endl;
    cout<< "|   Roda a câmera para cima                                           |" <<endl;
    cout<< "|                                                                     |" <<endl;
    cout<< "|- A:                                                                 |" <<endl;
    cout<< "|   Roda a câmera para a esquerda                                     |" <<endl;
    cout<< "|                                                                     |" <<endl;
    cout<< "|- S:                                                                 |" <<endl;
    cout<< "|   Roda a câmera para a direira                                      |" <<endl;
    cout<< "|                                                                     |" <<endl;
    cout<< "|- D:                                                                 |" <<endl;
    cout<< "|   Roda a câmera para baixo                                          |" <<endl;
    cout<< "|                                                                     |" <<endl;
    cout<< "|  Comandos (Zoom):                                                   |" <<endl;
    cout<< "|- Mouse Wheel up:                                                    |" <<endl;
    cout<< "|       Zoom in                                                       |" <<endl;
    cout<< "|- Mouse Wheel down:                                                  |" <<endl;
    cout<< "|       Zoom out                                                      |" <<endl;
    cout<< "|                                                                     |" <<endl;
    cout<< "| Comandos (Formatar):                                                |" <<endl;
    cout<< "|- i:                                                                 |" <<endl;
    cout<< "|    Desenhar os triângulos preenchidos                               |" <<endl;
    cout<< "|- o:                                                                 |" <<endl;
    cout<< "|    Desenhar apenas as bordas dos triângulos                         |" <<endl;
    cout<< "|- p:                                                                 |" <<endl;
    cout<< "|    Desenhar apenas os vértices dos triângulos                       |" <<endl;
    cout<< "|                                                                     |" <<endl;
    cout<< "| Comandos (Cores):                                                   |" <<endl;
    cout<< "|- v:                                                                 |" <<endl;
    cout<< "|   Voltar ao default                                                 |" <<endl;
    cout<< "|- c:                                                                 |" <<endl;
    cout<< "|   Pintar com um gradiente de preto e branco                         |" <<endl;
    cout<< "|- r:                                                                 |" <<endl;
    cout<< "|   Pintar com um gradiente de vermelho                               |" <<endl;
    cout<< "|- g:                                                                 |" <<endl;
    cout<< "|   Pintar com um gradiente de verde                                  |" <<endl;
    cout<< "|- b:                                                                 |" <<endl;
    cout<< "|   Pintar com um gradiente de azul                                   |" <<endl;
    cout<< "+---------------------------------------------------------------------+" <<endl;
}

int main(int argc, char **argv) {
    if (argc >2){
        return 0;
    }
    if(strcmp(argv[1],"-h") == 0){
        imprimeAjuda();
        return 0;
    }

// init GLUT and the window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(800,800);
    glutCreateWindow("CG@DI-UM");
    glewInit();

// Required callback registry
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);


// put here the registration of the keyboard callbacks
    glutKeyboardFunc(processKeyboard);
    glutMouseFunc(processMouseButton);
    glutMotionFunc(processMouseMotion);

//  OpenGL settings
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnableClientState(GL_VERTEX_ARRAY);

// enter GLUT's main cycle
    readXML(argv[1]);
    timebase = glutGet(GLUT_ELAPSED_TIME);
    glutMainLoop();

    return 1;
}
