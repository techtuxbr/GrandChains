#include "GrandChains.h"
#include "Tile.h"
#include "Sprite.h"

Tile::Tile(int startX, int startY, uint platType) {
	type = TILE;
	moving = false;
	MoveTo(startX, startY, Layer::FRONT);

	Define(platType);
}

Tile::Tile(int startX, int startY, int velX, int velY, int rangeX, int rangeY, uint platType) {
	type = TILE;
	moving = true;
	MoveTo(startX, startY, Layer::FRONT);

	Tile::velX = velX;
	Tile::velY = velY;
	Tile::rangeX = rangeX;
	Tile::rangeY = rangeY;

	originX = x;
	originY = y;

	Define(platType);
}


Tile::~Tile() {
	delete tile;
}

void Tile::Update() {
	if (moving) {
		if (velX != 0) {
			if (x >= originX + rangeX / 2) {
				velX = -200;
			} else if (y <= originX - rangeX / 2) {
				velX = 200;
			}
		}

		if (velY != 0) {
			if (y >= originY + rangeY / 2) {
				velY = -200;
			} else if (y <= originY - rangeY / 2) {
				velY = 200;
			}
		}
	}

	Translate(velX * gameTime, velY * gameTime);
	bbox->MoveTo(x, y);
}

void Tile::Draw() {
	tileAnim->Draw(x, y, Layer::FRONT);
}

void Tile::Define(uint platType) {
	switch (platType) {
		case FULL:
			bbox = new Rect(-42, -84, 42, 84);
			tile = new TileSet("Resources/tile.png", 84, 168, 1, 1);
			break;

		case HALF:
			bbox = new Rect(-42, -42, 42, 42);
			tile = new TileSet("Resources/tile.png", 84, 84, 1, 1);
			break;

		case JUST:
			bbox = new Rect(-42, -21, 42, 21);
			tile = new TileSet("Resources/tile.png", 84, 42, 1, 1);
			break;
	}

	tileAnim = new Animation(tile, 0, TRUE);
}

