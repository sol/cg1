//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   sphere.h - (c) 2003 by The Marrowmoon Group                            //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#ifndef SPHERE_H
#define SPHERE_H

#include "meshobject.h"


namespace MeshObjects {


//this class provides MeshObject with a constructor appropriate for spheres
class Sphere : public MeshObject {
public:
    Sphere( GLdouble Radius, int iSlices = 20, int Stacks=20, GLenum Style = GLU_FILL );
};


}

#endif
