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

#include "gllist.h"
#include "material.h"
#include "transformation.h"
#include <vector>
#include "worldobject.h"

class MeshObject : public WorldObject {
private:
    virtual void DefineObject();

protected:
    GLList* m_pGLList;
    Material* m_pMaterial;

public:
    MeshObject();
    ~MeshObject();

    void SetGLList(GLList* pGLList)                      {m_pGLList = pGLList;}
    void SetMaterial(Material* pMaterial)                {m_pMaterial = pMaterial;}

};



#endif
