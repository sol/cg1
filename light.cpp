
#include "light.h"
#include <stdlib.h>


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

        Enable();

        //Set Light
        Color _Color(1, 1, 1, 0);
        SetAllColors(_Color);



    }
    else
        m_IsValid = false;
}



void Light::DefineObject() {
    if (m_IsValid) {
        Color _Color(1.0, 1.0, 1.0, 1.0);
        SetAllColors(_Color);
    }
}



Light::~Light() {
    if (m_IsValid) {
        Disable();
        m_pIsAssigned[m_Light - GL_LIGHT0] = false;
    }
}



void Light::Enable() {
    if (m_IsValid)
        glEnable(m_Light);
}



void Light::Disable() {
    if (m_IsValid)
        glDisable(m_Light);
}



void Light::SetAmbient(Color& _Color) {
    if(m_IsValid)
        glLightfv(m_Light, GL_AMBIENT, _Color.GetColorVector());
}



void Light::SetDiffuse(Color& _Color) {
    if(m_IsValid)
        glLightfv(m_Light, GL_DIFFUSE, _Color.GetColorVector());
}



void Light::SetSpecular(Color& _Color) {
    if(m_IsValid)
        glLightfv(m_Light, GL_SPECULAR, _Color.GetColorVector());
}



void Light::SetAllColors(Color& _Color) {
    SetAmbient(_Color);
    SetDiffuse(_Color);
    SetSpecular(_Color);
}


void Light::SetPosition(GLfloat* pPosition) {
    if(m_IsValid)
        glLightfv(m_Light, GL_POSITION, pPosition);
}



