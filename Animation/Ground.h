#ifndef _GRANDCHAINS_GROUND_H_
#define _GRANDCHAINS_GROUND_H_

// Includes ----------
#include "Object.h"
#include "Animation.h"
// -------------------

// Objeto do personagem principal -------------------------------------------------------
class Ground : public Object {
private:
	
public:
	Ground(float startX, float startY, float width, float height);	// Construtor de plataforma est�tica
	~Ground();														// Destrutor

	void Update();	// Atualiza l�gica do jogo
	void Draw();	// Desenha os quadros do jogo
};
// --------------------------------------------------------------------------------------

#endif