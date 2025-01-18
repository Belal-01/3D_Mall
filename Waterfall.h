

#include <GL/glut.h>


class Waterfall {
private:
    float waveTime;
    float frequency;
    float amplitude;
    GLuint tableTex;
    GLuint chairTex;
    GLuint fantainTex;
    GLuint groundTex;
    GLuint climingRose;
    int numDrops =10;


public:

    float dropProgress[100];
    Waterfall();
    void draw();
    void init();
    void drawUmbrella(float x, float y, float z, float radius, float height, float handleLength, float handleRadius);
    void drawRoundedWall(float cx, float cy, float cz, float innerRadius, float outerRadius, float height, int segments);
    void Chair(float x, float y, float z, float radius, float thickness, float legHeight, float legRadius, float angle);
    void drawRoundedTable(float x, float y, float z, float radius, float thickness, float legHeight, float legRadius);
    void drawWaterDrop(float t, float startX, float startY, float startZ, float controlX, float controlY, float controlZ, float endX, float endY, float endZ);
    void drawWaterDropSeries(float startX, float startY, float startZ,
        float controlX, float controlY, float controlZ,
        float endX, float endY, float endZ);
    void drawFantain(float x, float y, float z);
    void drawWater(float centerx, float centery, float centerz, float width, float length, int gridSize);
   void drawFenceWater(float cornerx, float cornery, float cornerz, float len, float wid, float hig);
   void drawground(float x, float y, float z, float len, float wid);
   void drawWallWater(float cornerx, float cornery, float cornerz, float len, float hig);
   void drawRectangleXZ(float x, float y, float z, float len, float wid);
   void drawNet(float startX, float startY, float z, int columns, int rows, float cellSize, float thickness);
};

 

