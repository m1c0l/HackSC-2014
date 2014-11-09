#ifndef GENERAL_FUNCTIONS_H
#define GENERAL_FUNCTIONS_H
#include "SFML_Headers.h"
#include <iostream>
#include <random>

class Character;
void collision(Character *player, sf::Sprite *monster, bool &state);
int getRandomInt(int min, int max);
#endif