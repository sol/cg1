//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   pointlight.cpp - (c) 2003 by The Marrowmoon Group                      //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
#include "pointlight.h"



PointLight::PointLight() {
    if(m_IsValid) {
        m_aPosition[0] = 0.0; m_aPosition[1] = 0.0; m_aPosition[2] = 0.0; m_aPosition[3] = 1.0;
        m_SpotCutoff = 180.0;
    }
}
