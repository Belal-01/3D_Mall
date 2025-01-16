#include "Waterfall.h"
#include <cmath>
#include "texture.h"
#include "ObjLoader.h"
#include <iostream>
#include "OutSpace.h"

using namespace std;

ObjLoader objLoader;
// Constructor
Waterfall::Waterfall() {
 
    waveTime = 0.0f;
    frequency = 0.1f;
    amplitude = 5.0f;
}
 void Waterfall::drawUmbrella(float x, float y, float z, float radius, float height, float handleLength, float handleRadius) {
    const int slices = 36;

    glPushMatrix();
    glTranslatef(x, y, z);

    // Draw the canopy
    glColor3ub(227, 180, 255); // Red color for the umbrella
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0f, height, 0.0f); // Top center of the umbrella
    for (int i = 0; i <= slices; ++i) {
        float angle = 2.0f * 3.14 * i / slices; // Angle in radians
        float px = radius * cos(angle);
        float pz = radius * sin(angle);
        glVertex3f(px, 0.0f, pz);
    }
    glEnd();

    // Draw 10 spokes
    glColor3f(0.0f, 0.0f, 0.0f); // Black color for spokes
    glLineWidth(5);
    glBegin(GL_LINES);
    for (int i = 0; i < 10; ++i) {
        float angle = 2.0f * 3.14 * i / 10; // Divide the circle into 10 equal parts
        float px = radius * cos(angle);
        float pz = radius * sin(angle);
        glVertex3f(0.0f, height, 0.0f); // Start of the spoke at the top center
        glVertex3f(px, 0.0f, pz);      // End of the spoke at the canopy edge
    }
    glEnd();
    glColor3ub(140,106,50);
    glLineWidth(10);
    glBegin(GL_LINES);
    glVertex3f(0, height, 0);      
    glVertex3f(0, -250, 0);      

    glEnd();
    glPopMatrix();
}
void Waterfall::drawRoundedWall(float cx, float cy, float cz, float innerRadius, float outerRadius, float height, int segments) {
    float startAngle = -3.14 / 4;   // -45° in radians
    float endAngle = -3 * 3.14 / 4; // -135° in radians
    float angleStep = (endAngle - startAngle) / segments;

    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, chairTex);
    glColor3f(1,1,1);
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= segments; ++i) {
        float theta = startAngle + i * angleStep;
        float t = static_cast<float>(i) / segments; // Interpolating texture coordinate

        // Inner edge (bottom and top)
        float xInner = cx + innerRadius * cos(theta);
        float yInner = cy + innerRadius * sin(theta);

        // Outer edge (bottom and top)
        float xOuter = cx + outerRadius * cos(theta);
        float yOuter = cy + outerRadius * sin(theta);

        // Bottom vertices with texture coordinates
        glTexCoord2f(0.0f, t); glVertex3f(xInner, yInner, cz);         // Inner bottom
        glTexCoord2f(1.0f, t); glVertex3f(xOuter, yOuter, cz);         // Outer bottom

        // Top vertices with texture coordinates
        glTexCoord2f(0.0f, t); glVertex3f(xInner, yInner, cz + height); // Inner top
        glTexCoord2f(1.0f, t); glVertex3f(xOuter, yOuter, cz + height); // Outer top
    }
    glEnd();

    // Optional: Disable texturing if you want to render untextured geometry afterward
    glDisable(GL_TEXTURE_2D);
}








void Waterfall::Chair(float x, float y, float z, float radius, float thickness, float legHeight, float legRadius,float angle) {
    const int slices = 36; // Number of slices for smooth circular shapes

    glPushMatrix();
    glTranslatef(x, y, z); // Position the entire table
    glRotatef(-90, 1, 0, 0); // Rotate for proper alignment of the tabletop
    glRotatef(angle, 0, 0, 1); // Rotate for proper alignment of the tabletop

    // Enable textures
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, chairTex);

    GLUquadric* quad = gluNewQuadric();
    gluQuadricTexture(quad, GL_TRUE); // Enable texture mapping for the quadric

    // Draw the tabletop with texture
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f); // Use white color to show texture fully
    gluDisk(quad, 0.0, radius, slices, 1); // Top surface with texture
    glTranslatef(0.0f, 0.0f, -thickness);
    gluCylinder(quad, radius, radius, thickness, slices, 1); // Edge of the tabletop
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture for other objects
    glDisable(GL_TEXTURE_2D);

    // Draw the legs
    glColor3ub(128, 0, 0); // Darker brown for the legs
    float legPositions[4][6] = {
        { radius / 2, -radius / 2}, // Bottom-right leg
        {-radius / 2, -radius / 2}, // Bottom-left leg
        { radius / 2,  radius / 2},
        {-radius / 2,  radius / 2}, // Top-left leg
          // Top-right leg
    };

    for (int i = 0; i < 4; ++i) {
        glPushMatrix();
        glTranslatef(legPositions[i][0], legPositions[i][1], -legHeight);
        //glRotatef(legPositions[i][5], legPositions[i][2], legPositions[i][3], legPositions[i][4]);
        gluCylinder(quad, legRadius, legRadius, legHeight, slices, 1); // Cylindrical leg
        glPopMatrix();
    }

    // Cleanup the quadric object
    gluDeleteQuadric(quad);
    glColor3f(0.5,0.2,0.4);
    glPushMatrix();
    glRotatef(20,1,0,0);
    drawRoundedWall(0, 0, 0, radius-10, radius , 100, 300);

    glPopMatrix();
    glPopMatrix();
}













