#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#define _USE_MATH_DEFINES
#include <IL/il.h>
// Note: in Linux and Macs it
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "tinyxml2.h"
#include "../Structs/Forma.h"
#include "../Structs/Ponto.h"
#include "../Structs/Grupo.h"
#include "../Structs/Luz.h"

GLfloat amb[4] = {0.2,0.2,0.2,1.0};
GLfloat diff[4] = {1.0,1.0,1.0,1.0};
GLfloat pos[4] = {0.0,3.0,0.0,0.0};

float alpha = M_PI/4;
float beta = M_PI/4;
float radius = 400.0f;

float px = radius * cos(beta)*sin(alpha);
float pz = radius * cos(beta)*cos(alpha);
float py = radius * sin(beta);
float dx = 0.0f;
float dz = 0.0f;
float lx = 0.0f,lz = 0.0f,cam_angle = 0,px_fps = 0.0f,pz_fps = 0.0f,speed = 5.0f;

int timebase;
float frames;
float fps;

int startX, startY, tracking = 0,fps_mode = 0;
GLenum type = GL_FILL;

using namespace tinyxml2;
using namespace std;

vector<Grupo*> grupos;
vector<Luz*> luzes;

Forma* readFile(const char *path){
    Forma *f = new Forma();
    ifstream file(path);
    string line;
    if(file.is_open()){
        int i = 0;
        while(getline(file,line)){
            stringstream separado(line);
            vector<string> temp;
            for (string s; separado >> s;) {
                temp.push_back(s);
            }
            if(i == 0) {
                f->inserePonto(new Ponto(atof(temp[0].c_str()), atof(temp[1].c_str()), atof(temp[2].c_str())));
                i++;
            }else if (i == 1) {
                f->insereNormal(new Ponto(atof(temp[0].c_str()), atof(temp[1].c_str()), atof(temp[2].c_str())));
                i++;
            }else{
                f->insereTextura(new Ponto(atof(temp[0].c_str()), atof(temp[1].c_str()), atof(temp[2].c_str())));
                i = 0;
            }
        }
    }
    else {
        printf("Ficheiro não existe!\n");
    }
    return f;
}

