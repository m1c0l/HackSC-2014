#ifndef GENERAL_FUNCTIONS_H
#define GENERAL_FUNCTIONS_H
#include "SFML_Headers.h"
#include <iostream>
#include <random>

class Character;
class Floor;
class Level;
void collision(Character *player, sf::Sprite *monster, bool &state);
int getRandomInt(int min, int max);
void menuHandler(bool &state, int &n, Level *&level, sf::Window &window);
void drawGameOver(bool state,int &n, sf::RenderWindow &window, sf::Text &Text, sf::Sprite *Menu);
void scare(bool state, int n, Floor *floor, sf::RenderWindow &window);
int enterMenu(sf::Sprite *Menu, sf::RenderWindow &window);
#endif