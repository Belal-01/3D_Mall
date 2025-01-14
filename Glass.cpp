#include <GL/glut.h>
#include "Glass.h"
#include <iostream>

// Constructor
Glass::Glass() {}

// Draw method
void Glass::drawWall(int x1, int x2, int y1, int y2, int z1, int z2, float alpha ) {
    // Set color with transparency
    // Enable blending for transparency

    // Draw the glass wall
    glDepthMask(GL_FALSE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //  ÕœÌœ «··Ê‰ „⁄ ‘›«›Ì… («·ﬁÌ„… «·√ŒÌ—… ›Ì glColor4f ÂÌ «·‘›«›Ì…)
    glColor4f(0.5f, 0.8f, 1.0f,alpha); // ·Ê‰ “Ã«ÃÌ „⁄ ‘›«›Ì…

  
    glBegin(GL_QUADS);
   
    glVertex3i(x1, y1, z1);
  
    glVertex3i(x1, y1, z2);

    glVertex3i(x2, y2, z2);

    glVertex3i(x2, y2, z1);

    //front face of wall the width

    glEnd();

    // —”Ê„ ÂÊ‰ 
    glDisable(GL_BLEND);
    glDepthMask(GL_TRUE);



}
void Glass::drawRoof(int x1, int x2, int y1, int z1, int z2, float alpha) {
    glDepthMask(GL_FALSE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.5f, 0.8f, 1.0f, alpha);
    glBegin(GL_QUADS);
    glVertex3i(x1, y1, z1);
    
    glVertex3i(x1, y1, z2);
  
    glVertex3i(x2, y1, z2);
   
    glVertex3i(x2, y1, z1);

    //front face of wall the width

    glEnd();
    glDisable(GL_BLEND);
    glDepthMask(GL_TRUE);
}

void Glass::drawTriangle(int x1, int x2, int x3, int y1, int y2, int y3, int z1, float alpha) {

    glDepthMask(GL_FALSE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.5f, 0.8f, 1.0f, alpha);

    glBegin(GL_POLYGON);
    glVertex3i(x1, y1, z1);
    glVertex3i(x1, y2, z1);
    glVertex3i(x2, y2, z1);
    glVertex3i(x2, y3, z1);
    glVertex3i(x3, y3, z1);
    glEnd();
    glDisable(GL_BLEND);
    glDepthMask(GL_TRUE);
}
void Glass::drawfrontWall(int x1, int x2, int y1, int y2, int z1, float alpha) {
    glDepthMask(GL_FALSE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.5f, 0.8f, 1.0f, alpha);
    glBegin(GL_QUADS);
    
    glVertex3i(x1, y1, z1);
    glVertex3i(x2, y1, z1);
    glVertex3i(x2, y2, z1);
    glVertex3i(x1, y2, z1);
    glEnd();

    glDisable(GL_BLEND);
    glDepthMask(GL_TRUE);
}