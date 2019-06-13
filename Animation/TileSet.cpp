/**********************************************************************************
// TileSet (C�digo Fonte)
// 
// Cria��o:		17 Abr 2012
// Atualiza��o: 06 Jun 2019
// Compilador:	Visual C++ 2019
//
// Descri��o:	Classe para representar uma folha de sprites
//
**********************************************************************************/

#include "TileSet.h"
#include "Image.h"

// -------------------------------------------------------------------------------

TileSet::TileSet(string filename, uint tileWidth, uint tileHeight, uint numCols, uint numTiles) : 
	image(new Image(filename)), 
	width(tileWidth), 
	height(tileHeight), 
	columns(numCols),	
	size(numTiles)
{
	
}

// -------------------------------------------------------------------------------

TileSet::~TileSet()
{
	// libera mem�ria ocupada pela imagem
	if (image)
	{
		 delete image;
	}
}

// -------------------------------------------------------------------------------