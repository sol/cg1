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

#include "world.h"
#include "transformations.h"


//This is an appropriate base class for all objects needed to be transformed
class WorldObject {
private:
    //in this function, derived objects should send their specific data to the pipeline
    virtual void DefineObject() = 0;
    
    std::vector<WorldObject*> m_SubObjects;

protected:
    std::vector<Transformation*> m_Transformations;

public:
    virtual ~WorldObject();

    //in this function the data of (*this) and all sub-objects are sent to the pipleine
    void Execute();

    //all added transformations and sub-objects are deleted in WorldObject::~WorldObject
    void AddSubObject(WorldObject* pObject)                             { m_SubObjects.push_back(pObject); }
    void AddTransformation(Transformation* pTransformation)             { m_Transformations.push_back(pTransformation); }
    void AddRotation( GLfloat Angle, GLfloat X, GLfloat Y, GLfloat Z )  { AddTransformation( new Rotation( Angle, X, Y, Z )); }
    void AddTranslation( GLfloat X, GLfloat Y, GLfloat Z )              { AddTransformation( new Translation( X, Y, Z )); }
    void AddScaling( GLfloat X, GLfloat Y, GLfloat Z )                  { AddTransformation( new Scaling( X, Y, Z )); }
};

#endif
