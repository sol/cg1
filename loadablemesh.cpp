//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   loadablemesh.cpp - (c) 2004 by The Marrowmoon Group                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////


#include "loadablemesh.h"
#include <fstream>


namespace MeshObjects
{

LoadableMesh::LoadableMesh( const char *Filename, GLenum Mode)
{
	//open the file
	std::ifstream MyFile(Filename);
	if(!MyFile)
		printf("File %s not found!\n", Filename);//PROV


	else
	{
		//load the normals
		int NormalCount;
		MyFile >> NormalCount;
		GLdouble** Normals = new GLdouble*[NormalCount];
		for (int i = 0; i < NormalCount; i++)
		{
			GLdouble* Normal = new GLdouble[3];
			MyFile >> Normal[0];
			MyFile >> Normal[1];
			MyFile >> Normal[2];
			Normals[i] = Normal;
		}


		//load the vertices
		int VertexCount;
		MyFile >> VertexCount;
		GLdouble** Vertices = new GLdouble*[VertexCount];
		for (int i = 0; i < VertexCount; i++)
		{
			GLdouble* Vertex = new GLdouble[3];
			MyFile >> Vertex[0];
			MyFile >> Vertex[1];
			MyFile >> Vertex[2];
			Vertices[i] = Vertex;
		}


		//construct faces
		GLuint list = glGenLists(1);
		glNewList(list, GL_COMPILE);

		int FaceCount;
		MyFile >> FaceCount;

		for (int i = 0; i < FaceCount; i++)
		{
			glBegin(Mode);

			int FaceVertices[3];
			int FaceNormals[3];

			MyFile >> FaceVertices[0];
			MyFile >> FaceVertices[1];
			MyFile >> FaceVertices[2];

			MyFile >> FaceNormals[0];
			MyFile >> FaceNormals[1];
			MyFile >> FaceNormals[2];

			//define the actual geometry:)
			glNormal3dv(Normals[FaceNormals[0]]);
			glVertex3dv(Vertices[FaceVertices[0]]);
			glNormal3dv(Normals[FaceNormals[1]]);
			glVertex3dv(Vertices[FaceVertices[1]]);
			glNormal3dv(Normals[FaceNormals[2]]);
			glVertex3dv(Vertices[FaceVertices[2]]);

			glEnd();
		}
	
		glEndList();
		m_pGLList = new GLList( list);

		//destroy vectors
		for (int i = 0; i < VertexCount; i++)
			delete[] Vertices[i];
		delete[] Vertices;

		for (int i = 0; i < NormalCount; i++)
			delete[] Normals[i];
		delete[] Normals;


	}

}


}
