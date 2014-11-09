#include "Floor.h"

Floor::Floor() {
	textureMap = new sf::Texture();
	mapSprite = new sf::Sprite();
	player = new Character();
	monster = new Ghost();
	door = new Door();

	textureMap->loadFromFile("brickwall.png");
	mapSprite->setTextureRect(sf::IntRect(0, 0, 800, 600));
	
	mapSprite->setTexture(*textureMap);

	objects.push_back(&getDrawable());
	objects.push_back(&player->getDrawable());
	objects.push_back(&monster->getDrawable());
	objects.push_back(&door->getDrawable());
	
}

std::vector<sf::Drawable *> *Floor::getObjects(){
	return &objects;
}

sf::Drawable &Floor::getDrawable(){
	return *mapSprite;
}

Character *Floor::getPlayer(){
	return player;
}

Ghost *Floor::getMonster(){
	return monster;
}

sf::Sprite Floor::getSprite(){
	return *mapSprite;
}

Floor:: ~Floor(){
	delete mapSprite;
	delete textureMap;
}