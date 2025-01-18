#include "Market.h"
 
#include <cmath>
#include "texture.h"
#include "ObjLoader.h"
#include <iostream>
 

void Market::drawSelves(float x, float y, float z, float length, float width, float height) {
    glPushMatrix();
    glTranslatef(x, y, z);

    glColor3ub(240, 200, 120);



    glBegin(GL_QUADS);

    // Front face
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(length, 0.0f, 0.0f);
    glVertex3f(length, height, 0.0f);
    glVertex3f(0.0f, height, 0.0f);

    // Back face
    glVertex3f(0.0f, 0.0f, -width);
    glVertex3f(length, 0.0f, -width);
    glVertex3f(length, height, -width);
    glVertex3f(0.0f, height, -width);

    // Top face
    glVertex3f(0.0f, height, 0.0f);
    glVertex3f(length, height, 0.0f);
    glVertex3f(length, height, -width);
    glVertex3f(0.0f, height, -width);

    // Bottom face
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(length, 0.0f, 0.0f);
    glVertex3f(length, 0.0f, -width);
    glVertex3f(0.0f, 0.0f, -width);

    // Left face
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, height, 0.0f);
    glVertex3f(0.0f, height, -width);
    glVertex3f(0.0f, 0.0f, -width);

    // Right face
    glVertex3f(length, 0.0f, 0.0f);
    glVertex3f(length, height, 0.0f);
    glVertex3f(length, height, -width);
    glVertex3f(length, 0.0f, -width);

    glEnd();
    glColor3f(0, 0, 0);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex3f(0, height, -width);
    glVertex3f(length, height, -width);

    glVertex3f(0, 0, -width);
    glVertex3f(length, 0, -width);

    glVertex3f(0, height, 0);
    glVertex3f(length, height, 0);

    glVertex3f(0, 0, 0);
    glVertex3f(length, 0, 0);
    glEnd();
    glPopMatrix();

}
void Market::drawWallShelves() {
    glColor3ub(220, 170, 170);

    drawSelves(200, 10, 0, 2800, 200, 20);
    drawSelves(200, 200, 0, 2800, 200, 20);
    drawSelves(200, 400, 0, 2800, 200, 20);
    drawSelves(200, 600, 0, 2800, 200, 20);
    drawSelves(200, 780, 0, 2800, 200, 20);


    drawSelves(200, 10, -3720, 2800, 200, 20);
    drawSelves(200, 200, -3720, 2800, 200, 20);
    drawSelves(200, 400, -3720, 2800, 200, 20);
    drawSelves(200, 600, -3720, 2800, 200, 20);
    drawSelves(200, 780, -3720, 2800, 200, 20);

    // middle

    drawSelves(800, 10, -1750, 1500, 400, 20);
    drawSelves(800, 200, -1750, 1500, 400, 20);
    drawSelves(800, 400, -1750, 1500, 400, 20);
   
    // front
    glPushMatrix();
    glRotated(90,0,1,0);

    drawSelves(0, 10, 3200, 3920, 200, 20);
    drawSelves(0, 200, 3200, 3920, 200, 20);
    drawSelves(0, 400, 3200, 3920, 200, 20);
    drawSelves(0, 600, 3200, 3920, 200, 20);
    drawSelves(0, 780, 3200, 3920, 200, 20);
    glPopMatrix();
}
void Market::drawroof(float x, float y, float z, float length, float wid, int tex, int rx, int ry) {


    glPushMatrix();
    glTranslatef(x, y, z);


    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex);
    glColor4f(1.0f, 1.0f, 1.0f, 0.1);
    glBegin(GL_QUADS);

    // Front face
    glTexCoord2f(0, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);
    glTexCoord2f(0, ry); glVertex3f(length, 0, 0);
    glTexCoord2f(rx, ry); glVertex3f(length, 0,-wid);
    glTexCoord2f(rx, 0); glVertex3f(0, 0.0f, -wid);

    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


}



void Market::drawPorduct(float x, float y, float z, float length, float height ,int tex,int rx,int ry) {

   
    glPushMatrix();
    glTranslatef(x, y, z);

 
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex);
    glColor4f(1.0f, 1.0f, 1.0f,0.1);
    glBegin(GL_QUADS);

    // Front face
    glTexCoord2f(0, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);
    glTexCoord2f(0, ry); glVertex3f(0.0f, height, 0.0f);
    glTexCoord2f(rx, ry); glVertex3f(length, height, 0);
    glTexCoord2f(rx, 0); glVertex3f(length, 0.0f, 0);

    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


}

