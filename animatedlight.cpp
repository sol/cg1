#include "animatedlight.h"

AnimatedLight::AnimatedLight(GLfloat speed)
{
	m_speed = speed;
}

void
AnimatedLight::OnAnimate(unsigned int TimeToAnimate)
{
	GLfloat delta = m_speed * GLfloat(TimeToAnimate) / 1000.0;
	GLfloat r = m_aAmbient[0] + delta;

	if( r > 1.0 )
	{
		r = 1.0;
		m_speed = m_speed * -1;
	}
	else if( r < 0 )
	{
		r = 0;
		m_speed = m_speed * -1;
	}

	GLfloat g = 1.0 - r;
	GLfloat b = 1.0 - r;
	SetColor(r, g, b);
	//SetColor(0.5, 1.0, 0.7);
}
