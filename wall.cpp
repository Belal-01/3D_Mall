#include <GL/glut.h> // Include the GLUT header file
#include "texture.h"
#include <iostream>
#include "Wall.h"

void Wall::sideWall(int x1, int y1, int y2, int z1, int z2, int width,int textureID, int RepeatX, int RepeatY, int textureID2, int RepeatX2, int RepeatY2){
    int x2 = x1 + width;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor4ub(250, 250, 250,0);
    glTexCoord2d(0, 0); glVertex3i(x1, y1, z1);
    glTexCoord2d(RepeatX, 0); glVertex3i(x1, y1, z2);
    glTexCoord2d(RepeatX, RepeatY); glVertex3i(x1, y2, z2);
    glTexCoord2d(0, RepeatY); glVertex3i(x1, y2, z1);
    
    //front face of wall the width
    glColor4ub(250, 250, 250, 0);
    glVertex3i(x2, y1, z1);
    glVertex3i(x1, y1, z1);
    glVertex3i(x1, y2, z1);
    glVertex3i(x2, y2, z1);
    glDisable(GL_TEXTURE_2D);
    glEnd();
    // back surface of the wall

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID2);
    glBegin(GL_QUADS);
    glColor4ub(250, 250, 250, 0);
    glTexCoord2d(0, 0); glVertex3i(x2, y1, z1);
    glTexCoord2d(RepeatX2, 0); glVertex3i(x2, y1, z2);
    glTexCoord2d(RepeatX2, RepeatY2); glVertex3i(x2, y2, z2);
    glTexCoord2d(0, RepeatY2); glVertex3i(x2, y2, z1);


    //back face of wall the width
    glColor4ub(250, 250, 250, 0);
    glVertex3i(x2, y1, z2);
    glVertex3i(x1, y1, z2);
    glVertex3i(x1, y2, z2);
    glVertex3i(x2, y2, z2);
    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


}

void Wall::frontWall(int x1, int x2, int y1, int y2, int z1, int width ,int textureID, int RepeatX, int RepeatY, int textureID2, int RepeatX2, int RepeatY2) {
    int z2 = z1 - width;
    glEnable(GL_TEXTURE_2D);

    glPushMatrix();
 
    glBindTexture(GL_TEXTURE_2D, textureID);
    glBegin(GL_QUADS);
    glColor4ub(250, 250, 250,0);
    glTexCoord2d(0, 0); glVertex3i(x1, y1, z1);
    glTexCoord2d(RepeatX,0); glVertex3i(x2, y1, z1);
    glTexCoord2d(RepeatX,RepeatY); glVertex3i(x2, y2, z1);
    glTexCoord2d(0, RepeatY);glVertex3i(x1, y2, z1);
    glEnd();

    //front face of wall the width
   /* glColor3ub(150, 40, 30);*/
    glBindTexture(GL_TEXTURE_2D, textureID2);

    glBegin(GL_QUADS);

    glTexCoord2d(0, 0); glVertex3i(x1, y1, z2);
    glTexCoord2d(RepeatX2, 0);glVertex3i(x2, y1, z2);
    glTexCoord2d(RepeatX2, RepeatY2);glVertex3i(x2, y2, z2);
    glTexCoord2d(0, RepeatY2);glVertex3i(x1, y2, z2);

    // back surface of the wall
    /*glColor3ub(150, 100, 30);*/
    glVertex3i(x1, y1, z2);
    glVertex3i(x1, y1, z1);
    glVertex3i(x1, y2, z1);
    glVertex3i(x1, y2, z2);


    //back face of wall the width
   /* glColor3ub(150, 40, 30);*/
    glVertex3i(x2, y1, z2);
    glVertex3i(x2, y1, z1);
    glVertex3i(x2, y2, z1);
    glVertex3i(x2, y2, z2);
    glEnd();

    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


}

