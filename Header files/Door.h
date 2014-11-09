#ifndef DOOR_H
#define DOOR_H

#include "SFML_Headers.h"

class Character;

class Door{
public:
	Door();
	~Door();
	sf::Sprite getSprite();
	sf::Drawable &getDrawable();
	bool collision(Character *player);
protected:
	sf::Sprite *doorSprite;
	sf::Texture *Texture;
	
};

class Closet : public Door{
public:
	Closet();
	~Closet();
	void updateImage();
private:
	int animationCycle;
};

class Exit : public Door{
public:
	Exit();
	// TODO: exit will act differently from the door when the character enters it
};
#endif