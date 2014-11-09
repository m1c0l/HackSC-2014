#include "SFML_Headers.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
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

	sf::Sprite *menu = new sf::Sprite();
	sf::Texture *menuTexture = new sf::Texture();

	menuTexture->loadFromFile("menu.png");
	menu->setTexture(*menuTexture);
	menu->setScale(1.12, 1.85);

	Floor *floor = new Floor(2,1);
	int n = 0;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed){
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
					floor->getPlayer()->UpdatePosition(10, 0);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
					floor->getPlayer()->UpdatePosition(-10, 0);
				}
			}

			if (event.type == sf::Event::KeyReleased){
				floor->getPlayer()->UpdatePosition(0, 0);
			}

			if (event.type == sf::Event::MouseButtonPressed){
				if (state == false && sf::Mouse::getPosition().y > 300 && n > 100){
					window.close();
				}
				if (state == false && sf::Mouse::getPosition().y < 300 && n > 100){
					state = true;
					n = 0;
					for (int i = 0; i < floor->getTotalGhosts(); i++){
						floor->getMonster()[i].getSprite()->setPosition(100 + getRandomInt(200, 600), 400);
						floor->getMonster()[i].getSprite()->setScale(.5, .5);
						std::cout << i << std::endl;
					}
				}
			}
		}

		for (int i = 0; i < floor->getTotalGhosts(); i++){
			floor->getMonster()[i].UpdatePosition();
		}

		window.clear();

		for (int i = 0; i < floor->getTotalGhosts(); i++){
			collision(floor->getPlayer(), floor->getMonster()[i].getSprite(), state);
		}

		for (auto it = floor->getObjects()->begin(); it != floor->getObjects()->end(); it++){
			window.draw(**it);
		}

		if (state == false){
			window.draw(Text);
			n++;
			if (n > 100){
				window.draw(*menu);
			}
		}

		window.display();
		window.clear();

		if (state == false && n % 1000 == 0){
			floor->getMonster()[0].UpdatePosition();
			floor->getMonster()[0].getSprite()->setPosition(-10, 0);	
			window.display();
		}

	}

	system("pause");
}