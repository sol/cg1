//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   world.h - (c) 2003 by The Marrowmoon Group                             //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#ifndef WORLD_H
#define WORLD_H

#include <SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <vector>

#include "scene.h"



class World {
private:
//    std::vector<Scene*> m_Scenes;

    Scene* m_pScene;
    
public:
    World();
    ~World();

//    void AddScene(Scene* pScene) { m_Scenes.push_back(pScene); }
    void SetScene(Scene* pScene) { m_pScene = pScene; }
};



#endif
