//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   camera.h - (c) 2003, 2004 by The Marrowmoon Group                      //
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

#include "worldobject.h"


class Scene;


//to render any scene, we need a camera
//!!! camera does not work as subobject !!!
class Camera : public WorldObject
{
private:
	Scene* m_pAssociatedScene;

	void DefineObject(){}
    
public:
	Camera();

	void SetAssociatedScene(Scene* pAssociatedScene) {m_pAssociatedScene = pAssociatedScene;}

	//call this method to render and display an image of the scene
	void Render();
};



#endif
