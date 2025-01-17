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
    void drawBookshelves(int x, int y, int z, float tateFactor);
    void drawChair(int x, int y, int z, float rotateFactor, int seatTextureID, int pillowTextureID, int woodTextureID);
    void drawWallpaper(int x1, int x2, int y1, int y2, int z1, int z2, int textureID, float repeatFactor);
    void display();
    void init();
    void drawCabient(int x, int y, int z, double roateFactor);

private:

    int SofaTextureID, Table1TextureID, table2Texture;
    // circler table
    int CT_columnTextureID, CT_tabletopTextureID;
    // circler chair
    int CH_tabletopTextureID;
    // shelves
    int shelves1TextureID, CabinetLeftDoor1TextureID, CabinetRightDoor1TextureID;
    // cabinet
    int CabinetLeftDoor2TextureID, CabinetRightDoor2TextureID;
    // chair fabric
    int FabricChair1TextureID, FabricChair1WoodTextureID;
    // chair2 fabric
    int FabricChair2TextureID, FabricChair2WoodTextureID;
    // legs
    int LegsID;
    //
    int TopTmpTable1TextureID, TopTmpTable2TextureID;
    // walls
    int WallID;
    // tmp
    int tmpTextureID;


};