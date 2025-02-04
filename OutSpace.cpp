#include <GL/glut.h>  
#include "texture.h"
#include <iostream>
#include "OutSpace.h"
#include "Glass.h"
#include "Waterfall.h"
#include "Model_3DS.h"

 float M_PI =3.14;
 Model_3DS *car,*motor,*plant1, *pole, *smalplant1,*jeep,*pop,*man,*arch;


//Model_3DS *motor,
//
//Model_3DS *plant1;
//Model_3DS *pole;
//Model_3DS *smalplant1;

  void OutSpace::drawFlag(float x1, float y1, float z1, float len, float hig) {
     glPushMatrix();
     glTranslatef(x1, y1, z1);

     glEnable(GL_TEXTURE_2D);
     glBindTexture(GL_TEXTURE_2D, flagTex);
     glColor3f(1.0f, 1.0f, 1.0f);

     int gridSize = 20; 
     float stepX = len / gridSize;  
     float stepY = hig / gridSize;  

     float waveTime = glutGet(GLUT_ELAPSED_TIME) * 0.007f;  
     float frequency = 0.02f;   
     float amplitude = 20;   

     glBegin(GL_QUADS);
     for (int i = 0; i < gridSize; i++) {
         for (int j = 0; j < gridSize; j++) {
              float x1 = i * stepX;
             float y1 = j * stepY;
             float x2 = x1 + stepX;
             float y2 = y1 + stepY;

              float z1 = amplitude * sin(frequency * (x1 + y1) + waveTime);
             float z2 = amplitude * sin(frequency * (x2 + y1) + waveTime);
             float z3 = amplitude * sin(frequency * (x2 + y2) + waveTime);
             float z4 = amplitude * sin(frequency * (x1 + y2) + waveTime);

              glTexCoord2f((float)i / gridSize, (float)j / gridSize);
             glVertex3f(x1, y1, z1);  

             glTexCoord2f((float)(i + 1) / gridSize, (float)j / gridSize);
             glVertex3f(x2, y1, z2);  

             glTexCoord2f((float)(i + 1) / gridSize, (float)(j + 1) / gridSize);
             glVertex3f(x2, y2, z3);  

             glTexCoord2f((float)i / gridSize, (float)(j + 1) / gridSize);
             glVertex3f(x1, y2, z4);  
         }
     }
     glEnd();

     glDisable(GL_TEXTURE_2D);
     glPopMatrix();
 }

void  OutSpace::drawConicalStick(float centerx, float centery, float centerz,float baseRadius, float topRadius, float height,float len,float wid) {
     GLUquadricObj* quadric = gluNewQuadric();
    glPushMatrix();
    glTranslatef(centerx, centery, centerz); 
     glRotatef(-90, 1.0f, 0.0f, 0.0f);  
    glColor3f(1, 0.55, .2);
    gluCylinder(quadric, baseRadius, topRadius, height, 32, 50);  
    gluDeleteQuadric(quadric);  
    glPopMatrix();

    //
    glPushMatrix();
    glTranslatef(centerx, centery, centerz);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, himilayan);
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_TRIANGLE_FAN);

     glTexCoord2f(0.5f, 0.5f);
    glVertex3f(0.0f, 0.0f, 0.0f);
     
    glTexCoord2f(0.25f, 1.0f);  
    glVertex3f(-(3 * len) / 4, 0.0f, wid);

    glTexCoord2f(0.75f, 1.0f);  
    glVertex3f((3 * len) / 4, 0.0f, wid);

    glTexCoord2f(1.0f, 0.75f);  
    glVertex3f(len, 0.0f, (3 * wid) / 4);

    glTexCoord2f(1.0f, 0.25f);  
    glVertex3f(len, 0.0f, -(3 * wid) / 4);

    glTexCoord2f(0.75f, 0.0f);  
    glVertex3f((3 * len) / 4, 0.0f, -wid);

    glTexCoord2f(0.25f, 0.0f);  
    glVertex3f(-(3 * len) / 4, 0.0f, -wid);

    glTexCoord2f(0.0f, 0.25f);  
    glVertex3f(-len, 0.0f, -(3 * wid) / 4);

    glTexCoord2f(0.0f, 0.75f);  
    glVertex3f(-len, 0.0f, (3 * wid) / 4);

    glTexCoord2f(0.25f, 1.0f); 
    glVertex3f(-(3 * len) / 4, 0.0f, wid);

    glEnd();
    glDisable(GL_TEXTURE_2D);
    //
    for (float i = 0; i < 4; i++)
    {   
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, himilayan);
        glColor3f(1.0f, 1.0f, 1.0f);

        glBegin(GL_TRIANGLES);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-len, 0.0f, (3 * wid) / 4);
        glTexCoord2f(1, 0.0f);
        glVertex3f(-len - 75, -100, wid + 75);
        glTexCoord2f(0.5, 1);
        glVertex3f(-(3 * len) / 4, 0.0f, wid);
        glEnd();


        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 1.0f); 
        glVertex3f(-(3 * len) / 4, 0.0f, wid);
        glTexCoord2f(0.0f, 0.0f); 
        glVertex3f(-len - 75, -100, wid + 75);
        glTexCoord2f(1.0f, 0.0f);  
        glVertex3f(len + 75, -100, wid + 75);
        glTexCoord2f(1.0f, 1.0f);  
        glVertex3f((3 * len) / 4, 0.0f, wid);
        glEnd();
        ////// lines
        glColor3f(0, 0, 0);
        glLineWidth(5);
        glBegin(GL_LINE_STRIP);
        glVertex3f(-len - 75, -100, wid + 75);
        glVertex3f(-(3 * len) / 4, 0.0f, wid);
        glVertex3f(-len, 0.0f, (3 * wid) / 4);
        glVertex3f(-len - 75, -100, wid + 75);
        glVertex3f(len + 75, -100, wid + 75);
        glVertex3f((3 * len) / 4, 0.0f, wid);
        glVertex3f(-(3 * len) / 4, 0.0f, wid);
        glEnd();
    glDisable(GL_TEXTURE_2D);
    ///////////////
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, fatainTex2);
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glTexCoord2f(0,1 );
    glVertex3f(-len - 75, -100, wid + 75);
    glTexCoord2f(0.0f, 0);
    glVertex3f(-len - 75, -150, wid + 75);
    glTexCoord2f(3, 1.0f);
    glVertex3f(len + 75, -150, wid + 75);
    glTexCoord2f(3, 0);
    glVertex3f(len + 75, -100, wid + 75);
    glEnd();
    glDisable(GL_TEXTURE_2D);

        glRotatef(90, 0, 1, 0);
    }

    
    glPopMatrix();

}

