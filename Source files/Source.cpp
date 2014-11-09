#include "SFML_Headers.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	window.setFramerateLimit(60);

	//std::vector<sf::Drawable *> list;
	//Character *character = new Character();
	//Ghost *monster = new Ghost();
	Floor *floor = new Floor();

	//list.push_back(&floor->getDrawable());
	//list.push_back(&character->getDrawable());
	//list.push_back(&monster->getDrawable());

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
			
			std::cout<<collision(floor->getPlayer(), floor->getMonster()->getSprite());
		}
		
		floor->getMonster()->UpdatePosition();

		window.clear();

		for (auto it = floor->getObjects()->begin(); it != floor->getObjects()->end(); it++){
			window.draw(**it);
		}

		window.display();
	}

	return 0;
}