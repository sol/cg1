//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   animationcontroller.h - (c) 2003 by The Marrowmoon Group               //
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

#include "animatedobject.h"
#include "SDL.h"
#include <vector>



class AnimationController//: public Controller
{
private:
    std::vector<AnimatedObject*> m_AnimatedObjects;
    Uint32 m_u32InternalTime;
    int m_iPause;
    
public:
    AnimationController();
//    int Control() {return Animate();}
    int Animate();
    int Pause();
    int Unpause();
    int TogglePause();
    int OneStep();
    void AddObject(AnimatedObject* ObjectToAdd);
    void DeleteAllObjects();

    Uint32 GetInternalTime() {return m_u32InternalTime;}
};



#endif
