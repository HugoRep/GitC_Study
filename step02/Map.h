#pragma once
#include "Player.h"
class Map
{
public:
	Map();
	~Map();

	void init(Player* _player)
	{
		player = _player;
	}

	void Tick(int keyCode);
	void Draw();

	class Player* player;

	int Data[10][10] = { {1,1,1,1,1,1,1,1,1,1},
						{1,0,0,1,0,0,0,0,0,1},
						{1,0,0,1,0,0,0,0,0,1},
						{1,0,0,1,0,0,0,0,0,1},
						{1,0,0,1,0,0,0,0,0,1},
						{1,0,0,0,0,0,1,0,0,1},
						{1,0,0,0,0,0,1,0,0,1},
						{1,0,0,0,0,0,1,0,0,1},
						{1,0,0,0,0,0,1,0,0,1},
						{1,1,1,1,1,1,1,1,1,1},
	};
};
