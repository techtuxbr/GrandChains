// Includes ------------
#include "Engine.h"
#include "Level1.h"
#include "StartScreen.h"
#include "Player.h"
#include "Tile.h"
#include "Bullet.h"
#include "Turret.h"
#include "GameOver.h"
// ---------------------

void Level1::Init() {
	scene = new Scene();

	Player* player = new Player(100, window->CenterY() - 360, this, LEVEL1);
	scene->Add(player, MOVING);

	float startX = 16;
	float startY = 32;
	float wallSX = 4;
	float wallSY = 24;

	Tile* wall = new Tile(wallSX, window->Height() - wallSY * 3, WALL);
	scene->Add(wall, STATIC);
	Tile* wall2 = new Tile(wallSX, window->Height() - wallSY * 5, WALL);
	scene->Add(wall2, STATIC);
	Tile* wall3 = new Tile(wallSX, window->Height() - wallSY * 7, WALL);
	scene->Add(wall3, STATIC);
	Tile* wall4 = new Tile(wallSX, window->Height() - wallSY * 9, WALL);
	scene->Add(wall4, STATIC);
	Tile* wall5 = new Tile(wallSX, window->Height() - wallSY * 11, WALL);
	scene->Add(wall5, STATIC);
	Tile* wall6 = new Tile(wallSX, window->Height() - wallSY * 13, WALL);
	scene->Add(wall6, STATIC);
	Tile* wall7 = new Tile(wallSX, window->Height() - wallSY * 15, WALL);
	scene->Add(wall7, STATIC);
	Tile* wall8 = new Tile(wallSX, window->Height() - wallSY * 17, WALL);
	scene->Add(wall8, STATIC);
	Tile* wall9 = new Tile(wallSX, window->Height() - wallSY * 19, WALL);
	scene->Add(wall9, STATIC);
	Tile* wall10 = new Tile(wallSX, window->Height() - wallSY * 21, WALL);
	scene->Add(wall10, STATIC);
	Tile* wall11 = new Tile(wallSX, window->Height() - wallSY * 23, WALL);
	scene->Add(wall11, STATIC);
	Tile* wall12 = new Tile(wallSX, window->Height() - wallSY * 25, WALL);
	scene->Add(wall12, STATIC);
	Tile* wall13 = new Tile(wallSX, window->Height() - wallSY * 27, WALL);
	scene->Add(wall13, STATIC);
	Tile* wall14 = new Tile(wallSX, window->Height() - wallSY * 29, WALL);
	scene->Add(wall14, STATIC);

	Tile* wall15 = new Tile(window->Width() - wallSX, window->Height() - wallSY * 3, WALL);
	scene->Add(wall15, STATIC);
	Tile* wall16 = new Tile(window->Width() - wallSX, window->Height() - wallSY * 5, WALL);
	scene->Add(wall16, STATIC);
	Tile* wall17 = new Tile(window->Width() - wallSX, window->Height() - wallSY * 7, WALL);
	scene->Add(wall17, STATIC);
	Tile* wall18 = new Tile(window->Width() - wallSX, window->Height() - wallSY * 9, WALL);
	scene->Add(wall18, STATIC);
	Tile* wall19 = new Tile(window->Width() - wallSX, window->Height() - wallSY * 11, WALL);
	scene->Add(wall19, STATIC);
	Tile* wall20 = new Tile(window->Width() - wallSX, window->Height() - wallSY * 13, WALL);
	scene->Add(wall20, STATIC);
	Tile* wall21 = new Tile(window->Width() - wallSX, window->Height() - wallSY * 15, WALL);
	scene->Add(wall21, STATIC);
	Tile* wall22 = new Tile(window->Width() - wallSX, window->Height() - wallSY * 17, WALL);
	scene->Add(wall22, STATIC);
	Tile* wall23 = new Tile(window->Width() - wallSX, window->Height() - wallSY * 19, WALL);
	scene->Add(wall23, STATIC);
	Tile* wall24 = new Tile(window->Width() - wallSX, window->Height() - wallSY * 21, WALL);
	scene->Add(wall24, STATIC);
	Tile* wall25 = new Tile(window->Width() - wallSX, window->Height() - wallSY * 23, WALL);
	scene->Add(wall25, STATIC);
	Tile* wall26 = new Tile(window->Width() - wallSX, window->Height() - wallSY * 25, WALL);
	scene->Add(wall26, STATIC);
	Tile* wall27 = new Tile(window->Width() - wallSX, window->Height() - wallSY * 27, WALL);
	scene->Add(wall27, STATIC);
	Tile* wall28 = new Tile(window->Width() - wallSX, window->Height() - wallSY * 29, WALL);
	scene->Add(wall28, STATIC);

	Tile* tile = new Tile(startX, window->Height() - startY, FULL);
	scene->Add(tile, STATIC);
	Tile* tile2 = new Tile(startX * 3, window->Height() - startY, FULL);
	scene->Add(tile2, STATIC);
	Tile* tile3 = new Tile(startX * 5, window->Height() - startY, FULL);
	scene->Add(tile3, STATIC);
	Tile* tile4 = new Tile(startX * 7, window->Height() - startY, FULL);
	scene->Add(tile4, STATIC);
	Tile* tile5 = new Tile(startX * 9, window->Height() - startY, FULL);
	scene->Add(tile5, STATIC);
	Tile* tile6 = new Tile(startX * 11, window->Height() - startY, FULL);
	scene->Add(tile6, STATIC);
	Tile* tile7 = new Tile(startX * 23, window->Height() - startY, FULL);
	scene->Add(tile7, STATIC);
	Tile* tile8 = new Tile(startX * 25, window->Height() - startY, FULL);
	scene->Add(tile8, STATIC);
	Tile* tile9 = new Tile(startX * 27, window->Height() - startY, FULL);
	scene->Add(tile9, STATIC);

	Turret* turret = new Turret(window->CenterX(), window->CenterY() - 78, this, LEVEL1);
	scene->Add(turret, STATIC);

	
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
	} else if (window->KeyDown('N')) {
		Engine::Next<GameOver>();
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

void Level1::AddObject(Object* obj, uint objType) {
	scene->Add(obj, objType);
}


