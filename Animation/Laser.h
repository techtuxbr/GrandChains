#ifndef _GRANDCHAINS_LASER_H_
#define _GRANDCHAINS_LASER_H_

// Includes ----------
#include "Object.h"
#include "Animation.h"
#include "Sprite.h"
#include "Game.h"
#include "DetectArea.h"
// -------------------

enum directions { RIGHT, LEFT, UP, DOWN };

// Objeto do personagem principal -------------------------------------------------------
class Laser : public Object {
private:
	uint direction;

	Game* actualLevel;
	uint level;
	DetectArea* detectArea;

	Sprite* ejector;
	TileSet* fire;
	Animation* fireAnim;

	bool firing;

	float countFireTime = 0;
	float countFireOut = 0;
	float fireTime;
	float fireOut;

public:
	Laser(int startX, int startY, uint direction, float fireTime, float fireOut, Game* actualLevel, uint level);			// Construtor de plataforma estática
	~Laser();								// Destrutor

	void Update();	// Atualiza lógica do jogo
	void Draw();	// Desenha os quadros do jogo
	bool isFiring();
};
// --------------------------------------------------------------------------------------

#endif