#pragma once
#include <stdio.h>
#include "pond.h"

#define TILE_COUNT 3

typedef enum E_Tile
{
	E_TILE_GRASS = 1,
	E_TILE_FOREST,
	E_TILE_WATER,
} E_Tile;

typedef struct Cell
{
	E_Tile possibleTiles[TILE_COUNT];


} Cell;

void Init(void);
void Update(void);
void Draw(void);

void CreateCellMap(void);

void CollapseCell(void);
void UpdateCellNeighbours(void);
void UpdateCellTiles(void);

void DrawMap(void);
void CheckToDrawCell(int _x, int _y, Cell _cell);
void DrawTileOnCell(int _x, int _y, E_Tile _tile);





