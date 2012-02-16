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
    
/**
 * \addtogroup Light
 * \{
 */
    
/**
 * \brief An "infinite distant" light source. Light beams are parallel, coming
 * from a direction. Think: the sun.
 */
class DirectionalLight : public Light {
public:
	/**
	 * \brief Constructor
	 *
	 * \param red RGB color component
	 * \param green RGB color component
	 * \param blue RGB color component
	 */
    DirectionalLight(GLfloat red = 1.0, GLfloat green = 1.0, GLfloat blue = 1.0);
};

/**
 * \}
 */

    
}

#endif
