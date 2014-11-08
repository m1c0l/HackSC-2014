#include "Door.h"

Door::Door(){
	Texture = new sf::Texture();
	doorSprite = new sf::Sprite();
	// TODO
}

sf::Sprite Door::getSprite() {
	return *doorSprite;
}

Door::~Door(){
	delete Texture;
	delete doorSprite;
}