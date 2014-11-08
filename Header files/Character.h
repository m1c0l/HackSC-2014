#ifndef CHARACTERS_H
#define CHARACTERS_H

#include "SFML_Headers.h"

class Character{
public:
	Character();
	sf::Sprite getSprite();
	void UpdatePosition(float x, float y); 
protected:
	sf::Sprite *characterSprite;
	sf::Texture *Texture;
	void LoadTexture(sf::Texture *Texture);
	int animationCycle;
	~Character();
};

class Ghost : public Character{
public:
	Ghost();
	void UpdatePosition();
	void collision();
private:
	int ghostMovement;
};

#endif