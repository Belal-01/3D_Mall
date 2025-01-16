#pragma once
//#include "Wall.h"
//#include "Glass.h"
class BilalMain {
public:
	void display();
	void rightBuilding();
	void leftBuilding();
	void init();
	/*void stairs(int x, int y, int z, int Q);*/
	
private:
	//Wall wall;
	//Glass glass;
	int RoofFloorTexture , secondFloorTexture, textureID ,interiorWall,exteriorWall;
	int oneStairImg;
};
