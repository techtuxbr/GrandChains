#include "GrandChains.h"
#include "Ground.h"

Ground::Ground(float startX, float startY, float width, float height) {
	type = TILE;
	MoveTo(startX, startY, Layer::FRONT);
	bbox = new Rect(-width / 2, -height / 2, width / 2, height / 2);
}

Ground::~Ground() {

}

void Ground::Update() {
	bbox->MoveTo(x, y);
}

void Ground::Draw() {
	
}



