//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   camera.cpp - (c) 2003 by The Marrowmoon Group                          //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   This program is free software; you can redistribute it and/or modify   //
//   it under the terms of the GNU General Public License as published by   //
//   the Free Software Foundation; either version 2 of the License, or      //
//   (at your option) any later version.                                    //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#include "world.h"

#include "camera.h"
#include "scene.h"
#include "transformations.h"
#include "rotation.h"
#include "translation.h"

Camera::Camera() {
    m_pOpenGLContext = NULL;
    m_pAssociatedScene = NULL;

    //initialise OpenGL
    const SDL_VideoInfo* VideoInfo = SDL_GetVideoInfo();

    int bpp = VideoInfo->vfmt->BitsPerPixel;

    int width = 1024;
    int height = 768;

    if( SDL_SetVideoMode( width, height, bpp, SDL_OPENGL | SDL_FULLSCREEN ) == 0)
    {
        fprintf( stderr, "Video mode set failed: %s\n", SDL_GetError() );
        SDL_Quit();
        exit(1);
    }

    float ratio = (float) width / (float) height;

    //attributes of camera should be configured dynamically
    
    glShadeModel( GL_SMOOTH );
    glCullFace( GL_BACK );

    glFrontFace(GL_CCW);

//    glEnable( GL_CULL_FACE );
    glEnable( GL_DEPTH_TEST );

    SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 5 );
    SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

//    glClearColor(1, 1, 1, 1);
    glClearColor(0, 0, 0, 0);

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glEnable(GL_RENDER);
    glEnable(GL_LIGHTING);

    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, 0);

    //FOG

//    glEnable(GL_FOG);
//
//    GLfloat rgba[] = {1, 1, 1, 1};
//    glFogfv(GL_FOG_COLOR, rgba);
//
//
//    glFogi(GL_FOG_MODE, GL_LINEAR);
//    glFogf(GL_FOG_DENSITY, .5);
//
//    glFogf(GL_FOG_START, .5);
//    glFogf(GL_FOG_END, .6);

//    glHint(GL_FOG_HINT, GL_Fastest|FL_NICEST|GL_DONT_CARE);
 
    gluPerspective(60.0, ratio, 1.0, 1024.0);
}



void Camera::Render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    std::vector<Transformation*>::iterator it;
    for( it = m_Transformations.begin(); it < m_Transformations.end(); it++)
        (*it)->InverseApply();    

    if ( m_pAssociatedScene )
        m_pAssociatedScene->ExecuteAllObjects();

    glPopMatrix();


    SDL_GL_SwapBuffers();
}
