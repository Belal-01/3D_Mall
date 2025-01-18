#ifndef DOOR_H
#define DOOR_H

class Door {
private:
    float xPosition, zPosition, yPosition;
    float openAmount;
    float rotate;
    float transparency;
    float width,hight;
    float calculateDistance(float cameraX, float cameraY, float cameraZ) const;

public:
    Door(float x,float y, float z, float alpha,float rotate,float width ,float hight);
    void updateState(float cameraX,float cameraY,float cameraZ);
    void draw();
};

#endif // DOOR_H
