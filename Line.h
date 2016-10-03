/*
 * Line.h
 *
 *  Created on: Oct 2, 2016
 *      Author: Lee
 */

#ifndef LINE_H_
#define LINE_H_
#include "Point.h"
#include "Vector.h"

class Line {
private:
	point _p;
	Vector _d;
public:
	Line(point p,Vector d);
	point getP() const;
	Vector getD() const;
};

#endif /* LINE_H_ */
