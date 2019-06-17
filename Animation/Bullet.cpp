#include "Bullet.h"

Bullet::Bullet(int startX, int startY, int vel, uint level, Object* father) {
	bbox = new Rect(-12, -9, 12, 9);
	type = BULLET;
	MoveTo(startX, startY);
	state = RIGHT;
	actualLevel = level;
	Bullet::father = father;
	Bullet::vel = vel;
	fatherType = father->Type();
}

Bullet::~Bullet() {
	delete bulletR;
	delete chargedBullet;
	delete chargedBulletAnim;
}

void Bullet::OnCollision(Object* obj) {
	if (fatherType == ENEMY) {
		if (obj->Type() == PLAYER) {
			Delete(obj);
			Delete(this);
		} else if (obj->Type() == TILE) {
			Delete(this);
		}
	} else if (fatherType == PLAYER) {
		if (obj->Type() == ENEMY) {
			Delete(obj);
			Delete(this);
		} else if (obj->Type() == TILE) {
			Delete(this);
		}
	}
}

void Bullet::Update() {
	Translate(velX * gameTime, 0);
	bbox->MoveTo(x, y);

	if (x > window->Width() || x < 0) {
		Delete(this);
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
	velX = vel;
	state = RIGHT;
}

void Bullet::Left() {
	velX = -vel;
	state = LEFT;
}

void Bullet::Delete(Object* obj) {
	uint type;
	switch (obj->Type()) {
		case ENEMY:
			type = STATIC;
			break;

		default:
			type = MOVING;
			break;
	}

	switch (actualLevel) {
		case LEVEL1:
			Level1::scene->Delete(obj, type);
			break;
	}
}
