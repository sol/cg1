
#include "sphere.h"
#include "GL/glu.h"

Sphere::Sphere( GLdouble Radius, int iSlices, int iStacks, GLenum Style ){
    GLuint list = glGenLists(1);
    glNewList(list, GL_COMPILE);

    GLUquadric* sphere = gluNewQuadric();
    gluQuadricDrawStyle( sphere, Style );
    
    gluSphere( sphere, Radius, iSlices, iStacks );
    glEndList();
    m_pGLList = new GLList( list );

    gluDeleteQuadric( sphere );

}


Sphere::~Sphere(){
    glDeleteLists( m_pGLList->GetList(), 1 );
    delete m_pGLList;
}


