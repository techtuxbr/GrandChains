// Includes ------------
#include "Engine.h"
#include "GameOver.h"
#include "StartScreen.h"
// ---------------------

void GameOver::Init() {
	scene = new Scene();
	background = new Sprite("Resources/backgroundGameOver.png");
}

void GameOver::Finalize() {
	delete scene;
	delete background;
}

void GameOver::Update() {
	// Sai do jogo com a tecla ESC ---
	if (window->KeyUp(VK_RETURN)) {
		esc = true;
	}
	if (esc && window->KeyDown(VK_RETURN)) {
		Engine::Next<StartScreen>();
		esc = false;
	} else {
		scene->Update();
	}
	// -------------------------------
}

void GameOver::Draw() {
	background->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
	scene->Draw();
}


