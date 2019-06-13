/**********************************************************************************
// Sprite (Arquivo de Cabe�alho)
// 
// Cria��o:		11 Jul 2007
// Atualiza��o: 06 Jun 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Define uma classe para representar um sprite
//
**********************************************************************************/

#ifndef _DESENVJOGOS_SPRITE_H_
#define _DESENVJOGOS_SPRITE_H_

// ---------------------------------------------------------------------------------

#include "Image.h"
#include "Types.h"
#include <DirectXMath.h>
using namespace DirectX;

// ---------------------------------------------------------------------------------

// defini��o de um sprite
struct SpriteData
{
	float x, y;
	float scale;
	float depth;
	float rotation;
	uint  width;
	uint  height;
	ID3D11ShaderResourceView* texture;
	XMFLOAT2 texCoord;
	XMFLOAT2 texSize;
};

// defini��o de camadas para os sprites
struct Layer
{
	static const float FRONT;
	static const float MIDFRONT;
	static const float MIDDLE;
	static const float MIDBACK;
	static const float BACK;
};

// ---------------------------------------------------------------------------------

class Sprite
{
private:
	SpriteData sprite;										// dados do sprite 
	bool localImage;										// imagem local ou externa
	const Image * image;									// ponteiro para imagem

public:
	Sprite(string filename);								// constroi sprite a partir de um arquivo
	Sprite(const Image * img);								// constroi sprite a partir de imagem existente
	~Sprite();												// destrutor do sprite

	int Width();											// largura do sprite
	int Height();											// altura do sprite

	void Draw(float x, float y, float z = Layer::MIDDLE);	// desenha imagem
};

// ---------------------------------------------------------------------------------
// Fun��es Inline

// retorna a largura do sprite
inline int Sprite::Width() 
{ return image->Width(); }

// retorna a altura do sprite
inline int Sprite::Height() 
{ return image->Height(); }

// ---------------------------------------------------------------------------------

#endif