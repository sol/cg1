//////////////////////////////////////////////////////////////////////////////
//
//  file:       mazemap.h
//  begin:      Tue May 11 2004
//  copyright:  (C) 2004 by The Marrowmoon Group
//
//////////////////////////////////////////////////////////////////////////////
//
//   This program is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation; either version 2 of the License, or
//   (at your option) any later version.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef MAZEMAP_H
#define MAZEMAP_H

#include "mazemapelement.h"
#include "worldobject.h"
#include "plane.h"


namespace MazeDemo
{


class MazeMap : public WorldObject
{
private:
	//the actual map element, getter and setter
	MazeMapElement *m_Map[9][9];

	void SetElement(MazeMapElement* Element, int x, int y) {m_Map[x][y] = Element;}
	MazeMapElement* GetElement(int x, int y) {return m_Map[x][y];}

	void ConstructGeometry();

public: 
	MazeMap();
	~MazeMap();

};










class MapElementGeometry : public MeshObjects::MeshObject
{
public:
	MapElementGeometry(MazeMapElement Element)
	{
		AddSubObject(new MeshObjects::Plane ( 1.0, 1.0, 10, 10));

		//north
		if (Element.IsNorthAccessible())
		{
			MeshObjects::Plane* Wall = new MeshObjects::Plane ( 1.0, 1.0, 10, 10);
			Wall->AddRotation(-90, 1, 0, 0);
			Wall->AddTranslation(0, 0, 1);
			AddSubObject(Wall);

		}

		//south
		if (Element.IsSouthAccessible())
		{
			MeshObjects::Plane* Wall = new MeshObjects::Plane ( 1.0, 1.0, 10, 10);
			Wall->AddRotation(90, 1, 0, 0);
			Wall->AddTranslation(0, 1, 0);
			AddSubObject(Wall);

		}
		
		//east
		if (Element.IsEastAccessible());
		{
			MeshObjects::Plane* Wall = new MeshObjects::Plane ( 1.0, 1.0, 10, 10);
			Wall->AddRotation(90, 0, 1, 0);
			Wall->AddTranslation(0, 0, 1);
			AddSubObject(Wall);

		}

		//west
		if (Element.IsWestAccessible())
		{
			MeshObjects::Plane* Wall = new MeshObjects::Plane ( 1.0, 1.0, 10, 10);
			Wall->AddRotation(-90, 0, 1, 0);
			Wall->AddTranslation(1, 0, 0);
			AddSubObject(Wall);

		}
	}
};












}


#endif
