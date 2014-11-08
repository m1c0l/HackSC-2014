#ifndef GENERAL_FUNCTIONS_H
#define GENERAL_FUNCTIONS_H
#include "SFML_Headers.h"

class Character;
bool collision(Character *player, std::vector<sf::Sprite> list);
#endif