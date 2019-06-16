#include "Bullet.h"

Bullet::Bullet(int startX, int startY) {
	bbox = new Rect(-12, -9, 12, 9);

	type = BULLET;

	MoveTo(startX, startY);
}

Bullet::~Bullet() {
	delete bulletR;
	delete chargedBullet;
	delete chargedBulletAnim;
}

void Bullet::OnCollision(Object* obj) {

}

void Bullet::Update() {
	Translate(velX * gameTime, 0);
	bbox->MoveTo(x, y);
}

void Bullet::Draw() {
	bulletR->Draw(x, y);
}

void Bullet::Right() {
	velX = 700;
}

void Bullet::Left() {
	velX = -700;
}


