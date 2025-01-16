#pragma once
#include <GL/glut.h>

class FurnitureStore {
public:

    // Method to draw a table
    void drawTable(float x, float y, float z, float width, float depth, float height, int red, int green, int blue, int textureID);
    void drawSofa(float x, float y, float z, float width, float depth, float height, int red, int green, int blue, int textureID, float rotationAngle);
    void drawLeg(float x, float y, float z, float width, float depth, float height, int red, int green, int blue, int texture);
    void drawCube(float x, float y, float z, float width, float depth, float height, int red, int green, int blue, int textureID, float repeatFactor);
    void drawLambaderAtPosition(float x, float y, float z);
    void enableLampLight(float x, float y, float z);
    void circlerTable(float x, float y, float z, float radius, float height, int slices, int tabletopTexture, int columnTexture);
    void drawCirclerChair(float baseX, float baseY, float baseZ, float radius, float height, int segments, int textureID, int columntextureID, float repeatFactor);
    void display();
    void init();

private:

    int SofaTextureID, Table1TextureID, table2Texture;
    // circler table
    int CT_columnTextureID, CT_tabletopTextureID;
    // circler chair
    int CH_tabletopTextureID;

};