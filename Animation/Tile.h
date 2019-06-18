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
	int rangeX = NULL;		// Variação no eixo X
	int rangeY = NULL;		// Variação no eixo Y

	int originX;
	int originY;

	bool moving;

public:
	Tile(int startX, int startY, uint platType);												// Construtor de plataforma estática
	Tile(int startX, int startY, int velX, int velY, int rangeX, int rangeY, uint platType);	// Construtor de plataforma móvel
	~Tile();																					// Destrutor

	void Update();	// Atualiza lógica do jogo
	void Draw();	// Desenha os quadros do jogo
	void Define(uint platType);
	float Width();
	float Height();
};
// --------------------------------------------------------------------------------------

#endif