#include "abd.h"

void Abd::init()
{
    xboxb = LoadTexture((char*)"images\\xboxb.bmp", 255.0f);
   xboxf = LoadTexture((char*)"images\\xboxf.bmp", 255.0f);
   wash = LoadTexture((char*)"images\\wash.bmp", 255);
   washw = LoadTexture((char*)"images\\washw.bmp", 255);
   washb= LoadTexture((char*)"images\\washb.bmp", 255);
   washr = LoadTexture((char*)"images\\washr.bmp", 255);
   wash2= LoadTexture((char*)"images\\wash2.bmp", 255);
   speaker = LoadTexture((char*)"images\\speaker.bmp", 255);
   pcf = LoadTexture((char*)"images\\pcf.bmp", 255);
   pcb = LoadTexture((char*)"images\\pcb.bmp", 255);
   pcs = LoadTexture((char*)"images\\pcs.bmp", 255);
   fridge = LoadTexture((char*)"images\\fridge1.bmp", 255);
   fridge1= LoadTexture((char*)"images\\fridge.bmp", 255); 
   fridge2 = LoadTexture((char*)"images\\fridge2.bmp", 255);
   fridge3 = LoadTexture((char*)"images\\fridge3.bmp", 255);
   fridge4 = LoadTexture((char*)"images\\fridge4.bmp", 255);
   aircondition= LoadTexture((char*)"images\\aircondition.bmp", 255);
   airconditionfan = LoadTexture((char*)"images\\airconditionfan.bmp", 255);
   brada1 = LoadTexture((char*)"images\\brada1.bmp", 255);
   brada2 = LoadTexture((char*)"images\\brada2.bmp", 255);
   brada3 = LoadTexture((char*)"images\\brada3.bmp", 255);
   brada4 = LoadTexture((char*)"images\\brada4.bmp", 255);
   s7ana = LoadTexture((char*)"images\\s7ana.bmp", 255);
   games = LoadTexture((char*)"images\\games.bmp", 255);
   game1 = LoadTexture((char*)"images\\game1.bmp", 255);
   gameground = LoadTexture((char*)"images\\ardia.bmp", 255);
   gamingroof = LoadTexture((char*)"images\\gamingroof.bmp", 255);
   cod = LoadTexture((char*)"images\\cod.bmp", 255);
   gta = LoadTexture((char*)"images\\gta.bmp", 255);
   d3asa = LoadTexture((char*)"images\\d3asa.bmp", 255);
   sky = LoadTexture((char*)"images\\sky.bmp", 255);

}

//void Abd::AbdDraw(float CameraX,float CameraY,float CameraZ)
//{
//
//    cameraX= CameraX, cameraZ= CameraZ, cameraY = CameraY;
//    fanRotation += 10.0f;
//    if (fanRotation >= 360.0f) {
//        fanRotation = 0.0f; 
//    }
//
//   game1 = LoadTexture((char*)"images\\game1.bmp", 255);
//   gameground = LoadTexture((char*)"images\\ardia.bmp", 255);
//   gamingroof= LoadTexture((char*)"images\\gamingroof.bmp", 255);
//   cod= LoadTexture((char*)"images\\cod.bmp", 255);
//   gta = LoadTexture((char*)"images\\gta.bmp", 255);
//   d3asa = LoadTexture((char*)"images\\d3asa.bmp", 255);
//   sky = LoadTexture((char*)"images\\sky.bmp", 255);
//}
void Abd::drawRotatingGlassDoor(float centerX, float centerY, float centerZ,
    float height, float width, float angle) {
  
    glPushMatrix();

    
    glTranslatef(centerX, centerY, centerZ);

   
    glRotatef(angle, 0.0f, 1.0f, 0.0f);

  
    float halfHeight = height / 2.0f;
    float halfWidth = width / 2.0f;
    


   glass.drawfrontWall(-halfWidth, halfWidth, -halfHeight, halfHeight, centerZ,  0.5f);

  
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);

    
    glass.drawfrontWall(-halfWidth, halfWidth, -halfHeight, halfHeight, centerZ, 0.5f);


    glPopMatrix();
}

