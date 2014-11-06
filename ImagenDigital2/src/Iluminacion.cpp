/*
 * Iluminacion.cpp
 *
 *  Created on: 6/11/2014
 *      Author: isma
 */

#include "Iluminacion.h"

Iluminacion::Iluminacion() {
	// TODO Auto-generated constructor stub

}

void Iluminacion::ActivarIluminacionConstante() {

	glShadeModel(GL_FLAT);
}

void Iluminacion::DesactivarIluminacionConstante() {
}

void Iluminacion::ActivarIluminacionSuave() {

	GLfloat light_ambient[] = { 1.0, 0.0, 0.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GLU_SMOOTH);

}

void Iluminacion::DesactivarIluminacionSuave() {

	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHTING);
}

Iluminacion::~Iluminacion() {
	// TODO Auto-generated destructor stub
}

