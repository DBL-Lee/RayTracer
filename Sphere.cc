/*
 * Sphere.cpp
 *
 *  Created on: Oct 2, 2016
 *      Author: Lee
 */

#include "Sphere.h"
using namespace std;

Sphere::Sphere(point o, float r, Material* m){
	_o = o;
	_r = r;
	_m = m;
}

bool Sphere::intersect_ray(const Line& ray,float& t){
	Vector pmo = ray.getP().toVector()-_o.toVector();
	float b = ray.getD().dot_prod(pmo);
	float ddotd = ray.getD().dot_prod(ray.getD());
	float determinant = (b*b-ddotd*(pmo.dot_prod(pmo)-_r*_r));
	if (determinant<0){
		return false;
	}
	float tmin = (-ray.getD().dot_prod(pmo)-sqrt(determinant))/ddotd;
	float tmax = (-ray.getD().dot_prod(pmo)+sqrt(determinant))/ddotd;
	if (tmin>0){
		t = tmin;
	}else if (tmax>0){
		t = tmax;
	}else{
		return false;
	}
	return true;
}

Material* Sphere::getMaterial(){
	return _m;
}
