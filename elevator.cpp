#include "elevator.h";
#include <GL/glut.h>
#include "Wall.h"
#include "texture.h"
#include "restorant.h"
#include <iostream>
#include <cmath>


extern Wall wall;
extern Resturant resturant;
void Elevator::init() {
	Elevator::elevatorFloor = LoadTexture((char*)"images\\elevatorFloor.bmp", 255.0f);
	Elevator::elevatorWall = LoadTexture((char*)"images\\elevator Wall.bmp", 255.0f);

}
void Elevator::elevatorRoom() {
	glPushMatrix();
	glTranslated(0, MoveOnY, 0);
	wall.Roof(-350, 400, 0, 360, -400, 60,elevatorFloor,1,1 );
	wall.sideWall(-280, 60, 800, 380, -400, 10, elevatorWall, 1, 1, elevatorWall, 1, 1);
	wall.sideWall(380, 60, 800, 380, -400, 10, elevatorWall, 1, 1, elevatorWall, 1, 1);
	wall.Roof(-350, 400, 800, 380, -400, 60, elevatorFloor, 1, 1);
	wall.frontWall(250, 400, 60, 800, -390, 10, elevatorWall, 1, 1, elevatorWall, 1, 1);
	wall.frontWall(-260, -120, 60, 800, -390, 10, elevatorWall, 1, 1, elevatorWall, 1, 1);
	wall.frontWall(250, 400, 60, 800, 310, 10, elevatorWall, 1, 1, elevatorWall, 1, 1);
	glPopMatrix();



}
void Elevator::elevatorDoors() {
	glPushMatrix();
	glTranslated(Door1X, 0, 0);
	wall.frontWall(-300,300,0,800,5,40,resturant.sideshaurmaTable,1,1, resturant.sideshaurmaTable, 1, 1);
	wall.frontWall(0, 300, 0, 800, 30, 40, resturant.sideshaurmaTable, 1, 1, resturant.sideshaurmaTable, 1, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(Door2X, 0, 0);
	wall.frontWall(-300, 300, 880, 1680, 5, 40, resturant.sideshaurmaTable, 1, 1, resturant.sideshaurmaTable, 1, 1);
	wall.frontWall(0, 300, 880, 1680, 30, 40, resturant.sideshaurmaTable, 1, 1, resturant.sideshaurmaTable, 1, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(Door3X, 0, 0);
	wall.frontWall(-300, 500, 1700, 2540, 5, 40, resturant.sideshaurmaTable, 1, 1, resturant.sideshaurmaTable, 1, 1);
	wall.frontWall(0, 500, 1700, 2540, 30, 40, resturant.sideshaurmaTable, 1, 1, resturant.sideshaurmaTable, 1, 1);
	glPopMatrix();
}

void Elevator::moveElevator(unsigned char key, bool state) {

	if ((key == 'v' || key == 'V') && state)
		Vpressed = true;
	else if ((key == 'v' || key == 'V') && !state)
		Vpressed = false;
	else if ((key == 'b' || key == 'B') && state)
		Bpressed = true;
	else if ((key == 'b' || key == 'B') && !state)
		Bpressed = false;

	
}
void Elevator::updateMovment() {
	if (Vpressed && MoveOnY<=1680)
		MoveOnY += 10;
	else if (Bpressed && MoveOnY >= 0)
		MoveOnY -= 10;
}
void Elevator::upateDoorsMovments(int cameraX, int cameraY,int cameraZ) {
	if (calculateDistance(firstDoor, cameraX, cameraY, cameraZ)&&Door1X<=600)
		Door1X += 10;
	else if(!calculateDistance(firstDoor, cameraX, cameraY, cameraZ)&&Door1X>=0)
		Door1X -= 10;

	if (calculateDistance(secondDoor, cameraX, cameraY, cameraZ) && Door2X <= 600)
		Door2X += 10;
	else if (!calculateDistance(secondDoor, cameraX, cameraY, cameraZ) && Door2X >= 0)
		Door2X -= 10;

	if (calculateDistance(thirdDoor, cameraX, cameraY, cameraZ) && Door3X <= 600)
		Door3X += 10;
	else if (!calculateDistance(thirdDoor, cameraX, cameraY, cameraZ) && Door3X >= 0)
		Door3X -= 10;



}
bool Elevator::calculateDistance(int Door[], int cameraX, int cameraY, int cameraZ) {
	bool x = false, y= false, z=false;
	if(cameraX>-400&&cameraX<800)
		x =true;
	if (cameraY > (Door[1] - 400)&& cameraY < (Door[1] + 400))
		y = true;
	if (cameraZ>-3300&&cameraZ<-2200)
		z = true;
	if (x && y && z)
		return true;
	else
		return false;




}