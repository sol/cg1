//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   main.cpp - (c) 2003 by The Marrowmoon Group                            //
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
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include "camera.h"
#include "gllist.h"
#include "meshobject.h"
#include "cube.h"
#include "sphere.h"
#include "translation.h"
#include "animatedrotation.h"
#include "animationcontroller.h"
#include "cylinder.h"
#include "disk.h"
#include "grid.h"
#include "light.h"
#include "scaling.h"
#include "spotlight.h"
#include "pointlight.h"
#include "directionallight.h"
#include "animatedtranslation.h"


int handle_key_down(SDL_keysym* keysym) {
    
    if (keysym->sym == SDLK_ESCAPE) {
        SDL_Quit();
        exit(0);
    }
    if (keysym->sym == SDLK_SPACE){
        return 1;    
    }//PROV Pause

    return 0;
}



int process_events(void) {

    SDL_Event event;

    while(SDL_PollEvent(&event)) {

        if (event.type == SDL_KEYDOWN)
            return handle_key_down(&event.key.keysym);

        if (event.type == SDL_QUIT) {
            SDL_Quit();
            exit(0);
        }
    }
    return 0;
}

#define XX 50
#define YY 50
#define ZZ 50

int main(int argc, char** argv) {

    World MyWorld;
    Scene MyScene;
    Camera MyCamera; 

    MyScene.AddCamera(&MyCamera);
    MyWorld.AddScene(&MyScene);

    AnimationController MyAnimationController;
    MyCamera.AddTranslation(1, 1, 10);

    Grid grid(500, 500, 100, 100);
    grid.AddRotation(90, 1, 0, 0);
    MyScene.AddWorldObject( &grid );

//    SpotLight light1(30);
    PointLight light1;
    light1.SetColor(1, 1, 1, 1);
    Material *mat;
//    mat.SetColor(.2, .2, .3);
    Sphere* sph1;
    AnimatedRotation *aniRot;
    srand(49839775);
    for( int i = 0; i < 30; i++ ){
//        sph1 = new Cube( .4, .4, .4, GL_TRIANGLES );
        sph1 = new Sphere( 2, 30, 30, GLU_FILL );
        sph1->AddTranslation( rand()%XX / 10, rand()%YY / 10, rand()%ZZ / 10 );
        mat = new Material;
        mat->SetColor(rand()%3/10.0, rand()%3/10.0, rand()%3/10.0);
        sph1->SetMaterial( mat );
        aniRot = new AnimatedRotation( rand() % 360, (rand()%10/10.0)-.5, (rand()%10/10.0)-.5, (rand()%10/10.0)-.5, (rand() % 10 / 10.0)+.1 );
        sph1->AddTransform( aniRot );
        MyAnimationController.AddObject( aniRot );
        MyScene.AddWorldObject( sph1 );
        if( i == 0 )
            sph1->AddSubObject( &light1 );
    }
    while(1)
    {
        MyAnimationController.Animate();
        if( process_events() == 1 ) MyAnimationController.TogglePause();
        MyCamera.Render();

    }

    return 0;


}
