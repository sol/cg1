//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   worldobject.cpp - (c) 2003 by The Marrowmoon Group                        //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////


#include "worldobject.h"

WorldObject::~WorldObject(){
    //delete Transforms
    std::vector<Transformation*>::iterator TransformationIterator;

    for (TransformationIterator = m_Transformations.begin(); TransformationIterator < m_Transformations.end(); TransformationIterator++)
        delete (*TransformationIterator);

    //delete Subobjects
    std::vector<WorldObject*>::iterator it;
    for( it = m_SubObjects.begin(); it < m_SubObjects.end(); it++ )
        delete (*it);

}



void WorldObject::Execute() {
    //apply transformations
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    std::vector<Transformation*>::reverse_iterator TransformationIterator;

    for (TransformationIterator = m_Transformations.rbegin(); TransformationIterator < m_Transformations.rend(); TransformationIterator++)
        (*TransformationIterator)->Apply();

    DefineObject();
    
    //execute all subobjects
    std::vector<WorldObject*>::iterator ObjectIterator;

    for (ObjectIterator = m_SubObjects.begin(); ObjectIterator < m_SubObjects.end(); ObjectIterator++)
        (*ObjectIterator)->Execute();

    //undo transformations
    glPopMatrix();
}





