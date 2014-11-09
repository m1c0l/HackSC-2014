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

	Floor *floor = new Floor();
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

		}

		floor->getMonster()->UpdatePosition();

		window.clear();

		collision(floor->getPlayer(), floor->getMonster()->getSprite(), state);

		for (auto it = floor->getObjects()->begin(); it != floor->getObjects()->end(); it++){
			window.draw(**it);
		}

		if (state == false){
			window.draw(Text);
		}

		window.display();

		window.clear();

		if (state == false && n % 1000 == 0){
			floor->getMonster()->UpdatePosition();
			floor->getMonster()->getSprite()->setPosition(-10, 0);	
			window.display();
		}

		n++;
	}

	system("pause");
}