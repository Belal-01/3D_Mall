#pragma once
#include "texture.h"
#include <iostream>
#include "cameraConfiguration.h"
#include "Wall.h"
#include "Glass.h"
#include "ElectronicDeviceDrawer.h"
#include "TechnicalDivecesDrawer.h"
#include "Door.h"

class Abd
{
public :
    int xboxf, xboxb,wash,speaker,pcf,pcb,pcs,washw,fridge1,fridge3,washb,washr, wash2, fridge2, fridge, fridge4,aircondition,airconditionfan, s7ana;
    int brada1, brada2, brada3,brada4;
   float cameraX, cameraZ, cameraY;
    Glass glass;

    ElectronicDeviceDrawer electronic;
    TechnicalDivecesDrawer technical;
    float fanRotation = 0.0f;
    std::vector<Door> doors = {
    Door(1000,890, 820, 0.7f,90,570,800),
   Door(-3000,890, 820, 0.7f,90,570,800)
    };
    void AbdDraw(float CameraX, float CameraY, float CameraZ);
    
    void init();
};

