//============================================================================
// Name        : ImagenDigital2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Modelo3D.h"

using namespace std;

int window;
Modelo3D My_Model = Modelo3D();
int iDibujo = 3;
int iFondo = 0;
typedef enum {
	FONDO1, FONDO2, FONDO3, FONDO4, DIBUJO1, DIBUJO2, DIBUJO3, DIBUJO4
} opcionesMenu;
float xold;
float yold;
int x0;
int y0;

void onMenu(int opcion) {
	switch (opcion) {
	case FONDO1:
		iFondo = 0;
		break;
	case FONDO2:
		iFondo = 1;
		break;
	case FONDO3:
		iFondo = 2;
		break;
	case DIBUJO1:
		iDibujo = 3;
		break;
	case DIBUJO2:
		iDibujo = 4;
		break;
	case DIBUJO3:
		iDibujo = 5;
		break;
	}
	glutPostRedisplay();
}

void onMouse(int button, int state, int x, int y) {
	if ((button == GLUT_LEFT_BUTTON) & (state == GLUT_DOWN)) {
		x0 = x;
		y0 = y; //actualiza los valores de x,y
	}
}

void display(void) {
	float colores[6][3] = { { 0.00f, 0.00f, 0.00f }, // 0 - negro
			{ 0.06f, 0.25f, 0.13f }, // 1 - verde oscuro
			{ 0.10f, 0.07f, 0.33f }, // 2 - azul oscuro
			{ 1.00f, 1.00f, 1.00f }, // 3 - blanco
			{ 0.12f, 0.50f, 0.26f }, // 4 - verde claro
			{ 0.20f, 0.14f, 0.66f }, // 5 - azul claro
			};
	glClearColor(colores[iFondo][0], colores[iFondo][1], colores[iFondo][2],
			1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(colores[iDibujo][0], colores[iDibujo][1], colores[iDibujo][2]);
	glutWireTeapot(0.5);
	glFlush();
	glutSwapBuffers();
}

void creacionMenu(void) {
	int menuFondo, menuDibujo, menuPrincipal;
	menuFondo = glutCreateMenu(onMenu);
	glutAddMenuEntry("Negro", FONDO1);
	glutAddMenuEntry("Verde oscuro", FONDO2);
	glutAddMenuEntry("Azul oscuro", FONDO3);
	menuDibujo = glutCreateMenu(onMenu);
	glutAddMenuEntry("Blanco", DIBUJO1);
	glutAddMenuEntry("Verde claro", DIBUJO2);
	glutAddMenuEntry("Azul claro", DIBUJO3);
	menuPrincipal = glutCreateMenu(onMenu);
	glutAddSubMenu("Color de fondo", menuFondo);
	glutAddSubMenu("Color de dibujo", menuDibujo);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void onMotion(int x, int y) {
	My_Model.alfa = (My_Model.alfa + (y - yold));
	My_Model.beta = (My_Model.beta + (y - yold));
	xold = x;
	yold = y;
	cout << "X " << x << " Y " << y << endl;
//glutPostRedisplay();
}

void PintarModelo() {

	//display();
	creacionMenu();
	glutMouseFunc(onMouse);
	glutMotionFunc(onMotion);
	My_Model.Draw_Model(0.0, 20);

}

int main(int argc, char **argv) {

	My_Model.Load_Model("Images/Esfera.asc");
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(100, 100);
	window = glutCreateWindow("Planetario");
	glutDisplayFunc(&PintarModelo);

	//glutIdleFunc se utiliza principalmente para hacer que nuestro modelo pueda girar.
	glutIdleFunc(&PintarModelo);
	glutMainLoop();

}
