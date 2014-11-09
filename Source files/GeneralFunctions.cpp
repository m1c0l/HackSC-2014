#include "GeneralFunctions.h"


bool collision(Character *player, sf::Sprite *monsters){
	// Is the player colliding with the active sprites?
	if (player->getSprite()->getGlobalBounds().intersects(monsters->getGlobalBounds())){
		return true;
	}else{
		return false;
	}
}

int getRandomInt(int min, int max) {
	// We construct the distribution engine each time we need a random number.
	// Since we're using a function for now instead of a class,
	// we'll go through all the steps of setting up the random device and Mersenne Twister engine
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(min, max);
	return dis(gen);
}