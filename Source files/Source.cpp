#include "SFML_Headers.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
	window.setFramerateLimit(60);

	std::vector<sf::Sprite> list;
	Character *character = new Character();
	Ghost *monster = new Ghost();
	std::vector<Door> doors;
	Floor *floor;

	list.push_back(monster->getSprite());
	doors.push_back(Door());
	floor = new Floor(doors);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			// draw the floor first
			window.draw(floor->getSprite());
			for (int i = 0; i < floor->getDoors().size(); i++) {
				window.draw(floor->getDoors()[i].getSprite());
			}

			if (event.type == sf::Event::KeyPressed){
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
					character->UpdatePosition(10, 0);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
					character->UpdatePosition(-10, 0);
				}
			}
			if (event.type == sf::Event::KeyReleased){
				character->UpdatePosition(0, 0);
			}
		
			
			collision(character, list);
		}
		
		monster->UpdatePosition();

		window.clear();
		window.draw(character->getSprite());
		window.draw(monster->getSprite());
		window.display();
	}

	return 0;
}