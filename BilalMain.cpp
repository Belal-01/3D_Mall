#pragma once
#include "BilalMain.h"
#include <iostream>
#include "texture.h"
#include "Wall.h"
#include "Glass.h"
#include <GL/glut.h>
#include "restorant.h"
#include "Stairs.h"
#include "elevator.h"

 Wall wall;
 Glass glass;
 Stairs stairs;
 Resturant resturant;
 Elevator elevator;
 int widthofWall = 80;
 int widthofRoof = 80;


void BilalMain::leftBuilding() {
    

    wall.floor(-4000, -920, 10, 0, -4000, resturant.KitchenFloorWoodTexture, 10,10);
    wall.floor(-920, 0, 10, 0, -5000, RoofFloorTexture, 1, 3);

    wall.frontWall(-4080, -1000, 0, 800, -4000, widthofWall,resturant.kitchenWallTexture,1,1,exteriorWall,6,2);
    wall.sideWall(-4080, 0, 800, 5, -1000, widthofWall,exteriorWall,2,2, resturant.kitchenLogo, 1, 1);
    wall.sideWall(-4080, 0, 800, -2000, -3000, widthofWall, exteriorWall, 2, 2, resturant.kitchenLogo, 1, 1);

    wall.sideWall(-4080, 0, 800, -3000, -4000, widthofWall,exteriorWall,2,2, resturant.kitchenWallWood, 5, 1);

    wall.Roof(-4080, -1000, 800, 60, -4080, widthofRoof, RoofFloorTexture, 3, 3);
    wall.Roof(-1000, 0, 800, 60, -2500, widthofRoof, RoofFloorTexture, 1, 2);
    /* wall.frontWall(-4000, -800, 0, 800, 0, 20);*/
  

    // 
    // elevatore in the first building
    wall.sideWall(-1000, 0, 800, -2500, -4000, widthofWall, resturant.kitchenWallWood, 5, 1, interiorWall, 1, 1);
    wall.sideWall(-1000, 0, 800, -4000, -5000, widthofWall, exteriorWall, 2, 2, interiorWall, 1, 1);

    wall.sideWall(-1000, 800, 2480, -2500, -5000, widthofWall,exteriorWall,4,4, interiorWall, 4, 2);

    wall.sideWall(0, 0, 1680, -2500, -3000, widthofWall, interiorWall, 1, 1, interiorWall, 1, 1);
    wall.sideWall(0, 0, 1680, -3000, -3800, widthofWall, interiorWall, 1, 1, interiorWall, 1, 1);
    wall.sideWall(0, 0, 1680, -3800, -5000, widthofWall, interiorWall, 1, 1, exteriorWall, 2, 4);

    wall.sideWall(0, 1680, 2480, -3000, -3800, widthofWall, interiorWall, 1, 1, interiorWall, 1, 1);
    wall.sideWall(0, 1680, 2480, -3800, -5000, widthofWall, interiorWall, 1, 1, exteriorWall, 2, 2);


    wall.Roof(-1000, 80, 2480, -2500, -5000, widthofRoof, RoofFloorTexture, 10, 15);


    // draw the stairs 
    wall.Roof(-950,0,400,-4350,-5000,40,RoofFloorTexture,1,1);
    wall.Roof(-950, 0, 840, -2500, -3150, 40, RoofFloorTexture, 1, 1);

    stairs.stairs(-775,0,-3750,0);
    stairs.stairs(-225, 440, -3750, 180);

    wall.Roof(-950, 0, 1280, -4350, -5000, 40, RoofFloorTexture, 1, 1);
    wall.Roof(-950, 0, 1720, -2500, -3150, 40, RoofFloorTexture, 1, 1);
    stairs.stairs(-775, 880, -3750, 0);
    stairs.stairs(-225, 1320, -3750, 180);


   
}

