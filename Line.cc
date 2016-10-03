/*
 * Line.cpp
 *
 *  Created on: Oct 2, 2016
 *      Author: Lee
 */

#include "Line.h"
#include "Vector.h"

Line::Line(point p,Vector d):_d(d){
	_p = p;
	_d.normalize();
}

point Line::getP() const{
	return _p;
}

Vector Line::getD() const{
	return _d;
}
