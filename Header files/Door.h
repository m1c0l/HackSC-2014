#ifndef DOOR_H
#define DOOR_H

#include "SFML_Headers.h"

class Door{
public:
	Door();
	~Door();
	sf::Sprite getSprite();
protected:
	sf::Sprite *doorSprite;
	sf::Texture *Texture;
	
};

class Exit : public Door{
public:
	Exit();
	// TODO: exit will act differently from the door when the character enters it
};
#endif