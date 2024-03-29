//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   cube.h - (c) 2003 by The Marrowmoon Group                              //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#ifndef CUBE_H
#define CUBE_H

#include "meshobject.h"


namespace MeshObjects
{


//this class provides MeshObject with a constructor appropriate for cubes
class Cube : public MeshObject
{
public:
	Cube( GLdouble Height = 1.0, GLdouble Width = 1.0, GLdouble Depth = 1.0, GLenum Mode = GL_TRIANGLES );
};


}

#endif
