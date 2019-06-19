#ifndef _GRANDCHAINS_EXIT_H_
#define _GRANDCHAINS_EXIT_H_

// Includes ----------
#include "Object.h"
#include "Sprite.h"
// -------------------

// Objeto do personagem principal -------------------------------------------------------
class Exit : public Object {
private:
	Sprite* exit = nullptr;

public:
	Exit(int startX, int startY);			// Construtor de plataforma est�tica
	~Exit();								// Destrutor

	void Update();	// Atualiza l�gica do jogo
	void Draw();	// Desenha os quadros do jogo
};
// --------------------------------------------------------------------------------------

#endif