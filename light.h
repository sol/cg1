//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   light.h - (c) 2003 by The Marrowmoon Group                             //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#ifndef LIGHT_H
#define LIGHT_H



#include <GL/gl.h>

#include <worldobject.h>


class Light : public WorldObject
{
private:
    virtual void DefineObject();

    //this static members are used to map the gl-internal lights GL_LIGHT0 -
    //GL_MAX_LIGHTS to objets. If you create more objects of the type Light
    //then GL_MAX_LIGHTS you will get emty dummy-objects(m_IsValid == false)
    static bool* m_pIsAssigned;
    static int m_MaxNrOfLights;

protected:
    bool m_IsValid;
    GLenum m_Light;

    //members for the glLight parameters
    GLfloat m_aAmbient[4];
    GLfloat m_aDiffuse[4];
    GLfloat m_aSpecular[4];
    GLfloat m_aPosition[4];
    GLfloat m_aSpotDirection[3];
    GLfloat m_SpotExponent;
    GLfloat m_SpotCutoff;
    GLfloat m_ConstantAttenuation;
    GLfloat m_LinearAttenuation;
    GLfloat m_QuadraticAttenuation;
    

public:
    static int GetMaxNrOfLights() {return m_MaxNrOfLights;} //you have to create at least one light to get a valid value
    
    Light();
    ~Light();

    void Enable()  {if (m_IsValid) glEnable(m_Light);}
    void Disable() {if (m_IsValid) glDisable(m_Light);}

    void SetColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
};

#endif
