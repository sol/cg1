//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   loadablemesh.h - (c) 2003 by The Marrowmoon Group                      //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#ifndef LOADABLEMESH_H
#define LOADABLEMESH_H

#include "meshobject.h"


namespace MeshObjects {


//This class provides MeshObject with a constructor appropriate for loading a
//glList from a file.
//!!!this feature is not yet implemented!!!
class LoadableMesh : public MeshObject {
public:
    LoadableMesh( const char * filename );
};


}

#endif
