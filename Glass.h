//#ifndef GLASS_H
//#define GLASS_H

 class Glass {
public:
    // Constructor to initialize glass dimensions
    Glass();

    // Method to draw the glass
    void drawWall(int x1 ,int x2 ,int y1 ,int y2 ,int z1 ,int z2, float alpha);
    void drawRoof(int x1, int x2, int y1, int z1, int z2, float alpha);
    void drawTriangle(int x1, int x2,int x3, int y1,int y2 ,int y3, int z1, float alpha);
    void drawfrontWall(int x1, int x2, int y1, int y2, int z1, float alpha);
    void drawGlassDoors(float x1, float x2, float y1, float y2, float z, float alpha, float openAmount);
    void updateDoorState(float cameraX, float cameraZ, float doorX, float doorZ);
    void drawGlassDoors(float x1, float x2, float y1, float y2, float z, float alpha);
private:
    float length, width, height;
    float r, g, b, alpha; // Color and transparency
   
};

//#endif // GLASS_H
