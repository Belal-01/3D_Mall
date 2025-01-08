
#include <GL/glut.h>
#include <iostream>
#include <cstdlib> // · ÷„Ì‰ rand Ê srand
#include <ctime>   // · ÷„Ì‰ time
#include <random>


class ElectronicDeviceDrawer {

public:


  
    static void drawFridge(float x, float y, float z, float angleX, float angleY, float angleZ) {
        float fridgeWidth = 40.0f;
        float fridgeHeight = 100.0f;
        float fridgeDepth = 40.0f;
        float doorThickness = 0.5f;

        glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(angleX, 1.0f, 0.0f, 0.0f);
        glRotatef(angleY, 0.0f, 1.0f, 0.0f);
        glRotatef(angleZ, 0.0f, 0.0f, 1.0f);

        // —”„ Œÿ ›«’· · ﬁ”Ì„ «·»—«œ ≈·Ï »«»Ì‰
        glColor3f(0.0f, 0.0f, 0.0f); // ·Ê‰ «·Œÿ «·√”Êœ
        glBegin(GL_LINES);
        glVertex3f(-fridgeWidth / 2, 70, fridgeDepth / 2);
        glVertex3f(fridgeWidth / 2, 70, fridgeDepth / 2);
        glEnd();

        // —”„ «·„ﬁ«»÷
        glColor3f(0.7f, 0.7f, 0.7f); // ·Ê‰ «·„ﬁ«»÷ (—„«œÌ ›« Õ)
        glBegin(GL_QUADS);
        glVertex3f(-15, 40, fridgeDepth / 2 + 0.1f);
        glVertex3f(-12, 40, fridgeDepth / 2 + 0.1f);
        glVertex3f(-12, 50, fridgeDepth / 2 + 0.1f);
        glVertex3f(-15, 50, fridgeDepth / 2 + 0.1f);
        glVertex3f(-15, 80, fridgeDepth / 2 + 0.1f);
        glVertex3f(-12, 80, fridgeDepth / 2 + 0.1f);
        glVertex3f(-12, 90, fridgeDepth / 2 + 0.1f);
        glVertex3f(-15, 90, fridgeDepth / 2 + 0.1f);
        glEnd();

        // —”„ Ã”„ «·»—«œ
        glColor3f(0.9f, 0.9f, 0.9f); // ·Ê‰ «·»—«œ (√»Ì÷ √Ê —„«œÌ ›« Õ)
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


    static void drawAirConditioner(float x, float y, float z, float angleX, float angleY, float angleZ) {
        glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(angleX, 10.0f, 0.0f, 0.0f); // œÊ—«‰ ÕÊ· «·„ÕÊ— X
        glRotatef(angleY, 0.0f, 10.0f, 0.0f); // œÊ—«‰ ÕÊ· «·„ÕÊ— Y
        glRotatef(angleZ, 0.0f, 0.0f, 10.0f); // œÊ—«‰ ÕÊ· «·„ÕÊ— Z

        glColor3f(0.8f, 0.8f, 0.8f); // ·Ê‰ «·„ﬂÌ›
        glBegin(GL_QUADS);

        // «·ÃÊ«‰» «·√—»⁄… ··„ﬂÌ› („ﬂ⁄»)
        glVertex3f(0, 0, 0);
        glVertex3f(40.0f, 0, 0);
        glVertex3f(40.0f, 20.0f, 0);
        glVertex3f(0, 20.0f, 0);

        glVertex3f(0, 0, 0);
        glVertex3f(0, 20.0f, 0);
        glVertex3f(0, 20.0f, -10.0f);
        glVertex3f(0, 0, -10.0f);

        glVertex3f(40.0f, 0, 0);
        glVertex3f(40.0f, 20.0f, 0);
        glVertex3f(40.0f, 20.0f, -10.0f);
        glVertex3f(40.0f, 0, -10.0f);

        glVertex3f(0, 20.0f, 0);
        glVertex3f(40.0f, 20.0f, 0);
        glVertex3f(40.0f, 20.0f, -10.0f);
        glVertex3f(0, 20.0f, -10.0f);

        glVertex3f(0, 0, -10.0f);
        glVertex3f(40.0f, 0, -10.0f);
        glVertex3f(40.0f, 0, 0);
        glVertex3f(0, 0, 0);

        glEnd();

        //  ›«’Ì· ≈÷«›Ì… („À· «·√‰«»Ì»)
        glLineWidth(3.0f);
        glColor3f(0.3f, 0.3f, 0.3f);
        glBegin(GL_LINES);
        glVertex3f(0, 10.0f, 0);
        glVertex3f(40.0f, 10.0f, 0); // √‰»Ê» ›Ì «·√⁄·Ï
        glEnd();
        glLineWidth(3.0f);
        glColor3f(0.3f, 0.3f, 0.3f);
        glBegin(GL_LINES);
        glVertex3f(0, 10.0f, -10.0f);
        glVertex3f(40.0f, 10.0f, -10.0f); // √‰»Ê» ›Ì «·√”›·
        glEnd();

        glPopMatrix();
    }
    static void drawAirConditionerWithFan(float x, float y, float z, float angleX, float angleY, float angleZ, float fanRotation) {
        glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(angleX, 10.0f, 0.0f, 0.0f); // œÊ—«‰ ÕÊ· «·„ÕÊ— X
        glRotatef(angleY, 0.0f, 10.0f, 0.0f); // œÊ—«‰ ÕÊ· «·„ÕÊ— Y
        glRotatef(angleZ, 0.0f, 0.0f, 10.0f); // œÊ—«‰ ÕÊ· «·„ÕÊ— Z

        // —”„ ÂÌﬂ· «·„ﬂÌ›
        glColor3f(0.8f, 0.8f, 0.8f); // ·Ê‰ «·„ﬂÌ›
        glBegin(GL_QUADS);

        // «·ÃÊ«‰» «·√—»⁄… ··„ﬂÌ› („ﬂ⁄» „’€—)
        glVertex3f(0, 0, 0);
        glVertex3f(80.0f, 0, 0);
        glVertex3f(80.0f, 40.0f, 0);
        glVertex3f(0, 40.0f, 0);

        glVertex3f(0, 0, 0);
        glVertex3f(0, 40.0f, 0);
        glVertex3f(0, 40.0f, -20.0f);
        glVertex3f(0, 0, -20.0f);

        glVertex3f(80.0f, 0, 0);
        glVertex3f(80.0f, 40.0f, 0);
        glVertex3f(80.0f, 40.0f, -20.0f);
        glVertex3f(80.0f, 0, -20.0f);

        glVertex3f(0, 40.0f, 0);
        glVertex3f(80.0f, 40.0f, 0);
        glVertex3f(80.0f, 40.0f, -20.0f);
        glVertex3f(0, 40.0f, -20.0f);

        glVertex3f(0, 0, -20.0f);
        glVertex3f(80.0f, 0, -20.0f);
        glVertex3f(80.0f, 0, 0);
        glVertex3f(0, 0, 0);

        glEnd();

        glColor3f(0.8f, 0.8f, 0.8f); // ‰›” ·Ê‰ «·„ﬂÌ›
        glBegin(GL_QUADS);
        glVertex3f(20.0f, 20.0f, -0.1f);  // “«ÊÌ… «·√”›· «·Ì”—Ï
        glVertex3f(60.0f, 20.0f, -0.1f);  // “«ÊÌ… «·√”›· «·Ì„‰Ï
        glVertex3f(60.0f, 20.0f, -1.0f);  // “«ÊÌ… «·√⁄·Ï «·Ì„‰Ï
        glVertex3f(20.0f, 20.0f, -1.0f);  // “«ÊÌ… «·√⁄·Ï «·Ì”—Ï
        glEnd();

        //  €ÿÌ… «·› Õ… «·√„«„Ì… ··„ﬂÌ› »‘»ﬂ „ ﬁ«ÿ⁄
        glColor3f(0.0f, 0.0f, 0.0f); // ‰›” ·Ê‰ «·„ﬂÌ›

        glBegin(GL_LINES);
        for (float y = 0; y < 40; y++) {
            glVertex3f(0.1, y, -20);
            glVertex3f(80 - 0.1, y, -20);
        }
        for (float x = 0; x < 80; x += 2) {
            glVertex3f(x, 40 - 0.1, -20);
            glVertex3f(x, 0.1, -20);
        }
        glEnd();
        // —”„ › Õ«  «· ÂÊÌ…
        glLineWidth(3.0f);
        glColor3f(0.3f, 0.3f, 0.3f);
        glBegin(GL_LINES);

        // › Õ«  «· ÂÊÌ… ›Ì «·√⁄·Ï
        for (float i = 10.0f; i < 80.0f; i += 16.0f) {
            glVertex3f(i - 8, 40.0f, 0);
            glVertex3f(i, 40.0f, 0); // › Õ«  «· ÂÊÌ… ›Ì «·√⁄·Ï
        }

        // › Õ«  «· ÂÊÌ… ›Ì «·√”›·
        for (float i = 10.0f; i < 80.0f; i += 16.0f) {
            glVertex3f(i - 8, 40.0f, -20.0f);
            glVertex3f(i, 40.0f, -20.0f); // › Õ«  «· ÂÊÌ… ›Ì «·√”›·
        }

        glEnd();

        // —”„ «·‘»ﬂ «·√„«„Ì ··„—ÊÕ…
        glColor3f(0.2f, 0.2f, 0.2f); // ·Ê‰ «·‘»ﬂ
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < 360; i += 3) {
            float angle = i * 3.14159f / 180.0f;
            glVertex3f(40.0f + 20.0f * cos(angle), 20.0f + 20.0f * sin(angle), -0.1f);
        }
        glEnd();

        // —”„ «·„—ÊÕ…
        glColor3f(0.5f, 0.5f, 0.5f); // ·Ê‰ «·„—ÊÕ…
        float fanRadius = 16.0f;  // ‰’› «·ﬁÿ— «·„’€—

        // —”„ «·‘›—«  «·À·«À ··„—ÊÕ…
        for (int i = 0; i < 3; ++i) {
            glPushMatrix();
            glTranslatef(40.0f, 20.0f, -1.0f); //  Õ—Ìﬂ «·‰Ÿ«„ ≈·Ï „—ﬂ“ «·„—ÊÕ…
            glRotatef(fanRotation + i * 120.0f, 0.0f, 0.0f, 1.0f); // «· œÊÌ— ÕÊ· «·„ÕÊ— Z
            glTranslatef(-40.0f, -20.0f, 1.0f); // ≈⁄«œ… «·‰Ÿ«„ ≈·Ï „ﬂ«‰Â «·√’·Ì

            glColor3f(0.5f, 0.5f, 0.5f); // ·Ê‰ «·„—ÊÕ…
            glBegin(GL_TRIANGLES);
            glVertex3f(40.0f, 20.0f, -1.0f); // „—ﬂ“ «·„—ÊÕ…
            glVertex3f(40.0f + fanRadius * cos(0), 20.0f + fanRadius * sin(0), -1.0f); // ‰ﬁÿ… ⁄·Ï «·Õ«›…
            glVertex3f(40.0f + fanRadius * cos(60.0f * 3.14159f / 180.0f), 20.0f + fanRadius * sin(60.0f * 3.14159f / 180.0f), -1.0f);
            glEnd();

            glPopMatrix();
        }

        glPopMatrix();
    }
    static void drawfireplace(float x, float y, float z, float angleX, float angleY, float angleZ) {
        glPushMatrix();
        glTranslatef(x, y, z);
        glColor3f(0.5f, 0.5f, 0.5f);
        glColor3f(0.8f, 0.8f, 0.8f);
        glBegin(GL_QUADS);

        glVertex3f(0, 0, 0);
        glVertex3f(80.0f, 0, 0);
        glVertex3f(80.0f, 40.0f, 0);
        glVertex3f(0, 40.0f, 0);

        glVertex3f(0, 0, 0);
        glVertex3f(0, 40.0f, 0);
        glVertex3f(0, 40.0f, -20.0f);
        glVertex3f(0, 0, -20.0f);

        glVertex3f(80.0f, 0, 0);
        glVertex3f(80.0f, 40.0f, 0);
        glVertex3f(80.0f, 40.0f, -20.0f);
        glVertex3f(80.0f, 0, -20.0f);

        glVertex3f(0, 40.0f, 0);
        glVertex3f(80.0f, 40.0f, 0);
        glVertex3f(80.0f, 40.0f, -20.0f);
        glVertex3f(0, 40.0f, -20.0f);

        glVertex3f(0, 0, -20.0f);
        glVertex3f(80.0f, 0, -20.0f);
        glVertex3f(80.0f, 0, 0);
        glVertex3f(0, 0, 0);

        glEnd();

        glColor3f(0.8f, 0.8f, 0.8f);
        glBegin(GL_QUADS);
        glVertex3f(20.0f, 20.0f, -0.1f);
        glVertex3f(60.0f, 20.0f, -0.1f);
        glVertex3f(60.0f, 20.0f, -1.0f);
        glVertex3f(20.0f, 20.0f, -1.0f);
        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
        for (float y = 0; y < 40; y += 3) {
            glVertex3f(0.1, y, -20);
            glVertex3f(80 - 0.1, y, -20);
        }
        glEnd();

        // —”„ 3 √”ÿÊ«‰«  Õ„—«¡  „ œ ⁄·Ï „ÕÊ— x
        glColor3f(1.0f, 0.0f, 0.0f);  // «··Ê‰ «·√Õ„—
        GLUquadricObj* quadric = gluNewQuadric(); // ﬂ«∆‰ —»«⁄Ì · ÕœÌœ «·√”ÿÊ«‰…

        // «·√”ÿÊ«‰… «·√Ê·Ï ⁄‰œ y = 10
        glPushMatrix();
        glTranslatef(2.0f, 10.0f, -10.0f); // Ê÷⁄ «·√”ÿÊ«‰…
        glRotatef(90, 0.0f, 1.0f, 0.0f); //  œÊÌ— «·√”ÿÊ«‰… · ﬂÊ‰ ⁄·Ï „ÕÊ— x
        gluCylinder(quadric, 2.0f, 2.0f, 75.0f, 32, 32); // —”„ «·√”ÿÊ«‰…
        glPopMatrix();

        // «·√”ÿÊ«‰… «·À«‰Ì… ⁄‰œ y = 20
        glPushMatrix();
        glTranslatef(2.0f, 20.0f, -10.0f); // Ê÷⁄ «·√”ÿÊ«‰…
        glRotatef(90, 0.0f, 1.0f, 0.0f); //  œÊÌ— «·√”ÿÊ«‰… · ﬂÊ‰ ⁄·Ï „ÕÊ— x
        gluCylinder(quadric, 2.0f, 2.0f, 75.0f, 32, 32); // —”„ «·√”ÿÊ«‰…
        glPopMatrix();

        // «·√”ÿÊ«‰… «·À«·À… ⁄‰œ y = 30
        glPushMatrix();
        glTranslatef(2.0f, 30.0f, -10.0f); // Ê÷⁄ «·√”ÿÊ«‰…
        glRotatef(90, 0.0f, 1.0f, 0.0f); //  œÊÌ— «·√”ÿÊ«‰… · ﬂÊ‰ ⁄·Ï „ÕÊ— x
        gluCylinder(quadric, 2.0f, 2.0f, 75.0f, 32, 32); // —”„ «·√”ÿÊ«‰…
        glPopMatrix();

        gluDeleteQuadric(quadric); // Õ–› ﬂ«∆‰ «·—»«⁄Ì
        glPopMatrix();
    }
    static void drawWashingMachine(float x, float y, float z, float angleX, float angleY, float angleZ,int wash) {
        float machineWidth = 50.0f;
        float machineHeight = 80.0f;
        float machineDepth = 50.0f;
        float doorRadius = 20.0f;
        float doorThickness = 1.0f;

        glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(angleX, 1.0f, 0.0f, 0.0f);
        glRotatef(angleY, 0.0f, 1.0f, 0.0f);
        glRotatef(angleZ, 0.0f, 0.0f, 1.0f);
        glBindTexture(GL_TEXTURE_2D, wash);
        // —”„ Ã”„ «·€”«·…
        glColor3f(0.5, 0.5, 0.5); // ·Ê‰ «·€”«·… (√»Ì÷ √Ê —„«œÌ ›« Õ)
        
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
        glColor3f(0.1, 0.1, 0.1); // ·Ê‰ «·€”«·… (√»Ì÷ √Ê —„«œÌ ›« Õ)

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

    // —”„ «·‘«‘…
    static void drawCeilingFanWithArm(float x, float y, float z, float angleX, float angleY, float angleZ, float fanRotation) {
        glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(angleX, 10.0f, 0.0f, 0.0f); // œÊ—«‰ ÕÊ· «·„ÕÊ— X
        glRotatef(angleY, 0.0f, 10.0f, 0.0f); // œÊ—«‰ ÕÊ· «·„ÕÊ— Y
        glRotatef(angleZ, 0.0f, 0.0f, 10.0f); // œÊ—«‰ ÕÊ· «·„ÕÊ— Z

        //  ÊÃÌÂ «·„—ÊÕ… ··√”›· (œÊ—«‰ ÕÊ· «·„ÕÊ— X)
        glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // œÊ—«‰ 90 œ—Ã… ÕÊ· «·„ÕÊ— X ·Ã⁄· «·„—ÊÕ… „ÊÃÂ… ··√”›·

        // —”„ «·–—«⁄ «·√”ÿÊ«‰Ì… «· Ì  ⁄·ﬁ «·„—ÊÕ…
        glColor3f(0.5f, 0.5f, 0.5f); // ·Ê‰ «·–—«⁄ (√Ê œ⁄„ «·„—ÊÕ…)
        GLUquadric* quadric = gluNewQuadric(); // ≈‰‘«¡ ﬂ«∆‰ ·√”ÿÊ«‰…

        glPushMatrix();
        glTranslatef(0.0f, 0.0f, 40.0f); //  Õ—Ìﬂ «·–—«⁄ ≈·Ï √⁄·Ï Õ Ï Ì’· „—ﬂ“Â« ≈·Ï «·”ﬁ›
        gluCylinder(quadric, 2.0f, 2.0f, 40.0f, 10, 10); // —”„ «·√”ÿÊ«‰… (–—«⁄ «·„—ÊÕ…)
        glPopMatrix();

        // —”„ «·„ÕÊ— «·„—ﬂ“Ì ··„—ÊÕ…
        glPushMatrix();
        glTranslatef(0.0f, 0.0f, 40.0f); //  Õ—Ìﬂ «·„ÕÊ— ≈·Ï √⁄·Ï »ÕÌÀ Ì ’· »«·–—«⁄
        glRotatef(fanRotation, 0.0f, 0.0f, 1.0f); //  œÊÌ— «·„ÕÊ— „⁄ «·„—ÊÕ…
        glBegin(GL_QUADS); // —”„ «·„ÕÊ— ﬂ„ﬂ⁄» ’€Ì—
        glVertex3f(-2.0f, -2.0f, -2.0f);
        glVertex3f(2.0f, -2.0f, -2.0f);
        glVertex3f(2.0f, 2.0f, -2.0f);
        glVertex3f(-2.0f, 2.0f, -2.0f);
        glEnd();
        glPopMatrix();

        // —”„ «·‘›—«  «·„” ÿÌ·… ··„—ÊÕ…
        glColor3f(0.8f, 0.8f, 0.8f); // ·Ê‰ «·‘›—« 
        float bladeLength = 40.0f; // ÿÊ· «·‘›—… ( „ “Ì«œ Â)
        float bladeWidth = 8.0f; // ⁄—÷ «·‘›—… ( „ “Ì«œ Â)

        for (int i = 0; i < 4; ++i) {
            glPushMatrix();
            glTranslatef(0.0f, 0.0f, 40.0f); //  Õ—Ìﬂ «·‰Ÿ«„ ≈·Ï „—ﬂ“ «·„—ÊÕ…
            glRotatef(fanRotation + i * 90.0f, 0.0f, 0.0f, 1.0f); // «· œÊÌ— ÕÊ· «·„ÕÊ— Z

            // —”„ «·‘›—«  ﬂ„” ÿÌ·« 
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
};


