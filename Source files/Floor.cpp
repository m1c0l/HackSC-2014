#include "Floor.h"

Floor::Floor(std::vector<Door> d) {
	Texture = new sf::Texture();
	characterSprite = new sf::Sprite();
	doors = d;

	Texture->loadFromFile("\brickwall.png");
	characterSprite->setTextureRect(sf::IntRect(0, 0, 800, 600));
	
	characterSprite->setTexture(*Texture);

	for (int i = 0; i < doors.size(); i++) {
		doors[i].getSprite().setPosition(450, 210);

	}
}

sf::Sprite Floor::getSprite(){
	return *characterSprite;
}

std::vector<Door> Floor::getDoors() {
	return doors;
}

Floor:: ~Floor(){
	delete characterSprite;
	delete Texture;
}