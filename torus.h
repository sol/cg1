//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   torus.h - (c) 2003 by The Marrowmoon Group                             //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#ifndef TORUS_H
#define TORUS_H

#include "meshobject.h"


namespace MeshObjects {


//this class provides MeshObject with a constructor appropriate a torus
class Torus : public MeshObject
{
private:
    GLdouble m_InnerRadius;
    GLdouble m_OuterRadius;
    GLint m_SidesPerSection;
    GLint m_Sections;
    void DefineObject();

public:
    Torus(GLdouble InnerRadius, GLdouble OuterRadius, GLint SidesPerSection, GLint Sections);
};


}

#endif
