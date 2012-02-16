//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   oscillatingrotation.h - (c) 2003 by The Marrowmoon Group               //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#ifndef OSCILLATINGROTATION_H
#define OSCILLATINGROTATION_H

#include "animatedobject.h"
#include "rotation.h"

#if defined linux
#include <GL/glu.h>
#endif

#if defined osx
#include <GLUT/glut.h>
#endif

#define OSCIL_SINUS 0
#define OSCIL_LINEAR 1

namespace Transformations
{

class OscillatingRotation : public AnimatedObject, public Rotation
{
public:
	OscillatingRotation(double Startangle, double Stopangle, double Speed, GLfloat X, GLfloat Y, GLfloat Z, double Start=0,  int type=OSCIL_LINEAR);

	//        
	void OnAnimate(unsigned int TimeToAnimate);
private:
	double m_lfStartAngle, m_lfStopAngle, m_lfSpeed, m_lfProgress;
	int m_iType;
};

}
#endif
