
#include "spotlight.h"

SpotLight::SpotLight(GLfloat Angle) {
    if(m_IsValid) {
        GLfloat Position[] = { 0.0, 0.0, 0.0, 1.0};
        glLightfv(m_Light, GL_POSITION, Position);

        //set as spot light
        glLightf(m_Light, GL_SPOT_CUTOFF, Angle);
        glLightf(m_Light, GL_SPOT_EXPONENT, 0);
        
        
        GLfloat Direction[] = { 0.0, 0.0, -1.0 };
        glLightfv(m_Light, GL_SPOT_DIRECTION, Direction);
    }
}


void SpotLight::DefineObject(){
    if(m_IsValid) {
        GLfloat Position[] = { 0.0, 0.0, 0.0, 1.0 };
        glLightfv(m_Light, GL_POSITION, Position);
        GLfloat Direction[] = { 0.0, 0.0, -1.0 };
        glLightfv(m_Light, GL_SPOT_DIRECTION, Direction);
    }
}



