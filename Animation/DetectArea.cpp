#include "GrandChains.h"
#include "DetectArea.h"
#include "Turret.h"
#include "Laser.h"
#include "Level1.h"
#include "Level2.h"

DetectArea::DetectArea(float startX, float startY, float bboX1, float bboxY1, float bboX2, float bboxY2, Game* actualLevel, uint level, Object* father, uint enemyType) {
	bbox = new Rect(bboX1, bboxY1, bboX2, bboxY2);
	type = AREA;
	MoveTo(startX, startY, Layer::FRONT);
	DetectArea::father = father;
	DetectArea::enemyType = enemyType;
	DetectArea::level = level;
	DetectArea::actualLevel = actualLevel;
}

DetectArea::~DetectArea() {}

void DetectArea::Update() {
	bbox->MoveTo(x, y);
}

void DetectArea::OnCollision(Object* obj) {
	if (obj->Type() == PLAYER) {
		Turret* turret = (Turret*)father;
		Laser* laser = (Laser*)father;
		switch (enemyType) {
			case TURRET:
				if (obj->X() < turret->X()) {
					turret->Left();
				} else {
					turret->Right();
				}
				turret->Shooting();
				break;

			case LASER:
				if (laser->isFiring()) {
					Delete(obj);
				} 
				break;
		}
		
	}
}

void DetectArea::Draw() {}

void DetectArea::Delete(Object* obj) {
	uint type;
	switch (obj->Type()) {
		case ENEMY:
			type = STATIC;
			break;

		default:
			type = MOVING;
			break;
	}

	Level1* l1 = (Level1*)actualLevel;
	Level2* l2 = (Level2*)actualLevel;

	switch (level) {
		case LEVEL1:
			l1->scene->Delete(obj, type);
			break;
		
		case LEVEL2:
			l2->scene->Delete(obj, type);
			break;
	}
}

