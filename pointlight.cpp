#include "pointlight.h"

PointLight::PointLight() {
    if(m_IsValid) {
        GLfloat Position[] = { 0.0, 0.0, 0.0, 1.0};
        glLightfv(m_Light, GL_POSITION, Position);

        //set to point light
        glLighti(m_Light, GL_SPOT_CUTOFF, 180);
        glLighti(m_Light, GL_SPOT_EXPONENT, 0);
        glLighti(m_Light, GL_LINEAR_ATTENUATION, 1);
    }
}

void PointLight::DefineObject(){
    if(m_IsValid) {
        GLfloat Position[] = { 0.0, 0.0, 0.0, 1.0};
        glLightfv(m_Light, GL_POSITION, Position);
    }

}
