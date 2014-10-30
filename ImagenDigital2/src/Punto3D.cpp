#include "Punto3D.h"

Punto3D::Punto3D() {

	this->_X = 0;
	this->_Y = 0;
	this->_Z = 0;
}

Punto3D::Punto3D(const float x, const float y, const float z) {

	this->_X = x;
	this->_Y = y;
	this->_Z = z;
}

float Punto3D::getX() {

	return this->_X;
}

float Punto3D::getY() {

	return this->_Y;
}

float Punto3D::getZ() {

	return this->_Z;
}

void Punto3D::setX(const float valor) {

	this->_X = valor;
}


void Punto3D::setY(const float valor) {

	this->_Y = valor;
}


void Punto3D::setZ(const float valor) {

	this->_Z = valor;
}

Punto3D::~Punto3D() {
}
/*
 * Punto3D.cpp
 *
 *  Created on: 9/10/2014
 *      Author: isma
 */

