//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   disk.cpp - (c) 2003 by The Marrowmoon Group                        //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#include "disk.h"
#include "GL/glu.h"

Disk::Disk(GLdouble InnerRadius, GLdouble OuterRadius, GLint Slices, GLint Loops, GLenum Style){
    GLuint list = glGenLists(1);
    glNewList(list, GL_COMPILE);

    GLUquadric* disk = gluNewQuadric();
    gluQuadricDrawStyle( disk, Style );

    gluDisk( disk, InnerRadius, OuterRadius, Slices, Loops );
    glEndList();
    m_pGLList = new GLList( list );

    gluDeleteQuadric( disk );
    
}



Disk::~Disk(){
    
}
