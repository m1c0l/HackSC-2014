#ifndef LEVEL_H
#define LEVEL_H

#include "Floor.h"
#include "SFML_Headers.h"

class Floor;

class Level {
public:
	Level(int amount);
	int &getFloorLevel();
	Floor **getFloor();
	~Level();
private:
	Floor **floors;
	int floorLevel;
};

#endif
