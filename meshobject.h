//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   meshobject.h - (c) 2003 by The Marrowmoon Group                        //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#ifndef MESHOBJECT_H
#define MESHOBJECT_H

#include "worldobject.h"
#include "material.h"
#include "gllist.h"


namespace MeshObjects {


class MeshObject : public WorldObject {
private:
    virtual void DefineObject();

protected:
    GLList* m_pGLList;
    Material* m_pMaterial;

    void SetGLList(GLList* pGLList)                      {m_pGLList = pGLList;}

public:
    MeshObject();
    virtual ~MeshObject();//deletes m_pGLList and m_pMaterial

    void SetMaterial(GLfloat red, GLfloat green, GLfloat blue);
};


}

#endif
