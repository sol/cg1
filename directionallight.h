#ifndef DIRECTIONALLIGHT_H
#define DIRECTIONALLIGHT_H

#include "light.h"
#include "GL/gl.h"



class DirectionalLight : public Light
{
public:
    DirectionalLight();

public:
    void DefineObject();
};

#endif
