//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   cylinder.h - (c) 2003 by The Marrowmoon Group                        //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#ifndef CYLINDER_H
#define CYLINDER_H

#include <meshobject.h>


class Cylinder : public MeshObject  {
public: 
	Cylinder(GLdouble BaseRadius, GLdouble TopRadius, GLdouble Height,
                                                    GLint Slices, GLint Stacks, GLenum Style);
	~Cylinder();
};

#endif
