#include "Level.h"

Level::Level() {
	floors = new Floor*[3];
	// TODO: customize the floors here
	for (int i = 0; i < 3; i++) {
		floors[i] = new Floor(2, 2);
	}
}

Level::~Level() {
	for (int i = 0; i < 3; i++)
		delete floors[i];
	delete[] floors;
}