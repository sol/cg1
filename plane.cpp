//////////////////////////////////////////////////////////////////////////////
//
//  file:       plane.cpp
//  begin:      Tue May 11 2004
//  copyright:  (C) 2004 by The Marrowmoon Group
//
//////////////////////////////////////////////////////////////////////////////
//
//   This program is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation; either version 2 of the License, or
//   (at your option) any later version.
//
//////////////////////////////////////////////////////////////////////////////


#include "plane.h"


namespace MeshObjects
{


Plane::Plane( GLdouble Height, GLdouble Width, GLint StepsHeight, GLint StepsWidth, GLenum Mode)
{
	GLdouble HeightPerStep = Height / StepsHeight;
	GLdouble WidthPerStep = Width / StepsWidth;
	
	GLuint list = glGenLists(1);
	glNewList(list, GL_COMPILE);

	glBegin( Mode );


	for (int i = 0; i < StepsWidth; i++)
	{
		for (int j = 0; j < StepsHeight; j++)
		{
			GLdouble v0[] = { GLdouble(j) * HeightPerStep,     GLdouble(i) * WidthPerStep,     0};
			GLdouble v1[] = { GLdouble(j + 1) * HeightPerStep, GLdouble(i) * WidthPerStep,     0};
			GLdouble v2[] = { GLdouble(j + 1) * HeightPerStep, GLdouble(i + 1) * WidthPerStep, 0};
			GLdouble v3[] = { GLdouble(j) * HeightPerStep,     GLdouble(i + 1) * WidthPerStep, 0};

			glNormal3d(0, 0, 1);
			glVertex3dv( v0 );
			glNormal3d(0, 0, 1);
			glVertex3dv( v1 );
			glNormal3d(0, 0, 1);
			glVertex3dv( v2 );

			glNormal3d(0, 0, 1);
			glVertex3dv( v0 );
			glNormal3d(0, 0, 1);
			glVertex3dv( v2 );
			glNormal3d(0, 0, 1);
			glVertex3dv( v3 );
		}
	}

	glEnd();
	glEndList();
	m_pGLList = new GLList( list );
}


} // end namespace MeshObjects
