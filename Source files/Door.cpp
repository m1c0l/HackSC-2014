#include "Door.h"

Door::Door(){
	Texture = new sf::Texture();
	doorSprite = new sf::Sprite();
	// TODO
	Texture->loadFromFile("Doors.png");
	doorSprite->setTexture(*Texture);
}

sf::Sprite Door::getSprite() {
	return *doorSprite;
}

sf::Drawable &Door::getDrawable(){
	return *doorSprite;
}

Door::~Door(){
	delete Texture;
	delete doorSprite;
}

Exit::Exit(){
	Texture = new sf::Texture();
	doorSprite = new sf::Sprite();
	// TODO: This constructor will be different in the picture used
}