#ifndef _GRANDCHAINS_HOME_H_
#define _GRANDCHAINS_HOME_H_

// Includes -------
#include "Game.h"
#include "Sprite.h"
// ----------------

// Objeto da tela principal -------------------------------------------
class StartScreen : public Game {
private:
	Sprite* background = nullptr;	// Background
	Sprite* enter = nullptr;		// Pressione Enter
	bool	esc = false;			// controla o pressionamento do ESC

public:
	void Init();		// inicializa jogo
	void Update();		// atualiza l�gica do jogo
	void Draw();		// desenha jogo
	void Finalize();	// finaliza jogo
};
// --------------------------------------------------------------------

#endif