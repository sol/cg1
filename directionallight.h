//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   directionallight.h - (c) 2003 by The Marrowmoon Group                  //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#ifndef DIRECTIONALLIGHT_H
#define DIRECTIONALLIGHT_H

#include "light.h"


namespace Lights {
    
    
//this class provides Light with a constructor appropriate for directional lights
class DirectionalLight : public Light {
public:
    DirectionalLight(GLfloat red = 1.0, GLfloat green = 1.0, GLfloat blue = 1.0);
};

    
}

#endif
