/*
 * Normal.cpp
 *
 *  Created on: 6/11/2014
 *      Author: isma
 */

#include "Normal.h"

Normal::Normal() {

	this->A = 0;
	this->B = 0;
	this->C = 0;
}

Normal::Normal(float _A, float _B, float _C) {

	this->A = _A;
	this->B = _B;
	this->C = _C;
}

float Normal::getA() const {
	return A;
}

void Normal::setA(float a) {
	A = a;
}

float Normal::getB() const {
	return B;
}

void Normal::setB(float b) {
	B = b;
}

float Normal::getC() const {
	return C;
}

void Normal::setC(float c) {
	C = c;
}

Normal::~Normal() {
	// TODO Auto-generated destructor stub
}

