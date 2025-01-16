
#include <GL/glut.h>
#include <iostream>
#include <cstdlib> // · ÷„Ì‰ rand Ê srand
#include <ctime>   // · ÷„Ì‰ time
#include <random>


class ElectronicDeviceDrawer {

public:



    static void drawFridge(float x, float y, float z, float angleX, float angleY, float angleZ) {
        float fridgeWidth = 200.0f;
        float fridgeHeight = 500.0f;
        float fridgeDepth = 150.0f;
        float doorThickness = 0.5f;

        glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(angleX, 1.0f, 0.0f, 0.0f);
        glRotatef(angleY, 0.0f, 1.0f, 0.0f);
        glRotatef(angleZ, 0.0f, 0.0f, 1.0f);

        // —”„ Œÿ ›«’· · ﬁ”Ì„ «·»—«œ ≈·Ï »«»Ì‰
        glColor3f(0.0f, 0.0f, 0.0f); 
        glBegin(GL_LINES);
        glVertex3f(-fridgeWidth / 2, 400, fridgeDepth / 2);
        glVertex3f(fridgeWidth / 2, 400, fridgeDepth / 2);
        glEnd();

        // —”„ «·„ﬁ«»÷
        glColor3f(0.7f, 0.7f, 0.7f); 
        glBegin(GL_QUADS);
        glVertex3f(-100 + 15, 200, fridgeDepth / 2 + 0.1f);
        glVertex3f(-100 + 5, 200, fridgeDepth / 2 + 0.1f);
        glVertex3f(-100 + 5, 240, fridgeDepth / 2 + 0.1f);
        glVertex3f(-100 + 15, 240, fridgeDepth / 2 + 0.1f);
        glVertex3f(-100 + 15, 450, fridgeDepth / 2 + 0.1f);
        glVertex3f(-100 + 5, 450, fridgeDepth / 2 + 0.1f);
        glVertex3f(-100 + 5, 480, fridgeDepth / 2 + 0.1f);
        glVertex3f(-100 + 15, 480, fridgeDepth / 2 + 0.1f);
        glEnd();

        // —”„ Ã”„ «·»—«œ
        glColor3f(0.9f, 0.9f, 0.9f); 
        glBegin(GL_QUADS);

        // ÊÃÂ √„«„Ì
        glVertex3f(-fridgeWidth / 2, 0, fridgeDepth / 2);
        glVertex3f(fridgeWidth / 2, 0, fridgeDepth / 2);
        glVertex3f(fridgeWidth / 2, fridgeHeight, fridgeDepth / 2);
        glVertex3f(-fridgeWidth / 2, fridgeHeight, fridgeDepth / 2);

        // ÊÃÂ Œ·›Ì
        glVertex3f(-fridgeWidth / 2, 0, -fridgeDepth / 2);
        glVertex3f(fridgeWidth / 2, 0, -fridgeDepth / 2);
        glVertex3f(fridgeWidth / 2, fridgeHeight, -fridgeDepth / 2);
        glVertex3f(-fridgeWidth / 2, fridgeHeight, -fridgeDepth / 2);

        // «·ÕÊ«› «·Ã«‰»Ì…
        glVertex3f(-fridgeWidth / 2, 0, -fridgeDepth / 2);
        glVertex3f(-fridgeWidth / 2, 0, fridgeDepth / 2);
        glVertex3f(-fridgeWidth / 2, fridgeHeight, fridgeDepth / 2);
        glVertex3f(-fridgeWidth / 2, fridgeHeight, -fridgeDepth / 2);

        glVertex3f(fridgeWidth / 2, 0, -fridgeDepth / 2);
        glVertex3f(fridgeWidth / 2, 0, fridgeDepth / 2);
        glVertex3f(fridgeWidth / 2, fridgeHeight, fridgeDepth / 2);
        glVertex3f(fridgeWidth / 2, fridgeHeight, -fridgeDepth / 2);

        // «·”ﬁ› Ê«·ﬁ«⁄œ…
        glVertex3f(-fridgeWidth / 2, 0, -fridgeDepth / 2);
        glVertex3f(fridgeWidth / 2, 0, -fridgeDepth / 2);
        glVertex3f(fridgeWidth / 2, 0, fridgeDepth / 2);
        glVertex3f(-fridgeWidth / 2, 0, fridgeDepth / 2);

        glVertex3f(-fridgeWidth / 2, fridgeHeight, -fridgeDepth / 2);
        glVertex3f(fridgeWidth / 2, fridgeHeight, -fridgeDepth / 2);
        glVertex3f(fridgeWidth / 2, fridgeHeight, fridgeDepth / 2);
        glVertex3f(-fridgeWidth / 2, fridgeHeight, fridgeDepth / 2);

        glEnd();

        glPopMatrix();
    }

