#include "directionallight.h"

DirectionalLight::DirectionalLight() {

    if(m_IsValid) {
        GLfloat Position[] = { 0.0, 0.0, 1.0, 0.0};
        glLightfv(m_Light, GL_POSITION, Position);
    }
}



void DirectionalLight::DefineObject(){
    if(m_IsValid) {
        GLfloat Position[] = { 0.0, 0.0, 1.0, 0.0};
        glLightfv(m_Light, GL_POSITION, Position);

    }
}


