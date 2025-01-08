#ifndef ELECTRONICDEVICEDRAWER_H
#define ELECTRONICDEVICEDRAWER_H

#include <GL/glut.h>
#include <iostream>
#include <cstdlib> // · ÷„Ì‰ rand Ê srand
#include <ctime>   // · ÷„Ì‰ time
#include <random>


class ElectronicDeviceDrawer {

public:

    // —”„ «·ÃÊ«·
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
    void drawKeyboard(float x, float y, float z, float angleX, float angleY, float angleZ) {
        // √»⁄«œ «·ﬂÌ»Ê—œ
        float keyboardWidth = 60.0f;
        float keyboardHeight = 15.0f;
        float keyboardDepth = 2.0f; // ”„ﬂ «·ﬂÌ»Ê—œ
        float keyHeight = 1.0f; // «— ›«⁄ «·√“—«—
        float cableThickness = 0.5f;
        float cableLength = 20.0f;

        glPushMatrix();
        glTranslatef(x, y, z);

        //  ÿ»Ìﬁ «·œÊ—«‰
        glRotatef(angleX, 1.0f, 0.0f, 0.0f); // œÊ—«‰ ÕÊ· «·„ÕÊ— X
        glRotatef(angleY, 0.0f, 1.0f, 0.0f); // œÊ—«‰ ÕÊ· «·„ÕÊ— Y
        glRotatef(angleZ, 0.0f, 0.0f, 1.0f); // œÊ—«‰ ÕÊ· «·„ÕÊ— Z

        // —”„ «·ﬂÌ»Ê—œ
        glColor3f(0.2f, 0.2f, 0.2f); // ·Ê‰ «·ﬂÌ»Ê—œ
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
        glColor3f(0.8f, 0.8f, 0.8f); // ·Ê‰ «·√“—«—
        float keyWidth = 4.0f;
        float keyDepth = 4.0f;
        float spacing = 1.0f; // «·„”«›… »Ì‰ «·√“—«—

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

    // —”„ «··«» Ê»
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
    // —”„ «·„ﬂÌ›
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
        glColor3f(1, 1, 1); // ·Ê‰ «·Ã”„ (—„«œÌ €«„ﬁ)
        glBegin(GL_QUADS);


        // ÊÃÂ √„«„Ì
        glBindTexture(GL_TEXTURE_2D, xboxf);
        glTexCoord2f(0, 0);
        glVertex3f(-bodyWidth / 2, 0, -bodyDepth / 2);
        glTexCoord2f(1, 0);
        glVertex3f(bodyWidth / 2, 0, -bodyDepth / 2); glTexCoord2f(1, 1);
        glVertex3f(bodyWidth / 2, bodyHeight, -bodyDepth / 2); glTexCoord2f(0, 1);
        glVertex3f(-bodyWidth / 2, bodyHeight, -bodyDepth / 2);
        glBindTexture(GL_TEXTURE_2D, xboxb);

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


        glPushMatrix();
        glTranslatef(0.0f, bodyHeight + 0.1f, 0.0f);

        // ‘⁄«— Xbox
        glColor3f(0.0f, 1.0f, 0.0f); // ·Ê‰ «·‘⁄«— (√Œ÷—)
        glBegin(GL_LINES);
        glVertex3f(-3.5, 0.0f, -3.5);
        glVertex3f(3.5, 0.0f, 3.5);
        glVertex3f(3.5, 0.0f, -3.5);
        glVertex3f(-3.5, 0.0f, 3.5);
        glEnd();

        // —”„ œ«∆—… ÕÊ· «·‘⁄«—
        glColor3f(0.0f, 1.0f, 0.0f); // ·Ê‰ «·œ«∆—… (√Œ÷—)
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < 360; i++) {
            float angle = i * 3.14159f / 180.0f;
            float xPos = logoRadius * cos(angle);
            float zPos = logoRadius * sin(angle);
            glVertex3f(xPos, 0.0f, zPos);
        }
        glEnd();

        glPopMatrix();

        // —”„ “— ⁄·Ï «·Ã«‰»
        glPushMatrix();
        glTranslatef(bodyWidth / 2 + 1.0f, bodyHeight / 2, 0.0f); //  ÕœÌœ „Ê÷⁄ «·“— ⁄·Ï «·Ã«‰»

        glColor3f(0.0f, 1.0f, 0.0f); // ·Ê‰ «·“— (√Œ÷—)
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float angle = i * 3.14159f / 180.0f;
            float xPos = buttonRadius * cos(angle);
            float yPos = buttonRadius * sin(angle);
            glVertex3f(xPos, yPos, 0.0f);
        }
        glEnd();

        glPopMatrix();
        glPopMatrix();
    }

    void drawComputerMonitor(float x, float y, float z, float angleX, float angleY, float angleZ) {
        // «·√»⁄«œ «·À«» … ··‘«‘… Ê«·ﬁ«⁄œ…
        float width = 50.0f;
        float height = 30.0f;
        float screenThickness = 1.0f; // ”„ﬂ «·‘«‘…
        float baseWidth = 40.0f; //  ’€Ì— «·ﬁ«⁄œ…
        float baseDepth = 15.0f; //  ’€Ì— ⁄„ﬁ «·ﬁ«⁄œ…
        float connectorHeight = 1.5f; //  ﬁ·Ì’ ”„ﬂ «·Ê’·… ·ÌﬂÊ‰ √ﬁ· „‰ ”„ﬂ «·‘«‘…
        float buttonWidth = 3.0f; // ⁄—÷ «·“—
        float buttonHeight = 1.0f; // «— ›«⁄ «·“—

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
        glVertex3f(22, -connectorHeight + 2.0f, -0.1); //  ⁄œÌ· «— ›«⁄ «·“—
        glVertex3f(25, -connectorHeight + 2.0f, -0.1); //  ⁄œÌ· «— ›«⁄ «·“—
        glVertex3f(25, -connectorHeight + buttonHeight + 2.0f, -0.1); //  ⁄œÌ· «— ›«⁄ «·“—
        glVertex3f(22, -connectorHeight + buttonHeight + 2.0f, -0.1); //  ⁄œÌ· «— ›«⁄ «·“—
        glEnd();

        glPopMatrix();

    }
    // —”„ «·‘«‘…
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

#endif // ELECTRONICDEVICEDRAWER_H
