#include "Door.h"
#include <math.h> // only for abs()

Door::Door(){
	Texture = new sf::Texture();
	doorSprite = new sf::Sprite();
	// TODO
	Texture->loadFromFile("Doors.png");
	doorSprite->setTexture(*Texture);
	doorSprite->setPosition(450, 315);
	doorSprite->setTextureRect(sf::IntRect(15, 30, 105, 195));
	doorSprite->setScale(0.75, 0.75);
}

sf::Sprite Door::getSprite() {
	return *doorSprite;
}

sf::Drawable &Door::getDrawable(){
	return *doorSprite;
}

bool Door::collision(Character *player) {
	// Below line is very simple collision detection
	// return (player->getSprite()->getGlobalBounds().intersects(getSprite().getGlobalBounds()));

	sf::Rect<float> playerBounds = player->getSprite()->getGlobalBounds(),
		doorBounds = getSprite().getGlobalBounds();
	float playerCenterX = playerBounds.left + playerBounds.width / 2,
		doorCenterX = doorBounds.left + doorBounds.width / 2;
	return abs(playerCenterX - doorCenterX) < (doorBounds.width / 3);
	// return true if player's center x is within a third of the door's width to the door's center x
}

Door::~Door(){
	delete Texture;
	delete doorSprite;
}

Exit::Exit(){
	Texture = new sf::Texture();
	doorSprite = new sf::Sprite();
	// TODO: This constructor will be different in the picture used
}