
#ifndef CUBE_H
#define CUBE_H

#include "meshobject.h"

namespace MeshObjects {
class Cube : public MeshObject
{

public:
    Cube( GLdouble Height, GLdouble Width, GLdouble Depth, GLenum Mode = GL_TRIANGLES );
    ~Cube();


};
}
#endif // CUBE_H
