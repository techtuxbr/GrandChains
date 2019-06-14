#include "Player.h"
#include "Animation.h"
#include "TileSet.h"
#include "Level1.h"
#include "Tile.h"

Player::Player(int startX, int startY, float mSpeed, float jSpeed, float jHeigth) {
	grounded = false;

	collisionPrecision = 0;

	currentState = STOPPEDR;

	velX = 0;
	velY = 0;
	moveSpeed = mSpeed;

	bbox = new Rect(-75 + x, -75 + y, 75 + x, 75 + y);
	MoveTo(startX, startY);
	type = PLAYER;

	jumpDistance = 5000;
	jumpProgress = 5000;
	jumpSpeed = jSpeed;
	jumpHeight = jHeigth;

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
	// Processamento de input ------------
	if (window->KeyDown(VK_RIGHT)) {
		velX = moveSpeed;
	} else if (window->KeyDown(VK_LEFT)) {
		velX = -moveSpeed;
	} else {
		velX = 0;
	}
	// -----------------------------------

	// Movimento horizontal --------------------
	x += velX * gameTime; // Movendo player no X
	// -----------------------------------------

	// Movendo player para o topo do chão, caso ele penetre-o
	if (collisionPrecision != 0) {
		MoveTo(x, collisionPrecision - 75);
	}
	// ------------------------------------------------------

	// Movimento em Y 
	Jump();
	Gravity();
	// --------------

	// Animações -----------------------------------------------
	StateMachine(); // Executando maquina de estados de animação
	// ---------------------------------------------------------

	bbox->MoveTo(x, y); // Movendo bounding box a cada frame para a posição do player

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
			if (grounded) {
				fallRAnim->frame = 1;
			} else {
				fallRAnim->Restart();
			}
			break;

		case FALLL:
			fallLAnim->Draw(x, y, 0.2f);
			if (grounded) {
				fallLAnim->frame = 1;
			} else {
				fallLAnim->Restart();
			}
			break;
	}
}

void Player::StateMachine() {
	if (velX > 0 && velY < 0) {
		currentState = JUMPR;
	} else if (velX < 0 && velY < 0) {
		currentState = JUMPL;
	} else if (!grounded && velY > 0 ) {
		if (velX > 0 || currentState == STOPPEDR) {
			currentState = FALLR;
		} else if (velX < 0 || currentState == STOPPEDL) {
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
		collisionPrecision = 0;
	}

	// Caso esteja pulando -------------------
	if (jumpProgress < jumpDistance) {
		y -= jumpSpeed * gameTime;
		jumpProgress += jumpHeight * gameTime;
		velY = jumpSpeed * gameTime;
		grounded = false;
	} else { // Não está pulando
		velY = 0;
	}
}

void Player::Gravity() {
	if (!grounded) {
		y += gravityScale * gameTime;
		velY += gravityScale * gameTime;
	} else {
		velY = 0;
		y = y;
		collisionPrecision = 0;
		grounded = false;
	}
}

void Player::OnCollision(Object* obj) {
	if (obj->Type() == TILE) {
		grounded = true;
		Tile* tile = (Tile*)obj;

		Rect* rect = (Rect*)tile->bbox;

		collisionPrecision = rect->Top();
	}
}