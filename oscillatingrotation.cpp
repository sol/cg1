//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   oscillatingrotation.cpp - (c) 2003 by The Marrowmoon Group             //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#include "oscillatingrotation.h"
#include "math.h"

using namespace Transformations;

int OscillatingRotation::Animate(){
    if( m_iType == OSCIL_LINEAR ){
        m_lfProgress += m_lfSpeed;
        if( m_lfProgress > 1 || m_lfProgress < 0 ) m_lfSpeed *= -1;
        m_Angle = m_lfStartAngle + ( m_lfStopAngle - m_lfStartAngle ) * m_lfProgress;
    }
    if( m_iType == OSCIL_SINUS ){
        m_lfProgress += m_lfSpeed;
        if( m_lfProgress > 1 ) m_lfProgress = 0;
        m_Angle = m_lfStartAngle + ( m_lfStopAngle - m_lfStartAngle ) * ( sin(m_lfProgress * 6.28) + 1 ) / 2;
    }
    return 0;
}
