//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   worldobject.h - (c) 2003 by The Marrowmoon Group                        //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////


#ifndef WORLDOBJECT_H
#define WORLDOBJECT_H

#include "transformation.h"
#include <vector>
#include "rotation.h"
#include "translation.h"
#include "scaling.h"

class WorldObject
{
private:
    virtual void DefineObject() = 0;
    std::vector<WorldObject*> m_SubObjects;
    
protected:
    std::vector<Transformation*> m_Transformations;


public:
    void AddTransform(Transformation* pTransformation)   {m_Transformations.push_back(pTransformation);}
    void Execute();
    
    void AddRotation( GLfloat Angle, GLfloat X, GLfloat Y, GLfloat Z ){ AddTransform( new Rotation( Angle, X, Y, Z )); }
    void AddTranslation( GLfloat X, GLfloat Y, GLfloat Z ){ AddTransform( new Translation( X, Y, Z )); }
    void AddScaling( GLfloat X, GLfloat Y, GLfloat Z ){ AddTransform( new Scaling( X, Y, Z )); }
    virtual ~WorldObject();
    void AddSubObject(WorldObject* pObject)           {m_SubObjects.push_back(pObject);}
};

#endif // WORLDOBJECT_H
