#include "Menu.h"

Menu::Menu(){
	menuRectangle = new sf::Sprite();
	Texture = new sf::Texture();

	Texture->loadFromFile("\menu.png");
	menuRectangle->setTexture(*Texture);

	menuRectangle->setPosition(250, 200);
	menuRectangle->setScale(0.5, 0.5);
}

sf::Sprite Menu::getSprite(){
	return *menuRectangle;
}

void Menu::clickCheck(sf::Vector2i mousePosition){
	
}