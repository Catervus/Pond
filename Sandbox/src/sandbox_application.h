#pragma once
#include <stdio.h>
#include "pond.h"

#define TILE_COUNT 3
#define MAP_DIMENSIONS 10
#define TILE_DIMENSIONS 60

typedef enum E_Tile
{
	E_TILE_GRASS = 1,
	E_TILE_FOREST,
	E_TILE_WATER,

} E_Tile;

typedef struct Cell
{
	E_Tile possibleTiles[TILE_COUNT];
	int possibleTilesCounter;
	E_Tile collapsedTile;

} Cell;

void Init(void);
void Update(void);
void Draw(void);

void CreateCellMap(void);

void CollapseCell(Cell* _p_cell);
void UpdateCellNeighbours(E_Tile _tile, int _x, int _y);
int CheckIfCellShouldGetCollapsed(Cell* _p_cell);
int IsCellCollapsed(Cell* _p_cell);
int GetCellTileCount(Cell _cell);
void UpdateCellTiles(void);
void FindCellToCollapse(void);

void DrawMap(void);
void CheckToDrawCell(int _x, int _y, Cell _cell);
void DrawTileOnCell(int _x, int _y, E_Tile _tile);

Cell cellMap[MAP_DIMENSIONS][MAP_DIMENSIONS];






