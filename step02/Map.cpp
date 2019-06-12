#include "Map.h"
#include "Player.h"
#include <stdio.h>


Map::Map()
{

}


Map::~Map()
{

}

void Map::Tick(int keyCode)
{
	player-> Tick(keyCode);
}

void Map::Draw()
{
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			if (x == player->X && y == player->Y)
				player->Draw();
			else
				printf("%d", Data[y][x]);
		}
		printf("\n");
	}
}
