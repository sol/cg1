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
    GLfloat m_startX;
    GLfloat m_startY;
    GLfloat m_startZ;

    GLfloat m_endX;
    GLfloat m_endY;
    GLfloat m_endZ;

    double m_Step;
    double m_Factor;
    
    
public: 
	AnimatedTranslation(GLfloat startX, GLfloat startY, GLfloat startZ,
            GLfloat endX, GLfloat endY, GLfloat endZ,
            double Step=.01, double StartFactor=0.0);
            
	~AnimatedTranslation();
    int Animate();
};

#endif
