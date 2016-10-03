/*
 * Sphere.h
 *
 *  Created on: Oct 2, 2016
 *      Author: Lee
 */

#ifndef SPHERE_H_
#define SPHERE_H_
#include <iostream>
#include "Surface.h"
#include "Point.h"
#include "Material.h"

class Sphere: public Surface {
private:
	Material* _m;
	point _o;
	float _r;
public:
	Sphere(point o, float r, Material* m);
	virtual bool intersect_ray(const Line& ray,float& t);
	virtual Material* getMaterial();
};

#endif /* SPHERE_H_ */
