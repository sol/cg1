
#ifndef SPHERE_H
#define SPHERE_H

#include "world.h"
#include "meshobject.h"

class Sphere : public MeshObject
{

/** Public methods: */
public:
    Sphere( GLdouble Radius, int iSlices, int Stacks, GLenum Style = GLU_FILL );
    ~Sphere();

};

#endif // SPHERE_H
