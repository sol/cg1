#ifndef LIGHT_H
#define LIGHT_H



#include <GL/gl.h>

#include <worldobject.h>


//glEnable(GL_RENDER);
//glEnable(GL_LIGHTING);

//glShadeModle(GL_FLAT | GL_SMOOTH);

//glLightModlefv(GL_LIGHT_MODEL_AMBIENT, rgba);         //global ilumination
//glLightModlei(GL_LIGHT_MODEL_LOCAL_VIEWER, 0 | 1);    //specular reflection
//glLightModlei(GL_LIGHT_MODEL_TWO_SIDE, 0 | 1);        // off | on

//FOG

//glEnable(GL_FOG);

//glFogfv(GL_FOG_COLOR, rgba)

//glFogi(GL_FOG_MODE, GL_EXP | GL_LINEAR | GL_EXP2)
//glFog?(GL_FOG_DENSITY, 1 | any)

//glFogf(GL_FOG_START, 0.0 .. any);
//glFogf(GL_FOG_END, 0.0 .. any); (1)

//glHint(GL_FOG_HINT, GL_Fastest|FL_NICEST|GL_DONT_CARE);

class Color {
private:
    GLfloat m_Color[4];
    
public:
    Color(GLfloat Red, GLfloat Green, GLfloat Blue, GLfloat Alpha) {
        m_Color[0] = Red;
        m_Color[1] = Green;
        m_Color[2] = Blue;
        m_Color[3] = Alpha;
    }
    
    GLfloat* GetColorVector() {return m_Color;}
};


class Light : public WorldObject
{
private:
    virtual void DefineObject();
protected: 
    static bool* m_pIsAssigned;    //PROV
    static int m_MaxNrOfLights;


    bool m_IsValid;
    GLenum m_Light;
public:
	
    Light();
    ~Light();

    void Enable();
    void Disable();

    void SetAmbient(Color& _Color);
    void SetDiffuse(Color& _Color);
    void SetSpecular(Color& _Color);

    void SetAllColors(Color& _Color);
    void SetPosition(GLfloat* pPosition);

};

#endif
