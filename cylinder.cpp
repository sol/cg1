//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   cylinder.cpp - (c) 2003 by The Marrowmoon Group                        //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#include "cylinder.h"
#include <GL/glu.h>
#include "disk.h"

Cylinder::Cylinder(GLdouble BaseRadius, GLdouble TopRadius, GLdouble Height,
            GLint Slices, GLint Stacks, GLenum Style){
    GLuint list = glGenLists(1);
    glNewList(list, GL_COMPILE);

    GLUquadric* cylinder = gluNewQuadric();
    gluQuadricDrawStyle( cylinder, Style );

    gluCylinder( cylinder, BaseRadius, TopRadius, Height, Slices, Stacks );
    glEndList();
    m_pGLList = new GLList( list );

    gluDeleteQuadric( cylinder );
    
    //bottom plate
    Disk* bottom = new Disk( 0, BaseRadius, Slices, 10, Style);
    bottom->AddRotation(180, 1, 0, 0);
    AddSubObject( bottom );

    //top plate
    Disk* top = new Disk( 0, TopRadius, Slices, 10, Style);
    top->AddTranslation(0, 0, Height);
    AddSubObject( top );

}
Cylinder::~Cylinder(){
}
