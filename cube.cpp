
#include "cube.h"

Cube::Cube( GLdouble Height, GLdouble Width, GLdouble Depth, GLenum Style )
{
    GLuint list = glGenLists(1);
    glNewList(list, GL_COMPILE);
    
    GLdouble v0[] = { 0,      0,      Depth };
    GLdouble v1[] = { Height, 0,      Depth };
    GLdouble v2[] = { Height, Width,  Depth };
    GLdouble v3[] = { 0,      Width,  Depth };
    GLdouble v4[] = { 0,      0,     0 };
    GLdouble v5[] = { Height, 0,     0 };
    GLdouble v6[] = { Height, Width, 0 };
    GLdouble v7[] = { 0,      Width, 0 };
    glBegin( Style );

    glNormal3d(0, 0, 1);
    glVertex3dv( v0 );
    glVertex3dv( v1 );
    glVertex3dv( v2 );

    glVertex3dv( v0 );
    glVertex3dv( v2 );
    glVertex3dv( v3 );

    glNormal3d(1, 0, 0);
    glVertex3dv( v1 );
    glVertex3dv( v5 );
    glVertex3dv( v6 );

    glVertex3dv( v1 );
    glVertex3dv( v6 );
    glVertex3dv( v2 );

    glNormal3d(0, 0, -1);
    glVertex3dv( v5 );
    glVertex3dv( v4 );
    glVertex3dv( v7 );

    glVertex3dv( v5 );
    glVertex3dv( v7 );
    glVertex3dv( v6 );

    glNormal3d(0, -1, 0);
    glVertex3dv( v4 );
    glVertex3dv( v0 );
    glVertex3dv( v3 );

    glVertex3dv( v4 );
    glVertex3dv( v3 );
    glVertex3dv( v7 );

    glNormal3d(0, 1, 0);
    glVertex3dv( v3 );
    glVertex3dv( v2 );
    glVertex3dv( v6 );

    glVertex3dv( v3 );
    glVertex3dv( v6 );
    glVertex3dv( v7 );

    glNormal3d(0, -1, 0);
    glVertex3dv( v1 );
    glVertex3dv( v0 );
    glVertex3dv( v4 );

    glVertex3dv( v1 );
    glVertex3dv( v4 );
    glVertex3dv( v5 );

    glEnd();
    glEndList();
    m_pGLList = new GLList( list );

    
}


Cube::~Cube(){
    glDeleteLists( m_pGLList->GetList(), 1 );
    delete m_pGLList;
}


