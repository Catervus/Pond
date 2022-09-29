#include "sandbox_application.h"
#include <time.h>

Pond_Colour black = { 0, 0, 0, 255 };
Pond_Colour white = { 255, 255, 255, 255 };
Pond_Colour gray = { 100, 100, 100, 255 };
Pond_Colour red = { 255, 0, 0, 255 };
Pond_Colour blue = { 0, 0, 255, 255 };

Pond_Colour grassCol = { 50, 255, 25, 255 };
Pond_Colour forestCol = { 40, 100, 0, 255 };

Pond_Texture* p_texture;
Pond_Sprite* p_sprite;


Pond_Texture* p_tileTextures[TILE_COUNT];


Pond_Font* p_font;

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600



int screenWidth = SCREEN_WIDTH;
int screenHeight = SCREEN_HEIGHT;

int main(void)
{
	Pond_Init(&Init, &Update, &Draw);
	Pond_InitAudioSystem(24, 10, 20);
	Pond_Run(0, screenWidth, screenHeight, "Pond-Sandbox!");

	return 0;
}


void Init(void) 
{
	Pond_SetWindowMode(POND_WINDOW_MODE_WINDOWED);

	Pond_SetRenderClearColour(black);

	Pond_SetWindowResizable(false);

	// Pond_SetRandomSystemSeed(0);

	p_font = Pond_LoadFont("assets/monogram.ttf");

	p_texture = Pond_LoadTexture("assets/ledian.png", POND_TEXTURE_BLEND_MODE_BLENDING);
	p_sprite = Pond_InitSprite(p_texture);

	// p_tileTextures[0] = Pond_LoadTexture("assets/tiles/grass.png", POND_TEXTURE_BLEND_MODE_NO_BLENDING);
	// p_tileTextures[1] = Pond_LoadTexture("assets/tiles/forest.png", POND_TEXTURE_BLEND_MODE_NO_BLENDING);
	// p_tileTextures[2] = Pond_LoadTexture("assets/tiles/water.png", POND_TEXTURE_BLEND_MODE_NO_BLENDING);

	// TODO: Collapsing random Cell

	CreateCellMap();

	int x = Pond_GetRandomInt(0, MAP_DIMENSIONS - 1);
	int y = Pond_GetRandomInt(0, MAP_DIMENSIONS - 1);

	CollapseCell(&cellMap[y][x]);
	UpdateCellNeighbours(cellMap[y][x].collapsedTile, x, y);
}


void CreateCellMap(void)
{
	for (int row = 0; row < MAP_DIMENSIONS; row++)
	{
		for (int col = 0; col < MAP_DIMENSIONS; col++)
		{
			for (int i = 0; i < TILE_COUNT; i++)
			{
				cellMap[row][col].possibleTiles[i] = i + 1;
				cellMap[row][col].collapsedTile = 0;
				cellMap[row][col].possibleTilesCounter = TILE_COUNT;
			}
		}
	}
}

void Update(void)
{
	FindCellToCollapse();

	if (Pond_GetKeyDown(POND_KEYBOARD_KEY_SPACE))
	{
		// printf("Collapsed another Cell\n");
		CreateCellMap();

		int x = Pond_GetRandomInt(0, MAP_DIMENSIONS - 1);
		int y = Pond_GetRandomInt(0, MAP_DIMENSIONS - 1);

		CollapseCell(&cellMap[y][x]);
		UpdateCellNeighbours(cellMap[y][x].collapsedTile, x, y);
	}
}

void FindCellToCollapse(void)
{
	int leastpossibletiles = 100;
	Cell* p_celltocollapse;
	int rowToCollapse = 0;
	int colToCollapse = 0;

	for (int row = 0; row < MAP_DIMENSIONS; row++)
	{
		for (int col = 0; col < MAP_DIMENSIONS; col++)
		{
			/*if (cellMap[row][col].possibleTilesCounter < leastpossibletiles)
			{
				leastpossibletiles = cellMap[row][col].possibleTilesCounter;
				p_celltocollapse = &cellMap[row][col];
				rowToCollapse = row;
				colToCollapse = col;
			}*/
			if (cellMap[row][col].possibleTilesCounter == 2)
			{
				CollapseCell(&cellMap[row][col]);
				UpdateCellNeighbours(cellMap[row][col].collapsedTile, col, row);
				return;
			}

		}
	}

	for (int row = 0; row < MAP_DIMENSIONS; row++)
	{
		for (int col = 0; col < MAP_DIMENSIONS; col++)
		{
			if (cellMap[row][col].possibleTilesCounter == 3)
			{
				CollapseCell(&cellMap[row][col]);
				UpdateCellNeighbours(cellMap[row][col].collapsedTile, col, row);
				return;
			}

		}
	}

	//CollapseCell(&cellMap[rowToCollapse][colToCollapse]);
	//UpdateCellNeighbours(cellMap[rowToCollapse][colToCollapse].collapsedTile, colToCollapse, rowToCollapse);
	// CollapseCell(p_celltocollapse);
	// UpdateCellNeighbours(p_celltocollapse->collapsedTile, colToCollapse, rowToCollapse);
}


