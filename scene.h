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

#include <vector>

class WorldObject;
class Light;
class Camera;



class Scene {
private:
    std::vector<WorldObject*> m_WorldObjects;
    std::vector<Camera*> m_Cameras;

public:
    ~Scene();
    void AddWorldObject(WorldObject* pWorldObject) {m_WorldObjects.push_back(pWorldObject);}
    void AddCamera(Camera* pCamera);

    void ExecuteAllObjects();

};



#endif
