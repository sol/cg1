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


// for test use
#include "animatedtranslation.h"

AnimatedTranslation::AnimatedTranslation(GLfloat X, GLfloat Y, GLfloat Z):Translation(0, 0, 0), m_deltaX(X), m_deltaY(Y), m_deltaZ(Z){
    
}

AnimatedTranslation::~AnimatedTranslation(){
}

int AnimatedTranslation::Animate(){
    m_X += m_deltaX;
    m_Y += m_deltaY;
    m_Z += m_deltaZ;
    return 1; 
}
    
