//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   gllist.h - (c) 2003 by The Marrowmoon Group                            //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#ifndef GLLIST_H
#define GLLIST_H

#include <GL/gl.h>



class GLList {
private:
    GLuint m_DisplayList;

public:
    GLList(GLuint DisplayList)  { m_DisplayList = DisplayList; }
    void ExecuteList()          { glCallList(m_DisplayList); }
    GLuint GetList()            { return m_DisplayList; }
};



#endif
