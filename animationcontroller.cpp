//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   animationcontroller.cpp - (c) 2003 by The Marrowmoon Group             //
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



AnimationController::AnimationController()
{
    m_u32InternalTime = SDL_GetTicks();
    m_iPause = 0;
}



//adds an object to the list and returns cout of objects in the list
void AnimationController::AddObject(AnimatedObject* pObjectToAdd)
{
    m_AnimatedObjects.push_back(pObjectToAdd);
}

int AnimationController::OneStep(){
    m_u32InternalTime += 10;//Animate has to be called 100 times per second  (10ms * 100 = 1s)

    std::vector<AnimatedObject*>::iterator it;

    for (it = m_AnimatedObjects.begin(); it < m_AnimatedObjects.end(); it++)
        (*it)->Animate();

        return 0;
}



int AnimationController::Animate()
{
    if( !m_iPause )
        while( m_u32InternalTime < SDL_GetTicks() )
            OneStep();
   
    return 0;
}

int AnimationController::Pause(){
    int retval = m_iPause;
    m_iPause = 1;
    return retval;
}


int AnimationController::Unpause(){
    int retval = m_iPause;
    m_iPause = 0;
    m_u32InternalTime = SDL_GetTicks();
    return retval;
}


int AnimationController::TogglePause(){
    if( m_iPause )
        return Unpause();
    else
        return Pause();
}

void AnimationController::DeleteAllObjects(){
    std::vector<AnimatedObject*>::iterator it;

    for (it = m_AnimatedObjects.begin(); it < m_AnimatedObjects.end(); it++)
        delete *it;

    m_AnimatedObjects.clear();
}

