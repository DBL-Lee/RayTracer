/*
 * Point.h
 *
 *  Created on: Oct 2, 2016
 *      Author: Lee
 */

#ifndef POINT_H_
#define POINT_H_
#include "Vector.h"

struct point {
	float x,y,z;
	Vector toVector(){
		return Vector(x,y,z);
	};
};

#endif /* POINT_H_ */
