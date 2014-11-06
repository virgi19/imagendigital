/*
 * Normal.h
 *
 *  Created on: 6/11/2014
 *      Author: isma
 */

#ifndef NORMAL_H_
#define NORMAL_H_

class Normal {

private:
	float A;
	float B;
	float C;
public:
	Normal();
	Normal(float _A, float _B, float _C);
	~Normal();
	float getA() const;
	void setA(float a);
	float getB() const;
	void setB(float b);
	float getC() const;
	void setC(float c);
};

#endif /* NORMAL_H_ */
