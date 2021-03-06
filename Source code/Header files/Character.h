#ifndef CHARACTERS_H
#define CHARACTERS_H

#include "SFML_Headers.h"

class Character{
public:
	Character();
	sf::Drawable &getDrawable();
	sf::Sprite *getSprite();
	void UpdatePosition(float x, float y); 
	void UpdateSafety();
	bool getSafety();
protected:
	bool safety;
	sf::Sprite *characterSprite;
	sf::Texture *Texture;
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