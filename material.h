#ifndef MATERIAL_H
#define MATERIAL_H

#include <GL/gl.h>

class Material
{
private:
    GLfloat* m_Ambient, *m_Diffuse, *m_Specular, *m_Emission, *m_Shininess;
    
public:
    Material();
    ~Material();

    //setters...
    void SetAmbient(GLfloat R, GLfloat G, GLfloat B, GLfloat A );
    void SetDiffuse(GLfloat R, GLfloat G, GLfloat B, GLfloat A );
    void SetSpecular(GLfloat R, GLfloat G, GLfloat B, GLfloat A );
    void SetEmission(GLfloat R, GLfloat G, GLfloat B, GLfloat A );
    void SetShininess(GLfloat R, GLfloat G, GLfloat B, GLfloat A );

    void Apply();
};

#endif
