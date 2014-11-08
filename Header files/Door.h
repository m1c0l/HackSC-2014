#ifndef DOOR_H
#define DOOR_H

#include "SFML_Headers.h"

class Door{
public:
	Door();
	sf::Sprite getSprite();
private:
	sf::Sprite *doorSprite;
	sf::Texture *Texture;
	void LoadTexture();
	~Door();
};
#endif