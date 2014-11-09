#include "Door.h"

Door::Door(){
	Texture = new sf::Texture();
	doorSprite = new sf::Sprite();
	// TODO
	Texture->loadFromFile("Doors.png");
	doorSprite->setTexture(*Texture);
	doorSprite->setPosition(450, 315);
	doorSprite->setTextureRect(sf::IntRect(15, 30, 105, 195));
	doorSprite->setScale(0.75, 0.75);
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