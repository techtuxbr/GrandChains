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
	Sprite* tile = nullptr;

public:
	Tile(int startX, int startY);	// Construtor
	~Tile();	// Destrutor

	void OnCollision(Object* obj);
	void Update();	// Atualiza lógica do jogo
	void Draw();	// Desenha os quadros do jogo
};
// --------------------------------------------------------------------------------------

#endif