void Abd::secondwalls()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, game1);

    glBegin(GL_QUADS);
    float x = 800, y = 880, z = 1010, width = 3190, hight = 800;
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x, y, z);
    glTexCoord2f(5, 0.0f);
    glVertex3f(x + width, y, z);
    glTexCoord2f(5, 5);
    glVertex3f(x + width, y + hight, z);
    glTexCoord2f(0.0f, 5);
    glVertex3f(x, y + hight, z);
    glTexCoord2f(0.0f, 0.0f);
    float depth = 3900;
    glVertex3f(x, y, z + depth);
    glTexCoord2f(5, 0.0f);
    glVertex3f(x + width, y, z + depth);
    glTexCoord2f(5, 5);
    glVertex3f(x + width, y + hight, z + depth);
    glTexCoord2f(0.0f, 5);
    glVertex3f(x, y + hight, z + depth);
    //
    glRotatef(180, 0, 1, 0);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x + width - 10, y, z);
    glTexCoord2f(5, 0.0f);
    glVertex3f(x + width - 10, y, z + depth - 5);
    glTexCoord2f(5, 5);
    glVertex3f(x + width - 10, y + hight, z + depth - 5);
    glTexCoord2f(0.0f, 5);
    glVertex3f(x + width - 10, y + hight, z);
    glTexCoord2f(0.0f, 0.0f);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, cod);

    glBegin(GL_QUADS);
    depth = depth / 3 + 200;
    glTexCoord2f(0, 0.0f);
    glVertex3f(x, y, z);
    glTexCoord2f(1, 0.0f);
    glVertex3f(x, y, z + depth);
    glTexCoord2f(1, 1.0f);
    glVertex3f(x, y + hight, z + depth);
    glTexCoord2f(0, 1.0f);
    glVertex3f(x, y + hight, z);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, gta);

    glBegin(GL_QUADS);

    glTexCoord2f(0, 0.0f);
    glVertex3f(x, y, z + depth + 900);
    glTexCoord2f(1, 0.0f);
    glVertex3f(x, y, z + 2 * depth + 900);
    glTexCoord2f(1, 1.0f);
    glVertex3f(x, y + hight, z + 2 * depth + 900);
    glTexCoord2f(0, 1.0f);
    glVertex3f(x, y + hight, z + depth + 900);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}
void drawText(const char* text) {
    // ÖÈØ Çááæä
   

    // ÇÈÏÃ ÇáäÕ
    glPushMatrix();
    while (*text) {
        if (*text == 'J') {
            glColor3f(1.0f, 0, 0);  
        }
        else if (*text == 'B') {
            glColor3f(0.0f, 1, 0);  
        }
        else if (*text == 'N') {
            glColor3f(0.0f, 0, 1);  
        }
        else if (*text == 'T') {
            glColor3f(1.0f, 0.7, 0);  // áæä ÇáäÕ 
        }
        else {
            glColor3f(0.0f, 1, 1);  // áæä ÇáäÕ ÃÈíÖ
        }
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *text);
       
        glTranslatef(25, 0.0f, 0.0f);
        text++;
    }
    glPopMatrix();
}

void drawJBNAT(float x, float y, float z, float scale,  float rotationY) {

    for (float Z = z; Z > z - 200;Z-=1) {
        glPushMatrix();

    
    glTranslatef(x, y, Z);

    
    glRotatef(rotationY, 0,1,0);


    glScalef(scale, scale, scale);

    
    drawText("JBNAT");

    glPopMatrix();
}
}

