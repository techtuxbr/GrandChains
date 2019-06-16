#ifndef _GRANDCHAINS_LEVEL1_H_
#define _GRANDCHAINS_LEVEL1_H_

// Includes -------
#include "Game.h"
#include "Sprite.h"
#include "Scene.h"
// ----------------

// Classe da cena Level1 ----------------------------------------------
class Level1 : public Game {
private:
	Sprite* background = nullptr;	// Background

	bool viewBBox = false;	// habilita visualização da bounding box
	bool ctrlKeyB = false;	// habilita visualização da bounding box
public:
	static Scene* scene;	// Gerenciador de cena

	void Init();		// inicializa jogo
	void Update();		// atualiza lógica do jogo
	void Draw();		// desenha jogo
	void Finalize();	// finaliza jogo
};
// --------------------------------------------------------------------

#endif