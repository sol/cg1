//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   animatedtranslation.cpp - (c) 2003 by The Marrowmoon Group                        //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////


#include "animatedtranslation.h"

namespace Transformations {
    
AnimatedTranslation::AnimatedTranslation(GLfloat startX, GLfloat startY, GLfloat startZ,
        GLfloat endX, GLfloat endY, GLfloat endZ,
        double Step, double StartFactor)
        :Translation(0, 0, 0), m_startX(startX), m_startY(startY), m_startZ(startZ),
        m_endX(endX), m_endY(endY), m_endZ(endZ), m_Step(Step), m_Factor(StartFactor){
}

AnimatedTranslation::~AnimatedTranslation(){
}

int AnimatedTranslation::Animate(){
    m_Factor += m_Step;
    if( m_Factor > 1 ) m_Factor = 0;
    m_X = m_startX + m_endX * m_Factor;
    m_Y = m_startY + m_endY * m_Factor;
    m_Z = m_startZ + m_endZ * m_Factor;
    return 1; 
}
}    
