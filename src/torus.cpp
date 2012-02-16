//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   torus.cpp - (c) 2003 by The Marrowmoon Group                           //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#include "torus.h"



namespace MeshObjects
{

Torus::Torus(GLdouble InnerRadius, GLdouble OuterRadius, GLint SidesPerSection, GLint Sections)
{
    m_InnerRadius = InnerRadius;
    m_OuterRadius = OuterRadius;
    m_SidesPerSection = SidesPerSection;
    m_Sections =Sections;
}


void Torus::DefineObject()
{
    MeshObject::DefineObject();
    //send the mesh to the pipeline
    glutSolidTorus(m_InnerRadius, m_OuterRadius, m_SidesPerSection, m_Sections);
}


}
