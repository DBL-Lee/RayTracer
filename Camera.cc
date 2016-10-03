/*
 * Camera.cpp
 *
 *  Created on: Oct 2, 2016
 *      Author: Lee
 */

#include "Camera.h"
using namespace std;

Camera::Camera(point eye,float d, Vector lookAt, int pixelx, int pixely, float width, float height):
	_u(lookAt.cross_prod(Vector(0,1,0))),_v(0,0,0),_w(lookAt){
	if (_u.length()==0){
		throw invalid_argument( "Cannot look upwards!" );
	}
	_eye = eye;
	_d = d;

	_v = _u.cross_prod(lookAt);
	_w.to_negative();

	_u.normalize();
	_v.normalize();
	_w.normalize();


	_pixelx = pixelx;
	_pixely = pixely;
	_width = width;
	_height = height;
}

Line Camera::getRayThroughPixel(int i, int j){
	float l = -_width/2;
	float b = -_height/2;
	float u = l + _width*(j+0.5)/_pixelx;
	float v = b + _height*(i+0.5)/_pixely;

	return Line(_eye,u*_u + v*_v - _d*_w);
}

float Camera::getWidth(){
	return _width;
}

float Camera::getHeight(){
	return _height;
}

int Camera::getPixelX(){
	return _pixelx;
}

int Camera::getPixelY(){
	return _pixely;
}
