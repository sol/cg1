//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   animationcontroller.cpp - (c) 2003, 2004 by The Marrowmoon Group       //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#include "animationcontroller.h"



//constructor
AnimationController::AnimationController()
{
	m_u32InternalTime = SDL_GetTicks();
	m_IsPause = false;
}



void AnimationController::Animate()
{
	if (!m_IsPause)
	{
		Uint32 OldInternalTime = m_u32InternalTime;
		m_u32InternalTime = SDL_GetTicks();

		std::vector<AnimatedObject*>::iterator it;

		//call Animate() for all associated objects
		for (it = m_AnimatedObjects.begin(); it < m_AnimatedObjects.end(); it++)
			(*it)->OnAnimate(m_u32InternalTime - OldInternalTime);
	}
}



void AnimationController::Unpause()
{
	m_IsPause = false;
	m_u32InternalTime = SDL_GetTicks();
}


void AnimationController::TogglePause()
{
	if(m_IsPause)
		Unpause();

	else
		Pause();
}
