#ifndef SPOTLIGHT_H
#define SPOTLIGHT_H

#include "light.h"



class SpotLight : public Light {
public:
    SpotLight(GLfloat Angle);

private:
    void DefineObject();

};

#endif // SPOTLIGHT_H
