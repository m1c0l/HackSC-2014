#include "Character.h"

Character::Character(){
	Texture = new sf::Texture();
	characterSprite = new sf::Sprite();

	Texture->loadFromFile("\character1.png");
	characterSprite->setTexture(*Texture);
}

void Character::UpdatePosition(float x, float y){
	characterSprite->move(x, y);
}

sf::Sprite Character::getSprite(){
	return *characterSprite;
}

Character:: ~Character(){
	delete characterSprite;
	delete Texture;
}