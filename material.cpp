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
    m_aAmbient[0]  = .2*red; m_aAmbient[1]  = .2*green; m_aAmbient[2]  = .2*blue; m_aAmbient[3]  = 1;
    m_aDiffuse[0]  = red; m_aDiffuse[1]  = green; m_aDiffuse[2]  = blue; m_aDiffuse[3]  = 1;
    m_aSpecular[0] = 2*red; m_aSpecular[1] = 2*green; m_aSpecular[2] = 2*blue; m_aSpecular[3] = 1;
    m_aEmission[0] = 0;   m_aEmission[1] = 0;     m_aEmission[2] = 0;    m_aEmission[3] = 1;
    m_Shininess = 80;
}
