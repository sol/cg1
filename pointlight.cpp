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


namespace Lights {
    

PointLight::PointLight(GLfloat red, GLfloat green, GLfloat blue, int type) : Light(red, green, blue)  {
    if(m_IsValid) {
        m_aPosition[0] = 0.0; m_aPosition[1] = 0.0; m_aPosition[2] = 0.0; m_aPosition[3] = 1.0;
        m_SpotCutoff = 180.0;
		m_ConstantAttenuation = 0.0;
        m_LinearAttenuation = 0.0;
        m_QuadraticAttenuation = 0.0;
		if( type == POINTLIGHT_CONSTANT ) m_ConstantAttenuation = 1.0;
		if( type == POINTLIGHT_LINEAR ) m_LinearAttenuation = 1.0;
		if( type == POINTLIGHT_QUADRATIC ) m_QuadraticAttenuation = 1.0;
    }
}

    
}