void Waterfall::drawRoundedTable(float x, float y, float z, float radius, float thickness, float legHeight, float legRadius) {
    const int slices = 36; // Number of slices for smooth circular shapes

    glPushMatrix();
    glTranslatef(x, y, z); // Position the entire table
    glRotatef(-90, 1, 0, 0); // Rotate for proper alignment of the tabletop

    // Enable textures
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tableTex);

    GLUquadric* quad = gluNewQuadric();
    gluQuadricTexture(quad, GL_TRUE); // Enable texture mapping for the quadric

    // Draw the tabletop with texture
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f); // Use white color to show texture fully
    gluDisk(quad, 0.0, radius, slices, 1); // Top surface with texture
    glTranslatef(0.0f, 0.0f, -thickness);
    gluCylinder(quad, radius, radius, thickness, slices, 1); // Edge of the tabletop
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture for other objects
    glDisable(GL_TEXTURE_2D);

    // Draw the legs
    glColor3f(0.6f, 0.3f, 0.1f); // Darker brown for the legs
    float legPositions[4][2] = {
        {-radius / 2, -radius / 2}, // Bottom-left leg
        { radius / 2, -radius / 2}, // Bottom-right leg
        {-radius / 2,  radius / 2}, // Top-left leg
        { radius / 2,  radius / 2}  // Top-right leg
    };

    for (int i = 0; i < 4; ++i) {
        glPushMatrix();
        glTranslatef(legPositions[i][0], legPositions[i][1], -legHeight);
         gluCylinder(quad, legRadius, legRadius, legHeight, slices, 1); // Cylindrical leg
        glPopMatrix();
    }

    // Cleanup the quadric object
    gluDeleteQuadric(quad);
    glPushMatrix();
    glRotatef(90,1,0,0);
    glScalef(1.7, 1.7, 1.7);
    Chair(0, -40, radius/2, 50, 10,100,5,0 );
    Chair(radius/2, -40, 0, 50, 10,100,5,90 );
    Chair(-radius/2, -40, 0, 50, 10,100,5,-90 );
    Chair(0, -40, -radius/2, 50, 10,100,5,180 );
    glPopMatrix();
   

    glPopMatrix(); // Restore the modelview matrix
}



void Waterfall::drawWaterDrop(float t, float startX, float startY, float startZ,
    float controlX, float controlY, float controlZ,
    float endX, float endY, float endZ) {
    // Bézier curve calculations
    float x = (1 - t) * (1 - t) * startX + 2 * (1 - t) * t * controlX + t * t * endX;
    float y = (1 - t) * (1 - t) * startY + 2 * (1 - t) * t * controlY + t * t * endY;
    float z = (1 - t) * (1 - t) * startZ + 2 * (1 - t) * t * controlZ + t * t * endZ;

    // Draw the drop
    glPushMatrix();
    glTranslatef(x, y, z);
    glColor3f(0.0f, 0.5f, 1.0f); 
    glutSolidSphere(5.0, 16, 16); // Radius of 5.0
    glPopMatrix();
}


void Waterfall::drawWaterDropSeries(float startX, float startY, float startZ,
    float controlX, float controlY, float controlZ,
    float endX, float endY, float endZ) {
    const float speed = 0.01; // Speed of movement

    for (int i = 0; i < numDrops; ++i) {
        if (i < 0 || i >= numDrops) continue; // Safety check

        float t = fmod(dropProgress[i], 1.0f); // Keep progress within [0, 1]
        drawWaterDrop(t, startX, startY, startZ, controlX, controlY, controlZ, endX, endY, endZ);

        dropProgress[i] -= speed; // Decrement progress
        if (dropProgress[i] <= 0.0f) {
            dropProgress[i] = 1.0f; // Reset progress to start again from the end
        }
    }
}




