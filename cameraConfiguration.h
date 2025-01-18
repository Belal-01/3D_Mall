#ifndef CAMERACONFIGURATION_H
#define CAMERACONFIGURATION_H

#include <GL/glut.h>
#include <cmath>
#include <map>
#include "keyboardConfiguration.h"

class CameraConfiguration {
public:
    std::map<char, bool> keys;

    //float cameraX = -3670, cameraY = 2800, cameraZ = 4600;
    float cameraX = 500, cameraY = 200, cameraZ = 0;
    float cameraAngleX = 0.5, cameraAngleY = -45;
    float cameraSpeed = 20;
    float mouseSensitivity = 0.005f;

    bool isJumping = false;
    float jumpSpeed = 0.2f;
    float gravity = 0.1f;
    float jumpOffset = 0.0f;

    KeyboardConfiguration keyboardConfig;

    void moveForward();
    void moveBackward();
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void startJump();

    void updateJump();
    void setupCamera();
    void rotateCamera(int dx, int dy);
    void processKeyboardInput(unsigned char key, bool isPressed);
    void updateMovement();
};

#endif
