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
#include "Waterfall.h"
#include "Market.h"
#include "Model_3DS.h"
#include "Wall.h"


double angle = 0.0;
bool keys[255];

CameraConfiguration camera;
BilalMain bilal;
OutSpace outspace;
Waterfall waterfall;
Market market;
Model_3DS* tree; 
//GLTexture BARK, Leaf;
int windowWidth = 1920, windowHeight = 1080;

void keyPressed(unsigned char key, int x, int y) {
    camera.processKeyboardInput(key, true);
   
    
}

void keyReleased(unsigned char key, int x, int y) {
    camera.processKeyboardInput(key, false);
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

    // Set the camera configuration
    camera.updateMovement();
    camera.setupCamera();

    // Render the skybox first (background)
    glPushMatrix();
    glDisable(GL_DEPTH_TEST);   
    glTranslatef(camera.cameraX, camera.cameraY, camera.cameraZ);  
    outspace.drawskybox();  // Draw the skybox
    glEnable(GL_DEPTH_TEST);  // Re-enable depth testing
    glPopMatrix();
     
     bilal.display();
    //waterfall.draw();
    outspace.draw();
    market.draw();

    glFlush();  // Render the scene
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
        //waterfall.init();
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
