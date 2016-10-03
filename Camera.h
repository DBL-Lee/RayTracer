/*
 * Camera.h
 *
 *  Created on: Oct 2, 2016
 *      Author: Lee
 */


#ifndef CAMERA_H_
#define CAMERA_H_


#include <iostream>
#include "Point.h"
#include "Vector.h"
#include "Line.h"

class Camera {
private:
	point _eye;
	float _d;
	Vector _u,_v,_w;
	int _pixelx,_pixely;
	float _width,_height;
public:
	Camera(point eye,float d, Vector lookAt, int nx, int ny, float width, float height);
	Line getRayThroughPixel(int i, int j);
	float getWidth();
	float getHeight();
	int getPixelX();
	int getPixelY();
};

#endif /* CAMERA_H_ */
