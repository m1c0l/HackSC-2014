#ifndef FLOOR_H
#define FLOOR_H

#include "Door.h"
#include "SFML_Headers.h"

class Door;
class Ghost;
class Character;
class Floor {
public:
	Floor(int, int);
	~Floor();
	sf::Drawable &getDrawable();
	sf::Sprite getSprite();
	Character *getPlayer();
	Ghost *getMonster();
	std::vector<sf::Drawable *> *getObjects();
private:
	sf::Sprite *mapSprite;
	Door *door;
	Character *player;
	Ghost *monster;
	sf::Texture *textureMap;
	std::vector<sf::Drawable *> objects;
};

#endif