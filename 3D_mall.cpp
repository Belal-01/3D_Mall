// test2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <GL/glut.h> // Include the GLUT header file
#include "texture.h"
#include <iostream>
#include "cameraConfiguration.h"
#include "BilalMain.h"
#include "OutSpace.h"
#include "abd.h"
#include "FurnitureStore.h"
#include "elevator.h"
#include "Waterfall.h"
#include "Market.h"
#include "Model_3DS.h"
//#include "Wall.h"
double angle = 0.0;
bool keys[255];

CameraConfiguration camera;
BilalMain bilal;
OutSpace outspace;
Abd abd;
FurnitureStore furniturStore;
extern Elevator elevator;
Waterfall waterfall;
Market market;

int windowWidth = 1920, windowHeight = 1080;
GLfloat lightPosition[] = { -9000.0f, 4000, 6000.0f, 1.0f }; // Position of the "sun"
GLfloat shadowMatrix[16];

void keyPressed(unsigned char key, int x, int y) {
    camera.processKeyboardInput(key, true);
    elevator.moveElevator(key, true);
    
   
    
}

void keyReleased(unsigned char key, int x, int y) {
    camera.processKeyboardInput(key, false);
    elevator.moveElevator(key, false);

}


void mouseMotion(int x, int y) {
    int dx = x - (windowWidth / 2);
    int dy = y - (windowHeight / 2);
    camera.rotateCamera(dx, dy);
    glutWarpPointer(windowWidth / 2, windowHeight / 2);
    glutPostRedisplay();
}




void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    // set the camera confiuration
    camera.updateMovement();
    camera.setupCamera();
    elevator.updateMovment();



    // Render the skybox first (background)
    glPushMatrix();
    glDisable(GL_DEPTH_TEST);
    glTranslatef(camera.cameraX, camera.cameraY, camera.cameraZ);
    outspace.drawskybox();  // Draw the skybox
    glEnable(GL_DEPTH_TEST);  // Re-enable depth testing
    glPopMatrix();

    
    //here put ur display
    /* outspace.draw();*/
     abd.AbdDraw(camera.cameraX, camera.cameraY, camera.cameraZ);
     elevator.upateDoorsMovments(camera.cameraX, camera.cameraY, camera.cameraZ);
     furniturStore.display();
     bilal.display();
     outspace.drawshadow();
     market.draw();
     waterfall.draw();
   
    glFlush(); // Render the line
    glutSwapBuffers();
}
void reshape(int w, int h) {
    windowWidth = w;
    windowHeight = h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (double)w / (double)h, 0.1, 12000.0);
    glMatrixMode(GL_MODELVIEW);
}

void initLighting() {
    glEnable(GL_LIGHTING);  // Enable global lighting
    glEnable(GL_LIGHT0);    // Enable LIGHT0 for sunlight
    glEnable(GL_DEPTH_TEST); // Enable depth testing for proper rendering

    //GLfloat lightAmbient[] = { 0.5, 0.5, 0.5, 1.0f };    // Soft ambient light
    //GLfloat lightDiffuse[] = { 1.0f, 1, 1, 1.0f };    // Bright sunlight
    //GLfloat lightSpecular[] = { 1.0f, 1.0f, 0.9f, 1.0f };   // Highlights


    GLfloat lightAmbient[] = { 0.5, 0.5, 0.5, 1.0f };    // Soft ambient light
    GLfloat lightDiffuse[] = { 1.0f, 1, 1, 1.0f };    // Bright sunlight
    GLfloat lightSpecular[] = { 1.0f, 1.0f, 0.9f, 1.0f };   // Highlights

    // Sunlight position

    // Apply sunlight properties to LIGHT0
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glMaterialfv(GL_FRONT, GL_SPECULAR, lightSpecular);
    glMateriali(GL_FRONT, GL_SHININESS, 128);

    glShadeModel(GL_SMOOTH); // Smooth shading for realistic lighting


}


void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(60.0, (double)windowWidth / (double)windowHeight, 0.1, 12000);

    glMatrixMode(GL_MODELVIEW);
 //   
    /*glEnable(GL_TEXTURE_2D);*/

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // here put your inits 
    bilal.init();
    outspace.init();
    abd.init();
    furniturStore.init();
    initLighting();
    waterfall.init();
    market.init();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutGameModeString("1920x1080:32@60");
    glutEnterGameMode();
    glutSetCursor(GLUT_CURSOR_NONE);

    init();
    // texture = DrawTextures();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyPressed);
    glutKeyboardUpFunc(keyReleased);
    glutPassiveMotionFunc(mouseMotion);
    glutReshapeFunc(reshape);

    glutWarpPointer(windowWidth / 2, windowHeight / 2);

    glutMainLoop();
    return 0;
}






//void timer(int value) {
//    // Increase the angle for smooth rotation
//
//   
//    glutPostRedisplay(); // Request to redraw the window
//    glutTimerFunc(50, timer, 0); // Call timer again in ~16 ms (~60 FPS)
//}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
