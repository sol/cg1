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
#include <exception>



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
        Scene* MyScene = Scene2();
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
        sph1 = new Sphere( .5, 30, 30, GLU_FILL );
        sph1->AddTranslation( rand()%XX / 10, rand()%YY / 10, rand()%ZZ / 10 );
        sph1->SetMaterial(rand()%3/10.0, rand()%3/10.0, rand()%3/10.0);
        
        aniRot = new AnimatedRotation( rand() % 360, (rand()%10/10.0)-.5, (rand()%10/10.0)-.5, (rand()%10/10.0)-.5, (rand() % 10 / 10.0)+.1 );
        sph1->AddTransformation( aniRot );
        
        MyAnimationController->AddObject( aniRot );
        MyScene->AddWorldObject( sph1 );
        
    }
    return MyScene;
}

/*************************************************************************************************/
Scene* Scene2(){
    Scene *MyScene = new Scene;
    Camera *MyCamera = new Camera;

    MyScene->SetCamera( MyCamera );
    MyCamera->AddTranslation( 0, 0, 6 );
//    MyCamera->AddRotation(-30, 1, 0, 0);

    Grid *grid = new Grid(100, 100, 100, 100);
    grid->AddRotation(90, 1, 0, 0);
    grid->AddTranslation(0, -.5, 0);
    grid->SetMaterial(.1, .1, .1);
    MyScene->AddWorldObject( grid );
    
    OscillatingRotation *WalkUpper1 = new OscillatingRotation(-60, 60, .01, 1, 0, 0, 0, OSCIL_SINUS);
    OscillatingRotation *WalkLower1 = new OscillatingRotation(0, 90, .01, 1, 0, 0, 0, OSCIL_SINUS);
    MyScene->GetAnimationController()->AddObject( WalkUpper1 );
    MyScene->GetAnimationController()->AddObject( WalkLower1 );
   
    OscillatingRotation *WalkUpper2 = new OscillatingRotation(-60, 60, .01, 1, 0, 0, .5, OSCIL_SINUS);
    OscillatingRotation *WalkLower2 = new OscillatingRotation(0, 90, .01, 1, 0, 0, .5, OSCIL_SINUS);
    MyScene->GetAnimationController()->AddObject( WalkUpper2 );
    MyScene->GetAnimationController()->AddObject( WalkLower2 );

    OscillatingRotation *WalkArm1 = new OscillatingRotation( -60, 100, .01, 1, 0, 0, 0.5, OSCIL_SINUS);
    MyScene->GetAnimationController()->AddObject( WalkArm1 );
    OscillatingRotation *WalkArm2 = new OscillatingRotation( -60, 100, .01, 1, 0, 0, 0, OSCIL_SINUS);
    MyScene->GetAnimationController()->AddObject( WalkArm2 );

    OscillatingRotation *WalkTorso = new OscillatingRotation( -10, 10, .01, 0, 1, 0, 0.5, OSCIL_SINUS);
    MyScene->GetAnimationController()->AddObject( WalkTorso );

//    AnimatedTranslation *Walk = new AnimatedTranslation(-7, 0, -5, 10, 0, 6, .05, 0);
//    MyScene->GetAnimationController()->AddObject( Walk );
    AnimatedRotation* circle = new AnimatedRotation( 0, 0, 1, 0, .6 );
    AnimatedRotation *rot1 = new AnimatedRotation(0, 0, -1, 0, 1);
    MyScene->GetAnimationController()->AddObject( circle );
    MyScene->GetAnimationController()->AddObject( rot1 );

    //Torso
    Cube *Torso = new Cube(.22, .35, .1);
    Torso->AddTranslation(-.11, -.175, -.05);
    Torso->SetMaterial(.1, .3 , .1);
//    Torso->AddRotation(60, 0, 1, 0);
    Torso->AddTransformation( WalkTorso );
//    Torso->AddTransformation( rot1 );
    Torso->AddTranslation(-3, 0, 0);
    Torso->AddTransformation( circle );

    //Head
    Sphere *Head = new Sphere(.11);
    Head->AddTranslation(.1, .5, .05);
    Torso->AddSubObject( Head );
    Head->SetMaterial(.3, .2, .2);

    //Left Arm
    Cylinder* LUpperArm = new Cylinder(.05, .05, .2 );
    Torso->AddSubObject( LUpperArm );
    LUpperArm->AddRotation( 90, 0, 1, 0 );
    LUpperArm->AddTranslation( -.2, 0, 0 );
    LUpperArm->SetMaterial(.1, .3, .1);
    //Add Custom Rotations!!
    LUpperArm->AddRotation( 90, 0, 0, 1 );
    LUpperArm->AddTransformation( WalkArm1 );

    LUpperArm->AddTranslation( -.02, .30, .05 );
    Cylinder* LLowerArm = new Cylinder( .05, .05, .2 );
    LLowerArm->AddTranslation( 0, 0, -.22 );
    //AddCustomRotations!
    LLowerArm->AddRotation(90, 0, 1, 0);

    LUpperArm->AddSubObject( LLowerArm );

    //Right Arm
    Cylinder* RUpperArm = new Cylinder(.05, .05, .2 );
    Torso->AddSubObject( RUpperArm );
    RUpperArm->AddRotation( 90, 0, 1, 0 );
    //Add Custom Rotations!!
    RUpperArm->AddRotation(-90, 0, 0, 1);
    RUpperArm->AddTransformation( WalkArm2 );

    RUpperArm->AddTranslation( .24, .30, .05 );
    Cylinder* RLowerArm = new Cylinder( .05, .05, .2 );
    //AddCustomRotations!
    RLowerArm->AddRotation(-90, 0, 1, 0);

    RLowerArm->AddTranslation( 0, 0, .22 );
    RUpperArm->AddSubObject( RLowerArm );

    //Left Leg
    Cylinder *LUpperLeg = new Cylinder(.05, .05, .2);
    LUpperLeg->AddRotation(90, 1, 0, 0);
    LUpperLeg->SetMaterial(.1, .1, .3);
    Torso->AddSubObject( LUpperLeg );
    //AddCustomRotations!!
    LUpperLeg->AddTransformation( WalkUpper1 );

    LUpperLeg->AddTranslation(.05, -.01, .05);
    Cylinder *LLowerLeg = new Cylinder(.05, .05, .2);
    //Custom Rotations
    LLowerLeg->AddTransformation( WalkLower1 );

    LLowerLeg->AddTranslation(0, 0, .21);
    LUpperLeg->AddSubObject( LLowerLeg );

    //Right Leg
    Cylinder *RUpperLeg = new Cylinder( .05, .05, .2 );
    Torso->AddSubObject( RUpperLeg );
    RUpperLeg->AddRotation( 90, 1, 0, 0 );
    //Custom Rotations
    RUpperLeg->AddTransformation( WalkUpper2 );

    RUpperLeg->AddTranslation( .17, -.01, .05 );

    Cylinder *RLowerLeg = new Cylinder( .05, .05, .2 );
    RUpperLeg->AddSubObject( RLowerLeg );
    //Custom Rotations
    RLowerLeg->AddTransformation( WalkLower2 );

    RLowerLeg->AddTranslation( 0, 0, .21 );

    Light *light1 = new PointLight;
    light1->AddTranslation(-7, 7, 7);

    MyScene->AddWorldObject( light1 );
    MyScene->AddWorldObject( Torso );
    

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

    Light *light1 = new PointLight;
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
    AnimatedRotation *AniRot;
    for( int i = 0; i < 20; i++ ){
        //rings
        AniTrans = new AnimatedTranslation(0, 0, -300, 0, 0, 300, .0006, i/20.0);
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

        AniRot = new AnimatedRotation(0, rand()%10/10.0-.5, rand()%10/10.0-.5, rand()%10/10.0-.5, rand()%40/10.0);
        MyScene->GetAnimationController()->AddObject( AniRot );
        mob->AddTransformation( AniRot );
        
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
