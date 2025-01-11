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
   fridge = LoadTexture((char*)"fridge1.bmp", 255);
   fridge1= LoadTexture((char*)"fridge.bmp", 255); 
   fridge2 = LoadTexture((char*)"fridge2.bmp", 255);
   fridge3 = LoadTexture((char*)"fridge3.bmp", 255);
   fridge4 = LoadTexture((char*)"fridge4.bmp", 255);
   ///not finished
   aircondition= LoadTexture((char*)"aircondition.bmp", 255);
   airconditionfan = LoadTexture((char*)"airconditionfan.bmp", 255);
   brada1 = LoadTexture((char*)"brada1.bmp", 255);
   brada2 = LoadTexture((char*)"brada2.bmp", 255);
   brada3 = LoadTexture((char*)"brada3.bmp", 255);
   brada4 = LoadTexture((char*)"brada4.bmp", 255);
   s7ana = LoadTexture((char*)"s7ana.bmp", 255);
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
    electronic.drawFridge(2100, 890, 800, 0, 180, 0, fridge3, 0.5, 0.5, 0.5);
    electronic.drawFridge(2400, 890, 800, 0, 180, 0, fridge2, 144, 147, 153);
    electronic.drawFridge(2700, 890, 800, 0, 180, 0, fridge, 0.5, 0.5, 0.5);
    electronic.drawFridge(3000, 890, 800, 0, 180, 0, fridge1, 0.2, 0.2, 0.2);
    electronic.drawFridge(3300, 890, 800, 0, 180, 0);
    electronic.drawFridge(3600, 890, 800, 0, 180, 0);
    electronic.drawFridge(3875, 890, 800, 0, 180, 0, fridge4, 0.2, 0.2, 0.2);
    electronic.drawFloorFan(900, 872, -1700, 0, 270, 0, fanRotation,0,0,0);
    electronic.drawFloorFan(900, 872, -1900, 0, 270, 0, fanRotation, 0.40, 0.13, 0.18);
    electronic.drawFloorFan(900, 872, -2100, 0, 270, 0, fanRotation, 0.30, 0.13, 0.5);
    electronic.drawFloorFan(900, 872, -2300, 0, 270, 0, fanRotation, 0.18, 0.13, 0.5);
    electronic.drawfireplace(900, 882, -2400, 0, 90, 0);
    electronic.drawfireplace(900, 962, -2400, 0, 90, 0);
    electronic.drawAirConditionerWithFan(900, 880, -2600, 0, 90, 0,fanRotation);
    electronic.drawAirConditioner(900, 940, -2600, 0, 90, 0);
    electronic.drawbrada(900, 880, -2850, 0, 270, 0, brada1, 0.9, 0.9, 0.9);
    electronic.drawbrada(1100, 880, -2850, 0, 0, 0, brada1, 0.9, 0.9, 0.9);
    electronic.drawbrada(1300, 880, -2850, 0, 0, 0, brada2, 0.9, 0.9, 0.9);
    electronic.drawbrada(1500, 880, -2850, 0, 0, 0, brada3, 0.8, 0.8, 0.85);
    electronic.drawbrada(1700, 880, -2850, 0, 0, 0, s7ana, 0.2, 0.2, 0.2);
    electronic.drawbrada(1900, 880, -2850, 0, 0, 0, s7ana, 0.2, 0.2, 0.2);
    electronic.drawbrada(2100, 880, -2850, 0, 0, 0, s7ana, 0.2, 0.2, 0.2);
    electronic.drawbrada(2300, 880, -2850, 0, 0, 0, s7ana, 0.2, 0.2, 0.2);
    electronic.drawbrada(2500, 880, -2850, 0, 0, 0, brada1, 0.9, 0.9, 0.9);
    electronic.drawbrada(2700, 880, -2850, 0, 0, 0, brada2, 0.9, 0.9, 0.9);
    electronic.drawbrada(2900, 880, -2850, 0, 0, 0, brada3, 0.8, 0.8, 0.85);
    electronic.drawFloorFan(3100, 872, -2850, 0, 0, 0, fanRotation, 0, 0, 0);
    electronic.drawFloorFan(3300, 872, -2850, 0, 0, 0, fanRotation, 0.40, 0.13, 0.18);
    electronic.drawFloorFan(3500, 872, -2850, 0, 0, 0, fanRotation, 0.30, 0.13, 0.5);
    electronic.drawFloorFan(3700, 872, -2850, 0, 0, 0, fanRotation, 0.18, 0.13, 0.5);
    electronic.drawFloorFan(3900, 872, -2850, 0, 0, 0, fanRotation, 0.18, 0.13, 0.5);
    electronic.drawCeilingFanWithArm(2500, 1400, -1000, 0, 0, 0, fanRotation);

}
