#ifndef _GRANDCHAINS_TILE_H_
#define _GRANDCHAINS_TILE_H_

// Includes ----------
#include "Object.h"
#include "Animation.h"
// -------------------

enum types { FULL, HALF, JUST , WALL};

// Objeto do personagem principal -------------------------------------------------------
class Tile : public Object {
private:
	TileSet* tile;
	Animation* tileAnim;

	int velX = NULL;		// Velocidade no eixo X
	int velY = NULL;		// Velocidade no eixo Y
	
	// range = 400 -> (-200... x ... 200);
	int rangeX = NULL;		// Varia��o no eixo X
	int rangeY = NULL;		// Varia��o no eixo Y

	int originX;
	int originY;

	bool moving;

public:
	Tile(int startX, int startY, uint platType);												// Construtor de plataforma est�tica
	Tile(int startX, int startY, int velX, int velY, int rangeX, int rangeY, uint platType);	// Construtor de plataforma m�vel
	~Tile();																					// Destrutor

	void Update();	// Atualiza l�gica do jogo
	void Draw();	// Desenha os quadros do jogo
	void Define(uint platType);
	float Width();
	float Height();
};
// --------------------------------------------------------------------------------------

#endif