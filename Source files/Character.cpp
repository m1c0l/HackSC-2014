#include "Character.h"

Character::Character(){
	Texture = new sf::Texture();
	characterSprite = new sf::Sprite();

	Texture->loadFromFile("\character1.png");
	characterSprite->setTexture(*Texture);
}

sf::Sprite Character::getSprite(){
	return *characterSprite;
}