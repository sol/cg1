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

#include "world.h"
#include "animatedobject.h"


//an advanced container for AnimatedObjects
class AnimationController {
private:
    std::vector<AnimatedObject*> m_AnimatedObjects;
    Uint32 m_u32InternalTime;
    bool m_iPause;
    
public:
    AnimationController();
    
    int Animate();  //calls Animate() of all associated objects as often as necessary
    int OneStep();  //calls Animate() of all associated objects one time
    bool Pause();
    bool Unpause();
    bool TogglePause();

    void AddObject(AnimatedObject* ObjectToAdd); //associates an object witg the AnimationController
    void DeleteAllObjects(); //unassociates all objects
};

#endif
