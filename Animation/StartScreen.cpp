#include "Engine.h"
#include "StartScreen.h"
#include "Level1.h"

void StartScreen::Init() {
	enter = new Sprite("Resources/enter.png");
	background = new Sprite("Resources/backgroundLevel1.png");
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

	// Passa ao primeiro nível com ENTER
	if (window->KeyDown(VK_RETURN)) {
		Engine::Next<Level1>();
	}
	// ---------------------------------	
}

void StartScreen::Draw() {
	enter->Draw(150, float(window->CenterY()) + 80, Layer::FRONT);
	background->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
}