//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   scene.cpp - (c) 2003 by The Marrowmoon Group                           //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#include "scene.h"
#include "camera.h"
#include "meshobject.h"


void Scene::AddCamera(Camera* pCamera) {
    m_Cameras.push_back(pCamera);
    pCamera->SetAssociatedScene(this);
}



void Scene::ExecuteAllObjects() {
    
    std::vector<WorldObject*>::iterator it;

    for (it = m_WorldObjects.begin(); it < m_WorldObjects.end(); it++)
        (*it)->Execute();
}
