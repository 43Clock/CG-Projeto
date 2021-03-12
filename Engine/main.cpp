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

float alpha = 0.0f;
float beta = 0.0f;
float radius = 6.0f;

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
        for (int j = 0; j <pontos.size() ; j+=3) {
            if(colorChange){
                glColor3f(fabs(sin(color)),fabs(sin(color)),fabs(sin(color)));
                color+=0.01f;
            }else{
                glColor3f(1.0f,1.0f,1.0f);
            }
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



void processKeyboard(unsigned char key,int x,int y){
    switch (key) {
        case 'w':
            if(beta<1.54f) beta += 0.05f;
            px = radius * cos(beta)*sin(alpha);
            pz = radius * cos(beta)*cos(alpha);
            py = radius * sin(beta);
            glutPostRedisplay();
            break;
        case 's':
            if(beta>=-1.54f) beta -= 0.05f;
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
    }
}


//@TODO Fazer menu a explicar os comandos e meter cores mais bonitas
int main(int argc, char **argv) {
    if (argc >2){
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
