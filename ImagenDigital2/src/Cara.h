
#include "Normal.h"
#ifndef CARA_H
#define CARA_H
//6 MÉTODOS QUE SON PÚBLICOS, 3 SETS Y 3 GETS

class Cara
{

public:

	Cara();
	Cara(const int A, const int B, const int C);
	Cara(const int A, const int B, const int C, Normal normal);
	~ Cara();
	int getA();
	int getB();
	int getC();
	
	void setA(const int valor);
	void setB(const int valor);
	void setC(const int valor);
	const Normal& getNormal() const;
	void setNormal(const Normal& normal);

private:

int _A, _B, _C;
Normal normal;
};

#endif
