//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   directionallight.cpp - (c) 2003 by The Marrowmoon Group                //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#include "directionallight.h"


namespace Lights {

DirectionalLight::DirectionalLight(GLfloat red, GLfloat green, GLfloat blue) : Light(red, green, blue) {
    //the defaults are ok for directional lights
}
}
