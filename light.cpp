//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   light.cpp - (c) 2003 by The Marrowmoon Group                           //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#include "light.h"



bool* Light::m_pIsAssigned = NULL;
int Light::m_MaxNrOfLights = 0;



Light::Light() {

    if (!m_pIsAssigned) {
        glGetIntegerv(GL_MAX_LIGHTS, &m_MaxNrOfLights);
        m_pIsAssigned = new bool[m_MaxNrOfLights];
        for (int i = 0; i < m_MaxNrOfLights; i++)
            m_pIsAssigned[i] = false;
    }

    int i = 0;
    while ((i < m_MaxNrOfLights)  && (m_pIsAssigned[i]))
        i++;

    if (i < m_MaxNrOfLights) {
        m_pIsAssigned[i] = true;
        m_Light = GL_LIGHT0 + i;
        m_IsValid = true;

        //set all glLight prameters to gl-defaults
        m_aAmbient[0]  = 0.0; m_aAmbient[1]  = 0.0; m_aAmbient[2]  = 0.0; m_aAmbient[3]  = 1.0;
        m_aDiffuse[0]  = 0.0; m_aDiffuse[1]  = 0.0; m_aDiffuse[2]  = 0.0; m_aDiffuse[3]  = 1.0;
        m_aSpecular[0] = 0.0; m_aSpecular[1] = 0.0; m_aSpecular[2] = 0.0; m_aSpecular[3] = 1.0;
        m_aPosition[0] = 0.0; m_aPosition[1] = 0.0; m_aPosition[2] = 1.0; m_aPosition[3] = 0.0;
        m_aSpotDirection[0] = 0.0; m_aSpotDirection[1] = 0.0; m_aSpotDirection[2] = -1.0;
        m_SpotExponent = 0.0;
        m_SpotCutoff = 180.0;
        m_ConstantAttenuation = 1.0;
        m_LinearAttenuation = 0.0;
        m_QuadraticAttenuation = 0.0;

        DefineObject();
        Enable();
    }
    else
        m_IsValid = false;
}



Light::~Light() {
    if (m_IsValid) {
        Disable();
        m_pIsAssigned[m_Light - GL_LIGHT0] = false;
    }
}



void Light::DefineObject() {
    if(m_IsValid) {

        glLightfv(m_Light, GL_AMBIENT, m_aAmbient);
        glLightfv(m_Light, GL_DIFFUSE, m_aDiffuse);
        glLightfv(m_Light, GL_SPECULAR, m_aSpecular);

        glLightfv(m_Light, GL_POSITION, m_aPosition);
        glLightfv(m_Light, GL_SPOT_DIRECTION, m_aSpotDirection);

        glLightf (m_Light, GL_SPOT_EXPONENT, m_SpotExponent);
        glLightf (m_Light, GL_SPOT_CUTOFF, m_SpotCutoff);
        
        glLightf (m_Light, GL_CONSTANT_ATTENUATION, m_ConstantAttenuation);
        glLightf (m_Light, GL_LINEAR_ATTENUATION, m_LinearAttenuation);
        glLightf (m_Light, GL_QUADRATIC_ATTENUATION, m_QuadraticAttenuation);
    }
}



void Light::SetColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    m_aAmbient[0]  = red; m_aAmbient[1]  = green; m_aAmbient[2]  = blue; m_aAmbient[3]  = alpha;
    m_aDiffuse[0]  = red; m_aDiffuse[1]  = green; m_aDiffuse[2]  = blue; m_aDiffuse[3]  = alpha;
    m_aSpecular[0] = red; m_aSpecular[1] = green; m_aSpecular[2] = blue; m_aSpecular[3] = alpha;
}
