#ifndef PUNTO3D_H
#define PUNTO3D_H
//6 MÉTODOS QUE SON PÚBLICOS, 3 SETS Y 3 GETS

class Punto3D
{

public:

	Punto3D();
	Punto3D(const float x, const float y, const float z);
	~ Punto3D();
	float getX();
	float getY();
	float getZ();
	
	void setX(const float valor);
	void setY(const float valor);
	void setZ(const float valor);

private:

float _X, _Y, _Z;

};

#endif //fin de PUNTO3D_H