#ifndef _GRANDCHAINS_HOME_H_
#define _GRANDCHAINS_HOME_H_

// Includes -------
#include "Game.h"
#include "Sprite.h"
#include "Scene.h"
// ----------------

// Objeto da tela principal -------------------------------------------
class StartScreen : public Game {
private:
	Scene* scene;
	Sprite* background = nullptr;	// Background
	bool	esc = false;			// Controla o pressionamento do ESC
	bool	ent = false;			// Controla o pressionamento do Enter

public:
	void Init();		// inicializa jogo
	void Update();		// atualiza lógica do jogo
	void Draw();		// desenha jogo
	void Finalize();	// finaliza jogo
};
// --------------------------------------------------------------------

#endif