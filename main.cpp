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

  



int main(int argc, char** argv) {

    World MyWorld;
    Scene MyScene;
    Camera MyCamera; 

    MyScene.AddCamera(&MyCamera);
    MyWorld.AddScene(&MyScene);

    AnimationController MyAnimationController;

    AnimatedRotation AniRot( 0, 0, 1, 0, 1 );
    AnimatedRotation AniRot2( 0, 1, 0, 0, -1 );
    
    AnimatedTranslation AniTransZ(0, 0, 1);
    MyAnimationController.AddObject( &AniTransZ );
    MyAnimationController.AddObject( &AniRot );
    MyAnimationController.AddObject( &AniRot2 );
    
//    MyCamera.AddTransform( &AniRot );
    MyCamera.AddTranslation(0, 0, 40);
//    MyCamera.AddRotation(45, 1, 0, 0 );
    MyCamera.AddRotation( -20, 1, 0, 0 );
//    MyCamera.AddTransform( &AniRot2 );
//    MyCamera.AddTransform( &AniTransZ );
    
    
    Material NormalMat;
    NormalMat.SetEmission(.2, .2, .3, 0);
    NormalMat.SetAmbient(0, 0, 0, 0);
    NormalMat.SetDiffuse(0, 0, 0, 0);
    NormalMat.SetShininess(0, 0, 0, 0);
    NormalMat.SetSpecular(.2, .5, .3, 0);
    Sphere MySphere( 5, 80, 80, GLU_FILL );
    MyScene.AddWorldObject( &MySphere );
    MySphere.SetMaterial( &NormalMat );
    
//    MySphere.AddTransform( &AniRot );
//    MySphere.AddTranslation(0, 0, -10);
    Grid MyGrid(100, 100, 200, 200);
    MyGrid.AddRotation(90, 1, 0, 0);
    MyGrid.AddTranslation(0, -6, 0);
    MyScene.AddWorldObject( &MyGrid );
    MyGrid.SetMaterial( &NormalMat );


    Material LBMat;
    LBMat.SetEmission(1, 1, 1, 1);
    
    Sphere Sphere2( 4, 80, 80, GLU_FILL );
    Sphere2.AddTranslation(0, 0, -10);
    Sphere2.SetMaterial( &NormalMat );
    Sphere2.AddTransform( &AniRot );
    MyScene.AddWorldObject( &Sphere2 );
        
    Disk Disk1( 5, 6, 20, 3, GLU_LINE );
    MySphere.AddSubObject( &Disk1 );

    Sphere LightBulb(.5, 10, 10, GLU_FILL );
    LightBulb.SetMaterial( &LBMat );

//    PointLight MySpot;
    SpotLight MySpot(30);
    MySpot.AddSubObject( &LightBulb );
    MySphere.AddSubObject( &MySpot );
    MySpot.AddTranslation(0, 0, 20);
    MySpot.AddTransform( &AniRot );  
//	MySpot.AddRotation(5, 1, 0, 0);


    while(1)
    {
        MyAnimationController.Animate();
        if( process_events() == 1 ) MyAnimationController.TogglePause();
        MyCamera.Render();

    }

    return 0;


}
