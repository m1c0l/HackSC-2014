#include "Floor.h"

Floor::Floor(int numGhosts, int numDoors) {
	textureMap = new sf::Texture();
	mapSprite = new sf::Sprite();
	player = new Character();
	monster = new Ghost[numGhosts];
	door = new Door[numDoors];

	for (int i = 1; i < numGhosts; i++) {
		monster[i].getSprite()->setPosition(100 + getRandomInt(200, 600), 400);
	}

	textureMap->loadFromFile("brickwall.png");
	
	mapSprite->scale(0.78125, 0.5859375); // 800 / 1024 and 600 / 1024 respectively
	//mapSprite->setTextureRect(sf::IntRect(0, 0, 800, 600));
	
	mapSprite->setTexture(*textureMap);

	// push back in order of drawing
	objects.push_back(&getDrawable());
	for (int i = 0; i < numDoors; i++) {
		objects.push_back(&door[i].getDrawable());
	}
	objects.push_back(&player->getDrawable());
	for (int i = 0; i < numGhosts; i++) {
		objects.push_back(&monster[i].getDrawable());
	}
	
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
	// TODO: delete the other stuff too
}