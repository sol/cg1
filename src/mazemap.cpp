//////////////////////////////////////////////////////////////////////////////
//
//  file:       mazemap.cpp
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

#include "mazemap.h"
#include <string>


namespace MazeDemo
{




MazeMap::MazeMap()
{
	std::string MazeData[] =
	{
		"+-+-+-+-+-+-+-+-+-+",
		"|   |              ",
		"+-+ +-+ + +-+-+-+ +",
		"|             |   |",
		"+ +-+-+-+-+-+ +-+-+",
		"|   |       |     |",
		"+-+ + + + + +-+-+-+",
		"|     |       |   |",
		"+-+-+ +-+-+-+-+-+ +",
		"|     |  ^        |",
		"+-+ + + +-+-+-+ +-+",
		"|   | |     |     |",
		"+ +-+-+ + + + +-+-+",
		"|           |     |",
		"+-+-+ + + + +-+-+-+",
		"|       |         |",
		"+-+-+ + +-+-+ +-+-+",
		"|         |       |",
		"+-+-+-+-+-+-+-+-+-+"
	};


	for (int x = 0; x < 9; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			int MazeDataX = x * 2 + 1;
			int MazeDataY = y * 2 + 1;
			
			MazeMapElement* NewElement = new MazeMapElement;

			NewElement->SetNorthAccessibility( MazeData[MazeDataY - 1][MazeDataX] == '-' );
			NewElement->SetSouthAccessibility( MazeData[MazeDataY + 1][MazeDataX] == '-' );
			
			NewElement->SetEastAccessibility( MazeData[MazeDataY][MazeDataX + 1] == '|' );
			NewElement->SetWestAccessibility( MazeData[MazeDataY][MazeDataX - 1] == '|' );

			SetElement(NewElement, x, y);
		}
	}

	ConstructGeometry();
}


void MazeMap::ConstructGeometry()
{
	for (int x = 0; x < 9; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			MapElementGeometry* ElementGeometry = new MapElementGeometry(*(GetElement(x, y)));

			ElementGeometry->AddTranslation(GLdouble(x), GLdouble(y), 0);
			
			
			AddSubObject(ElementGeometry);
		}
	}
}


MazeMap::~MazeMap()
{
	for (int x = 0; x < 9; x++)
	{
		for (int y = 0; y < 9; y++)
		{
			delete m_Map[x][y];
		}
	}
}



} // end namespace MazeDemo
