
#ifndef CUBE_H
#define CUBE_H

#include "meshobject.h"

class Cube : public MeshObject
{

public:
    Cube( GLdouble Height, GLdouble Width, GLdouble Depth, GLenum Mode );
    ~Cube();


};

#endif // CUBE_H
