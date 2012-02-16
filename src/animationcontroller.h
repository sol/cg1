//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   animationcontroller.h - (c) 2003, 2004 by The Marrowmoon Group         //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#ifndef ANIMATIONCONTROLLER_H
#define ANIMATIONCONTROLLER_H

#include "world.h"
#include "animatedobject.h"



//
class AnimationController
{
private:
	//all associated objects are kept in this vector
	std::vector<AnimatedObject*> m_AnimatedObjects;

	//an helper, to determine how much time has pased
	Uint32 m_u32InternalTime;

	bool m_IsPause;
    
public:
	//constructor
	AnimationController();

	//calls Animate() of all associated objects
	void Animate();

	//
	void Pause() {m_IsPause = true;}
	void Unpause();
	void TogglePause();

	//associates an object with the AnimationController
	void AddObject(AnimatedObject* pObjectToAdd) {m_AnimatedObjects.push_back(pObjectToAdd);}

	//unassociates all objects
	void DeleteAllObjects() {m_AnimatedObjects.clear();}
};



#endif
