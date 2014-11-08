#include "Character.h"
#include <iostream>

Character::Character(){
	Texture = new sf::Texture();
	characterSprite = new sf::Sprite();
	animationCycle = 0;

	Texture->loadFromFile("\character1.png");
	characterSprite->setTextureRect(sf::IntRect(450, 210, 105, 180));
	
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
		if (!characterSprite->getGlobalBounds().contains(0, characterSprite->getPosition().y)){
			characterSprite->move(x, y);
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

		if (!characterSprite->getGlobalBounds().contains(800, characterSprite->getPosition().y)){
			characterSprite->move(x, y);
		}
	}

	if (x == 0){
		characterSprite->setTextureRect(sf::IntRect(450, 210, 105, 180));
		animationCycle = 0;
	}

	animationCycle++;
}

sf::Sprite Character::getSprite(){
	return *characterSprite;
}

Character:: ~Character(){
	delete characterSprite;
	delete Texture;
}

Ghost::Ghost(){
	Texture = new sf::Texture();
	characterSprite = new sf::Sprite();
	animationCycle = 0;
	ghostMovement = 1;

	Texture->loadFromFile("\ghost.png");
	characterSprite->setTextureRect(sf::IntRect(15, 16, 90, 180));

	characterSprite->setTexture(*Texture);
	characterSprite->setPosition(300, 300);
	characterSprite->setScale(0.5, 0.5);
}

void Ghost::UpdatePosition(){
	if (animationCycle == 0 || animationCycle == 5){
		characterSprite->setTextureRect(sf::IntRect(15, 16, 90, 180));

	}if (animationCycle == 1 || animationCycle == 4){
		characterSprite->setTextureRect(sf::IntRect(120, 16, 90, 180));

	}if (animationCycle == 3){
		characterSprite->setTextureRect(sf::IntRect(225, 16, 90, 180));
	}

	if (animationCycle == 5){
		animationCycle = 0;
	}else{
		animationCycle++;
	}

	characterSprite->move(ghostMovement, 0);
	collision();
}

void Ghost::collision(){
	if (characterSprite->getGlobalBounds().contains(0, characterSprite->getPosition().y) || characterSprite->getGlobalBounds().contains(800, characterSprite->getPosition().y)){
		ghostMovement = -ghostMovement;
	}
}