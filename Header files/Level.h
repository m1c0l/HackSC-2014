#ifndef LEVEL_H
#define LEVEL_H

#include "Floor.h"
#include "SFML_Headers.h"

class Floor;

class Level {
public:
	Level();
	~Level();
private:
	Floor **floors;
	
};

#endif
