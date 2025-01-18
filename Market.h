#pragma once

#include <GL/glut.h>

 class Market
{

public:
	int shoseTex;
	int woodTex;
	int fishTex;
	int fish1Tex;
	int milkTex;
	int milk1Tex;
	int milk11Tex;
	int milk111Tex;
	int milk1111Tex;
	int juce1;
	int juce11;
	int juce111;
	int juce1111;
	int glass1;
	int glass11;
	int glass111;
	int foodsale;
	int toyssale;
	int delivery;
	int toys1;
	int toys11;
	int toys111;
	int toys1111;
	int roof;
 	void draw();
	void init();
	void drawSelves(float x, float y, float z, float length, float width, float height);
	void drawWallShelves();	
	void drawroof(float x, float y, float z, float length, float wid, int tex, int rx, int ry);
	void drawPorduct(float x, float y, float z, float length, float height, int tex, int rx, int ry);
	void drawCylinder(float radius, float height, int segments);
	void drawCube(float width, float height, float depth);
	void drawShoppingCart(float x, float y, float z);

};