void OutSpace:: drawStreet(float x1,float x2,float y,float z1,float z2) {
     
    glColor3f(0.3f, 0.3f, 0.3f);  
    glBegin(GL_QUADS);
    glVertex3f(x1, y, z1); 
    glVertex3f(x2, y, z1); 
    glVertex3f(x2, y, z2); 
    glVertex3f(x1, y, z2); 
    glEnd();

    // Draw lane dividers
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow for lane dividers
    for (float i = z1; i >= z2-200; i -= 200) {
        glBegin(GL_QUADS);
        glVertex3f(x1+10, y+5, i);  // Bottom-left
        glVertex3f(x1 + 50, y + 5, i);
        glVertex3f(x1 + 50, y + 5, i-150); 
        glVertex3f(x1 + 10, y + 5, i-150); 
      //
        glVertex3f(x2 -60 , y + 5, i);  // Bottom-left
        glVertex3f(x2 - 10, y + 5, i);
        glVertex3f(x2 -10, y + 5, i - 150);
        glVertex3f(x2 -60, y + 5, i - 150);

        glEnd();
    }

}

void OutSpace::drawParking(float x, float y, float z) { 
    float width = 1300;
    int x1 = 0;
    float len = 9000;
     glPushMatrix();
    glTranslatef(x,y,z);

    for (float i = 0; i < 29; i++)
    {
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_QUADS);
      
    glVertex3f(x1, 0,width);
    glVertex3f(x1+10, 0,width );
    glVertex3f(x1+10, 0,-width );
    glVertex3f(x1, 0,-width);
        glEnd();
    glColor3f(1, 1, 1);
    
    x1 += 10;
   
        width -= (30 - i);

    }
    glColor3f(0.3f, 0.3f, 0.3f);

    glBegin(GL_QUADS);
    glVertex3f(x1, 0, width);
    glVertex3f(x1+len, 0, width);
    glVertex3f(x1+len, 0, -width);
    glVertex3f(x1, 0, -width);
     glEnd();


     for (float i = x1; i < len-100; i+=300)
     {
         glBegin(GL_QUADS);
         glColor3ub(255,255,255);
         glVertex3f(i, 5, 300);
         glVertex3f(i+300, 5, width);
         glVertex3f(i+350, 5, width);
         glVertex3f(i+50, 5, 300);
         //
          
         glVertex3f(i, 5, -300);
         glVertex3f(i + 300, 5, -width);
         glVertex3f(i + 350, 5, -width);
         glVertex3f(i + 50, 5, -300);

         glEnd();
     }
    glPopMatrix();
     sidewalkX(x+x1,2,z-width,len,150);
     sidewalkX(x+x1,2,z+width,len,150);

     glPushMatrix();
     glTranslatef(x+1550,y-20,z-6400);
     glRotatef(90,0,1,0);
     sidewalkX(x + x1, 2, z , width*2, 150);

     glPopMatrix();
    
}
 
  

void OutSpace::drawBigTree(float x, float y, float z, float h,  float scale) {
   
    float width = 400;
    glColor3f(1, 1, 1);
    for (float i = 0; i <= 360; i += 30) {
        glPushMatrix();  

        glTranslatef(x, y, z);  
        glRotatef(i, 0, 1, 0);  
        glScalef(scale, scale, scale);
        glColor3f(0.1, 0.7, 0.1);  
        glBegin(GL_POLYGON);

         glVertex3f(-width/2, h/4, 0);    
        glVertex3f(width/2, h/4, 0);     
        glVertex3f(0, h/2, 0);
        glVertex3f(-width / 4, h/2, 0);
        glEnd();
        //
        glBegin(GL_TRIANGLES);
        glVertex3f(-width / 3, h/2, 0);
        glVertex3f(width / 3, h/2, 0);
        glVertex3f(0, h , 0);
        glEnd();
       
        //
        glBegin(GL_LINES);
        glLineWidth(5);
        glColor3f(0,0,0);
        glVertex3f(-width/2, h/4, 0);    
        glVertex3f(-width/4, h/2, 0);
        glVertex3f(-width / 3, h / 2, 0);
        glVertex3f(0, h, 0);
 
        glEnd();
 
        glPopMatrix(); 
    }
        glLineWidth(10);
    for (float i = 0; i <= 360; i += 1) {
        glPushMatrix();

        glTranslatef(x, y, z);
        glRotatef(i, 0, 1, 0);
        glScalef(scale, scale, scale);
        glColor3f(0.5, 0.3, 0.1);
        glBegin(GL_LINES);
        glVertex3f(-15, 0, 0);
        glVertex3f(-3, h / 4, 0);
        glEnd();
        glPopMatrix();
    }
        glLineWidth(1);

}


