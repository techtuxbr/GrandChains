#include "Life.h"

Life::Life(float startX, float startY) {
	x = startX;
	y = startY;
}

Life::~Life() {
	delete life;
}

void Life::Update() {

}

void Life::Draw() {
	life->Draw(x, y, Label::FRONT);
}
