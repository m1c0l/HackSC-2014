#include "Character.h"

Character::Character(std::string type){
	Texture = new sf::Texture();
	characterSprite = new sf::Sprite();
	animationCycle = 0;

	if (type == "player"){
		Texture->loadFromFile("\character1.png");
		characterSprite->setTextureRect(sf::IntRect(450, 210, 105, 180));
	}
	else{
		Texture->loadFromFile("\ghost.png");
		characterSprite->setTextureRect(sf::IntRect(15, 16, 90, 180));
	}
	characterSprite->setTexture(*Texture);
	characterSprite->setPosition(300, 300);
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