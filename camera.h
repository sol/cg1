//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   camera.h - (c) 2003 by The Marrowmoon Group                            //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#ifndef CAMERA_H
#define CAMERA_H

#include "world.h"

#include "worldobject.h"
#include "transformations.h"

class OpenGLContext;
class Scene;


//!!! camera does not work as subobject !!!
class Camera : public WorldObject{
private:
    OpenGLContext* m_pOpenGLContext;
    Scene* m_pAssociatedScene;

    void DefineObject(){}
    
public:
    Camera();

    void SetAssociatedScene(Scene* pAssociatedScene) {m_pAssociatedScene = pAssociatedScene;}
    void Render();
};



#endif
