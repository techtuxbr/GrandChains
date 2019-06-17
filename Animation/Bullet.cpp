#include "Bullet.h"

Bullet::Bullet(int startX, int startY, uint level) {
	bbox = new Rect(-12, -9, 12, 9);
	type = BULLET;
	MoveTo(startX, startY);
	state = RIGHT;
	actualLevel = level;
}

Bullet::~Bullet() {
	delete bulletR;
	delete chargedBullet;
	delete chargedBulletAnim;
}

void Bullet::OnCollision(Object* obj) {
	if (obj->Type() == ENEMY) {

	} else if (obj->Type() == TILE){
		Delete();
	}
}

void Bullet::Update() {
	Translate(velX * gameTime, 0);
	bbox->MoveTo(x, y);

	if (x > window->Width() || x < 0) {
		Delete();
	}
}

void Bullet::Draw() {
	switch (state) {
		case RIGHT:
			bulletR->Draw(x, y);
			break;

		case LEFT:
			bulletL->Draw(x, y);
			break;
	}
}

void Bullet::Right() {
	velX = 700;
	state = RIGHT;
}

void Bullet::Left() {
	velX = -700;
	state = LEFT;
}

void Bullet::Delete() {
	switch (actualLevel) {
		case LEVEL1:
			Level1::scene->Delete(this, MOVING);
			break;
	}
}
