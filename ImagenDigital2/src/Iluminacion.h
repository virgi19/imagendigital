/*
 * Iluminacion.h
 *
 *  Created on: 6/11/2014
 *      Author: isma
 */
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#ifndef ILUMINACION_H_
#define ILUMINACION_H_

class Iluminacion {

public:
	Iluminacion();

	~Iluminacion();

	void SeleccionarFoco(int Nfoco);
};

#endif /* ILUMINACION_H_ */
