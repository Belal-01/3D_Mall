#pragma once
#include "texture.h"
#include <iostream>
#include "cameraConfiguration.h"
#include "Wall.h"
#include "Glass.h"
#include "ElectronicDeviceDrawer.h"
#include "TechnicalDivecesDrawer.h"
class Abd
{
public :
    int xboxf, xboxb,wash,speaker,pcf,pcb,pcs,washw,fridge1,washb,washr, wash2;
    
    ElectronicDeviceDrawer electronic;
    TechnicalDivecesDrawer technical;
    float fanRotation = 0.0f;
    void AbdDraw();
    
    void init();
};

