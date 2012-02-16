//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   animatedobject.h - (c) 2003, 2004 by The Marrowmoon Group              //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#ifndef ANIMATEDOBJECT_H
#define ANIMATEDOBJECT_H



//to use the AnimationController with a given class, it has to implement this interface
class AnimatedObject
{
public:
	//TimeToAnimate in ms
	virtual void OnAnimate(unsigned int TimeToAnimate) = 0;
};



#endif
