//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   grid.cpp - (c) 2003 by The Marrowmoon Group                            //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#include "grid.h"


namespace MeshObjects {

    
Grid::Grid( GLdouble Height, GLdouble Width, GLint StepsHeight, GLint StepsWidth ) {
    GLuint list = glGenLists(1);
    glNewList(list, GL_COMPILE);

    glBegin( GL_LINES );
    glNormal3d(0, 0, -1);
	GLint i;
    for( i = 0; i <= StepsHeight; i++ )
        for( GLint w = 0; w < StepsWidth; w++ ){
            glVertex3d( (w*Width/StepsWidth)-(Width/2.0), (Height / StepsHeight * i) - (Height / 2), 0);
            glVertex3d( ((w+1)*Width/StepsWidth)-(Width/2.0), (Height / StepsHeight * i) - (Height / 2), 0);
    }
    

    for( i = 0; i <= StepsWidth; i++ )
        for( GLint w = 0; w < StepsHeight; w++ ){
            glVertex3d( (Width / StepsWidth * i) - (Width / 2), (w*Height/StepsHeight)-(Height/2.0), 0);
            glVertex3d( (Width / StepsWidth * i) - (Width / 2), ((w+1)*Height/StepsHeight)-(Height/2.0), 0);
    }            
    
    glEnd();
    glEndList();
    m_pGLList = new GLList( list );

}


}
