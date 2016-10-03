/*
 * Material.h
 *
 *  Created on: Oct 2, 2016
 *      Author: Lee
 */

#ifndef MATERIAL_H_
#define MATERIAL_H_

class Material {
private:
	float _dr,_dg,_db;
	float _sr,_sg,_sb;
	float _ir,_ig,_ib;
	float _r;
public:
	Material(float dr,float dg,float db,float sr,float sg,float sb,float ir,float ig,float ib,float r);
    float getdr() const;
    float getir() const;
    float getsr() const;
    float getdg() const;
	float getig() const;
	float getsg() const;
	float getdb() const;
	float getib() const;
	float getsb() const;
    float getr() const;
};

#endif /* MATERIAL_H_ */