void OutSpace::sidewalkX(float x1, float y1, float z1, float len,float wid) {
    int h = 80;
    glPushMatrix();
    glTranslatef(x1,y1,z1);
    glColor3f(0.87f, 0.72f, 0.53f);
    glBegin(GL_QUADS);
    // r
    glVertex3f(0, 0, wid/2);
    glVertex3f(len, 0, wid/2);
    glVertex3f(len, h,wid/2);
    glVertex3f(0, h, wid/2);
// t
    glVertex3f(0, h, wid / 2);
    glVertex3f(len, h, wid / 2);
    glVertex3f(len, h, -wid / 2);
    glVertex3f(0, h, -wid/2);
    //l
    glVertex3f(0, 0, -wid / 2);
    glVertex3f(len, 0, -wid / 2);
    glVertex3f(len, h, -wid / 2);
    glVertex3f(0, h, -wid/2);
    // f
    glVertex3f(0, 0, -wid / 2);
    glVertex3f(0, 0, wid / 2);
    glVertex3f(0, h, wid / 2);
    glVertex3f(0, h, -wid/2);
    // b
     // f
    glVertex3f(len, 0, -wid / 2);
    glVertex3f(len, 0, wid / 2);
    glVertex3f(len, h, wid / 2);
    glVertex3f(len, h, -wid / 2);

    glEnd();

    for (float i = 0; i < len-25; i+=50)
    {
    glLineWidth(1);
        glPushMatrix();
        glColor3f(0,0,0);
        glScalef(1,1.04,1.04);
        glBegin(GL_LINES);
        glVertex3f(i, 0, wid/2);
        glVertex3f(i, h, wid / 2);
        //
        glVertex3f(i, h, wid / 2);
        glVertex3f(i, h, -wid / 2);
        //
        glVertex3f(i, h, -wid / 2);
        glVertex3f(i, 0, -wid / 2);
        glEnd();
        glPopMatrix();

    }
    glPopMatrix();

}

void OutSpace::drawMianCircle(float centerx, float centery, float centerz, float rd, float red, float green, float blue) {

    glPushMatrix();
    glTranslatef(centerx,centery,centerz);
    float step = 3.14f / 50;
    for (float angle = -3.14f; angle <= 3.14f; angle += step) {
    glColor3ub(red,green,blue);   

    glBegin(GL_TRIANGLES);
        float x1 = cos(angle) * rd;
        float z1 = sin(angle) * rd;

        float x2 = cos(angle + step) * rd;
        float z2 = sin(angle + step) * rd;

        glVertex3f(0, 0, 0);
        glVertex3f(x1, 0, z1);
        glVertex3f(x2, 0, z2);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex3f(x1, 0, z1);
    glVertex3f(x2, 0, z2);
 
    glEnd();

    }

    glPopMatrix();
    
}


void OutSpace::drawFlower(float x, float y, float z,float petalRadius, float centerRadius, int petalCount) {
    // Draw petals
    for (int i = 0; i < 360; i += 360 / petalCount) {
        float angle = i * (M_PI / 180.0f); // Convert degrees to radians
        float petalX = x + (centerRadius + petalRadius / 2) * cos(angle);
        float petalZ = z + (centerRadius + petalRadius / 2) * sin(angle);
        drawMianCircle(petalX,y+80, petalZ, petalRadius, 255, 0, 0);  
    }

     
    drawMianCircle(x,y+81,z, centerRadius, 255, 240, 0);  
    glPushMatrix();
    glTranslatef(x, y, z);
    glBegin(GL_LINES);
    glLineWidth(50);
    glColor3ub(50,150,20);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 80, 0);

    glEnd();
    glPopMatrix();
}

void  OutSpace::drawWater(float centerx, float centery, float centerz, float width, float length, int gridSize) {
    glPushMatrix();
    glTranslatef(centerx,centery,centerz);
    
    float stepX = width / gridSize;  
    float stepZ = length / gridSize;  
    float waveTime = glutGet(GLUT_ELAPSED_TIME) * 0.005; // Time for wave animation
    float frequency = 0.01;  // Wave frequency
    float amplitude = 18; 
     glColor4f(0.5f, 0.9f, 1.0f, 0.8);  
     glEnable(GL_BLEND);
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            // Calculate the positions of the four vertices of each quad
            float x1 = -width / 2 + i * stepX;
            float z1 = -length / 2 + j * stepZ;
            float x2 = x1 + stepX;
            float z2 = z1 + stepZ;

            // Calculate dynamic wave heights using sine functions
            float y1 = amplitude * sin(frequency * (x1 + z1) + waveTime);
            float y2 = amplitude * sin(frequency * (x2 + z1) + waveTime);
            float y3 = amplitude * sin(frequency * (x2 + z2) + waveTime);
            float y4 = amplitude * sin(frequency * (x1 + z2) + waveTime);

            // Draw a quad for the water surface
            glBegin(GL_QUADS);
            glVertex3f(x1, y1, z1); // Bottom-left
            glVertex3f(x2, y2, z1); // Bottom-right
            glVertex3f(x2, y3, z2); // Top-right
            glVertex3f(x1, y4, z2); // Top-left
            glEnd();
        }
    }
        glDisable(GL_BLEND);
        glPopMatrix();
}

