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

using namespace std;

typedef std::vector<Cara> ListaFaces;
typedef std::vector<Punto3D> ListaVertex;

class Modelo3D: public Punto3D, public Cara {

private:

	int _NumCaras;
	int _NumVertices;
	int x0;
	int y0;


public:
//alfa y beta son los angulos de rotacion en el plano XY y seran conectados al raton
	float alfa;
	float beta;
	Modelo3D();
	Modelo3D(const int ncaras, const int nvertices);
	~Modelo3D();
	void init_lights();
	int getCaras();
	void setCaras(const int val);
	int getVertices();
	void setVertices(const int val);
	void Load_Model(char fileName[50]);
	void PintarSolido();
	void PintarAlambres();
	void Draw_Model(float scale_from_editor, int size_axes);
	float Model_color[3];
	ListaFaces ListaCaras;
	ListaVertex ListaPuntos3d;

};

#endif //MODELO3D_H
