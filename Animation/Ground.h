#ifndef _GRANDCHAINS_GROUND_H_
#define _GRANDCHAINS_GROUND_H_

// Includes ----------
#include "Object.h"
#include "Animation.h"
// -------------------

// Objeto do personagem principal -------------------------------------------------------
class Ground : public Object {
private:
	int width = NULL;		// Variação no eixo X
	int height = NULL;		// Variação no eixo Y

public:
	Ground(int startX, int startY, int width, int height);			// Construtor de plataforma estática
	~Ground();														// Destrutor

	void Update();	// Atualiza lógica do jogo
	void Draw();	// Desenha os quadros do jogo
};
// --------------------------------------------------------------------------------------

#endif