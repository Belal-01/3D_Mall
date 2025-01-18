#pragma once

class Resturant {
public:
	void Table(int width, int tall, int height,int textureID);
	void Chair(int width, int tall, int height, int rotateQ, int textureID);
	void drawTable(int width, int tall,int textureID);
	void drawCone(float radius, float height, int slices);
	void resturantRoom();
	void resturantInit();
	int kitchenWallTexture;
	int tableWoodTexture;
	int KitchenFloorWoodTexture;
	int kitchenLogo , kitchenWallWood, sideshaurmaTable;
    float PI = 3.14159265358979323846;


private:
	void TableLeg(int width, int tall, int height);
	void ChairLeg(int width, int tall,  int start, int height);
	int woodWallTexture;
	int phrezFront,phrezBack;
	int shauma, shaurmaTable  ,shaurmaTable2;
	
};
