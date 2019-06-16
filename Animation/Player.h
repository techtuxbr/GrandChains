#ifndef _GRANDCHAINS_PLAYER_H_
#define _GRANDCHAINS_PLAYER_H_

// Includes ----------
#include "Object.h"
#include "Animation.h"
#include "TileSet.h"
#include "GrandChains.h"
#include "Tile.h"
#include "Bullet.h"
#include "Level1.h"
// -------------------

// Objeto do personagem principal ---------------------------------------------------------------------------------------------------
class Player : public Object {
private:
	uint currentState = NULL;														// Estado atual do player
	enum PLAYERSTATE {	RIGHT,	LEFT,	STOPPEDR,	STOPPEDL,	FALLR,	FALLL,		// Estados poss�veis
						RIGHTS,	LEFTS,	STOPPEDRS,	STOPPEDLS,	FALLRS,	FALLLS};			

	TileSet*	right			= new TileSet("Resources/playerRight.png", 150, 150, 10, 10);				// Sprite do estado andando para a direita
	Animation*	rightAnim		= new Animation(right, 1.0 / 10.0, true);									// Anima��o do estado andando para a direita
	TileSet*	rightS			= new TileSet("Resources/playerRightShooting.png", 150, 150, 10, 10);		// Sprite do estado andando para a direita
	Animation*	rightSAnim		= new Animation(rightS, 1.0 / 10.0, true);									// Anima��o do estado andando para a direita
	TileSet*	left			= new TileSet("Resources/playerleft.png", 150, 150, 10, 10);				// Sprite do estado andando para a esquerda
	Animation*	leftAnim		= new Animation(left, 1.0 / 10.0, true);									// Anima��o do estado andando para a esquerda
	TileSet*	leftS			= new TileSet("Resources/playerleftShooting.png", 150, 150, 10, 10);		// Sprite do estado andando para a esquerda
	Animation*	leftSAnim		= new Animation(leftS, 1.0 / 10.0, true);									// Anima��o do estado andando para a esquerda
	TileSet*	stoppedR		= new TileSet("Resources/stoppedRight.png", 150, 150, 10, 10);				// Sprite do estado parado
	Animation*	stoppedRAnim	= new Animation(stoppedR, 1.0 / 10.0, true);								// Anima��o do estado parado
	TileSet*	stoppedRS		= new TileSet("Resources/stoppedRightShooting.png", 150, 150, 2, 2);		// Sprite do estado parado
	Animation*	stoppedRSAnim	= new Animation(stoppedRS, 0.5 / 2, true);									// Anima��o do estado parado
	TileSet*	stoppedL		= new TileSet("Resources/stoppedLeft.png", 150, 150, 10, 10);				// Sprite do estado parado
	Animation*	stoppedLAnim	= new Animation(stoppedL, 1.0 / 10.0, true);								// Anima��o do estado parado
	TileSet*	stoppedLS		= new TileSet("Resources/stoppedLeftShooting.png", 150, 150, 2, 2);			// Sprite do estado parado
	Animation*	stoppedLSAnim	= new Animation(stoppedLS, 0.5 / 2, true);									// Anima��o do estado parado
	TileSet*	fallR			= new TileSet("Resources/fallRight.png", 150, 150, 2, 2);					// Sprite do estado caindo para a direita
	Animation*	fallRAnim		= new Animation(fallR, 1.0 / 10.0, true);									// Anima��o do estado caindo para a direita
	TileSet*	fallRS			= new TileSet("Resources/fallRightShooting.png", 150, 150, 2, 2);			// Sprite do estado caindo para a direita
	Animation*	fallRSAnim		= new Animation(fallRS, 1.0 / 10.0, true);									// Anima��o do estado caindo para a direita
	TileSet*	fallL			= new TileSet("Resources/fallLeft.png", 150, 150, 2, 2);					// Sprite do estado caindo para a esquerda
	Animation*	fallLAnim		= new Animation(fallL, 1.0 / 10.0, true);									// Anima��o do estado caindo para a esquerda
	TileSet*	fallLS			= new TileSet("Resources/fallLeftShooting.png", 150, 150, 2, 2);			// Sprite do estado caindo para a esquerda
	Animation*	fallLSAnim		= new Animation(fallLS, 1.0 / 10.0, true);									// Anima��o do estado caindo para a esquerda

	uint actualLevel;

	int collisionPrecision = 0;		// Define posi��o ap�s colis�o

	bool grounded	= false;		// Define se jogador est� no ch�o
	int righted		= true;		// Define se jogador est� virado para a direita
	float fireTime	= -1;

	float velX			= 0;		// Velocidade do player no eixo X
	float velY			= 0;		// Velocidade do player no eixo Y
	float moveSpeed		= 400;		// Velocidade de movimento
	float jumpSpeed		= 720;		// Velocidade do pulo
	float jumpHeight	= 16000;	// Altura do pulo (quanto menor esse n�mero, maior a altura)
	int jumpDistance	= 5000;		// Vari�vel de controle de dist�ncia
	int jumpProgress	= 5000;		// Varia at� o jumpDistance

	float gravityScale = 270;	// For�a da gravidade


public:
	Player(int startX, int startY, float mSpeed, float jSpeed, float jHeigth, uint level);		// Construtor
	~Player();																					// Destrutor

	void OnCollision(Object* obj);	// Detecta as colis�es do player
	void Update();					// Atualiza l�gica do jogo
	void Draw();					// Desenha os quadros do jogo

	void Jump();					// Realiza o pulo do personagem
	void Gravity();					// Aplica gravidade ao objeto
	void StateMachine();			// Interpretador de estados
};
// ----------------------------------------------------------------------------------------------------------------------------------

#endif
