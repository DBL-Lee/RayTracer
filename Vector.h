/*
 * Vector.h
 *
 *  Created on: Oct 2, 2016
 *      Author: Lee
 */

#ifndef VECTOR_H_
#define VECTOR_H_

#include <string>
#include <math.h>

class Vector {
private:
	float _x,_y,_z;
public:
	Vector(float x,float y, float z);
	Vector(const Vector &v);
	float getX() const;
	float getY() const;
	float getZ() const;
	float length() const;
	void normalize();
	void to_negative();
	float dot_prod(const Vector& rhs);
	Vector cross_prod(const Vector& rhs);
	std::string tostr();
};

Vector operator+(const Vector& v1, const Vector& v2);

Vector operator-(const Vector& v1, const Vector& v2);

Vector operator*(float f, const Vector& v);

#endif /* VECTOR_H_ */
