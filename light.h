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


//glEnable(GL_RENDER);
//glEnable(GL_LIGHTING);

//glShadeModle(GL_FLAT | GL_SMOOTH);

//glLightModlefv(GL_LIGHT_MODEL_AMBIENT, rgba);         //global ilumination
//glLightModlei(GL_LIGHT_MODEL_LOCAL_VIEWER, 0 | 1);    //specular reflection
//glLightModlei(GL_LIGHT_MODEL_TWO_SIDE, 0 | 1);        // off | on

//FOG

//glEnable(GL_FOG);

//glFogfv(GL_FOG_COLOR, rgba)

//glFogi(GL_FOG_MODE, GL_EXP | GL_LINEAR | GL_EXP2)
//glFog?(GL_FOG_DENSITY, 1 | any)

//glFogf(GL_FOG_START, 0.0 .. any);
//glFogf(GL_FOG_END, 0.0 .. any); (1)

//glHint(GL_FOG_HINT, GL_Fastest|FL_NICEST|GL_DONT_CARE);

//class Color {
//private:
//    GLfloat m_Color[4];
//
//public:
//    Color(GLfloat Red, GLfloat Green, GLfloat Blue, GLfloat Alpha) {
//        m_Color[0] = Red;
//        m_Color[1] = Green;
//        m_Color[2] = Blue;
//        m_Color[3] = Alpha;
//    }
//
//    GLfloat* GetColorVector() {return m_Color;}
//};







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
