// Includes ------------
#include "Level2.h"
#include "Exit.h"
#include "Laser.h"
#include "StartScreen.h"
#include "GameOver.h"
#include "Tile.h"
#include "Bullet.h"
#include "Turret.h"
#include "Engine.h"
#include "Ground.h"
// ---------------------

void Level2::Init() {
	scene = new Scene();

	player = new Player(100, 100, this, LEVEL2);
	scene->Add(player, MOVING);

	Ground* topLeft = new Ground(192.5, 199, 388, 81);
	scene->Add(topLeft, STATIC);

	Laser* laser = new Laser(600, 150, LEFT, 1, 2.5, this, LEVEL2);
	scene->Add(laser, STATIC);

	Ground* bar = new Ground(640, 175, 73, 350);
	scene->Add(bar, STATIC);

	Ground* middle = new Ground(640, 335, 198, 31);
	scene->Add(middle, STATIC);

	Ground* bottomLeft = new Ground(169, 675, 338, 89);
	scene->Add(bottomLeft, STATIC);

	Tile* tileRight = new Tile(700, 675, 200, 0, 500, 0, new Sprite("Resources/tile2.png"));
	scene->Add(tileRight, STATIC);

	Tile* tileUp = new Tile(1150, 575, 0, 200, 0, 300, new Sprite("Resources/tile2.png"));
	scene->Add(tileUp, STATIC);

	Ground* blockBootom = new Ground(915, 254, 60, 29);
	scene->Add(blockBootom, STATIC);

	Ground* blockUp = new Ground(915, 462, 60, 29);
	scene->Add(blockUp, STATIC);

	Ground* topRight = new Ground(1160, 230, 240, 72);
	scene->Add(topRight, STATIC);

	Exit* exit = new Exit(1235, 100);
	scene->Add(exit, STATIC);

	PlaySound("Resources/theme.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}

void Level2::Update() {
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
		Engine::Next<StartScreen>();
	} else {
		scene->Update();
		scene->CollisionDetection();
	}
	// -------------------------------------
}

void Level2::Draw() {
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

void Level2::Finalize() {
	delete background;
	delete scene;
	PlaySound(NULL, NULL, 0);
}


