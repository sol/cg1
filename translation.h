//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   translation.h - (c) 2003 by The Marrowmoon Group                       //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#ifndef TRANSLATION_H
#define TRANSLATION_H

#include "world.h"
#include "transformation.h"


class Translation : public Transformation {
protected:
    //This values define a vector used for translating
    GLfloat m_X;
    GLfloat m_Y;
    GLfloat m_Z;

public:
    Translation(GLfloat X, GLfloat Y, GLfloat Z) : m_X(X), m_Y(Y), m_Z(Z) {}
    ~Translation(){}
    void Apply() { glTranslatef( m_X, m_Y, m_Z ); }
    void InverseApply() { glTranslatef( -m_X, -m_Y, -m_Z ); }
};



#endif
