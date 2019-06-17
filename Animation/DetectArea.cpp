#include "GrandChains.h"
#include "DetectArea.h"
#include "Sprite.h"
#include "Turret.h"

DetectArea::DetectArea(int startX, int startY, int sizeX, int sizeY, Object* father) {
	bbox = new Rect(-sizeX, -sizeY, sizeX, sizeY);
	type = AREA;
	MoveTo(startX, startY, Layer::FRONT);
	DetectArea::father = father;
}

DetectArea::~DetectArea() {}

void DetectArea::Update() {
	bbox->MoveTo(x, y);
}

void DetectArea::OnCollision(Object* obj) {
	if (obj->Type() == PLAYER) {
		Turret* turret = (Turret*)father;

		if (obj->X() < turret->X()) {
			turret->Left();
		} else {
			turret->Right();
		}

		turret->Shooting();
	}
}

void DetectArea::Draw() {
}


