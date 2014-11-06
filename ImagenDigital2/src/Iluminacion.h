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

	void ActivarIluminacionConstante();
	void DesactivarIluminacionConstante();

	void ActivarIluminacionSuave();
	void DesactivarIluminacionSuave();

	~Iluminacion();
};

#endif /* ILUMINACION_H_ */