void processaModels(XMLElement *x,Grupo *g){
    XMLElement *child = x->FirstChildElement();
    for(;child;child = child->NextSiblingElement()){
        const char * rS,*gS,*bS,*sS;
        float R = 0.0f, G = 0.0f,B= 0.0f,S = 0.0f;
        Forma *f = readFile(child->Attribute("file"));
        if(child->FindAttribute("diffR") || child->FindAttribute("diffG") || child->FindAttribute("diffB")){
            rS = child->Attribute("diffR");
            gS = child->Attribute("diffG");
            bS = child->Attribute("diffB");
            if(rS) R = atof(rS);
            if(gS) G = atof(gS);
            if(bS) B = atof(bS);
            f->insereMaterial(new Material(1,new Ponto(R,G,B),S));
        }
        if(child->FindAttribute("specR") || child->FindAttribute("specG") || child->FindAttribute("specB")) {
            rS = child->Attribute("specR");
            gS = child->Attribute("specG");
            bS = child->Attribute("specB");
            sS = child->Attribute("shine");
            if (rS) R = atof(rS);
            if (gS) G = atof(gS);
            if (bS) B = atof(bS);
            if (sS) S = atof(sS);
            f->insereMaterial(new Material(2, new Ponto(R, G, B), S));
        }
        if(child->FindAttribute("emissR") || child->FindAttribute("emissG") || child->FindAttribute("emissB")) {
            rS = child->Attribute("emissR");
            gS = child->Attribute("emissG");
            bS = child->Attribute("emissB");
            if (rS) R = atof(rS);
            if (gS) G = atof(gS);
            if (bS) B = atof(bS);
            f->insereMaterial(new Material(3, new Ponto(R, G, B), S));
        }
        if(child->FindAttribute("ambR") || child->FindAttribute("ambG") || child->FindAttribute("ambB")) {
            rS = child->Attribute("ambR");
            gS = child->Attribute("ambG");
            bS = child->Attribute("ambB");
            if (rS) R = atof(rS);
            if (gS) G = atof(gS);
            if (bS) B = atof(bS);
            f->insereMaterial(new Material(4, new Ponto(R, G, B), S));
        }
        if(child->FindAttribute("texture")){
            f->loadTexture(child->Attribute("texture"));
        }
        f->createVBO();
        g->adicionaForma(f);
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
}

void processaLuzes(XMLElement *x){
    XMLElement *group = x;
    XMLElement *child = group->FirstChildElement();
    for(;child;child = child->NextSiblingElement()){
        const char * typestr = child->Attribute("type");
        if(strcmp(typestr,"POINT") == 0){
            float pos[3];
            child->QueryFloatAttribute("posX", pos);
            child->QueryFloatAttribute("posY", pos+1);
            child->QueryFloatAttribute("posZ", pos+2);
            luzes.push_back(new Luz(0,pos));
        }
        else if(strcmp(typestr,"DIRECTIONAL") == 0){
            float dir[3];
            child->QueryFloatAttribute("dirX", dir);
            child->QueryFloatAttribute("dirY", dir+1);
            child->QueryFloatAttribute("dirZ", dir+2);
            luzes.push_back(new Luz(1,dir));
        }
        else if(strcmp(typestr,"SPOT") == 0){
            float pos[3];
            float dir[3];
            float extra[2];
            child->QueryFloatAttribute("posX", pos);
            child->QueryFloatAttribute("posY", pos+1);
            child->QueryFloatAttribute("posZ", pos+2);
            child->QueryFloatAttribute("dirX", dir);
            child->QueryFloatAttribute("dirY", dir+1);
            child->QueryFloatAttribute("dirZ", dir+2);

            child->QueryFloatAttribute( "Angle", extra );
            child->QueryFloatAttribute( "Int", extra +1);
            luzes.push_back(new Luz(2,pos,dir,extra));
        }
    }

}

void desenhaGrupo(Grupo *g) {
    vector<Transformacao*> transform = g->getTransformacoes();
    glPushMatrix();
    for (Transformacao* t : transform) {
        t->apply();
    }
    for(Forma *f:g->getFormas()){
        glDisable(GL_COLOR_MATERIAL);
        f->draw();
        glEnable(GL_COLOR_MATERIAL);
    }
    for(Grupo * gp:g->getGrupos()){
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
        if(strcmp(x->Name(),"lights")==0){
            processaLuzes(x);
            x = x->NextSiblingElement();
        }
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


	if(fps_mode == 0) {
        gluLookAt(px, py, pz,
                  dx, 0.0, dz,
                  0.0f, 1.0f, 0.0f);
    }
	else {
	    lx = px_fps+sin(cam_angle);
        lz = pz_fps+cos(cam_angle);
        gluLookAt(px_fps,10.0f,pz_fps,
                  lx,10.0f,lz,
                  0.0f,1.0f,0.0f);
	}
// put the geometric transformations here

    glColor3f(1,1,1);

// put drawing instructions here
    glPolygonMode(GL_FRONT_AND_BACK,type);

    for(Luz *l:luzes){
        l->draw();
    }

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
    float dx,dy = 0,dz,rx,ry,rz;
    float upx = 0, upy = 1, upz = 0;
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
        case 'f':
            fps_mode = abs(fps_mode - 1);
            if(fps_mode == 0) glutSetCursor(0);
            else {
                glutSetCursor(GLUT_CURSOR_NONE);
            }
            break;
        case 'e':
            cam_angle -= 0.1f;
            break;
        case 'q':
            cam_angle+= 0.1f;
            break;
        case 'w':
            dx = lx - px_fps;
            dz = lz - pz_fps;
            px_fps = px_fps + speed*dx;
            pz_fps = pz_fps + speed*dz;
            break;
        case 's':
            dx = lx - px_fps;
            dz = lz - pz_fps;
            px_fps = px_fps + (-speed)*dx;
            pz_fps = pz_fps + (-speed)*dz;
            break;
        case 'a':
            dx = lx - px_fps;
            dz = lz - pz_fps;
            rx = dy*upz - dz*upy;
            rz = dx*upy - dy*upx;
            px_fps = px_fps + (-speed)*rx;
            pz_fps = pz_fps + (-speed)*rz;
            break;
        case 'd':
            dx = lx - px_fps;
            dz = lz - pz_fps;
            rx = dy*upz - dz*upy;
            rz = dx*upy - dy*upx;
            px_fps = px_fps + speed*rx;
            pz_fps = pz_fps + speed*rz;
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


void initGL(){

#ifndef __APPLE__
    glewInit();
#endif
    ilInit();

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_NORMALIZE);

    glEnable(GL_TEXTURE_2D);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);


    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

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
    initGL();

    glClearColor(0,0,0,1) ;
    glClear(GL_COLOR_BUFFER_BIT);


// Required callback registry
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);


// put here the registration of the keyboard callbacks
    glutKeyboardFunc(processKeyboard);
    glutMouseFunc(processMouseButton);
    glutMotionFunc(processMouseMotion);


// enter GLUT's main cycle
    readXML(argv[1]);
    timebase = glutGet(GLUT_ELAPSED_TIME);
    glutMainLoop();

    return 1;
}
