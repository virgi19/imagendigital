#include "Modelo3D.h"

Modelo3D::Modelo3D() {

	setCaras(0);
	setVertices(0);
	this->alfa = 0;
	this->beta = 0;
	this->tecla = 0;
	this->Model_color[0] = 1.0;
	this->Model_color[1] = 1.0;
	this->Model_color[2] = 1.0;
}

Modelo3D::Modelo3D(const int ncaras, const int nvertices) {

	setCaras(ncaras);
	setVertices(nvertices);
	this->alfa = 0;
	this->beta = 0;
}

int Modelo3D::getCaras() {

	return this->_NumCaras;
}

void Modelo3D::init_lights() {

	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);
	glEnable(GL_CULL_FACE);
	//Focos.Activate(0);
	//Focos.Activate(1);
	//Focos.Activate(2);
	//Focos.Activate(3);
	//Focos.Activate(4);
	//Focos.Activate(5);
	//Focos.Activate(6);
	//Focos.Activate(7);
}

void Modelo3D::setCaras(const int val) {

	this->_NumCaras = val;
}

int Modelo3D::getVertices() {

	return this->_NumVertices;
}

void Modelo3D::setVertices(const int val) {

	this->_NumVertices = val;
}

unsigned Modelo3D::getTecla() {
	return tecla;
}

void Modelo3D::setTecla(unsigned tecla) {
	this->tecla = tecla;
}

void Modelo3D::setModelColor(float color[]){

	Model_color[0] = color[0];
	Model_color[1] = color[1];
	Model_color[2] = color[2];
}

void Modelo3D::Load_Model(char fileName[50])

{
	FILE *fich;
	int NVertex, NFaces, VertexNumber, FaceNumber, N, A, B, C;
	float X, Y, Z;
	char cad1[20], cad2[20], cad3[20], cad4[20];
	char cadena[100]; // Lo suf. larga para leer una línea

	if ((fich = fopen(fileName, "r")) == NULL) // open for reading  // open for reading
	{
		cout << " Error en la apertura. Es posible que el fichero no exista \n "
				<< endl;
		exit(1);
	}
	cout << "Opened File....." << endl;
	while (fgets(cadena, 100, fich) != NULL) {
		if (strncmp(cadena, "Named", 5) == 0) // Nvertex and NFaces in file
				{
			fscanf(fich, "%[Tri-mesh A-Za-z:-,: ]%d%[ ]%[Faces]:%d\n", cad1,
					&NVertex, cad2, cad3, &NFaces);
			setCaras(NFaces);
			setVertices(NVertex);
		}
		cout << "Nfaces and NVertex captured....." << NVertex << "  " << NFaces
				<< endl;
		ListaCaras.resize(getCaras());
		ListaPuntos3d.resize(getVertices());
		if (strncmp(cadena, "Vertex list:", 12) == 0) // Vertex List in file
			for (N = 1; N <= NVertex; N++) {
				fscanf(fich, "%[A-Za-z ]%d: %[X:] %f %[Y:] %f %[Z:] %f    \n",
						cad1, &VertexNumber, cad2, &X, cad3, &Y, cad4, &Z);
				cout << "Nº de vértice....." << VertexNumber << endl;
				ListaPuntos3d[VertexNumber].setX(X);
				ListaPuntos3d[VertexNumber].setY(Y);
				ListaPuntos3d[VertexNumber].setZ(Z);

			}
		if (strncmp(cadena, "Face list:", 10) == 0) // Face List in model file
			for (N = 1; N <= NFaces; N++) {
				fscanf(fich, "%[Face]%d: %[A:]%d %[B:]%d %[C:]%d\n", cad1,
						&FaceNumber, cad2, &A, cad3, &B, cad4, &C);
				fgets(cadena, 100, fich);
				ListaCaras[FaceNumber] = Cara(A, B, C);
			}
	}
	fclose(fich);

}

