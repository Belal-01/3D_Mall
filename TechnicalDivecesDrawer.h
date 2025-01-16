#pragma once
#include <GL/glut.h>
#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include <random>

class TechnicalDivecesDrawer
{
public:
    void drawComputerMonitor(float x, float y, float z, float angleX, float angleY, float angleZ) {

        float width = 50.0f * 4;
        float height = 30.0f * 4;
        float screenThickness = 1.0f * 4;
        float baseWidth = 40.0f * 4;
        float baseDepth = 15.0f * 4;
        float connectorHeight = 4 * 1.5f;
        float buttonWidth = 3.0f * 4;
        float buttonHeight = 1.0f * 4;

        glPushMatrix();
        glTranslatef(x, y, z);


        glRotatef(angleX, 1.0f, 0.0f, 0.0f);
        glRotatef(angleY, 0.0f, 1.0f, 0.0f);
        glRotatef(angleZ, 0.0f, 0.0f, 1.0f);


        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);

        glVertex3f(-width / 2, height, 0);
        glVertex3f(width / 2, height, 0);
        glVertex3f(width / 2, 0, 0);
        glVertex3f(-width / 2, 0, 0);


        glVertex3f(-width / 2, height, screenThickness);
        glVertex3f(width / 2, height, screenThickness);
        glVertex3f(width / 2, 0, screenThickness);
        glVertex3f(-width / 2, 0, screenThickness);


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


        glColor3f(0.2f, 0.2f, 0.2f);
        glBegin(GL_QUADS);
        glVertex3f(-baseWidth / 2, -connectorHeight, -baseDepth / 2);
        glVertex3f(baseWidth / 2, -connectorHeight, -baseDepth / 2);
        glVertex3f(baseWidth / 2, -connectorHeight, baseDepth / 2);
        glVertex3f(-baseWidth / 2, -connectorHeight, baseDepth / 2);
        glEnd();


        glColor3f(0.4f, 0.4f, 0.4f);
        glBegin(GL_QUADS);

        glVertex3f(-baseWidth / 12, 0, -baseDepth / 12);
        glVertex3f(baseWidth / 12, 0, -baseDepth / 12);
        glVertex3f(baseWidth / 12, -connectorHeight, -baseDepth / 12);
        glVertex3f(-baseWidth / 12, -connectorHeight, -baseDepth / 12);

        // æÌå ÎáÝí
        glVertex3f(-baseWidth / 12, 0, baseDepth / 12);
        glVertex3f(baseWidth / 12, 0, baseDepth / 12);
        glVertex3f(baseWidth / 12, -connectorHeight, baseDepth / 12);
        glVertex3f(-baseWidth / 12, -connectorHeight, baseDepth / 12);


        glVertex3f(-baseWidth / 12, 0, -baseDepth / 12);
        glVertex3f(-baseWidth / 12, 0, baseDepth / 12);
        glVertex3f(-baseWidth / 12, -connectorHeight, baseDepth / 12);
        glVertex3f(-baseWidth / 12, -connectorHeight, -baseDepth / 12);


        glVertex3f(baseWidth / 12, 0, -baseDepth / 12);
        glVertex3f(baseWidth / 12, 0, baseDepth / 12);
        glVertex3f(baseWidth / 12, -connectorHeight, baseDepth / 12);
        glVertex3f(baseWidth / 12, -connectorHeight, -baseDepth / 12);
        glEnd();


        glColor3f(1.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);

        glVertex3f(22, -connectorHeight + 10.0f, -0.1);
        glVertex3f(25, -connectorHeight + 10.0f, -0.1);
        glVertex3f(25, -connectorHeight + buttonHeight + 10.0f, -0.1);
        glVertex3f(22, -connectorHeight + buttonHeight + 10.0f, -0.1);
        glEnd();

