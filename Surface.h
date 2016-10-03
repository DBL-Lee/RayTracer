/*
 * Surface.h
 *
 *  Created on: Oct 2, 2016
 *      Author: Lee
 */

#ifndef SURFACE_H_
#define SURFACE_H_
#include "Vector.h"
#include "Material.h"
#include "Line.h"

class Surface {
public:
	virtual ~Surface() {};
	virtual bool intersect_ray(const Line& ray,float& t) = 0;
	virtual Material* getMaterial() =0;
};

#endif /* SURFACE_H_ */
