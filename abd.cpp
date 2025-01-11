#include "abd.h"

void Abd::init()
{
    xboxb = LoadTexture((char*)"xboxb.bmp", 255.0f);
   xboxf = LoadTexture((char*)"xboxf.bmp", 255.0f);
   wash = LoadTexture((char*)"wash.bmp", 255);
   speaker = LoadTexture((char*)"speaker.bmp", 255);
   pcf = LoadTexture((char*)"pcf.bmp", 255);
   pcb = LoadTexture((char*)"pcb.bmp", 255);
   pcs = LoadTexture((char*)"pcs.bmp", 255);
}

void Abd::AbdDraw()
{
    fanRotation += 10.0f; // “Ì«œ… «·“«ÊÌ… »„ﬁœ«— 1 œ—Ã… ›Ì ﬂ· „—…
    if (fanRotation >= 360.0f) {
        fanRotation = 0.0f; // ≈⁄«œ…  ⁄ÌÌ‰ «·“«ÊÌ… ≈·Ï 0 ⁄‰œ «·Ê’Ê· ≈·Ï 360 œ—Ã…
    }
    technical.drawLaptop(0, 10, 0, 0, 0, 0);
    electronic.drawAirConditionerWithFan(100, 100, 0, 0, 0, 0, fanRotation);
    electronic.drawCeilingFanWithArm(100, 200, 0, 0, 0, 0, fanRotation);
    electronic.drawfireplace(0, 300, 0, 0, 0, 0);
    technical.drawComputerMonitor(400, 50, 0, 0, 0, 0);
    technical.drawPhone(200, 10, 0, 0, 0, 0, 1, 0.5, 0);
    technical.drawTablet(250, 10, 0, 0, 0, 0, 0, 1, 1);
    technical.drawPS5(500, 0, 0, 0, 0, 0);
    technical.drawXbox(600, 50, 0, 0, 0, 0, xboxf, xboxb);
    technical.drawScreen(300, 10, 0, 0, 0, 0);
    electronic.drawFridge(700, 50, 0, 0, 0, 0);
    electronic.drawWashingMachine(800, 50, 0, 0, 0, 0,wash);
    technical.drawKeyboard(450, 10, 0, 0, 0, 0);
    technical.drawSpeakerFrame(900, 100, 0, 0, 0, 0, speaker);
    technical.drawComputerCase(950, 0, 0, 0, 0, 0,pcf,pcb,pcs);
}