void OutSpace::drawFantain(float cornerx, float cornery, float cornerz, float len, float wid, float hig) {
    int repX = 10;
    int repY = 1;
    int repXflower = 8;
    int repYflower = 2;
    glDisable(GL_BLEND);

    glPushMatrix();
    glTranslatef(cornerx, cornery, cornerz);

    glPushMatrix();
    for (int i = 1; i < 5; i++) {
        // Base texture
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, fatainTex1);
        glColor3f(1.0f, 1.0f, 1.0f);  
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3d(0, 0, 0);
        glTexCoord2f(repX, 0.0f);
        glVertex3d(len, 0, 0);
        glTexCoord2f(repX, repY);
        glVertex3d(len, hig, 0);
        glTexCoord2f(0.0f, repY);
        glVertex3d(0, hig, 0);

        glTexCoord2f(0.0f, 0.0f);
        glVertex3d(0, hig, 0);
        glTexCoord2f(repX, 0.0f);
        glVertex3d(len, hig, 0);
        glTexCoord2f(repX, repY);
        glVertex3d((7 * len) / 8, hig, -wid / 8);
        glTexCoord2f(0.0f, repY);
        glVertex3d(len / 8, hig, -wid / 8);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Additional texture
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, fatainTex2);
        glColor3f(1.0f, 1.0f, 1.0f); // Set color to white
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3d(len / 8, hig, -wid / 8);
        glTexCoord2f(repX, 0.0f);
        glVertex3d((7 * len) / 8, hig, -wid / 8);
        glTexCoord2f(repX, repY);
        glVertex3d((7 * len) / 8, 0, -wid / 8);
        glTexCoord2f(0.0f, repY);
        glVertex3d(len / 8, 0, -wid / 8);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Flower texture
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, flowerTex);
        glColor3f(1.0f, 1.0f, 1.0f); // Set color to white
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3d(len / 4, hig-50, -wid / 8);
        glTexCoord2f(repXflower, 0.0f);
        glVertex3d((3 * len) / 4, hig-50, -wid / 8);
        glTexCoord2f(repXflower, repYflower);
        glVertex3d((3 * len) / 4, hig-50, -wid / 4);
        glTexCoord2f(0.0f, repYflower);
        glVertex3d(len / 4, hig-50, -wid / 4);
        glEnd();
        glDisable(GL_TEXTURE_2D);


        //
        // white stone
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, flowerLand);
        glColor3f(1.0f, 1.0f, 1.0f);  
        glBegin(GL_TRIANGLES);
        glTexCoord2f(0, 3);
        glVertex3d(len / 8, 12, 0);
        glTexCoord2f(2, 0.0f);
        glVertex3d(len/2, 12, wid/4);
        glTexCoord2f(5, 3);
        glVertex3d((7 * len) / 8, 12, 0);
         
        glEnd();
        glDisable(GL_TEXTURE_2D);
        // black wall
         glColor3f(0, 0, 0);  

         glBegin(GL_QUADS);
         glVertex3d(len / 4, hig -50, -wid / 8);
         glVertex3d(len / 4, 0, -wid / 8);
         glVertex3d(len / 4, 0, -wid / 4);
         glVertex3d(len / 4, hig-50, -wid / 4);
       //
         glVertex3d((3 * len) / 4, hig - 50, -wid / 8);
         glVertex3d((3 * len) / 4, 0, -wid / 8);
         glVertex3d((3 * len) / 4, 0, -wid / 4);
         glVertex3d((3 * len) / 4, hig - 50, -wid / 4);
          
         glEnd();


         drawWater((3*len)/16, hig - 70, -(3 * wid) / 16, len/8, wid/8, 5);

         drawShrubTree(len/2, 0.0f, wid/8, 200, 10, 150, 1);


      glTranslatef(len, 0, 0);
      glRotatef(90, 0, 1, 0);
    }
    glPopMatrix();

    // Draw big water
    //drawWater(len / 2, hig-50, -wid / 2, len / 2, wid / 2, 50);
    

    glPopMatrix();
}

void OutSpace::drawSmallFantain(float cornerx, float cornery, float cornerz, float len, float wid, float hig) {
    int repX = 4;
    int repY = 1;
    int repXflower = 1;
    int repYflower =1;
    glDisable(GL_BLEND);

    glPushMatrix();
    glTranslatef(cornerx, cornery, cornerz);

    glPushMatrix();
    for (int i = 1; i < 5; i++) {
        // Base texture
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, fatainTex1);
        glColor3f(1.0f, 1.0f, 1.0f); 
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3d(0, 0, 0);
        glTexCoord2f(repX, 0.0f);
        glVertex3d(len, 0, 0);
        glTexCoord2f(repX, repY);
        glVertex3d(len, hig, 0);
        glTexCoord2f(0.0f, repY);
        glVertex3d(0, hig, 0);

        glTexCoord2f(0.0f, 0.0f);
        glVertex3d(0, hig, 0);
        glTexCoord2f(repX, 0.0f);
        glVertex3d(len, hig, 0);
        glTexCoord2f(repX, repY);
        glVertex3d((7 * len) / 8, hig, -wid / 8);
        glTexCoord2f(0.0f, repY);
        glVertex3d(len / 8, hig, -wid / 8);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Additional texture
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, fatainTex2);
        glColor3f(1.0f, 1.0f, 1.0f);  
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3d(len / 8, hig, -wid / 8);
        glTexCoord2f(repX, 0.0f);
        glVertex3d((7 * len) / 8, hig, -wid / 8);
        glTexCoord2f(repX, repY);
        glVertex3d((7 * len) / 8, 0, -wid / 8);
        glTexCoord2f(0.0f, repY);
        glVertex3d(len / 8, 0, -wid / 8);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // Flower texture
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, flower1Tex);
        glColor3f(1.0f, 1.0f, 1.0f);  
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3d(len / 8, hig - 50, -wid / 8);
        glTexCoord2f(repXflower, 0.0f);
        glVertex3d( len / 4, hig - 50, -wid / 8);
        glTexCoord2f(repXflower, repYflower);
        glVertex3d(len / 4, hig - 50, -wid / 4);
        glTexCoord2f(0.0f, repYflower);
        glVertex3d(len / 8, hig - 50, -wid / 4);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        // black wall
        glColor3f(0, 0, 0);  

        glBegin(GL_QUADS);
        glVertex3d(len / 4, hig - 50, -wid / 8);
        glVertex3d(len / 4, 0, -wid / 8);
        glVertex3d(len / 4, 0, -wid / 4);
        glVertex3d(len / 4, hig - 50, -wid / 4);
        //
        glVertex3d((3 * len) / 4, hig - 50, -wid / 8);
        glVertex3d((3 * len) / 4, 0, -wid / 8);
        glVertex3d((3 * len) / 4, 0, -wid / 4);
        glVertex3d((3 * len) / 4, hig - 50, -wid / 4);

        glEnd();
        drawWater(len/2, hig - 70, -(3 * wid) / 16, len / 2, wid / 8, 5);


        glTranslatef(len, 0, 0);
        glRotatef(90, 0, 1, 0);
    }
    glPopMatrix();

    // Draw big water
    //drawWater(len / 2, hig-50, -wid / 2, len / 2, wid / 2, 50);


    glPopMatrix();
}

