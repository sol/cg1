//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   animatedrotation.h - (c) 2003 by The Marrowmoon Group                  //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#ifndef ANIMATEDROTATION_H
#define ANIMATEDROTATION_H

#include "world.h"
#include "rotation.h"
#include "animatedobject.h"


namespace Transformations {
    

class AnimatedRotation : public Rotation, public AnimatedObject
{
private:
	GLdouble m_AngularVelocity;

public:

	//AngularVelocity has to be given in deg/s
	AnimatedRotation(GLfloat Angle, GLfloat X, GLfloat Y, GLfloat Z, GLdouble AngularVelocity);

	//implementation of the interface AnimatedObject
	void OnAnimate(unsigned int TimeToAnimate);

};


}



#endif
