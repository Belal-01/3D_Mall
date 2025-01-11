#include "restorant.h"
#include "GL/glut.h"
#include "Wall.h"
#include "texture.h"
#include <cmath>

extern Wall wall;

void Resturant::resturantInit() {

    Resturant::woodWallTexture = LoadTexture((char*)"woodWallTexture.bmp", 255.0f);
    Resturant::kitchenWallTexture = LoadTexture((char*)"kitchenWallTexture2.bmp", 255.0f);
    Resturant::tableWoodTexture = LoadTexture((char*)"TableWoodTexture.bmp", 255.0f);
    Resturant::KitchenFloorWoodTexture = LoadTexture((char*)"KitchenFloorWoodTexture.bmp", 255.0f);
    Resturant::phrezFront = LoadTexture((char*)"phreza2Front.bmp", 255.0f);
    Resturant::phrezBack = LoadTexture((char*)"phrezaside.bmp", 255.0f);
    Resturant::shauma = LoadTexture((char*)"shaurma.bmp", 255.0f);
    Resturant::shaurmaTable = LoadTexture((char*)"shaurmaTable.bmp", 255.0f);
    Resturant::sideshaurmaTable = LoadTexture((char*)"sideshaurmaTable.bmp", 255.0f);
    Resturant::shaurmaTable2 = LoadTexture((char*)"shaurmaTable2.bmp", 255.0f);









}

void Resturant::TableLeg(int width, int tall,int height) {
    
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3ub(250, 250, 250);
    glVertex3i(-width/2, 0, tall / 2);
    glVertex3i(width / 2, 0, tall / 2);
    glVertex3i(width / 2, height, tall / 2);
    glVertex3i(-width / 2, height, tall / 2);

    //front face of wall the width
    glColor3ub(250, 250, 250);
    glVertex3i(-width / 2, 0, -tall / 2);
    glVertex3i(width / 2, 0, -tall / 2);
    glVertex3i(width / 2, height, -tall / 2);
    glVertex3i(-width / 2, height,-tall / 2);

    // back surface of the wall
    glColor3ub(250, 250, 250);
    glVertex3i(-width / 2, 0, -tall / 2);
    glVertex3i(-width / 2, 0, tall / 2);
    glVertex3i(-width / 2, height, tall / 2);
    glVertex3i(-width / 2, height, -tall / 2);


    //back face of wall the width
    glColor3ub(250, 250, 250);
    glVertex3i(width / 2, 0, -tall / 2);
    glVertex3i(width / 2, 0, tall / 2);
    glVertex3i(width / 2, height, tall / 2);
    glVertex3i(width / 2, height, -tall / 2);
    glEnd();
    glPopMatrix();
}
void Resturant::Table(int width ,int tall,int height, int textureID) {
   // wall.Roof(-250, 250, 200, 250, -250, 20, RoofFloorTexture, 1, 1);
   int y2 = height + 20;
   glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, textureID);
    
    glBegin(GL_QUADS);
    /* glColor4ub(0, 0, 0,0);*/

    glVertex3i(-width/2, height, tall/2);
    glVertex3i(width/2, height, tall / 2);
    glVertex3i(width / 2, height, -tall / 2);
    glVertex3i(-width / 2, height, -tall / 2);

    glColor4ub(255, 255, 255, 0);
    glTexCoord2f(0.0f, 0.0f); glVertex3i(-width / 2, y2, tall / 2);
    glTexCoord2f(1, 0.0f); glVertex3i(width / 2, y2, tall / 2);
    glTexCoord2f(1, 1); glVertex3i(width / 2, y2, -tall / 2);
    glTexCoord2f(0.0f, 1); glVertex3i(-width / 2, y2, -tall / 2);


    // front face of roof width
    /*glColor3ub(150, 40, 30);*/
    glVertex3i(-width / 2, height, tall / 2);
    glVertex3i(width / 2, height, tall / 2);
    glVertex3i(width / 2, y2, tall / 2);
    glVertex3i(-width / 2, y2, tall / 2);

    // right side face of roof width
    /*glColor3ub(150, 40, 30);*/
    glVertex3i(width / 2, height, tall / 2);
    glVertex3i(width / 2, height, -tall / 2);
    glVertex3i(width / 2, y2, -tall / 2);
    glVertex3i(width / 2, y2, tall / 2);

    // right side face of roof width
    /*glColor3ub(150, 40, 30);*/
    glVertex3i(-width / 2, height, tall / 2);
    glVertex3i(-width / 2, height, -tall / 2);
    glVertex3i(-width / 2, y2, -tall / 2);
    glVertex3i(-width / 2, y2, tall / 2);
    glEnd();

    

    int legWidth = 20;
    int xTranslate = (width / 2) - (legWidth / 2);
    int zTranslate = (tall/2) - (legWidth / 2);
    // draw the legs 
    glPushMatrix();
    glTranslated(-xTranslate,0, zTranslate);
    Resturant::TableLeg(20,20,200);
    glPopMatrix();

    glPushMatrix();
    glTranslated(xTranslate, 0, zTranslate);
    Resturant::TableLeg(20, 20, 200);
    glPopMatrix();

    glPushMatrix();
    glTranslated(xTranslate, 0, -zTranslate);
    Resturant::TableLeg(20, 20, 200);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-xTranslate, 0, -zTranslate);
    Resturant::TableLeg(20, 20, 200);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}

