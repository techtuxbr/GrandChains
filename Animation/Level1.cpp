// Includes ------------
#include "Engine.h"
#include "Level1.h"
#include "StartScreen.h"
#include "Player.h"
// ---------------------

void Level1::Init() {
	scene = new Scene();

	Player* player = new Player();
	scene->Add(player, MOVING);
	//FRANCISCO MILTON
	background = new Sprite("Resources/backgroundLevel1.jpg");
}

void Level1::Finalize() {
	delete background;
}

void Level1::Update() {
	// Sai do jogo com a tecla ESC ---------
	if (window->KeyDown(VK_ESCAPE)) {
		Engine::Next<StartScreen>();
	} else {
		scene->Update();
	}
	// -------------------------------------
}

void Level1::Draw() {
	background->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
	scene->Draw();
}