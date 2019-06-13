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
	Sprite*	background = nullptr;	// Background

	Scene*	scene = nullptr;	// Gerenciador de cena

public:
	void Init();		// inicializa jogo
	void Update();		// atualiza lógica do jogo
	void Draw();		// desenha jogo
	void Finalize();	// finaliza jogo
};
// --------------------------------------------------------------------

#endif