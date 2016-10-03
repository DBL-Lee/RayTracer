/*
 * raytracer.h
 *
 *  Created on: Oct 2, 2016
 *      Author: Lee
 */
#include <ImfRgbaFile.h>
#include <ImfStringAttribute.h>
#include <ImfMatrixAttribute.h>
#include <ImfArray.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <limits>

#include "Vector.h"
#include "Point.h"
#include "Sphere.h"
#include "Material.h"
#include "Camera.h"

using namespace std;
using namespace Imf;

struct float3 {
  float x,y,z;
};
inline istream &operator>>(istream &is, float3 &f) {
  return is>>f.x>>f.y>>f.z;
}
inline ostream &operator<<(ostream &os, float3 &f) {
  return os<<"<"<<f.x<<","<<f.y<<","<<f.z<<">";
}
