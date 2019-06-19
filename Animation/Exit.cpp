#include "GrandChains.h"
#include "Exit.h"

Exit::Exit(int startX, int startY) {
	type = EXIT;
	exit = new Sprite("Resources/exit.png");

	bbox = new Rect(-47, -95, 47, 95);
	MoveTo(startX, startY, Layer::FRONT);
}

Exit::~Exit() {
	delete exit;
}

void Exit::Update() {

}

void Exit::Draw() {
	exit->Draw(x, y, Layer::MIDDLE);
}