void Wall::Roof(int x1, int x2, int y1, int z1, int z2, int width, int textureID ,int RepeatX ,int RepeatY) {

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID);
    int y2 = y1 + width;
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
   /* glColor4ub(0, 0, 0,0);*/

    glVertex3i(x1, y1, z1);
    glVertex3i(x2, y1, z1);
    glVertex3i(x2, y1, z2);
    glVertex3i(x1, y1, z2);

    glColor4ub(255, 255, 255, 0);
    glTexCoord2f(0.0f, 0.0f); glVertex3i(x1, y2, z1);
    glTexCoord2f(RepeatX, 0.0f); glVertex3i(x2, y2, z1);
    glTexCoord2f(RepeatX, RepeatY); glVertex3i(x2, y2, z2);
    glTexCoord2f(0.0f, RepeatY); glVertex3i(x1, y2, z2);


    // front face of roof width
    /*glColor3ub(150, 40, 30);*/
    glVertex3i(x1, y1, z1);
    glVertex3i(x2, y1, z1);
    glVertex3i(x2, y2, z1);
    glVertex3i(x1, y2, z1);

    // back face of roof width
    glVertex3i(x1, y1, z2);
    glVertex3i(x2, y1, z2);
    glVertex3i(x2, y2, z2);
    glVertex3i(x1, y2, z2);

    // right side face of roof width
    /*glColor3ub(150, 40, 30);*/
    glVertex3i(x2, y1, z1);
    glVertex3i(x2, y1, z2);
    glVertex3i(x2, y2, z2);
    glVertex3i(x2, y2, z1);

    // right side face of roof width
    /*glColor3ub(150, 40, 30);*/
    glVertex3i(x1, y1, z1);
    glVertex3i(x1, y1, z2);
    glVertex3i(x1, y2, z2);
    glVertex3i(x1, y2, z1);
    glEnd();
    //glDisable(GL_BLEND);
    //glDepthMask(GL_TRUE);
    glDisable(GL_TEXTURE_2D);
}

void Wall::floor(int x1, int x2, int y1, int z1, int z2,int textureID ,float RepeatX, float RepeatY ){
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID);
    //glDepthMask(GL_FALSE);
    //glEnable(GL_BLEND);
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_QUADS);
    /*glColor3ub(0, 0, 0);*/
    //glColor3uba(150, 40, 30);
    glColor4ub(255, 255, 255, 0);

    glTexCoord2f(0.0f, 0.0f); glVertex3i(x1, y1, z1);
    glTexCoord2f(RepeatX, 0.0f); glVertex3i(x2, y1, z1);
    glTexCoord2f(RepeatX, RepeatY); glVertex3i(x2, y1, z2);
    glTexCoord2f(0.0f, RepeatY); glVertex3i(x1, y1, z2);
       
    
    glEnd();
    glDisable(GL_TEXTURE_2D);
    //glDisable(GL_BLEND);
    //glDepthMask(GL_TRUE);
}


// nozo function 
void Wall::create(int x1, int x2, int y1, int y2, int z1, int z2) {
    glBegin(GL_QUADS);

    // First face
    glColor3ub(250, 40, 30);
    glVertex3i(x1, y1, z1);
    glVertex3i(x1, y1, z2);
    glVertex3i(x1, y2, z2);
    glVertex3i(x1, y2, z1);

    // Second face
    glColor3ub(150, 40, 30);
    glVertex3i(x2, y1, z1);
    glVertex3i(x1, y1, z1);
    glVertex3i(x1, y2, z1);
    glVertex3i(x2, y2, z1);

    // Third face
    glColor3ub(50, 40, 30);
    glVertex3i(x2, y1, z2);
    glVertex3i(x1, y1, z2);
    glVertex3i(x1, y2, z2);
    glVertex3i(x2, y2, z2);

    // Fourth face
    glColor3ub(20, 40, 30);
    glVertex3i(x2, y1, z1);
    glVertex3i(x2, y1, z2);
    glVertex3i(x2, y2, z2);
    glVertex3i(x2, y2, z1);

    glEnd();
}

