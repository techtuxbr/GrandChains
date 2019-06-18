// Includes ------------
#include "Engine.h"
#include "GameOver.h"
#include "StartScreen.h"
// ---------------------

void GameOver::Init() {
	background = new Sprite("Resources/backgroundGameOver.png");
}

void GameOver::Finalize() {
	delete background;
}

void GameOver::Update() {
	// Sai do jogo com a tecla ESC
	if (window->KeyUp(VK_ESCAPE)) {
		esc = true;
	}
	if (esc && window->KeyDown(VK_ESCAPE)) {
		Engine::Next<StartScreen>();
		esc = false;
	}
	// ----------------------------
}

void GameOver::Draw() {
	background->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
}


