#include "texture.h"
#include <iostream>
#include "cameraConfiguration.h"
#include "Wall.h"
#include "Glass.h"
#include "ElectronicDeviceDrawer.h"
int xboxf, xboxb;
ElectronicDeviceDrawer electronic;
float fanRotation = 0.0f;
void AbdDraw() {

    fanRotation += 10.0f; // “Ì«œ… «·“«ÊÌ… »„ﬁœ«— 1 œ—Ã… ›Ì ﬂ· „—…
    if (fanRotation >= 360.0f) {
        fanRotation = 0.0f; // ≈⁄«œ…  ⁄ÌÌ‰ «·“«ÊÌ… ≈·Ï 0 ⁄‰œ «·Ê’Ê· ≈·Ï 360 œ—Ã…
    }
    electronic.drawLaptop(0, 10, 0, 0, 0, 0);
    electronic.drawAirConditionerWithFan(100, 100, 0, 0, 0, 0, fanRotation);
    electronic.drawCeilingFanWithArm(100, 200, 0, 0, 0, 0, fanRotation);
    electronic.drawfireplace(0, 300, 0, 0, 0, 0);
    electronic.drawComputerMonitor(400, 50, 0, 0, 0, 0);
    electronic.drawPhone(200, 10, 0, 0, 0, 0, 1, 0.5, 0);
    electronic.drawTablet(250, 10, 0, 0, 0, 0, 0, 1, 1);
    electronic.drawPS5(500, 0, 0, 0, 0, 0);
    electronic.drawXbox(600, 50, 0, 0, 0, 0, xboxf, xboxb);
    electronic.drawScreen(300, 10, 0, 0, 0, 0);
    electronic.drawKeyboard(450, 10, 0, 0, 0, 0);

}
void AbdLoadPhotos() {
    xboxf= LoadTexture((char*)"xboxf.bmp", 255.0f);
    xboxb = LoadTexture((char*)"xboxb.bmp", 255.0f);
}