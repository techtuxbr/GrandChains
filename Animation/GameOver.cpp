// Includes ------------
#include "Engine.h"
#include "GameOver.h"
#include "StartScreen.h"
// ---------------------

void GameOver::Init() {
	scene = new Scene();

	background = new Sprite("Resources/backgroundGameOver.jpg");
}

void GameOver::Finalize() {
	delete background;
	delete scene;
}

void GameOver::Update() {
	// Sai do jogo com a tecla ESC
	if (window->KeyUp(VK_ESCAPE)) {
		esc = true;
	}
	if (esc && window->KeyDown(VK_ESCAPE)) {
		Engine::Next<StartScreen>();
		esc = false;
	} else {
		scene->Update();
		scene->CollisionDetection();
	}
	// ----------------------------
}

void GameOver::Draw() {
	background->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
	scene->Draw();
}


