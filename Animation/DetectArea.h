#ifndef _GRANDCHAINS_DETECTAREA_H_
#define _GRANDCHAINS_DETECTAREA_H_

// Includes ----------
#include "Object.h"
#include "Sprite.h"
#include "Animation.h"
// -------------------

// Objeto do personagem principal -------------------------------------------------------
class DetectArea : public Object {
private:
	Object* father;
public:
	DetectArea(int startX, int startY, int sizeX, int sizeY, Object* father);		// Construtor de plataforma estática
	~DetectArea();													// Destrutor

	void OnCollision(Object* obj);
	void Update();	// Atualiza lógica do jogo
	void Draw();	// Desenha os quadros do jogo
};
// --------------------------------------------------------------------------------------

#endif
