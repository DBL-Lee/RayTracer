/*
 * raytracer.cpp
 *
 *  Created on: Oct 2, 2016
 *      Author: Lee
 */

#include "raytracer.h"
#include <fstream>

void
writeRgba (const char fileName[],
           const Rgba *pixels,
           int width,
           int height)
{
    //
    // Write an RGBA image using class RgbaOutputFile.
    //
    //	- open the file
    //	- describe the memory layout of the pixels
    //	- store the pixels in the file
    //


    RgbaOutputFile file (fileName, width, height, WRITE_RGBA);
    file.setFrameBuffer (pixels, 1, width);
    file.writePixels (height);
}


void parse(const char *file,
		vector<Surface*> &surfaces,
		Camera** camera,
		vector<Material*> &materials) {
	ifstream in(file);
	char buffer[1025];
	string cmd;

	Material *current_material = nullptr;

	for (int line=1; in.good(); line++) {
		in.getline(buffer,1024);
		buffer[in.gcount()]=0;

		cmd="";

		istringstream iss(buffer);

		iss >> cmd;
		if (cmd[0]=='/' or cmd.empty()) {
			continue;
		} else if (cmd=="s") {
			if (!current_material){
				throw invalid_argument( "Include material before geometry!" );
			}
			float3 pos; float r;
			iss >> pos >> r;
			point origin = {pos.x,pos.y,pos.z};
			Surface* s = new Sphere(origin,r,current_material);
			surfaces.push_back(s);
		} else if (cmd=="t"){
			//float3 a,b,c;
			//iss >> a,b,c;
			//triangle(a,b,c);
		} else if (cmd=="p") {
			float3 n; float d;
			iss >> n >> d;
			//plane(n,d);
		} else if (cmd=="c") {
			float3 pos,dir; float d,iw,ih; int pw,ph;
			iss >> pos >> dir >> d >> iw >> ih >> pw >> ph;
			point eye = {pos.x,pos.y,pos.z};
			*camera = new Camera(eye,d, Vector(dir.x,dir.y,dir.z), pw, ph, iw, ih);
		} else if (cmd=="l") {
			iss >> cmd;
			if (cmd=="p") {
				float3 pos,rgb;
				iss >> pos >> rgb;
				//pointLight(pos,rgb);
			} else if (cmd=="d") {
				float3 dir,rgb;
				iss >> dir >> rgb;
				//directionalLight(dir,rgb);
			} else if (cmd=="a") {
				float3 rgb;
				iss >> rgb;
				//ambientLight(rgb);
			} else {
				cout << "Parser error: invalid light at line " << line << endl;
			}
		} else if (cmd=="m") {
			float3 diff,spec,refl; float r;
			iss >> diff >> spec >> r >> refl;
			current_material = new Material(diff.x,diff.y,diff.z,spec.x,spec.y,spec.z,refl.x,refl.y,refl.z,r);
			Material* m = current_material;
			materials.push_back(m);
		} else {
			cout << "Parser error: invalid command at line " << line << endl;
		}
	}

	in.close();
}

bool file_exist(char *name) {
    ifstream f(name);
    return f.good();
}

int main (int argc, char *argv[])
{
	if (!file_exist(argv[1])){
		cerr << "File does not exist!"<<endl;
		return 1;
	}

	vector<Surface*> surfaces;
	Camera* c = nullptr;
	vector<Material*> materials;
	parse(argv[1],surfaces,&c,materials);
	cout << "finish parsing scene file" << endl;
	int h = c->getPixelY();
	int w = c->getPixelX();
	Array2D<Rgba> pixel (h,w);

	cout << "start ray tracing" << endl;
	//Iterate through pixels
	for (int i = 0; i < h ; i++){
		for (int j=0; j<w; j++){
			float minimum_distance = numeric_limits<float>::max();

			//Find the ray going through pixel i,j. h-1-i due to
			//upside down y-axis
			Line ray = c->getRayThroughPixel(h-1-i,j);

			//Iterate through list of surfaces
			for (auto &surface:surfaces){
				float t = 0.;

				//Find out if ray intersect the surface
				if (surface->intersect_ray(ray,t)){

					//If intersected in front and surface is in
					//front of previous surfaces
					if (t>0 && t<minimum_distance){

						minimum_distance = t;
						Rgba &px = pixel[i][j];

						//Get material of surface
						Material* m = surface->getMaterial();
						px.r = half(m->getdr());
						px.b = half(m->getdb());
						px.g = half(m->getdg());
					}
				}
			}

		}
	}

	cout << "writing to file" << endl;
	writeRgba ("hw1.exr", &pixel[0][0], w, h);
	cout << "finished"<<endl;
    return 0;
}
