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
			bbox = new Rect(-16, -32, 16, 32);
			tile = new TileSet("Resources/tile.png", 32, 64, 1, 1);
			break;

		case HALF:
			bbox = new Rect(-16, -16, 16, 16);
			tile = new TileSet("Resources/tile.png", 32, 32, 1, 1);
			break;

		case JUST:
			bbox = new Rect(-16, -8, 16, 8);
			tile = new TileSet("Resources/tile.png", 32, 16, 1, 1);
			break;

		case WALL:
			bbox = new Rect(-4, -24, 4, 24);
			tile = new TileSet("Resources/wall.png", 8, 48, 1, 1);
			break;
	}

	tileAnim = new Animation(tile, 0, TRUE);
}

float Tile::Width() {
	Rect* buffer = (Rect*)bbox;

	return abs(buffer->Right() - buffer->Left());
}

float Tile::Height() {
	Rect* buffer = (Rect*)bbox;

	return abs(buffer->Top() - buffer->Bottom());
}

