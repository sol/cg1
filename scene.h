//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   scene.h - (c) 2003 by The Marrowmoon Group                             //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#ifndef SCENE_H
#define SCENE_H

#include "world.h"
#include "animationcontroller.h"


class WorldObject;
class Camera;


class Scene {
private:
    std::vector<WorldObject*> m_WorldObjects;
    Camera* m_pActiveCamera;
    AnimationController *m_pAnimationController;

public:
    Scene();
    ~Scene();
    
    void AddWorldObject(WorldObject* pWorldObject) { m_WorldObjects.push_back(pWorldObject); }
    void SetCamera( Camera* pCamera );//sets current camera and adds it to the world object vector
    
    void Render();
    void ExecuteAllObjects();
    
    AnimationController* GetAnimationController()  { return m_pAnimationController; }

};

#endif
