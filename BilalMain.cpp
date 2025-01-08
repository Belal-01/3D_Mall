#pragma once
#include "BilalMain.h"
#include <iostream>
#include "texture.h"
#include "Wall.h"
#include "Glass.h"
#include <GL/glut.h>

 Wall wall;
 Glass glass;
 int widthofWall = 80;
 int widthofRoof = 80;

void BilalMain::leftBuilding() {
    wall.frontWall(-4080, 0, 0, 800, -4000, widthofWall);
    wall.sideWall(-4080, 0, 800, 0, -1000, widthofWall);
    wall.sideWall(-4080, 0, 800, -2000, -4000, widthofWall);

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
    wall.sideWall(-1000, 0, 2480, -2500, -4000, widthofWall);
    wall.sideWall(0, 0, 1680, -2500, -4000, widthofWall);
    wall.sideWall(0, 1600, 2480, -3000, -4000, widthofWall);
    glass.drawfrontWall(-1000, 0, 800, 2480, -4000, 0.7f);
    glass.drawfrontWall(-1000, 0, 1600, 2480, -2500, 0.7f);
    glass.drawfrontWall(-600, 0, 800, 1600, -2500, 0.7f);


    wall.Roof(-1000, 80, 2480, -2500, -4000, widthofRoof, RoofFloorTexture, 10, 15);
}

void BilalMain::rightBuilding() {
    wall.frontWall(0, 4000, 0, 1680, -3000, widthofWall);
    wall.sideWall(4000, 0, 1680, 5000, -3000, widthofWall);
    /*wall.sideWall(0, 0, 1600, 5000, 0, 20);*/
    glass.drawWall(0, 0, 0, 1600, 5000, 0, 0.8f);

    wall.frontWall(0, 4000, 0, 1680, 5000, widthofWall);
    wall.Roof(0, 4080, 800, 5000, -3000, widthofRoof, RoofFloorTexture, 40, 80);
    wall.Roof(0, 4080, 1680, 5000, -3000, widthofRoof, RoofFloorTexture, 20, 40);
}
void BilalMain::init() {


    BilalMain::textureID = LoadTexture((char*)"floorImg.bmp", 255.0f);
    BilalMain::secondFloorTexture = LoadTexture((char*)"insidMallFloorTexture.bmp", 255.0f);
    BilalMain::RoofFloorTexture = LoadTexture((char*)"floortexture.bmp", 255.0f); // Use 255 for fully opaque
  /*  if (textureID < 0) {
        std::cerr << "Failed to load texture." << std::endl;
        exit(1);
    }*/
}

void BilalMain::display() {
    glPushMatrix();

    wall.floor(-9000, 6000, 0, 9000, -6000, textureID, 50);
    leftBuilding();
    rightBuilding();

    glPopMatrix();

}

