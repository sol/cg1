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



//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   A simple OpenGL apllication using cpp and featuring hierarchical       //
//   transformations.                                                       //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   Authors: Markus Klinik and Simon Hengel                                //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   You should have received a copy of the GNU General Public License      //
//   with this software, if not it is availabel online at:                  //
//                                                                          //
//   http://www.gnu.org/copyleft/gpl.html                                   //
//                                                                          //
//   Make sure, you understand the license agreements before using this     //
//   sofrware.                                                              //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////
//                                                                          //
//   Comments of the Authors:                                               //
//                                                                          //
//   This program was written for a cg-course at the University of          //
//   Applied Sciences Georg-Simon-Ohm Fachhochschule Nuernberg. As we       //
//   think, it may be useful getting started with OpenGL. Feel free to      //
//   use it for any purpose you like (in accordance with the GNU General    //
//   Public License, see above).                                            //
//                                                                          //
//   The following features may be implemented in the future (as we think   //
//   they coul be useful):                                                  //
//                                                                          //
//   - LoadableMesh, a MeshObject, which gets its geometry defenition       //
//     from a file.                                                         //
//                                                                          //
//   -Additional materials like metal, plastic, glass, ...                  //
//                                                                          //
//   -Advanced scene-management by the World class.                         //
//                                                                          //
//   Known Bugs:                                                            //
//                                                                          //
//   - The hierarchical transformations work not in the right way, if       //
//     the camera is a sub-object.                                          //
//                                                                          //
//   If you have implemented one of the above or other useful features or   //
//   if you have done a bug fix, please let us know.                        //
//                                                                          //
//   Bug reports and additional comments are welcome.                       //
//                                                                          //
//   Contact: markus.klinik@gmx.de or simon.hengel@web.de                   //
//                                                                          //
//////////////////////////////////////////////////////////////////////////////

#include "world.h"

#include "scene.h"
#include "camera.h"
#include "animationcontroller.h"

#include "meshobjects.h"
#include "lights.h"
#include "transformations.h"
//#include "softmaterial.h"



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
    Scene* MyScene = Scene1();
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


//    Sphere *sph2 = new Sphere(2, 10, 10);
//    sph2->SetMaterial(1, 1, 1);
//    MyScene->AddWorldObject( sph2 );
//    sph2->AddTranslation( 10, 4, 0 );

    Light* light1 = new PointLight(2, 2, 2); 
    light1->AddTranslation( 10, 4, 0 );
    MyScene->AddWorldObject( light1 );

    MeshObject* sph1;
    AnimatedRotation *aniRot;
    srand(0);
    for( int i = 0; i < 30; i++ ){

//        sph1 = new Cylinder(.5, .5, .7);
//        sph1 = new Cube(.7, .7, .7);        
        sph1 = new Sphere( .5, 30, 30);
        sph1->AddTranslation( rand()%XX / 10, rand()%YY / 10, rand()%ZZ / 10 );
        sph1->SetMaterial(rand()%3/10.0, rand()%3/10.0, rand()%3/10.0);
        
        aniRot = new AnimatedRotation( rand() % 360, (rand()%10/10.0)-.5, (rand()%10/10.0)-.5, (rand()%10/10.0)-.5, (rand() % 10 / 10.0)+.1 );
        sph1->AddTransformation( aniRot );
        
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
    sphere2->AddTransformation( rot1 );

    Light *light1 = new SpotLight(40);
    MyScene->AddWorldObject( light1 );
    light1->AddTranslation(0, 4, 7);
    light1->AddTransformation( rot2 );
    
    MyScene->SetCamera( MyCamera );

    return MyScene;
}






Scene* Scene4(){
    Scene *MyScene = new Scene;
    Camera *MyCamera = new Camera;

//    MyCamera->AddRotation(-20, 1, 0, 0);
//    MyCamera->AddRotation(180, 0, 1, 0);
//    MyCamera->AddTranslation(0, 20, -40);    

    srand(12);
    int which;
    MeshObject* mob;
    AnimatedTranslation *AniTrans;
    for( int i = 0; i < 20; i++ ){
        //rings
        AniTrans = new AnimatedTranslation(0, 0, 0, 0, 0, -300, .0006, i/20.0);
        MyScene->GetAnimationController()->AddObject( AniTrans );

        Disk *disk = new Disk(5, 5.3, 50, 2);
        disk->AddTransformation( AniTrans );
        MyScene->AddWorldObject( disk );
        disk->SetMaterial(.1, i%5/5.0+.2, .1);
    }

    for( int i = 0; i < 60; i++){
        //flying objects
        AniTrans = new AnimatedTranslation(0, 0, -300, rand()%50/10.0-2.5, rand()%50/10.0-2.5, 300, .0012, i/60.0);
        MyScene->GetAnimationController()->AddObject( AniTrans );

        which = rand() % 3;
        if( which == 0 )
            mob = new Sphere(rand()%4/4.0+.2);
        else if( which == 1 )
            mob = new Cylinder(.4, .4, rand()%10/10.0+.2);
        else
            mob = new Cube(rand()%10/10.0+.2, rand()%10/10.0+.2, rand()%10/10.0+.2);
            
        mob->AddRotation(rand()%360, rand()%10/10.0, rand()%10/10.0, rand()%10/10.0);
        MyScene->AddWorldObject( mob );
        mob->AddTransformation( AniTrans );
        mob->SetMaterial(rand()%10/10.0+.2, rand()%10/10.0+.2, rand()%10/10.0+.2);
        
    }

    Grid *grid = new Grid(500, 500, 100, 100);
    grid->AddRotation(90, 1, 0, 0);
    grid->AddTranslation(0, -6, 0);
    grid->SetMaterial(.1, .1, .1);
    MyScene->AddWorldObject( grid );
    
    Light *light1 = new PointLight;
    MyScene->AddWorldObject( light1 );
    light1->AddTranslation(5, 5, -2);

    MyScene->SetCamera( MyCamera );
    return MyScene;
}

Scene* Scene5(){
    Scene *MyScene = new Scene;
    Camera *MyCamera = new Camera;

    MyScene->SetCamera( MyCamera );
    return MyScene;
}