void Market::drawCube(float width, float height, float depth) {
    glBegin(GL_QUADS);

    // Front face
    glVertex3f(-width / 2, -height / 2, depth / 2);
    glVertex3f(width / 2, -height / 2, depth / 2);
    glVertex3f(width / 2, height / 2, depth / 2);
    glVertex3f(-width / 2, height / 2, depth / 2);

    // Back face
    glVertex3f(-width / 2, -height / 2, -depth / 2);
    glVertex3f(-width / 2, height / 2, -depth / 2);
    glVertex3f(width / 2, height / 2, -depth / 2);
    glVertex3f(width / 2, -height / 2, -depth / 2);

    // Left face
    glVertex3f(-width / 2, -height / 2, -depth / 2);
    glVertex3f(-width / 2, -height / 2, depth / 2);
    glVertex3f(-width / 2, height / 2, depth / 2);
    glVertex3f(-width / 2, height / 2, -depth / 2);

    // Right face
    glVertex3f(width / 2, -height / 2, -depth / 2);
    glVertex3f(width / 2, height / 2, -depth / 2);
    glVertex3f(width / 2, height / 2, depth / 2);
    glVertex3f(width / 2, -height / 2, depth / 2);

    // Top face
    glVertex3f(-width / 2, height / 2, -depth / 2);
    glVertex3f(width / 2, height / 2, -depth / 2);
    glVertex3f(width / 2, height / 2, depth / 2);
    glVertex3f(-width / 2, height / 2, depth / 2);

    // Bottom face
    glVertex3f(-width / 2, -height / 2, -depth / 2);
    glVertex3f(-width / 2, -height / 2, depth / 2);
    glVertex3f(width / 2, -height / 2, depth / 2);
    glVertex3f(width / 2, -height / 2, -depth / 2);

    glEnd();
}

// Function to draw a cylinder (for wheels)
void Market::drawCylinder(float radius, float height, int segments) {
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= segments; i++) {
        float angle = 2.0f * 3.14159f * i / segments;
        float x = radius * cos(angle);
        float z = radius * sin(angle);

        glVertex3f(x, -height / 2, z);
        glVertex3f(x, height / 2, z);
    }
    glEnd();
}

