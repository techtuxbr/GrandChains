#ifndef _GRANDCHAINS_GAMEOVER_H_
#define _GRANDCHAINS_GAMEOVER_H_

// Includes -------
#include "Game.h"
#include "Sprite.h"
#include "Scene.h"
// ----------------

// Classe da cena GameOver ----------------------------------------------
class GameOver : public Game {
private:
	Scene*	scene;
	Sprite* background	= nullptr;	// Background
	bool	esc			= false;	// Controla o pressionamento do ESC

public:

	void Init();		// inicializa jogo
	void Update();		// atualiza l�gica do jogo
	void Draw();		// desenha jogo
	void Finalize();	// finaliza jogo
};
// --------------------------------------------------------------------

#endif