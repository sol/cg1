
#ifndef LOADABLEMESH_H
#define LOADABLEMESH_H

#include "meshobject.h"



namespace MeshObjects {

class LoadableMesh : public MeshObject
{
public:
    void LoadFromFile( const char * filename );
};
}
#endif // LOADABLEMESH_H
