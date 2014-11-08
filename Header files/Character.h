#ifndef CHARACTERS_H
#define CHARACTERS_H

#include "SFML_Headers.h"

class Character{
public:
	Character();
	sf::Sprite getSprite();
	void UpdatePosition(float x, float y);
private:
	sf::Sprite *characterSprite;
	sf::Texture *Texture;
	void LoadTexture(sf::Texture *Texture);
	
	~Character();
};

#endif