void CollapseCell(Cell* _p_cell)
{
	int index = 0;

	if (IsCellCollapsed(_p_cell))
		return;

	while (1)
	{
		int rnd = Pond_GetRandomInt(0, TILE_COUNT - 1);
		if (_p_cell->possibleTiles[rnd] != 0)
		{
			index = rnd;
			break;
		}
	}

	_p_cell->collapsedTile = _p_cell->possibleTiles[index];
	_p_cell->possibleTilesCounter = 1;

	for (int i = 0; i < TILE_COUNT; i++)
	{
		if (i == index)
			continue;
		_p_cell->possibleTiles[i] = 0;

	}
}

void UpdateCellNeighbours(E_Tile _tile, int _x, int _y)
{

	int yoffset = 0;
	int xoffset = 0;


	for (int dir = 0; dir < 4; dir++)
	{
		if (dir == 0) // Check up
		{
			yoffset = -1;
			xoffset = 0;
		}
		else if (dir == 1) // Check down
		{
			yoffset = 1;
			xoffset = 0;
		}
		else if (dir == 2) // Check left
		{
			yoffset = 0;
			xoffset = -1;
		}
		else if (dir == 3) // Check right
		{
			yoffset = 0;
			xoffset = 1;
		}

		// Check if neighbouring tile already collapsed
		if (IsCellCollapsed(&cellMap[_y + yoffset][_x + xoffset]))
			continue;

		if (_y + yoffset < 0 || _y + yoffset >= MAP_DIMENSIONS)
			continue;
		if (_x + xoffset < 0 || _x + xoffset >= MAP_DIMENSIONS)
			continue;

		if (_tile == E_TILE_GRASS)
		{

		}
		else if (_tile == E_TILE_FOREST)
		{
			for (int i = 0; i < TILE_COUNT; i++)
			{
				if (cellMap[_y + yoffset][_x + xoffset].possibleTiles[i] == E_TILE_WATER)
				{
					cellMap[_y + yoffset][_x + xoffset].possibleTiles[i] = 0;
					cellMap[_y + yoffset][_x + xoffset].possibleTilesCounter--;

					if (cellMap[_y + yoffset][_x + xoffset].possibleTilesCounter == 1)
						CollapseCell(&cellMap[_y + yoffset + xoffset][_x]);
				}
			}
		}
		else if (_tile == E_TILE_WATER)
		{
			for (int i = 0; i < TILE_COUNT; i++)
			{
				if (cellMap[_y + yoffset][_x + xoffset].possibleTiles[i] == E_TILE_FOREST)
				{
					cellMap[_y + yoffset][_x + xoffset].possibleTiles[i] = 0;
					cellMap[_y + yoffset][_x + xoffset].possibleTilesCounter--;

					if (cellMap[_y + yoffset][_x + xoffset].possibleTilesCounter == 1)
						CollapseCell(&cellMap[_y + yoffset + xoffset][_x]);
				}
			}
		}
	}

	
}

int CheckIfCellShouldGetCollapsed(Cell* _p_cell)
{
	int counter = 0;
	for (int i = 0; i < TILE_COUNT; i++)
	{
		if (_p_cell->possibleTiles[i] != 0)
		{
			counter++;
			
		}
	}

	if (counter > 1)
		return 1;


	return 0;
}

int IsCellCollapsed(Cell* _p_cell) 
{

	if (_p_cell->possibleTilesCounter == 1)
		return 1;

	return 0;
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
			
			// Pond_DrawRectByDimensions(x * TILE_DIMENSIONS, y * TILE_DIMENSIONS, TILE_DIMENSIONS, TILE_DIMENSIONS, blue, false);
			// CheckToDrawCell(x, y, cellMap[y][x]);
			if (cellMap[y][x].possibleTilesCounter == 1)
			{
				printf("X: %i\n", x);
				printf("Y: %i\n", y);
				printf("Collapsed: %i\n---------\n", cellMap[y][x].possibleTilesCounter);
				DrawTileOnCell(x, y, cellMap[y][x].collapsedTile);

			}
			else if (cellMap[y][x].possibleTilesCounter == 2)
			{
				Pond_DrawRectByDimensions(x * TILE_DIMENSIONS, y * TILE_DIMENSIONS, 
					TILE_DIMENSIONS, TILE_DIMENSIONS, red, true);
			}

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
			Pond_DrawRectByDimensions(_x, _y, TILE_DIMENSIONS, TILE_DIMENSIONS, grassCol, true);
			break;
		case E_TILE_FOREST:
			Pond_DrawRectByDimensions(_x, _y, TILE_DIMENSIONS, TILE_DIMENSIONS, forestCol, true);
			break;
		case E_TILE_WATER:
			Pond_DrawRectByDimensions(_x, _y, TILE_DIMENSIONS, TILE_DIMENSIONS, blue, true);
			break;
		default:
			break;
	}
}

