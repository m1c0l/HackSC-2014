#include "Level.h"

Level::Level(int amount) {
	floorLevel = 0;
	floors = new Floor*[amount];
	// TODO: customize the floors here
	for (int i = 0; i < amount; i++) {
		if (i == amount - 1){
			floors[i] = new Floor(2, 0);
		}else{
			floors[i] = new Floor(2, 2);
		}
	}
}

int &Level::getFloorLevel(){
	return floorLevel;
}

Floor **Level::getFloor(){
	return floors;
}

Level::~Level() {
	for (int i = 0; i < 3; i++)
		delete floors[i];
	delete[] floors;
}