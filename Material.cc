/*
 * Material.cpp
 *
 *  Created on: Oct 2, 2016
 *      Author: Lee
 */

#include "Material.h"

Material::Material(float dr,float dg,float db,float sr,float sg,float sb,float ir,float ig,float ib,float r) {
	_dr = dr;
	_dg = dg;
	_db = db;

	_sr = sr;
	_sg = sg;
	_sb = sb;

	_ir = ir;
	_ig = ig;
	_ib = ib;

	_r = r;
}

float Material::getdr() const
{
    return _dr;
}

float Material::getir() const
{
    return _ir;
}

float Material::getsr() const
{
    return _sr;
}

float Material::getdg() const
{
    return _dg;
}

float Material::getig() const
{
    return _ig;
}

float Material::getsg() const
{
    return _sg;
}

float Material::getdb() const
{
    return _db;
}

float Material::getib() const
{
    return _ib;
}

float Material::getsb() const
{
    return _sb;
}

float Material::getr() const
{
    return _r;
}



