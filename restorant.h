#pragma once

class Resturant {
public:
	void Table(int width, int tall, int height,int textureID);
	void Chair(int width, int tall, int height, int rotateQ, int textureID);
	void drawTable(int width, int tall,int textureID);
private:
	void TableLeg(int width, int tall, int height);
	void ChairLeg(int width, int tall,  int start, int height);
};