void OutSpace::drawGrass(float x1, float x2, float y, float z1, float z2,float repx,float repy,int tex) {
    int repX = repx;
    int repY = repy;
    glPushMatrix();
    glTranslatef(x1,y,z1);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex);
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3d(0 , 0,0 );
    glTexCoord2f(repX, 0.0f);
    glVertex3d(x2-x1,0,0 );
    glTexCoord2f(repX, repY);
    glVertex3d( x2-x1,0,z2-z1);
    glTexCoord2f(0.0f, repY);
    glVertex3d(0,0,z2-z1 );

    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

}

void OutSpace::drawWalkway(float x, float y, float z,float len,float wid ,float repx, float repy) {
    int repX = repx;
    int repY = repy;
    glPushMatrix();
    glTranslatef(x, y, z);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, WalkwayTex);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3d(0, 0, 0);
    glTexCoord2f(repX, 0.0f);
    glVertex3d(len, 0, 0);
    glTexCoord2f(repX, repY);
    glVertex3d(len, 0, -wid);
    glTexCoord2f(0.0f, repY);
    glVertex3d(0, 0, -wid);

    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    drawSperatedGlass(x, y, z-wid, len, 0.7);
    drawSperatedGlass(x, y, z, len, 0.7);

}
 
void drawSperatedGlass(int x, int y, int z, float len, float alpha) {
    float hig =150;
    float oneWid = len/15-len/150;
    glDepthMask(GL_FALSE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glPushMatrix();
    glTranslatef(x, y, z);
    for (float i = 0; i < len; i += len/15)
    {
    glColor4f(0.6f, 0.7f, 1.0f, alpha);
        glBegin(GL_QUADS);

        glVertex3i(i, 0, 0);
        glVertex3i(i + oneWid, 0, 0);
        glVertex3i(i + oneWid, hig, 0);
        glVertex3i(i, hig, 0);
        glEnd();
        //
  glColor3ub(13, 90, 115);
  glLineWidth(10);
        glBegin(GL_LINES);
        glVertex3i(i, 0, 0);
        glVertex3i(i, hig, 0);
        glVertex3i(i+oneWid, 0, 0);
        glVertex3i(i+oneWid, hig, 0);
        glVertex3i(i, hig, 0);
        glVertex3i(i+oneWid, hig, 0);
        glEnd();
    }
    // full line
    glBegin(GL_LINES);
    glVertex3i(0, hig, 0);
    glVertex3i(len-50, hig, 0);
    glEnd();
    glPopMatrix();

    glDisable(GL_BLEND);
    glDepthMask(GL_TRUE);
}

void  OutSpace::drawGrassSquare(float x , float y ,float z ,float len,float wid) {
    int repX = 15;
    int repY = 15;

    glPushMatrix();
    glTranslatef(x, y, z);
        
    glEnable(GL_TEXTURE_2D);           
    glBindTexture(GL_TEXTURE_2D, grassSpaceTex);  
    glColor3f(1,1,1);
        glBegin(GL_QUADS);
        glTexCoord2f(repX , repY);
        glVertex3f(0, 0, 0);
        glTexCoord2f(0, repY);
        glVertex3f(-len, 0, 0);

        glTexCoord2f(0, 0.0f);
        glVertex3f(-len, 0, wid);

        glTexCoord2f(repX, 0.0f);
        glVertex3f(0, 0, wid);
        
        glEnd();
    glDisable(GL_TEXTURE_2D);
      

    glPopMatrix();
}
void OutSpace:: drawShrubTree(float centerX, float centerY, float centerZ, float radius, int segments, float height,float scale) {
    glPushMatrix();
    glTranslatef(centerX, centerY, centerZ);


     float width = 400;
     for (float i = 0; i <= 360; i += segments) {
         glPushMatrix();

         
         glRotatef(i, 0, 1, 0);
         glScalef(scale, scale, scale);
         glColor3ub(255, 85, 223);
         
         //
         glBegin(GL_TRIANGLES);
         glVertex3f(radius*0.1, 0,0);
         glVertex3f(radius,height,0);
         glVertex3f(radius*0.3, height, 0);
         glEnd();

         //
         glLineWidth(5);
         glBegin(GL_LINE_STRIP);
         glLineWidth(5);
         glColor3f(0, 0, 0);
         glVertex3f(radius * 0.1, 0, 0);
         glVertex3f(radius, height, 0);
         glVertex3f(radius * 0.3, height, 0);

         glEnd();

         glPopMatrix();
     }
     
    glPopMatrix();
}

void OutSpace::drawEnterance(float x, float y, float z, float len,float wid) {
    int repx = 2;
    int repY = 2;
    glPushMatrix();
    glTranslatef(x,y,z);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, enteranc);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glTexCoord2f(repx, repY);

    glVertex3f(0, 0, 0);
    glTexCoord2f(0, repY);

    glVertex3f(-len, 0, 0);
    glTexCoord2f(0, 0);

    glVertex3f(-len, 0, wid);
    glTexCoord2f(repx, 0);

    glVertex3f(0, 0, wid);


    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

void OutSpace::drawSquareTree(float centerX, float centerY, float centerZ, float wid, float height, float scale ) {
    glPushMatrix();
    glTranslatef(centerX, centerY, centerZ);
    for (float i = 0; i <= 360; i += 1) {
        glPushMatrix();


        glRotatef(i*0.5, 0, 1, 0);
        glScalef(scale, scale, scale);
        glColor3ub(25, 140, 0);

        //
        glBegin(GL_QUADS);
        glVertex3f(-wid+i*0.5, i * height / 1000, -wid+i * 0.5);
        glVertex3f(-wid+i * 0.5, i*height/1000, wid-i * 0.5);
        glVertex3f(wid-i * 0.5, i * height / 1000, wid-i * 0.5);
        glVertex3f(wid-i * 0.5, i * height / 1000, -wid+i * 0.5);
        glEnd();
        // points
        glPointSize(1);  
        glColor3f(0,0,0);
        glBegin(GL_POINTS);
        glVertex3f(-wid + i * 0.5, i * height / 1000, -wid + i * 0.5);
        glVertex3f(-wid + i * 0.5, i * height / 1000, wid - i * 0.5);
        glVertex3f(wid - i * 0.5, i * height / 1000, wid - i * 0.5);
        glVertex3f(wid - i * 0.5, i * height / 1000, -wid + i * 0.5);
        glEnd();
        //
       
        glPopMatrix();
    }
    glRotatef(180, 1, 0, 0);
    for (float i = 0; i <= 200; i += 1) {
        glPushMatrix();


        glRotatef(i * 0.5, 0, 1, 0);
        glScalef(scale, scale, scale);
        glColor3ub(25, 140, 0);

        //
        glBegin(GL_QUADS);
        glVertex3f(-wid + i * 0.5, i * height / 1000, -wid + i * 0.5);
        glVertex3f(-wid + i * 0.5, i * height / 1000, wid - i * 0.5);
        glVertex3f(wid - i * 0.5, i * height / 1000, wid - i * 0.5);
        glVertex3f(wid - i * 0.5, i * height / 1000, -wid + i * 0.5);
        glEnd();
        // points
        glPointSize(1);
        glColor3f(0, 0, 0);
        glBegin(GL_POINTS);
        glVertex3f(-wid + i * 0.5, i * height / 1000, -wid + i * 0.5);
        glVertex3f(-wid + i * 0.5, i * height / 1000, wid - i * 0.5);
        glVertex3f(wid - i * 0.5, i * height / 1000, wid - i * 0.5);
        glVertex3f(wid - i * 0.5, i * height / 1000, -wid + i * 0.5);
        glEnd();
        //

        glPopMatrix();
    }
    glPopMatrix();
}


void OutSpace::drawFence(float x, float y, float z, float len, float hig) {
    int repX = 1;  // Texture repetition in the horizontal direction
    int repY = 1;  // Texture repetition in the vertical direction
    int quantity = len / 40;
    glPushMatrix();
    glTranslatef(x, y, z);

    for (float i = 0; i < len; i += quantity) {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, fence);

        glColor3f(1.0f, 1.0f, 1.0f);  // Ensure the color doesn't affect texture rendering

        glBegin(GL_QUADS);

        // Bottom-left corner
        glTexCoord2f(0, 0);
        glVertex3f(0, 0, -i);

        // Top-left corner
        glTexCoord2f(0, repY);
        glVertex3f(0, hig, -i);

        // Top-right corner
        glTexCoord2f(repX, repY);
        glVertex3f(0, hig, -(i + quantity));

        // Bottom-right corner
        glTexCoord2f(repX, 0);
        glVertex3f(0, 0, -(i + quantity));

        glEnd();

        glDisable(GL_TEXTURE_2D);
    }

    glPopMatrix();
}

