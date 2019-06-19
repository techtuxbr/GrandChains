#ifndef _GRANDCHAINS_TURRET_H_
#define _GRANDCHAINS_TURRET_H_

// Includes ----------
#include "Object.h"
#include "Animation.h"
#include "DetectArea.h"
#include "GrandChains.h"
#include "Bullet.h"
// -------------------

// Objeto do personagem principal -------------------------------------------------------
class Turret : public Object {
private:
	enum states { LEFT, RIGHT };
	bool shooting;
	bool facingRight = true;

	Game* actualLevel;

	uint level;
	uint state = RIGHT;

	float fireTime = 0;

	TileSet*	turretR		= new TileSet("Resources/turretR.png", 121, 74, 3, 3);
	Animation*	turretRAnim	= new Animation(turretR, 1.0 / 3.0, TRUE);
	TileSet*	turretL		= new TileSet("Resources/turretL.png", 121, 74, 3, 3);
	Animation*	turretLAnim	= new Animation(turretL, 1.0 / 3.0, TRUE);

	DetectArea* detectArea = nullptr;

public:
	Turret(	int startX, int startY, float bboX1, float bboxY1, float bboX2, float bboxY2, Game* actualLevel, uint level );				// Construtor de plataforma estática
	~Turret();																	// Destrutor

	void Update();		// Atualiza lógica do jogo
	void Draw();		// Desenha os quadros do jogo

	void Shooting();
	void Left();
	void Right();
};
// --------------------------------------------------------------------------------------

#endif