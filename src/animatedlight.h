//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   animatedlight.h - (c) 2003 by The Marrowmoon Group                     //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#ifndef ANIMATEDLIGHT_H
#define ANIMATEDLIGHT_H

#include "pointlight.h"
#include "animatedobject.h"

/**
 * \addtogroup Playground
 * \{
 */

/**
 * \brief playing around with light color etc.
 */
class AnimatedLight : public AnimatedObject, public Lights::PointLight
{
public:
	AnimatedLight(GLfloat speed=0.5);
	virtual void OnAnimate(unsigned int TimeToAnimate);

private:
	GLfloat m_speed;
};

/**
 * \}
 */

#endif // ANIMATEDLIGHT_H
