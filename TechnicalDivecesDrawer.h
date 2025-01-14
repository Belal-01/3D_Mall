#pragma once
#include <GL/glut.h>
#include <iostream>
#include <cstdlib> // · ÷„Ì‰ rand Ê srand
#include <ctime>   // · ÷„Ì‰ time
#include <random>

class TechnicalDivecesDrawer
{
public :
    void drawComputerMonitor(float x, float y, float z, float angleX, float angleY, float angleZ) {
        // «·√»⁄«œ «·À«» … ··‘«‘… Ê«·ﬁ«⁄œ…
        float width = 50.0f*4;
        float height = 30.0f*4;
        float screenThickness = 1.0f*4; // ”„ﬂ «·‘«‘…
        float baseWidth = 40.0f*4; //  ’€Ì— «·ﬁ«⁄œ…
        float baseDepth = 15.0f*4; //  ’€Ì— ⁄„ﬁ «·ﬁ«⁄œ…
        float connectorHeight = 4*1.5f; //  ﬁ·Ì’ ”„ﬂ «·Ê’·… ·ÌﬂÊ‰ √ﬁ· „‰ ”„ﬂ «·‘«‘…
        float buttonWidth = 3.0f*4; // ⁄—÷ «·“—
        float buttonHeight = 1.0f*4; // «— ›«⁄ «·“—

        glPushMatrix();
        glTranslatef(x, y, z);

        //  ÿ»Ìﬁ «·œÊ—«‰
        glRotatef(angleX, 1.0f, 0.0f, 0.0f); // œÊ—«‰ ÕÊ· «·„ÕÊ— X
        glRotatef(angleY, 0.0f, 1.0f, 0.0f); // œÊ—«‰ ÕÊ· «·„ÕÊ— Y
        glRotatef(angleZ, 0.0f, 0.0f, 1.0f); // œÊ—«‰ ÕÊ· «·„ÕÊ— Z

        // —”„ «·‘«‘… „⁄ «·”„ﬂ «·ÃœÌœ
        glColor3f(0.0f, 0.0f, 0.0f); // ·Ê‰ «·‘«‘…
        glBegin(GL_QUADS);
        // Ê«ÃÂ… «·‘«‘…
        glVertex3f(-width / 2, height, 0);
        glVertex3f(width / 2, height, 0);
        glVertex3f(width / 2, 0, 0);
        glVertex3f(-width / 2, 0, 0);

        // «·”„ﬂ «·Œ·›Ì ··‘«‘…
        glVertex3f(-width / 2, height, screenThickness);
        glVertex3f(width / 2, height, screenThickness);
        glVertex3f(width / 2, 0, screenThickness);
        glVertex3f(-width / 2, 0, screenThickness);

        // ÃÊ«‰» «·‘«‘…
        glVertex3f(-width / 2, height, 0);
        glVertex3f(-width / 2, height, screenThickness);
        glVertex3f(-width / 2, 0, screenThickness);
        glVertex3f(-width / 2, 0, 0);

        glVertex3f(width / 2, height, 0);
        glVertex3f(width / 2, height, screenThickness);
        glVertex3f(width / 2, 0, screenThickness);
        glVertex3f(width / 2, 0, 0);

        glVertex3f(-width / 2, height, screenThickness);
        glVertex3f(width / 2, height, screenThickness);
        glVertex3f(width / 2, height, 0);
        glVertex3f(-width / 2, height, 0);

        glVertex3f(-width / 2, 0, screenThickness);
        glVertex3f(width / 2, 0, screenThickness);
        glVertex3f(width / 2, 0, 0);
        glVertex3f(-width / 2, 0, 0);
        glEnd();

        // —”„ «·ﬁ«⁄œ…
        glColor3f(0.2f, 0.2f, 0.2f); // ·Ê‰ «·ﬁ«⁄œ…
        glBegin(GL_QUADS);
        glVertex3f(-baseWidth / 2, -connectorHeight, -baseDepth / 2);
        glVertex3f(baseWidth / 2, -connectorHeight, -baseDepth / 2);
        glVertex3f(baseWidth / 2, -connectorHeight, baseDepth / 2);
        glVertex3f(-baseWidth / 2, -connectorHeight, baseDepth / 2);
        glEnd();

        // —”„ «·„Ê’· («·„” ÿÌ· «·⁄„ÊœÌ) „⁄ ”„ﬂ √ﬁ·
        glColor3f(0.4f, 0.4f, 0.4f); // ·Ê‰ «·„Ê’·
        glBegin(GL_QUADS);
        // ÊÃÂ √„«„Ì
        glVertex3f(-baseWidth / 12, 0, -baseDepth / 12);
        glVertex3f(baseWidth / 12, 0, -baseDepth / 12);
        glVertex3f(baseWidth / 12, -connectorHeight, -baseDepth / 12);
        glVertex3f(-baseWidth / 12, -connectorHeight, -baseDepth / 12);

        // ÊÃÂ Œ·›Ì
        glVertex3f(-baseWidth / 12, 0, baseDepth / 12);
        glVertex3f(baseWidth / 12, 0, baseDepth / 12);
        glVertex3f(baseWidth / 12, -connectorHeight, baseDepth / 12);
        glVertex3f(-baseWidth / 12, -connectorHeight, baseDepth / 12);

        // ÊÃÂ Ã«‰»Ì (Ì”«—)
        glVertex3f(-baseWidth / 12, 0, -baseDepth / 12);
        glVertex3f(-baseWidth / 12, 0, baseDepth / 12);
        glVertex3f(-baseWidth / 12, -connectorHeight, baseDepth / 12);
        glVertex3f(-baseWidth / 12, -connectorHeight, -baseDepth / 12);

        // ÊÃÂ Ã«‰»Ì (Ì„Ì‰)
        glVertex3f(baseWidth / 12, 0, -baseDepth / 12);
        glVertex3f(baseWidth / 12, 0, baseDepth / 12);
        glVertex3f(baseWidth / 12, -connectorHeight, baseDepth / 12);
        glVertex3f(baseWidth / 12, -connectorHeight, -baseDepth / 12);
        glEnd();

        // —”„ “— «· ‘€Ì· (—›⁄ «·“— Ê €ÌÌ— ·Ê‰Â ≈·Ï «·√Õ„—)
        glColor3f(1.0f, 0.0f, 0.0f); // ·Ê‰ «·“— √Õ„—
        glBegin(GL_QUADS);
        // —›⁄ «·“— ﬁ·Ì·« ÊÃ⁄·Â √Õ„—
        glVertex3f(22, -connectorHeight + 10.0f, -0.1); //  ⁄œÌ· «— ›«⁄ «·“—
        glVertex3f(25, -connectorHeight + 10.0f, -0.1); //  ⁄œÌ· «— ›«⁄ «·“—
        glVertex3f(25, -connectorHeight + buttonHeight + 10.0f, -0.1); //  ⁄œÌ· «— ›«⁄ «·“—
        glVertex3f(22, -connectorHeight + buttonHeight + 10.0f, -0.1); //  ⁄œÌ· «— ›«⁄ «·“—
        glEnd();

        glPopMatrix();

    }
    static void drawScreen(float x, float y, float z, float angleX, float angleY, float angleZ) {
        glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(angleX, 10.0f, 0.0f, 0.0f); // œÊ—«‰ ÕÊ· «·„ÕÊ— X
        glRotatef(angleY, 0.0f, 10.0f, 0.0f); // œÊ—«‰ ÕÊ· «·„ÕÊ— Y
        glRotatef(angleZ, 0.0f, 0.0f, 10.0f); // œÊ—«‰ ÕÊ· «·„ÕÊ— Z

        glColor3f(0.0f, 0.0f, 0.0f); // ·Ê‰ «·‘«‘…
        glBegin(GL_QUADS);

        // «·‘«‘…
        glVertex3f(0, 0, 0);
        glVertex3f(60.0f, 0, 0);
        glVertex3f(60.0f, 40.0f, 0);
        glVertex3f(0, 40.0f, 0);

        glEnd();

        // «·ÕÊ«›
        glColor3f(0.2f, 0.2f, 0.2f);
        glBegin(GL_LINE_LOOP);

        glVertex3f(0, 0, 0);
        glVertex3f(60.0f, 0, 0);
        glVertex3f(60.0f, 40.0f, 0);
        glVertex3f(0, 40.0f, 0);

        glEnd();
        glPopMatrix();
    }
    void drawPS5(float x, float y, float z, float angleX, float angleY, float angleZ) {
        // √»⁄«œ PS5
        float bodyWidth = 10.0f;
        float bodyHeight = 30.0f;
        float bodyDepth = 5.0f;
        float wingWidth = 12.0f;
        float wingHeight = 30.0f;
        float wingDepth = 0.5f;
        float wingOffset = 2.0f; // «·„”«›… »Ì‰ «·Ã”„ Ê«·√Ã‰Õ…

        glPushMatrix();
        glTranslatef(x, y, z);

        //  ÿ»Ìﬁ «·œÊ—«‰
        glRotatef(angleX, 1.0f, 0.0f, 0.0f); // œÊ—«‰ ÕÊ· «·„ÕÊ— X
        glRotatef(angleY, 0.0f, 1.0f, 0.0f); // œÊ—«‰ ÕÊ· «·„ÕÊ— Y
        glRotatef(angleZ, 0.0f, 0.0f, 1.0f); // œÊ—«‰ ÕÊ· «·„ÕÊ— Z

        // —”„ «·Ã”„ «·—∆Ì”Ì
        glColor3f(0.1f, 0.1f, 0.1f); // ·Ê‰ «·Ã”„ «·—∆Ì”Ì (√”Êœ)
        glBegin(GL_QUADS);
        // ÊÃÂ √„«„Ì
        glVertex3f(-bodyWidth / 2, 0, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, 0, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, bodyHeight, -bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, bodyHeight, -bodyDepth / 2);

        // ÊÃÂ Œ·›Ì
        glVertex3f(-bodyWidth / 2, 0, bodyDepth / 2);
        glVertex3f(bodyWidth / 2, 0, bodyDepth / 2);
        glVertex3f(bodyWidth / 2, bodyHeight, bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, bodyHeight, bodyDepth / 2);

        // «·ÃÊ«‰»
        glVertex3f(-bodyWidth / 2, 0, -bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, 0, bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, bodyHeight, bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, bodyHeight, -bodyDepth / 2);

        glVertex3f(bodyWidth / 2, 0, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, 0, bodyDepth / 2);
        glVertex3f(bodyWidth / 2, bodyHeight, bodyDepth / 2);
        glVertex3f(bodyWidth / 2, bodyHeight, -bodyDepth / 2);

        // «·ﬁ«⁄œ… Ê«·”ﬁ›
        glVertex3f(-bodyWidth / 2, 0, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, 0, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, 0, bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, 0, bodyDepth / 2);

        glVertex3f(-bodyWidth / 2, bodyHeight, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, bodyHeight, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, bodyHeight, bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, bodyHeight, bodyDepth / 2);
        glEnd();

        // —”„ «·√Ã‰Õ… «·Ã«‰»Ì…
        glColor3f(1.0f, 1.0f, 1.0f); // ·Ê‰ «·√Ã‰Õ… (√»Ì÷)
        glBegin(GL_QUADS);
        // «·Ã‰«Õ «·√Ì”—
        glVertex3f(5.1, 0, -bodyDepth / 2 - wingDepth / 2);
        glVertex3f(5.1, 0, 5);
        glVertex3f(5.1, wingHeight, 5);
        glVertex3f(5.1, wingHeight, -bodyDepth / 2 + wingDepth / 2);

        // «·Ã‰«Õ «·√Ì„‰
        glVertex3f(-5.1, 0, -bodyDepth / 2 - wingDepth / 2);
        glVertex3f(-5.1, 0, 5);
        glVertex3f(-5.1, wingHeight, 5);
        glVertex3f(-5.1, wingHeight, -bodyDepth / 2 - wingDepth / 2);
        glEnd();
        glColor3f(0, 0, 0);
        glBegin(GL_LINES);
        glVertex3f(5.1, wingHeight / 2, -bodyDepth / 2 - wingDepth / 2);
        glVertex3f(5.1, wingHeight * 3 / 4, 5);
        glVertex3f(-5.1, wingHeight / 2, -bodyDepth / 2 - wingDepth / 2);
        glVertex3f(-5.1, wingHeight * 3 / 4, 5);
        glEnd();
        glPopMatrix();
    }
    void drawXbox(float x, float y, float z, float angleX, float angleY, float angleZ, int xboxf, int xboxb) {
        float bodyWidth = 24.0f;
        float bodyHeight = 12.0f;
        float bodyDepth = 20.0f;
        float buttonRadius = 2.0f; // ÕÃ„ «·‘⁄«—
        float logoRadius = 4.5f;
        glPushMatrix();
        glTranslatef(x, y, z);

        glRotatef(angleX, 1.0f, 0.0f, 0.0f);
        glRotatef(angleY, 0.0f, 1.0f, 0.0f);
        glRotatef(angleZ, 0.0f, 0.0f, 1.0f);

        // —”„ Ã”„ Xbox
        glColor3f(0.5, 0.5, 0.5); // ·Ê‰ «·Ã”„ (—„«œÌ €«„ﬁ)
        glBindTexture(GL_TEXTURE_2D, xboxf);
        glBegin(GL_QUADS);
        // ÊÃÂ √„«„Ì
        glTexCoord2f(0, 0);
        glVertex3f(-bodyWidth / 2, 0, -bodyDepth / 2);
        glTexCoord2f(1, 0);
        glVertex3f(bodyWidth / 2, 0, -bodyDepth / 2);
        glTexCoord2f(1, 1);
        glVertex3f(bodyWidth / 2, bodyHeight, -bodyDepth / 2);
        glTexCoord2f(0, 1);
        glVertex3f(-bodyWidth / 2, bodyHeight, -bodyDepth / 2);

        glEnd();

        glBindTexture(GL_TEXTURE_2D, xboxb);
        glBegin(GL_QUADS);

        // ÊÃÂ Œ·›Ì
        glTexCoord2f(0, 0);
        glVertex3f(-bodyWidth / 2, 0, bodyDepth / 2);
        glTexCoord2f(1, 0);
        glVertex3f(bodyWidth / 2, 0, bodyDepth / 2);
        glTexCoord2f(1, 1);
        glVertex3f(bodyWidth / 2, bodyHeight, bodyDepth / 2);
        glTexCoord2f(0, 1);
        glVertex3f(-bodyWidth / 2, bodyHeight, bodyDepth / 2);

        // «·ÃÊ«‰»
        glVertex3f(-bodyWidth / 2, 0, -bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, 0, bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, bodyHeight, bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, bodyHeight, -bodyDepth / 2);

        glVertex3f(bodyWidth / 2, 0, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, 0, bodyDepth / 2);
        glVertex3f(bodyWidth / 2, bodyHeight, bodyDepth / 2);
        glVertex3f(bodyWidth / 2, bodyHeight, -bodyDepth / 2);

        // «·ﬁ«⁄œ… Ê«·”ﬁ›
        glVertex3f(-bodyWidth / 2, 0, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, 0, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, 0, bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, 0, bodyDepth / 2);

        glVertex3f(-bodyWidth / 2, bodyHeight, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, bodyHeight, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, bodyHeight, bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, bodyHeight, bodyDepth / 2);
        glEnd();



        glPopMatrix();
    }
    static void drawLaptop(float x, float y, float z, float angleX, float angleY, float angleZ) {
        glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(angleX, 1.0f, 0.0f, 0.0f); // œÊ—«‰ ÕÊ· «·„ÕÊ— X
        glRotatef(angleY, 0.0f, 1.0f, 0.0f); // œÊ—«‰ ÕÊ· «·„ÕÊ— Y
        glRotatef(angleZ, 0.0f, 0.0f, 1.0f); // œÊ—«‰ ÕÊ· «·„ÕÊ— Z

        glColor3f(0.3f, 0.3f, 0.3f); // ·Ê‰ «··«» Ê»
        glBegin(GL_QUADS);

        // ﬁ«⁄œ… «··«» Ê»
        glVertex3f(0, 0, 0);
        glVertex3f(50.0f, 0, 0);
        glVertex3f(50.0f, 30.0f, 0);
        glVertex3f(0, 30.0f, 0);

        // «·‘«‘…
        glVertex3f(0, 30.0f, 0);
        glVertex3f(50.0f, 30.0f, 0);
        glVertex3f(50.0f, 60.0f, -10.0f);
        glVertex3f(0, 60.0f, -10.0f);

        glEnd();
        glColor3f(1.0f, 1.0f, 1.0f); // ·Ê‰ «·ÕÊ«› √»Ì÷
        glBegin(GL_LINE_LOOP);

        glVertex3f(0.0f, 30.0f, 0.0f);


        glVertex3f(50.0f, 30.0f, 0.0f);


        glVertex3f(50.0f, 60.0f, -10.0f);


        glVertex3f(0.0f, 60.0f, -10.0f);

        glEnd();

        // —”„ «·ﬂÌ»Ê—œ
       // —”„ «·ﬂÌ»Ê—œ
        glColor3f(static_cast<float>(rand()) / RAND_MAX,
            static_cast<float>(rand()) / RAND_MAX,
            static_cast<float>(rand()) / RAND_MAX);
        glBegin(GL_QUADS);

        // «·ﬂÌ»Ê—œ
        for (int y = 0; y < 25; y += 5) {
            for (int x = 0; x < 50; x += 5) {
                glVertex3f(x + 2, y + 2, -0.1f);             // «·“«ÊÌ… «·”›·Ì… «·Ì”—Ï
                glVertex3f(x + 4, y + 2, -0.1f);         // «·“«ÊÌ… «·”›·Ì… «·Ì„‰Ï
                glVertex3f(x + 4, y + 4, -0.1f);     // «·“«ÊÌ… «·⁄·Ì« «·Ì„‰Ï
                glVertex3f(x + 2, y + 4, -0.1f);         // «·“«ÊÌ… «·⁄·Ì« «·Ì”—Ï
            }
        }

        glEnd();
        glColor3f(0.1, 0.1, 0.1);
        glBegin(GL_LINES);
        for (float y = 25; y < 29; y += 0.4) {
            glVertex3f(5, y, 0.1);
            glVertex3f(45, y, 0.1);
        }


        glEnd();
        glPopMatrix();
    }
    void drawKeyboard(float x, float y, float z, float angleX, float angleY, float angleZ) {
        // √»⁄«œ «·ﬂÌ»Ê—œ
        float keyboardWidth = 3*60.0f;
        float keyboardHeight =3* 15.0f;
        float keyboardDepth =3* 2.0f; // ”„ﬂ «·ﬂÌ»Ê—œ
        float keyHeight = 1.0f*3; // «— ›«⁄ «·√“—«—
        float cableThickness = 3*0.5f;
        float cableLength = 15.0f*3;

        glPushMatrix();
        glTranslatef(x, y, z);

        //  ÿ»Ìﬁ «·œÊ—«‰
        glRotatef(angleX, 1.0f, 0.0f, 0.0f); // œÊ—«‰ ÕÊ· «·„ÕÊ— X
        glRotatef(angleY, 0.0f, 1.0f, 0.0f); // œÊ—«‰ ÕÊ· «·„ÕÊ— Y
        glRotatef(angleZ, 0.0f, 0.0f, 1.0f); // œÊ—«‰ ÕÊ· «·„ÕÊ— Z

        // —”„ «·ﬂÌ»Ê—œ
        glColor3f(0.5f, 0.5f, 0.5f); // ·Ê‰ «·ﬂÌ»Ê—œ
        glBegin(GL_QUADS);
        // ÊÃÂ «·ﬂÌ»Ê—œ «·⁄·ÊÌ
        glVertex3f(-keyboardWidth / 2, 0, -keyboardHeight / 2);
        glVertex3f(keyboardWidth / 2, 0, -keyboardHeight / 2);
        glVertex3f(keyboardWidth / 2, 0, keyboardHeight / 2);
        glVertex3f(-keyboardWidth / 2, 0, keyboardHeight / 2);

        // «·ÃÊ«‰» Ê«·Ã“¡ «·Œ·›Ì
        glVertex3f(-keyboardWidth / 2, -keyboardDepth, -keyboardHeight / 2);
        glVertex3f(keyboardWidth / 2, -keyboardDepth, -keyboardHeight / 2);
        glVertex3f(keyboardWidth / 2, 0, -keyboardHeight / 2);
        glVertex3f(-keyboardWidth / 2, 0, -keyboardHeight / 2);

        glVertex3f(-keyboardWidth / 2, -keyboardDepth, keyboardHeight / 2);
        glVertex3f(keyboardWidth / 2, -keyboardDepth, keyboardHeight / 2);
        glVertex3f(keyboardWidth / 2, 0, keyboardHeight / 2);
        glVertex3f(-keyboardWidth / 2, 0, keyboardHeight / 2);

        glVertex3f(-keyboardWidth / 2, -keyboardDepth, -keyboardHeight / 2);
        glVertex3f(-keyboardWidth / 2, -keyboardDepth, keyboardHeight / 2);
        glVertex3f(-keyboardWidth / 2, 0, keyboardHeight / 2);
        glVertex3f(-keyboardWidth / 2, 0, -keyboardHeight / 2);

        glVertex3f(keyboardWidth / 2, -keyboardDepth, -keyboardHeight / 2);
        glVertex3f(keyboardWidth / 2, -keyboardDepth, keyboardHeight / 2);
        glVertex3f(keyboardWidth / 2, 0, keyboardHeight / 2);
        glVertex3f(keyboardWidth / 2, 0, -keyboardHeight / 2);
        glEnd();

        // —”„ «·√“—«—
        glColor3f(0.9f, 0.9f, 0.9f); // ·Ê‰ «·√“—«—
        float keyWidth = 4*3.0f;
        float keyDepth = 4*3.0f;
        float spacing = 1.0f*3; // «·„”«›… »Ì‰ «·√“—«—

        for (float row = -keyboardHeight / 2 + spacing; row < keyboardHeight / 2 - spacing; row += keyDepth + spacing) {
            for (float col = -keyboardWidth / 2 + spacing; col < keyboardWidth / 2 - spacing; col += keyWidth + spacing) {
                glBegin(GL_QUADS);
                glVertex3f(col, keyHeight, row);
                glVertex3f(col + keyWidth, keyHeight, row);
                glVertex3f(col + keyWidth, keyHeight, row + keyDepth);
                glVertex3f(col, keyHeight, row + keyDepth);

                glVertex3f(col, keyHeight, row);
                glVertex3f(col + keyWidth, keyHeight, row);
                glVertex3f(col + keyWidth, 0, row);
                glVertex3f(col, 0, row);

                glVertex3f(col, keyHeight, row + keyDepth);
                glVertex3f(col + keyWidth, keyHeight, row + keyDepth);
                glVertex3f(col + keyWidth, 0, row + keyDepth);
                glVertex3f(col, 0, row + keyDepth);

                glVertex3f(col, keyHeight, row);
                glVertex3f(col, keyHeight, row + keyDepth);
                glVertex3f(col, 0, row + keyDepth);
                glVertex3f(col, 0, row);

                glVertex3f(col + keyWidth, keyHeight, row);
                glVertex3f(col + keyWidth, keyHeight, row + keyDepth);
                glVertex3f(col + keyWidth, 0, row + keyDepth);
                glVertex3f(col + keyWidth, 0, row);
                glEnd();
            }
        }

        // —”„ «·ﬂ«»·
        glColor3f(0.0f, 0.0f, 0.0f); // ·Ê‰ «·ﬂ«»·
        glBegin(GL_QUADS);
        glVertex3f(-cableThickness / 2, 0, keyboardHeight / 2);
        glVertex3f(cableThickness / 2, 0, keyboardHeight / 2);
        glVertex3f(cableThickness / 2, -cableThickness, keyboardHeight / 2 + cableLength);
        glVertex3f(-cableThickness / 2, -cableThickness, keyboardHeight / 2 + cableLength);
        glEnd();

        glPopMatrix();
    }
    static void drawPhone(float x, float y, float z, float angleX, float angleY, float angleZ, float r, float g, float b) {
        float thickness = 1.0f; // ”„ﬂ «·ÃÊ«·

        glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(angleX, 1.0f, 0.0f, 0.0f); // œÊ—«‰ ÕÊ· «·„ÕÊ— X
        glRotatef(angleY, 0.0f, 1.0f, 0.0f); // œÊ—«‰ ÕÊ· «·„ÕÊ— Y
        glRotatef(angleZ, 0.0f, 0.0f, 1.0f); // œÊ—«‰ ÕÊ· «·„ÕÊ— Z

        // —”„ «·ÂÌﬂ· «·Œ«—ÃÌ ··ÃÊ«·
        glColor3f(r, g, b); // ·Ê‰ «·ÃÊ«·
        glBegin(GL_QUADS);

        // ÊÃÂ √„«„Ì
        glVertex3f(0, 0, 0);
        glVertex3f(20.0f, 0, 0);
        glVertex3f(20.0f, 40.0f, 0);
        glVertex3f(0, 40.0f, 0);

        // ÊÃÂ Œ·›Ì
        glVertex3f(0, 0, -thickness);
        glVertex3f(20.0f, 0, -thickness);
        glVertex3f(20.0f, 40.0f, -thickness);
        glVertex3f(0, 40.0f, -thickness);

        // «·ÕÊ«› «·Ã«‰»Ì…
        glVertex3f(0, 0, 0);
        glVertex3f(0, 40.0f, 0);
        glVertex3f(0, 40.0f, -thickness);
        glVertex3f(0, 0, -thickness);

        glVertex3f(20.0f, 0, 0);
        glVertex3f(20.0f, 40.0f, 0);
        glVertex3f(20.0f, 40.0f, -thickness);
        glVertex3f(20.0f, 0, -thickness);

        glVertex3f(0, 0, 0);
        glVertex3f(20.0f, 0, 0);
        glVertex3f(20.0f, 0, -thickness);
        glVertex3f(0, 0, -thickness);

        glVertex3f(0, 40.0f, 0);
        glVertex3f(20.0f, 40.0f, 0);
        glVertex3f(20.0f, 40.0f, -thickness);
        glVertex3f(0, 40.0f, -thickness);

        glEnd();

        // —”„ «·‘«‘…
        glColor3f(0.0f, 0.0f, 0.0f); // ·Ê‰ «·‘«‘…
        glBegin(GL_QUADS);

        glVertex3f(2.0f, 2.0f, 0.01f);
        glVertex3f(18.0f, 2.0f, 0.01f);
        glVertex3f(18.0f, 38.0f, 0.01f);
        glVertex3f(2.0f, 38.0f, 0.01f);

        glEnd();

        // —”„ «·“— «·—∆Ì”Ì
        glColor3f(0.5f, 0.5f, 0.5f); // ·Ê‰ «·“—
        glBegin(GL_QUADS);

        glVertex3f(8.0f, 0.5f, 0.02f);
        glVertex3f(12.0f, 0.5f, 0.02f);
        glVertex3f(12.0f, 2.0f, 0.02f);
        glVertex3f(8.0f, 2.0f, 0.02f);

        glEnd();

        // —”„ «·√“—«— «·Ã«‰»Ì…
        glColor3f(0.4f, 0.4f, 0.4f); // ·Ê‰ «·√“—«— «·Ã«‰»Ì…
        glBegin(GL_QUADS);

        // “— «·ÿ«ﬁ… ⁄·Ï «·Ã«‰» «·√Ì„‰
        glVertex3f(20.0f, 30.0f, -0.2f);  // »—Ê“ »”Ìÿ ··Œ«—Ã
        glVertex3f(20.5f, 30.0f, -0.2f);
        glVertex3f(20.5f, 32.0f, -0.2f);
        glVertex3f(20.0f, 32.0f, -0.2f);

        // √“—«— «·’Ê  ⁄·Ï «·Ã«‰» «·√Ì”—
        glVertex3f(-0.5f, 30.0f, -0.2f);  // »—Ê“ »”Ìÿ ··Œ«—Ã
        glVertex3f(-0.0f, 30.0f, -0.2f);
        glVertex3f(-0.0f, 32.0f, -0.2f);
        glVertex3f(-0.5f, 32.0f, -0.2f);

        glVertex3f(-0.5f, 27.0f, -0.2f);
        glVertex3f(-0.0f, 27.0f, -0.2f);
        glVertex3f(-0.0f, 29.0f, -0.2f);
        glVertex3f(-0.5f, 29.0f, -0.2f);

        glEnd();

        glPopMatrix();
    }
    static void drawTablet(float x, float y, float z, float angleX, float angleY, float angleZ, float r, float g, float b) {
        float thickness = 1.0f; // ”„ﬂ «·ÃÊ«·

        glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(angleX, 1.0f, 0.0f, 0.0f); // œÊ—«‰ ÕÊ· «·„ÕÊ— X
        glRotatef(angleY, 0.0f, 1.0f, 0.0f); // œÊ—«‰ ÕÊ· «·„ÕÊ— Y
        glRotatef(angleZ, 0.0f, 0.0f, 1.0f); // œÊ—«‰ ÕÊ· «·„ÕÊ— Z

        // —”„ «·ÂÌﬂ· «·Œ«—ÃÌ ··ÃÊ«·
        glColor3f(r, g, b); // ·Ê‰ «·ÃÊ«·
        glBegin(GL_QUADS);

        // ÊÃÂ √„«„Ì
        glVertex3f(0, 0, 0);
        glVertex3f(30.0f, 0, 0);
        glVertex3f(30.0f, 40.0f, 0);
        glVertex3f(0, 40.0f, 0);

        // ÊÃÂ Œ·›Ì
        glVertex3f(0, 0, -thickness);
        glVertex3f(30.0f, 0, -thickness);
        glVertex3f(30.0f, 40.0f, -thickness);
        glVertex3f(0, 40.0f, -thickness);

        // «·ÕÊ«› «·Ã«‰»Ì…
        glVertex3f(0, 0, 0);
        glVertex3f(0, 40.0f, 0);
        glVertex3f(0, 40.0f, -thickness);
        glVertex3f(0, 0, -thickness);

        glVertex3f(30.0f, 0, 0);
        glVertex3f(30.0f, 40.0f, 0);
        glVertex3f(30.0f, 40.0f, -thickness);
        glVertex3f(30.0f, 0, -thickness);

        glVertex3f(0, 0, 0);
        glVertex3f(30.0f, 0, 0);
        glVertex3f(30.0f, 0, -thickness);
        glVertex3f(0, 0, -thickness);

        glVertex3f(0, 40.0f, 0);
        glVertex3f(30.0f, 40.0f, 0);
        glVertex3f(30.0f, 40.0f, -thickness);
        glVertex3f(0, 40.0f, -thickness);

        glEnd();

        // —”„ «·‘«‘…
        glColor3f(0.0f, 0.0f, 0.0f); // ·Ê‰ «·‘«‘…
        glBegin(GL_QUADS);

        glVertex3f(2.0f, 2.0f, 0.01f);
        glVertex3f(28.0f, 2.0f, 0.01f);
        glVertex3f(28.0f, 38.0f, 0.01f);
        glVertex3f(2.0f, 38.0f, 0.01f);

        glEnd();

        // —”„ «·“— «·—∆Ì”Ì
        glColor3f(0.5f, 0.5f, 0.5f); // ·Ê‰ «·“—
        glBegin(GL_QUADS);

        glVertex3f(13.0f, 0.5f, 0.02f);
        glVertex3f(17, 0.5f, 0.02f);
        glVertex3f(17.0f, 2.0f, 0.02f);
        glVertex3f(13.0f, 2.0f, 0.02f);

        glEnd();

        // —”„ «·√“—«— «·Ã«‰»Ì…
        glColor3f(0.4f, 0.4f, 0.4f); // ·Ê‰ «·√“—«— «·Ã«‰»Ì…
        glBegin(GL_QUADS);

        // “— «·ÿ«ﬁ… ⁄·Ï «·Ã«‰» «·√Ì„‰
        glVertex3f(30.0f, 30.0f, -0.2f);  // »—Ê“ »”Ìÿ ··Œ«—Ã
        glVertex3f(30.5f, 30.0f, -0.2f);
        glVertex3f(30.5f, 32.0f, -0.2f);
        glVertex3f(30.0f, 32.0f, -0.2f);

        // √“—«— «·’Ê  ⁄·Ï «·Ã«‰» «·√Ì”—
        glVertex3f(-0.5f, 30.0f, -0.2f);  // »—Ê“ »”Ìÿ ··Œ«—Ã
        glVertex3f(-0.0f, 30.0f, -0.2f);
        glVertex3f(-0.0f, 32.0f, -0.2f);
        glVertex3f(-0.5f, 32.0f, -0.2f);

        glVertex3f(-0.5f, 27.0f, -0.2f);
        glVertex3f(-0.0f, 27.0f, -0.2f);
        glVertex3f(-0.0f, 29.0f, -0.2f);
        glVertex3f(-0.5f, 29.0f, -0.2f);

        glEnd();

        glPopMatrix();
    }
    static void drawSpeakerFrame(float x, float y, float z, float angleX, float angleY, float angleZ, int  speaker) {
        float speakerWidth = 1.5*20.0f;   // ⁄—÷ «·”»Ìﬂ—
        float speakerHeight = 1.5*60.0f;  // «— ›«⁄ «·”»Ìﬂ—
        float speakerDepth = 1.5*20.0f;   // ⁄„ﬁ «·”»Ìﬂ—

        glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(angleX, 1.0f, 0.0f, 0.0f);
        glRotatef(angleY, 0.0f, 1.0f, 0.0f);
        glRotatef(angleZ, 0.0f, 0.0f, 1.0f);

        // —»ÿ «· ﬂ” ‘—
        glBindTexture(GL_TEXTURE_2D, speaker);

        //  ›⁄Ì· Œ«’Ì… «· ﬂ” ‘—
     

        // —”„ «·√ÊÃÂ «·√—»⁄ ·Ã”„ «·”»Ìﬂ— („ Ê«“Ì „” ÿÌ·« )
        glColor3f(0.5, 0.5, 0.5);
        glBegin(GL_QUADS);

        // «·ÃÂ… «·√„«„Ì…
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-speakerWidth / 2, -speakerHeight / 2, speakerDepth / 2);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(speakerWidth / 2, -speakerHeight / 2, speakerDepth / 2);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(speakerWidth / 2, speakerHeight / 2, speakerDepth / 2);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-speakerWidth / 2, speakerHeight / 2, speakerDepth / 2);
        glEnd();
        glColor3f(0.2, 0.2, 0.2);
        glBegin(GL_QUADS);
        // «·ÃÂ… «·Œ·›Ì…
        glVertex3f(-speakerWidth / 2, -speakerHeight / 2, -speakerDepth / 2);
    glVertex3f(speakerWidth / 2, -speakerHeight / 2, -speakerDepth / 2);
         glVertex3f(speakerWidth / 2, speakerHeight / 2, -speakerDepth / 2);
         glVertex3f(-speakerWidth / 2, speakerHeight / 2, -speakerDepth / 2);

        // «·ÃÂ… «·⁄·Ì«
        glVertex3f(-speakerWidth / 2, speakerHeight / 2, -speakerDepth / 2);
        glVertex3f(speakerWidth / 2, speakerHeight / 2, -speakerDepth / 2);
       glVertex3f(speakerWidth / 2, speakerHeight / 2, speakerDepth / 2);
         glVertex3f(-speakerWidth / 2, speakerHeight / 2, speakerDepth / 2);

        // «·ÃÂ… «·”›·Ï
         glVertex3f(-speakerWidth / 2, -speakerHeight / 2, -speakerDepth / 2);
         glVertex3f(speakerWidth / 2, -speakerHeight / 2, -speakerDepth / 2);
        glVertex3f(speakerWidth / 2, -speakerHeight / 2, speakerDepth / 2);
         glVertex3f(-speakerWidth / 2, -speakerHeight / 2, speakerDepth / 2);

        // «·ÃÂ… «·Ì„‰Ï
     glVertex3f(speakerWidth / 2, -speakerHeight / 2, -speakerDepth / 2);
         glVertex3f(speakerWidth / 2, -speakerHeight / 2, speakerDepth / 2);
       glVertex3f(speakerWidth / 2, speakerHeight / 2, speakerDepth / 2);
        glVertex3f(speakerWidth / 2, speakerHeight / 2, -speakerDepth / 2);

        // «·ÃÂ… «·Ì”—Ï
         glVertex3f(-speakerWidth / 2, -speakerHeight / 2, -speakerDepth / 2);
        glVertex3f(-speakerWidth / 2, -speakerHeight / 2, speakerDepth / 2);
        glVertex3f(-speakerWidth / 2, speakerHeight / 2, speakerDepth / 2);
         glVertex3f(-speakerWidth / 2, speakerHeight / 2, -speakerDepth / 2);

        glEnd();

        glPopMatrix();

       
    }
    static void drawMouse(float x, float y, float z, float angleX, float angleY, float angleZ) {
        float mouseWidth = 20.0f;
        float mouseHeight = 5.0f;
        float mouseDepth = 25.0f;

        glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(angleX, 1.0f, 0.0f, 0.0f);
        glRotatef(angleY, 0.0f, 1.0f, 0.0f);
        glRotatef(angleZ, 0.0f, 0.0f, 1.0f);

        // —”„ «·„«Ê” ﬂ„ Ê«“Ì „” ÿÌ·« 
        glColor3f(0.7f, 0.7f, 0.7f);  // ·Ê‰ «·„«Ê” «·—„«œÌ
        glBegin(GL_QUADS);

        // «·ÃÂ… «·√„«„Ì…
        glVertex3f(0, 0, 0);
        glVertex3f(mouseWidth, 0, 0);
        glVertex3f(mouseWidth, mouseHeight, 0);
        glVertex3f(0, mouseHeight, 0);

        // «·ÃÂ… «·Œ·›Ì…
        glVertex3f(0, 0, -mouseDepth);
        glVertex3f(mouseWidth, 0, -mouseDepth);
        glVertex3f(mouseWidth, mouseHeight, -mouseDepth);
        glVertex3f(0, mouseHeight, -mouseDepth);

        // «·ÃÂ… «·⁄·Ì«
        glVertex3f(0, mouseHeight, -mouseDepth);
        glVertex3f(mouseWidth, mouseHeight, -mouseDepth);
        glVertex3f(mouseWidth, mouseHeight, 0);
        glVertex3f(0, mouseHeight, 0);

        // «·ÃÂ… «·”›·Ï
        glVertex3f(0, 0, -mouseDepth);
        glVertex3f(mouseWidth, 0, -mouseDepth);
        glVertex3f(mouseWidth, 0, 0);
        glVertex3f(0, 0, 0);

        // «·ÃÂ… «·Ì„‰Ï
        glVertex3f(mouseWidth, 0, -mouseDepth);
        glVertex3f(mouseWidth, mouseHeight, -mouseDepth);
        glVertex3f(mouseWidth, mouseHeight, 0);
        glVertex3f(mouseWidth, 0, 0);

        // «·ÃÂ… «·Ì”—Ï
        glVertex3f(0, 0, -mouseDepth);
        glVertex3f(0, mouseHeight, -mouseDepth);
        glVertex3f(0, mouseHeight, 0);
        glVertex3f(0, 0, 0);

        glEnd();

        // —”„ «·√“—«— ⁄·Ï «·ÊÃÂ «·⁄·ÊÌ „‰ «·√„«„
        float buttonWidth = mouseWidth / 2;
        float buttonHeight = mouseHeight / 5;

        glColor3f(0.2f, 0.2f, 0.2f);  // ·Ê‰ «·√“—«— «·√”Êœ
        glBegin(GL_QUADS);

        // «·“— «·√Ì”—
        glVertex3f(0, mouseHeight+1, 0.01f);
        glVertex3f( buttonWidth, mouseHeight+1, 0.01f);
        glVertex3f(buttonWidth, mouseHeight+1, -mouseDepth/4);
        glVertex3f(0, mouseHeight +1, -mouseDepth / 4);

        // «·“— «·√Ì„‰
        glVertex3f(buttonWidth+1, mouseHeight + 1, 0.01f);
        glVertex3f(buttonWidth*2, mouseHeight + 1, 0.01f);
        glVertex3f(buttonWidth*2, mouseHeight + 1, -mouseDepth / 4);
        glVertex3f(buttonWidth + 1, mouseHeight + 1, -mouseDepth / 4);

        glEnd();

        glPopMatrix();
    }

    static void drawComputerCase(float x, float y, float z, float angleX, float angleY, float angleZ,int pcf,int pcb,int pcs) {
        float caseWidth = 60*3.0f;   // ⁄—÷ «·ﬂÌ” (√ﬂ»— ⁄—÷)
        float caseHeight = 40*3; // «— ›«⁄ «·ﬂÌ”
        float caseDepth = 20.0f*3;   // ⁄„ﬁ «·ﬂÌ” (√’€— „‰ «·⁄—÷)

        glPushMatrix();
        glTranslatef(x, y+ caseHeight / 2, z);
        glRotatef(angleX, 1.0f, 0.0f, 0.0f);
        glRotatef(angleY, 0.0f, 1.0f, 0.0f);
        glRotatef(angleZ, 0.0f, 0.0f, 1.0f);
        glColor3f(0, 0, 0);
        // —”„ «·√ÊÃÂ «·” … ··ﬂÌ” („ Ê«“Ì „” ÿÌ·« )
        glBegin(GL_QUADS);

        // «·ÃÂ… «·√„«„Ì… (⁄—÷ √ﬂ»— „‰ «·⁄„ﬁ)
        glVertex3f(-caseWidth / 2, -caseHeight / 2, caseDepth / 2);   // √”›· «·Ì”«—
        glVertex3f(caseWidth / 2, -caseHeight / 2, caseDepth / 2);    // √”›· «·Ì„Ì‰
        glVertex3f(caseWidth / 2, caseHeight / 2, caseDepth / 2);     // √⁄·Ï «·Ì„Ì‰
        glVertex3f(-caseWidth / 2, caseHeight / 2, caseDepth / 2);    // √⁄·Ï «·Ì”«—

      
        // «·ÃÂ… «·⁄·Ì«
        glVertex3f(-caseWidth / 2, caseHeight / 2, -caseDepth / 2);   // √”›· «·Ì”«—
        glVertex3f(caseWidth / 2, caseHeight / 2, -caseDepth / 2);    // √”›· «·Ì„Ì‰
        glVertex3f(caseWidth / 2, caseHeight / 2, caseDepth / 2);     // √⁄·Ï «·Ì„Ì‰
        glVertex3f(-caseWidth / 2, caseHeight / 2, caseDepth / 2);    // √⁄·Ï «·Ì”«—

        // «·ÃÂ… «·”›·Ï
        glVertex3f(-caseWidth / 2, -caseHeight / 2, -caseDepth / 2);  // √”›· «·Ì”«—
        glVertex3f(caseWidth / 2, -caseHeight / 2, -caseDepth / 2);   // √”›· «·Ì„Ì‰
        glVertex3f(caseWidth / 2, -caseHeight / 2, caseDepth / 2);    // √⁄·Ï «·Ì„Ì‰
        glVertex3f(-caseWidth / 2, -caseHeight / 2, caseDepth / 2);   // √⁄·Ï «·Ì”«—
        glEnd();

      
        glColor3f(0.5, 0.5, 0.5);

        glBindTexture(GL_TEXTURE_2D, pcs);
        glBegin(GL_QUADS);
        // «·ÃÂ… «·Œ·›Ì… (‰›” «·√»⁄«œ „À· «·√„«„Ì… Ê·ﬂ‰ ›Ì «·« Ã«Â «·„⁄«ﬂ”)
        glTexCoord2f(1, 0);
        glVertex3f(-caseWidth / 2, -caseHeight / 2, caseDepth / 2 -5);  // √”›· «·Ì”«—
        glTexCoord2f(0, 0);
        glVertex3f(caseWidth / 2, -caseHeight / 2, caseDepth / 2-5);   // √”›· «·Ì„Ì‰
        glTexCoord2f(0, 1);
        glVertex3f(caseWidth / 2, caseHeight / 2, caseDepth / 2-5);    // √⁄·Ï «·Ì„Ì‰
        glTexCoord2f(1, 1);
        glVertex3f(-caseWidth / 2, caseHeight / 2, caseDepth / 2-5);   // √⁄·Ï «·Ì”«—
        glEnd();
        glColor3f(0.5, 0.5, 0.5);

        glBindTexture(GL_TEXTURE_2D, pcb);
        glBegin(GL_QUADS);
        // «·ÃÂ… «·Ì„‰Ï
        glTexCoord2f(1, 0);
        glVertex3f(caseWidth / 2, -caseHeight / 2, -caseDepth / 2);   // √”›· «·Ì”«—
        glTexCoord2f(0, 0);
        glVertex3f(caseWidth / 2, -caseHeight / 2, caseDepth / 2);    // √”›· «·Ì„Ì‰

        glTexCoord2f(0, 1);
        glVertex3f(caseWidth / 2, caseHeight / 2, caseDepth / 2);     // √⁄·Ï «·Ì„Ì‰
        glTexCoord2f(1, 1);
        glVertex3f(caseWidth / 2, caseHeight / 2, -caseDepth / 2);    // √⁄·Ï «·Ì”«—
        glEnd();
        glColor3f(0.5, 0.5, 0.5);

        glBindTexture(GL_TEXTURE_2D, pcf);
        glBegin(GL_QUADS);
        // «·ÃÂ… «·Ì”—Ï
        
        glTexCoord2f(1, 0);
        glVertex3f(-caseWidth / 2, -caseHeight / 2, -caseDepth / 2);  // √”›· «·Ì”«—
        glTexCoord2f(0, 0);
       
        glVertex3f(-caseWidth / 2, -caseHeight / 2, caseDepth / 2);   // √”›· «·Ì„Ì‰
        glTexCoord2f(0, 1);
       

        glVertex3f(-caseWidth / 2, caseHeight / 2, caseDepth / 2);    // √⁄·Ï «·Ì„Ì‰
         glTexCoord2f(1, 1);
      
        glVertex3f(-caseWidth / 2, caseHeight / 2, -caseDepth / 2);   // √⁄·Ï «·Ì”«—

        glEnd();

        glPopMatrix();
    }
    static void drawGamingTable(float width, float depth, float height, float x, float y, float z, float rotation) {
        glPushMatrix();
        glTranslatef(x, y , z);
        glRotatef(rotation, 0.0f, 1.0f, 0.0f);
        glLineWidth(10.0f);
        glColor3f(0.5, 0.5, 0.5);
        glBegin(GL_LINES);
        glVertex3f(5, 0, 0);
        glVertex3f(5, height, depth);
        glVertex3f(5, 0, 0);
        glVertex3f(5, 0, depth);
        glVertex3f(5, height, 0);
        glVertex3f(5, 0, depth);

        glVertex3f(width-5, 0, -10);
        glVertex3f(width-5, height, depth);
        glVertex3f(width-5, 0, -10);
        glVertex3f(width-5, 0, depth);
        glVertex3f(width - 5, height, 0);
        glVertex3f(width - 5, 0, depth);

        glEnd();
        glBegin(GL_QUADS);
        glVertex3f(0, height, 0);
        glVertex3f(width, height, 0);
        glVertex3f(width, height, depth+2);
        glVertex3f(0, height, depth+2);
        glEnd();
        glPopMatrix();
    }
    void drawGamingChair(float x, float y, float z, float rotationAngle) {
        glPushMatrix();

        // Apply translation and rotation
        glTranslatef(x, y, z);
        glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f);  // Rotate around the y-axis

        // Base Cylinder (Vertical)
        glPushMatrix();
        glColor3f(0.5f, 0.5f, 0.5f);  // Gray color
        glTranslatef(0.0f, 0.0f, 0.0f);  // Ensure cylinder is vertically aligned
        GLUquadric* quadric = gluNewQuadric();
        gluCylinder(quadric, 5.0f, 5.0f, 40.0f, 32, 32);
        gluDeleteQuadric(quadric);
        glPopMatrix();

        // Slanted Rectangles
        for (int i = 0; i < 3; ++i) {
            glPushMatrix();
            glTranslatef(0.0f, 0.0f, -5.0f);
            glRotatef(120.0f * i, 0.0f, 1.0f, 0.0f);
            glRotatef(-30.0f, 1.0f, 0.0f, 0.0f);
            glColor3f(0.3f, 0.3f, 0.3f);
            glBegin(GL_QUADS);
            glVertex3f(-1.0f, 0.0f, 0.0f);
            glVertex3f(1.0f, 0.0f, 0.0f);
            glVertex3f(1.0f, 20.0f, -10.0f);
            glVertex3f(-1.0f, 20.0f, -10.0f);
            glEnd();
            glPopMatrix();
        }

        // Polygon Circle at the Top
        glPushMatrix();
        glTranslatef(0.0f, 0.0f, 40.0f);
        glColor3f(0.7f, 0.7f, 0.7f);  // Light gray
        glBegin(GL_POLYGON);
        for (int i = 0; i < 32; ++i) {
            float angle = 2.0f * 3.14 * float(i) / float(32);
            float px = 5.0f * cosf(angle);
            float py = 5.0f * sinf(angle);
            glVertex2f(px, py);
        }
        glEnd();
        glPopMatrix();

        // Backrest (Rectangle connected to the polygon)
        glPushMatrix();
        glTranslatef(0.0f, 0.0f, 40.0f);
        glColor3f(0.2f, 0.2f, 0.2f);  // Dark gray
        glBegin(GL_QUADS);
        glVertex3f(-5.0f, 0.0f, 0.0f);
        glVertex3f(5.0f, 0.0f, 0.0f);
        glVertex3f(5.0f, 30.0f, 0.0f);
        glVertex3f(-5.0f, 30.0f, 0.0f);
        glEnd();
        glPopMatrix();

        glPopMatrix();
    }

    void display() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        gluLookAt(0.0f, 50.0f, 100.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

        // Example usage of drawGamingChair
        drawGamingChair(0.0f, 0.0f, 0.0f, 45.0f);  // Position at origin with 45-degree rotation

        glutSwapBuffers();
    }


};

