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

	

	addSpriteBoundaries(player->getSprite(), 0, 200, 400); // add player first at the left
	for (int i = 0; i < totalDoors; i++) {
		//door[i].getSprite()->setPosition(100 + getRandomInt(200, 600), 315);
		addSpriteBoundaries(door[i].getSprite(), 300, 700, 315);
	}
	if (numDoors == 0){
		exit = new Exit();
		addSpriteBoundaries(exit->getSprite(), 400, 700, 315);
	}
	for (int i = 0; i < totalGhosts; i++) {
		//monster[i].getSprite()->setPosition(100 + getRandomInt(200, 600), 400);
		addSpriteBoundaries(monster[i].getSprite(), 0, 700, 400);
	}

	//closet->getSprite()->setPosition(100 + getRandomInt(200, 600), 330);
	addSpriteBoundaries(closet->getSprite(), 0, 700, 330);




	textureMap->loadFromFile("brickwall.png");

	mapSprite->scale(0.78125, 0.5859375); // 800 / 1024 and 600 / 1024 respectively
	//mapSprite->setTextureRect(sf::IntRect(0, 0, 800, 600));

	mapSprite->setTexture(*textureMap);

	// push back in order of drawing
	objects.push_back(&getDrawable());
	objects.push_back(&closet->getDrawable());

	if (numDoors == 0){
		objects.push_back(&exit->getDrawable());
		for (int i = 0; i < numDoors; i++) {
			objects.push_back(&door[i].getDrawable());
			playerPosition++;
		}
		playerPosition += 3;
		objects.push_back(&player->getDrawable());
		for (int i = 0; i < numGhosts; i++) {
			objects.push_back(&monster[i].getDrawable());
		}
	}else{
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
}

Exit *Floor::getExit(){
	return exit;
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

void Floor::addSpriteBoundaries(sf::Sprite *sprite, int xmin, int xmax, int y) {
	// randomly add sprite at a location with x between min and max
	// and also, none of the sprites will collide at all with each other
	int x;
	if (spriteBoundaries.empty()) {
		x = getRandomInt(xmin, xmax); // freely choose random x if there aren't any sprites yet
		sprite->setPosition(x, y);
	}
	else {
		bool isIntersect;
		do {
			isIntersect = false;
			x = getRandomInt(xmin, xmax); // generate new x until current sprite doesn't collide with any other sprite
			for (int i = 0; !isIntersect && i < spriteBoundaries.size(); i++) {
				sprite->setPosition(x, y);
				isIntersect = sprite->getGlobalBounds().intersects(spriteBoundaries[i]->getGlobalBounds());
			}
		} while(isIntersect);
	}
	
	spriteBoundaries.push_back(sprite);
}