//Cuando vayamos a pintar sólido tenemos que pintar triángulos,
//es decir, necesitamos hacer un glBegin(GL_TRIANGLES)
void Modelo3D::PintarSolido() {

	for (int i = 0; i < this->ListaCaras.size(); i++) {

		//glPopMatrix();
		//glPushMatrix();

		//Establecer un color sólido basándonos
		//en un relleno con triángulos
		glBegin(GL_TRIANGLES);
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);

		glColor3f(Model_color[0], Model_color[1], Model_color[2]);

		glVertex3f(ListaPuntos3d[ListaCaras[i].getA()].getX(),
				ListaPuntos3d[ListaCaras[i].getA()].getY(),
				ListaPuntos3d[ListaCaras[i].getA()].getZ());
		//glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(ListaPuntos3d[ListaCaras[i].getB()].getX(),
				ListaPuntos3d[ListaCaras[i].getB()].getY(),
				ListaPuntos3d[ListaCaras[i].getB()].getZ());
		//glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(ListaPuntos3d[ListaCaras[i].getC()].getX(),
				ListaPuntos3d[ListaCaras[i].getC()].getY(),
				ListaPuntos3d[ListaCaras[i].getC()].getZ());
		//glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(ListaPuntos3d[ListaCaras[i].getA()].getX(),
				ListaPuntos3d[ListaCaras[i].getA()].getY(),
				ListaPuntos3d[ListaCaras[i].getA()].getZ());

		glDisable(GL_LIGHTING);
		glEnd();

	}
}

void Modelo3D::PintarAlambres() {

	for (int i = 0; i < this->ListaCaras.size(); i++) {

		//glPopMatrix();
		//glPushMatrix();

		//Establecer un color sólido
		//glBegin(GL_POLYGON);
		glBegin(GL_LINES);
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);

		//Aquí establecemos el color de las alambres
		glColor3f(Model_color[0], Model_color[1], Model_color[2]);

		glVertex3f(ListaPuntos3d[ListaCaras[i].getA()].getX(),
				ListaPuntos3d[ListaCaras[i].getA()].getY(),
				ListaPuntos3d[ListaCaras[i].getA()].getZ());
		//glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(ListaPuntos3d[ListaCaras[i].getB()].getX(),
				ListaPuntos3d[ListaCaras[i].getB()].getY(),
				ListaPuntos3d[ListaCaras[i].getB()].getZ());
		//glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(ListaPuntos3d[ListaCaras[i].getC()].getX(),
				ListaPuntos3d[ListaCaras[i].getC()].getY(),
				ListaPuntos3d[ListaCaras[i].getC()].getZ());
		//glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(ListaPuntos3d[ListaCaras[i].getA()].getX(),
				ListaPuntos3d[ListaCaras[i].getA()].getY(),
				ListaPuntos3d[ListaCaras[i].getA()].getZ());

		glDisable(GL_LIGHT0);
		glDisable(GL_LIGHTING);
		glEnd();

	}
}

void Modelo3D::Draw_Model(float scale_from_editor, int size_axes,
		float colorFondo[], float colorAlambre[]) {

	GLfloat material_difuso[4], material_ambiente[4], material_specular[4],
			material_emission[4];
	GLfloat luzdifusa[4], luzambiente[4], luzspecular[4], posicion0[4],
			rotacion[4];
	GLfloat brillo;

	//Aquí establecemos el color del fondo
	glClearColor(colorFondo[0], colorFondo[1], colorFondo[2], 1.0f);
	glClearStencil(0);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(20.0f, 1.0f, 1.0f, 10.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0f, 0.0f, 5.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	glScalef(0.003, 0.003, 0.003);
	glRotated(this->alfa, 1.0f, 0.0f, 0.0f);
	glRotated(this->beta, 0.0f, 1.0f, 0.0f);

	//Poner color al modelo
	setModelColor(colorAlambre);
	TipoPintura();

	glFlush();
	glutSwapBuffers();
}

//Función para elegir entre el tipo de pintura que queremos
//es decir, sólido o alambre
void Modelo3D::TipoPintura() {

	switch (getTecla()) {

	case 32:
		PintarSolido();
		break;

	default:
		PintarAlambres();
		break;

	}
}

Modelo3D::~Modelo3D() {
}
/*
 * Modelo3D.cpp
 *
 *  Created on: 9/10/2014
 *      Author: isma
 */

