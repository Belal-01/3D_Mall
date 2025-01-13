#include <GL/glut.h>
#include "Door.h"
#include <cmath>

// Constructor
Door::Door(float x,float y, float z, float alpha,float rot,float w,float h)
    : xPosition(x), yPosition(y), zPosition(z), openAmount(0.0f), transparency(alpha),rotate(rot),width(w),hight(h) {}

// Function to calculate the distance between the camera and the door
float Door::calculateDistance(float cameraX,float cameraY, float cameraZ) const {
    float dis = abs(zPosition - cameraZ);
    if (rotate == 90 || rotate == 270) {
        dis= abs(zPosition - cameraX);
   }

    return dis;
}

// Update door state based on distance
void Door::updateState(float cameraX, float cameraY, float cameraZ) {
    float distance = calculateDistance(cameraX, cameraY, cameraZ);
    if (distance <= 1000) {
        openAmount = std::min(openAmount + 2, width/2); // Open the doors gradually
    }
    else {
        openAmount = std::max(openAmount - 2, 0.0f); // Close the doors gradually
    }
}

// Draw the door
void Door::draw() {
    float door1Offset = openAmount ; // Assuming door width is 50, so half is 25
    
    glPushMatrix();
    glRotatef(rotate, 0, 1, 0);
    glDepthMask(GL_FALSE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.5f, 0.8f, 1.0f, transparency);

    // Draw the left door
    glBegin(GL_QUADS);
    glVertex3f(xPosition  + door1Offset, yPosition, zPosition);
    glVertex3f(xPosition + door1Offset+width, yPosition, zPosition);
    glVertex3f(xPosition + door1Offset+ width, yPosition+hight, zPosition);
    glVertex3f(xPosition + door1Offset, yPosition + hight, zPosition);
    glEnd();
    
    // Draw the right door
    glBegin(GL_QUADS);
    glVertex3f(xPosition - width - door1Offset, yPosition, zPosition);
    glVertex3f(xPosition - door1Offset , yPosition, zPosition);
    glVertex3f(xPosition - door1Offset , yPosition+ hight, zPosition);
    glVertex3f(xPosition- width - door1Offset, yPosition+ hight, zPosition);
    glEnd();

    glDisable(GL_BLEND);
    glDepthMask(GL_TRUE);
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(xPosition + door1Offset, yPosition, zPosition);
    glVertex3f(xPosition + door1Offset + width, yPosition, zPosition);
    glVertex3f(xPosition + door1Offset + width, yPosition + hight/100, zPosition);
    glVertex3f(xPosition + door1Offset, yPosition + hight/100, zPosition);
    
    glVertex3f(xPosition - width - door1Offset, yPosition, zPosition);
    glVertex3f(xPosition - door1Offset, yPosition, zPosition);
    glVertex3f(xPosition - door1Offset, yPosition + hight/100, zPosition);
    glVertex3f(xPosition - width - door1Offset, yPosition + hight/100, zPosition);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(xPosition - door1Offset, yPosition, zPosition);
    glVertex3f(xPosition - door1Offset, yPosition + hight, zPosition);
    glVertex3f(xPosition - door1Offset, yPosition, zPosition);
    glVertex3f(xPosition - door1Offset, yPosition + hight, zPosition);
    glEnd();
    glPopMatrix();
}
