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

//#define osx

#include <SDL/SDL.h>

#if defined osx
#include <GLUT/glut.h>
#endif


#if defined linux
#include <GL/glut.h>
#endif

#include <vector>


class Scene;


//At the moment the class World has not much functionality(it only initialises sdl).
//In furure it could be used to manage scenes.
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
