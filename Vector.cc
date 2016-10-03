#include "Vector.h"

Vector::Vector(float x,float y, float z) {
	_x = x;
	_y = y;
	_z = z;
}

Vector::Vector(const Vector &v){
	_x = v.getX();
	_y = v.getY();
	_z = v.getZ();
}

float Vector::getX() const{
	return _x;
}

float Vector::getY() const{
	return _y;
}

float Vector::getZ() const{
	return _z;
}

float Vector::length() const{
	return sqrt(_x*_x+_y*_y+_z*_z);
}

void Vector::normalize(){
	float len = length();
	_x = _x/len;
	_y = _y/len;
	_z = _z/len;
}

void Vector::to_negative(){
	_x = -_x;
	_y = -_y;
	_z = -_z;
}

float Vector::dot_prod(const Vector& rhs){
	return _x*rhs.getX()+_y*rhs.getY()+_z*rhs.getZ();
}

Vector Vector::cross_prod(const Vector& rhs){
	float a = _y * rhs.getZ() - _z * rhs.getY() ;
	float b = _z * rhs.getX() - _x * rhs.getZ() ;
	float c = _x * rhs.getY() - _y * rhs.getX() ;
	Vector product(a,b,c);
	return product;
}

std::string Vector::tostr(){
	return "x="+std::to_string(_x)+" y="+std::to_string(_y)+" z="+std::to_string(_z);
}

Vector operator+(const Vector& v1, const Vector& v2){
	return Vector(v1.getX()+v2.getX(),v1.getY()+v2.getY(),v1.getZ()+v2.getZ());
}

Vector operator-(const Vector& v1, const Vector& v2){
	return Vector(v1.getX()-v2.getX(),v1.getY()-v2.getY(),v1.getZ()-v2.getZ());
}

Vector operator*(float f, const Vector& v){
	return Vector(f*v.getX(),f*v.getY(),f*v.getZ());
}
