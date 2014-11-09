#ifndef MENU_H
#define MENU_H

#include "SFML_Headers.h"

class Menu{
public:
	Menu();
	sf::Sprite getSprite();
	void clickCheck(sf::Vector2i mousePosition);
private:
	sf::Sprite *menuRectangle;
	sf::Texture *Texture;
	~Menu();
};
#endif