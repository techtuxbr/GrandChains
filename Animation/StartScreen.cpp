#include "Engine.h"
#include "StartScreen.h"
#include "Level1.h"
#include "Level2.h"

void StartScreen::Init() {
	scene = new Scene();
	background = new Sprite("Resources/startScreen.png");
}

void StartScreen::Finalize() {
	delete scene;
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
	if (window->KeyUp(VK_RETURN)) {
		ent = true;
	}
	if (ent && window->KeyDown(VK_RETURN)) {
		Engine::Next<Level2>();
		ent = false;
	} else {
		scene->Update();
	}
	// ---------------------------------	
}

void StartScreen::Draw() {
	background->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
	scene->Draw();
}