void OutSpace::drawskybox() {

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, skyrh);

        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_QUADS);
       glTexCoord2f(0, 0);
        glVertex3f(-6000, 0, 6000);
        glTexCoord2f(1, 0);
        glVertex3f(-6000, 0, -6000);
        glTexCoord2f(1, 1);
        glVertex3f(-6000, 4000, -6000);
       glTexCoord2f(0, 1);
        glVertex3f(-6000, 4000, 6000);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    

        // mid 
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, skymid);

        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_QUADS);
        glTexCoord2f(0, 0);
        glVertex3f(-6000, 0, -6000);
        glTexCoord2f(1, 0);
        glVertex3f(6000, 0, -6000);
        glTexCoord2f(1, 1);
        glVertex3f(6000, 4000, -6000);
        glTexCoord2f(0, 1);
        glVertex3f(-6000, 4000, -6000);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        //left
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, skyleft);

        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_QUADS);
        glTexCoord2f(0, 0);
        glVertex3f(6000, 0, -6000);
        glTexCoord2f(1, 0);
        glVertex3f(6000, 0, 6000);
        glTexCoord2f(1, 1);
        glVertex3f(6000, 4000, 6000);
        glTexCoord2f(0, 1);
        glVertex3f(6000, 4000, -6000);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        //le left
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, skyleftleft);

        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_QUADS);
        glTexCoord2f(1, 0);
        glVertex3f(-6000, 0, 6000);
        glTexCoord2f(0, 0);
        glVertex3f(6000, 0, 6000);
        glTexCoord2f(0, 1);
        glVertex3f(6000, 4000, 6000);
        glTexCoord2f(1, 1);
        glVertex3f(-6000, 4000, 6000);
        glEnd();
        glDisable(GL_TEXTURE_2D);
        // up 


        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, skyup);

        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_QUADS);
        glTexCoord2f(0, 0);
        glVertex3f(-6000, 4000, -6000);
        glTexCoord2f(1, 0);
        glVertex3f(6000, 4000, -6000);
        glTexCoord2f(1, 1);
        glVertex3f(6000, 4000, 6000);
        glTexCoord2f(0, 1);
        glVertex3f(-6000, 4000, 6000);
        glEnd();
        glDisable(GL_TEXTURE_2D);


 
}
void setMaterialProperties() {
    GLfloat matAmbient[] = { 0, 0, 0, 0 };  // Ambient reflection
    GLfloat matDiffuse[] = { 0, 0, 0, 0 };  // Diffuse reflection
    GLfloat matSpecular[] = { 0, 0, 0, 0 }; // Specular reflection
    GLfloat matShininess[] = { 50 };                 // Shininess factor

    glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
    glMaterialfv(GL_FRONT, GL_SHININESS, matShininess);
}

