//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   spotlight.h - (c) 2003 by The Marrowmoon Group                         //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#ifndef SPOTLIGHT_H
#define SPOTLIGHT_H

#include "light.h"


namespace Lights {

/**
 * \addtogroup Light
 * \{
 */

/**
 * \brief A light source with position and direction. Think: desk lamp.
 */
class SpotLight : public Light {
public:
	/**
	 * \brief Constructor
	 *
	 * \param Angle opening angle of the light cone
	 * \param red RGB color component
	 * \param green RGB color component
	 * \param blue RGB color component
	 */
    SpotLight(GLfloat Angle = 30, GLfloat red = 1.0, GLfloat green = 1.0, GLfloat blue = 1.0);
};

/**
 * \}
 */

}

#endif
