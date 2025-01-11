#pragma once
#include "BilalMain.h"
#include <iostream>
#include "texture.h"
#include "Wall.h"
#include "Glass.h"
#include <GL/glut.h>
#include "restorant.h"

 Wall wall;
 Glass glass;
 Resturant resturant;
 int widthofWall = 80;
 int widthofRoof = 80;

void BilalMain::leftBuilding() {
    wall.floor(-4000, 0, 10, 0, -4000, resturant.KitchenFloorWoodTexture, 10);
    wall.frontWall(-4080, -1000, 0, 800, -4000, widthofWall,resturant.kitchenWallTexture,1,1);
    wall.sideWall(-4080, 0, 800, 0, -1000, widthofWall,textureID,1,1);
    wall.sideWall(-4080, 0, 800, -2000, -4000, widthofWall,textureID,1,1);

    wall.Roof(-4080, -1000, 800, 0, -4000, widthofRoof, RoofFloorTexture, 30, 40);
    wall.Roof(-1000, 0, 800, 0, -2500, widthofRoof, RoofFloorTexture, 10, 25);
    /* wall.frontWall(-4000, -800, 0, 800, 0, 20);*/
    glass.drawfrontWall(-4000, -800, 0, 800, 0, 0.7f);




    glass.drawWall(-4000, -5000, 0, 1200, -1000, -2000, 0.7f);
    glass.drawTriangle(-4000, -3800, -5000, 0, 800, 1200, -1000, 0.7f);
    glass.drawTriangle(-4000, -3800, -5000, 0, 800, 1200, -2000, 0.7f);
    glass.drawRoof(-5000, -3800, 1200, -1000, -2000, 0.7f);

    // 
    // elevatore in the first building
    wall.sideWall(-1000, 0, 2480, -2500, -4000, widthofWall,textureID,1,1);
    wall.sideWall(0, 0, 1680, -2500, -4000, widthofWall, textureID, 1, 1);
    wall.sideWall(0, 1600, 2480, -3000, -4000, widthofWall, textureID, 1, 1);
    glass.drawfrontWall(-1000, 0, 0, 2480, -3980, 0.7f);
    glass.drawfrontWall(-1000, 0, 1600, 2480, -2520, 0.7f);
    glass.drawfrontWall(-600, 0, 800, 1600, -2520, 0.7f);


    wall.Roof(-1000, 80, 2480, -2500, -4000, widthofRoof, RoofFloorTexture, 10, 15);
}

void BilalMain::rightBuilding() {
    wall.frontWall(0, 4000, 0, 1680, -3000, widthofWall,textureID,1,1);
    wall.sideWall(4000, 0, 1680, 5000, -3000, widthofWall, textureID, 1, 1);
    /*wall.sideWall(0, 0, 1600, 5000, 0, 20);*/
    glass.drawWall(0, 0, 0, 1680, 5000, 0, 0.8f);

    wall.frontWall(0, 4000, 0, 1680, 5000, widthofWall,textureID,1,1);
    wall.Roof(0, 4080, 800, 5000, -3000, widthofRoof, RoofFloorTexture, 40, 80);
    wall.Roof(0, 4080, 1680, 5000, -3000, widthofRoof, RoofFloorTexture, 20, 40);

    // split the building
    wall.frontWall(800, 4000, 0, 1680, 1000, widthofWall,textureID,1,1);
    glass.drawWall(800, 800, 0, 1680, -1500, -3000, 0.7);
    glass.drawWall(800, 800, 0, 1680, 1000, -500, 0.7);

    glass.drawWall(800, 800, 0, 1680, 5000, 3500, 0.7);
    glass.drawWall(800, 800, 0, 1680, 2500, 1000, 0.7);


}
void BilalMain::init() {


    BilalMain::textureID = LoadTexture((char*)"floorImg.bmp", 255.0f);
    BilalMain::secondFloorTexture = LoadTexture((char*)"insidMallFloorTexture.bmp", 255.0f);
    BilalMain::RoofFloorTexture = LoadTexture((char*)"floortexture.bmp", 255.0f); // Use 255 for fully opaque
    resturant.resturantInit();

}

void BilalMain::display() {
    glPushMatrix();

    wall.floor(-9000, 6000, 0, 9000, -6000, textureID, 50);
    leftBuilding();
    rightBuilding();

    resturant.resturantRoom();
    

    glPopMatrix();

}

