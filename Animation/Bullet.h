#ifndef _GRANDCHAINS_BULLET_H_
#define _GRANDCHAINS_BULLET_H_

// Includes ----------
#include "Object.h"
#include "Animation.h"
#include "TileSet.h"
#include "Sprite.h"
#include "GrandChains.h"
// -------------------

// Objeto do personagem principal ---------------------------------------------------------------------------------------------------
class Bullet : public Object {
private:
	Sprite* bulletR					= new Sprite("Resources/bulletR.png");							// Sprite do tiro para direita
	Sprite* bulletL					= new Sprite("Resources/bulletL.png");							// Sprite do tiro para esquerda
	TileSet* chargedBullet			= new TileSet("Resources/stoppedL.png", 150, 150, 10, 10);		// Sprite do tiro carregado
	Animation* chargedBulletAnim	= new Animation(chargedBullet, 1.0 / 10.0, true);				// Animação do tiro carregado

	float velX = 700;		// Velocidade do player no eixo X

public:
	Bullet(int startX, int startY);		// Construtor
	~Bullet();							// Destrutor

	void OnCollision(Object* obj);	// Detecta as colisões do player
	void Update();					// Atualiza lógica do jogo
	void Draw();					// Desenha os quadros do jogo

	void Left();
	void Right();
	void StateMachine();			// Interpretador de estados
};
// ----------------------------------------------------------------------------------------------------------------------------------

#endif

