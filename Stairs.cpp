#include "Stairs.h"
#include <GL/glut.h>
#include "texture.h"
#include "Wall.h"
#include "restorant.h"

 extern Wall wall;
extern Resturant resturant;
void Stairs::stairsInit() {
    oneStairImg = LoadTexture((char*)"images\\stairimg.bmp", 255.0f);
    stairSideStickImg = LoadTexture((char*)"images\\floorImg.bmp", 255.0f);

}
void Stairs::oneStair() {
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex3i(-225, 0, 0);
    glVertex3i(225, 0, 0);
    glVertex3i(225, 55, 0);
    glVertex3i(-225, 55, 0);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, oneStairImg);
    glBegin(GL_QUADS);
    /*glColor3ub(255, 255, 255);*/
    glTexCoord2i(0, 0); glVertex3i(-225, 55, 0);
    glTexCoord2i(1, 0); glVertex3i(225, 55, 0);
    glTexCoord2i(1, 1); glVertex3i(225, 55, -150);
    glTexCoord2i(0, 1); glVertex3i(-225, 55, -150);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);

    glVertex3i(225, -40, 0);
    glVertex3i(225, 15, -150);
    glVertex3i(225, 55, -150);
    glVertex3i(225, 55, 0);


    glEnd();
    glDisable(GL_TEXTURE_2D);
}
void Stairs::stairSideStick(int textureID) {
    int x1 = 220, x2 = 235, width = 15, y1 = 190, y3 = 630, z1 = 600, z2 = -600;
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID);
    int y2 = y1 + width;
    int y4 = y3 + width;
    glBegin(GL_QUADS);
    /* glColor4ub(0, 0, 0,0);*/

    glVertex3i(x1, y1, z1);
    glVertex3i(x2, y1, z1);
    glVertex3i(x2, y3, z2);
    glVertex3i(x1, y3, z2);

    glColor4ub(255, 255, 255, 0);
    glTexCoord2f(0.0f, 0.0f); glVertex3i(x1, y2, z1);
    glTexCoord2f(1, 0.0f); glVertex3i(x2, y2, z1);
    glTexCoord2f(1, 1); glVertex3i(x2, y4, z2);
    glTexCoord2f(0.0f, 1); glVertex3i(x1, y4, z2);


    // front face of roof width
    /*glColor3ub(150, 40, 30);*/
    glVertex3i(x1, y1, z1);
    glVertex3i(x2, y1, z1);
    glVertex3i(x2, y2, z1);
    glVertex3i(x1, y2, z1);

    // back face of roof width
    glVertex3i(x1, y3, z2);
    glVertex3i(x2, y3, z2);
    glVertex3i(x2, y4, z2);
    glVertex3i(x1, y4, z2);

    // right side face of roof width
    /*glColor3ub(150, 40, 30);*/
    glVertex3i(x2, y1, z1);
    glVertex3i(x2, y3, z2);
    glVertex3i(x2, y4, z2);
    glVertex3i(x2, y2, z1);

    // left side face of roof width
    /*glColor3ub(150, 40, 30);*/
    glVertex3i(x1, y1, z1);
    glVertex3i(x1, y3, z2);
    glVertex3i(x1, y4, z2);
    glVertex3i(x1, y2, z1);
    glEnd();
    //glDisable(GL_BLEND);
    //glDepthMask(GL_TRUE);
    glDisable(GL_TEXTURE_2D);
}
void Stairs::stairs(int x, int y, int z, int Q) {

    glPushMatrix();
    glTranslated(x, y, z);
    glRotated(Q, 0, 400, 0);
    glBegin(GL_QUADS);
    glColor3ub(139, 130, 130);
    glVertex3i(-225, -40, 600);
    glVertex3i(225, -40, 600);
    glVertex3i(225, 400, -600);
    glVertex3i(-225, 400, -600);
    glEnd();

    // draw the glasses
    glDepthMask(GL_FALSE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.5f, 0.8f, 1.0f, 0.8);
    glBegin(GL_QUADS);
    glVertex3i(220, 0, 600);

    glVertex3i(220, 400, -600);

    glVertex3i(220, 600, -600);

    glVertex3i(220, 160, 600);

    glEnd();

    glDisable(GL_BLEND);
    glDepthMask(GL_TRUE);

    // draw the glasses staicks roof 
      stairSideStick(stairSideStickImg);


    glPushMatrix();
    glTranslated(0, 0, 600);
    for (int i = 0; i < 8; i++)
    {
        wall.sideWall(220, 0, 220, -60, -75, 15, resturant.sideshaurmaTable, 1, 1, resturant.sideshaurmaTable, 1, 1);
        oneStair();
            glTranslated(0, 55, -150);
    }
    glPopMatrix();


    glPopMatrix();



}