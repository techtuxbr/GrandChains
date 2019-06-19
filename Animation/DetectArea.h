#ifndef _GRANDCHAINS_DETECTAREA_H_
#define _GRANDCHAINS_DETECTAREA_H_

// Includes ----------
#include "Object.h"
#include "Sprite.h"
#include "Animation.h"
#include "Game.h"
// -------------------

// Objeto do personagem principal -------------------------------------------------------
class DetectArea : public Object {
private:
	Object* father;
	uint enemyType;
	uint level;
	Game* actualLevel;

public:
	DetectArea(	float startX, float startY, float bboX1, float bboxY1, float bboX2, 
				float bboxY2, Game* actualLevel, uint level, Object* father, uint enemyType	);	// Construtor de plataforma estática
	~DetectArea();																				// Destrutor

	void OnCollision(Object* obj);
	void Update();	// Atualiza lógica do jogo
	void Draw();	// Desenha os quadros do jogo
	void Delete(Object* obj);
};
// --------------------------------------------------------------------------------------

#endif
