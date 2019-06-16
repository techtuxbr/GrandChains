// Includes ------------
#include "Engine.h"
#include "Level1.h"
#include "StartScreen.h"
#include "Player.h"
#include "Tile.h"
#include "Bullet.h"
// ---------------------

Scene* Level1::scene = nullptr;

void Level1::Init() {
	scene = new Scene();

	Player* player = new Player(window->CenterX(), window->CenterY() - 300, 400, 720, 16000, LEVEL1);
	scene->Add(player, MOVING);

	Tile* tile = new Tile(window->CenterX(), window->CenterY());
	scene->Add(tile, STATIC);
	
	Tile* tile2 = new Tile(window->CenterX() - 500, window->CenterY());
	scene->Add(tile2, STATIC);
	
	Tile* tile3 = new Tile(window->CenterX() + 500, window->CenterY());
	scene->Add(tile3, STATIC);

	background = new Sprite("Resources/backgroundLevel1.jpg");
}

void Level1::Update() {
	// habilita visualização da bounding box
	if (window->KeyUp('B'))
		ctrlKeyB = true;

	// habilita/desabilita visualização da bounding box
	if (ctrlKeyB && window->KeyDown('B')) {
		viewBBox = !viewBBox;
		ctrlKeyB = false;
	}

	// Sai do jogo com a tecla ESC ---------
	if (window->KeyDown(VK_ESCAPE)) {
		Engine::Next<StartScreen>();
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
}

