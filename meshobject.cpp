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


namespace MeshObjects {


MeshObject::MeshObject() {
    m_pGLList = NULL;
    m_pMaterial = NULL;
}


MeshObject::~MeshObject(){
    if( m_pGLList )
        glDeleteLists( m_pGLList->GetList(), 1);
        delete m_pGLList;

    if( m_pMaterial )
        delete m_pMaterial;
}


void MeshObject::DefineObject() {
    //apply material
    if( m_pMaterial )
        m_pMaterial->Apply();

    //send the mesh to the pipeline
    if (m_pGLList)
        m_pGLList->ExecuteList();
}


void MeshObject::SetMaterial(GLfloat red, GLfloat green, GLfloat blue) {
    if (m_pMaterial)
        delete m_pMaterial;

    m_pMaterial = new Material(red, green, blue);
}


}
