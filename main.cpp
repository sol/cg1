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


Scene* Scene1();
Scene* Scene2();
Scene* Scene3();
Scene* Scene4();
Scene* Scene5();



int main(int argc, char** argv) {

    World MyWorld;
    AnimationController MyAnimationController;
    Scene* MyScene = Scene3();
//    MyWorld.AddScene( MyScene );

    int key;
    
    while(1)
    {
        key = process_events();
        if( key == TOGGLE_PAUSE ) MyScene->GetAnimationController()->TogglePause();
        if( key == SCENE1 ){ delete MyScene; MyScene = Scene1(); } 
        if( key == SCENE2 ){ delete MyScene; MyScene = Scene2(); } 
        if( key == SCENE3 ){ delete MyScene; MyScene = Scene3(); } 
        if( key == SCENE4 ){ delete MyScene; MyScene = Scene4(); } 
        if( key == SCENE5 ){ delete MyScene; MyScene = Scene5(); } 

        MyScene->Render();

    }

    return 0;


}



Scene* Scene1(){
    int XX = 50;
    int YY = 50;
    int ZZ = 50;
    Scene *MyScene = new Scene;
    Camera *MyCamera = new Camera;

    MyScene->SetCamera( MyCamera );
    AnimationController* MyAnimationController = MyScene->GetAnimationController();
    MyCamera->AddTranslation(1, 2, 10);

    Grid *grid = new Grid(500, 500, 100, 100);
    grid->AddRotation(90, 1, 0, 0);
    grid->SetMaterial(.1, .1, .1);
    MyScene->AddWorldObject( grid );


    Sphere *sph2 = new Sphere(2, 10, 10);
    sph2->SetMaterial(1, 1, 1);
    MyScene->AddWorldObject( sph2 );
    sph2->AddTranslation( 10, 4, 0 );

    Light* light1 = new PointLight(3, 3, 4); 
    light1->AddTranslation( 10, 4, 0 );
    MyScene->AddWorldObject( light1 );

    MeshObject* sph1;
    AnimatedRotation *aniRot;
    srand(0);
    for( int i = 0; i < 30; i++ ){

        sph1 = new Cylinder(.5, .5, .7);
//        sph1 = new Cube(.5, .5, .5);        
//        sph1 = new Sphere( .5, 30, 30, GLU_FILL );
        sph1->AddTranslation( rand()%XX / 10, rand()%YY / 10, rand()%ZZ / 10 );
        sph1->SetMaterial(rand()%3/10.0, rand()%3/10.0, rand()%3/10.0);
        
        aniRot = new AnimatedRotation( rand() % 360, (rand()%10/10.0)-.5, (rand()%10/10.0)-.5, (rand()%10/10.0)-.5, (rand() % 10 / 10.0)+.1 );
        sph1->AddTransform( aniRot );
        
        MyAnimationController->AddObject( aniRot );
        MyScene->AddWorldObject( sph1 );
        
    }
    return MyScene;
}


Scene* Scene2(){
    Scene *MyScene = new Scene;
    Camera *MyCamera = new Camera;

    MyScene->SetCamera( MyCamera );
    MyCamera->AddTranslation( 0, 0, 10 );

    Grid *grid = new Grid(100, 100, 100, 100);
    grid->SetMaterial(.1, .1, .1);
    MyScene->AddWorldObject( grid );
    grid->AddRotation(90, 1, 0, 0);

    MyCamera->AddRotation(-20, 1, 0, 0);
    MyCamera->AddTranslation(0, 20, 40);

    AnimatedTranslation* trans1 = new AnimatedTranslation(0, .1, 0);
    AnimatedTranslation *trans2 = new AnimatedTranslation(0, .1, 0);
        
    Sphere* sphere = new Sphere( 1, 20, 20, GLU_FILL );
    sphere->AddTranslation(0, -10, 0 );
    sphere->SetMaterial(1, 1, 1);
    sphere->AddTransform( trans1 );
    MyScene->AddWorldObject( sphere );
    
    
    Light *light1 = new PointLight;
    light1->AddTranslation(0, -10, 0 );
    MyScene->AddWorldObject( light1 );
    light1->AddTransform( trans2 );

    MyScene->GetAnimationController()->AddObject( trans1 );
    MyScene->GetAnimationController()->AddObject( trans2 );    
    return MyScene;
}
Scene* Scene3(){
    Scene *MyScene = new Scene;
    Camera *MyCamera = new Camera;
    
    MyCamera->AddRotation(-20, 1, 0, 0);
    MyCamera->AddTranslation(0, 20, 40);    

    Grid *grid = new Grid(100, 100, 100, 100);
    grid->SetMaterial(.1, .1, .1);
    MyScene->AddWorldObject( grid );
    grid->AddRotation(90, 1, 0, 0);
    grid->AddRotation(90, 0, 1, 0);

    Sphere* sphere = new Sphere(4, 30, 30);
    sphere->AddTranslation(0, 5, 0);
    sphere->SetMaterial(.5, .5, .5);
    MyScene->AddWorldObject( sphere );

    AnimatedRotation *rot1 = new AnimatedRotation(0, 0, 1, 0, 1),
                     *rot2 = new AnimatedRotation(0, 0, 1, 0, 1);
    MyScene->GetAnimationController()->AddObject( rot1 );
    MyScene->GetAnimationController()->AddObject( rot2 );
    
    Sphere* sphere2 = new Sphere(.5, 20, 20);
    sphere2->SetMaterial(1, 1, 1);
    MyScene->AddWorldObject( sphere2 );
    sphere2->AddTranslation(0, 4, 7);
    sphere2->AddTransform( rot1 );

    Light *light1 = new SpotLight(40);
    MyScene->AddWorldObject( light1 );
    light1->AddTranslation(0, 4, 7);
    light1->AddTransform( rot2 );
    
    MyScene->SetCamera( MyCamera );

    return MyScene;
}

Scene* Scene4(){
    Scene *MyScene = new Scene;
    Camera *MyCamera = new Camera;

//    MyCamera->AddRotation(-20, 1, 0, 0);
    MyCamera->AddTranslation(0, 0, 40);    
    

    Light *light1 = new PointLight;
    MyScene->AddWorldObject( light1 );
    light1->AddTranslation(7, 0, 0);

    Cylinder *cyl1 = new Cylinder(5, 6, 7);
    MyScene->AddWorldObject( cyl1 );

    MyScene->SetCamera( MyCamera );
    return MyScene;
}

Scene* Scene5(){
    Scene *MyScene = new Scene;
    Camera *MyCamera = new Camera;

    MyScene->SetCamera( MyCamera );
    return MyScene;
}