    static void drawFridge(float x, float y, float z, float angleX, float angleY, float angleZ,int fridge,float r,float g,float b) {
        float fridgeWidth = 200.0f;
        float fridgeHeight = 500.0f;
        float fridgeDepth = 150.0f;
        float doorThickness = 0.5f;

        glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(angleX, 1.0f, 0.0f, 0.0f);
        glRotatef(angleY, 0.0f, 1.0f, 0.0f);
        glRotatef(angleZ, 0.0f, 0.0f, 1.0f);

        
        // —”„ Ã”„ «·»—«œ

        glBindTexture(GL_TEXTURE_2D, fridge);
        glColor3f(0.9f, 0.9f, 0.9f); 
        glBegin(GL_QUADS);

            // ÊÃÂ √„«„Ì
        glTexCoord2f(1, 0);
        glVertex3f(-fridgeWidth / 2, 0, fridgeDepth / 2);
        glTexCoord2f(0, 0);
     
        glVertex3f(fridgeWidth / 2, 0, fridgeDepth / 2);
        glTexCoord2f(0, 1);
        
        glVertex3f(fridgeWidth / 2, fridgeHeight, fridgeDepth / 2);
        glTexCoord2f(1, 1);
        glVertex3f(-fridgeWidth / 2, fridgeHeight, fridgeDepth / 2);

        glEnd();

        glColor3f(r, g, b); 
        glBegin(GL_QUADS);
        // ÊÃÂ Œ·›Ì
        glVertex3f(-fridgeWidth / 2, 0, -fridgeDepth / 2);
        glVertex3f(fridgeWidth / 2, 0, -fridgeDepth / 2);
        glVertex3f(fridgeWidth / 2, fridgeHeight, -fridgeDepth / 2);
        glVertex3f(-fridgeWidth / 2, fridgeHeight, -fridgeDepth / 2);

        // «·ÕÊ«› «·Ã«‰»Ì…
        glVertex3f(-fridgeWidth / 2, 0, -fridgeDepth / 2);
        glVertex3f(-fridgeWidth / 2, 0, fridgeDepth / 2);
        glVertex3f(-fridgeWidth / 2, fridgeHeight, fridgeDepth / 2);
        glVertex3f(-fridgeWidth / 2, fridgeHeight, -fridgeDepth / 2);

        glVertex3f(fridgeWidth / 2, 0, -fridgeDepth / 2);
        glVertex3f(fridgeWidth / 2, 0, fridgeDepth / 2);
        glVertex3f(fridgeWidth / 2, fridgeHeight, fridgeDepth / 2);
        glVertex3f(fridgeWidth / 2, fridgeHeight, -fridgeDepth / 2);

        // «·”ﬁ› Ê«·ﬁ«⁄œ…
        glVertex3f(-fridgeWidth / 2, 0, -fridgeDepth / 2);
        glVertex3f(fridgeWidth / 2, 0, -fridgeDepth / 2);
        glVertex3f(fridgeWidth / 2, 0, fridgeDepth / 2);
        glVertex3f(-fridgeWidth / 2, 0, fridgeDepth / 2);

        glVertex3f(-fridgeWidth / 2, fridgeHeight, -fridgeDepth / 2);
        glVertex3f(fridgeWidth / 2, fridgeHeight, -fridgeDepth / 2);
        glVertex3f(fridgeWidth / 2, fridgeHeight, fridgeDepth / 2);
        glVertex3f(-fridgeWidth / 2, fridgeHeight, fridgeDepth / 2);

        glEnd();

        glPopMatrix();
    }
    static void drawAirConditioner(float x, float y, float z, float angleX, float angleY, float angleZ) {
        float width = 40.0f * 3;  
        float height = 20.0f * 3; 
        float depth = 10.0f * 3;  
        float pipeHeight = 10.0f * 3; 

        glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(angleX, 10.0f, 0.0f, 0.0f);
        glRotatef(angleY, 0.0f, 10.0f, 0.0f); 
        glRotatef(angleZ, 0.0f, 0.0f, 10.0f); 

        glColor3f(0.8f, 0.8f, 0.8f); 
        glBegin(GL_QUADS);

       
        glVertex3f(0, 0, 0);
        glVertex3f(width, 0, 0);
        glVertex3f(width, height, 0);
        glVertex3f(0, height, 0);

        glVertex3f(0, 0, 0);
        glVertex3f(0, height, 0);
        glVertex3f(0, height, -depth);
        glVertex3f(0, 0, -depth);

        glVertex3f(width, 0, 0);
        glVertex3f(width, height, 0);
        glVertex3f(width, height, -depth);
        glVertex3f(width, 0, -depth);

        glVertex3f(0, height, 0);
        glVertex3f(width, height, 0);
        glVertex3f(width, height, -depth);
        glVertex3f(0, height, -depth);

        glVertex3f(0, 0, -depth);
        glVertex3f(width, 0, -depth);
        glVertex3f(width, 0, 0);
        glVertex3f(0, 0, 0);

        glEnd();
           
      

        glPopMatrix();
    }
    static void drawAirConditioner(float x, float y, float z, float angleX, float angleY, float angleZ,int texture) {
        //  ⁄—Ì› „ €Ì—«  ·· Õﬂ„ ›Ì «·ÕÃ„
        float width = 40.0f * 3;  // «·⁄—÷
        float height = 20.0f * 3; // «·«— ›«⁄
        float depth = 10.0f * 3;  // «·⁄„ﬁ
        float pipeHeight = 10.0f * 3; // «— ›«⁄ «·√‰«»Ì»

        glBindTexture(GL_TEXTURE_2D, texture);
        glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(angleX, 10.0f, 0.0f, 0.0f); // œÊ—«‰ ÕÊ· «·„ÕÊ— X
        glRotatef(angleY, 0.0f, 10.0f, 0.0f); // œÊ—«‰ ÕÊ· «·„ÕÊ— Y
        glRotatef(angleZ, 0.0f, 0.0f, 10.0f); // œÊ—«‰ ÕÊ· «·„ÕÊ— Z

        glColor3f(0.8f, 0.8f, 0.8f); // ·Ê‰ «·„ﬂÌ›
        glBegin(GL_QUADS);

        // «·ÃÊ«‰» «·√—»⁄… ··„ﬂÌ› („ﬂ⁄») »«” Œœ«„ «·„ €Ì—« 
        glTexCoord2f(0, 0);
        glVertex3f(0, 0, 0);
        glTexCoord2f(1, 0);
        glVertex3f(width, 0, 0);
        glTexCoord2f(1, 1);
        glVertex3f(width, height, 0);
        glTexCoord2f(0, 1);
        glVertex3f(0, height, 0);

        glVertex3f(0, 0, 0);
        glVertex3f(0, height, 0);
        glVertex3f(0, height, -depth);
        glVertex3f(0, 0, -depth);

        glVertex3f(width, 0, 0);
        glVertex3f(width, height, 0);
        glVertex3f(width, height, -depth);
        glVertex3f(width, 0, -depth);

        glVertex3f(0, height, 0);
        glVertex3f(width, height, 0);
        glVertex3f(width, height, -depth);
        glVertex3f(0, height, -depth);

        glVertex3f(0, 0, -depth);
        glVertex3f(width, 0, -depth);
        glVertex3f(width, 0, 0);
        glVertex3f(0, 0, 0);

        glEnd();

        //  ›«’Ì· ≈÷«›Ì… („À· «·√‰«»Ì») »«” Œœ«„ «·„ €Ì—« 
        glLineWidth(3.0f);
        glColor3f(0.3f, 0.3f, 0.3f);
        glBegin(GL_LINES);
        glVertex3f(0, pipeHeight, 0);
        glVertex3f(width, pipeHeight, 0); // √‰»Ê» ›Ì «·√⁄·Ï
        glEnd();

        glLineWidth(3.0f);
        glColor3f(0.3f, 0.3f, 0.3f);
        glBegin(GL_LINES);
        glVertex3f(0, pipeHeight, -depth);
        glVertex3f(width, pipeHeight, -depth); // √‰»Ê» ›Ì «·√”›·
        glEnd();

        glPopMatrix();
    }

