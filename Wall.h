
 class Wall {
    /*int x1, x2, y1, y2, z1, z2, width;*/
public:
    void sideWall(int x1, int y1, int y2, int z1, int z2, int width , int textureID, int RepeatX, int RepeatY, int textureID2, int RepeatX2, int RepeatY2);
    void frontWall(int x1, int x2, int y1, int y2, int z1, int width, int textureID, int RepeatX, int RepeatY, int textureID2, int RepeatX2, int RepeatY2);
    void Roof(int x1, int x2, int y1, int z1, int z2, int width ,int textureID , int RepeatX,int RepeatY);
    void floor(int x1, int x2, int y1, int z1, int z2 ,int textureID, float RepeatX, float RepeatY);
    void create(int x1, int x2, int y1, int y2, int z1, int z2);

    

};
