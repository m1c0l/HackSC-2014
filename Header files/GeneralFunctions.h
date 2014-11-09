#ifndef GENERAL_FUNCTIONS_H
#define GENERAL_FUNCTIONS_H
#include "SFML_Headers.h"
#include <iostream>
#include <random>

class Character;
bool collision(Character *player, sf::Sprite *monster);
int getRandomInt(int min, int max);
#endif