#include "Map.h"


struct Pos
{
	int x, y;
	Pos operator + (Pos p) const { return Pos(x + p.x, y + p.y); }
	Pos(int x = 0 ,int y = 0) :x(x), y(0){}
};


enum Dir { 
	Left,
	Right,
	Down,
	Top ,
	Pos_End,
};


Dir& operator ++ (Dir& d) { d = (Dir)(1 + (int)d); return d; }
Pos deltas[Pos_End] = { {0,-1}, {+1,0}, {0,+1}, {-1,0} };

Dir other(Dir d)
{
	switch (d)
	{
	case Left: return Left;
	case Right: return Right;
	case Down: return Down;
	case Top: return Top;
	default: return Pos_End;
	}
}


Map::Map()
{
	Init();
}


Map::~Map()
{

}
void Map::Init()
{
	Draw();
}

void Map::Draw()
{
	for (int y = 0; y < MapHeight; y++)
	{
		for (int x = 0; x < MapWidth; x++)
		{
			cout << setw(3) << Data[y][x];
		}
		cout << endl;
	}
}

void Map::DirectionCheck(int CurrentValue)
{
	Pos p;
	for (Dir iter = Left; iter != Pos_End; ++iter)
	{		
		cout << deltas[iter] << endl;
	}
}

void Map::MapCheck()
{

}

