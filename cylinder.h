//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   cylinder.h - (c) 2003 by The Marrowmoon Group                          //
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

#include "meshobject.h"


namespace MeshObjects {


//this class provides MeshObject with a constructor appropriate for cylinders
class Cylinder : public MeshObject  {
public: 
    Cylinder(GLdouble BaseRadius, GLdouble TopRadius, GLdouble Height, GLint Slices=20, GLint Stacks=20, GLenum Style = GLU_FILL);
};


}

#endif