void drawsky(float cameraX, float cameraY, float CameraZ,int sky) {
    glPushMatrix();

    glEnable(GL_TEXTURE_2D);
    glColor3f(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, sky);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3f(cameraX - 30000, cameraY + 9000, CameraZ - 30000);
    glTexCoord2f(1, 0);
    glVertex3f(cameraX + 30000, cameraY + 9000, CameraZ - 30000);
    glTexCoord2f(1, 1);
    glVertex3f(cameraX + 30000, cameraY + 9000, CameraZ + 30000);
    glTexCoord2f(0, 1);
    glVertex3f(cameraX - 30000, cameraY + 9000, CameraZ + 30000);
    glEnd();

    glDisable(GL_TEXTURE_2D);

    glPopMatrix();

}
void Abd::AbdDraw(float CameraX,float CameraY,float CameraZ){

    cameraX= CameraX, cameraZ= CameraZ, cameraY = CameraY;
    fanRotation += 10.0f;
    doorrotation += 1;
    if (fanRotation >= 360.0f) {
        fanRotation = 0.0f; 
    }
    if (doorrotation >= 360)
        doorrotation = 0;

    drawRotatingGlassDoor(-400, 500, 100, 750, 800,doorrotation);
   // drawsky(cameraX, CameraY, CameraZ, sky);
  
    

    


    for (auto& door : doors) {
        door.updateState(cameraX,cameraY, cameraZ);
        door.draw();
    }
    first();
    second();

    drawJBNAT(100, 1800, 600, 7, 270);
   
}
void  Abd::first() {

    glLineWidth(1);
    electronic.drawFridge(900, 890, 200, 0, 270, 0);
    electronic.drawFridge(900, 890, -300, 0, 270, 0, fridge1, 0.2, 0.2, 0.2);
    electronic.drawFridge(900, 890, -50, 0, 270, 0);
    electronic.drawWashingMachine(900, 890, 400, 0, 270, 0, wash, 0.1, 0.1, 0.1);
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
    electronic.drawFloorFan(900, 872, -1700, 0, 270, 0, fanRotation, 0, 0, 0);
    electronic.drawFloorFan(900, 872, -1900, 0, 270, 0, fanRotation, 0.40, 0.13, 0.18);
    electronic.drawFloorFan(900, 872, -2100, 0, 270, 0, fanRotation, 0.30, 0.13, 0.5);
    electronic.drawFloorFan(900, 872, -2300, 0, 270, 0, fanRotation, 0.18, 0.13, 0.5);
    electronic.drawfireplace(900, 882, -2400, 0, 90, 0);
    electronic.drawfireplace(900, 962, -2400, 0, 90, 0);
    electronic.drawAirConditionerWithFan(900, 880, -2600, 0, 90, 0, fanRotation);
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

void Abd::second()
{
   
    drawtable(1200, 885, 1015, 0);
    drawtable(1950, 885, 1015, 0);
    drawtable(2600, 885, 1015, 0);
    drawtable(3300, 885, 1015, 0);
    drawtable(1800, 885, 4900, 180);
    drawtable(2550, 885, 4900, 180);
    drawtable(3200, 885, 4900, 180);
    drawtable(3900, 885, 4900, 180);
    technical.drawScreen(3960, 1100, 3000, 0, 90, 0);
    technical.drawScreen(3960, 1100, 2200, 0, 90, 0);
    technical.drawScreen(3960, 1100, 4000, 0, 90, 0);
    wall.Roof(3800, 4000, 1000, 1500, 4000, 10, games, 2, 1);
    wall.Roof(800, 4000, 880, 940, 4990, 2, gameground, 5, 5);
    wall.Roof(800, 4000, 1680, 940, 4990, -2, gameground, 10, 10);
    technical.drawPS5(3900, 1010, 1700, 0, 90, 0);
    technical.drawPS5(3900, 1010, 2500, 0, 90, 0);
    technical.drawXbox(3900, 1010, 3500, 0, 90, 0, xboxf, xboxb);
    Abd::secondwalls();
  

}
void Abd::drawtable(float x,float y, float z,float rotate) {

    technical.drawGamingTable(600, 200, 250,x, y, z ,rotate);
    if (rotate == 180) {
        technical.drawComputerCase(x -550 , y + 252, z-100, 0, 270, 0, pcf, pcb, pcs);
        technical.drawComputerMonitor(x - 250, y + 257, z -50, 0, 0, 0);
        technical.drawKeyboard(x - 250, y + 260, z - 150, 0, 0, 0);
        technical.drawSpeakerFrame(x - 100, y + 295, z - 100, 0, 180, 0, speaker);
        technical.drawMouse(x - 400, y + 250, z - 150, 0, 0, 0);
        technical.drawGamingChair(x - 275, 1075, z  -300, 270);;
    }
    else {
        technical.drawComputerCase(x + 550, y + 252, z + 100, 0, 90, 0, pcf, pcb, pcs);
        technical.drawComputerMonitor(x + 250, y + 257, z+50 , 0, 180, 0);
        technical.drawKeyboard(x + 250, y + 260, z + 150, 0, 180, 0);
        technical.drawSpeakerFrame(x + 100, y + 295, z + 100, 0, 0, 0, speaker);
        technical.drawMouse(x + 400, y + 250, z + 150, 0, 180, 0);
        technical.drawGamingChair(x+275, 1075, z+300, 90);;
    }

}

