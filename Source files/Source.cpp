#include "SFML_Headers.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

	Character *character = new Character();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed){
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
					character->UpdatePosition(5, 0);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
					character->UpdatePosition(-5, 0);
				}
			}

		}

		window.clear();
		window.draw(character->getSprite());
		window.display();
	}

	return 0;
}