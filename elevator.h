#pragma once
class Elevator {
public:
	void elevatorRoom();
	void init();
	void moveElevator(unsigned char key,bool state);
	void updateMovment();
	void elevatorDoors();
	void upateDoorsMovments(int cameraX, int cameraY, int cameraZ);
	bool calculateDistance(int Door[], int cameraX, int cameraY, int cameraZ);
private:
	int elevatorFloor ,elevatorWall,Door1X=0,Door2X=0,Door3X=0;
	bool Vpressed = false;
	bool Bpressed = false;
	int MoveOnY = 0 ;
	int firstDoor[3] = { 400, 400, -3040 };
	int secondDoor[3] = { 400, 1200, -3040 };
	int thirdDoor[3] = { 400, 2000, -3040 };

};
