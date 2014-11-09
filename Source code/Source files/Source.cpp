	#include "SFML_Headers.h"

int main()
{
	sf::Sprite *menu = new sf::Sprite();
	sf::Texture *menuTexture = new sf::Texture();

	menuTexture->loadFromFile("menu.png");
	menu->setTexture(*menuTexture);
	menu->setScale(1.12, 1.85);

	sf::RenderWindow windowStart(sf::VideoMode(800, 600), "START MENU");
	int x = enterMenu(menu, windowStart);
	if (x == 0){
		return 0;
	}

	sf::RenderWindow window(sf::VideoMode(800, 600), "CAN YOU SURVIVE?");
	window.setFramerateLimit(60);

	bool state = true;

	sf::Font gameOver;
	gameOver.loadFromFile("arial.ttf");
	sf::Text Text, levelIndicator;

	Text.setFont(gameOver);
	Text.setString("GAME OVER");
	Text.setCharacterSize(75);
	Text.setPosition(200, 250);
	Text.setColor(sf::Color::Red);

	int numLevels = getRandomInt(5, 10);
	Level *level = new Level(numLevels);
	int n = 0;

	levelIndicator.setFont(gameOver);
	levelIndicator.setString(std::to_string(level->getFloorLevel()));
	levelIndicator.setCharacterSize(25);
	levelIndicator.setPosition(10, 10);
	levelIndicator.setColor(sf::Color::Cyan);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed){
				menuHandler(state, n, level, window, levelIndicator);
			}

			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed){
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
					if (level->getFloor()[level->getFloorLevel()]->getCloset()->collision(level->getFloor()[level->getFloorLevel()]->getPlayer())){
						level->getFloor()[level->getFloorLevel()]->getPlayer()->UpdateSafety();
						level->getFloor()[level->getFloorLevel()]->getCloset()->updateImage();
					}
					for (int i = 0; i < level->getFloor()[level->getFloorLevel()]->getTotalDoors(); i++){
						if (level->getFloor()[level->getFloorLevel()]->getDoor()[i].collision(level->getFloor()[level->getFloorLevel()]->getPlayer())){
							if (level->getFloorLevel() < numLevels){
								level->getFloorLevel()++;
								levelIndicator.setString(std::to_string(level->getFloorLevel()));
							}
						}
					}
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && level->getFloor()[level->getFloorLevel()]->getPlayer()->getSafety() == false){
					level->getFloor()[level->getFloorLevel()]->getPlayer()->UpdatePosition(10, 0);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && level->getFloor()[level->getFloorLevel()]->getPlayer()->getSafety() == false){
					level->getFloor()[level->getFloorLevel()]->getPlayer()->UpdatePosition(-10, 0);
				}
			}

			if (event.type == sf::Event::KeyReleased){
				level->getFloor()[level->getFloorLevel()]->getPlayer()->UpdatePosition(0, 0);
			}

		}
		level->getFloor()[level->getFloorLevel()]->updateMonsterPosition();

		window.clear();

		for (int i = 0; i < level->getFloor()[level->getFloorLevel()]->getTotalGhosts(); i++){
			collision(level->getFloor()[level->getFloorLevel()]->getPlayer(), level->getFloor()[level->getFloorLevel()]->getMonster()[i].getSprite(), state);
		}

		int t = 0;
		for (auto it = level->getFloor()[level->getFloorLevel()]->getObjects()->begin(); it != level->getFloor()[level->getFloorLevel()]->getObjects()->end(); it++){
			if (level->getFloor()[level->getFloorLevel()]->getPlayer()->getSafety() == true && level->getFloor()[level->getFloorLevel()]->getPlayerPosition() == t){
				it++;
			}

			window.draw(**it);
			t++;
		}

		drawGameOver(state, n, window, Text, menu);

		window.draw(levelIndicator);
		window.display();
		window.clear();

		scare(state, n, level->getFloor()[level->getFloorLevel()], window);

		sf::Event event2;
		if (level->getFloorLevel() == numLevels - 1){
			if (level->getFloor()[level->getFloorLevel()]->getExit()->collision(level->getFloor()[level->getFloorLevel()]->getPlayer())){
				
				sf::Sprite *victory = new sf::Sprite();
				sf::Texture *victoryTexture = new sf::Texture();

				victoryTexture->loadFromFile("victory.png");
				victory->setTexture(*victoryTexture);
				victory->setScale(0.9, 2.1);
				
				window.clear();
				window.draw(*victory);
				window.display();
				break;
			}
		}
	}
	system("pause");
}