    static void drawAirConditionerWithFan(float x, float y, float z, float angleX, float angleY, float angleZ, float fanRotation) {
    
        float acWidth = 40.0f * 3;   
        float acHeight = 20.0f * 3;  
        float acDepth = 10.0f * 3;  
        float fanRadius = 10 * 3; 

        glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(angleX, 10.0f, 0.0f, 0.0f); 
        glRotatef(angleY, 0.0f, 10.0f, 0.0f); 
        glRotatef(angleZ, 0.0f, 0.0f, 10.0f); 

        // —”„ ÂÌﬂ· «·„ﬂÌ›
        glColor3f(0.8f, 0.8f, 0.8f); 
        glBegin(GL_QUADS);

    // ÊÃÂ «„«„Ì
        glVertex3f(0, 0, 0);
        glVertex3f(acWidth, 0, 0);
        glVertex3f(acWidth, acHeight, 0);
        glVertex3f(0, acHeight, 0);

        glVertex3f(0, 0, 0);
        glVertex3f(0, acHeight, 0);
        glVertex3f(0, acHeight, -acDepth);
        glVertex3f(0, 0, -acDepth);

        glVertex3f(acWidth, 0, 0);
        glVertex3f(acWidth, acHeight, 0);
        glVertex3f(acWidth, acHeight, -acDepth);
        glVertex3f(acWidth, 0, -acDepth);

        glVertex3f(0, acHeight, 0);
        glVertex3f(acWidth, acHeight, 0);
        glVertex3f(acWidth, acHeight, -acDepth);
        glVertex3f(0, acHeight, -acDepth);

        glVertex3f(0, 0, -acDepth);
        glVertex3f(acWidth, 0, -acDepth);
        glVertex3f(acWidth, 0, 0);
        glVertex3f(0, 0, 0);

        glEnd();

        // —”„ «·› Õ… «·√„«„Ì… ··„ﬂÌ›
        glColor3f(0.8f, 0.8f, 0.8f);
        glBegin(GL_QUADS);
        glVertex3f(20.0f, 20.0f, -0.1f);
        glVertex3f(60.0f, 20.0f, -0.1f);
        glVertex3f(60.0f, 20.0f, -1.0f);
        glVertex3f(20.0f, 20.0f, -1.0f);
        glEnd();

        // —”„ «·‘»ﬂ «·√„«„Ì ··„ﬂÌ›
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        for (float y = 0; y < acHeight; y += 3) {
            glVertex3f(0.1, y, -acDepth);
            glVertex3f(acWidth - 0.1, y, -acDepth);
        }
        for (float x = 0; x < acWidth; x += 3) {
            glVertex3f(x, acHeight - 0.1, -acDepth);
            glVertex3f(x, 0.1, -acDepth);
        }
        glEnd();

       
        float fanCenterX = acWidth / 2.0f;
        float fanCenterY = acHeight / 2.0f;
        float fanCenterZ = -1.0f;
      
        glColor3f(0.2f, 0.2f, 0.2f);
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < 360; i += 3) {
            float angle = i * 3.14159f / 180.0f;
            glVertex3f(fanCenterX + fanRadius * cos(angle), fanCenterY + fanRadius * sin(angle), -0.1f);
        }
        glEnd();

