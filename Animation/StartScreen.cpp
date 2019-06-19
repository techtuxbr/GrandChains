#include "Engine.h"
#include "StartScreen.h"
#include "Level1.h"

void StartScreen::Init() {
	background = new Sprite("Resources/startScreen.png");
}

void StartScreen::Finalize() {
	delete background;
}

void StartScreen::Update() {
	// Sai do jogo com a tecla ESC
	if (window->KeyUp(VK_ESCAPE)) {
		esc = true;
	}
	if (esc && window->KeyDown(VK_ESCAPE)) {
		window->Close();
		esc = false;
	}
	// ----------------------------

	// Passa ao primeiro n�vel com ENTER
	if (window->KeyUp(VK_RETURN)) {
		ent = true;
	}
	if (ent && window->KeyDown(VK_RETURN)) {
		Engine::Next<Level1>();
		ent = false;
	}
	// ---------------------------------	
}

void StartScreen::Draw() {
	background->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
}