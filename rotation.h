//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   rotation.h - (c) 2003 by The Marrowmoon Group                        //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#ifndef ROTATION_H
#define ROTATION_H

#include "world.h"
#include "transformation.h"



class Rotation : public Transformation {
protected:
    GLfloat m_Angle;

    //This values define a vector used as rotation axis
    GLfloat m_X;
    GLfloat m_Y;
    GLfloat m_Z;

public:
    Rotation(GLfloat Angle, GLfloat X, GLfloat Y, GLfloat Z) : m_Angle(Angle), m_X(X), m_Y(Y), m_Z(Z) {}
    void Apply() { glRotatef( m_Angle, m_X, m_Y, m_Z ); }
    void InverseApply(){ glRotatef( -m_Angle, m_X, m_Y, m_Z ); }
};



#endif
