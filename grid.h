//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   grid.h - (c) 2003 by The Marrowmoon Group                              //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#ifndef GRID_H
#define GRID_H

#include "meshobject.h"


namespace MeshObjects {


//this class provides MeshObject with a constructor appropriate for grids
class Grid : public MeshObject {
public: 
    Grid(GLdouble Height, GLdouble Width, GLint StepsHeight, GLint StepsWidth);
};


}

#endif
