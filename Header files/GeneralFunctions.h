#ifndef GENERAL_FUNCTIONS_H
#define GENERAL_FUNCTIONS_H
#include "SFML_Headers.h"
#include <iostream>
#include <random>

class Character;
bool collision(Character *player, std::vector<sf::Sprite> list);
int getRandomInt(int min, int max);
#endif