#include "Level1.h"
#include "Tile.h"
#include "Sprite.h"

Tile::Tile(int startX, int startY) {
	type = TILE;

	tile = new Sprite("Resources/tile.png");

	bbox = new Rect(-126, -36, 126, 36);
	MoveTo(startX, startY, Layer::FRONT);
}

Tile::~Tile() {
	delete tile;
}

void Tile::Update() {

}

void Tile::Draw() {
	tile->Draw(x, y, Layer::FRONT);
}

void Tile::OnCollision(Object* obj) {
	if (obj->Type() == PLAYER) {
		
	}
}