// Function to compute the shadow matrix
void generateShadowMatrix(GLfloat shadowMatrix[16], GLfloat groundPlane[4], GLfloat lightPos[4]) {
    GLfloat dot = groundPlane[0] * lightPos[0] +
        groundPlane[1] * lightPos[1] +
        groundPlane[2] * lightPos[2] +
        groundPlane[3] * lightPos[3];

    shadowMatrix[0] = dot - lightPos[0] * groundPlane[0];
    shadowMatrix[4] = 0.0f - lightPos[0] * groundPlane[1];
    shadowMatrix[8] = 0.0f - lightPos[0] * groundPlane[2];
    shadowMatrix[12] = 0.0f - lightPos[0] * groundPlane[3];

    shadowMatrix[1] = 0.0f - lightPos[1] * groundPlane[0];
    shadowMatrix[5] = dot - lightPos[1] * groundPlane[1];
    shadowMatrix[9] = 0.0f - lightPos[1] * groundPlane[2];
    shadowMatrix[13] = 0.0f - lightPos[1] * groundPlane[3];

    shadowMatrix[2] = 0.0f - lightPos[2] * groundPlane[0];
    shadowMatrix[6] = 0.0f - lightPos[2] * groundPlane[1];
    shadowMatrix[10] = dot - lightPos[2] * groundPlane[2];
    shadowMatrix[14] = 0.0f - lightPos[2] * groundPlane[3];

    shadowMatrix[3] = 0.0f - lightPos[3] * groundPlane[0];
    shadowMatrix[7] = 0.0f - lightPos[3] * groundPlane[1];
    shadowMatrix[11] = 0.0f - lightPos[3] * groundPlane[2];
    shadowMatrix[15] = dot - lightPos[3] * groundPlane[3];
}
void OutSpace::draw() {
    
    setMaterialProperties();
    for (float i = -3000; i < 0; i+=600)
    {
        drawBigTree(-7250, 0, i, 1300, 1.2);
    }
    for (float i = 2300; i < 6500; i += 600)
    {
        drawBigTree(-7250, 0, i, 1300, 1.2);
    }
 
    
     
    drawConicalStick(-4200,150,4200,50,20,3000,250,250);
    drawFlag(-4200,2500,4200,1000,600);
   
    drawFence(-7500,0,6500,5000,100);
    drawFence(-7500,0,300,5000,100);

   
   

}

void render3DModel(float x, float y, float z, float scale, Model_3DS* model, float rotationAngle,float r,float g,float b,bool rx,bool ry,bool rz) {
    if (!model) return;

    glPushMatrix();
    glColor3ub(255, 255, 255);
    glTranslatef(x, y, z);
    glRotatef(rotationAngle, rx, ry, rz);
    glScalef(scale, scale, scale);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
     
        glColor3ub(r,g,  b);
    model->Draw();
    glPopMatrix();
}

