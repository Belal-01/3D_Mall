 
class OutSpace {
 
   
public:
    int fatainTex1;
    int fatainTex2;
    int grassTex;
    int grassSpaceTex;
    int flowerTex;
    int flower1Tex;
    int flagTex;
    int WalkwayTex;
    int whiteStone;
    int himilayan;
    int enteranc;
    int flowerLand;
    int fence;

    void drawFlag(float x1, float y1, float z1, float len, float hig);
    void drawConicalStick(float baseRadius, float topRadius, float height, float x, float y, float z,  float len, float wid);
    void  drawStreet(float x1, float x2, float y, float z1, float z2);
    void draw();
    void init();
    void drawParking(float x, float y, float z);
    
    void drawBigTree(float x, float y, float z,float h, float scale);
    void sidewalkX(float x1, float y1, float z1, float len, float wid);
    void drawMianCircle(float centerx, float centery, float centerz, float rd, float red, float green, float blue);
void drawFlower(float x, float y, float z, float petalRadius, float centerRadius, int petalCount);
void drawWater(float centerx, float centery, float centerz, float wid, float len, int gridSize);
void drawFantain(float cornerx, float cornery, float cornerz, float len, float wid, float hig);
void drawEntranceArch(float x, float y, float z, float width, float height, float archRadius);
void drawGrass(float x1, float x2, float y, float z1, float z2, float repx, float repy,int tex);
void drawSmallFantain(float cornerx, float cornery, float cornerz, float len, float wid, float hig);
void drawWalkway(float x, float y, float z1, float len, float wid, float repx, float repy);
void drawSperatedGlass(int x, int y, int z, float len, float alpha);
void drawGrassSquare(float x, float y, float z, float len, float wid);
void drawShrubTree(float centerX, float centerY, float centerZ, float radius, int segments, float height, float scale);
void drawEnterance(float x, float y, float z, float len, float wid);
void drawSquareTree(float centerX, float centerY, float centerZ, float wid, float height, float scale );
void drawFence(float x, float y, float z, float len,float  hig);
};

 
