//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   material.cpp - (c) 2003 by The Marrowmoon Group                        //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#include "material.h"
#include <stdlib.h>



Material::Material(){
    m_Ambient = NULL;
    m_Diffuse = NULL;
    m_Emission = NULL;
    m_Specular = NULL;
    m_Shininess = NULL;
}


Material::~Material(){
    if( m_Ambient ) delete[] m_Ambient;
    if( m_Diffuse ) delete[] m_Diffuse;
    if( m_Emission ) delete[] m_Emission;
    if( m_Specular ) delete[] m_Specular;
    if( m_Shininess ) delete[] m_Shininess;
}

void Material::Apply(){
    //apply the Material settings
    if( m_Ambient ) glMaterialfv( GL_FRONT, GL_AMBIENT, m_Ambient );
    if( m_Diffuse ) glMaterialfv( GL_FRONT, GL_DIFFUSE, m_Diffuse );
    if( m_Emission ) glMaterialfv( GL_FRONT, GL_EMISSION, m_Emission );
    if( m_Specular ) glMaterialfv( GL_FRONT, GL_SPECULAR, m_Specular );
    if( m_Shininess ) glMaterialfv( GL_FRONT, GL_SHININESS, m_Shininess );    

}


void Material::SetAmbient(GLfloat R, GLfloat G, GLfloat B, GLfloat A ){
    if( !m_Ambient )
        m_Ambient = new GLfloat[4];

    m_Ambient[0] = R;
    m_Ambient[1] = G;
    m_Ambient[2] = B;
    m_Ambient[3] = A;
}

void Material::SetDiffuse(GLfloat R, GLfloat G, GLfloat B, GLfloat A ){
    if( !m_Diffuse )
        m_Diffuse = new GLfloat[4];

    m_Diffuse[0] = R;
    m_Diffuse[1] = G;
    m_Diffuse[2] = B;
    m_Diffuse[3] = A;
}
void Material::SetSpecular(GLfloat R, GLfloat G, GLfloat B, GLfloat A ){
    if( !m_Specular )
        m_Specular = new GLfloat[4];

    m_Specular[0] = R;
    m_Specular[1] = G;
    m_Specular[2] = B;
    m_Specular[3] = A;
}


void Material::SetEmission(GLfloat R, GLfloat G, GLfloat B, GLfloat A ){
    if( !m_Emission )
        m_Emission = new GLfloat[4];

    m_Emission[0] = R;
    m_Emission[1] = G;
    m_Emission[2] = B;
    m_Emission[3] = A;
}


void Material::SetShininess(GLfloat R, GLfloat G, GLfloat B, GLfloat A ){
    if( !m_Shininess )
        m_Shininess = new GLfloat[4];

    m_Shininess[0] = R;
    m_Shininess[1] = G;
    m_Shininess[2] = B;
    m_Shininess[3] = A;
    
}

