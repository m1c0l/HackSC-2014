#include "SFML_Headers.h"

int main()
{
	sf::Sprite *menu = new sf::Sprite();
	sf::Texture *menuTexture = new sf::Texture();

	menuTexture->loadFromFile("menu.png");
	menu->setTexture(*menuTexture);
	menu->setScale(1.12, 1.85);

	sf::RenderWindow windowStart(sf::VideoMode(800, 600), "START MENU");
	int x = enterMenu(menu,windowStart);
	if (x == 0){
		return 0;
	}

	sf::RenderWindow window(sf::VideoMode(800, 600), "CAN YOU SURVIVE?");
	window.setFramerateLimit(60);

	bool state = true;

	sf::Font gameOver;
	gameOver.loadFromFile("arial.ttf");
	sf::Text Text;

	Text.setFont(gameOver);
	Text.setString("GAME OVER");
	Text.setCharacterSize(75);
	Text.setPosition(200, 250);
	Text.setColor(sf::Color::Red);

	Floor *floor = new Floor(2,1);
	int n = 0;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed){
				menuHandler(state, n, floor, window);
			}

			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed){
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && floor->getPlayer()->getSafety() == false){
					floor->getPlayer()->UpdatePosition(10, 0);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && floor->getPlayer()->getSafety() == false){
					floor->getPlayer()->UpdatePosition(-10, 0);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
					if (floor->getCloset()->collision(floor->getPlayer())){
						floor->getPlayer()->UpdateSafety();
						floor->getCloset()->updateImage();
					}
				}
			}

			if (event.type == sf::Event::KeyReleased){
				floor->getPlayer()->UpdatePosition(0, 0);
			}

		}
		floor->updateMonsterPosition();

		window.clear();

		for (int i = 0; i < floor->getTotalGhosts(); i++){
			collision(floor->getPlayer(), floor->getMonster()[i].getSprite(), state);
		}

		int t = 0;
		for (auto it = floor->getObjects()->begin(); it != floor->getObjects()->end(); it++){
			if (floor->getPlayer()->getSafety() == true && floor->getPlayerPosition() == t){
				it++;
			}
			
			window.draw(**it);
			t++;
		}

		drawGameOver(state, n, window, Text, menu);

		window.display();
		window.clear();

		scare(state, n, floor, window);

	}

	system("pause");
}