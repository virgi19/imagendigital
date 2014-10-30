/*
 * Cara.cpp
 *
 *  Created on: 9/10/2014
 *      Author: isma
 */

#include "Cara.h"

Cara::Cara() {

	this->_A = 0;
	this->_B = 0;
	this->_C = 0;
}

Cara::Cara(const int A, const int B, const int C){

	this->_A = A;
	this->_B = B;
	this->_C = C;
}

int Cara::getA(){

	return this->_A;
}

int Cara::getB(){

	return this->_B;
}

int Cara::getC(){

	return this->_C;
}

void Cara::setA(const int valor){

	this->_A = valor;
}

void Cara::setB(const int valor){

	this->_B = valor;
}



void Cara::setC(const int valor){

	this->_C = valor;
}

Cara::~Cara(){

}

