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

namespace Transformations
{

OscillatingRotation::OscillatingRotation(double Startangle, double Stopangle, double Speed, GLfloat X, GLfloat Y, GLfloat Z, double Start,  int type):
	Rotation(0, X, Y, Z),
	m_lfStartAngle(Startangle),
	m_lfStopAngle(Stopangle),
	m_lfSpeed(Speed),
	m_lfProgress(Start),
	m_iType(type)
{}


void OscillatingRotation::OnAnimate(unsigned int TimeToAnimate)
{
	double delta = double(TimeToAnimate) / 10.0 * m_lfSpeed;
	m_lfProgress += delta;

    if( m_iType == OSCIL_LINEAR ){
        if( m_lfProgress > 1 || m_lfProgress < 0 ) m_lfSpeed *= -1;
        m_Angle = m_lfStartAngle + ( m_lfStopAngle - m_lfStartAngle ) * m_lfProgress;
    }
    if( m_iType == OSCIL_SINUS )
    {
		while( m_lfProgress > 1 )
			m_lfProgress -= 1;

		m_Angle = m_lfStartAngle + ( m_lfStopAngle - m_lfStartAngle ) * ( sin(m_lfProgress * 6.28) + 1 ) / 2;
    }
}

}

