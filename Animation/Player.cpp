#include "Engine.h"
#include "Player.h"
#include "Animation.h"
#include "TileSet.h"

Player::Player() {
	x = window->CenterX();
	y = window->CenterY();
	velX = 200;
	velY = 0;

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
	
	fallR = new TileSet("Resources/fallR.png", 150, 197, 5, 5);
	fallRAnim = new Animation(jumpR, 1.0 / 10.0, true);

	fallL = new TileSet("Resources/fallL.png", 150, 197, 5, 5);
	fallLAnim = new Animation(jumpL, 1.0 / 10.0, true);
}

Player::~Player() {
	delete left;
	delete leftAnim;
}

void Player::Update() {
	// Pressionar RightArrow -----------------------
	if (window->KeyDown(VK_RIGHT)) {
		Translate(velX * gameTime, velY * gameTime);
		currentState = RIGHT;
	}
	// ---------------------------------------------
	// Pressionar LeftArrow -------------------------
	else if (window->KeyDown(VK_LEFT)) {
		Translate(-velX * gameTime, velY * gameTime);
		currentState = LEFT;
	} 
	// ----------------------------------------------
	// Pressionar Space -----------------
	else if (window->KeyDown(VK_SPACE)) {
		if (currentState == LEFT) {
			currentState == JUMPL;
		} else if (currentState == RIGHT) {
			currentState == JUMPR;
		} 
	} 
	// ----------------------------------
	// Nada pressionado ------------
	else {
		if (currentState == LEFT) {
			currentState = STOPPEDL;
		} else {
			currentState = STOPPEDR;
		}
	}
	// -----------------------------
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
	}
}

void Jump() {

}

void Gravity(){
	//xumpeter
}