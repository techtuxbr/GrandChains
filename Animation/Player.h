#ifndef _GRANDCHAINS_PLAYER_H_
#define _GRANDCHAINS_PLAYER_H_

// Includes ----------
#include "Object.h"
#include "Sprite.h"
#include "Animation.h"
#include "TileSet.h"
// -------------------

// Objeto do personagem principal -------------------------------------------------------
class Player : public Object {
private:
	TileSet*	stoppedR = nullptr;			// Sprite do estado parado
	Animation*	stoppedRAnim = nullptr;		// Anima��o do estado parado
	TileSet*	stoppedL = nullptr;			// Sprite do estado parado
	Animation*	stoppedLAnim = nullptr;		// Anima��o do estado parado
	TileSet*	right = nullptr;			// Sprite do estado andando para a direita
	Animation*	rightAnim = nullptr;		// Anima��o do estado andando para a direita
	TileSet*	left = nullptr;				// Sprite do estado andando para a esquerda
	Animation*	leftAnim = nullptr;			// Anima��o do estado andando para a esquerda
	TileSet*	jumpR = nullptr;			// Sprite do estado pulando para a direita
	Animation*	jumpRAnim = nullptr;		// Anima��o do estado pulando para a direita
	TileSet*	jumpL = nullptr;			// Sprite do estado pulando para a esquerda
	Animation*	jumpLAnim = nullptr;		// Anima��o do estado pulando para a esquerda	
	TileSet*	fallR = nullptr;			// Sprite do estado caindo para a direita
	Animation*	fallRAnim = nullptr;		// Anima��o do estado caindo para a direita
	TileSet*	fallL = nullptr;			// Sprite do estado caindo para a esquerda
	Animation*	fallLAnim = nullptr;		// Anima��o do estado caindo para a esquerda

	uint currentState = NULL;		// Estado atual do player
	enum PLAYERSTATE {				// Estados poss�veis
		FALLR, FALLL,
		STOPPEDR, STOPPEDL,		
		JUMPR, JUMPL,
		RIGHT, LEFT
	};


	bool jumpCtrl = NULL;
	int collisionPrecision = NULL;

	bool grounded = NULL;


	float velX = NULL;		// Velocidade do player no eixo X
	float velY = NULL;		// Velocidade do player no eixo Y

	int jumpDistance = NULL;
	int jumpProgress = NULL;
public:
	Player(int startX, int startY);		// Construtor
	~Player();							// Destrutor


	void OnCollision(Object* obj);	// Detecta as colis�es do player
	void Update();					// Atualiza l�gica do jogo
	void Draw();					// Desenha os quadros do jogo

	void Jump();	
	void Gravity();
	void StateMachine();
};
// --------------------------------------------------------------------------------------

#endif
