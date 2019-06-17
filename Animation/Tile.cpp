#include "GrandChains.h"
#include "Tile.h"
#include "Sprite.h"

Tile::Tile(int startX, int startY) {
	bbox = new Rect(-126, -36, 126, 36);
	type = TILE;
	platType = STATIC;
	tile = new Sprite("Resources/tile.png");
	MoveTo(startX, startY, Layer::FRONT);
}
Tile::Tile(int startX, int startY, int velX, int velY, int rangeX, int rangeY) {
	bbox = new Rect(-126, -36, 126, 36);
	type = TILE;
	platType = MOVING;
	tile = new Sprite("Resources/tile.png");
	MoveTo(startX, startY, Layer::FRONT);

	Tile::velX = velX;
	Tile::velY = velY;
	Tile::rangeX = rangeX;
	Tile::rangeY = rangeY;
	
	originX = x;
	originY = y;
}


Tile::~Tile() {
	delete tile;
}

void Tile::Update() {
	switch (platType) {
		case MOVING:
			if (x > originX + rangeX / 2 || x < originX - rangeX / 2) {
				velX = -velX;
			}

			if (y > originY + rangeY / 2 || y < originY - rangeY / 2) {
				velY = -velY;
			}

			Translate(velX * gameTime, velY * gameTime);
			break;
	}


	bbox->MoveTo(x, y);
}

void Tile::Draw() {
	tile->Draw(x, y, Layer::FRONT);
}

void Tile::OnCollision(Object* obj) {
	if (obj->Type() == PLAYER) {
		
	}
}

