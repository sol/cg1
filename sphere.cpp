//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   sphere.cpp - (c) 2003 by The Marrowmoon Group                          //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#include "sphere.h"


namespace MeshObjects {

    
Sphere::Sphere( GLdouble Radius, int iSlices, int iStacks, GLenum Style ) {
    GLuint list = glGenLists(1);
    glNewList(list, GL_COMPILE);

    GLUquadric* sphere = gluNewQuadric();
    gluQuadricDrawStyle( sphere, Style );
    
    gluSphere( sphere, Radius, iSlices, iStacks );
    glEndList();
    m_pGLList = new GLList( list );

    gluDeleteQuadric( sphere );

}


}
