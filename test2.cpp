// test2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <GL/glut.h> // Include the GLUT header file
//#include <GL/texture.h>
#include "texture.h"
#include <iostream>
#include "cameraConfiguration.h"
#include "Wall.h"
#include "Glass.h"


int textureID ,secondFloorTexture ,RoofFloorTexture;

double angle = 0.0;
bool keys[255];

CameraConfiguration camera;
Wall wall;
Glass glass;


int windowWidth = 1920, windowHeight = 1080;

void keyPressed(unsigned char key, int x, int y) {
    camera.processKeyboardInput(key, true);
   
    
}

void keyReleased(unsigned char key, int x, int y) {
    camera.processKeyboardInput(key, false);
}





void rightBuilding() {
    wall.frontWall(0, 4000, 0, 1600, -3000, 20);
    wall.sideWall(4000, 0, 1600, 5000, -3000, 20);
    /*wall.sideWall(0, 0, 1600, 5000, 0, 20);*/
    glass.drawWall(0, 0, 0, 1600, 5000, 0, 0.8f);

    wall.frontWall(0, 4000, 0, 1600, 5000, 20);
    wall.Roof(0, 4000, 800, 5000, -3000, 20,secondFloorTexture,40,80);
    wall.Roof(0, 4000, 1600, 5000, -3000, 20, RoofFloorTexture, 40,80);

}

void leftBuilding() {
    // the back wall
    wall.frontWall(-4000,0,0,800,-3000,20);
    wall.sideWall(-4000,0,800,0,-1000,20);
    wall.sideWall(-4000, 0, 800, -2000, -3000, 20);

    wall.Roof(-4000,-1000,800,0,-3000,20,RoofFloorTexture,40,30);
    wall.Roof(-1000, 0, 800, 0, -1500, 20,RoofFloorTexture,10,15);
   /* wall.frontWall(-4000, -800, 0, 800, 0, 20);*/
    glass.drawfrontWall(-4000, -800, 0, 800, 0, 0.7f);




    glass.drawWall(-4000,-5000,0,1200,-1000,-2000,0.7f);
    glass.drawTriangle(-4000,-3800,-5000,0,800,1200,-1000,0.7f);
    glass.drawTriangle(-4000, -3800, -5000, 0, 800, 1200, -2000, 0.7f);
    glass.drawRoof(-5000, -3800, 1200, -1000, -2000, 0.7f);

    // 
    // elevatore in the first building
    wall.sideWall(-1000, 0, 2400, -1500, -3000,10);
    wall.sideWall(0, 0, 1600, -1500, -3000, 10);
    wall.sideWall(0, 1600, 2400, -2000, -3000, 10);
    glass.drawfrontWall(-1000, 0, 800, 2400, -3000, 0.7f);
    glass.drawfrontWall(-1000, 0, 1600, 2400, -1500, 0.7f);
    glass.drawfrontWall(-600, 0, 800, 1600, -1500, 0.7f);


    wall.Roof(-1000, 0, 2400, -1500, -3000, 20, RoofFloorTexture, 10,15);



    


}



void timer(int value) {
    // Increase the angle for smooth rotation

   
    glutPostRedisplay(); // Request to redraw the window
    glutTimerFunc(50, timer, 0); // Call timer again in ~16 ms (~60 FPS)
}

void keyboard(unsigned char key, int x, int y) {
    //switch (key) {
    //case 'w': // Move forward
    //    camera.MoveForward(0.1f);
    //    break;
    //case 's': // Move backward
    //    camera.MoveForward(-0.1f);
    //    break;
    //case 'a': // Move left
    //    camera.MoveRight(-0.1f);
    //    break;
    //case 'd': // Move right
    //    camera.MoveRight(0.1f);
    //    break;
    //case 'q': // Move upward
    //    camera.MoveUpward(0.1f);
    //    break;
    //case 'e': // Move downward
    //    camera.MoveUpward(-0.1f);
    //    break;
    //case 27: // Escape key
    //    exit(0);
    //    break;
    //}
    glutPostRedisplay(); // Request a redraw

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
    camera.updateMovement();
    camera.setupCamera();
    
    glPushMatrix();
    glTranslated(0, 0, -8);
     wall.floor(-9000, 6000,0, 9000, -6000, textureID,50);
     leftBuilding();
     rightBuilding();
    /*glass.draw(40,40,-40,0.5);*/
    glPopMatrix();
 
   
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

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (double)windowWidth / (double)windowHeight, 0.1, 12000.0);

 //   
    glEnable(GL_TEXTURE_2D);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    char fileName[] = "floorImg.bmp";


    textureID = LoadTexture(fileName,255.0f); 
    secondFloorTexture = LoadTexture((char*)"insidMallFloorTexture.bmp", 255.0f);
    RoofFloorTexture = LoadTexture((char*)"floortexture.bmp", 255.0f); // Use 255 for fully opaque
    if (textureID < 0) {
        std::cerr << "Failed to load texture." << std::endl;
        exit(1);
    }
 
    
   
    
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


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
