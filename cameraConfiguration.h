#ifndef CAMERACONFIGURATION_H
#define CAMERACONFIGURATION_H

#include <GL/glut.h>
#include <cmath>
#include <map>
#include "keyboardConfiguration.h"

class CameraConfiguration {
public:
    std::map<char, bool> keys;

    float cameraX = 300, cameraY = 600, cameraZ = -1000;
    float cameraAngleX = 0.0f, cameraAngleY = 0.0f;

    float cameraSpeed = 25.1f;

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
