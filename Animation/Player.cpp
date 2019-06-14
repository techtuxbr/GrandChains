#include "Player.h"
#include "Animation.h"
#include "TileSet.h"
#include "Level1.h"
#include "Tile.h"

Player::Player(int startX, int startY) {
	grounded = false;
	lefted = false;

	collisionPrecision = 0;

	currentState = STOPPEDR;

	velX = 0;
	velY = 0;

	bbox = new Rect(-75 + x, -75 + y, 75 + x, 75 + y);
	MoveTo(startX, startY);
	type = PLAYER;

	jumpDistance = 450;
	jumpProgress = 450;

	right = new TileSet("Resources/playerRight.png", 150, 150, 10, 10);
	rightAnim = new Animation(right, 1.0 / 10.0, true);

	left = new TileSet("Resources/playerleft.png", 150, 150, 10, 10);
	leftAnim = new Animation(left, 1.0 / 10.0, true);

	stoppedR = new TileSet("Resources/stoppedR.png", 150, 150, 10, 10);
	stoppedRAnim = new Animation(stoppedR, 1.0 / 10.0, true);

	stoppedL = new TileSet("Resources/stoppedL.png", 150, 150, 10, 10);
	stoppedLAnim = new Animation(stoppedL, 1.0 / 10.0, true);

	jumpR = new TileSet("Resources/jumpR.png", 150, 197, 5, 5);
	jumpRAnim = new Animation(jumpR, 1.0 / 10.0, true);

	jumpL = new TileSet("Resources/jumpL.png", 150, 197, 5, 5);
	jumpLAnim = new Animation(jumpL, 1.0 / 10.0, true);
	
	fallR = new TileSet("Resources/fallR.png", 150, 197, 2, 2);
	fallRAnim = new Animation(fallR, 1.0 / 10.0, true);

	fallL = new TileSet("Resources/fallL.png", 150, 197, 2, 2);
	fallLAnim = new Animation(fallL, 1.0 / 10.0, true);
}

Player::~Player() {
	delete right;
	delete left;
	delete stoppedR;
	delete stoppedL;
	delete jumpR;
	delete jumpL;
	delete fallR;
	delete fallL;
}

void Player::Update() {
	if (!lefted && window->KeyDown(VK_RIGHT)) {
		velX = 400;
	}
	else if (window->KeyDown(VK_LEFT)) {
		velX = -400;
	}
	else {
		velX = 0;
	}

	//// Pressionar Space --------------------
	//if (window->KeyUp(VK_SPACE)) {
	//	jumpCtrl = true;
	//}
	//if (window->KeyDown(VK_SPACE) && jumpCtrl && grounded) {
	//	velY = -1000;
	//	collisionPrecision = 0;
	//	jumpCtrl = false;
	//}
	//// -------------------------------------

	Translate(velX * gameTime, velY * gameTime);
	if (collisionPrecision != 0) {
		MoveTo(x, collisionPrecision - 75);
	}
	StateMachine();
	Gravity();

	bbox->MoveTo(x, y);
}

void Player::Draw() {
	switch (currentState) {
		case RIGHT:
			rightAnim->Draw(x, y, 0.2f);
			rightAnim->NextFrame();
			break;
		
		case LEFT:
			leftAnim->Draw(x, y, 0.2f);
			leftAnim->NextFrame();
			break;

		case STOPPEDR:
			stoppedRAnim->Draw(x, y, 0.2f);
			stoppedRAnim->NextFrame();
			break;

		case STOPPEDL:
			stoppedLAnim->Draw(x, y, 0.2f);
			stoppedLAnim->NextFrame();
			break;
	
		case JUMPR:
			jumpRAnim->Draw(x, y, 0.2f);
			jumpRAnim->NextFrame();
			break;

		case JUMPL:
			jumpLAnim->Draw(x, y, 0.2f);
			jumpLAnim->NextFrame();
			break;

		case FALLR:
			fallRAnim->Draw(x, y, 0.2f);
			if (fallRAnim->frame == 1) {
				if (grounded) {
					fallRAnim->NextFrame();
				} else {
					fallRAnim->frame = 0;
					fallRAnim->NextFrame();
				}
			} else {
				fallRAnim->NextFrame();
			}
			break;
		
		case FALLL:
			fallLAnim->Draw(x, y, 0.2f);
			if (fallLAnim->frame == 1) {
				if (grounded) {
					fallLAnim->NextFrame();
				} else {
					fallLAnim->frame = 0;
					fallLAnim->NextFrame();
				}
			} else {
				fallLAnim->NextFrame();
			}
			break;

	}
}

void Player::StateMachine() {
	if (velX > 0 && velY < 0) {
		currentState = JUMPR;
	} else if (velX < 0 && velY < 0) {
		currentState = JUMPL;
	} else if (!grounded && velY > 0) {
		if (currentState == RIGHT || currentState == STOPPEDR) {
			currentState = FALLR;
		} else if (currentState == LEFT || currentState == STOPPEDL) {
			currentState = FALLL;
		}
	} else if (velX > 0) {
		currentState = RIGHT;
	} else if (velX < 0) {
		currentState = LEFT;
	} else {
		if (currentState == RIGHT || currentState == FALLR) {
			currentState = STOPPEDR;
		} else if (currentState == LEFT || currentState == FALLL) {
			currentState = STOPPEDL;
		}
	}
}


void Player::Jump() {
	if (window->KeyDown(VK_SPACE) && jumpProgress >= jumpDistance && grounded) {
		jumpProgress = 0;
	}

	if (jumpProgress < jumpDistance) {
		y += 20;
		jumpProgress += 30;
	}
}

void Player::Gravity() {
	if (!grounded) {
		velY += 980 * gameTime;
	} else {
		velY = 0;
		collisionPrecision = 0;
		grounded = false;
	}
}

void Player::OnCollision(Object* obj) {
	if (obj->Type() == TILE) {
		grounded = true;

		Tile* tile = (Tile*)obj;
		switch (tile->bbox->type) {
			case RECTANGLE_T:
				Rect * rect = (Rect*)tile->bbox;

				if (rect->Top() == y + stoppedR->Height() / 2) {
					collisionPrecision = rect->Top();
				} 
		}
	}
}