//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   scaling.h - (c) 2003 by The Marrowmoon Group                           //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#ifndef SCALING_H
#define SCALING_H

#include "world.h"
#include "transformation.h"


namespace Transformations {


class Scaling : public Transformation {
private:
    //This values are used for scaling
    GLfloat m_X;
    GLfloat m_Y;
    GLfloat m_Z;

public:
    Scaling(GLfloat X, GLfloat Y, GLfloat Z) : m_X(X), m_Y(Y), m_Z(Z) {}
    void Apply() { glScalef(m_X, m_Y, m_Z); }
    void InverseApply(){ glScalef( 1/m_X, 1/m_Y, 1/m_Z ); }
};


}

#endif
