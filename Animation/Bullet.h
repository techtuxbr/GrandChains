#ifndef _GRANDCHAINS_BULLET_H_
#define _GRANDCHAINS_BULLET_H_

// Includes ----------
#include "Object.h"
#include "Animation.h"
#include "TileSet.h"
#include "Sprite.h"
#include "GrandChains.h"
#include "Level1.h"
// -------------------

// Objeto do personagem principal ---------------------------------------------------------------------------------------------------
class Bullet : public Object {
private:
	enum states {RIGHT, LEFT};		// Estados poss�veis da bala
	uint state;						// Estado atual

	Sprite* bulletR					= new Sprite("Resources/bulletR.png");							// Sprite do tiro para direita
	Sprite* bulletL					= new Sprite("Resources/bulletL.png");							// Sprite do tiro para esquerda
	TileSet* chargedBullet			= new TileSet("Resources/stoppedL.png", 150, 150, 10, 10);		// Sprite do tiro carregado
	Animation* chargedBulletAnim	= new Animation(chargedBullet, 1.0 / 10.0, true);				// Anima��o do tiro carregado

	float velX;			// Velocidade do player no eixo X
	float vel;			// Velocidade do player no eixo X

	uint level;	// Level que a bala est� sendo renderizada
	Game* actualLevel;	// Level que a bala est� sendo renderizada

	Object* father;		// Dono da bala
	uint fatherType;	// Tipo do dono da bala (Mant�m integridade)

public:
	Bullet(int startX, int startY, int vel, Game* actualLevel, uint level, Object* father);		// Construtor
	~Bullet();																					// Destrutor

	void OnCollision(Object* obj);	// Detecta as colis�es do player
	void Update();					// Atualiza l�gica do jogo
	void Draw();					// Desenha os quadros do jogo

	void Left();					// Bala para a esquerda
	void Right();					// Bala para a direita
	void Delete(Object* obj);		// Deleta objeto selecionado ("this" para deletar a pr�pia bala)
};
// ----------------------------------------------------------------------------------------------------------------------------------

#endif

