#include "Player.h"
#include "iostream"

Player::Player(int startX, int startY, uint level) {
	// Define tamanho da Bounding Box do player ------
	bbox = new Rect(-spriteSize/2, -spriteSize/2, spriteSize/2, spriteSize/2);
	// -----------------------------------------------

	actualLevel = level;

	// Define estados inciais ---------------------------
	type = PLAYER;						// Tipo do objeto	
	MoveTo(startX, startY);				// Posição incial
	// --------------------------------------------------
}

Player::~Player() {
	// Limpa memória
	delete right;
	delete left;
	delete stoppedR;
	delete stoppedL;
	delete fallR;
	delete fallL;
	// -------------
}

void Player::Update() {
	// Processamento de input --------------------------------------------
	if (window->KeyDown(VK_RIGHT) && !righted) {			// Right Arrow
		velX = moveSpeed;
	} else if (window->KeyDown(VK_LEFT) && !lefted) {		// Left Arrow
		velX = -moveSpeed;
	} else {
		velX = 0;
	}

	if (window->KeyDown(0x5A) && fireTime < 0) {			// Z
		Bullet* bullet;

		if (facingRight) {
			bullet = new Bullet(x + 50, y, 700, actualLevel, this);
			bullet->Right();
		} else {
			bullet = new Bullet(x - 50, y, 700, actualLevel, this);
			bullet->Left();
		}
		
		switch (actualLevel) {
			case LEVEL1:
				Level1::scene->Add(bullet, MOVING);
				break;
		}

		if (fireTime < 0) {
			fireTime = 0.5;
		}
	}
	// ----------------------------------------------------------------------



	// Movimento -------------------------------------------
	x += velX * gameTime;	// Movimento em X
	Jump();					// Movimento em Y		
	// -----------------------------------------------------

	// Analisa o estado atual baseado no movimento
	StateMachine();
	// -------------------------------------------

	// Calcula o tempo para o próximo tiro
	if (fireTime > -1) {
		fireTime -= gameTime;
	}
	// ------------------------------------

	// Executa o cáculo da gravidade
	Gravity();				
	// -----------------------------

	// Atualiza a bounding box para a posição do player
	bbox->MoveTo(x, y); 
	// ------------------------------------------------

	// Reafirma os estados 
	righted = false;
	lefted = false;
	grounded = false; 
	upped = false;
}

void Player::Draw() {
	switch (currentState) {
		case RIGHT:
			rightAnim->Draw(x, y, 0.2f);
			rightAnim->NextFrame();
			break;

		case RIGHTS:
			rightSAnim->Draw(x, y, 0.2f);
			rightSAnim->NextFrame();
			break;

		case LEFT:
			leftAnim->Draw(x, y, 0.2f);
			leftAnim->NextFrame();
			break;
		
		case LEFTS:
			leftSAnim->Draw(x, y, 0.2f);
			leftSAnim->NextFrame();
			break;

		case STOPPEDR:
			stoppedRAnim->Draw(x, y, 0.2f);
			stoppedRAnim->NextFrame();
			break;
		
		case STOPPEDRS:
			stoppedRSAnim->Draw(x, y, 0.2f);
			stoppedRSAnim->NextFrame();
			break;

		case STOPPEDL:
			stoppedLAnim->Draw(x, y, 0.2f);
			stoppedLAnim->NextFrame();
			break;
		
		case STOPPEDLS:
			stoppedLSAnim->Draw(x, y, 0.2f);
			stoppedLSAnim->NextFrame();
			break;

		case FALLR:
			fallRAnim->Draw(x, y, 0.2f);
			// Repete a animação enquanto não tocar no chão
			if (grounded) {				
				fallRAnim->frame = 1;
			} else {
				fallRAnim->Restart();
			}
			// --------------------------------------------
			break;
		
		case FALLRS:
			fallRSAnim->Draw(x, y, 0.2f);
			if (grounded) {				
				fallRSAnim->frame = 1;
			} else {
				fallRSAnim->Restart();
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
		
		case FALLLS:
			fallLSAnim->Draw(x, y, 0.2f);
			if (grounded) {
				fallLSAnim->frame = 1;
			} else {
				fallLSAnim->Restart();
			}
			break;
	}
}

void Player::StateMachine() {
	if (velX > 0) {
		facingRight = true;
	} else if (velX < 0) {
		facingRight = false;
	}

	if (facingRight) {
		if (fireTime > 0) {
			if (!grounded) {
				currentState = FALLRS;
			} else {
				if (velX > 0) {
					currentState = RIGHTS;
				} else {
					currentState = STOPPEDRS;
				}
			}
		} else {
			if (!grounded) {
				currentState = FALLR;
			} else {
				if (velX > 0) {
					currentState = RIGHT;
				} else {
					currentState = STOPPEDR;
				}
			}
		}
	} else {
		if (fireTime > 0) {
			if (!grounded) {
				currentState = FALLLS;
			} else {
				if (velX < 0) {
					currentState = LEFTS;
				} else {
					currentState = STOPPEDLS;
				}
			}
		} else {
			if (!grounded) {
				currentState = FALLL;
			} else {
				if (velX < 0) {
					currentState = LEFT;
				} else {
					currentState = STOPPEDL;
				}
			}
		}
	}
}


void Player::Jump() {
	if (window->KeyDown(VK_SPACE) && jumpProgress >= jumpDistance && grounded) {
		jumpProgress = 0;
	}

	// Caso esteja pulando -------------------
	if (jumpProgress < jumpDistance) {
		y -= jumpSpeed * gameTime;
		jumpProgress += jumpHeight * gameTime;
		velY = jumpSpeed * gameTime;
	} else { // Não está pulando
		velY = 0;
	}

	if (upped) {
		jumpProgress = jumpDistance + 1;
	}
}

void Player::Gravity() {
	if (!grounded) {
		y += gravityScale * gameTime;
		velY += gravityScale * gameTime;
	} 
}

void Player::OnCollision(Object* obj) {
	if (obj->Type() == TILE) {

		Tile* tile = (Tile*)obj;

		Rect* object = (Rect*)tile->bbox;
		Rect* player = (Rect*)bbox;

		int objectScaleX = object->Right() - object->Left();

		if (x > tile->X()) {
			if (player->Left() - tile->X() < objectScaleX / 2 - 5) {
				if (y < tile->Y()) {
					grounded = true;
					MoveTo(x, object->Top() - spriteSize/2 + 5);
				} else {
					upped = true;
					MoveTo(x, object->Bottom() + spriteSize / 2);
				}
			} else {
				lefted = true;
			}
		} else {
			if (tile->X() - player->Right() < objectScaleX / 2 - 5) {
				if (y < tile->Y()) {
					grounded = true;
					MoveTo(x, object->Top() - spriteSize / 2 + 5);
				} else {
					upped = true;
					MoveTo(x, object->Bottom() + spriteSize / 2);
				}
			} else {
				righted = true;
			}
		}
	}
}