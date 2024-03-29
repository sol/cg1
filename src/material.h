//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   material.h - (c) 2003 by The Marrowmoon Group                          //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#ifndef MATERIAL_H
#define MATERIAL_H

#include "world.h"


class Material {
private:
    GLfloat m_aAmbient[4];
    GLfloat m_aDiffuse[4];
    GLfloat m_aSpecular[4];
    GLfloat m_aEmission[4];
    GLfloat m_Shininess;

protected:
    void SetMaterialComponent(GLfloat* Component, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
    
public:
    Material(GLfloat red = 0.2, GLfloat green = 0.2, GLfloat blue = 0.2) {SetColor(red, green, blue);}
    virtual ~Material() {}
    void SetShininess( GLfloat Shininess ){ m_Shininess = Shininess; }
    virtual void SetColor(GLfloat red, GLfloat green, GLfloat blue);
    void Apply();
};

#endif
