//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   meshobject.cpp - (c) 2003 by The Marrowmoon Group                      //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#include "meshobject.h"



MeshObject::MeshObject() {
    m_pGLList = NULL;
    m_pMaterial = NULL;
}






void MeshObject::DefineObject() {
    //apply material
    if( m_pMaterial )
        m_pMaterial->Apply();
    //PROV

    //send the mesh to the pipeline
    if (m_pGLList)
        m_pGLList->ExecuteList();
    
}
