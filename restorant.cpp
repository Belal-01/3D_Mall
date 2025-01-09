#include "restorant.h"
#include "GL/glut.h"

void Resturant::TableLeg(int width, int tall, int height) {
    
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