void  Waterfall::drawWater(float centerx, float centery, float centerz, float width, float length, int gridSize) {
    glPushMatrix();
    glTranslatef(centerx, centery, centerz);

    float stepX = width / gridSize;
    float stepZ = length / gridSize;
    float waveTime = glutGet(GLUT_ELAPSED_TIME) * 0.005; // Time for wave animation
    float frequency = 0.01;  // Wave frequency
    float amplitude = 18;
    glColor4f(0.0f, 0.7f, 1.0f,0.8);
    //glColor4f(0.5f, 0.9f, 1.0f, 0.8);
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


void Waterfall::drawFantain(float x, float y, float z ) {
    glPushMatrix();
    glTranslatef(x, y, z);

    glBegin(GL_QUADS);
    //glVertex3f();
    glEnd();
    drawWaterDropSeries(50, 50, 0, 100, 250, 0, 150, 100, 0);
    drawWaterDropSeries(50, 50, 50, 100, 250, 0, 150, 100, 0);
    drawWaterDropSeries(50, 50, -50, 100, 250, 0, 150, 100, 0);
   


    glPopMatrix();
}

void Waterfall::drawground(float x, float y, float z,float len,float wid) {
    int repX = 6;
    int repY = 10;
    glPushMatrix();
    glTranslatef(x, y, z);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, groundTex);
    glColor3f(0.9, 0.9, 0.9);
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
}





void Waterfall::drawFenceWater(float cornerx, float cornery, float cornerz, float len, float wid, float hig) {
    int repX = 1;
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
        glBindTexture(GL_TEXTURE_2D, fantainTex);
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
        glBindTexture(GL_TEXTURE_2D, fantainTex);
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

        glTranslatef(len, 0, 0);
        glRotatef(90, 0, 1, 0);
    }
    glPopMatrix();

    // Draw big water
    drawWater(len / 2, hig-50, -wid / 2,2* len / 2,2* wid / 2, 50);


    glPopMatrix();
}




void Waterfall::drawWallWater(float centerx, float bottomy, float centerz, float len,float hig) {
    int repX = 5;
    int repY = 1;
   
    glDisable(GL_BLEND);

    glPushMatrix();
    glTranslatef(centerx, bottomy, centerz);

   
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, climingRose);
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3d(-len/2, 0, 0);
        glTexCoord2f(repX, 0.0f);
        glVertex3d(len/2, 0, 0);
        glTexCoord2f(repX, repY);
        glVertex3d(len/2, hig, 0);
        glTexCoord2f(0.0f, repY);
        glVertex3d(-len/2, hig, 0);
        glEnd();
        glDisable(GL_TEXTURE_2D);

    glPopMatrix();
    glDisable(GL_BLEND);

}



void Waterfall::draw() {
    
    static float t = 0.0f;  
    t += 0.01f; // Increment t for animation
    if (t > 1.0f) t = 0.0f;  

     

    // Draw other elements in the scene (existing functionality)
    for (float i = 0; i <= 2000; i += 1000) {
        drawUmbrella(-6250, 500, -500 - i, 500, 180, 200, 50);
        drawRoundedTable(-6250, 250, -500 - i, 300, 20, 250, 10);
    }
    for (float i = 0; i <= 2000; i += 1000) {
        drawUmbrella(-4750, 500, -500 - i, 500, 180, 200, 50);
        drawRoundedTable(-4750, 250, -500 - i, 300, 20, 250, 10);
    }

    for (float i = 0; i < 3000; i+=500)
    {
        drawFantain(-5400, 0, -500-i);
        glPushMatrix();
        glRotatef(180,0,1,0);
        drawFantain(5600, 0, 500 +i);
        glPopMatrix();
        glPushMatrix();
        glScalef(1, 1, 0.5);
    drawFenceWater(-5800,0,-650-i*2,600,600,100);
        glPopMatrix();
    }
    drawground(-7000,10,0,3000,5000);
    drawWallWater(-5500,0,-4000,2800,800);
}


void Waterfall::init() {
     tableTex = LoadTexture((char*)"images/chair.bmp", 255.0f);   
    chairTex= LoadTexture((char*)"images/tableTex.bmp", 255.0f);
    fantainTex= LoadTexture((char*)"images/fall.bmp", 255.0f);
    groundTex= LoadTexture((char*)"images/ground.bmp", 255.0f);
    climingRose= LoadTexture((char*)"images/climbingrose.bmp", 255.0f);
    for (int i = 0; i < numDrops; ++i) {
        dropProgress[i] = static_cast<float>(i) / numDrops; // Evenly space progress
    }
}