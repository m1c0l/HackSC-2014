#include "Floor.h"

Floor::Floor(int numGhosts, int numDoors) {
	textureMap = new sf::Texture();
	mapSprite = new sf::Sprite();
	player = new Character();
	monster = new Ghost[numGhosts];
	door = new Door[numDoors];
	closet = new Closet();
	totalDoors = numDoors;
	totalGhosts = numGhosts;
	playerPosition = 0;

	closet->getSprite()->setPosition(100 + getRandomInt(200, 600), 330);

	for (int i = 0; i < totalGhosts; i++) {
		monster[i].getSprite()->setPosition(100 + getRandomInt(200, 600), 400);
	}
	for (int i = 0; i < totalDoors; i++) {
		door[i].getSprite()->setPosition(100 + getRandomInt(200, 600), 315);
	}

	textureMap->loadFromFile("brickwall.png");
	
	mapSprite->scale(0.78125, 0.5859375); // 800 / 1024 and 600 / 1024 respectively
	//mapSprite->setTextureRect(sf::IntRect(0, 0, 800, 600));
	
	mapSprite->setTexture(*textureMap);

	// push back in order of drawing
	objects.push_back(&getDrawable());
	objects.push_back(&closet->getDrawable());
	for (int i = 0; i < numDoors; i++) {
		objects.push_back(&door[i].getDrawable());
		playerPosition++;
	}
	playerPosition += 2;
	objects.push_back(&player->getDrawable());
	for (int i = 0; i < numGhosts; i++) {
		objects.push_back(&monster[i].getDrawable());
	}
	
}

int Floor::getPlayerPosition(){
	return playerPosition;
}

void Floor::updateMonsterPosition(){
	for (int i = 0; i < getTotalGhosts(); i++){
		getMonster()[i].UpdatePosition();
	}
}

Closet *Floor::getCloset(){
	return closet;
}

Door *Floor::getDoor() {
	return door;
}

int Floor::getTotalGhosts(){
	return totalGhosts;
}

int Floor::getTotalDoors(){
	return totalDoors;
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