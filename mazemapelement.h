//////////////////////////////////////////////////////////////////////////////
//
//  file:       mazemapelement.h
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

#ifndef MAZEMAPELEMENT_H
#define MAZEMAPELEMENT_H


namespace MazeDemo
{



class MazeMapElement
{
	bool m_NorthAccessible;
	bool m_SouthAccessible;
	bool m_EastAccessible;
	bool m_WestAccessible;
	
public:
	//constructor
	MazeMapElement();

	bool IsNorthAccessible() {return m_NorthAccessible;}
	bool IsSouthAccessible() {return m_SouthAccessible;}
	bool IsEastAccessible() {return m_EastAccessible;}
	bool IsWestAccessible() {return m_WestAccessible;}

	void SetNorthAccessibility(bool Accessibility) { m_NorthAccessible = Accessibility;}
	void SetSouthAccessibility(bool Accessibility) { m_SouthAccessible = Accessibility;}
	void SetEastAccessibility(bool Accessibility) { m_EastAccessible = Accessibility;}
	void SetWestAccessibility(bool Accessibility) { m_WestAccessible = Accessibility;}

};


}


#endif
