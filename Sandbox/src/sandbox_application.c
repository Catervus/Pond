#include "sandbox_application.h"
#include <time.h>

Pond_Colour black = { 0, 0, 0, 255 };
Pond_Colour white = { 255, 255, 255, 255 };
Pond_Colour gray = { 100, 100, 100, 255 };
Pond_Colour red = { 255, 0, 0, 255 };
Pond_Colour blue = { 0, 0, 255, 255 };

Pond_Texture* p_texture;
Pond_Sprite* p_sprite;


Pond_Texture* p_tileTextures[TILE_COUNT];


Pond_Font* p_font;

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600

#define MAP_DIMENSIONS 10
#define TILE_DIMENSIONS 60

int screenWidth = SCREEN_WIDTH;
int screenHeight = SCREEN_HEIGHT;

int main(void)
{
	Pond_Init(&Init, &Update, &Draw);
	Pond_InitAudioSystem(24, 10, 20);
	Pond_Run(60, screenWidth, screenHeight, "Pond-Sandbox!");

	return 0;
}


void Init(void) 
{
	Pond_SetWindowMode(POND_WINDOW_MODE_WINDOWED);

	Pond_SetRenderClearColour(black);

	Pond_SetWindowResizable(false);

	Pond_SetRandomSystemSeed(0);

	p_font = Pond_LoadFont("assets/monogram.ttf");

	p_texture = Pond_LoadTexture("assets/ledian.png", POND_TEXTURE_BLEND_MODE_BLENDING);
	p_sprite = Pond_InitSprite(p_texture);

	// p_tileTextures[0] = Pond_LoadTexture("assets/tiles/grass.png", POND_TEXTURE_BLEND_MODE_NO_BLENDING);
	// p_tileTextures[1] = Pond_LoadTexture("assets/tiles/forest.png", POND_TEXTURE_BLEND_MODE_NO_BLENDING);
	// p_tileTextures[2] = Pond_LoadTexture("assets/tiles/water.png", POND_TEXTURE_BLEND_MODE_NO_BLENDING);


	// TODO: Collapsing random Cell

}

Cell cellMap[MAP_DIMENSIONS][MAP_DIMENSIONS];

void CreateCellMap(void)
{
	for (int row = 0; row < MAP_DIMENSIONS; row++)
	{
		for (int col = 0; col < MAP_DIMENSIONS; col++)
		{

		}
	}
}

void Update(void)
{
	
}

void Draw(void)
{
	DrawMap();
}

void DrawMap(void)
{
	for (int y = 0; y < MAP_DIMENSIONS; y++)
	{
		for (int x = 0; x < MAP_DIMENSIONS; x++)
		{
			Pond_DrawRectByDimensions(x * TILE_DIMENSIONS, y * TILE_DIMENSIONS, TILE_DIMENSIONS, TILE_DIMENSIONS, blue, false);
			CheckToDrawCell(x, y, cellMap[y][x]);
		}
	}
}

void CheckToDrawCell(int _x, int _y, Cell _cell)
{
	int counter = 0;
	E_Tile tiletodraw = 0;
	for (int i = 0; i < TILE_COUNT; i++)
	{
		if (_cell.possibleTiles[i] != 0)
		{
			tiletodraw = _cell.possibleTiles[i];
			counter++;
		}
	}

	if (counter == 1)
	{
		DrawTileOnCell(_x, _y, tiletodraw);
	}
}

void DrawTileOnCell(int _x, int _y, E_Tile _tile)
{
	_x *= TILE_DIMENSIONS;
	_y *= TILE_DIMENSIONS;

	switch (_tile)
	{
		case E_TILE_GRASS:
			break;
		case E_TILE_FOREST:
			break;
		case E_TILE_WATER:
			break;
	}
}

