#include "Character.h"

Character::Character(){
	Texture = new sf::Texture();
	characterSprite = new sf::Sprite();
	animationCycle = 0;

	Texture->loadFromFile("\character1.png");
	characterSprite->setTexture(*Texture);
	characterSprite->setTextureRect(sf::IntRect(450, 210, 105, 180));
	characterSprite->setScale(0.5, 0.5);
}

void Character::UpdatePosition(float x, float y){
	if (x < 0){
		if (animationCycle % 3 == 0){
			characterSprite->setTextureRect(sf::IntRect(180, 15, 90, 180));
		}
		if (animationCycle % 3 == 1){
			characterSprite->setTextureRect(sf::IntRect(315, 15, 90, 180));
		}
		if (animationCycle % 3 == 2){
			characterSprite->setTextureRect(sf::IntRect(450, 15, 90, 180));
		}
	}
	if (x > 0){
		if (animationCycle % 3 == 0){
			characterSprite->setTextureRect(sf::IntRect(45, 210, 90, 180));
		}
		if (animationCycle % 3 == 1){
			characterSprite->setTextureRect(sf::IntRect(180, 210, 90, 180));
		}
		if (animationCycle % 3 == 2){
			characterSprite->setTextureRect(sf::IntRect(315, 210, 90, 180));
		}
	}
	if (x == 0){
		characterSprite->setTextureRect(sf::IntRect(450, 210, 105, 180));
		animationCycle = 0;
	}
	characterSprite->move(x, y);
	animationCycle++;
}

sf::Sprite Character::getSprite(){
	return *characterSprite;
}

Character:: ~Character(){
	delete characterSprite;
	delete Texture;
}