// Function to draw the shopping cart
void Market::drawShoppingCart(float x,float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(200,200,200);
    // Draw base frame
    glPushMatrix();
    glColor3f(0.5f, 0.5f, 0.5f);
    glTranslatef(0.0f, 0.1f, 0.0f);
    drawCube(1.5f, 0.1f, 1.0f); // Base platform
    glPopMatrix();

    // Draw basket
    glPushMatrix();
    glColor3f(0.8f, 0.8f, 0.8f);
    glTranslatef(0.0f, 0.7f, 0.0f);
    drawCube(1.4f, 0.8f, 0.9f);
    glPopMatrix();

    // Draw wheels
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f);

    // Front-left wheel
    glPushMatrix();
    glTranslatef(-0.7f, -0.05f, 0.6f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    drawCylinder(0.1f, 0.05f, 32);
    glPopMatrix();

    // Front-right wheel
    glPushMatrix();
    glTranslatef(0.7f, -0.05f, 0.6f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    drawCylinder(0.1f, 0.05f, 32);
    glPopMatrix();

    // Back-left wheel
    glPushMatrix();
    glTranslatef(-0.7f, -0.05f, -0.6f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    drawCylinder(0.1f, 0.05f, 32);
    glPopMatrix();

    // Back-right wheel
    glPushMatrix();
    glTranslatef(0.7f, -0.05f, -0.6f);
    glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
    drawCylinder(0.1f, 0.05f, 32);
    glPopMatrix();

    glPopMatrix();

    glPopMatrix();
}



void Market::draw() {
    glPushMatrix();
    glTranslatef(800,0,1000-80);
    drawWallShelves();

    /// right product
    //drawShoseTable(-0, 10, -200, 200, 800, 600);
    drawPorduct(200,20,-150,2900,180,fishTex,4,2);
    drawPorduct(200,220,-150,2900,180,fish1Tex,4,2);
    drawPorduct(200,420,-150,2900,180,fishTex,4,2);
    drawPorduct(200,620,-150,2900,150,fish1Tex,4,2);

    /// left product 
    //drawShoseTable(-0, 10, -200, 200, 800, 600);
    drawPorduct(200, 20, -3770, 2850, 180, glass1, 4, 1);
    drawPorduct(200, 220, -3770, 2850, 180, glass11, 4, 1);
    drawPorduct(200, 420, -3770, 2850, 180, glass111, 4, 1);
    drawPorduct(200, 620, -3770, 2850, 150, glass1, 4,1);
    

    // toys
    drawPorduct(800, 20, -1800, 1500, 180, toys1, 4, 2);
    drawPorduct(800, 220, -1800, 1500, 180, toys111, 4, 2);
    drawPorduct(800, 20, -2100, 1500, 180, toys11, 4, 2);
    drawPorduct(800, 220, -2100, 1500, 180, toys1111, 4, 2);
    /* drawPorduct(1950, 220, 50, 1850, 180, juce11, 4, 1);
     drawPorduct(1950, 420, 50, 1850, 180, juce1, 4, 1);
     drawPorduct(1950, 620, 50, 1850, 180, juce11, 4, 1);*/
     //drawSelves(800, 10, -1750, 1500, 400, 20);
     // 
    // front product
    glPushMatrix();
    glTranslatef(3000,0,0);
    glRotatef(90,0,1,0);
    drawPorduct(150, 20, 50, 1800, 180, milk1Tex, 4, 2);
    drawPorduct(150, 220, 50, 1800, 180, milk11Tex, 4, 2);
    drawPorduct(150, 420, 50, 1800, 180, milk111Tex, 4, 2);
    drawPorduct(150, 620, 50, 1800, 180, milk1111Tex, 4, 2);

    drawPorduct(1950, 20, 50, 1850, 180, juce1, 4, 1);
    drawPorduct(1950, 220, 50, 1850, 180, juce11, 4,1);
    drawPorduct(1950, 420, 50, 1850, 180, juce1, 4, 1);
    drawPorduct(1950, 620, 50, 1850, 180, juce11, 4, 1);
    //

   
    // sale
    glPopMatrix();
    glPushMatrix();
    glRotatef(-90,0,1,0);
    drawPorduct(-1000, 0, 0, 600, 800, foodsale, 1, 1);
    drawPorduct(-3500, 0, 0, 600, 800, toyssale, 1, 1);
    drawPorduct(-2150, 10,-790 , 400, 420, delivery, 1, 1);
    drawPorduct(-2150, 10,-2310 , 400, 420, delivery, 1, 1);
    glPopMatrix();
    drawroof(0,790,0,3000,4000,roof,10,10);
     glPopMatrix();
}
void Market::init() {
    shoseTex = LoadTexture((char*)"images/shose.bmp", 255.0f);
    woodTex = LoadTexture((char*)"images/wood.bmp", 255.0f);
    fishTex = LoadTexture((char*)"images/fish.bmp", 255.0f);
    fish1Tex = LoadTexture((char*)"images/fish1.bmp", 255.0f);
    milk1Tex = LoadTexture((char*)"images/milk1.bmp", 255.0f);
    milk11Tex = LoadTexture((char*)"images/milk11.bmp", 255.0f);
    milk111Tex = LoadTexture((char*)"images/milk111.bmp", 255.0f);
    milk1111Tex = LoadTexture((char*)"images/milk1111.bmp", 255.0f);
    juce1 = LoadTexture((char*)"images/juce1.bmp", 255.0f);
    juce11 = LoadTexture((char*)"images/juce11.bmp", 255.0f);
    glass1 = LoadTexture((char*)"images/glass1.bmp", 255.0f);
    glass11 = LoadTexture((char*)"images/glass11.bmp", 255.0f);
    glass111 = LoadTexture((char*)"images/glass111.bmp", 255.0f);
    toyssale = LoadTexture((char*)"images/toyssale.bmp", 255.0f);
    foodsale = LoadTexture((char*)"images/foodsale.bmp", 100);
    delivery = LoadTexture((char*)"images/delivery.bmp", 100);
    toys1 = LoadTexture((char*)"images/toys1.bmp", 255.0f);
    toys11 = LoadTexture((char*)"images/toys11.bmp", 255.0f);
    toys111 = LoadTexture((char*)"images/toys111.bmp", 255.0f);
    toys1111= LoadTexture((char*)"images/toys1111.bmp", 255.0f);
    roof= LoadTexture((char*)"images/roof.bmp", 255.0f);
   
   

}