        // —”„ «·„—ÊÕ…
        glColor3f(0.5f, 0.5f, 0.5f);


        for (int i = 0; i < 3; ++i) {
            glPushMatrix();
            glTranslatef(fanCenterX, fanCenterY, fanCenterZ);
            glRotatef(fanRotation + i * 120.0f, 0.0f, 0.0f, 1.0f);
            glTranslatef(-fanCenterX, -fanCenterY, -fanCenterZ);

            glBegin(GL_TRIANGLES);
            glVertex3f(fanCenterX, fanCenterY, fanCenterZ);
            glVertex3f(fanCenterX + fanRadius * cos(0) - 5, fanCenterY + fanRadius * sin(0) - 5, fanCenterZ);
            glVertex3f(fanCenterX + fanRadius * cos(60.0f * 3.14159f / 180.0f) - 5, fanCenterY + fanRadius * sin(60.0f * 3.14159f / 180.0f) - 5, fanCenterZ);
            glEnd();

            glPopMatrix();
        }

        glPopMatrix();
    }
    static void drawfireplace(float x, float y, float z, float angleX, float angleY, float angleZ) {
      
        float width = 80.0f * 2;
        float height = 40.0f * 2;
        float depth = 20.0f * 2;

        glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(angleX, 1.0f, 0.0f, 0.0f);
        glRotatef(angleY, 0.0f, 1.0f, 0.0f);
        glRotatef(angleZ, 0.0f, 0.0f, 1.0f);

      
        glColor3f(0.8f, 0.8f, 0.8f);
        glBegin(GL_QUADS);
        // «·ÃÊ«‰» «·√—»⁄…
        glVertex3f(0, 0, 0);
        glVertex3f(width, 0, 0);
        glVertex3f(width, height, 0);
        glVertex3f(0, height, 0);

        glVertex3f(0, 0, 0);
        glVertex3f(0, height, 0);
        glVertex3f(0, height, -depth);
        glVertex3f(0, 0, -depth);

        glVertex3f(width, 0, 0);
        glVertex3f(width, height, 0);
        glVertex3f(width, height, -depth);
        glVertex3f(width, 0, -depth);

        glVertex3f(0, height, 0);
        glVertex3f(width, height, 0);
        glVertex3f(width, height, -depth);
        glVertex3f(0, height, -depth);

        glVertex3f(0, 0, -depth);
        glVertex3f(width, 0, -depth);
        glVertex3f(width, 0, 0);
        glVertex3f(0, 0, 0);
        glEnd();

        glColor3f(0.8f, 0.8f, 0.8f);
        glBegin(GL_QUADS);
        glVertex3f(40.0f, 40.0f, -0.1f);
        glVertex3f(120.0f, 40.0f, -0.1f);
        glVertex3f(120.0f, 40.0f, -1.0f);
        glVertex3f(40.0f, 40.0f, -1.0f);
        glEnd();

        // —”„ «·‘»ﬂ «·√„«„Ì
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        for (float y = 0; y < height; y += 6) {
            glVertex3f(0.1f, y, -depth);
            glVertex3f(width - 0.1f, y, -depth);
        }
        glEnd();

        // —”„ 3 √”ÿÊ«‰«  Õ„—«¡
        glColor3f(1.0f, 0.0f, 0.0f);
        GLUquadricObj* quadric = gluNewQuadric();

        for (int i = 1; i <= 3; i++) {
            glPushMatrix();
            glTranslatef(4.0f, i * 20.0f, -10.0f); // „÷«⁄›… «·≈“«Õ…
            glRotatef(90, 0.0f, 1.0f, 0.0f);
            gluCylinder(quadric, 4.0f, 4.0f, 150.0f, 32, 32); // „÷«⁄›… «·ÕÃ„
            glPopMatrix();
        }

        gluDeleteQuadric(quadric);
        glPopMatrix();
    }
    static void drawWashingMachine(float x, float y, float z, float angleX, float angleY, float angleZ, int wash,float r,float g,float b) {
        float machineWidth = 50.0f * 3;
        float machineHeight = 80.0f * 3;
        float machineDepth = 50.0f * 3;
        float doorRadius = 20.0f * 3;
        float doorThickness = 1.0f * 3;

        glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(angleX, 1.0f, 0.0f, 0.0f);
        glRotatef(angleY, 0.0f, 1.0f, 0.0f);
        glRotatef(angleZ, 0.0f, 0.0f, 1.0f);
        glBindTexture(GL_TEXTURE_2D, wash);
        // —”„ Ã”„ «·€”«·…
        glColor3f(0.5, 0.5, 0.5); 

        glBegin(GL_QUADS);

        // ÊÃÂ √„«„Ì
        glTexCoord2f(0, 0);
        glVertex3f(-machineWidth / 2, 0, machineDepth / 2);
        glTexCoord2f(1, 0);
        glVertex3f(machineWidth / 2, 0, machineDepth / 2);
        glTexCoord2f(1, 1);
        glVertex3f(machineWidth / 2, machineHeight, machineDepth / 2);
        glTexCoord2f(0, 1);
        glVertex3f(-machineWidth / 2, machineHeight, machineDepth / 2);
        glEnd();
        glColor3f(r, g, b); 

        glBegin(GL_QUADS);
        // ÊÃÂ Œ·›Ì
        glVertex3f(-machineWidth / 2, 0, -machineDepth / 2);
        glVertex3f(machineWidth / 2, 0, -machineDepth / 2);
        glVertex3f(machineWidth / 2, machineHeight, -machineDepth / 2);
        glVertex3f(-machineWidth / 2, machineHeight, -machineDepth / 2);

        // «·ÕÊ«› «·Ã«‰»Ì…
        glVertex3f(-machineWidth / 2, 0, -machineDepth / 2);
        glVertex3f(-machineWidth / 2, 0, machineDepth / 2);
        glVertex3f(-machineWidth / 2, machineHeight, machineDepth / 2);
        glVertex3f(-machineWidth / 2, machineHeight, -machineDepth / 2);

        glVertex3f(machineWidth / 2, 0, -machineDepth / 2);
        glVertex3f(machineWidth / 2, 0, machineDepth / 2);
        glVertex3f(machineWidth / 2, machineHeight, machineDepth / 2);
        glVertex3f(machineWidth / 2, machineHeight, -machineDepth / 2);

        // «·”ﬁ› Ê«·ﬁ«⁄œ…
        glVertex3f(-machineWidth / 2, 0, -machineDepth / 2);
        glVertex3f(machineWidth / 2, 0, -machineDepth / 2);
        glVertex3f(machineWidth / 2, 0, machineDepth / 2);
        glVertex3f(-machineWidth / 2, 0, machineDepth / 2);

        glVertex3f(-machineWidth / 2, machineHeight, -machineDepth / 2);
        glVertex3f(machineWidth / 2, machineHeight, -machineDepth / 2);
        glVertex3f(machineWidth / 2, machineHeight, machineDepth / 2);
        glVertex3f(-machineWidth / 2, machineHeight, machineDepth / 2);

        glEnd();



        glPopMatrix();
    }
    static void drawCeilingFanWithArm(float x, float y, float z, float angleX, float angleY, float angleZ, float fanRotation) {
        glPushMatrix();
        float scale = 4;
        glTranslatef(x, y, z);
        glRotatef(angleX, 1.0f, 0.0f, 0.0f); 
        glRotatef(angleY, 0.0f, 1.0f, 0.0f); 
        glRotatef(angleZ, 0.0f, 0.0f, 1.0f); 
        glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); 

      
        glColor3f(0.5f, 0.5f, 0.5f); 
        GLUquadric* quadric = gluNewQuadric(); 

        glPushMatrix();
        glTranslatef(0.0f, 0.0f, 40.0f * scale); 
        gluCylinder(quadric, 2.0f * scale, 2.0f * scale, 40.0f * scale, 10, 10); 
        glPopMatrix();

       
        glPushMatrix();
        glTranslatef(0.0f, 0.0f, 40.0f * scale); 
        glRotatef(fanRotation, 0.0f, 0.0f, 1.0f);
        glBegin(GL_QUADS); 
        glVertex3f(-2.0f * scale, -2.0f * scale, -2.0f * scale);
        glVertex3f(2.0f * scale, -2.0f * scale, -2.0f * scale);
        glVertex3f(2.0f * scale, 2.0f * scale, -2.0f * scale);
        glVertex3f(-2.0f * scale, 2.0f * scale, -2.0f * scale);
        glEnd();
        glPopMatrix();

        // —”„ «·‘›—«  
        glColor3f(0.8f, 0.8f, 0.8f); 
        float bladeLength = 40.0f * scale; 
        float bladeWidth = 8.0f * scale; 

        for (int i = 0; i < 4; ++i) {
            glPushMatrix();
            glTranslatef(0.0f, 0.0f, 40.0f * scale); 
            glRotatef(fanRotation + i * 90.0f, 0.0f, 0.0f, 1.0f); 

            // —”„ «·‘›—«  ﬂ„” ÿÌ·«  „⁄  ﬂ»Ì—
            glBegin(GL_QUADS);
            glVertex3f(-bladeWidth / 2.0f, -bladeLength / 2.0f, 0.0f); // “«ÊÌ… √”›· «·‘›—…
            glVertex3f(bladeWidth / 2.0f, -bladeLength / 2.0f, 0.0f); // “«ÊÌ… √”›· «·‘›—…
            glVertex3f(bladeWidth / 2.0f, bladeLength / 2.0f, 0.0f); // “«ÊÌ… √⁄·Ï «·‘›—…
            glVertex3f(-bladeWidth / 2.0f, bladeLength / 2.0f, 0.0f); // “«ÊÌ… √⁄·Ï «·‘›—…
            glEnd();

            glPopMatrix();
        }

        glPopMatrix();
    }
    void drawFloorFan(float x, float y, float z, float rotationX, float rotationY, float rotationZ, float fanRotation,float r,float g,float b) {
        glPushMatrix();
        float scale = 300.0f;

   
        glColor3f(r, g, b);
        glTranslatef(x, y, z);

        glRotatef(rotationX, 1.0f, 0.0f, 0.0f); 
        glRotatef(rotationY, 0.0f, 1.0f, 0.0f); 
        glRotatef(rotationZ, 0.0f, 0.0f, 1.0f); 

        glPushMatrix();
        glRotatef(270, 1, 0, 0);
        glTranslatef(0.0f, 0.0f, 0.05f * scale); 
        glBegin(GL_POLYGON);
        int numSegments = 100; 
        for (int i = 0; i < numSegments; ++i) {
            float theta = 2.0f * 3.1415926f * float(i) / float(numSegments); 
            float dx = 0.2f * scale * cosf(theta); 
            float dy = 0.2f * scale * sinf(theta); 
            glVertex3f(dx, dy, -5);
        }
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glRotatef(270, 1, 0, 0);

        // —”„ «·⁄„Êœ
        glPushMatrix();
        GLUquadric* standQuad = gluNewQuadric();
        glTranslatef(0.0f, 0.1f * scale, 0.0f); 
        gluCylinder(standQuad, 0.05f * scale, 0.05f * scale, 0.5f * scale, 32, 32); 
        gluDeleteQuadric(standQuad);
        glPopMatrix();

       
        glPushMatrix();
        glTranslatef(0.0f, 0.1f * scale, 60*3); 
        glutSolidSphere(0.1f * scale, 100, 32); // —”„ ﬂ—…
        glPopMatrix();

        glPopMatrix();

        // —”„ «·‘›—« 
        glPushMatrix();
        glColor3f(0, 0, 0);
        glTranslatef(0.0f, 0.6f * scale, 0.0f); 
        for (int i = 0; i < 3; ++i) {
            glPushMatrix();
            glRotatef(fanRotation + i * 120.0f, 0.0f, 0.0f, 1.0f);
            glTranslatef(0.2f * scale, 0.0f, 0.0f); 
            glScalef(0.4f * scale/2, 0.05f * scale/2, 0.1f * scale/2); 
            glutSolidCube(1.0f); 
            glPopMatrix();
        }
        glPopMatrix();

        // —”„ «·‘»ﬂ «·ﬂ—ÊÌ ÕÊ· «·‘›—« 
        glPushMatrix();
        glTranslatef(0.0f, 0.6f * scale, 0.0f); 
        GLUquadric* meshQuad = gluNewQuadric();
        gluQuadricDrawStyle(meshQuad, GLU_LINE); 
        gluSphere(meshQuad, 0.3f * scale, 32, 32); 
        gluDeleteQuadric(meshQuad);
        glPopMatrix();

        glPopMatrix();
    }
    static void drawbrada(float x, float y, float z, float angleX, float angleY, float angleZ, int brada, float r, float g, float b) {
        float fridgeWidth = 125.0f;
        float fridgeHeight = 300.0f;
        float fridgeDepth = 100.0f;
        float doorThickness = 0.5f;

        glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(angleX, 1.0f, 0.0f, 0.0f);
        glRotatef(angleY, 0.0f, 1.0f, 0.0f);
        glRotatef(angleZ, 0.0f, 0.0f, 1.0f);


        // —”„ Ã”„ «·»—«œ

        glBindTexture(GL_TEXTURE_2D, brada);
        glColor3f(0.9f, 0.9f, 0.9f); 
        glBegin(GL_QUADS);

        // ÊÃÂ √„«„Ì

        glTexCoord2f(0, 0);
        glVertex3f(-fridgeWidth / 2, 0, fridgeDepth / 2);
        glTexCoord2f(1, 0);

        glVertex3f(fridgeWidth / 2, 0, fridgeDepth / 2);
        glTexCoord2f(1, 1);

        glVertex3f(fridgeWidth / 2, fridgeHeight, fridgeDepth / 2);
        glTexCoord2f(0, 1);
        glVertex3f(-fridgeWidth / 2, fridgeHeight, fridgeDepth / 2);

        glEnd();

        glColor3f(r, g, b);
        glBegin(GL_QUADS);
        // ÊÃÂ Œ·›Ì
        glVertex3f(-fridgeWidth / 2, 0, -fridgeDepth / 2);
        glVertex3f(fridgeWidth / 2, 0, -fridgeDepth / 2);
        glVertex3f(fridgeWidth / 2, fridgeHeight, -fridgeDepth / 2);
        glVertex3f(-fridgeWidth / 2, fridgeHeight, -fridgeDepth / 2);

        // «·ÕÊ«› «·Ã«‰»Ì…
        glVertex3f(-fridgeWidth / 2, 0, -fridgeDepth / 2);
        glVertex3f(-fridgeWidth / 2, 0, fridgeDepth / 2);
        glVertex3f(-fridgeWidth / 2, fridgeHeight, fridgeDepth / 2);
        glVertex3f(-fridgeWidth / 2, fridgeHeight, -fridgeDepth / 2);

        glVertex3f(fridgeWidth / 2, 0, -fridgeDepth / 2);
        glVertex3f(fridgeWidth / 2, 0, fridgeDepth / 2);
        glVertex3f(fridgeWidth / 2, fridgeHeight, fridgeDepth / 2);
        glVertex3f(fridgeWidth / 2, fridgeHeight, -fridgeDepth / 2);

        // «·”ﬁ› Ê«·ﬁ«⁄œ…
        glVertex3f(-fridgeWidth / 2, 0, -fridgeDepth / 2);
        glVertex3f(fridgeWidth / 2, 0, -fridgeDepth / 2);
        glVertex3f(fridgeWidth / 2, 0, fridgeDepth / 2);
        glVertex3f(-fridgeWidth / 2, 0, fridgeDepth / 2);

        glVertex3f(-fridgeWidth / 2, fridgeHeight, -fridgeDepth / 2);
        glVertex3f(fridgeWidth / 2, fridgeHeight, -fridgeDepth / 2);
        glVertex3f(fridgeWidth / 2, fridgeHeight, fridgeDepth / 2);
        glVertex3f(-fridgeWidth / 2, fridgeHeight, fridgeDepth / 2);

        glEnd();

        glPopMatrix();
    }

};


