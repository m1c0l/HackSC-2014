#include "GeneralFunctions.h"


bool collision(Character *player, std::vector<sf::Sprite> list){
	// Is the player colliding with the active sprites?
	for (auto it : list){
		player->getSprite().getGlobalBounds().intersects(it.getGlobalBounds());
	}
	return true;
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