//////////////////////////////////////////////////////////////////////////////
//
//  file:       plane.h
//  begin:      Tue May 11 2004
//  copyright:  (C) 2004 by The Marrowmoon Group
//
//////////////////////////////////////////////////////////////////////////////
//
//   This program is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation; either version 2 of the License, or
//   (at your option) any later version.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef PLANE_H
#define PLANE_H

#include "meshobject.h"


namespace MeshObjects
{



//this class provides MeshObject with a constructor appropriate for planes
class Plane : public MeshObject
{
public: 
	Plane( GLdouble Height, GLdouble Width, GLint StepsHeight, GLint StepsWidth, GLenum Mode = GL_TRIANGLES );

};



}



#endif