void OutSpace::drawshadow() {

    draw();
    GLfloat lightPosition[] = { -9000.0f, 4000, 6000.0f, 1.0f }; // Position of the "sun"
    GLfloat shadowMatrix[16];
    GLfloat groundPlanes[2][4] = {
           { 0.0f, 1.0f, 0.0f, -30 },   // Ground plane for floor 1
           { 0.0f, 1.0f, 0.0f, 890.0f }, // Ground plane for floor 2
    };

    generateShadowMatrix(shadowMatrix, groundPlanes[0], lightPosition);  // Compute shadow matrix

    // Disable lighting and material settings for the shadow
    glPushMatrix();
    glMultMatrixf(shadowMatrix);   

    //glDisable(GL_LIGHT0);
    //glDisable(GL_LIGHTING);
    //glDisable(GL_COLOR_MATERIAL);
    //glEnable(GL_BLEND);

     draw();  // Draw the shadow of the object (for the current object being rendered)

     glEnable(GL_LIGHT0);
     glEnable(GL_LIGHTING);
     glEnable(GL_COLOR_MATERIAL);
     glEnable(GL_BLEND);
    glPopMatrix();

    drawFantain(-5500, 0, 5500, 2600, 2600, 100);
    drawSmallFantain(-4850, 0, 4850, 1300, 1300, 100);

    drawStreet(-8500, -7500, 15, 9000, -6000);
    drawParking(-7500, 20, 7700);
    drawGrass(-7500, -7000, 10, 8000, 1500, 3, 200, grassTex);
    drawGrass(-7500, -7000, 10, 300, -6000, 3, 200, grassTex);
    drawGrass(-7000, -1500, 10, 300, 0, 15, 1, flowerLand);
    drawGrass(-300, 0, 10, 8000, 1500, 1, 15, flowerLand);
    //drawEntranceArch(0, 0, 0, 1000, 1000, 500);

    drawGrassSquare(-1500, 8, 1500, 5500, 6000);
    drawEnterance(0, 10, 0, 1500, 1500);
    drawEnterance(-7000, 10, 300, 500, 1200);

    drawSquareTree(-7250, 200, 150, 200, 2000, 0.6);
    drawSquareTree(-7250, 200, 1650, 200, 2000, 0.6);

    drawWalkway(-7000, 10, 1500, 5500, 1200, 10, 2);
    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    drawWalkway(-6750, 10, -300, 5250, 1200, 10, 2);
    glPopMatrix();

    drawSperatedGlass(-4000, 880, -20, 4000, 0.4);
    drawSperatedGlass(-4000, 880, -4000, 3000, 0.4);
    glPushMatrix();
    glTranslatef(-7900, 30, 2000);
    glRotatef(90,0,1,0);
    render3DModel(-0, 50, 0, 2, car, 90, 250, 0, 0, 1, 0, 0);
    render3DModel(-2000, 50, 0, 0.1, motor, -90, 100, 150, 130, 1, 0, 0);
    glPopMatrix();


    glPushMatrix();
    
    glRotatef(90, 1, 0, 0);
    render3DModel(-2000, 7350, -150, 0.2, jeep, 30, 70, 70, 90,0, 0, 1);
    render3DModel(-5000, 7350, -150, 0.2, jeep, 30, 70, 70, 90,0, 0, 1);
   
    glPopMatrix();
    render3DModel(-2000, 10, 1250, 0.2, man, 0, 220, 150, 30,0, 0, 0);
    render3DModel(-3000, 10, 1100, 0.2, man, 0, 220, 150, 30,0, 0, 0);
    render3DModel(-5000, 10, 700, 0.2, man, 180, 220, 150, 30, 0, 1, 0);
    
    render3DModel(-500, 100, 200, 6, pop, 90, 200, 180, 90, 1, 0, 0);
    render3DModel(-700, 100, 3000, 6, pop, 90, 200, 180, 90, 1, 0, 0);
    render3DModel(-1000, 100, 5500, 6, pop, 90, 200, 180, 90, 1, 0, 0);
    render3DModel(-800, 100, 1500, 6, pop, 90, 200, 180, 90, 1, 0, 0);

    for (float i = 2000; i < 6500; i+=700)
    {
        render3DModel(-150, 10, i, 5, plant1, 0, 0, 255, 50, 0, 0, 0);
        render3DModel(-1650, 10, i, 5, plant1, 0, 0, 255, 50, 0, 0, 0);
        render3DModel(-i, 10, 150, 5, plant1, 0, 0, 255, 50, 0, 0, 0);
        render3DModel(-i, 10, 1650, 5, plant1, 0, 0, 255, 50, 0, 0, 0);

    }
    for (float i = -6000; i < 7500; i += 1500)
    {
        
        render3DModel(-8050, 150, i, 3.5, pole, 90, 200, 200, 200, 0, 1, 0);
        render3DModel(-7970, 150, i, 3.5, pole, -90, 200, 200, 200, 0, 1, 0);
        
 
    }

    render3DModel(-8120, 0, 900, 68, arch, 0, 130, 140, 160, 0, 0, 0);

}


void OutSpace::init(){

    car = new Model_3DS();
    motor = new Model_3DS();
   plant1 = new Model_3DS();
    pole = new Model_3DS();
    smalplant1 = new Model_3DS();
    jeep = new Model_3DS();
    pop = new Model_3DS();
    man = new Model_3DS();
    arch = new Model_3DS();
 car->Load((char*)"model/car1.3ds");
 motor->Load((char*)"model/motor.3ds");
 plant1->Load((char*)"model/plant1.3ds");
 pole->Load((char*)"model/pole.3ds");
 smalplant1->Load((char*)"model/smallplanet1.3ds");
 jeep->Load((char*)"model/Jeep.3ds");
 pop->Load((char*)"model/BOB.3ds");
 man->Load((char*)"model/Man.3ds");
 arch->Load((char*)"model/arch.3ds");
    fatainTex1 = LoadTexture((char*)"images/fatain.bmp", 255.0f);
    fatainTex2 = LoadTexture((char*)"images/fatain1.bmp", 255.0f);
    grassTex = LoadTexture((char*)"images/grass.bmp", 255.0f);
    grassSpaceTex = LoadTexture((char*)"images/grassSpace.bmp", 255.0f);
    flowerTex = LoadTexture((char*)"images/flower.bmp", 255.0f);
    flower1Tex = LoadTexture((char*)"images/flower1.bmp", 255.0f);
    flagTex = LoadTexture((char*)"images/flag.bmp", 255.0f);
    WalkwayTex = LoadTexture((char*)"images/Walkway.bmp", 255.0f);
    whiteStone = LoadTexture((char*)"images/whiteStone.bmp", 255.0f);
    himilayan = LoadTexture((char*)"images/himalayan.bmp", 255.0f);
    enteranc = LoadTexture((char*)"images/enterance.bmp", 255.0f);
    flowerLand = LoadTexture((char*)"images/flowerlandspace.bmp", 255.0f);
    fence = LoadTexture((char*)"images/fence.bmp", 255.0f);

    skyrh = LoadTexture((char*)"images/skyrh.bmp", 255.0f);
    skymid = LoadTexture((char*)"images/skymid.bmp", 255.0f);
    skyleft = LoadTexture((char*)"images/skyleft.bmp", 255.0f);
    skyleftleft = LoadTexture((char*)"images/skyleftleft.bmp", 255.0f);
    skyup = LoadTexture((char*)"images/skyup.bmp", 255.0f);


    if (fatainTex1 < 0 || fatainTex2<0 || grassTex<0|| grassSpaceTex<0 || flowerTex<0 || flower1Tex<0 || flagTex<0 || WalkwayTex<0 || whiteStone<0) {
        std::cerr << "Failed to load texture." << std::endl;
        exit(1);
    }

}
