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


void Material::Apply() {
    glMaterialfv( GL_FRONT, GL_AMBIENT, m_aAmbient );
    glMaterialfv( GL_FRONT, GL_DIFFUSE, m_aDiffuse );
    glMaterialfv( GL_FRONT, GL_SPECULAR, m_aSpecular );
    glMaterialfv( GL_FRONT, GL_EMISSION, m_aEmission );
    glMaterialf( GL_FRONT, GL_SHININESS, m_Shininess );
}


void Material::SetColor(GLfloat red, GLfloat green, GLfloat blue) {

    SetMaterialComponent(m_aAmbient, 0.6 * red, 0.6 * green, 0.6 * blue, 1);
    SetMaterialComponent(m_aDiffuse, red, green, blue, 1);
    SetMaterialComponent(m_aSpecular, 2 * red, 2 * green, 2 * blue, 1);
    SetMaterialComponent(m_aEmission, 0, 0, 0, 1);

    m_Shininess = 80;
}


void Material::SetMaterialComponent(GLfloat* Component, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    Component[0] = red; Component[1] = green; Component[2] = blue; Component[3] = alpha;
}

