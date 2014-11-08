#ifndef FLOOR_H
#define FLOOR_H

#include "Door.h"
#include "SFML_Headers.h"

class Door;
class Floor {
public:
	Floor(std::vector<Door>);
	sf::Sprite getSprite();
	std::vector<Door> getDoors();
private:
	~Floor();
	sf::Sprite *characterSprite;
	sf::Texture *Texture;
	std::vector<Door> doors;
};

#endif