void Resturant::ChairLeg(int width, int tall,int start, int height) {
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3ub(250, 250, 250);
    glVertex3i(-width / 2, start, tall / 2);
    glVertex3i(width / 2, start, tall / 2);
    glVertex3i(width / 2, height, tall / 2);
    glVertex3i(-width / 2, height, tall / 2);

    //front face of wall the width
    glColor3ub(250, 250, 250);
    glVertex3i(-width / 2, start, -tall / 2);
    glVertex3i(width / 2, start, -tall / 2);
    glVertex3i(width / 2, height, -tall / 2);
    glVertex3i(-width / 2, height, -tall / 2);

    // back surface of the wall
    glColor3ub(250, 250, 250);
    glVertex3i(-width / 2, start, -tall / 2);
    glVertex3i(-width / 2, start, tall / 2);
    glVertex3i(-width / 2, height, tall / 2);
    glVertex3i(-width / 2, height, -tall / 2);


    //back face of wall the width
    glColor3ub(250, 250, 250);
    glVertex3i(width / 2, start, -tall / 2);
    glVertex3i(width / 2, start, tall / 2);
    glVertex3i(width / 2, height, tall / 2);
    glVertex3i(width / 2, height, -tall / 2);
    glEnd();
    glPopMatrix();
}
void Resturant::Chair(int width, int tall, int height,int rotateQ, int textureID) {
    // wall.Roof(-250, 250, 200, 250, -250, 20, RoofFloorTexture, 1, 1);
    int y2 = height + 20;
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, textureID);
    glPushMatrix();
    glRotated(rotateQ, 0, height, 0);
    glBegin(GL_QUADS);
    /* glColor4ub(0, 0, 0,0);*/

    glVertex3i(-width / 2, height, tall / 2);
    glVertex3i(width / 2, height, tall / 2);
    glVertex3i(width / 2, height, -tall / 2);
    glVertex3i(-width / 2, height, -tall / 2);

    glColor4ub(255, 255, 255, 0);
    glTexCoord2f(0.0f, 0.0f); glVertex3i(-width / 2, y2, tall / 2);
    glTexCoord2f(1, 0.0f); glVertex3i(width / 2, y2, tall / 2);
    glTexCoord2f(1, 1); glVertex3i(width / 2, y2, -tall / 2);
    glTexCoord2f(0.0f, 1); glVertex3i(-width / 2, y2, -tall / 2);


    // front face of roof width
    /*glColor3ub(150, 40, 30);*/
    glVertex3i(-width / 2, height, tall / 2);
    glVertex3i(width / 2, height, tall / 2);
    glVertex3i(width / 2, y2, tall / 2);
    glVertex3i(-width / 2, y2, tall / 2);

    // right side face of roof width
    /*glColor3ub(150, 40, 30);*/
    glVertex3i(width / 2, height, tall / 2);
    glVertex3i(width / 2, height, -tall / 2);
    glVertex3i(width / 2, y2, -tall / 2);
    glVertex3i(width / 2, y2, tall / 2);

    // right side face of roof width
    /*glColor3ub(150, 40, 30);*/
    glVertex3i(-width / 2, height, tall / 2);
    glVertex3i(-width / 2, height, -tall / 2);
    glVertex3i(-width / 2, y2, -tall / 2);
    glVertex3i(-width / 2, y2, tall / 2);
    glEnd();
   
    ///legsss

    int legWidth = 20;
    int xTranslate = (width / 2) - (legWidth / 2);
    int zTranslate = (tall / 2) - (legWidth / 2);
    // draw the legs 
    glPushMatrix();
    glTranslated(-xTranslate, 0, zTranslate);
    Resturant::ChairLeg(20, 20,0, height);
    glPopMatrix();

    glPushMatrix();
    glTranslated(xTranslate, 0, zTranslate);
    Resturant::ChairLeg(20, 20,0, height);
    glPopMatrix();

    glPushMatrix();
    glTranslated(xTranslate, 0, -zTranslate);
    Resturant::ChairLeg(20, 20,0, height*2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-xTranslate, 0, -zTranslate);
    Resturant::ChairLeg(20, 20,0, height*2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0, 0, -zTranslate);
    Resturant::ChairLeg(20, 20,height, height * 2);
    glPopMatrix();



    /////
    int x1 = -width / 2,x2 = width/2;
    int z1 = -tall / 2 + 20;
    int z2 = -tall / 2;
    int y1 = height * 2;
    int y2Top = y1 + 20;
    glBegin(GL_QUADS);
    /* glColor4ub(0, 0, 0,0);*/

    glVertex3i(x1, y1, z1);
    glVertex3i(x2, y1, z1);
    glVertex3i(x2, y1, z2);
    glVertex3i(x1, y1, z2);

    glColor4ub(255, 255, 255, 0);
     glVertex3i(x1, y2Top, z1);
     glVertex3i(x2, y2Top, z1);
     glVertex3i(x2, y2Top, z2);
     glVertex3i(x1, y2Top, z2);


    // front face of roof width
    /*glColor3ub(150, 40, 30);*/
    glVertex3i(x1, y1, z1);
    glVertex3i(x2, y1, z1);
    glVertex3i(x2, y2Top, z1);
    glVertex3i(x1, y2Top, z1);

    // right side face of roof width
    /*glColor3ub(150, 40, 30);*/
    glVertex3i(x2, y1, z1);
    glVertex3i(x2, y1, z2);
    glVertex3i(x2, y2Top, z2);
    glVertex3i(x2, y2Top, z1);

    // right side face of roof width
    /*glColor3ub(150, 40, 30);*/
    glVertex3i(x1, y1, z1);
    glVertex3i(x1, y1, z2);
    glVertex3i(x1, y2Top, z2);
    glVertex3i(x1, y2Top, z1);
    glEnd();

    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}
