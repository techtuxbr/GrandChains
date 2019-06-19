#ifndef _GRANDCHAINS_LIFE_H_
#define _GRANDCHAINS_LIFE_H_

// Includes -------
#include "Object.h"
#include "Sprite.h"
// ----------------

// Classe da cena Life ----------------------------------------------
class Life : public Object {
private:
	Sprite* life = new Sprite("Resources/life.png");	// Sprite do coração

public:
	Life(float startX, float startY);	// inicializa jogo
	~Life();							// atualiza lógica do jogo
	void Update();
	void Draw();						// desenha jogo
};
// --------------------------------------------------------------------

#endif