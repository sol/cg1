
#ifndef SPHERE_H
#define SPHERE_H

#include "meshobject.h"

class Sphere : public MeshObject
{

/** Public methods: */
public:
    Sphere( GLdouble Radius, int iSlices, int Stacks, GLenum Style  );
    ~Sphere();

};

#endif // SPHERE_H
