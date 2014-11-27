/*
 * Iluminacion.cpp
 *
 *  Created on: 6/11/2014
 *      Author: isma
 */

#include "Iluminacion.h"

Iluminacion::Iluminacion() {

}

Iluminacion::~Iluminacion() {

}

void Iluminacion::SeleccionarFoco(int Nfoco) {
	switch (Nfoco) {

	case 1:

		if (!glIsEnabled(GL_LIGHT1)) {
			GLfloat posicion[] = { 10.0f, 10.0f, 10.0f, 0.0f };
			GLfloat ambiente[] = { 0.5f, 0.25f, 0.5f, 0.0f };
			GLfloat difusa[] = { 1.0f, 1.0f, 0.25f, 0.5f };
			GLfloat especular[] = { 1.0f, 0.0f, 0.25f, 1.0f };

			glEnable(GL_LIGHTING);
			glLightfv(GL_LIGHT1, GL_AMBIENT, ambiente);
			glLightfv(GL_LIGHT1, GL_DIFFUSE, difusa);
			glLightfv(GL_LIGHT1, GL_SPECULAR, especular);
			glLightfv(GL_LIGHT1, GL_POSITION, posicion);

			glEnable(GL_LIGHT1);
		}

		else
			glDisable(GL_LIGHT1);

		break;

	case 2:
		if (!glIsEnabled(GL_LIGHT2)) {

			GLfloat posicion2[] = { 10.0f, 60.0f, 50.0f, 0.0f };
			GLfloat ambiente2[] = { 0.5f, 0.25f, 0.5f, 0.0f };
			GLfloat difusa2[] = { 0.0f, 1.0f, 0.0f, 1.0f };
			GLfloat especular2[] = { 0.5f, 0.5f, 0.25f, 1.0f };
			glLightfv(GL_LIGHT2, GL_POSITION, posicion2);
			glLightfv(GL_LIGHT2, GL_AMBIENT, ambiente2);
			glLightfv(GL_LIGHT2, GL_SPECULAR, difusa2);
			glLightfv(GL_LIGHT2, GL_DIFFUSE, especular2);

			glEnable(GL_LIGHT2);
		} else
			glDisable(GL_LIGHT2);

		break;

	case 3:
		if (!glIsEnabled(GL_LIGHT3)) {

			GLfloat posicion2[] = { 10.0f, 60.0f, 50.0f, 0.0f };
			GLfloat ambiente2[] = { 0.5f, 0.25f, 0.5f, 0.0f };
			GLfloat difusa2[] = { 0.0f, 1.0f, 0.0f, 1.0f };
			GLfloat especular2[] = { 0.5f, 0.5f, 0.25f, 1.0f };
			glLightfv(GL_LIGHT3, GL_POSITION, posicion2);
			glLightfv(GL_LIGHT3, GL_AMBIENT, ambiente2);
			glLightfv(GL_LIGHT3, GL_SPECULAR, difusa2);
			glLightfv(GL_LIGHT3, GL_DIFFUSE, especular2);

			glEnable(GL_LIGHT3);
		} else
			glDisable(GL_LIGHT3);

		break;

	case 0:
		if (!glIsEnabled(GL_LIGHT0)) {

			glEnable(GL_LIGHT0);
		} else
			glDisable(GL_LIGHT0);
		break;
	}

}
