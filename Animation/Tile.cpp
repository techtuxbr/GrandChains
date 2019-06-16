#include "GrandChains.h"
#include "Tile.h"
#include "Sprite.h"

Tile::Tile(int startX, int startY) {
	type = TILE;

	tile = new Sprite("Resources/tile.png");

	bbox = new Rect(-126 + x, -36 + y, 126 + x, 36 + y);
	MoveTo(startX, startY, Layer::FRONT);
}

Tile::~Tile() {
	delete tile;
}

void Tile::Update() {
	bbox->MoveTo(x, y);
}

void Tile::Draw() {
	tile->Draw(x, y, Layer::FRONT);
}

void Tile::OnCollision(Object* obj) {
	if (obj->Type() == PLAYER) {
		
	}
}