        glPopMatrix();

    }
    static void drawScreen(float x, float y, float z, float angleX, float angleY, float angleZ) {
        float width = 60 * 6;
        float hight = 40 * 6;
        glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(angleX, 10.0f, 0.0f, 0.0f);
        glRotatef(angleY, 0.0f, 10.0f, 0.0f);
        glRotatef(angleZ, 0.0f, 0.0f, 10.0f);

        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);

        // ÇáÔÇÔÉ
        glVertex3f(0, 0, 0);
        glVertex3f(width, 0, 0);
        glVertex3f(width, hight, 0);
        glVertex3f(0, hight, 0);

        glEnd();


        glPopMatrix();
    }
    void drawPS5(float x, float y, float z, float angleX, float angleY, float angleZ) {

        float bodyWidth = 30.0f;   // 10 * 3
        float bodyHeight = 90.0f;  // 30 * 3
        float bodyDepth = 15.0f;   // 5 * 3
        float wingWidth = 36.0f;   // 12 * 3
        float wingHeight = 90.0f;  // 30 * 3
        float wingDepth = 1.5f;    // 0.5 * 3
        float wingOffset = 6.0f;   // 2 * 3

        glPushMatrix();
        glTranslatef(x, y, z);

        glRotatef(angleX, 1.0f, 0.0f, 0.0f);
        glRotatef(angleY, 0.0f, 1.0f, 0.0f);
        glRotatef(angleZ, 0.0f, 0.0f, 1.0f);

        glColor3f(0.1f, 0.1f, 0.1f);
        glBegin(GL_QUADS);

        // æÌå ÃãÇãí
        glVertex3f(-bodyWidth / 2, 0, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, 0, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, bodyHeight, -bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, bodyHeight, -bodyDepth / 2);

        // æÌå ÎáÝí
        glVertex3f(-bodyWidth / 2, 0, bodyDepth / 2);
        glVertex3f(bodyWidth / 2, 0, bodyDepth / 2);
        glVertex3f(bodyWidth / 2, bodyHeight, bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, bodyHeight, bodyDepth / 2);

        // ÇáÌæÇäÈ
        glVertex3f(-bodyWidth / 2, 0, -bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, 0, bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, bodyHeight, bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, bodyHeight, -bodyDepth / 2);

        glVertex3f(bodyWidth / 2, 0, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, 0, bodyDepth / 2);
        glVertex3f(bodyWidth / 2, bodyHeight, bodyDepth / 2);
        glVertex3f(bodyWidth / 2, bodyHeight, -bodyDepth / 2);

        // ÇáÞÇÚÏÉ æÇáÓÞÝ
        glVertex3f(-bodyWidth / 2, 0, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, 0, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, 0, bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, 0, bodyDepth / 2);

        glVertex3f(-bodyWidth / 2, bodyHeight, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, bodyHeight, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, bodyHeight, bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, bodyHeight, bodyDepth / 2);
        glEnd();

        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_QUADS);
        // ÇáÌäÇÍ ÇáÃíÓÑ
        glVertex3f(15.3, 0, -bodyDepth / 2 - wingDepth / 2);
        glVertex3f(15.3, 0, 15);
        glVertex3f(15.3, wingHeight, 15);
        glVertex3f(15.3, wingHeight, -bodyDepth / 2 + wingDepth / 2);

        // ÇáÌäÇÍ ÇáÃíãä
        glVertex3f(-15.3, 0, -bodyDepth / 2 - wingDepth / 2);
        glVertex3f(-15.3, 0, 15);
        glVertex3f(-15.3, wingHeight, 15);
        glVertex3f(-15.3, wingHeight, -bodyDepth / 2 - wingDepth / 2);
        glEnd();

        glColor3f(0, 0, 0);
        glBegin(GL_LINES);
        glVertex3f(15.3, wingHeight / 2, -bodyDepth / 2 - wingDepth / 2);
        glVertex3f(15.3, wingHeight * 3 / 4, 15);
        glVertex3f(-15.3, wingHeight / 2, -bodyDepth / 2 - wingDepth / 2);
        glVertex3f(-15.3, wingHeight * 3 / 4, 15);
        glEnd();
        glPopMatrix();
    }
    void drawXbox(float x, float y, float z, float angleX, float angleY, float angleZ, int xboxf, int xboxb) {
        float bodyWidth = 24.0f * 3;
        float bodyHeight = 12.0f * 3;
        float bodyDepth = 20.0f * 3;
        float buttonRadius = 2.0f * 3;
        float logoRadius = 4.5f * 3;
        glPushMatrix();
        glTranslatef(x, y, z);

        glRotatef(angleX, 1.0f, 0.0f, 0.0f);
        glRotatef(angleY, 0.0f, 1.0f, 0.0f);
        glRotatef(angleZ, 0.0f, 0.0f, 1.0f);

        glEnable(GL_TEXTURE_2D);
        glColor3f(0.5, 0.5, 0.5);
        glBindTexture(GL_TEXTURE_2D, xboxf);
        glBegin(GL_QUADS);
        // æÌå ÃãÇãí
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

        // æÌå ÎáÝí
        glTexCoord2f(0, 0);
        glVertex3f(-bodyWidth / 2, 0, bodyDepth / 2);
        glTexCoord2f(1, 0);
        glVertex3f(bodyWidth / 2, 0, bodyDepth / 2);
        glTexCoord2f(1, 1);
        glVertex3f(bodyWidth / 2, bodyHeight, bodyDepth / 2);
        glTexCoord2f(0, 1);
        glVertex3f(-bodyWidth / 2, bodyHeight, bodyDepth / 2);

        // ÇáÌæÇäÈ
        glVertex3f(-bodyWidth / 2, 0, -bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, 0, bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, bodyHeight, bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, bodyHeight, -bodyDepth / 2);

        glVertex3f(bodyWidth / 2, 0, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, 0, bodyDepth / 2);
        glVertex3f(bodyWidth / 2, bodyHeight, bodyDepth / 2);
        glVertex3f(bodyWidth / 2, bodyHeight, -bodyDepth / 2);

        // ÇáÞÇÚÏÉ æÇáÓÞÝ
        glVertex3f(-bodyWidth / 2, 0, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, 0, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, 0, bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, 0, bodyDepth / 2);

        glVertex3f(-bodyWidth / 2, bodyHeight, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, bodyHeight, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, bodyHeight, bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, bodyHeight, bodyDepth / 2);
        glEnd();

        glDisable(GL_TEXTURE_2D);

        glPopMatrix();
    }
    static void drawLaptop(float x, float y, float z, float angleX, float angleY, float angleZ) {
        glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(angleX, 1.0f, 0.0f, 0.0f);
        glRotatef(angleY, 0.0f, 1.0f, 0.0f);
        glRotatef(angleZ, 0.0f, 0.0f, 1.0f);

        glColor3f(0.3f, 0.3f, 0.3f);
        glBegin(GL_QUADS);

        // ÞÇÚÏÉ ÇááÇÈÊæÈ
        glVertex3f(0, 0, 0);
        glVertex3f(50.0f, 0, 0);
        glVertex3f(50.0f, 30.0f, 0);
        glVertex3f(0, 30.0f, 0);

        // ÇáÔÇÔÉ
        glVertex3f(0, 30.0f, 0);
        glVertex3f(50.0f, 30.0f, 0);
        glVertex3f(50.0f, 60.0f, -10.0f);
        glVertex3f(0, 60.0f, -10.0f);

        glEnd();
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_LINE_LOOP);

        glVertex3f(0.0f, 30.0f, 0.0f);


        glVertex3f(50.0f, 30.0f, 0.0f);


        glVertex3f(50.0f, 60.0f, -10.0f);


        glVertex3f(0.0f, 60.0f, -10.0f);

        glEnd();


        // ÑÓã ÇáßíÈæÑÏ
        glColor3f(static_cast<float>(rand()) / RAND_MAX,
            static_cast<float>(rand()) / RAND_MAX,
            static_cast<float>(rand()) / RAND_MAX);
        glBegin(GL_QUADS);


        for (int y = 0; y < 25; y += 5) {
            for (int x = 0; x < 50; x += 5) {
                glVertex3f(x + 2, y + 2, -0.1f);
                glVertex3f(x + 4, y + 2, -0.1f);
                glVertex3f(x + 4, y + 4, -0.1f);
                glVertex3f(x + 2, y + 4, -0.1f);
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

        float keyboardWidth = 3 * 60.0f;
        float keyboardHeight = 3 * 15.0f;
        float keyboardDepth = 3 * 2.0f;
        float keyHeight = 1.0f * 3;
        float cableThickness = 3 * 0.5f;
        float cableLength = 15.0f * 3;

        glPushMatrix();
        glTranslatef(x, y, z);

        glRotatef(angleX, 1.0f, 0.0f, 0.0f);
        glRotatef(angleY, 0.0f, 1.0f, 0.0f);
        glRotatef(angleZ, 0.0f, 0.0f, 1.0f);

        // ÑÓã ÇáßíÈæÑÏ
        glColor3f(0.5f, 0.5f, 0.5f);
        glBegin(GL_QUADS);

        glVertex3f(-keyboardWidth / 2, 0, -keyboardHeight / 2);
        glVertex3f(keyboardWidth / 2, 0, -keyboardHeight / 2);
        glVertex3f(keyboardWidth / 2, 0, keyboardHeight / 2);
        glVertex3f(-keyboardWidth / 2, 0, keyboardHeight / 2);


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

        // ÑÓã ÇáÃÒÑÇÑ
        glColor3f(0.9f, 0.9f, 0.9f);
        float keyWidth = 4 * 3.0f;
        float keyDepth = 4 * 3.0f;
        float spacing = 1.0f * 3;

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

        // ÑÓã ÇáßÈá
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
        glVertex3f(-cableThickness / 2, 0, keyboardHeight / 2);
        glVertex3f(cableThickness / 2, 0, keyboardHeight / 2);
        glVertex3f(cableThickness / 2, -cableThickness, keyboardHeight / 2 + cableLength);
        glVertex3f(-cableThickness / 2, -cableThickness, keyboardHeight / 2 + cableLength);
        glEnd();

        glPopMatrix();
    }
    static void drawPhone(float x, float y, float z, float angleX, float angleY, float angleZ, float r, float g, float b) {
        float thickness = 1.0f;

        glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(angleX, 1.0f, 0.0f, 0.0f);
        glRotatef(angleY, 0.0f, 1.0f, 0.0f);
        glRotatef(angleZ, 0.0f, 0.0f, 1.0f);


        glColor3f(r, g, b);
        glBegin(GL_QUADS);

        // æÌå ÃãÇãí
        glVertex3f(0, 0, 0);
        glVertex3f(20.0f, 0, 0);
        glVertex3f(20.0f, 40.0f, 0);
        glVertex3f(0, 40.0f, 0);

        // æÌå ÎáÝí
        glVertex3f(0, 0, -thickness);
        glVertex3f(20.0f, 0, -thickness);
        glVertex3f(20.0f, 40.0f, -thickness);
        glVertex3f(0, 40.0f, -thickness);

        // ÇáÍæÇÝ ÇáÌÇäÈíÉ
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

        // ÑÓã ÇáÔÇÔÉ
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);

        glVertex3f(2.0f, 2.0f, 0.01f);
        glVertex3f(18.0f, 2.0f, 0.01f);
        glVertex3f(18.0f, 38.0f, 0.01f);
        glVertex3f(2.0f, 38.0f, 0.01f);

        glEnd();

        // ÑÓã ÇáÒÑ ÇáÑÆíÓí
        glColor3f(0.5f, 0.5f, 0.5f);
        glBegin(GL_QUADS);

        glVertex3f(8.0f, 0.5f, 0.02f);
        glVertex3f(12.0f, 0.5f, 0.02f);
        glVertex3f(12.0f, 2.0f, 0.02f);
        glVertex3f(8.0f, 2.0f, 0.02f);

        glEnd();

        // ÑÓã ÇáÃÒÑÇÑ ÇáÌÇäÈíÉ
        glColor3f(0.4f, 0.4f, 0.4f);
        glBegin(GL_QUADS);

        // ÒÑ ÇáØÇÞÉ Úáì ÇáÌÇäÈ ÇáÃíãä
        glVertex3f(20.0f, 30.0f, -0.2f);
        glVertex3f(20.5f, 30.0f, -0.2f);
        glVertex3f(20.5f, 32.0f, -0.2f);
        glVertex3f(20.0f, 32.0f, -0.2f);

        // ÃÒÑÇÑ ÇáÕæÊ Úáì ÇáÌÇäÈ ÇáÃíÓÑ
        glVertex3f(-0.5f, 30.0f, -0.2f);
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
        float thickness = 1.0f;

        glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(angleX, 1.0f, 0.0f, 0.0f);
        glRotatef(angleY, 0.0f, 1.0f, 0.0f);
        glRotatef(angleZ, 0.0f, 0.0f, 1.0f);


        glColor3f(r, g, b);
        glBegin(GL_QUADS);


        glVertex3f(0, 0, 0);
        glVertex3f(30.0f, 0, 0);
        glVertex3f(30.0f, 40.0f, 0);
        glVertex3f(0, 40.0f, 0);


        glVertex3f(0, 0, -thickness);
        glVertex3f(30.0f, 0, -thickness);
        glVertex3f(30.0f, 40.0f, -thickness);
        glVertex3f(0, 40.0f, -thickness);


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

        // ÑÓã ÇáÔÇÔÉ
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);

        glVertex3f(2.0f, 2.0f, 0.01f);
        glVertex3f(28.0f, 2.0f, 0.01f);
        glVertex3f(28.0f, 38.0f, 0.01f);
        glVertex3f(2.0f, 38.0f, 0.01f);

        glEnd();


        glColor3f(0.5f, 0.5f, 0.5f);
        glBegin(GL_QUADS);

        glVertex3f(13.0f, 0.5f, 0.02f);
        glVertex3f(17, 0.5f, 0.02f);
        glVertex3f(17.0f, 2.0f, 0.02f);
        glVertex3f(13.0f, 2.0f, 0.02f);

        glEnd();

        // ÑÓã ÇáÃÒÑÇÑ ÇáÌÇäÈíÉ
        glColor3f(0.4f, 0.4f, 0.4f);
        glBegin(GL_QUADS);

        // ÒÑ ÇáØÇÞÉ 
        glVertex3f(30.0f, 30.0f, -0.2f);
        glVertex3f(30.5f, 30.0f, -0.2f);
        glVertex3f(30.5f, 32.0f, -0.2f);
        glVertex3f(30.0f, 32.0f, -0.2f);

        // ÃÒÑÇÑ ÇáÕæÊ 
        glVertex3f(-0.5f, 30.0f, -0.2f);
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
        float speakerWidth = 1.5 * 20.0f;
        float speakerHeight = 1.5 * 60.0f;
        float speakerDepth = 1.5 * 20.0f;

        glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(angleX, 1.0f, 0.0f, 0.0f);
        glRotatef(angleY, 0.0f, 1.0f, 0.0f);
        glRotatef(angleZ, 0.0f, 0.0f, 1.0f);


        glEnable(GL_TEXTURE_2D);

        glBindTexture(GL_TEXTURE_2D, speaker);





        glColor3f(0.5, 0.5, 0.5);
        glBegin(GL_QUADS);


        glTexCoord2f(0.0f, 0.0f); glVertex3f(-speakerWidth / 2, -speakerHeight / 2, speakerDepth / 2);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(speakerWidth / 2, -speakerHeight / 2, speakerDepth / 2);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(speakerWidth / 2, speakerHeight / 2, speakerDepth / 2);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-speakerWidth / 2, speakerHeight / 2, speakerDepth / 2);
        glEnd();
        glColor3f(0.2, 0.2, 0.2);
        glBegin(GL_QUADS);

        glVertex3f(-speakerWidth / 2, -speakerHeight / 2, -speakerDepth / 2);
        glVertex3f(speakerWidth / 2, -speakerHeight / 2, -speakerDepth / 2);
        glVertex3f(speakerWidth / 2, speakerHeight / 2, -speakerDepth / 2);
        glVertex3f(-speakerWidth / 2, speakerHeight / 2, -speakerDepth / 2);


        glVertex3f(-speakerWidth / 2, speakerHeight / 2, -speakerDepth / 2);
        glVertex3f(speakerWidth / 2, speakerHeight / 2, -speakerDepth / 2);
        glVertex3f(speakerWidth / 2, speakerHeight / 2, speakerDepth / 2);
        glVertex3f(-speakerWidth / 2, speakerHeight / 2, speakerDepth / 2);


        glVertex3f(-speakerWidth / 2, -speakerHeight / 2, -speakerDepth / 2);
        glVertex3f(speakerWidth / 2, -speakerHeight / 2, -speakerDepth / 2);
        glVertex3f(speakerWidth / 2, -speakerHeight / 2, speakerDepth / 2);
        glVertex3f(-speakerWidth / 2, -speakerHeight / 2, speakerDepth / 2);


        glVertex3f(speakerWidth / 2, -speakerHeight / 2, -speakerDepth / 2);
        glVertex3f(speakerWidth / 2, -speakerHeight / 2, speakerDepth / 2);
        glVertex3f(speakerWidth / 2, speakerHeight / 2, speakerDepth / 2);
        glVertex3f(speakerWidth / 2, speakerHeight / 2, -speakerDepth / 2);


        glVertex3f(-speakerWidth / 2, -speakerHeight / 2, -speakerDepth / 2);
        glVertex3f(-speakerWidth / 2, -speakerHeight / 2, speakerDepth / 2);
        glVertex3f(-speakerWidth / 2, speakerHeight / 2, speakerDepth / 2);
        glVertex3f(-speakerWidth / 2, speakerHeight / 2, -speakerDepth / 2);

        glEnd();
        glDisable(GL_TEXTURE_2D);
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


        glColor3f(0.7f, 0.7f, 0.7f);
        glBegin(GL_QUADS);


        glVertex3f(0, 0, 0);
        glVertex3f(mouseWidth, 0, 0);
        glVertex3f(mouseWidth, mouseHeight, 0);
        glVertex3f(0, mouseHeight, 0);


        glVertex3f(0, 0, -mouseDepth);
        glVertex3f(mouseWidth, 0, -mouseDepth);
        glVertex3f(mouseWidth, mouseHeight, -mouseDepth);
        glVertex3f(0, mouseHeight, -mouseDepth);


        glVertex3f(0, mouseHeight, -mouseDepth);
        glVertex3f(mouseWidth, mouseHeight, -mouseDepth);
        glVertex3f(mouseWidth, mouseHeight, 0);
        glVertex3f(0, mouseHeight, 0);


        glVertex3f(0, 0, -mouseDepth);
        glVertex3f(mouseWidth, 0, -mouseDepth);
        glVertex3f(mouseWidth, 0, 0);
        glVertex3f(0, 0, 0);


        glVertex3f(mouseWidth, 0, -mouseDepth);
        glVertex3f(mouseWidth, mouseHeight, -mouseDepth);
        glVertex3f(mouseWidth, mouseHeight, 0);
        glVertex3f(mouseWidth, 0, 0);


        glVertex3f(0, 0, -mouseDepth);
        glVertex3f(0, mouseHeight, -mouseDepth);
        glVertex3f(0, mouseHeight, 0);
        glVertex3f(0, 0, 0);

        glEnd();


        float buttonWidth = mouseWidth / 2;
        float buttonHeight = mouseHeight / 5;

        glColor3f(0.2f, 0.2f, 0.2f);
        glBegin(GL_QUADS);


        glVertex3f(0, mouseHeight + 1, 0.01f);
        glVertex3f(buttonWidth, mouseHeight + 1, 0.01f);
        glVertex3f(buttonWidth, mouseHeight + 1, -mouseDepth / 4);
        glVertex3f(0, mouseHeight + 1, -mouseDepth / 4);


        glVertex3f(buttonWidth + 1, mouseHeight + 1, 0.01f);
        glVertex3f(buttonWidth * 2, mouseHeight + 1, 0.01f);
        glVertex3f(buttonWidth * 2, mouseHeight + 1, -mouseDepth / 4);
        glVertex3f(buttonWidth + 1, mouseHeight + 1, -mouseDepth / 4);

        glEnd();

        glPopMatrix();
    }

    static void drawComputerCase(float x, float y, float z, float angleX, float angleY, float angleZ, int pcf, int pcb, int pcs) {
        float caseWidth = 60 * 3.0f;
        float caseHeight = 40 * 3;
        float caseDepth = 20.0f * 3;

        glPushMatrix();
        glTranslatef(x, y + caseHeight / 2, z);
        glRotatef(angleX, 1.0f, 0.0f, 0.0f);
        glRotatef(angleY, 0.0f, 1.0f, 0.0f);
        glRotatef(angleZ, 0.0f, 0.0f, 1.0f);
        glColor3f(0, 0, 0);

        glBegin(GL_QUADS);


        glVertex3f(-caseWidth / 2, -caseHeight / 2, caseDepth / 2);
        glVertex3f(caseWidth / 2, -caseHeight / 2, caseDepth / 2);
        glVertex3f(caseWidth / 2, caseHeight / 2, caseDepth / 2);
        glVertex3f(-caseWidth / 2, caseHeight / 2, caseDepth / 2);



        glVertex3f(-caseWidth / 2, caseHeight / 2, -caseDepth / 2);
        glVertex3f(caseWidth / 2, caseHeight / 2, -caseDepth / 2);
        glVertex3f(caseWidth / 2, caseHeight / 2, caseDepth / 2);
        glVertex3f(-caseWidth / 2, caseHeight / 2, caseDepth / 2);


        glVertex3f(-caseWidth / 2, -caseHeight / 2, -caseDepth / 2);
        glVertex3f(caseWidth / 2, -caseHeight / 2, -caseDepth / 2);
        glVertex3f(caseWidth / 2, -caseHeight / 2, caseDepth / 2);
        glVertex3f(-caseWidth / 2, -caseHeight / 2, caseDepth / 2);
        glEnd();


        glColor3f(0.5, 0.5, 0.5);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, pcs);
        glBegin(GL_QUADS);

        glTexCoord2f(1, 0);
        glVertex3f(-caseWidth / 2, -caseHeight / 2, caseDepth / 2 - 5);
        glTexCoord2f(0, 0);
        glVertex3f(caseWidth / 2, -caseHeight / 2, caseDepth / 2 - 5);
        glTexCoord2f(0, 1);
        glVertex3f(caseWidth / 2, caseHeight / 2, caseDepth / 2 - 5);
        glTexCoord2f(1, 1);
        glVertex3f(-caseWidth / 2, caseHeight / 2, caseDepth / 2 - 5);
        glEnd();
        glColor3f(0.5, 0.5, 0.5);

        glBindTexture(GL_TEXTURE_2D, pcb);
        glBegin(GL_QUADS);

        glTexCoord2f(1, 0);
        glVertex3f(caseWidth / 2, -caseHeight / 2, -caseDepth / 2);
        glTexCoord2f(0, 0);
        glVertex3f(caseWidth / 2, -caseHeight / 2, caseDepth / 2);

        glTexCoord2f(0, 1);
        glVertex3f(caseWidth / 2, caseHeight / 2, caseDepth / 2);
        glTexCoord2f(1, 1);
        glVertex3f(caseWidth / 2, caseHeight / 2, -caseDepth / 2);
        glEnd();
        glColor3f(0.5, 0.5, 0.5);

        glBindTexture(GL_TEXTURE_2D, pcf);
        glBegin(GL_QUADS);

        glTexCoord2f(1, 0);
        glVertex3f(-caseWidth / 2, -caseHeight / 2, -caseDepth / 2);
        glTexCoord2f(0, 0);

        glVertex3f(-caseWidth / 2, -caseHeight / 2, caseDepth / 2);
        glTexCoord2f(0, 1);


        glVertex3f(-caseWidth / 2, caseHeight / 2, caseDepth / 2);
        glTexCoord2f(1, 1);

        glVertex3f(-caseWidth / 2, caseHeight / 2, -caseDepth / 2);

        glEnd();
        glDisable(GL_TEXTURE_2D);
        glPopMatrix();
    }
    static void drawGamingTable(float width, float depth, float height, float x, float y, float z, float rotation) {
        glPushMatrix();
        glTranslatef(x, y, z);
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

        glVertex3f(width - 5, 0, -10);
        glVertex3f(width - 5, height, depth);
        glVertex3f(width - 5, 0, -10);
        glVertex3f(width - 5, 0, depth);
        glVertex3f(width - 5, height, 0);
        glVertex3f(width - 5, 0, depth);

        glEnd();
        glBegin(GL_QUADS);
        glVertex3f(0, height, 0);
        glVertex3f(width, height, 0);
        glVertex3f(width, height, depth + 2);
        glVertex3f(0, height, depth + 2);
        glEnd();
        glPopMatrix();
    }
    void drawGamingChair(float x, float y, float z, float rotationAngle) {
        glPushMatrix();


        glTranslatef(x, y, z);
        glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f);

        glPushMatrix();
        glRotatef(90, 1.0f, 0.0f, 0);
        glColor3f(0.5f, 0.5f, 0.5f);
        glTranslatef(0.0f, 0.0f, 0.0f);
        GLUquadric* quadric = gluNewQuadric();
        gluCylinder(quadric, 5.0f, 5.0f, 150, 200, 32);
        gluDeleteQuadric(quadric);
        glPopMatrix();
        glLineWidth(15);
        glPointSize(100);

        glBegin(GL_LINES);
        glVertex3f(-5, -150, 0);
        glVertex3f(-50, -180, 0);
        glVertex3f(-5, -150, 0);
        glVertex3f(50, -180, 0);
        glVertex3f(-5, -150, 0);
        glVertex3f(0, -180, 50);
        glVertex3f(-5, -150, 0);
        glVertex3f(0, -180, -50);
        glEnd();
        //
        glPushMatrix();
        glColor3f(0.7f, 0.7f, 0.7f);
        glBegin(GL_POLYGON);
        for (int i = 0; i < 320; ++i) {
            float angle = 2.0f * 3.14 * float(i) / float(320);
            float px = 70 * cosf(angle);
            float py = 70 * sinf(angle);
            glVertex3f(px, 0, py);
        }
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.0f, 0.0f, 40.0f);
        glColor3f(0.7f, 0.7f, 0.7f);
        glBegin(GL_QUADS);
        glVertex3f(-60, 0.0f, 0);
        glVertex3f(-60, 0.0f, -75);
        glVertex3f(-90, 150, -75);
        glVertex3f(-90, 150, 0);
        glEnd();
        glPopMatrix();



        glPopMatrix();
    }


    void drawPlayStationController(float x, float y, float z, float angleX, float angleY, float angleZ) {
        float bodyWidth = 20.0f;
        float bodyHeight = 5.0f;
        float bodyDepth = 15.0f;
        float buttonRadius = 2.0f;

        // ÏÇÝÚ ÈÏÇíÉ ÇáÊÇÈÚ
        glPushMatrix();
        glTranslatef(x, y, z);

        glRotatef(angleX, 1.0f, 0.0f, 0.0f);
        glRotatef(angleY, 0.0f, 1.0f, 0.0f);
        glRotatef(angleZ, 0.0f, 0.0f, 1.0f);

        // ÑÓã ÇáÌÓã ÇáÑÆíÓí (ÞÈÖÉ ÇáÊÍßã)
        glColor3f(0.1f, 0.1f, 0.1f); // áæä ÇáÞÈÖÉ (ÃÓæÏ)
        glBegin(GL_QUADS);
        // ÇáÌæÇäÈ ÇáÃãÇãíÉ æÇáÎáÝíÉ
        glVertex3f(-bodyWidth / 2, -bodyHeight / 2, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, -bodyHeight / 2, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, bodyHeight / 2, -bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, bodyHeight / 2, -bodyDepth / 2);

        glVertex3f(-bodyWidth / 2, -bodyHeight / 2, bodyDepth / 2);
        glVertex3f(bodyWidth / 2, -bodyHeight / 2, bodyDepth / 2);
        glVertex3f(bodyWidth / 2, bodyHeight / 2, bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, bodyHeight / 2, bodyDepth / 2);

        // ÇáÌæÇäÈ ÇáÌÇäÈíÉ
        glVertex3f(-bodyWidth / 2, -bodyHeight / 2, -bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, -bodyHeight / 2, bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, bodyHeight / 2, bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, bodyHeight / 2, -bodyDepth / 2);

        glVertex3f(bodyWidth / 2, -bodyHeight / 2, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, -bodyHeight / 2, bodyDepth / 2);
        glVertex3f(bodyWidth / 2, bodyHeight / 2, bodyDepth / 2);
        glVertex3f(bodyWidth / 2, bodyHeight / 2, -bodyDepth / 2);

        // ÇáÓÞÝ æÇáÞÇÚÏÉ
        glVertex3f(-bodyWidth / 2, -bodyHeight / 2, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, -bodyHeight / 2, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, -bodyHeight / 2, bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, -bodyHeight / 2, bodyDepth / 2);

        glVertex3f(-bodyWidth / 2, bodyHeight / 2, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, bodyHeight / 2, -bodyDepth / 2);
        glVertex3f(bodyWidth / 2, bodyHeight / 2, bodyDepth / 2);
        glVertex3f(-bodyWidth / 2, bodyHeight / 2, bodyDepth / 2);
        glEnd();

        // ÑÓã ÇáÃÒÑÇÑ
        glColor3f(1.0f, 1.0f, 1.0f); // áæä ÇáÃÒÑÇÑ (ÃÈíÖ)
        drawButton(4.0f, 2.0f, 0.0f, buttonRadius); // ÒÑ Çáíãíä
        drawButton(-4.0f, 2.0f, 0.0f, buttonRadius); // ÒÑ ÇáíÓÇÑ
        drawButton(0.0f, -2.0f, 0.0f, buttonRadius); // ÒÑ ÇáÃÓÝá

        // äåÇíÉ ÇáÊÇÈÚ
        glPopMatrix();
    }

    // ÊÇÈÚ ÑÓã ÇáÒÑ
    void drawButton(float x, float y, float z, float radius) {
        glPushMatrix();
        glTranslatef(x, y, z);
        glBegin(GL_TRIANGLE_FAN);
        for (int i = 0; i <= 360; i += 15) {
            float angle = i * 3.14159f / 180.0f;
            glVertex3f(radius * cos(angle), radius * sin(angle), 0.0f);
        }
        glEnd();
        glPopMatrix();
    }

};