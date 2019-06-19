#include "GrandChains.h"
#include "Tile.h"
#include "Sprite.h"

Tile::Tile(int startX, int startY, int velX, int velY, int rangeX, int rangeY, Sprite* sprite) {
	type = TILE;
	moving = true;
	tile = sprite;
	bbox = new Rect(-(tile->Width()/2), -(tile->Height()/2), tile->Width()/2, tile->Height()/2);
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
	if (moving) {
		if (velX != 0) {
			if (x >= originX + rangeX / 2) {
				velX = -200;
			} else if (x <= originX - rangeX / 2) {
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
	tile->Draw(x, y, Layer::FRONT);
}

