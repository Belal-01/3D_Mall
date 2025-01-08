
#include <GL/glut.h>
#include <iostream>
#include <cstdlib> // ������ rand � srand
#include <ctime>   // ������ time
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

        // ��� �� ���� ������ ������ ��� �����
        glColor3f(0.0f, 0.0f, 0.0f); // ��� ���� ������
        glBegin(GL_LINES);
        glVertex3f(-fridgeWidth / 2, 70, fridgeDepth / 2);
        glVertex3f(fridgeWidth / 2, 70, fridgeDepth / 2);
        glEnd();

        // ��� �������
        glColor3f(0.7f, 0.7f, 0.7f); // ��� ������� (����� ����)
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

        // ��� ��� ������
        glColor3f(0.9f, 0.9f, 0.9f); // ��� ������ (���� �� ����� ����)
        glBegin(GL_QUADS);

        // ��� �����
        glVertex3f(-fridgeWidth / 2, 0, fridgeDepth / 2);
        glVertex3f(fridgeWidth / 2, 0, fridgeDepth / 2);
        glVertex3f(fridgeWidth / 2, fridgeHeight, fridgeDepth / 2);
        glVertex3f(-fridgeWidth / 2, fridgeHeight, fridgeDepth / 2);

        // ��� ����
        glVertex3f(-fridgeWidth / 2, 0, -fridgeDepth / 2);
        glVertex3f(fridgeWidth / 2, 0, -fridgeDepth / 2);
        glVertex3f(fridgeWidth / 2, fridgeHeight, -fridgeDepth / 2);
        glVertex3f(-fridgeWidth / 2, fridgeHeight, -fridgeDepth / 2);

        // ������ ��������
        glVertex3f(-fridgeWidth / 2, 0, -fridgeDepth / 2);
        glVertex3f(-fridgeWidth / 2, 0, fridgeDepth / 2);
        glVertex3f(-fridgeWidth / 2, fridgeHeight, fridgeDepth / 2);
        glVertex3f(-fridgeWidth / 2, fridgeHeight, -fridgeDepth / 2);

        glVertex3f(fridgeWidth / 2, 0, -fridgeDepth / 2);
        glVertex3f(fridgeWidth / 2, 0, fridgeDepth / 2);
        glVertex3f(fridgeWidth / 2, fridgeHeight, fridgeDepth / 2);
        glVertex3f(fridgeWidth / 2, fridgeHeight, -fridgeDepth / 2);

        // ����� ��������
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
        glRotatef(angleX, 10.0f, 0.0f, 0.0f); // ����� ��� ������ X
        glRotatef(angleY, 0.0f, 10.0f, 0.0f); // ����� ��� ������ Y
        glRotatef(angleZ, 0.0f, 0.0f, 10.0f); // ����� ��� ������ Z

        glColor3f(0.8f, 0.8f, 0.8f); // ��� ������
        glBegin(GL_QUADS);

        // ������� ������� ������ (����)
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

        // ������ ������ (��� ��������)
        glLineWidth(3.0f);
        glColor3f(0.3f, 0.3f, 0.3f);
        glBegin(GL_LINES);
        glVertex3f(0, 10.0f, 0);
        glVertex3f(40.0f, 10.0f, 0); // ����� �� ������
        glEnd();
        glLineWidth(3.0f);
        glColor3f(0.3f, 0.3f, 0.3f);
        glBegin(GL_LINES);
        glVertex3f(0, 10.0f, -10.0f);
        glVertex3f(40.0f, 10.0f, -10.0f); // ����� �� ������
        glEnd();

        glPopMatrix();
    }
    static void drawAirConditionerWithFan(float x, float y, float z, float angleX, float angleY, float angleZ, float fanRotation) {
        glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(angleX, 10.0f, 0.0f, 0.0f); // ����� ��� ������ X
        glRotatef(angleY, 0.0f, 10.0f, 0.0f); // ����� ��� ������ Y
        glRotatef(angleZ, 0.0f, 0.0f, 10.0f); // ����� ��� ������ Z

        // ��� ���� ������
        glColor3f(0.8f, 0.8f, 0.8f); // ��� ������
        glBegin(GL_QUADS);

        // ������� ������� ������ (���� ����)
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

        glColor3f(0.8f, 0.8f, 0.8f); // ��� ��� ������
        glBegin(GL_QUADS);
        glVertex3f(20.0f, 20.0f, -0.1f);  // ����� ������ ������
        glVertex3f(60.0f, 20.0f, -0.1f);  // ����� ������ ������
        glVertex3f(60.0f, 20.0f, -1.0f);  // ����� ������ ������
        glVertex3f(20.0f, 20.0f, -1.0f);  // ����� ������ ������
        glEnd();

        // ����� ������ �������� ������ ���� ������
        glColor3f(0.0f, 0.0f, 0.0f); // ��� ��� ������

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
        // ��� ����� �������
        glLineWidth(3.0f);
        glColor3f(0.3f, 0.3f, 0.3f);
        glBegin(GL_LINES);

        // ����� ������� �� ������
        for (float i = 10.0f; i < 80.0f; i += 16.0f) {
            glVertex3f(i - 8, 40.0f, 0);
            glVertex3f(i, 40.0f, 0); // ����� ������� �� ������
        }

        // ����� ������� �� ������
        for (float i = 10.0f; i < 80.0f; i += 16.0f) {
            glVertex3f(i - 8, 40.0f, -20.0f);
            glVertex3f(i, 40.0f, -20.0f); // ����� ������� �� ������
        }

        glEnd();

        // ��� ����� ������� �������
        glColor3f(0.2f, 0.2f, 0.2f); // ��� �����
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < 360; i += 3) {
            float angle = i * 3.14159f / 180.0f;
            glVertex3f(40.0f + 20.0f * cos(angle), 20.0f + 20.0f * sin(angle), -0.1f);
        }
        glEnd();

        // ��� �������
        glColor3f(0.5f, 0.5f, 0.5f); // ��� �������
        float fanRadius = 16.0f;  // ��� ����� ������

        // ��� ������� ������ �������
        for (int i = 0; i < 3; ++i) {
            glPushMatrix();
            glTranslatef(40.0f, 20.0f, -1.0f); // ����� ������ ��� ���� �������
            glRotatef(fanRotation + i * 120.0f, 0.0f, 0.0f, 1.0f); // ������� ��� ������ Z
            glTranslatef(-40.0f, -20.0f, 1.0f); // ����� ������ ��� ����� ������

            glColor3f(0.5f, 0.5f, 0.5f); // ��� �������
            glBegin(GL_TRIANGLES);
            glVertex3f(40.0f, 20.0f, -1.0f); // ���� �������
            glVertex3f(40.0f + fanRadius * cos(0), 20.0f + fanRadius * sin(0), -1.0f); // ���� ��� ������
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

        // ��� 3 �������� ����� ���� ��� ���� x
        glColor3f(1.0f, 0.0f, 0.0f);  // ����� ������
        GLUquadricObj* quadric = gluNewQuadric(); // ���� ����� ������ ���������

        // ��������� ������ ��� y = 10
        glPushMatrix();
        glTranslatef(2.0f, 10.0f, -10.0f); // ��� ���������
        glRotatef(90, 0.0f, 1.0f, 0.0f); // ����� ��������� ����� ��� ���� x
        gluCylinder(quadric, 2.0f, 2.0f, 75.0f, 32, 32); // ��� ���������
        glPopMatrix();

        // ��������� ������� ��� y = 20
        glPushMatrix();
        glTranslatef(2.0f, 20.0f, -10.0f); // ��� ���������
        glRotatef(90, 0.0f, 1.0f, 0.0f); // ����� ��������� ����� ��� ���� x
        gluCylinder(quadric, 2.0f, 2.0f, 75.0f, 32, 32); // ��� ���������
        glPopMatrix();

        // ��������� ������� ��� y = 30
        glPushMatrix();
        glTranslatef(2.0f, 30.0f, -10.0f); // ��� ���������
        glRotatef(90, 0.0f, 1.0f, 0.0f); // ����� ��������� ����� ��� ���� x
        gluCylinder(quadric, 2.0f, 2.0f, 75.0f, 32, 32); // ��� ���������
        glPopMatrix();

        gluDeleteQuadric(quadric); // ��� ���� �������
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
        // ��� ��� �������
        glColor3f(0.5, 0.5, 0.5); // ��� ������� (���� �� ����� ����)
        
        glBegin(GL_QUADS);

        // ��� �����
        glTexCoord2f(0, 0);
        glVertex3f(-machineWidth / 2, 0, machineDepth / 2);
        glTexCoord2f(1, 0);
        glVertex3f(machineWidth / 2, 0, machineDepth / 2);
        glTexCoord2f(1, 1);
        glVertex3f(machineWidth / 2, machineHeight, machineDepth / 2);
        glTexCoord2f(0, 1);
        glVertex3f(-machineWidth / 2, machineHeight, machineDepth / 2);
        glEnd();
        glColor3f(0.1, 0.1, 0.1); // ��� ������� (���� �� ����� ����)

        glBegin(GL_QUADS);
        // ��� ����
        glVertex3f(-machineWidth / 2, 0, -machineDepth / 2);
        glVertex3f(machineWidth / 2, 0, -machineDepth / 2);
        glVertex3f(machineWidth / 2, machineHeight, -machineDepth / 2);
        glVertex3f(-machineWidth / 2, machineHeight, -machineDepth / 2);

        // ������ ��������
        glVertex3f(-machineWidth / 2, 0, -machineDepth / 2);
        glVertex3f(-machineWidth / 2, 0, machineDepth / 2);
        glVertex3f(-machineWidth / 2, machineHeight, machineDepth / 2);
        glVertex3f(-machineWidth / 2, machineHeight, -machineDepth / 2);

        glVertex3f(machineWidth / 2, 0, -machineDepth / 2);
        glVertex3f(machineWidth / 2, 0, machineDepth / 2);
        glVertex3f(machineWidth / 2, machineHeight, machineDepth / 2);
        glVertex3f(machineWidth / 2, machineHeight, -machineDepth / 2);

        // ����� ��������
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

    // ��� ������
    static void drawCeilingFanWithArm(float x, float y, float z, float angleX, float angleY, float angleZ, float fanRotation) {
        glPushMatrix();
        glTranslatef(x, y, z);
        glRotatef(angleX, 10.0f, 0.0f, 0.0f); // ����� ��� ������ X
        glRotatef(angleY, 0.0f, 10.0f, 0.0f); // ����� ��� ������ Y
        glRotatef(angleZ, 0.0f, 0.0f, 10.0f); // ����� ��� ������ Z

        // ����� ������� ������ (����� ��� ������ X)
        glRotatef(-90.0f, 1.0f, 0.0f, 0.0f); // ����� 90 ���� ��� ������ X ���� ������� ����� ������

        // ��� ������ ���������� ���� ���� �������
        glColor3f(0.5f, 0.5f, 0.5f); // ��� ������ (�� ��� �������)
        GLUquadric* quadric = gluNewQuadric(); // ����� ���� ��������

        glPushMatrix();
        glTranslatef(0.0f, 0.0f, 40.0f); // ����� ������ ��� ���� ��� ��� ������ ��� �����
        gluCylinder(quadric, 2.0f, 2.0f, 40.0f, 10, 10); // ��� ��������� (���� �������)
        glPopMatrix();

        // ��� ������ ������� �������
        glPushMatrix();
        glTranslatef(0.0f, 0.0f, 40.0f); // ����� ������ ��� ���� ���� ���� �������
        glRotatef(fanRotation, 0.0f, 0.0f, 1.0f); // ����� ������ �� �������
        glBegin(GL_QUADS); // ��� ������ ����� ����
        glVertex3f(-2.0f, -2.0f, -2.0f);
        glVertex3f(2.0f, -2.0f, -2.0f);
        glVertex3f(2.0f, 2.0f, -2.0f);
        glVertex3f(-2.0f, 2.0f, -2.0f);
        glEnd();
        glPopMatrix();

        // ��� ������� ��������� �������
        glColor3f(0.8f, 0.8f, 0.8f); // ��� �������
        float bladeLength = 40.0f; // ��� ������ (�� ������)
        float bladeWidth = 8.0f; // ��� ������ (�� ������)

        for (int i = 0; i < 4; ++i) {
            glPushMatrix();
            glTranslatef(0.0f, 0.0f, 40.0f); // ����� ������ ��� ���� �������
            glRotatef(fanRotation + i * 90.0f, 0.0f, 0.0f, 1.0f); // ������� ��� ������ Z

            // ��� ������� ���������
            glBegin(GL_QUADS);
            glVertex3f(-bladeWidth / 2.0f, -bladeLength / 2.0f, 0.0f); // ����� ���� ������
            glVertex3f(bladeWidth / 2.0f, -bladeLength / 2.0f, 0.0f); // ����� ���� ������
            glVertex3f(bladeWidth / 2.0f, bladeLength / 2.0f, 0.0f); // ����� ���� ������
            glVertex3f(-bladeWidth / 2.0f, bladeLength / 2.0f, 0.0f); // ����� ���� ������
            glEnd();

            glPopMatrix();
        }

        glPopMatrix();
    }
};


