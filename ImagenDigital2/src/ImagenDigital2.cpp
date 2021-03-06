//============================================================================
// Name        : ImagenDigital2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Modelo3D.h"
#include "Camera.h"

using namespace std;

unsigned char teclaPulsadaTipoPintura = 0;
unsigned char teclaPulsadaFoco = 0;
int window;
Modelo3D My_Model = Modelo3D();
Iluminacion Focos;
Camera Camara = Camera();

//Por defecto cuando iDibujo vale e se pinta loa figura de color blanco
int iDibujo = 3;

//Por defecto cuando iFondo vale 0 se pinta el fondo de color negro
int iFondo = 0;
int x1;
int x2;

typedef enum {
	FONDO1, FONDO2, FONDO3, FONDO4, DIBUJO1, DIBUJO2, DIBUJO3, DIBUJO4
} opcionesMenu;
float xold;
float yold;

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

void creacionMenu(void) {

	int menuFondo, menuDibujo, menuMaterial, menuPrincipal;

	menuFondo = glutCreateMenu(onMenu);
	glutAddMenuEntry("Negro", FONDO1);
	glutAddMenuEntry("Verde oscuro", FONDO2);
	glutAddMenuEntry("Azul oscuro", FONDO3);

	menuDibujo = glutCreateMenu(onMenu);
	glutAddMenuEntry("Blanco", DIBUJO1);
	glutAddMenuEntry("Verde claro", DIBUJO2);
	glutAddMenuEntry("Azul claro", DIBUJO3);

	//menuMaterial = glutCreateMenu(onMenu);
	//glutAddMenuEntry("Rojo", DIBUJO1);
	//glutAddMenuEntry("Verde", DIBUJO2);
	//glutAddMenuEntry("Azul", DIBUJO3);
	//glutAddMenuEntry("Blanco", DIBUJO3);

	menuPrincipal = glutCreateMenu(onMenu);
	glutAddSubMenu("Color de fondo", menuFondo);
	glutAddSubMenu("Color de dibujo", menuDibujo);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

//Esta función no la vamos a a utilizar ya que nostros queremos dibujar
//figuras distintas, no sólo una tetera.
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

void onMouse(int button, int state, int x, int y) {
	if ((button == GLUT_LEFT_BUTTON) & (state == GLUT_DOWN)) {
		x1 = x;
		x2 = y;
		//y0 = y; //actualiza los valores de x,y
	}
}

void onMotion(int x, int y) {
	My_Model.alfa = (My_Model.alfa + (y - yold));
	My_Model.beta = (My_Model.beta + (y - yold));
	xold = x;
	yold = y;
	cout << "X " << x << " Y " << y << endl;
	glutPostRedisplay();
}

//Permite conocer qué tecla hemos pulsado
void TeclaPulsada(unsigned char key, int x, int y) {

	switch (key) {

	//Tecla a
	case 97:
		My_Model.Look = alambre;
		break;

		//Tecla s
	case 115:
		My_Model.Look = solido;
		break;

		//Tecla d
	case 100:
		My_Model.Look = plana;
		break;

		//Tecla f
	case 102:
		My_Model.Look = suave;
		break;

	case 48:
		Focos.SeleccionarFoco(0);
		break;
	case 49:
		Focos.SeleccionarFoco(1);
		break;
	case 50:
		Focos.SeleccionarFoco(2);
		break;
	case 51:
		Focos.SeleccionarFoco(3);
		break;

		//Materiales

	//Tecla r
	case 114:
		My_Model.material = rojo;
		break;

	//Tecla b de blue
	case 98:
		My_Model.material = azul;
		break;

	//Tecla g de green
	case 103:
		My_Model.material = verde;
		break;

	//Tecla w de white
	case 119:
		My_Model.material = blanco;
		break;

	}

}

void initGL() {

	glEnable(GL_NORMALIZE);
	glEnable(GL_CULL_FACE);
	glEnable(GL_LIGHTING);

}

void DibujarFigura() {

	//Matriz de floats que contiene los valores de los distintos colores
	float colores[6][3] = { { 0.00f, 0.00f, 0.00f }, // 0 - negro
			{ 0.06f, 0.25f, 0.13f }, // 1 - verde oscuro
			{ 0.10f, 0.07f, 0.33f }, // 2 - azul oscuro
			{ 1.00f, 1.00f, 1.00f }, // 3 - blanco
			{ 0.12f, 0.50f, 0.26f }, // 4 - verde claro
			{ 0.20f, 0.14f, 0.66f }, // 5 - azul claro
			};

	//Pasamos al Draw_Model los valores del fondo y del color de las alambres o de las caras
	My_Model.Draw_Model(0.009, 20, colores[iFondo], colores[iDibujo]);
}

void Pintar() {

//Permite dibujar la figura que nosotros hayamos definido
	glutDisplayFunc(DibujarFigura);

//Se llama a una función capaz de crear un menú con diversas
//funciones.
	creacionMenu();

//Función que nos permite interactuar con la figura. Permite
//realizar rotaciones en la figura cuando dejamos pulsado el
//ratón.
	glutMouseFunc(onMouse);

//Establece el giro de la figura modificando sus respectivos alfa
//y beta.
	glutMotionFunc(onMotion);

//glutIdleFunc permite dibujar la esfera cuando la ventana
//está inactiva. Si no llamamos a esta función la ventana
//aparecerá inicialmente de color blanco sin mostrar nuestra figura.
//Sólo haría falta hacer click sobre la ventana para que se vea la figura.
	glutIdleFunc(DibujarFigura);

//Mediante glutKeyboardFunc cambiamos la pintura del
//elemento que se muestra en la pantalla
	glutKeyboardFunc(TeclaPulsada);

}

int main(int argc, char **argv) {

	My_Model.Load_Model("Images/Esfera.asc");
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(100, 100);
	window = glutCreateWindow("Planetario");
	initGL();
	Pintar();
	glutMainLoop();

}
