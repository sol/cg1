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


Scene::Scene(){
    m_pAnimationController = new AnimationController;
}


void Scene::SetCamera(Camera* pCamera) {
    m_WorldObjects.push_back(pCamera);
    pCamera->SetAssociatedScene(this);
    m_pActiveCamera = pCamera;  
}



void Scene::ExecuteAllObjects() {
    
    std::vector<WorldObject*>::iterator it;

    for (it = m_WorldObjects.begin(); it < m_WorldObjects.end(); it++)
        (*it)->Execute();
}


Scene::~Scene(){
    std::vector<WorldObject*>::iterator it;

    for (it = m_WorldObjects.begin(); it < m_WorldObjects.end(); it++)
        delete (*it);

    delete m_pAnimationController;
}

void Scene::Render(){
    m_pAnimationController->Animate();
    m_pActiveCamera->Render();
}
    
