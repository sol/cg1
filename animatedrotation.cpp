//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   animatedrotation.cpp - (c) 2003 by The Marrowmoon Group                //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#include "animatedrotation.h"


namespace Transformations {


AnimatedRotation::AnimatedRotation(GLfloat Angle, GLfloat X, GLfloat Y, GLfloat Z, GLdouble DeltaAngle) : Rotation(Angle, X, Y, Z), m_DeltaAngle( DeltaAngle ) {
    //do nut'n    
}


int AnimatedRotation::Animate(){
    m_Angle += m_DeltaAngle;
    if( m_Angle > 360 )
        m_Angle -= 360;

    return 1;
}


}
