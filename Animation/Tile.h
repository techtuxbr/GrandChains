#ifndef _GRANDCHAINS_TILE_H_
#define _GRANDCHAINS_TILE_H_

// Includes ----------
#include "Object.h"
#include "Sprite.h"
#include "Animation.h"
#include "TileSet.h"
// -------------------

// Objeto do personagem principal -------------------------------------------------------
class Tile : public Object {
private:
	enum types {STATIC, MOVING};
	uint platType;

	Sprite* tile = nullptr;

	int velX = NULL;		// Velocidade no eixo X
	int velY = NULL;		// Velocidade no eixo Y
	
	// range = 400 -> (-200... x ... 200);
	int rangeX = NULL;		// Variação no eixo X
	int rangeY = NULL;		// Variação no eixo Y

	int originX;
	int originY;

public:
	Tile(int startX, int startY);												// Construtor de plataforma estática
	Tile(int startX, int startY, int velX, int velY, int rangeX, int rangeY);	// Construtor de plataforma móvel
	~Tile();																	// Destrutor

	void OnCollision(Object* obj);
	void Update();	// Atualiza lógica do jogo
	void Draw();	// Desenha os quadros do jogo
};
// --------------------------------------------------------------------------------------

#endif