//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   loadablemesh.h - (c) 2004 by The Marrowmoon Group                      //
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


namespace MeshObjects
{


//This class provides MeshObject with a constructor appropriate for loading a
//glList from a file.
//
//The File has to be in the following format:
//int NormalCount
//NormalCount * ((float x) (float y) (float z))
//int VertexCount
//VertexCount * ((float x) (float y) (float z))
//int FaceCount
//FaceCount * ((int VertexIndex1) (int VertexIndex2) (int VertexIndex3) (int Normalndex1) (int Normalndex2) (int Normalndex3))
class LoadableMesh : public MeshObject
{
public:
	LoadableMesh( const char *Filename, GLenum Mode = GL_TRIANGLES);

};


}


#endif