void Resturant::drawTable(int width ,int tall,int textureID) {
    Resturant::Table(width, tall, 200, textureID);
    //table chair
    
    glPushMatrix();
    glTranslated(-width/2, 0, 0);
    Resturant::Chair(200, 200, 150, 90, textureID);
    glPopMatrix();
    

    //table chair
    glPushMatrix();
    glTranslated(0, 0, -tall/2);
    Resturant::Chair(200, 200, 150, 0, textureID);
    glPopMatrix();

    //table chair
    glPushMatrix();
    glTranslated(width / 2, 0, 0);
    Resturant::Chair(200, 200, 150, -90, textureID);
    glPopMatrix();

    //table chair
    glPushMatrix();
    glTranslated(0, 0, tall / 2);
    Resturant::Chair(200, 200, 150, 180, textureID);
    glPopMatrix();
    

}
void Resturant::drawCone(float radius, float height, int slices) {
    // Draw the base of the cone
    glEnable(GL_TEXTURE_2D);

    glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f(0.5f, 0.5f); // Center of the base
    glVertex3f(0.0f, 0.0f, 0.0f); // Center point of base
    for (int i = 0; i <= slices; i++) {
        float angle = 2 * PI * i / slices;
        float x = radius * cos(angle);
        float y = radius * sin(angle);

        // Map texture coordinates
        glTexCoord2f((x / radius + 1) / 2, (y / radius + 1) / 2); // Scale to [0,1]
        glVertex3f(x, y, 0.0f);
    }
    glEnd();

    // Draw the sides of the cone
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= slices; i++) {
        float angle = 2 * PI * i / slices;
        float x = radius * cos(angle);
        float y = radius * sin(angle);

        // Map texture coordinates
        glTexCoord2f((x / radius + 1) / 2, (y / radius + 1) / 2); // Scale to [0,1]
        glVertex3f(x, y, 0.0f);       // Base vertex

        glTexCoord2f(0.5f, 1.0f);     // Texture coordinate for the top vertex
        glVertex3f(0.0f, 0.0f, height); // Apex of the cone
    }
    glEnd();
    glDisable(GL_TEXTURE_2D);
}


