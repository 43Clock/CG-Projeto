#ifdef __APPLE__
#include <GLUT/glut.h>
#else
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

float alpha = M_PI/4;
float beta = M_PI/4;
float radius = 10.0f;

float px = radius * cos(beta)*sin(alpha);
float pz = radius * cos(beta)*cos(alpha);
float py = radius * sin(beta);
float color = 0.0f;
GLenum tipo = GL_FILL;
int colorChange = 0;

using namespace tinyxml2;
using namespace std;

vector<Forma*> formas;

void readFile(char *path){
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
        formas.push_back(f);
    }
    else {
        printf("Ficheiro não existe!\n");
    }

}


void readXML(char *path){
    XMLDocument ficheiro;
    XMLError erro = ficheiro.LoadFile(path);
    if(!erro){
        XMLElement *x = ficheiro.FirstChildElement()->FirstChildElement();
        while (x){
            char *file = const_cast<char *>(x->Attribute("file"));
            x = x->NextSiblingElement();
            readFile(file);
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
	gluLookAt(px,py,pz,
		      0.0,0.0,0.0,
			  0.0f,1.0f,0.0f);

// put the geometric transformations here


// put drawing instructions here
    glPolygonMode(GL_FRONT_AND_BACK,tipo);
    for (int i = 0; i < formas.size(); ++i) {
        vector<Ponto*> pontos = formas[i]->getPontos();
        color = 0.0f;
        float colorValueChange = (float) 1/(pontos.size()/(float)(3));
        for (int j = 0; j <pontos.size() ; j+=3) {
            if (colorChange == 4){
                glColor3f(color,0,0);
            }else if(colorChange == 3){
                glColor3f(0,color,0);
            }
            else if (colorChange == 2){
                glColor3f(0,0,color);
            }
            else if(colorChange==1){
                glColor3f(color,color,color);
            }else{
                glColor3f(1.0f,1.0f,1.0f);
            }
            color+=colorValueChange;
            glBegin(GL_TRIANGLES);
                glVertex3f(pontos[j]->getX(),pontos[j]->getY(),pontos[j]->getZ());
                glVertex3f(pontos[j+1]->getX(),pontos[j+1]->getY(),pontos[j+1]->getZ());
                glVertex3f(pontos[j+2]->getX(),pontos[j+2]->getY(),pontos[j+2]->getZ());
            glEnd();

        }
    }

	// End of frame
	glutSwapBuffers();
}



// write function to process keyboard events

void processSpecialKeyboard(int key,int x,int y){
    switch (key) {
        case GLUT_KEY_UP:
            radius -= 0.05f;
            px = radius * cos(beta)*sin(alpha);
            pz = radius * cos(beta)*cos(alpha);
            py = radius * sin(beta);
            glutPostRedisplay();
            break;
        case GLUT_KEY_DOWN:
            radius += 0.05f;
            px = radius * cos(beta)*sin(alpha);
            pz = radius * cos(beta)*cos(alpha);
            py = radius * sin(beta);
            glutPostRedisplay();
            break;
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
        case 'w':
            if(beta<(float)M_PI/2) beta += 0.05f;
            beta = min((M_PI/2)-0.05f,beta);
            px = radius * cos(beta)*sin(alpha);
            pz = radius * cos(beta)*cos(alpha);
            py = radius * sin(beta);
            glutPostRedisplay();
            break;
        case 's':
            if(beta>=-(float)M_PI/2) beta -= 0.05f;
            beta = max((-M_PI/2)+0.05f,beta);
            px = radius * cos(beta)*sin(alpha);
            pz = radius * cos(beta)*cos(alpha);
            py = radius * sin(beta);
            glutPostRedisplay();
            break;
        case 'a':
            alpha += 0.05f;
            px = radius * cos(beta)*sin(alpha);
            pz = radius * cos(beta)*cos(alpha);
            py = radius * sin(beta);
            glutPostRedisplay();
            break;
        case 'd':
            alpha -= 0.05f;
            px = radius * cos(beta)*sin(alpha);
            pz = radius * cos(beta)*cos(alpha);
            py = radius * sin(beta);
            glutPostRedisplay();
            break;
        case 'i':
            tipo = GL_FILL;
            glutPostRedisplay();
            break;
        case 'o':
            tipo = GL_LINE;
            glutPostRedisplay();
            break;
        case 'p':
            tipo = GL_POINT;
            glutPostRedisplay();
            break;
        case 'c':
            colorChange = 1;
            glutPostRedisplay();
            break;
        case 'v':
            colorChange = 0;
            glutPostRedisplay();
            break;
        case 'r':
            colorChange = 4;
            glutPostRedisplay();
            break;
        case 'g':
            colorChange = 3;
            glutPostRedisplay();
            break;
        case 'b':
            colorChange = 2;
            glutPostRedisplay();
            break;
    }
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
    cout<< "|- UP_ARROW_KEY:                                                      |" <<endl;
    cout<< "|       Zoom in                                                       |" <<endl;
    cout<< "|- Down_ARROW_KEY:                                                    |" <<endl;
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
    cout<< "|   Pintar tudo a branco                                              |" <<endl;
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

    readXML(argv[1]);
// init GLUT and the window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("CG@DI-UM");
		
// Required callback registry 
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);

	
// put here the registration of the keyboard callbacks

    glutKeyboardFunc(processKeyboard);
    glutSpecialFunc(processSpecialKeyboard);

//  OpenGL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	
// enter GLUT's main cycle
	glutMainLoop();
	
	return 1;
}
