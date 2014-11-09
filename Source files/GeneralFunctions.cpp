#include "GeneralFunctions.h"


void collision(Character *player, sf::Sprite *monsters, bool &state){
	// Is the player colliding with the active sprites?
	if (player->getSprite()->getGlobalBounds().intersects(monsters->getGlobalBounds())){
		monsters->setScale(9, 3.5);
		monsters->setPosition(-10, 0);
		state = false;
	}else{
		return;
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

void menuHandler(bool &state, int &n, Floor *floor, sf::Window &window){
	if (state == false && sf::Mouse::getPosition().y > 400 && n > 100){
		window.close();
	}
	if (state == false && sf::Mouse::getPosition().y < 400 && n > 100){
		state = true;
		n = 0;
		for (int i = 0; i < floor->getTotalGhosts(); i++){
			floor->getMonster()[i].getSprite()->setPosition(100 + getRandomInt(200, 600), 400);
			floor->getMonster()[i].getSprite()->setScale(.5, .5);
		}
	}
}

void drawGameOver(bool state, int &n, sf::RenderWindow &window, sf::Text &Text, sf::Sprite *Menu){
	if (state == false){
		window.draw(Text);
		n++;
		if (n > 100){
			window.draw(*Menu);
		}
	}
}

void scare(bool state, int n, Floor *floor, sf::RenderWindow &window){
	if (state == false && n % 1000 == 0){
		floor->getMonster()[0].UpdatePosition();
		floor->getMonster()[0].getSprite()->setPosition(-10, 0);
		window.display();
	}
}

int enterMenu(sf::Sprite *Menu, sf::RenderWindow &window){
	while (window.isOpen())
	{
		sf::Event event;

		window.clear();
		window.draw(*Menu);
		window.display();
		while (window.pollEvent(event)){
			if (event.type == sf::Event::MouseButtonPressed){
				if (sf::Mouse::getPosition().y < 400){
					window.close();
				}
				if (sf::Mouse::getPosition().y > 400){
					window.close();
					return 0;
				}
			}
		}
	}
	return 1;
}