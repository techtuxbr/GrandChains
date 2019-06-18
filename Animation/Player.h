#ifndef _GRANDCHAINS_PLAYER_H_
#define _GRANDCHAINS_PLAYER_H_

// Includes ----------
#include "Object.h"
#include "Animation.h"
#include "TileSet.h"
#include "Game.h"
// -------------------

// Objeto do personagem principal ---------------------------------------------------------------------------------------------------
class Player : public Object {
private:
	int spriteSize = 100;

	uint currentState = NULL;														// Estado atual do player
	enum PLAYERSTATE {	RIGHT,	LEFT,	STOPPEDR,	STOPPEDL,	FALLR,	FALLL,		// Estados possíveis
						RIGHTS,	LEFTS,	STOPPEDRS,	STOPPEDLS,	FALLRS,	FALLLS};			

	TileSet*	right			= new TileSet("Resources/playerRight.png", spriteSize, spriteSize, 10, 10);			// Sprite do estado andando para a direita
	Animation*	rightAnim		= new Animation(right, 1.0 / 10.0, true);											// Animação do estado andando para a direita
	TileSet*	rightS			= new TileSet("Resources/playerRightShooting.png", spriteSize, spriteSize, 10, 10);	// Sprite do estado andando para a direita
	Animation*	rightSAnim		= new Animation(rightS, 1.0 / 10.0, true);											// Animação do estado andando para a direita
	TileSet*	left			= new TileSet("Resources/playerleft.png", spriteSize, spriteSize, 10, 10);			// Sprite do estado andando para a esquerda
	Animation*	leftAnim		= new Animation(left, 1.0 / 10.0, true);											// Animação do estado andando para a esquerda
	TileSet*	leftS			= new TileSet("Resources/playerleftShooting.png", spriteSize, spriteSize, 10, 10);	// Sprite do estado andando para a esquerda
	Animation*	leftSAnim		= new Animation(leftS, 1.0 / 10.0, true);											// Animação do estado andando para a esquerda
	TileSet*	stoppedR		= new TileSet("Resources/stoppedRight.png", spriteSize, spriteSize, 10, 10);		// Sprite do estado parado
	Animation*	stoppedRAnim	= new Animation(stoppedR, 1.0 / 10.0, true);										// Animação do estado parado
	TileSet*	stoppedRS		= new TileSet("Resources/stoppedRightShooting.png", spriteSize, spriteSize, 2, 2);	// Sprite do estado parado
	Animation*	stoppedRSAnim	= new Animation(stoppedRS, 0.5 / 2, true);											// Animação do estado parado
	TileSet*	stoppedL		= new TileSet("Resources/stoppedLeft.png", spriteSize, spriteSize, 10, 10);			// Sprite do estado parado
	Animation*	stoppedLAnim	= new Animation(stoppedL, 1.0 / 10.0, true);										// Animação do estado parado
	TileSet*	stoppedLS		= new TileSet("Resources/stoppedLeftShooting.png", spriteSize, spriteSize, 2, 2);	// Sprite do estado parado
	Animation*	stoppedLSAnim	= new Animation(stoppedLS, 0.5 / 2, true);											// Animação do estado parado
	TileSet*	fallR			= new TileSet("Resources/fallRight.png", spriteSize, spriteSize, 2, 2);				// Sprite do estado caindo para a direita
	Animation*	fallRAnim		= new Animation(fallR, 1.0 / 10.0, true);											// Animação do estado caindo para a direita
	TileSet*	fallRS			= new TileSet("Resources/fallRightShooting.png", spriteSize, spriteSize, 2, 2);		// Sprite do estado caindo para a direita
	Animation*	fallRSAnim		= new Animation(fallRS, 1.0 / 10.0, true);											// Animação do estado caindo para a direita
	TileSet*	fallL			= new TileSet("Resources/fallLeft.png", spriteSize, spriteSize, 2, 2);				// Sprite do estado caindo para a esquerda
	Animation*	fallLAnim		= new Animation(fallL, 1.0 / 10.0, true);											// Animação do estado caindo para a esquerda
	TileSet*	fallLS			= new TileSet("Resources/fallLeftShooting.png", spriteSize, spriteSize, 2, 2);		// Sprite do estado caindo para a esquerda
	Animation*	fallLSAnim		= new Animation(fallLS, 1.0 / 10.0, true);											// Animação do estado caindo para a esquerda

	Game* actualLevel;		// Informa o level atual do player
	uint level;		// Informa o level atual do player

	bool upped		= false;	// Define se o jogador colidiu a cabeça
	bool grounded	= false;	// Define se o jogador colidiu com o chão
	bool righted	= false;	// Define se o jogador não pode andar pra direita
	bool lefted		= false;	// Define se o jogador não pode andar pra esquerda
	bool dead		= false;

	int facingRight	= true;		// Define se jogador está virado para a direita
	float fireTime	= -1;

	float velX			= 0;		// Velocidade do player no eixo X
	float velY			= 0;		// Velocidade do player no eixo Y
	float moveSpeed		= 400;		// Velocidade de movimento
	float jumpSpeed		= 720;		// Velocidade do pulo
	float jumpHeight	= 16000;	// Altura do pulo (quanto menor esse número, maior a altura)
	int jumpDistance	= 5000;		// Variável de controle de distância
	int jumpProgress	= 5000;		// Varia até o jumpDistance
	float gravityScale	= 270;		// Força da gravidade

public:
	Player(int startX, int startY, Game* actualScene, uint level);		// Construtor
	~Player();										// Destrutor

	void OnCollision(Object* obj);	// Detecta as colisões do player
	void Update();					// Atualiza lógica do jogo
	void Draw();					// Desenha os quadros do jogo

	void Jump();					// Realiza o pulo do personagem
	void Gravity();					// Aplica gravidade ao objeto
	void StateMachine();			// Interpretador de estados

	void setDead(bool state);
	bool isDead();
};
// ----------------------------------------------------------------------------------------------------------------------------------

#endif
