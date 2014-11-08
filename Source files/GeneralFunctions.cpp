#include "GeneralFunctions.h"
#include <iostream>

bool collision(Character *player, std::vector<sf::Sprite> list){
	for (auto it : list){
		std::cout << player->getSprite().getGlobalBounds().intersects(it.getGlobalBounds())<<std::endl;
	}
	return true;
}