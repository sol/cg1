//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   animatedtranslation.h - (c) 2003 by The Marrowmoon Group                        //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
#ifndef ANIMATEDTRANSLATION_H
#define ANIMATEDTRANSLATION_H

#include "world.h"

#include "translation.h"
#include "animatedobject.h"


class AnimatedTranslation : public Translation, public AnimatedObject  {
private:
    GLfloat m_deltaX;
    GLfloat m_deltaY;
    GLfloat m_deltaZ;
    
public: 
	AnimatedTranslation(GLfloat X, GLfloat Y, GLfloat Z);
	~AnimatedTranslation();
    int Animate();
};

#endif
