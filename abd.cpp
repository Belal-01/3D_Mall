#include "abd.h"

void Abd::init()
{
    xboxb = LoadTexture((char*)"xboxb.bmp", 255.0f);
   xboxf = LoadTexture((char*)"xboxf.bmp", 255.0f);
   wash = LoadTexture((char*)"wash.bmp", 255);
   washw = LoadTexture((char*)"washw.bmp", 255);
   washb= LoadTexture((char*)"washb.bmp", 255);
   washr = LoadTexture((char*)"washr.bmp", 255);
   wash2= LoadTexture((char*)"wash2.bmp", 255);
   speaker = LoadTexture((char*)"speaker.bmp", 255);
   pcf = LoadTexture((char*)"pcf.bmp", 255);
   pcb = LoadTexture((char*)"pcb.bmp", 255);
   pcs = LoadTexture((char*)"pcs.bmp", 255);
   fridge1= LoadTexture((char*)"fridge.bmp", 255);
}

void Abd::AbdDraw()
{
    fanRotation += 10.0f; // “Ì«œ… «·“«ÊÌ… »„ﬁœ«— 1 œ—Ã… ›Ì ﬂ· „—…
    if (fanRotation >= 360.0f) {
        fanRotation = 0.0f; // ≈⁄«œ…  ⁄ÌÌ‰ «·“«ÊÌ… ≈·Ï 0 ⁄‰œ «·Ê’Ê· ≈·Ï 360 œ—Ã…
    }
   
    electronic.drawFridge(900, 890, 200, 0,270, 0);
    electronic.drawFridge(900, 890, -300, 0, 270, 0, fridge1, 0.2, 0.2, 0.2);
    electronic.drawFridge(900, 890, -50, 0, 270, 0);
    electronic.drawWashingMachine(900, 890, 400,0, 270, 0,wash,0.1,0.1,0.1);
    electronic.drawWashingMachine(900, 890, 600, 0, 270, 0, washw, 0.4, 0.4, 0.4);
    electronic.drawWashingMachine(900, 890, 800, 0, 270, 0, washr, 0.40, 0.13, 0.18);
    electronic.drawWashingMachine(1100, 890, 800, 0, 180, 0, washb, 0.16, 0.23, 0.27);
    electronic.drawWashingMachine(1300, 890, 800, 0, 180, 0, washr, 0.40, 0.13, 0.18);
    electronic.drawWashingMachine(1500, 890, 800, 0, 180, 0, wash, 0.1, 0.1, 0.1);
    electronic.drawWashingMachine(1700, 890, 800, 0, 180, 0, washw, 0.4, 0.4, 0.4);
    electronic.drawWashingMachine(1900, 890, 800, 0, 180, 0, wash2, 0.5, 0.5, 0.5);
}
