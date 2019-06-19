#ifndef _GRANDCHAINS_GROUND_H_
#define _GRANDCHAINS_GROUND_H_

// Includes ----------
#include "Object.h"
#include "Animation.h"
// -------------------

// Objeto do personagem principal -------------------------------------------------------
class Ground : public Object {
private:
	int width = NULL;		// Varia��o no eixo X
	int height = NULL;		// Varia��o no eixo Y

public:
	Ground(int startX, int startY, int width, int height);			// Construtor de plataforma est�tica
	~Ground();														// Destrutor

	void Update();	// Atualiza l�gica do jogo
	void Draw();	// Desenha os quadros do jogo
};
// --------------------------------------------------------------------------------------

#endif