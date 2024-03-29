// Includes ------------
#include "Level1.h"
#include "Level2.h"
#include "StartScreen.h"
#include "GameOver.h"
#include "Tile.h"
#include "Bullet.h"
#include "Turret.h"
#include "Engine.h"
#include "Ground.h"
#include "Laser.h"
#include "Exit.h"
// ---------------------

void Level1::Init() {
	scene = new Scene();

	player = new Player(100, window->CenterY(), this, LEVEL1);
	scene->Add(player, MOVING);

	Ground* ground = new Ground(0, window->Height(), 550, 200);
	scene->Add(ground, STATIC);

	Ground* ground1 = new Ground(761, window->Height(), 630, 200);
	scene->Add(ground1, STATIC);

	Ground* ground2 = new Ground(365, 182, 275, 50);
	scene->Add(ground2, STATIC);
	
	Ground* ground3 = new Ground(899, 182, 368, 50);
	scene->Add(ground3, STATIC);

	Ground* ground4 = new Ground(882, 580, 390, 125);
	scene->Add(ground4, STATIC);

	Tile* tile = new Tile(window->Width() - 64, 325, 0, 200, 0, 400, new Sprite("Resources/tile.png"));
	scene->Add(tile, STATIC);

	Turret* turret = new Turret(1000, 485, -700, -250, 300, 37, this, LEVEL1);
	scene->Add(turret, STATIC);
	
	Laser* laser = new Laser(358, window->Height() - 17, UP, 1, 2, this, LEVEL1);
	scene->Add(laser, STATIC);

	Exit* exit = new Exit(365, 65);
	scene->Add(exit, STATIC);

	PlaySound("Resources/theme.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}

void Level1::Update() {
	// Habilita visualização da bounding box
	if (window->KeyUp('B')) {
		ctrlKeyB = true;
	}
	if (ctrlKeyB && window->KeyDown('B')) {
		viewBBox = !viewBBox;
		ctrlKeyB = false;
	}
	// -------------------------------------

	// Sai do jogo com a tecla ESC ---------
	if (window->KeyDown(VK_ESCAPE)) {
		Engine::Next<StartScreen>();
	} else if (player->isDead()) {
		Engine::Next<GameOver>();
	} else if (player->isExiting() && window->KeyDown(VK_UP)) {
		Engine::Next<Level2>();
	} else {
		scene->Update();
		scene->CollisionDetection();
	}
	// -------------------------------------
}

void Level1::Draw() {
	background->Draw(float(window->CenterX()), float(window->CenterY()), Layer::BACK);
	scene->Draw();

	// desenha a bounding box de todos os objetos
	if (viewBBox) {
		Engine::renderer->BeginPixels();

		// cor compactada em 32 bits
		ulong magenta = (255 << 24) + (255 << 16) + (0 << 8) + 255;

		scene->Begin();
		Object* obj = nullptr;
		while (obj = scene->Next()) {
			if (obj->bbox)
				Engine::renderer->Draw(obj->bbox, magenta);
		}

		Engine::renderer->EndPixels();
	}
}

void Level1::Finalize() {
	delete background;
	delete scene;
	PlaySound(NULL, NULL, 0);
}


