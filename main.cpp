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


int TOGGLE_PAUSE = SDLK_SPACE;
int SCENE1 = SDLK_1;
int SCENE2 = SDLK_2;
int SCENE3 = SDLK_3;
int SCENE4 = SDLK_4;
int SCENE5 = SDLK_5;


int handle_key_down(SDL_keysym* keysym) {
    
    if (keysym->sym == SDLK_ESCAPE) {
        SDL_Quit();
        exit(0);
    }
        return keysym->sym;    
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


Scene* Scene1(AnimationController* MyAnimationController);
Scene* Scene2(AnimationController* MyAnimationController);
Scene* Scene3(AnimationController* MyAnimationController);
Scene* Scene4(AnimationController* MyAnimationController);
Scene* Scene5(AnimationController* MyAnimationController);


int main(int argc, char** argv) {

    World MyWorld;
    AnimationController MyAnimationController;
    Scene* MyScene = Scene2( &MyAnimationController );
//    MyWorld.AddScene( MyScene );

    int key;
    
    while(1)
    {
        MyAnimationController.Animate();
        key = process_events();
        if( key == TOGGLE_PAUSE ) MyAnimationController.TogglePause();
        if( key == SCENE1 ){ delete MyScene; MyScene = Scene1( &MyAnimationController ); } 
        if( key == SCENE2 ){ delete MyScene; MyScene = Scene2( &MyAnimationController ); } 
        if( key == SCENE3 ){ delete MyScene; MyScene = Scene3( &MyAnimationController ); } 
        if( key == SCENE4 ){ delete MyScene; MyScene = Scene4( &MyAnimationController ); } 
        if( key == SCENE5 ){ delete MyScene; MyScene = Scene5( &MyAnimationController ); } 

        MyScene->Render();

    }

    return 0;


}



Scene* Scene1(AnimationController* MyAnimationController){
    int XX = 50;
    int YY = 50;
    int ZZ = 50;
    Scene *MyScene = new Scene;
    Camera *MyCamera = new Camera;

    MyScene->SetCamera( MyCamera );

    MyCamera->AddTranslation(1, 1, 10);

    Grid *grid = new Grid(500, 500, 100, 100);
    grid->AddRotation(90, 1, 0, 0);
    MyScene->AddWorldObject( grid );

    Rotation *rot1 = new Rotation(1, 1, 0, 0);

//    SpotLight light1(30);
    PointLight* light1 = new PointLight;
    light1->AddTransform( rot1 );
    light1->SetColor(.3, 1, .3);
    Sphere* sph1;
    AnimatedRotation *aniRot;
    srand(2355753);
    for( int i = 0; i < 30; i++ ){
//        sph1 = new Cube( .4, .4, .4, GL_TRIANGLES );
        sph1 = new Sphere( .5, 30, 30, GLU_FILL );
        sph1->AddTranslation( rand()%XX / 10, rand()%YY / 10, rand()%ZZ / 10 );
        
        sph1->SetMaterial(rand()%3/10.0, rand()%3/10.0, rand()%3/10.0);
        aniRot = new AnimatedRotation( rand() % 360, (rand()%10/10.0)-.5, (rand()%10/10.0)-.5, (rand()%10/10.0)-.5, (rand() % 10 / 10.0)+.1 );
        sph1->AddTransform( aniRot );
        MyAnimationController->AddObject( aniRot );
        MyScene->AddWorldObject( sph1 );
        if( i == 0 )
            sph1->AddSubObject( light1 );
            sph1->AddTransform( rot1 );
    }
    return MyScene;
}


Scene* Scene2(AnimationController* MyAnimationController){
    Scene *MyScene = new Scene;
    Camera *MyCamera = new Camera;

    MyScene->SetCamera( MyCamera );
    MyCamera->AddTranslation( 0, 0, 10 );

    Disk *disk1 = new Disk( 3, 4, 20, 5, GLU_FILL );
    
    disk1->SetMaterial(.2, .2, .3);
    MyScene->AddWorldObject( disk1 );
    
    return MyScene;
}
Scene* Scene3(AnimationController* MyAnimationController){
    Scene *MyScene = new Scene;
    Camera *MyCamera = new Camera;

    MyScene->SetCamera( MyCamera );

    return MyScene;
}

Scene* Scene4(AnimationController* MyAnimationController){
    Scene *MyScene = new Scene;
    Camera *MyCamera = new Camera;

    MyScene->SetCamera( MyCamera );
    return MyScene;
}

Scene* Scene5(AnimationController* MyAnimationController){
    Scene *MyScene = new Scene;
    Camera *MyCamera = new Camera;

    MyScene->SetCamera( MyCamera );
    return MyScene;
}
