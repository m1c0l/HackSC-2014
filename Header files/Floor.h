#ifndef FLOOR_H
#define FLOOR_H

#include "Door.h"
#include "SFML_Headers.h"


class Door;
class Closet;
class Exit;
class Ghost;
class Character;
class Floor {
public:
	Floor(int numGhosts, int numDoors);
	~Floor();
	int getTotalGhosts();
	int getTotalDoors();
	int getPlayerPosition();
	sf::Drawable &getDrawable();
	sf::Sprite getSprite();
	Character *getPlayer();
	Ghost *getMonster();
	Closet *getCloset();
	Exit *getExit();
	Door *getDoor();
	std::vector<sf::Drawable *> *getObjects();
	void updateMonsterPosition();
private:
	int playerPosition;
	int totalGhosts;
	int totalDoors;
	sf::Sprite *mapSprite;
	Exit *exit;
	Closet *closet;
	Door *door;
	Character *player;
	Ghost *monster;
	sf::Texture *textureMap;
	std::vector<sf::Drawable *> objects;
	std::vector<sf::Sprite*> spriteBoundaries;
	void addSpriteBoundaries(sf::Sprite *sprite, int xmin, int xmax, int y);
};

#endif