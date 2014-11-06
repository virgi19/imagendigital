#ifndef MODELO3D_H
#define MODELO3D_H
#include <iostream>
#include <vector>
#include "Cara.h"
#include "Punto3D.h"
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <string.h>
#include <math.h>
#include "Normal.h"
#include "Iluminacion.h"

using namespace std;

typedef std::vector<Cara> ListaFaces;
typedef std::vector<Punto3D> ListaVertex;

class Modelo3D: public Punto3D, public Cara {

private:

	int _NumCaras;
	int _NumVertices;
	int x0;
	int y0;
	unsigned tecla;

public:
//alfa y beta son los angulos de rotacion en el plano XY y seran conectados al raton
	float alfa;
	float beta;
	Modelo3D();
	Modelo3D(const int ncaras, const int nvertices);
	~Modelo3D();
	void init_lights();
	const Normal& CargarNormales(int FaceNumber);

	//Getters y Setters
	int getCaras();
	void setCaras(const int val);
	int getVertices();
	void setVertices(const int val);
	unsigned getTecla();
	void setTecla(unsigned tecla);
	void setModelColor(float color[]);


	//Funciones para pintar
	void Load_Model(char fileName[50]);
	void PintarSolido();
	void PintarAlambres();
	void IluminacionSuave();
	void Draw_Model(float scale_from_editor, int size_axes, float colorFondo[],
			float colorAlambre[]);
	void TipoPintura();

	float Model_color[3];
	ListaFaces ListaCaras;
	ListaVertex ListaPuntos3D;

};

#endif //MODELO3D_H
