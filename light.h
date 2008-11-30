//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   light.h - (c) 2003 by The Marrowmoon Group                             //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#ifndef LIGHT_H
#define LIGHT_H

#include "worldobject.h"


namespace Lights {

/**
 * \addtogroup Light
 * \{
 */


/**
 * \brief Base class for lights
 *
 * Base class for all lights, wrapping OpenGL lights (GL_LIGHT0, GL_LIGHT1,
 * ...). If you create more objects of the type Light then GL_MAX_LIGHTS you
 * will get emty dummy-objects (m_IsValid == false) 
 */
class Light : public WorldObject 
{
public:
	/**
	 * \brief OpenGL implementation dependent maximum number of lights
	 *
	 * Create at least one light to get a valid value.
	 */
    static int GetMaxNrOfLights() {return m_MaxNrOfLights;}

	/**
	 * \brief Constructor
	 *
	 * \param red RGB color component
	 * \param green RGB color component
	 * \param blue RGB color component
	 */
    Light(GLfloat red = 1.0, GLfloat green = 1.0, GLfloat blue = 1.0);

    virtual ~Light();

	/**
	 * \brief Switch light on
	 */
    void Enable()  {if (m_IsValid) glEnable(m_Light);}

	/**
	 * \brief Switch lighth off
	 */
    void Disable() {if (m_IsValid) glDisable(m_Light);}

	/**
	 * \brief Accessor for light color
	 */
    void SetColor(GLfloat red, GLfloat green, GLfloat blue);

private:
    virtual void DefineObject();

    //this static members are used to map the gl-internal lights to objets.
    static bool* m_pIsAssigned;
    static GLint m_MaxNrOfLights;

protected:
    bool m_IsValid;
    GLenum m_Light;

    //members mapping the glLight parameters
    GLfloat m_aAmbient[4];
    GLfloat m_aDiffuse[4];
    GLfloat m_aSpecular[4];
    GLfloat m_aPosition[4];
    GLfloat m_aSpotDirection[3];
    GLfloat m_SpotExponent;
    GLfloat m_SpotCutoff;
    GLfloat m_ConstantAttenuation;
    GLfloat m_LinearAttenuation;
    GLfloat m_QuadraticAttenuation;
};


/**
 * \}
 */


}

#endif
