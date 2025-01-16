#include "cameraConfiguration.h"
#include <iostream>
#include<algorithm>


float clamp(float value, float min, float max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}
void CameraConfiguration::moveForward() {
    cameraX += cameraSpeed * sin(cameraAngleY);
    cameraZ -= cameraSpeed * cos(cameraAngleY);
}


void CameraConfiguration::moveBackward() {
    cameraX -= cameraSpeed * sin(cameraAngleY);
    cameraZ += cameraSpeed * cos(cameraAngleY);
}

void CameraConfiguration::moveLeft() {
    cameraX -= cameraSpeed * cos(cameraAngleY);
    cameraZ -= cameraSpeed * sin(cameraAngleY);
}

void CameraConfiguration::moveRight() {
    cameraX += cameraSpeed * cos(cameraAngleY);
    cameraZ += cameraSpeed * sin(cameraAngleY);
}

void CameraConfiguration::moveUp() {
    cameraY += cameraSpeed;
}

void CameraConfiguration::moveDown() {
    cameraY -= cameraSpeed;
}

void CameraConfiguration::startJump() {
    if (!isJumping) {
        isJumping = true;
    }
}

void CameraConfiguration::updateJump() {
    if (isJumping) {
        jumpOffset += jumpSpeed;
        jumpSpeed -= gravity;

        if (jumpOffset <= 0.0f) {
            jumpOffset = 0.0f;
            jumpSpeed = 0.2f;
            isJumping = false;
        }
    }
}

void CameraConfiguration::setupCamera() {
    gluLookAt(cameraX, cameraY + jumpOffset, cameraZ,
        cameraX + sin(cameraAngleY),
        cameraY + jumpOffset + sin(cameraAngleX),
        cameraZ - cos(cameraAngleY),
        0.0, 1.0, 0.0);
}

void CameraConfiguration::rotateCamera(int dx, int dy) {
    cameraAngleY += dx * mouseSensitivity;
    cameraAngleX -= dy * mouseSensitivity;

    cameraAngleX = clamp(cameraAngleX, -1.5f, 1.5f);
   
}

void CameraConfiguration::processKeyboardInput(unsigned char key, bool isPressed) {
    keys[key] = isPressed;
}

void CameraConfiguration::updateMovement() {
    if (keys[keyboardConfig.forwardKey]) moveForward();
    if (keys[keyboardConfig.backwardKey]) moveBackward();
    if (keys[keyboardConfig.leftKey]) moveLeft();
    if (keys[keyboardConfig.rightKey]) moveRight();
    if (keys[keyboardConfig.upKey]) moveUp();
    if (keys[keyboardConfig.downKey]) moveDown();
    if (keys[keyboardConfig.jumpKey]) startJump();
    if (keys[keyboardConfig.exitKey]) exit(0);
}