void Resturant::resturantRoom() {
    // first table
    glPushMatrix();
    glTranslated(-1500, 0, -500);
    Resturant::drawTable(500, 500, tableWoodTexture);
    glPopMatrix();


    //second table
    glPushMatrix();
    glTranslated(-3000, 0, -500);
    Resturant::drawTable(1000, 500, tableWoodTexture);
    glPopMatrix();

    // third table
    glPushMatrix();
    glTranslated(-1500, 0, -1500);
    Resturant::drawTable(500, 500, tableWoodTexture);
    glPopMatrix();


    //forth table
    glPushMatrix();
    glTranslated(-3000, 0, -1500);
    Resturant::drawTable(1000, 500, tableWoodTexture);
    glPopMatrix();


    //chicken table
    wall.Roof(-3200, -1000, 250, -2500, -3000, 50, Resturant::woodWallTexture, 1, 1);
    wall.sideWall(-3200, 0, 250, -2500, -3000, 50, woodWallTexture, 1, 1);
    wall.frontWall(-3200, -1000, 0, 250, -2550, 50,Resturant::woodWallTexture,1,1);


    // phreza
    wall.frontWall(-4000,-3300,0,600,-3650,20,phrezFront,1,1);
    wall.sideWall(-3320, 0, 600, -3655, -4000, 20, phrezBack, 1, 1);
    wall.Roof(-4000, -3300, 600, -3650, -4000, 20, phrezBack, 1, 1);


    // shaurmaa 
    glPushMatrix();
    glTranslated(-1250, 650, -3800);
    glRotated(90,100,0,0);
    glBindTexture(GL_TEXTURE_2D, shauma);
    drawCone(100, 300, 200);
    glPopMatrix();

    // shaurma Table

    wall.frontWall(-1500, -1000, 0, 300, -3650, 20, shaurmaTable, 1, 1);
    wall.sideWall(-1500, 0, 300, -3650, -4000, 20, sideshaurmaTable, 1, 1);
    wall.Roof(-1500, -1000, 300, -3650, -4000, 10, sideshaurmaTable, 1, 1);
    wall.frontWall(-1400, -1100, 300, 750, -3940, 60, shaurmaTable2, 1, 1);


    // base table
    wall.Roof(-3300,-1500,300,-3650,-4000,30,sideshaurmaTable,1,1);
    wall.sideWall(-3300, 0, 300, -3650, -4000, 30, sideshaurmaTable, 1, 1);

}

