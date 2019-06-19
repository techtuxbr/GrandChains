#include "Turret.h"
#include "Level1.h"

Turret::Turret(int startX, int startY, float bboX1, float bboxY1, float bboX2, float bboxY2, Game* actualLevel, uint level) {
	bbox = new Rect(-60, -37, 60, 37);
	type = ENEMY;
	MoveTo(startX, startY, Layer::FRONT);
	detectArea = new DetectArea(x, y, bboX1, bboxY1, bboX2, bboxY2, actualLevel, level, this, TURRET);
	Turret::level = level;
	Turret::actualLevel = actualLevel;

	switch (level) {
		case LEVEL1:
			Level1* l1 = (Level1*)actualLevel;

			l1->scene->Add(detectArea, STATIC);
			break;
	}

}

Turret::~Turret() {
	delete turretR;
	delete turretRAnim;
	delete turretL;
	delete turretLAnim;

	switch (level) {
		case LEVEL1:
			Level1* l1 = (Level1*)actualLevel;

			l1->scene->Delete(detectArea, STATIC);
			break;
			
	}
}

void Turret::Update() {
	if (shooting && fireTime <= 0) {
		Bullet* bullet;

		if (facingRight) {
			bullet = new Bullet(x + 50, y, 500, actualLevel, level, this);
			bullet->Right();
		} else {
			bullet = new Bullet(x - 50, y, 500, actualLevel, level, this);
			bullet->Left();
		}

		switch (level) {
			case LEVEL1:
				Level1* l1 = (Level1*)actualLevel;

				l1->scene->Add(bullet, MOVING);
				break;
		}

		if (fireTime <= 0) {
			fireTime = 1;
		}
	}

	// Calcula o tempo para o próximo tiro
	if (fireTime > 0) {
		fireTime -= gameTime;
	}
	// ------------------------------------

	shooting = false;
	bbox->MoveTo(x, y);
}

void Turret::Draw() {
	switch (state) {
		case RIGHT:
			turretRAnim->Draw(x, y, Layer::FRONT);
			if (shooting) {
				turretRAnim->NextFrame();
			}
			break;

		case LEFT:
			turretLAnim->Draw(x, y, Layer::FRONT);
			if (shooting) {
				turretLAnim->NextFrame();
			}
			break;
	}
}

void Turret::Shooting() {
	shooting = true;
}

void Turret::Right() {
	state = RIGHT;
	facingRight = true;
}

void Turret::Left() {
	state = LEFT;
	facingRight = false;
}

