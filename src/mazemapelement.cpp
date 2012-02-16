//////////////////////////////////////////////////////////////////////////////
//
//  file:       mazemapelement.cpp
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

#include "mazemapelement.h"

namespace MazeDemo
{


//constuctor
MazeMapElement::MazeMapElement()
{
	m_NorthAccessible = true;
	m_SouthAccessible = true;
	m_EastAccessible = true;
	m_WestAccessible = true;
}


}
