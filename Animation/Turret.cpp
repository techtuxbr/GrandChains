#include "Turret.h"

Turret::Turret(int startX, int startY, Game* actualLevel, uint level) {
	bbox = new Rect(-50, -50, 50, 50);
	type = ENEMY;
	MoveTo(startX, startY, Layer::FRONT);
	detectArea = new DetectArea(x, y, 500, 200, this);
	Turret::level = level;
	Turret::actualLevel = actualLevel;

	switch (Turret::level) {
		case LEVEL1:
			Level1* l1 = (Level1*)Turret::actualLevel;

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