void BilalMain::rightBuilding() {
    wall.floor(0, 4080, 10, 5000, -3080, RoofFloorTexture, 2, 4);

    wall.frontWall(60, 120, 0, 1680, -3000, widthofWall,interiorWall,1,1,exteriorWall,1,1);
    wall.frontWall(650, 4000, 0, 1680, -3000, widthofWall, interiorWall, 2, 1, exteriorWall, 8, 4);

    wall.sideWall(4000, 0, 800, 5000, -3000, widthofWall, interiorWall, 8, 1, exteriorWall, 16, 2);
    wall.sideWall(4000, 880, 1680, 5000, -3000, widthofWall, interiorWall, 8, 1, exteriorWall, 16, 2);

    /*wall.sideWall(0, 0, 1600, 5000, 0, 20);*/
    

    wall.frontWall(-80, 4000, 0, 1680, 5000, widthofWall,exteriorWall,8,2,interiorWall,2,1);
    wall.Roof(-80, 4080, 800, 5000, 0, widthofRoof, RoofFloorTexture, 2, 4);
    wall.Roof(0, 4080, 800, 0, -3000, widthofRoof, RoofFloorTexture, 2, 4);

    wall.Roof(-80, 4080, 1680, 5000, 0, widthofRoof, RoofFloorTexture, 2, 4);
    wall.Roof(0, 4080, 1680, 0, -3080, widthofRoof, RoofFloorTexture, 2, 4);



    // split the building
    wall.frontWall(760, 4000, 0, 800, 1000, widthofWall,interiorWall,2,1,interiorWall,2,1);
    wall.frontWall(760, 4000, 880, 1680, 1000, widthofWall, interiorWall, 2, 1, interiorWall, 2, 1);

   

    // elevator of the second building
    wall.sideWall(800,0,2480,-3080,-3800,80,interiorWall,1,4,exteriorWall,1,4);

    
    wall.Roof(0, 880, 2480, -3000, -3800, 80, RoofFloorTexture, 1, 1);
    glPushMatrix();
    glTranslated(400, 0, -3400);
    elevator.elevatorRoom();
    
    glPopMatrix();
    glPushMatrix();
    glTranslated(400, 0, -3040);
    elevator.elevatorDoors();

    glPopMatrix();




}


void BilalMain::glasses() {

    //left building 
    glass.drawfrontWall(-1000, 0, 0, 2480, -4980, 0.7f);
    glass.drawfrontWall(-1000, 0, 1600, 2480, -2520, 0.7f);
    glass.drawfrontWall(-600, 0, 880, 1600, -2520, 0.7f);

    glass.drawfrontWall(-4000, -920, 0, 800, 0, 0.7f);




    glass.drawWall(-4000, -5000, 0, 1200, -1000, -2000, 0.7f);
    glass.drawTriangle(-4000, -3800, -5000, 0, 800, 1200, -1000, 0.7f);
    glass.drawTriangle(-4000, -3800, -5000, 0, 800, 1200, -2000, 0.7f);
    glass.drawRoof(-5000, -3800, 1200, -1000, -2000, 0.7f);
    //right building 

    glass.drawWall(800, 800, 0, 1680, -1500, -3000, 0.7);
    glass.drawWall(800, 800, 0, 1680, 1000, -500, 0.7);

    glass.drawWall(0, 0, 0, 1680, 5000, 0, 0.8f);


    glass.drawWall(800, 800, 0, 1680, 5000, 3500, 0.7);
    glass.drawWall(800, 800, 0, 1680, 2500, 1000, 0.7);
    glass.drawfrontWall(0, 800, 0, 2480, -3800, 0.8);

}


void BilalMain::init(){


    BilalMain::textureID = LoadTexture((char*)"images\\floorImg.bmp", 255.0f);
    BilalMain::secondFloorTexture = LoadTexture((char*)"images\\insidMallFloorTexture.bmp", 255.0f);
    BilalMain::RoofFloorTexture = LoadTexture((char*)"images\\floorInsidStore.bmp", 255.0f); // Use 255 for fully opaque
    BilalMain::interiorWall = LoadTexture((char*)"images\\interiorWall.bmp", 255.0f);
    BilalMain::exteriorWall = LoadTexture((char*)"images\\externalWall.bmp", 255.0f);
   


    resturant.resturantInit();
    stairs.stairsInit();
    elevator.init();

    }

void BilalMain::display() {
    glPushMatrix();

    wall.floor(-9000, 6000, -20, 9000, -6000, textureID, 50,50);
    resturant.resturantRoom();
    leftBuilding();
    rightBuilding();

    
    

    glPopMatrix();

}

