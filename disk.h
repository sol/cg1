//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   disk.h - (c) 2003 by The Marrowmoon Group                        //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#ifndef DISK_H
#define DISK_H

#include <meshobject.h>

class Disk : public MeshObject  {
public: 
	Disk(GLdouble InnerRadius, GLdouble OuterRadius, GLint Slices, GLint Loops, GLenum Style);
	~Disk();
};

#endif
